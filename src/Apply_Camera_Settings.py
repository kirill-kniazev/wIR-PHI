import sys
from CMOS_Functions import PhotronCamera
import time
import subprocess
import tkinter as tk
from tkinter import messagebox

print ('Initialising system')
camera = PhotronCamera()                         # Initialize camera
camera.setExternalInMode()                       # Set external sync mode
camera.setSyncInDelay(delay=9.0)                 # Set sync delay in μsec
camera.setShutterSpeed(speed_in_fps=3_000_000)   # Set shutter speed in fps
camera.setResolution(size=(256, 256))            # Set resolution
camera.intShading()                              # Performs shading correction
time.sleep(2)                                    # Wait for 2 sec for CMOS to save the paremeters                    
camera.closeCamera()                             # Disconnect camera
time.sleep(2)                                    # Wait for 2 sec for CMOS to fully shut down

print ("Opening PVF4")
subprocess.Popen(r'C:\Program Files\Photron\Photron FASTCAM Viewer 4\pfv4.exe') # Open PVF4
time.sleep(10)                                   # Wait for 10 sec for PVF4 to open
def popup_message():
    root = tk.Tk()
    root.wm_title("Setup Instructions")
    root.withdraw()  # Hide the main window
    messagebox.showinfo("Setup Instructions", "Set up the partitions\nI/O setting -> Record -> Partitions = 128")
popup_message()
