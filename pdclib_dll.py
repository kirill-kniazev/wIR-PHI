import ctypes as ct
import numpy as np

class PhotronCameraDll():
    def __init__(self):
        self.path_to_dll = "C:\\Users\\kuno\\OneDrive - nd.edu\\Documents\\Soft_related\\_Python Scripts\\IR-PHI (widefield) 2022\\photron_cam_Oct\\lib\\PDCLIB.dll" # path to PDCLIB dll file
        self.lib = ct.CDLL(self.path_to_dll)
        
        
    def pdcInit(self):
        """
        This function initializes PDCLIB.
        
        unsigned long PDC_Init(unsigned long *pErrorCode)

        Parameter
        ---------
            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.

        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.

        Remarks
        -------
            Only use this function once the first time PDCLIB is used.
        
        """
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_Init(ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcInit() error | error code: {pErrorCode.value}"
        
    
    def pdcCloseDevice(self, nDeviceNo):
        """
        This function closes the specified device.

        unsigned long PDC_CloseDevice(
            unsigned long nDeviceNo
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_CloseDevice(ct.c_ulong(nDeviceNo),
                                           ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcCloseDevice() error | error code: {pErrorCode.value}"
        
        
    def pdcDetectDevice(self,
                        targetIP=0xC0A8000A,
                        nInterfaceCode=0x00000002, # Gigabit-Ethernet interface
                        nDetectNum=1,
                        nDetectParam=0):
        """
        This function searches for devices that can be opened and retrieves the number of those devices.

        unsigned long PDC_DetectDevice(
            unsigned long nInterfaceCode
            unsigned long *pDetectNo
            unsigned long nDetectNum
            unsigned long nDetectParam
            PPDC_DETECT_NUM_INFO pDetectNumInfo
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nInterfaceCode
                Specifies the interface code to be searched.
                
                Values
                    PDC_INTTYPE_G_ETHER	`0x00000002`
                        Gigabit-Ethernet interface

                    PDC_INTTYPE_IEEE1394 `0x00000003`	
                        IEEE1394a interface

                    PDC_INTTYPE_OPTICAL	`0x00000004`
                        Photron Optical interface

                    PDC_INTTYPE_PCI	`0x00000100`
                        PCI/PCI Express interface

                    PDC_INTTYPE_USB	`0x00000005`
                        USB interface

                    PDC_INTTYPE_GIGE_VISION	`0x00000006`
                        GigE Vision interface
            
            + pDetectNo
                Specifies the IP address to be searched. Specify this parameter
                when the interface code is PDC_INTTYPE_G_ETHER.
                For interface codes other than PDC_INTTYPE_G_ETHER, specify NULL.
                    Comment: "None" should be used as the NULL pointer in Python.
                The IP address is a 32-bit unsigned integer.
                
            + nDetectNum
                Specifies the maximum number of devices to be searched.
                This parameter specifies the number of the devices when
                the IP address is specified using parameter pDetectNo.
                This parameter is valid only when an interface code is 
                PDC_INTTYPE_G_ETHER. For interface codes other than PDC_INTTYPE_G_ETHER, 
                this function is always PDC_MAX_DEVICE `64`.
                
            + nDetectParam
                Specifies a search option. This parameter is valid only when an interface
                code is PDC_INTTYPE_ETHER. For interface codes other than PDC_INTTYPE_ETHER, 
                this function is automatically searched at all times.

                Values
                    PDC_DETECT_NORMAL `0`
                        Specifies an IP address directly.

                    PDC_DETECT_AUTO	`1`
                        Automatic search
                    
            + pDetectNumInfo
                This parameter is the address of the PDC_DETECT_NUM_INFO
                structure that receives search results.
        
                Values
                    This structure saves the number of searched devices as well 
                    as information from PDC_DETECT_INFO.

                    typedef struct {
                        unsigned long m_nDeviceNum;
                        PDC_DETECT_INFO m_DetectInfo[PDC_MAX_DEVICE];
                    } PDC_DETECT_NUM_INFO, *PPDC_DETECT_NUM_INFO;
                    
                    Parameter
                        m_nDeviceNum
                            Saves the number of searched devices.

                        m_DetectInfo
                            Save the search result information of the device.
                            
                            This structure saves the device code and interface code of the searched device.

                            typedef struct {
                                unsigned long m_nDeviceCode;
                                unsigned long m_nTmpDeviceNo;
                                unsigned long m_nInterfaceCode;
                            } PDC_DETECT_INFO, *PPDC_DETECT_INFO;
                            
                            Parameter
                                m_nDeviceCode
                                    Saves the device code.

                                m_nTmpDeviceNo
                                    Saves the temporary device number. Specified as 
                                    an IP address when the interface is a Gigabit-Ether type.

                                m_nInterfaceCode
                                    Saves the interface code.
            
            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        Remarks
        -------
            Attempt to apply this function for repeated search to interface having opened 
            device will fail (error code PDC_ERROR_OPEN_ALREADY). From PDCLIB.dll 1.0.9.5 on, 
            repeated search can be made only if target interface is Gigabit-Ethernet 
            (PDC_INTTYPE_G_ETHER). List of connected devices that are not opened 
            at such repeated search is returned.
        
        """
        pDetectNo = (ct.c_ulong * 64)()
        pDetectNo[0] = targetIP # example: 192.168.0.10 -> 0xC0A8000A 
        pErrorCode  = ct.c_ulong()
        
        # create structures for data storing
        class PDC_DETECT_INFO(ct.Structure):
            _fields_ = [('m_nDeviceCode', ct.c_ulong),
                        ('m_nTmpDeviceNo', ct.c_ulong),
                        ('m_nInterfaceCode', ct.c_ulong)]
            
        class PDC_DETECT_NUM_INFO(ct.Structure):
            _fields_ = [('m_nDeviceNum', ct.c_ulong),
                        ('m_DetectInfo', PDC_DETECT_INFO * 64)]
            
        pDetectNumInfo = PDC_DETECT_NUM_INFO()
        
        ret_val = self.lib.PDC_DetectDevice(ct.c_ulong(nInterfaceCode),
                                            ct.byref(pDetectNo),
                                            ct.c_ulong(nDetectNum),
                                            ct.c_ulong(nDetectParam),
                                            ct.byref(pDetectNumInfo), #! check this
                                            ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcDetectDevice() error | error code: {pErrorCode.value}"        
        
        # del PDC_DETECT_INFO, PDC_DETECT_NUM_INFO #! check if it is needed
        return pDetectNumInfo
        
        
    def      pdcOpenDevice(self, pDetectNumInfo):
        """
        This function opens and initializes the specified device.

        unsigned long PDC_OpenDevice(
            PPDC_DETECT_INFO pDetectInfo
            unsigned long *pDeviceNo
            unsigned long *pErrorCode
        )
            
        Parameter
        ---------
            + pDetectInfo
                This parameter is the address of the PDC_DETECT_INFO structure 
                in which search information is contained.

            + pDeviceNo
                This parameter is the variable pointer that retrieves the device 
                number of the opened device. This parameter value is used when 
                a device number must be specified in other functions.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.  
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
            
        Remarks
        -------
            A PDC_DetectDevice function must be performed in advance. Select and use
            the PDC_DETECT_INFO structure opened from the PDC_DETECT_NUM_INFO structure 
            that is retrieved using a PDC_DetectDevice function. The opened device is put 
            into live mode. 
        
        """
        pDeviceNo = ct.c_ulong()
        pErrorCode  = ct.c_ulong()
        ret_val = self.lib.PDC_OpenDevice(ct.byref(pDetectNumInfo.m_DetectInfo[0]), #! check this
                                          ct.byref(pDeviceNo),
                                          ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcOpenDevice() error | error code: {pErrorCode.value}"
        
        return pDeviceNo.value # return device number (pDeviceNo)
    
    
    def pdcGetNumberOfDevice(self):
        """
        This function retrieves the number of opened devices.

        unsigned long PDC_GetNumberOfDevice(
            unsigned long *pNum
            unsigned long *pErrorCode
        )

        Parameter
        ---------
            + pNum
                This parameter is the variable pointer that retrieves the number
                of all opened devices, irrespective of the type of interface.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.

        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        """
        
        pNum = ct.c_ulong()
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_GetNumberOfDevice(ct.byref(pNum), ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetNumberOfDevice() error | error code: {pErrorCode.value}"
        return pNum.value
    
    
    def pdcGetLiveImageData(self, nDeviceNo, nBitDepth=16, nChildNo=1, bufferSize=(1024, 1024)):
        """
        This function retrieves the live image of the specified child device.

        unsigned long PDC_GetLiveImageData(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long nBitDepth
            void *pData
            unsigned long *pErrorCode
        )

        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + nBitDepth
                Specifies the bit depth. For 8-bit data, this parameter specifies "8".
                For 16-bit data, it specifies "16". For 16-bit data, the data is
                lower-justified.

            + pData
                This parameter is the top address of a buffer that retrieves 
                image data. For 8 bits, usually prepare a buffer using 
                an 8-bit unsigned integer. For 16 bits, prepare a buffer 
                using a 16-bit unsigned integer.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        nChildNo = ct.c_ulong(nChildNo) # by default is 1
        nBitDepth = ct.c_ulong(nBitDepth) # by defaul is 16
        pData = (ct.c_uint16 * bufferSize[0] * bufferSize[1])() # an array for 16 bit depth
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_GetLiveImageData(nDeviceNo, 
                                                nChildNo,
                                                nBitDepth,
                                                ct.byref(pData),
                                                ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetLiveImageData() error | error code: {pErrorCode.value}"
        
        image = np.array(pData, dtype=np.uint16).reshape(bufferSize[0], bufferSize[1])
        return image
    

    def pdcSetStatus(self, nDeviceNo, nMode):
        """
        This function switches the live mode and memory playback mode of the specified device.

        unsigned long PDC_SetStatus(
            unsigned long nDeviceNo
            unsigned long nMode
            unsigned long *pErrorCode
        )

        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nMode
                Specifies a mode setting value.

                PDC_STATUS_LIVE `0x00`: Live mode (Forcibly interrupted during recording.)
                PDC_STATUS_PLAYBACKMemory `0x01`: playback mode

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        nMode = ct.c_ulong(nMode)
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetStatus(nDeviceNo,
                                         nMode,
                                         ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetStatus() error | error code: {pErrorCode.value}"
        
        
    def pdcSetRecReady(self, nDeviceNo):
        """
        This function puts the specified device into the recording ready status.

        unsigned long PDC_SetRecReady(
            unsigned long nDeviceNo
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetRecReady(nDeviceNo,
                                           ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetRecReady() error | error code: {pErrorCode.value}"
        
    
    def pdcTriggerIn(self, nDeviceNo):
        """
        This function starts recording in the specified device.

        unsigned long PDC_TriggerIn(
            unsigned long nDeviceNo
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_TriggerIn(nDeviceNo,
                                         ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcTriggerIn() error | error code: {pErrorCode.value}"
        
        
    def pdcGetMemFrameInfo(self, nDeviceNo, nChildNo=1):
        """
        This function retrieves the frame information recorded in the current partition of the specified child device.

        unsigned long PDC_GetMemFrameInfo(
            unsigned long nDeviceNo
            unsigned long nChildNo
            PPDC_FRAME_INFO pFrame
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + pFrame
                This parameter is the PDC_FRAME_INFO pointer that retrieves 
                the frame information of the current partition.
                
                This structure saves the frame information of the recorded partition.

                typedef struct {
                    long m_nStart;
                    long m_nEnd;
                    long m_nTrigger;
                    long m_nTwoStageLowToHigh;
                    long m_nTwoStageHighToLow;
                    unsigned long m_nTwoStageTiming;
                    long m_nEvent[10];
                    long m_nEventCount;
                    long m_nRecordedFrames;
                } PDC_FRAME_INFO, *PPDC_FRAME_INFO;
                
                Parameter
                    m_nStart
                        This parameter is the top frame number of the recording range.

                    m_nEnd
                        This parameter is the last frame number of the recording range.

                    m_nTrigger
                        This parameter is the frame number of the imput trigger.

                    m_nTwoStageLowToHigh
                        This parameter is the frame number that is switched from 
                        low to high during two-stage trigger.

                    m_nTwoStageHighToLow
                        This parameter is the frame number that is switched from
                        high to low during two-stage trigger.

                    m_nTwoStageTiming
                        This parameter is the timming that is switched from low 
                        to high during two-stage trigger.

                    m_nEvent
                        This parameter is the frame number of the imput event trigger.

                    m_nEventCount;
                        This parameter is the number of times that the event
                        trigger was input.

                    m_nRecordedFrames
                        This parameter is the number of picture-recorded frames.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        nChildNo = ct.c_ulong(nChildNo)
        class PDC_FRAME_INFO(ct.Structure):
            _fields_ = [('m_nStart', ct.c_long),
                        ('m_nEnd', ct.c_long),
                        ('m_nTrigger', ct.c_long),
                        ('m_nTwoStageLowToHigh', ct.c_long),
                        ('m_nTwoStageHighToLow', ct.c_long),
                        ('m_nTwoStageTiming', ct.c_ulong),
                        ('m_nEvent', ct.c_long * 10),
                        ('m_nEventCount', ct.c_long),
                        ('m_nRecordedFrames', ct.c_long)]
        pFrame = PDC_FRAME_INFO()
        pErrorCode = ct.c_ulong()
        
        ret_val = self.lib.PDC_GetMemFrameInfo(nDeviceNo,
                                               nChildNo,
                                               ct.byref(pFrame),
                                               ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetMemFrameInfo() error | error code: {pErrorCode.value}"
        
        return pFrame
    
    
    def pdcGetMemImageData(self, 
                           nDeviceNo,
                           nFrameNo, 
                           bufferSize=(1024, 1024), 
                           nChildNo=1, 
                           nBitDepth=16):
        """
        This function retrieves the recording image of the specified child 
        device's current partition.

        unsigned long PDC_GetMemImageData(
            unsigned long nDeviceNo
            unsigned long nChildNo
            long nFrameNo
            unsigned long nBitDepth
            void *pData
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + nFrameNo
                Specifies a frame number.

            + nBitDepth
                Specifies the bit depth. For 8-bit data, this parameter 
                specifies "8". For 16-bit data, it specifies "16". For 16-bit data,
                the data is lower-justified.

            + pData
                This parameter is the top address of a buffer that retrieves image data. 
                For 8 bits, usually prepare a buffer using an 8-bit unsigned integer. 
                For 16 bits, prepare a buffer using a 16-bit unsigned integer.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        nChildNo = ct.c_ulong(nChildNo)
        nFrameNo = ct.c_long(nFrameNo)
        nBitDepth = ct.c_ulong(nBitDepth)
        pData = (ct.c_uint16 * bufferSize[0] * bufferSize[1])()
        pErrorCode = ct.c_ulong()
        
        ret_val = self.lib.PDC_GetMemImageData(nDeviceNo,
                                               nChildNo,
                                               nFrameNo,
                                               nBitDepth,
                                               ct.byref(pData),
                                               ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetMemImageData() error | error code: {pErrorCode.value}"                                       
        
        image = np.array(pData, dtype=np.uint16).reshape(bufferSize[0], 
                                                         bufferSize[1]) #! check this
        
        return image
    
    
    def pdcSetShadingMode(self, nDeviceNo, nMode, nChildNo=1):
        """
        This function sets the status of a shading function in the specified 
        child device.

        unsigned long PDC_SetShadingMode(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long nMode
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + nMode
                This parameter is the status of a shading function.

                Values
                    PDC_SHADING_OFF `1`	 
                        Sets shading correction to OFF.

                    PDC_SHADING_ON `2`	
                        Sets shading correction to ON and performs recalibration.

                    PDC_SHADING_SAVE `3`	
                        Saves shading data.

                    PDC_SHADING_LOAD `4`	
                        Reads shading data and sets shading correction to ON.

                    PDC_SHADING_UPDATE `5`	
                        Updates shading data from a device

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.

        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        nChildNo = ct.c_ulong(nChildNo)
        nMode = ct.c_ulong(nMode)
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetShadingMode(nDeviceNo,
                                              nChildNo,
                                              nMode,
                                              ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetShadingMode() error | error code: {pErrorCode.value}" 
        
        
    def pdcSetShadingType(self, nDeviceNo, nMode, nChildNo=1):
        """
        This function sets correction method for shading function on specified child device.

        unsigned long PDC_SetShadingType(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long nMode
            unsigned long *pErrorCode
        )

        Parameters
        ----------
            + nDeviceNo
                Specify a device number.

            + nChildNo
                Specify a child device number.

            + nMode
                Correction method for shading function.

                Values
                
                PDC_SHADING_TYPE_NORMAL	`0`
                    Makes normal corrections.

                PDC_SHADING_TYPE_FINE `1`
                    Makes stricter corrections.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
            
        
        """
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetShadingType(ct.c_ulong(nDeviceNo),
                                              ct.c_ulong(nChildNo),
                                              ct.c_ulong(nMode),
                                              ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetShadingType() error | error code: {pErrorCode.value}" 
    
        
    def pdcGetStatus(self, nDeviceNo):
        """
        This function retrieves the operating condition of the specified device.

        unsigned long PDC_GetStatus(
            unsigned long nDeviceNo
            unsigned long *pStatus
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + pStatus
                This function is the variable pointer that retrieves the operating condition of a device.

                Values
                    PDC_STATUS_LIVE	`0x00`
                        Live mode

                    PDC_STATUS_PLAYBACK	`0x01`
                        Memory playback mode

                    PDC_STATUS_RECREADY	`0x02`
                        Recording standby mode (Only during live mode/status retrieval)

                    PDC_STATUS_ENDLESS `0x04`	
                        Endless recording mode (Only during live mode/status retrieval)

                    PDC_STATUS_REC `0x08`
                        Recording mode (Only during live mode/status retrieval)

                    PDC_STATUS_SAVE	`0x10`
                        Shading data save mode (Only during live mode/status retrieval)

                    PDC_STATUS_LOAD	`0x20`
                        Shading data read mode (Only during live mode/status retrieval)

                    PDC_STATUS_STORAGE_PLAYBACK	`0x80`
                        Storage mode

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        pStatus = ct.c_ulong()
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_GetStatus(nDeviceNo,
                                         ct.byref(pStatus),
                                         ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetStatus() error | error code: {pErrorCode.value}"
        satus_dict = {
            0x00 : "Live mode",
            0x01 : "Memory playback mode",
            0x02 : "Recording standby mode (Only during live mode/status retrieval)",
            0x04 : "Endless recording mode (Only during live mode/status retrieval)",
            0x08 : "Recording mode (Only during live mode/status retrieval)",
            0x10 : "Shading data save mode (Only during live mode/status retrieval)",
            0x20 : "Shading data read mode (Only during live mode/status retrieval)",
            0x80 : "Storage mode"
        }
        
        return pStatus.value, satus_dict[pStatus.value]
            
    
    def pdcGetCamMode(self, nDeviceNo, nChildNo=1):
        """
        This function retrieves the operating conditions of the specified child device.

        unsigned long PDC_GetCamMode(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long *pMode
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + pMode
                This parameter is the variable pointer that retrieves the operating 
                conditions of the camera.

                Values
                    PDC_CAM_MODE_DEFAULT `0`
                        Ordinary operation (Internal synchronization)

                    PDC_CAM_MODE_VARIABLE `1`
                        Variable function operation (Internal synchronization)

                    PDC_CAM_MODE_EXTERNAL `2`	
                        External synchronization 

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
            
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        nChildNo = ct.c_ulong(nChildNo)
        pMode = ct.c_ulong()
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_GetCamMode(nDeviceNo,
                                          nChildNo,
                                          ct.byref(pMode),
                                          ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetCamMode() error | error code: {pErrorCode.value}"
        mode_dict = {
            0 : "Ordinary operation (Internal synchronization)",
            1 : "Variable function operation (Internal synchronization)",
            2 : "External synchronization"
        }
        
        return pMode.value, mode_dict[pMode.value]
    
    
    def pdcGetResolution(self, nDeviceNo, nChildNo=1):
        """
        This function retrieves the resolution of the specified child device.

        unsigned long PDC_GetResolution(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long *pWidth
            unsigned long *pHeight
            unsigned long *pErrorCode
        )

        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + pWidth
                This parameter is the variable pointer that retrieves
                the width of an image.

            + pHeight
                This parameter is the variable pointer that retrieves 
                the height of an image.

            + pErrorCode
                This parameter is the variable pointer that retrieves 
                an error code.
            
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.

        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        nChildNo = ct.c_ulong(nChildNo)
        pWidth = ct.c_ulong()
        pHeight = ct.c_ulong()
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_GetResolution(nDeviceNo,
                                             nChildNo,
                                             ct.byref(pWidth),
                                             ct.byref(pHeight),                                        
                                             ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetResolution() error | error code: {pErrorCode.value}"
        
        return (pWidth.value, pHeight.value)
    
    
    def pdcSetResolution(self, nDeviceNo, nWidth, nHeight, nChildNo=1):
        """
        This function sets the resolution of the specified child device.

        unsigned long PDC_SetResolution(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long nWidth
            unsigned long nHeight
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + nWidth
                This parameter is the width of an image. Specify this parameter 
                through combined use of the values that are retrieved using 
                PDC_GetResolutionList.

            + nHeight
                This parameter is the height of an image. Specify this parameter 
                through combined use of the values that are retrieved using 
                PDC_GetResolutionList.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        """
        nDeviceNo = ct.c_ulong(nDeviceNo)
        nChildNo = ct.c_ulong(nChildNo)
        nWidth = ct.c_ulong(nWidth)
        nHeight = ct.c_ulong(nHeight)
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetResolution(nDeviceNo,
                                             nChildNo,
                                             nWidth,
                                             nHeight,                                        
                                             ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetResolution() error | error code: {pErrorCode.value}"
    
    
    def pdcSetResolutionLockMode(self, nDeviceNo, nMode):
        """
        This function sets the resolution lock mode status of the specified device.

        unsigned long PDC_SetResolutionLockMode(
            unsigned long nDeviceNo
            unsigned long nMode
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nMode
                Sets the resolution lock mode.

                Values
                
                PDC_RESOLUTIONLOCK_MODE1 `0`
                    Maximum resolution that can be chosen at the recording 
                    speed is set up, when we change it.

                PDC_RESOLUTIONLOCK_MODE2 `1`
                    Resolution is maintained even if it changes recording frame rate.
                *It is not the limitation when it cannot be changed new recordingframe rate at the current resolution.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
        
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
            
        """
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetResolutionLockMode(ct.c_ulong(nDeviceNo), 
                                                     ct.c_ulong(nMode),                                                                                                                                                                  
                                                     ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetResolutionLockMode() error | error code: {pErrorCode.value}"
    
    
    def pdcSetTriggerMode(self, nDeviceNo, nMode, nAFrames, nRFrames, nRCount):
        """
        This function sets the trigger mode of the specified device.

        unsigned long PDC_SetTriggerMode(
            unsigned long nDeviceNo
            unsigned long nMode
            unsigned long nAFrames
            unsigned long nRFrames
            unsigned long nRCount
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nMode
                This parameter is the setting value of trigger mode.

                Values
                
                    PDC_TRIGGER_START `(0x00 << 24)`	
                        Start trigger

                    PDC_TRIGGER_CENTER `(0x01 << 24)`
                        Center trigger

                    PDC_TRIGGER_END	`(0x02 << 24)`
                        End trigger

                    PDC_TRIGGER_RANDOM `(0x03 << 24)`
                        Random trigger

                    PDC_TRIGGER_MANUAL `(0x04 << 24)`
                        Manual trigger

                    PDC_TRIGGER_RANDOM_RESET `(0x05 << 24)`	
                        Random reset trigger

                    PDC_TRIGGER_RANDOM_CENTER `(0x06 << 24)`	
                        Random center trigger

                    PDC_TRIGGER_RANDOM_MANUAL `(0x07 << 24)`
                        Random manual trigger

                    PDC_TRIGGER_TWOSTAGE_HALF `((0x08 << 24) | 1)`
                        Two-stage trigger (1/2)

                    PDC_TRIGGER_TWOSTAGE_QUARTER `((0x08 << 24) | 2)`
                        Two-stage trigger (1/4)

                    PDC_TRIGGER_TWOSTAGE_ONEEIGHTH `((0x08 << 24) | 3)`
                        Two-stage trigger (1/8)
                

            + nAFrames
                This parameter is the number of frames following a trigger frame. 
                It is used in the manual and random manual states.

            + nRFrames
                This parameter is the number of frames per one-time random trigger.

            + nRCount
                This parameter is the number of recording times in the random 
                center and random manual states.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetTriggerMode(ct.c_ulong(nDeviceNo),
                                              ct.c_ulong(nMode),
                                              ct.c_ulong(nAFrames),
                                              ct.c_ulong(nRFrames),
                                              ct.c_ulong(nRCount),                                                                                      
                                              ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetTriggerMode() error | error code: {pErrorCode.value}"
        
        
    def pdcSetRecordRate(self, nDeviceNo, nRate, nChildNo=1):
        """
        This function sets the recording speed of the specified child device.

        unsigned long PDC_SetRecordRate(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long nRate
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + nRate
                This parameter is the setting value of the recording speed. The speed is
                set in 1/(setting value) second (The actual recording speed is 1/2000 
                seconds when the setting value is 2000). Values other than those 
                that are retrieved using PDC_GetRecordRateList cannot be used.
            
            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetRecordRate(ct.c_ulong(nDeviceNo),
                                             ct.c_ulong(nChildNo),
                                             ct.c_ulong(nRate),                                                                                                                                    
                                             ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetRecordRate() error | error code: {pErrorCode.value}"
        
      
    def pdcGetRecordRate(self, nDeviceNo, nChildNo=1):
        """
        This function retrieves the recording speed of the specified child device.

        unsigned long PDC_GetRecordRate(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long *pRate
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + pRate
            This parameter is the variable pointer that retrieves the recording speed. 
            The speed is represented by 1/(retrieved value) second.
            Example : The actual recording speed is 1/2000 seconds when the 
            retrieved value is 2000.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
            
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        pRate = ct.c_ulong()
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_GetRecordRate(ct.c_ulong(nDeviceNo),
                                             ct.c_ulong(nChildNo),
                                             ct.byref(pRate),                                                                                                                                    
                                             ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetRecordRate() error | error code: {pErrorCode.value}"
        
        return pRate.value # in fps
      
        
    def pdcSetShutterSpeedFps(self, nDeviceNo, nFps, nChildNo=1):
        """
        This function sets the shutter speed of the specified child device.

        unsigned long PDC_SetShutterSpeedFps(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long nFps
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
            Specifies a device number.

            + nChildNo
            Specifies a child device number.

            + nFps
            This parameter is the setting value of the shutter speed. The speed is 
            represented in 1/(setting value) second (The actual shutter speed is 1/2000 
            seconds when the setting value is 2000.). Values other than those
            that are retrieved using PDC_GetShutterSpeedFps cannot be used.
            
            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
        
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.        
        
        """
        
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetShutterSpeedFps(ct.c_ulong(nDeviceNo),     
                                                  ct.c_ulong(nChildNo),
                                                  ct.c_ulong(nFps),                                                                                                                              
                                                  ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetShutterSpeedFps() error | error code: {pErrorCode.value}"
        
        
    def pdcSetShutterLockMode(self, nDeviceNo, nMode):
        """
        This function sets the status of a shutter lock function in the specified device.

        unsigned long PDC_SetShutterLockMode(
            unsigned long nDeviceNo
            unsigned long nMode
            unsigned long *pErrorCode
        )

        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nMode
                This parameter is the status setting value of a device's shutter 
                lock function.

                Values
                    
                    PDC_SHUTTERLOCK_MODE1 `0`	
                        MODE 1 (The shutter speed is set to the open state 
                        (becomes equal to the recording speed) when the recording 
                        speed is changed.)

                    PDC_SHUTTERLOCK_MODE2 `1`
                        MODE 2 (The shutter speed is maintained even if the recording 
                        speed is changed.)
                        * This does not apply when the current shutter speed 
                        cannot be used at a new recording speed.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
        
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
            
        """
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetShutterLockMode(ct.c_ulong(nDeviceNo),
                                                  ct.c_ulong(nMode),                                                                                                                       
                                                  ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetShutterLockMode() error | error code: {pErrorCode.value}"
        
        
    def pdcGetShutterSpeedFps(self, nDeviceNo, nChildNo=1):
        """
        This function retrieves the shutter speed, in fractions of a second, of the specified child device.

        unsigned long PDC_GetShutterSpeedFps(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long *pFps
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nChildNo
                Specifies a child device number.

            + pFps
                This parameter is the variable pointer that retrieves a shutter speed. 
                The speed is represented by 1/(retrieved value) second. 
                Example:The actual shutter speed is 1/2000 seconds when the retrieved
                value is 2000.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
            
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
            
        """
        pFps = ct.c_ulong()
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_GetShutterSpeedFps(ct.c_ulong(nDeviceNo),     
                                                  ct.c_ulong(nChildNo),
                                                  ct.byref(pFps),                                                                                                                              
                                                  ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetShutterSpeedFps() error | error code: {pErrorCode.value}"
        
        return pFps.value
        
        
    def pdcSetDelay(self, nDeviceNo, nSignal, nValue):
        """
        This function sets the delay value for the input/output signal of the specified device.

        unsigned long PDC_SetDelay(
            unsigned long nDeviceNo
            unsigned long nSignal
            unsigned long nValue
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nSignal
                Specifies the signal to be retrieved.

                Values
                
                    PDC_DELAY_TRIGGER_IN `1`	
                        Trigger signal input to TRIG TTL IN connector

                    PDC_DELAY_VSYNC_IN `2`	
                        Vertical synchronizing signal input to SYNC IN connector

                    PDC_DELAY_GENERAL_IN `3`
                        Signal (not including a READY signal) input to 
                        GENERAL IN connector

                    PDC_DELAY_TRIGGER_OUT_WIDTH	`4`
                        Pulse width of TTL trigger signal to be output

                    PDC_DELAY_VSYNC_OUT	`5`
                        Vertical synchronizing signal to be output

                    PDC_DELAY_VSYNC_OUT_WIDTH `6`
                        Pulse width of vertical synchronizing signal to be output

                    PDC_DELAY_EXPOSE `7`
                        Exposure duration signal to be output

            + nValue
                This parameter is a delay/period value. The minimum setting 
                unit is 100 nsec (a value is 1).

                Example:
                    The minimum setting value is 100 nsec when the setting value is 1.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetDelay(ct.c_ulong(nDeviceNo),
                                        ct.c_ulong(nSignal), 
                                        ct.c_ulong(nValue),                                                                                                                   
                                        ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetDelay() error | error code: {pErrorCode.value}"
        
        
    def pdcGetDelay(self, nDeviceNo, nSignal):
        """
        This function retrieves the delay value of the input/output signal of the specified device.

        unsigned long PDC_GetDelay(
            unsigned long nDeviceNo
            unsigned long nSignal
            unsigned long *pValue
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nSignal
                Specifies the signal to be retrieved.

                Values
                
                    PDC_DELAY_TRIGGER_IN `1`	
                        Trigger signal input to TRIG TTL IN connector

                    PDC_DELAY_VSYNC_IN `2`	
                        Vertical synchronizing signal input to SYNC IN connector

                    PDC_DELAY_GENERAL_IN `3`
                        Signal (not including a READY signal) input to 
                        GENERAL IN connector

                    PDC_DELAY_TRIGGER_OUT_WIDTH	`4`
                        Pulse width of TTL trigger signal to be output

                    PDC_DELAY_VSYNC_OUT	`5`
                        Vertical synchronizing signal to be output

                    PDC_DELAY_VSYNC_OUT_WIDTH `6`
                        Pulse width of vertical synchronizing signal to be output

                    PDC_DELAY_EXPOSE `7`
                        Exposure duration signal to be output

            + pValue
                This parameter is the variable pointer that retrieves a delay 
                value and period value. The minimum setting unit is 100 nsec
                (a value is 1).

                Example:
                The case where the retrieved value is 1 indicates that the minimum 
                setting unit is 100 nsec.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
            
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """ 
        
        pValue = ct.c_ulong()
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetDelay(ct.c_ulong(nDeviceNo),
                                        ct.c_ulong(nSignal), 
                                        ct.byref(pValue),                                                                                                                   
                                        ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetDelay() error | error code: {pErrorCode.value}"
        
        return pValue.value
        
               
    def pdcSetRecordingType(self, nDeviceNo, nMode):
        """
        This function sets the status of hardware recording type function for the specified device.

        unsigned long PDC_SetRecordingType(
            unsigned long nDeviceNo
            unsigned long nMode
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nMode
                Sets the status of hardware recording type.

                Values
                
                PDC_RECORDING_TYPE_READY_AND_TRIG `0`
                    Input the "REC"trigger after the camera is in the "READY" state.

                PDC_RECORDING_TYPE_DIRECT_TRIG `1`
                    Start recording immediately when the "REC" trigger is input.

                PDC_RECORDING_TYPE_DIRECT_START	`2`
                    "ENDLESS" will be started if "READY" is inputted with an endless series trigger mode.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
                
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.

        """
        
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetRecordingType(ct.c_ulong(nDeviceNo),   
                                                ct.c_ulong(nMode),                                                                                                               
                                                ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetRecordingType() error | error code: {pErrorCode.value}"
        
    
    def pdcSetEndless(self, nDeviceNo):
        """
        This function puts the specified device into the endless recording status.

        unsigned long PDC_SetEndless(
            unsigned long nDeviceNo
            unsigned long *pErrorCode
        )
        
        Parameter
            + nDeviceNo
                Specifies a device number.

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.

        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetEndless(ct.c_ulong(nDeviceNo),                                                                                                                
                                          ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetEndless() error | error code: {pErrorCode.value}"
   
   
    def pdcSetExternalInMode(self, nDeviceNo, nMode, nPort=1):
        """
        This function sets the input signal of the specified device.

        unsigned long PDC_SetExternalInMode(
            unsigned long nDeviceNo
            unsigned long nPort
            unsigned long nMode
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nPort
                Specifies the port number of an input port.

            + nMode
                This parameter is the signal setting value set to the specified
                input port.

                Values
                
                PDC_EXT_IN_NONE	`0x01`
                    No external synchronizing input signal (Internal synchronizing 
                    operation)

                PDC_EXT_IN_CAMSYNC_POSI	`0x02`
                    External synchronizing operation. Inputs a camera synchronizing
                    signal for synchronizing with the same model. (Positive polarity)

                PDC_EXT_IN_CAMSYNC_NEGA	`0x03`
                    External synchronizing operation. Inputs a camera synchronizing
                    signal for synchronizing with the same model. (Negative polarity)

                PDC_EXT_IN_OTHERSSYNC_POSI `0x04`
                    External synchronizing operation. Inputs a synchronizing 
                    signal for synchronizing with external equipment (including other PHOTRON products). (Positive polarity)

                PDC_EXT_IN_OTHERSSYNC_NEGA `0x05`
                    External synchronizing operation. Inputs a synchronizing 
                    signal for synchronizing with external equipment (including other PHOTRON products). (Negative polarity)

                PDC_EXT_IN_EVENT_POSI `0x06`
                    Inputs an event signal. (Positive polarity)

                PDC_EXT_IN_EVENT_NEGA `0x07`
                    Inputs an event signal. (Negative polarity)

                PDC_EXT_IN_TRIGGER_POSI	`0x08`
                    Inputs a TTL trigger signal. (Positive polarity)

                PDC_EXT_IN_TRIGGER_NEGA	`0x09`
                    Inputs a TTL trigger signal. (Negative polarity)

                PDC_EXT_IN_READY_POSI `0x0A`
                    Inputs a switching signal (READY ON/OFF) for recording 
                    standby state. (Positive polarity)

                PDC_EXT_IN_READY_NEGA `0x0B`
                    Inputs a switching signal (READY ON/OFF) for recording 
                    standby state. (Negative polarity)

                PDC_EXT_IN_SYNC_POS	`0x0C`
                    External synchronization operation. Input synchronization 
                    signal for synchronization. (Positive polarity)@

                PDC_EXT_IN_SYNC_NEGA `0x0D`
                    External synchronization operation. Input synchronization 
                    signal for synchronization. (Negative polarity)

                PDC_EXT_IN_CAMSYNC `0x0E`
                    External synchronization operation. Input camera 
                    synchronization signal for synchronization with a same model.

                PDC_EXT_IN_OTHERSSYNC `0x0F`
                    External synchronization operation. Input camera 
                    synchronization signal for synchronization with an external 
                    devise. (Including other PHOTRON products)
                

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
        
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetExternalInMode(ct.c_ulong(nDeviceNo),   
                                                ct.c_ulong(nPort), 
                                                ct.c_ulong(nMode),                                                                                                               
                                                ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetExternalInMode() error | error code: {pErrorCode.value}"
        
        
    def pdcGetExternalInMode(self, nDeviceNo, nPort=1):
        """
        This function sets the input signal of the specified device.

        unsigned long PDC_SetExternalInMode(
            unsigned long nDeviceNo
            unsigned long nPort
            unsigned long nMode
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo
                Specifies a device number.

            + nPort
                Specifies the port number of an input port.

            + pMode
                This parameter is the variable pointer that retrieves the signal 
                set to the specified input port.

                Values
                
                PDC_EXT_IN_NONE	`0x01`
                    No external synchronizing input signal (Internal synchronizing 
                    operation)

                PDC_EXT_IN_CAMSYNC_POSI	`0x02`
                    External synchronizing operation. Inputs a camera synchronizing
                    signal for synchronizing with the same model. (Positive polarity)

                PDC_EXT_IN_CAMSYNC_NEGA	`0x03`
                    External synchronizing operation. Inputs a camera synchronizing
                    signal for synchronizing with the same model. (Negative polarity)

                PDC_EXT_IN_OTHERSSYNC_POSI `0x04`
                    External synchronizing operation. Inputs a synchronizing 
                    signal for synchronizing with external equipment 
                    (including other PHOTRON products). (Positive polarity)

                PDC_EXT_IN_OTHERSSYNC_NEGA `0x05`
                    External synchronizing operation. Inputs a synchronizing 
                    signal for synchronizing with external equipment 
                    (including other PHOTRON products). (Negative polarity)

                PDC_EXT_IN_EVENT_POSI `0x06`
                    Inputs an event signal. (Positive polarity)

                PDC_EXT_IN_EVENT_NEGA `0x07`
                    Inputs an event signal. (Negative polarity)

                PDC_EXT_IN_TRIGGER_POSI	`0x08`
                    Inputs a TTL trigger signal. (Positive polarity)

                PDC_EXT_IN_TRIGGER_NEGA	`0x09`
                    Inputs a TTL trigger signal. (Negative polarity)

                PDC_EXT_IN_READY_POSI `0x0A`
                    Inputs a switching signal (READY ON/OFF) for recording 
                    standby state. (Positive polarity)

                PDC_EXT_IN_READY_NEGA `0x0B`
                    Inputs a switching signal (READY ON/OFF) for recording 
                    standby state. (Negative polarity)

                PDC_EXT_IN_SYNC_POS	`0x0C`
                    External synchronization operation. Input synchronization 
                    signal for synchronization. (Positive polarity)@

                PDC_EXT_IN_SYNC_NEGA `0x0D`
                    External synchronization operation. Input synchronization 
                    signal for synchronization. (Negative polarity)

                PDC_EXT_IN_CAMSYNC `0x0E`
                    External synchronization operation. Input camera 
                    synchronization signal for synchronization with a same model.

                PDC_EXT_IN_OTHERSSYNC `0x0F`
                    External synchronization operation. Input camera 
                    synchronization signal for synchronization with an external 
                    devise. (Including other PHOTRON products)
                

            + pErrorCode
                This parameter is the variable pointer that retrieves an error code.
        
        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        
        pErrorCode = ct.c_ulong()
        pMode = ct.c_ulong()
        ret_val = self.lib.PDC_GetExternalInMode(ct.c_ulong(nDeviceNo),   
                                                ct.c_ulong(nPort), 
                                                ct.byref(pMode),                                                                                                               
                                                ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcGetExternalInMode() error | error code: {pErrorCode.value}"
        
        mode_dict = {
            0x01 : "No external synchronizing input signal (Internal synchronizing operation)",
            0x02 : "External synchronizing operation. Inputs a camera synchronizing signal for synchronizing with the same model. (Positive polarity)",
            0x03 : "External synchronizing operation. Inputs a camera synchronizing signal for synchronizing with the same model. (Negative polarity)",
            0x04 : "External synchronizing operation. Inputs a synchronizing signal for synchronizing with external equipment (including other PHOTRON products). (Positive polarity)",
            0x05 : "External synchronizing operation. Inputs a synchronizing signal for synchronizing with external equipment (including other PHOTRON products). (Negative polarity)",
            0x06 : "Inputs an event signal. (Positive polarity)",
            0x07 : "Inputs an event signal. (Negative polarity)",
            0x08 : "Inputs a TTL trigger signal. (Positive polarity)",
            0x09 : "Inputs a TTL trigger signal. (Negative polarity)",
            0x0A : "Inputs a switching signal (READY ON/OFF) for recording standby state. (Positive polarity)",
            0x0B : "Inputs a switching signal (READY ON/OFF) for recording standby state. (Negative polarity)",
            0x0C : "External synchronization operation. Input synchronization signal for synchronization. (Positive polarity)@",
            0x0D : "External synchronization operation. Input synchronization signal for synchronization. (Negative polarity)",
            0x0E : "External synchronization operation. Input camera synchronization signal for synchronization with a same model.",
            0x0F : "External synchronization operation. Input camera synchronization signal for synchronization with an external devise. (Including other PHOTRON products)"
        }
        
        return pMode.value, mode_dict[pMode.value]
    
    
    def pdcSetCurrentPartition(self, nDeviceNo, nChildNo=1, nNo=1):
        """
        This function sets the current partition number of the specified child device.

        unsigned long PDC_SetCurrentPartition(
            unsigned long nDeviceNo
            unsigned long nChildNo
            unsigned long nNo
            unsigned long *pErrorCode
        )
        
        Parameter
        ---------
            + nDeviceNo 
                Specifies a device number.

            + nChildNo 
                Specifies a child device number.

            + nNo 
                This parameter displays a partition number.

            + pErrorCode 
                This parameter is the variable pointer that retrieves
                an error code.

        Return value
        ------------
            PDC_SUCCEEDED `1` is returned when the function is terminated normally.
            PDC_FAILED `0` is returned when the function is terminated abnormally.
        
        """
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetCurrentPartition(ct.c_ulong(nDeviceNo),   
                                                   ct.c_ulong(nChildNo), 
                                                   ct.c_ulong(nNo),                                                                                                              
                                                   ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetCurrentPartition() error | error code: {pErrorCode.value}"
        

    def pdcSetCommunicationParameter(self, nParamKey, nParamValue):
        """
        Add here.
        
        """
        
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetCommunicationParameter(ct.c_ulong(0x00000002), # PDC_INTTYPE_G_ETHER  
                                                         ct.c_ulong(nParamKey), 
                                                         ct.c_ulong(nParamValue),                                                                                                              
                                                         ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetCommunicationParameter() error | error code: {pErrorCode.value}"
        
        
    def pdcSetPacketIntervalMode(self, nDeviceNo):
        """
        Add doc here.
        
        """
        pErrorCode = ct.c_ulong()
        ret_val = self.lib.PDC_SetPacketIntervalMode(ct.c_ulong(nDeviceNo),   
                                                     ct.c_ulong(1),  # PDC_LINK_SPEED_10G
                                                     ct.c_ulong(19), # packet interval Mode: 1 to 19 (Default vale is 1)                                                                                                      
                                                     ct.byref(pErrorCode))
        assert ret_val == 1, f"pdcSetPacketIntervalMode() error | error code: {pErrorCode.value}"