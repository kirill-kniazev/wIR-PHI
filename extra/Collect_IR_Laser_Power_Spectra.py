import numpy as np
from numpy import *
from time import sleep
import os
from datetime import datetime as dt
import Firefly_SW #192.168.1.229, separate py file
import Firefly_LW #192.168.1.231, , separate py file
import pyqtgraph as pg
import pyvisa
from ThorlabsPM100 import ThorlabsPM100
from pathlib import Path

# Define the wavelength range and step size
start_wavenumber = 1730  # Initial wavelength in nm
end_wavenumber = 1750    # Final wavelength in nm
step_size = 1            # Step size in cm-1

#initializing PM100D power meter:
rm = pyvisa.ResourceManager()                   # Initialize the VISA resource manager
inst = rm.open_resource('USB0::0x1313::0x8078::P0006834::INSTR', LF='\n', timeout=000000) # Open the resource for the Thorlabs power meter
power_meter = ThorlabsPM100(inst=inst)          # Initialize the Thorlabs power meter
power_meter.input.pdiode.filter.lpass.state = 1 # Enable the low-pass filter on the power meter
sleep(1)                                        # Wait for the settings to take effect
power = power_meter.read                        # Read the power measurement
sleep(2)                                        # Wait for the reading to stabilize

# Create the file path
cur_time = dt.now() # Get the current time
f_name_prefix = cur_time.strftime("%d-%m-%Y-%H%M_IR_power_spectrum")    # Create the filename prefix with the current date and time
dir_name = Path(__file__).resolve().parent.parent / "docs"              # Get the parent directory of the script
file_path = dir_name / f"{f_name_prefix}.csv"                           # Create the full file path

# Create the data placeholder
num_steps = ((abs(end_wavenumber - start_wavenumber)) / step_size) + 1                  # Calculate the number of steps to scan
wavenumber_pattern = np.arange(start_wavenumber, end_wavenumber + step_size, step_size) # Generate the wavenumber pattern
scan_shape = np.shape(wavenumber_pattern)                                               # Determine the shape of the scan
data_PM = np.zeros(scan_shape)                                                          # Create an empty array for power meter data

# Initialize the Firefly laser and start the loop
# Firefly3 = Firefly3.Firefly3(sock=None)   # For short wavelength range, use Firefly3.Firefly3
Firefly3 = Firefly_LW.Firefly_LW(sock=None) # For long wavelength range, use Firefly_LW.Firefly_LW
Firefly3.go_to_wavelength(start_wavenumber) # Set the laser to the starting wavenumber
sleep(5)                                    # Allow time for the Firefly laser to change wavelength
# Spectrum measurement loop
for index in np.ndindex(scan_shape):
    Firefly3.go_to_wavelength(wavenumber_pattern[index])    # Set the laser to the current wavenumber
    sleep(2)                                                # Allow time for the laser to stabilize
    power = power_meter.read                                # Read the power measurement
    sleep(1.5)                                              # Allow time for the power meter to stabilize
    data_PM[index] = power                                  # Store the power measurement in the data array
full_data = np.vstack((wavenumber_pattern, data_PM)).T      # Combine the wavenumbers and power measurements into a single array
np.savetxt(file_path, full_data, delimiter=",")             # Save the data to a CSV file
Firefly3.go_to_wavelength(start_wavenumber)                 # Reset the laser to the starting wavenumber
sleep(10)                                                   # Allow time for the laser to reset