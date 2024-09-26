from pdclib_dll import PhotronCameraDll
import numpy as np
import ctypes as ct
from colorama import Fore, init
from pathlib import Path

init(autoreset = True)

class PhotronCamera():
    def __init__(self):
        self.camera_dll = PhotronCameraDll()
        
        # lib for retrieving images
        self.ret_image_dll = ct.CDLL(str(Path(__file__).resolve().parent / "c" / "get_images_parallel_high_speed_dynamic.dll"))
        
        # init lib
        self.camera_dll.pdcInit()
        
        # detect camera with ip=192.168.0.10
        pDetectNumInfo = self.camera_dll.pdcDetectDevice(targetIP=0xC0A8000A)
        print(pDetectNumInfo)
        if pDetectNumInfo.m_nDeviceNum == 0: raise Exception(f"{Fore.RED}Camera is not found!\n")
        
        # init (open) camera
        self.device_number = self.camera_dll.pdcOpenDevice(pDetectNumInfo)
        
        # set current partion
        self.camera_dll.pdcSetCurrentPartition(nDeviceNo=self.device_number)
        
        # switch to 10Gb mode
        self.camera_dll.pdcSetPacketIntervalMode(nDeviceNo=self.device_number)
        
        print(f"{Fore.GREEN}\nCamera was successfully initialized!\n")
        
        
    def getCameraStatus(self):
        """
        Checks current camera status.
        
        """
        status = self.camera_dll.pdcGetStatus(self.device_number)
        print(f"Camera status: {status}")
        
    
    def setCameraStatus(self, status):
        """
        Set camera status.
        
        """
        if status == "live":
            self.camera_dll.pdcSetStatus(self.device_number, nMode=0x00)
            
        elif status == "playback":
            self.camera_dll.pdcSetStatus(self.device_number, nMode=0x01)
            
        else:
            print("{Fore.RED}Attempt to set improper status! Status should be either 'live' or 'playback'.\n")
            return
    
    
    def getCameraResolution(self):
        """
        Check current camera resolution.
        
        """
        width, height = self.camera_dll.pdcGetResolution(self.device_number)
        print(f"Camera resolution:")
        print(f"-------------------")
        print(f"width: {width} px")
        print(f"height: {height} px\n")
        return width, height
            
            
    def getCurrentRecordSpeed(self):
        """
        Get current camera record speed.
        
        """            
        fps = self.camera_dll.pdcGetRecordRate(nDeviceNo=self.device_number)
        print(f"Current frame rate: {fps} fps.\n")
            
            
    def getLiveImage(self, change_status=False, bufferSize=(1024, 1024)):
        """
        Allows to get real-time image from the camera.
        Be carefull with proper buffer size.
        
        """
        if not change_status:
            image = self.camera_dll.pdcGetLiveImageData(
                nDeviceNo=self.device_number, 
                bufferSize=bufferSize
            )
            
        else:
            self.setCameraStatus(status="live")
            image = self.camera_dll.pdcGetLiveImageData(self.device_number, bufferSize)
            
        return image
    
    def getLiveImage_Mod(self, change_status=False, bufferSize=(1024, 1024), Flip=False, x1=0, x2=256, y1=0, y2=256):
        """
        Allows to get real-time image from the camera.
        Be carefull with proper buffer size.
        
        """
        if not change_status:
            image = self.camera_dll.pdcGetLiveImageData(
                nDeviceNo=self.device_number, 
                bufferSize=bufferSize
            )
            
        else:
            self.setCameraStatus(status="live")
            image = self.camera_dll.pdcGetLiveImageData(self.device_number, bufferSize)
            
        if Flip:
            image = np.flip(image)

        image = image = image[y1:y2,x1:x2]

        return image

    
    def setExternalInMode(self, nMode=0x0C):
        """
        Adjust external sync mode. 
        
        """
        # try to install mode
        self.camera_dll.pdcSetExternalInMode(
            nDeviceNo=self.device_number,
            nPort=1, #! check this
            nMode=nMode, # PDC_EXT_IN_SYNC_POS
        )

        # this is needed to "activate" signal grabbing
        self.camera_dll.pdcSetExternalInMode(
            nDeviceNo=self.device_number,
            nPort=3, #! check this
            nMode=0x0F, # PDC_EXT_IN_OTHERSSYNC
        )
        
        # check if mode successfully installed
        code, _ = self.getExternalInMode()
        assert nMode == code, f"{Fore.RED}Set and get IN sync modes are different."

        print("External IN sync mode is successfully set!\n")
        
    
    def getExternalInMode(self):
        """
        Get external sync mode. 
        
        """

        code, desc = self.camera_dll.pdcGetExternalInMode(
            nDeviceNo=self.device_number,
            nPort=1,
        )
        
        return code, desc
        
        
    def setSyncInDelay(self, delay):
        """
        Adjust sync IN delay (in microseconds).
        
        """        
        
        # try to set proper delay
        delay = round(delay * 10) # 1 correspond to 100 nsec or 10 to 1 μsec
        self.camera_dll.pdcSetDelay(
            nDeviceNo=self.device_number,
            nSignal=2, #! check this
            nValue=delay
        )
        
        print("Delay is successfully set!\n")    


    def closeCamera(self):
        """
        Close camera.
        
        """        
        
        self.camera_dll.pdcCloseDevice(nDeviceNo=self.device_number)
    
    
    def setShutterSpeed(self, speed_in_fps): 
        """
        Set shutter speed in nsec.
        NOTE: keep in mind round procedure.
        
        """
        
        # try to set shutter speed
        self.camera_dll.pdcSetShutterSpeedFps(
            nDeviceNo=self.device_number,
            nFps=speed_in_fps)
        
        
    def setResolution(self, size):
        """
        Set camera resolution (order: width, height).
        
        """
        # try to set camera resolution
        self.camera_dll.pdcSetResolution(
            nDeviceNo=self.device_number,
            nWidth=size[0],
            nHeight=size[1]
        )
        
        # check if resolution was successfully set
        post_size = self.camera_dll.pdcGetResolution(
            nDeviceNo=self.device_number
        )
        
        assert size == post_size, f"Different resolutions set and get."
        print("Resolution is successfully set!\n") 
    
    
    def setCameraFps(self, fps):
        """
        Sets camera fps.
        
        """
        self.camera_dll.pdcSetRecordRate(nDeviceNo=self.device_number, nRate=fps)


    def returnFinalImage(self, num_of_images, start_image):
        """
        Retrives images from single experiment, subtracts odd images from even 
        and summirize them. At the end we will have only one image.
        Functions utilizes additional dll lib.
        
        Parameters
        ----------
            `num_of_images` : total number images expected to treat. MUST BE less
            or equal camera memory capacity.
            
            `start_image` : position of initial image to start from. Can be used
            if some first images are considered "bad".
        
        """
        
        width, height = self.getCameraResolution()

        # go to "live" mode to be able to record images
        self.camera_dll.pdcSetStatus(
            nDeviceNo=self.device_number,
            nMode=0x00 # live mode
        )

        # set trigger mode
        self.camera_dll.pdcSetTriggerMode(
            nDeviceNo=self.device_number,
            nMode=0x00 << 24, # start trigger
            nAFrames=0,
            nRFrames=0,
            nRCount=0
        )
        
        # set the device to the recording ready status
        self.camera_dll.pdcSetRecReady(nDeviceNo=self.device_number)
        
        # confirm the operating mode of the device
        while True:
            status, _ = self.camera_dll.pdcGetStatus(nDeviceNo=self.device_number)
            if status == 0x02 or status == 0x08: # 0x02 -> PDC_STATUS_RECREADY status
                break                            # 0x08 -> PDC_STATUS_REC status
            
        # start recording
        self.camera_dll.pdcTriggerIn(nDeviceNo=self.device_number)
        print("Recording images...", end=" ")
        
        # confirm the operating mode of the device
        while True:
            status, _ = self.camera_dll.pdcGetStatus(nDeviceNo=self.device_number)
            
            # check for end of recording
            if status != 0x02 and status != 0x08: # 0x02 -> PDC_STATUS_RECREADY status
                break                             # 0x08 -> PDC_STATUS_REC status 
            
        print("Done!\n")

        #self.setCameraFps(125)
        
        # set proper status to retrieve images
        self.setCameraStatus(status="playback")

        # now data is recorded and we can retrieve it
        # use c function to speed image processing
        
        # MUST BE initialized by zeros for proper work
        image = (ct.c_int * width * height)() 

        status = self.ret_image_dll.returnFinalImage(
                            ct.byref(image),
                            ct.c_uint(width),
                            ct.c_uint(height),
                            ct.c_uint(num_of_images),
                            ct.c_uint(start_image),
                            ct.c_ulong(self.device_number))
        
        if status != 0: raise Exception(f"{Fore.RED}Error while retrieving images!")
        
        # convert C array to numpy array
        image = np.array(image, dtype=np.int32, copy=False).reshape(width, height)
        
        # now `image` is our final image (hot images minus cold images
        # and then summed up)
     
        return image
            
    def intShading(self):
        """
        Calibrats camera shading.
        
        """
        self.camera_dll.pdcSetShadingMode(nDeviceNo=self.device_number, nMode=2)
        
    def SetPartition(self, Number):
        """
        Sets camera storage partition. This will afect the number of the frames can be collected until the storage is full
        
        """
        self.camera_dll.pdcSetCurrentPartition(nDeviceNo=self.device_number, nNo=Number)


    def returnFinalImage_Mod(self, num_of_images, start_image, Flip=False, x1=0, x2=256, y1=0, y2=256):
        """
        Retrives images from single experiment, subtracts odd images from even 
        and summirize them. At the end we will have only one image.
        Functions utilizes additional dll lib.
        
        Parameters
        ----------
            `num_of_images` : total number images expected to treat. MUST BE less
            or equal camera memory capacity.
            
            `start_image` : position of initial image to start from. Can be used
            if some first images are considered "bad".
        
        """
        
        width, height = self.getCameraResolution()

        # go to "live" mode to be able to record images
        self.camera_dll.pdcSetStatus(
            nDeviceNo=self.device_number,
            nMode=0x00 # live mode
        )

        # set trigger mode
        self.camera_dll.pdcSetTriggerMode(
            nDeviceNo=self.device_number,
            nMode=0x00 << 24, # start trigger
            nAFrames=0,
            nRFrames=0,
            nRCount=0
        )
        
        # set the device to the recording ready status
        self.camera_dll.pdcSetRecReady(nDeviceNo=self.device_number)
        
        # confirm the operating mode of the device
        while True:
            status, _ = self.camera_dll.pdcGetStatus(nDeviceNo=self.device_number)
            if status == 0x02 or status == 0x08: # 0x02 -> PDC_STATUS_RECREADY status
                break                            # 0x08 -> PDC_STATUS_REC status
            
        # start recording
        self.camera_dll.pdcTriggerIn(nDeviceNo=self.device_number)
        print("Recording images...", end=" ")
        
        # confirm the operating mode of the device
        while True:
            status, _ = self.camera_dll.pdcGetStatus(nDeviceNo=self.device_number)
            
            # check for end of recording
            if status != 0x02 and status != 0x08: # 0x02 -> PDC_STATUS_RECREADY status
                break                             # 0x08 -> PDC_STATUS_REC status 
            
        print("Done!\n")

        #self.setCameraFps(125)
        
        # set proper status to retrieve images
        self.setCameraStatus(status="playback")

        # now data is recorded and we can retrieve it
        # use c function to speed image processing
        
        # MUST BE initialized by zeros for proper work
        image = (ct.c_int * width * height)() 

        status = self.ret_image_dll.returnFinalImage(
                            ct.byref(image),
                            ct.c_uint(width),
                            ct.c_uint(height),
                            ct.c_uint(num_of_images),
                            ct.c_uint(start_image),
                            ct.c_ulong(self.device_number))
        
        if status != 0: raise Exception(f"{Fore.RED}Error while retrieving images!")
        
        # convert C array to numpy array
        image = np.array(image, dtype=np.int32, copy=False).reshape(width, height)

        # So, we are subtracts odd images from even, assumng hot are even and cold are odd. 
        # However, we can't controll the order and image can be negative. We are compensaiting possible issues in the processing steps: 
        #if np.sum(image[:,:]) < 0: 
        if abs(np.min(image)) > np.max(image):
            image[:,:] = -image[:,:]
        
        if Flip:
            image = np.flip(image)

        image = image = image[y1:y2,x1:x2]
        # now `image` is our final image (hot images minus cold images
        # and then summed up)
        
        return image