from photron_camera import PhotronCamera
import numpy as np
import matplotlib.pyplot as plt
from time import sleep

# init camera
camera = PhotronCamera()

# adjust external sync mode
# camera.setExternalInMode()

camera.setCameraFps(fps=40_165)

# check current fps
# camera.getCurrentRecordSpeed()

# # set resolution
# camera.setResolution(size=(512, 512))

# # set sync delay in μsec
# # camera.setSyncInDelay(delay=23.1)

# # set shutter speed in fps
# camera.setShutterSpeed(speed_in_fps=3_000_000)

# # init recording and return final image
# # I turned off low framerate for the data collection, because of the error
# x_data = []
# y_data = []
# y_data2 = []
# y_data3 = []

# for delay in np.arange(0, 1, 0.1):
#     camera.setSyncInDelay(delay=delay)
#     print(f"delay : {delay}")
#     image = camera.returnFinalImage(num_of_images=1000, start_image=0)
#     x_data.append(delay) 
#     y_data.append(np.std(image[160:260, 230:340]))
#     y_data2.append(np.amax(image[160:260, 230:340]))
#     y_data3.append(np.ptp(image[160:260, 230:340]))

# close camera
camera.closeCamera()

# plt.plot(x_data, y_data)
# plt.plot(x_data, y_data2)
# plt.plot(x_data, y_data3)
# plt.show()