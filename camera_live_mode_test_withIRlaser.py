import sys
sys.path.append("C:/Users/kuno/OneDrive - nd.edu/Documents/Soft_related/_Python Scripts/IR-PHI_2021/laser_manipulator-test_June_2022/Newfocus")
sys.path.append("C:/Users/kuno/OneDrive - nd.edu/Documents/Soft_related/_Python Scripts/IR-PHI_2021")
from photron_camera import PhotronCamera
import numpy as np
import matplotlib.pyplot as plt
import time
from time import sleep
import os
from datetime import datetime as dt
import Firefly_SW #192.168.1.229, separate py file
import Firefly_LW #192.168.1.231, , separate py file
import clr
clr.AddReference('C:/Users/kuno/OneDrive - nd.edu/Documents/Soft_related/_Python Scripts/IR-PHI_2021/laser_manipulator-test_June_2022/Newfocus/Newport.CONEXCC.CommandInterface.dll')
import CommandInterfaceConexCC
# from Newfocus.ConexCC import ConexCC
# import CommandInterfaceConexCC
# from Newfocus.ConexCC import ConexCC
from ConexCC import ConexCC
start = time.time()
conex_cc = ConexCC(com_port='COM3', velocity=0.5)
ready = conex_cc.wait_for_ready(timeout=60)
if ready:
    conex_cc.move_absolute(1.582)
else:
    print('something went wrong')

SLEEP_TIME = 1
MIRROR_LEFT_BORDER = 0
MIRROR_RIGHT_BORDER = 3

mirror_correction_map = [
    {"wavenum" : 1630, "motor_step" : 1.577, "sleep_time" : 1},
    {"wavenum" : 1690, "motor_step" : 1.570, "sleep_time" : 1},
    {"wavenum" : 1710, "motor_step" : 1.575, "sleep_time" : 1},
    {"wavenum" : 1713, "motor_step" : 1.566, "sleep_time" : 1},
    {"wavenum" : 1715, "motor_step" : 1.560, "sleep_time" : 1},
    {"wavenum" : 1717, "motor_step" : 1.556, "sleep_time" : 1},
    {"wavenum" : 1725, "motor_step" : 1.551, "sleep_time" : 1},
    {"wavenum" : 1735, "motor_step" : 1.547, "sleep_time" : 1},
    {"wavenum" : 1745, "motor_step" : 1.542, "sleep_time" : 1},
    {"wavenum" : 1760, "motor_step" : 1.537, "sleep_time" : 1},
    {"wavenum" : 1770, "motor_step" : 1.533, "sleep_time" : 1},
    {"wavenum" : 1785, "motor_step" : 1.530, "sleep_time" : 1},
    {"wavenum" : 1795, "motor_step" : 1.535, "sleep_time" : 1},
    {"wavenum" : 1805, "motor_step" : 1.540, "sleep_time" : 1},
    {"wavenum" : 1828, "motor_step" : 1.545, "sleep_time" : 1}
] 

mirror_correction_map_used = sorted(mirror_correction_map, 
                                            key=lambda d: d["wavenum"], 
                                            reverse=True)

def mirror_correction(wavenum_val):
        """
        Corrects mirror position to mitigate some physical issues.

        """

        dict_val = mirror_correction_map_used[-1]
        wavenum_border = dict_val["wavenum"]

        if wavenum_val >= wavenum_border:

            conex_cc.move_absolute(float(dict_val["motor_step"])) #this spin box is filled up initially

            sleep(dict_val["sleep_time"])

            # delete last element if correction procedure was done successfully
            mirror_correction_map_used.pop() 


#=========================== INIT SETTINGS ====================================
# NOTE disable Windows firefall before program run
IR_WAVENUM_START = 1050         
IR_WAVENUM_END   = 1800
IR_WAVENUM_STEP  = 4

ir_wavenum_arr = list(range(IR_WAVENUM_START, 
                            IR_WAVENUM_END + IR_WAVENUM_STEP, 
                            IR_WAVENUM_STEP))

#==============================================================================

# init camera
camera = PhotronCamera()

# adjust external sync mode
# camera.setExternalInMode()

#camera.setCameraFps(fps=40_000)

# check current fps
camera.getCurrentRecordSpeed()

# set resolution
# camera.setResolution(size=(256, 256))

# set sync delay in μsec
camera.setSyncInDelay(delay=9.0)

# set shutter speed in fps
# camera.setShutterSpeed(speed_in_fps=3_000_000)

# init recording and return final image
# I turned off low framerate for the data collection, because of the error


Firefly3 = Firefly_LW.Firefly_LW(sock=None) #long WL
Firefly3.go_to_wavelength(IR_WAVENUM_START)
sleep(5)  # to allow Firefly to change wavelength

cur_time = dt.now()
f_name_prefix = str(cur_time.year)+'-' + str(cur_time.month)+"-" + str(
    cur_time.day)+"-" "%1.2d"%cur_time.hour+"%1.2d"%cur_time.minute
dir_name = "C:\\Users\\kuno\\OneDrive - nd.edu\\Documents\\Measurements\\Wide_field\\" + f_name_prefix

if os.path.exists(dir_name):  # check if folder already exists
    if os.listdir(dir_name):  # check if folder is empty
        dir_name = dir_name + "_1"  # change folder name if folder is not empty
        os.makedirs(dir_name)  # create another foder if folder is not empty
else:
    os.makedirs(dir_name)


st = time.time()

data_cube = np.empty((len(ir_wavenum_arr), 256,256), int)
spectra = np.empty((len(ir_wavenum_arr), 3), int)
spectra [:,0] = ir_wavenum_arr

for i in range(0, len(ir_wavenum_arr)):
    start_2 = time.time()
    Firefly3.go_to_wavelength(ir_wavenum_arr[i])
    # mirror_correction(ir_wavenum_arr[i])
    print (ir_wavenum_arr[i])
    sleep(0.1)
    image = camera.returnFinalImage(num_of_images=5000,start_image=0)

    #Compinsate hot - cold flip 
    if np.abs(image.min()) > np.abs(image.max()):
        image = image * -1
    data_cube[i,:,:] = image


    #image_crop = image[150:290,230:370]
    #normalisation
    # im_min = image_crop.min()
    # image_crop = image_crop - im_min
    # d_max = n_difference.max()
    # n_difference = n_difference/d_max
    #####
    spectra [i,1] = np.std(image)
    spectra [i,2] = np.average(image)  
    np.savetxt(dir_name + "\\" + f"Widefield_at_{ir_wavenum_arr[i]}_wavenumber.csv", image, delimiter=",")	
    end_2 = time.time()
    print(end_2 - start_2)

# plt.imshow(image_crop)
# plt.show()

np.save(dir_name + "\\" + "mydata.npy", data_cube)	

np.savetxt(dir_name + "\\" + "Spectra.csv", spectra, delimiter=",")	
print(f"For widefield spectra it took {time.time() - st} sec")
Firefly3.go_to_wavelength(IR_WAVENUM_START)
conex_cc.move_absolute(float(1.582))
conex_cc.close()
# close camera
camera.closeCamera()
end = time.time()
print(end - start)