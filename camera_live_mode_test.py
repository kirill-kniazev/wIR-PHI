from photron_camera import PhotronCamera
import numpy as np
import matplotlib.pyplot as plt
import time

#=========================== INIT SETTINGS ====================================
# NOTE disable Windows firefall before program run
IR_WAVENUM_START = 1100
IR_WAVENUM_END   = 1800
IR_WAVENUM_STEP  = 10

ir_wavenum_arr = list(range(IR_WAVENUM_START, 
                            IR_WAVENUM_END + IR_WAVENUM_STEP, 
                            IR_WAVENUM_STEP))

#==============================================================================

# init camera
camera = PhotronCamera()

# adjust external sync mode
# camera.setExternalInMode()

# camera.setCameraFps(fps=40_168)

# check current fps
camera.getCurrentRecordSpeed()

# set resolution
# camera.setResolution(size=(512, 512))

# set sync delay in μsec
# camera.setSyncInDelay(delay=23.2)

# set shutter speed in fps
# camera.setShutterSpeed(speed_in_fps=3_000_000)

# init recording and return final image
# I turned off low framerate for the data collection, because of the error
st = time.time()
image = camera.returnFinalImage(
    num_of_images=2000, 
    start_image=0)
print(f"For 000 images it took {time.time() - st} sec")

# close camera
camera.closeCamera()
# np.savetxt("1734_2", image, delimiter=",")	
plt.imshow(image)#[207:239,277:309])
plt.show()