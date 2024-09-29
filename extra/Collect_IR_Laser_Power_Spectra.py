import numpy as np
from numpy import *
import time
from time import sleep
import os
from datetime import datetime as dt
import Firefly_SW #192.168.1.229, separate py file
import Firefly_LW #192.168.1.231, , separate py file
import pyqtgraph as pg
# import ThorLabs_PM100_PowerMeter as PM
# from PyQt5 import QtCore, QtGui
import pyvisa
from ThorlabsPM100 import ThorlabsPM100

#initializing PM100D power meter:
rm = pyvisa.ResourceManager()
inst = rm.open_resource('USB0::0x1313::0x8078::P0006834::INSTR', LF='\n', timeout=000000)#, LF='\n', timeout=50000)
power_meter = ThorlabsPM100(inst=inst)
power_meter.input.pdiode.filter.lpass.state = 1
sleep(1)
power = power_meter.read
sleep(2)

cur_time = dt.now()
f_name_prefix = str(cur_time.day)+'-' + str(cur_time.month)+"-" + str(
    cur_time.year)+"-" "%1.2d"%cur_time.hour+"%1.2d"%cur_time.minute+'_power_spectrum'
dir_name = "C:\\Users\\kuno\\OneDrive - nd.edu\\Documents\\Measurements\\Power_spectrum\\" + f_name_prefix

if os.path.exists(dir_name):  # check if folder already exists
    if os.listdir(dir_name):  # check if folder is empty
        dir_name = dir_name + "_1"  # change folder name if folder is not empty
        os.makedirs(dir_name)  # create another foder if folder is not empty
else:
    os.makedirs(dir_name)

lambda1, lambda2 = 1730, 1750  # edit here, wavelength range for spectrum in nm, format: initial wavelength, final wavelength
lambda_stepsize = 1 # edit here, enter stepsize in nm, if >5nm steps, change sleep time in Firefly3 library
len_lambda = ((abs(lambda2-lambda1))/lambda_stepsize) + 1  # this is the number of steps in which the scan length will be divided

lambda_pattern = np.arange(lambda1, lambda2+lambda_stepsize, lambda_stepsize)

print (lambda_pattern)
print ("********************************************")

scan_shape = np.shape(lambda_pattern)

# create empty lists for y axes on the plot
data_PM = np.zeros(scan_shape)
# pw = pg.plot() # calling the plot function
print (scan_shape)



# for Firelfy laser initialization:
#Firefly3 = Firefly3.Firefly3(sock=None) #short WL
Firefly3 = Firefly_LW.Firefly_LW(sock=None) #long WL
Firefly3.go_to_wavelength(lambda1)
sleep(5)  # to allow Firefly to change wavelength

#spectrum measurement
for index in np.ndindex(scan_shape):
    Firefly3.go_to_wavelength(lambda_pattern[index])
    # sleep(1)
    # meter.read_value()
    # sleep(1)
    # meter.measure.scalar.power()
    sleep(2)
    # current_data = meter.read
    power = power_meter.read
    print (f"Power = {power} W @ {lambda_pattern[index]} cm-1")
    sleep(1.5)
    data_PM[index] = power
    
    #   print (f"Power = {data_PM[index]} W @ {lambda_pattern[index]} cm-1")
    # pw.plot(lambda_pattern, data_PM, clear=True, pen='r')
    # pg.QtGui.QApplication.processEvents()
    # sleep(1)
    # sleep(0.5)  # integration time in seconds

full_data = np.vstack((lambda_pattern, data_PM)).T	
np.savetxt(dir_name + "\\" + "power_IR" +".csv", full_data, delimiter=",")


# to reset laser wavelength
Firefly3.go_to_wavelength(lambda1)
sleep(10)