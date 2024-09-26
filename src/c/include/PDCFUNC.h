/*
 *	PDCFUNC.h
 *	Photron Device Control SDK
 *	Function Definition
 *
 *	Copyright (C) 2006-2012 PHOTRON LIMITED
 */

#ifndef	_PDC_FUNC_H_
#define	_PDC_FUNC_H_

#define PDCAPI WINAPI

#ifdef __cplusplus
extern "C" {
#endif

/*
 *	Initialize etc...
 */
unsigned long PDCAPI
PDC_Init(
        unsigned long 			*pErrorCode
        );

unsigned long PDCAPI
PDC_DetectDevice(
        unsigned long			nInterfaceCode,
        unsigned long			*pDetectNo,
        unsigned long			nDetectNum,
        unsigned long			nDetectParam,
        PPDC_DETECT_NUM_INFO	pDetectNumInfo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_DetectDeviceLV(
        unsigned long			nInterfaceCode,
        unsigned long			*pDetectNo,
        unsigned long			nDetectNum,
        unsigned long			nDetectParam,
        unsigned long			*pDeviceNum,
        unsigned long			*pDeviceCode,
        unsigned long			*pTmpDeviceNo,
        unsigned long			*pInterfaceCode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_OpenDevice(
        PPDC_DETECT_INFO		pDetectInfo,
        unsigned long			*pDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_OpenDevice2(
        PPDC_DETECT_INFO		pDetectInfo,
        long					nMaxRetryCount,
        long					nConnectMode,
        unsigned long			*pDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_OpenDeviceLV(
        unsigned long			nDeviceCode,
        unsigned long			nTmpDeviceNo,
        unsigned long			nInterfaceCode,
        unsigned long			*pDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_OpenDevice2LV(
        unsigned long			nDeviceCode,
        unsigned long			nTmpDeviceNo,
        unsigned long			nInterfaceCode,
        long					nMaxRetryCount,
        long					nConnectMode,
        unsigned long			*pDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_CloseDevice(
        unsigned long			nDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDeviceNameA(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					*pStrName,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_GetDeviceNameW(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        wchar_t					*pStrName,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_GetDeviceName  PDC_GetDeviceNameW
#else
#define PDC_GetDeviceName  PDC_GetDeviceNameA
#endif // !UNICODE

unsigned long PDCAPI
PDC_GetSubInterface(
        unsigned long			nDeviceNo,
        unsigned long			*pIPAddress,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_OpenSubInterface(
        unsigned long			nDeviceNo,
        unsigned long			*pIPAddress,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_OpenSubInterface2(
        unsigned long			nDeviceNo,
        long					nMaxRetryCount,
        long					nConnectMode,
        unsigned long			*pIPAddress,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_CloseSubInterface(
        unsigned long			nDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetNumberOfDevice(
        unsigned long			*pNum,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_IsFunction(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nFunction,
        char					*pFlag,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetInterfaceInfo(
        unsigned long			nInterfaceCode,
        unsigned long			nParam1,
        unsigned long			nParam2,
        unsigned long			nParam3,
        unsigned long			nParam4,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetInterfaceInfo(
        unsigned long			nInterfaceCode,
        unsigned long			*pParam1,
        unsigned long			*pParam2,
        unsigned long			*pParam3,
        unsigned long			*pParam4,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_DeviceStatusUpdate(
        unsigned long			nDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_PingDevice(
        unsigned long			nDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetConnectStatus(
        unsigned long			nDeviceNo,
        unsigned long			*pStatus,
        unsigned long			*pErrorCode
        );


/*
 *	Get List
 */
unsigned long PDCAPI
PDC_GetRecordRateList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetResolutionList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShutterSpeedFpsList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShutterSpeedUsecList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShutterSpeedNsecList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetTriggerModeList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSensorGainModeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSensorGammaModeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetColorTempModeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLUTModeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableRecordRateList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDSShutterModeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVideoOutModeList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShadingModeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetAEShutterFpsList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetAEShutterUsecList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetAEShutterNsecList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetEdgeEnhanceModeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetExternalIOTypeList(
    unsigned long			nDeviceNo,
    unsigned long		   nMode,
    unsigned long			*pSize,
    unsigned long			*pList,
    unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_GetExternalInModeList(
        unsigned long			nDeviceNo,
        unsigned long			nPortNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetExternalOutModeList(
        unsigned long			nDeviceNo,
        unsigned long			nPortNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSyncPriorityList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetExistChildDeviceList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetOpenedDeviceList(
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLUTValueList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nPlane,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLUTOrgValueList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nPlane,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetPartitionList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pCount,
        unsigned long			*pFrames,
        unsigned long			*pBlocks,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetProgSwitchModeList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetPixelGainModeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSyncOutTimesList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetExposeOutTimesList(
        unsigned long			nDeviceNo,
        unsigned long			nSignal,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetColorEnhanceModeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetHeadExchangeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_GetLiveResolutionList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetCameraCommandBaudRateList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDownloadModeList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVideoOutSignalList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVideoOutHDSDIList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetHighSpeedModeList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetBlackClipLevelList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetRecordingTypeList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetADCRangeList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetPartitionIncModeList(
        unsigned long			nDeviceNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );


/*
 *	Set List
 */
unsigned long PDCAPI
PDC_SetLUTValueList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nPlane,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetPartitionList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nCount,
        unsigned long			*pBlocks,
        unsigned long			*pErrorCode
        );

/*
 *	Get Device status
 */
unsigned long PDCAPI
PDC_GetDeviceCode(
        unsigned long			nDeviceNo,
        unsigned long			*pCode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDeviceID(
        unsigned long			nDeviceNo,
        unsigned long			*pID,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetProductID(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pID,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLotID(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pID,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetIndividualID(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pID,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVersion(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pVer,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetColorType(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetStatus(
        unsigned long			nDeviceNo,
        unsigned long			*pStatus,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShutterLockMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetResolutionLockMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetPartitionIncMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetKeyPadLock(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVideoOutMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetChildDeviceCount(
        unsigned long			nDeviceNo,
        unsigned long			*pCount,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMaxChildDeviceCount(
        unsigned long			nDeviceNo,
        unsigned long			*pCount,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetExternalCount(
        unsigned long			nDeviceNo,
        unsigned long			*pIn,
        unsigned long			*pOut,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetExternalInMode(
        unsigned long			nDeviceNo,
        unsigned long			nPort,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetExternalOutMode(
        unsigned long			nDeviceNo,
        unsigned long			nPort,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetIRIG(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMCDL(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetADC(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetADCRange(
        unsigned long			nDeviceNo,
        unsigned long			nADCChannel,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetIRIGOffset(
        unsigned long			nDeviceNo,
        long					*pValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetIRIGSampleMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_GetRecordRate(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pRate,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetTriggerMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pAFrames,
        unsigned long			*pRFrames,
        unsigned long			*pRCount,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetResolution(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetResolutionROI(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShutterSpeedFps(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pFps,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShutterSpeedUsec(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pUsec,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShutterSpeedNsec(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pNsec,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMaxPartition(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pCount,
        unsigned long			*pBlock,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetCurrentPartition(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSensorGainMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSensorGammaMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetColorTempMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pR,
        unsigned long			*pG,
        unsigned long			*pB,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSoftColorTempMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pR,
        unsigned long			*pG,
        unsigned long			*pB,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetAutoExposure(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLUTMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDSShutterMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDSShutterValue(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetEdgeEnhanceMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShadingMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShadingTypeList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pSize,
        unsigned long			*pList,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetPixelGainMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMaxFrames(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pFrames,
        unsigned long			*pBlocks,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMaxResolution(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSegmentPosition(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pXPos,
        unsigned long			*pYPos,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableMaxResolution(
        unsigned long			nDeviceNo,
        unsigned long			nRate,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableMaxWidth(
        unsigned long			nDeviceNo,
        unsigned long			nRate,
        unsigned long			nHeight,
        unsigned long			*pWidth,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableMaxHeight(
        unsigned long			nDeviceNo,
        unsigned long			nRate,
        unsigned long			nWidth,
        unsigned long			*pHeight,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableMaxRate(
        unsigned long			nDeviceNo,
        unsigned long			nWidth,
        unsigned long			nHeight,
        unsigned long			*pRate,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableChannel(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pChannel,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableChannelInfo(
        unsigned long			nDeviceNo,
        unsigned long			nChannel,
        unsigned long			*pRate,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pXPos,
        unsigned long			*pYPos,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableChannelInfo2(
        unsigned long			nDeviceNo,
        unsigned long			nChannel,
        unsigned long			*pRate,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pXPos,
        unsigned long			*pYPos,
        unsigned long			*pIRIG,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableChannelInfo3(
        unsigned long			nDeviceNo,
        unsigned long			nChannel,
        unsigned long			*pRate,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pXPos,
        unsigned long			*pYPos,
        unsigned long			*pIRIG,
        unsigned long			*pHSMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetEnableVariableChannelSetting(
        unsigned long			nDeviceNo,
        unsigned long			pRate,
        unsigned long			pWidth,
        unsigned long			pHeight,
        unsigned long			*pEnable,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetAutoExposureInfo(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pXPos,
        unsigned long			*pYPos,
        unsigned long			*pValue,
        unsigned long			*pRange,
        unsigned long			*pLimit,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMaxBitDepth(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					*pDepth,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLUTParams(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nLUTMode,
        PPDC_LUT_PARAMS			pParams,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDelay(
        unsigned long			nDeviceNo,
        unsigned long			nSignal,
        unsigned long			*pValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDelayLimit(
        unsigned long			nDeviceNo,
        unsigned long			nSignal,
        unsigned long			*pValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDelayLimitEx(
        unsigned long			nDeviceNo,
        unsigned long			nSignal,
        unsigned long			*pValue_max,
        unsigned long			*pValue_min,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVariableRestriction(
        unsigned long			nDeviceNo,
        unsigned long			*pWidthStep,
        unsigned long			*pHeightStep,
        unsigned long			*pXPosStep,
        unsigned long			*pYPosStep,
        unsigned long			*pWidthMin,
        unsigned long			*pHeightMin,
        unsigned long			*pFreePos,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetColorEnhanceValue(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nPlane,
        long					*pR,
        long					*pG,
        long					*pB,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetColorEnhanceMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDownloadMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetCamMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMaxFullResoRate(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pRate,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLowLightMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetProgSwitchMode(
        unsigned long			nDeviceNo,
        unsigned long			nSwitchNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetColorTempBase(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pBase,
        unsigned long			*pMax,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetAutoExposureRestriction(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pWidthStep,
        unsigned long			*pHeightStep,
        unsigned long			*pXPosStep,
        unsigned long			*pYPosStep,
        unsigned long			*pWidthMin,
        unsigned long			*pHeightMin,
        unsigned long			*pMaxValue,
        unsigned long			*pMaxRange,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSyncOutTimes(
        unsigned long			nDeviceNo,
        unsigned long			*pRatio,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetStoreNum(
        unsigned long			nDeviceNo,
        unsigned long			*pNum,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetEthernetInfo(
        unsigned long			nDeviceNo,
        unsigned long			nTarget,
        unsigned long			*pValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetConnectedEthernetInfo(
        unsigned long			nDeviceNo,
        unsigned long			nTarget,
        unsigned long			*pValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetIRIGPhaseLock(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetIRIGPhaseLockStatus(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetHighSpeedMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetBurstTransfer(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetHeadExchange(
        unsigned long			nDeviceNo,
        unsigned long			*pNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetHeadTypeNameA(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nHeadNo,
        char					*pStrName,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_GetHeadTypeNameW(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nHeadNo,
        wchar_t					*pStrName,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_GetHeadTypeName  PDC_GetHeadTypeNameW
#else
#define PDC_GetHeadTypeName  PDC_GetHeadTypeNameA
#endif // !UNICODE

unsigned long PDCAPI
PDC_GetStepShutter(
        unsigned long			nDeviceNo,
        unsigned long			*pStep,
        unsigned long			*pMin,
        unsigned long			*pMax,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_GetLiveResolutionMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetCameraCommandBaudRate(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pRate,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetBitDepth(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					*pDepth,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetBitDepth2(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					*pDepth,
        unsigned long			*pBitSel,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSyncPriority(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVideoOutSignal(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVideoOutSignalEnable(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetVideoOutHDSDI(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetRecordingType(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetPixelGainData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetAutoPlay(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetFactoryDefaults(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetStorePreset(
        unsigned long			nDeviceNo,
        unsigned long			*pNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetStorePresetReboot(
        unsigned long			nDeviceNo,
        unsigned long			*pReboot,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_GetInstructionSet(
        unsigned long			nDeviceNo,
        unsigned long			*pInstSetCode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLEDMode(
        unsigned long			nDeviceNo,
        unsigned long			*pLEDMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetBatteryPowerMode(
        unsigned long			nDeviceNo,
        unsigned long			*pBattery,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_GetSyncInSignalStatus(
        unsigned long			nDeviceNo,
        unsigned long			*pStatus,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLiveIRIGData(
        unsigned long			nDeviceNo,
        PPDC_IRIG_INFO			pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetPolarizerConfig(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetShadingType(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_GetShadingAvailable(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pAvailable,
        unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_GetBlackClipLevel(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSubInterfaceMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetExposeExtension(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetImageTrigger(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetImageTriggerInfo(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pXPos,
        unsigned long			*pYPos,
        unsigned long			*pValue,
        unsigned long			*pRange,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetImageTriggerRestriction(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pWidthStep,
        unsigned long			*pHeightStep,
        unsigned long			*pXPosStep,
        unsigned long			*pYPosStep,
        unsigned long			*pWidthMin,
        unsigned long			*pHeightMin,
        unsigned long			*pMaxValue,
        unsigned long			*pMaxRange,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetImageTriggerConditions(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pConditions,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetRTC(
        unsigned long			nDeviceNo,
        unsigned long			*pYear,
        unsigned long			*pMonth,
        unsigned long			*pDay,
        unsigned long			*pHour,
        unsigned long			*pMinute,
        unsigned long			*pSecond,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemoryModePartition(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLensControl(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pType,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetGetherTransferMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMechaShutterMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

//Hieu ExposeTime
unsigned long PDCAPI 
PDC_GetExposeTimeData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long					*pBuf,
        unsigned long			*pNum,
        unsigned long			*pErrorCode
        );

//hieu recon cmd 20131024
unsigned long PDCAPI
PDC_GetCurrentFramesRecorded(
        unsigned long			nDeviceNo,
        unsigned long			*pParam,
        unsigned long			*pErrorCode
        );

/*	FAN Control*/
unsigned long PDCAPI
PDC_GetFanCtrl(
        unsigned long			nDeviceNo,
        unsigned long			*pCtrl,
        unsigned long			*pUsed,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetFanState(
        unsigned long			nDeviceNo,
        unsigned long			*pState,
        unsigned long			*pOnState,
        unsigned long			*pErrorCode
        );

/*	SD CARD Control*/
unsigned long PDCAPI
PDC_GetSdCardCtrl(
        unsigned long 			nDeviceNo,
        unsigned long 			*pCtrl,
        unsigned long 			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSdCardState(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			*pInOut,
        unsigned long			*pProtect,
        unsigned long			*pFormat,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSdCardInfo(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			*pSpeedMode,
        unsigned long			*pSpeedClass,
        unsigned long			*pSize,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSdCardDataRecDate(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			nDataNo,
        unsigned long			*pDate,
        unsigned long			*pTime,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSdCardDataRecFrames(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			nDataNo,
        unsigned long			*pFrames,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSdCardMemoryMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetSdCardRunState(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			*pState,
        unsigned long			*pOption,
        unsigned long			*pErrorCode
        );

//
// SSD BOX
//
unsigned long PDCAPI
PDC_GetSSDBoxInfo(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			*pTotal,
        unsigned long			*pAvailable,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_GetSSDBoxDataName(
        unsigned long nDeviceNo,
        unsigned long nSlotNo,
        unsigned long nDataNo,
        char *pName,
        unsigned long *pErrorCode
        );

unsigned long PDCAPI 
PDC_SetSSDBoxDataName(
        unsigned long nDeviceNo,
        unsigned long nSlotNo,
        unsigned long nDataNo,
        char *pName,
        unsigned long *pErrorCode
        );

unsigned long PDCAPI
PDC_GetSSDBoxCtrl(
        unsigned long 			nDeviceNo,
        unsigned long 			*pCtrl,
        unsigned long 			*pErrorCode
        );

//
// FAST Drive
//
unsigned long PDCAPI
PDC_GetFASTDriveInfo(
    unsigned long			nDeviceNo,
    unsigned long			*pTotal,
    unsigned long			*pAvailable,
    unsigned long			*pErrorCode
    );

unsigned long PDCAPI
PDC_GetFASTDriveInfo2(
    unsigned long			nDeviceNo,
    unsigned long			nSlotNo,
    unsigned long			*pTotal,
    unsigned long			*pAvailable,
    unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_GetStorageMode(
    unsigned long			nDeviceNo,
    unsigned long			*pMode,
    unsigned long			*pErrorCode
    );

unsigned long PDCAPI
PDC_GetFASTDriveState(
    unsigned long			nDeviceNo,
    unsigned long			nSlotNo,
    unsigned long			*pInOut,
    unsigned long			*pFormat,
    unsigned long			*pErrorCode
    );

unsigned long PDCAPI
PDC_GetFASTDriveDataName(
    unsigned long nDeviceNo,
    unsigned long nDataNo,
    char *pName,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI
PDC_GetFASTDriveDataName2(
    unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    char *pName,
    unsigned long *pErrorCode
);

unsigned long PDCAPI
PDC_SetFASTDriveDataName(
    unsigned long nDeviceNo,
    unsigned long nDataNo,
    char *pName,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI
PDC_SetFASTDriveDataName2(
    unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    char *pName,
    unsigned long *pErrorCode
);

unsigned long PDCAPI
PDC_GetFASTDriveCtrl(
    unsigned long 			nDeviceNo,
    unsigned long 			*pCtrl,
    unsigned long 			*pErrorCode
    );

unsigned long PDCAPI
PDC_GetFASTDriveDataRecDate(
    unsigned long			nDeviceNo,
    unsigned long			nSlotNo,
    unsigned long			nDataNo,
    unsigned long			*pDate,
    unsigned long			*pTime,
    unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_GetFASTDriveDataRecFrames(
    unsigned long			nDeviceNo,
    unsigned long			nSlotNo,
    unsigned long			nDataNo,
    unsigned long			*pFrames,
    unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_SetFASTDriveFormatRequest(
    unsigned long			nDeviceNo,
    unsigned long			nSlotNo,
    unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_SetFASTDriveCancelRequest(
    unsigned long			nDeviceNo,
    unsigned long			nSlotNo,
    unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_SetFASTDriveResetRequest(
    unsigned long			nDeviceNo,
    unsigned long			nSlotNo,
    unsigned long			*pErrorCode
);
unsigned long PDCAPI
PDC_SetFASTDriveSaveRequest(
    unsigned long			nDeviceNo,
    unsigned long			nSlotNo,
    unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_GetFASTDriveRunState(
    unsigned long			nDeviceNo,
    unsigned long			nSlotNo,
    unsigned long			*pState,
    unsigned long			*pOption,
    unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_GetFASTDriveSaveSlotNo(
    unsigned long			nDeviceNo,
    unsigned long			nChildNo,
    unsigned long*			nSlotNo,
    unsigned long			*pErrorCode
);

//
// Media(CFast)
//
unsigned long PDCAPI
PDC_SetMediaSaveRequest(
    unsigned long	nDeviceNo,
    unsigned long	nSlotNo,
    long			nStartFrame,
    long			nFrameCount,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_SetMediaCancelRequest(
    unsigned long	nDeviceNo,
    unsigned long	nSlotNo,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_GetMediaState(
    unsigned long	nDeviceNo,
    unsigned long	nSlotNo,
    unsigned long	*pInOut,
    unsigned long	*pProtect,
    unsigned long	*pFormat,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_GetMediaRunState(
    unsigned long	nDeviceNo,
    unsigned long	nSlotNo,
    unsigned long	*pState,
    unsigned long	*pOption,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_SetMediaFormatRequest(
    unsigned long	nDeviceNo,
    unsigned long	nSlotNo,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_GetMediaInfo(
    unsigned long	nDeviceNo,
    unsigned long	nSlotNo,
    PPDC_MEDIA_INFO	pInfo,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_GetMediaRecordInfo(
    unsigned long		nDeviceNo,
    unsigned long		nSlotNo,
    unsigned long		nDataNo,
    PPDC_RECORD_INFO	pRecInfo,
    unsigned long		*pErrorCode
);

unsigned long PDCAPI PDC_OpenMedia(
    unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long *pErrorCode
);

unsigned long PDCAPI PDC_CloseMedia(
    unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long *pErrorCode
);

unsigned long PDCAPI PDC_GetMediaImage(
    unsigned long	nDeviceNo,
    unsigned long	nSlotNo,
    unsigned long	nDataNo,
    long			nFrameNo,
    unsigned long	nInterleave,
    void			*pData,
    unsigned long	*pErrorCode
);

/*
 *	Get Recorded status
 */
unsigned long PDCAPI
PDC_GetMemIRIG(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemMCDL(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemADC(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemADCRange(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nADCChannel,
        unsigned long			*pMode,
        unsigned long			*pErrorCode);

unsigned long PDCAPI
PDC_GetAdcInfo(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pNumberOfChannel,
        unsigned long			*pSamplePerFrame,
        unsigned long			*pErrorCode);

unsigned long PDCAPI
PDC_GetMemRecordRate(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pRate,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemTriggerMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pAFrames,
        unsigned long			*pRFrames,
        unsigned long			*pRCount,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemResolution(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemResolutionROI(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pWidth,
        unsigned long			*pHeight,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemShutterSpeedFps(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pFps,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemShutterSpeedUsec(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pUsec,
        unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_GetMemShutterSpeedNsec(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pNsec,
        unsigned long			*pErrorCode
);


unsigned long PDCAPI
PDC_GetMemSensorGainMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemSensorGammaMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemColorTempMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pR,
        unsigned long			*pG,
        unsigned long			*pB,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemAutoExposure(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemLUTMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemDSShutterMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemDSShutterValue(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemEdgeEnhanceMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetTransferOption(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*p8BitSel,
        unsigned long			*pBayer,
        unsigned long			*pInterleave,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemFrameInfo(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        PPDC_FRAME_INFO			pFrame,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemColorEnhanceValue(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nPlane,
        long					*pR,
        long					*pG,
        long					*pB,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemColorEnhanceMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemIRIGPhaseLockStatus(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_GetMemLiveResolutionMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemBitDepth(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					*pDepth,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemBitDepth2(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					*pDepth,
        unsigned long			*pBitSel,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemSegmentPosition(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pXpos,
        unsigned long			*pYpos,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetInitialError(
        unsigned long			nDeviceNo,
        unsigned long			nHeadCount,
        unsigned long			*pErrorNumber,
        unsigned long			*pErrorOption,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_GetLastError(
        unsigned long			nDeviceNo,
        unsigned long			*pType,
        unsigned long			*pErrorNumber,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_GetIgnoreTriggerNumber(
        unsigned long			nDeviceNo,
        unsigned long			*pNumber,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetExtSyncOverSync(
        unsigned long			nDeviceNo,
        unsigned long			*pStatus,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetHeadLedLaser(
        unsigned long 			nDeviceNo,
        unsigned long 			nChildNo,
        unsigned long 			*pLedStatus,
        unsigned long 			*pLaserStatus,
        unsigned long 			*pErrorCode
        );
unsigned long PDCAPI
PDC_GetLensInfo(
        unsigned long 			nDeviceNo,
        unsigned long 			nChildNo,
        unsigned long 			*pLensType,
        unsigned long 			*pErrorCode
        );
unsigned long PDCAPI
PDC_GetSelfSyncMode(
        unsigned long			nDeviceNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetRandomTriggerEnable(
        unsigned long nDeviceNo,
        unsigned long nChildNo,
        BOOL *pEnable,
        unsigned long *pErrorCode
        );

unsigned long PDCAPI
PDC_GetMaxRandomTriggerCount(
        unsigned long nDeviceNo,
        unsigned long nChildNo,
        unsigned long *pMaxRandomCount,
        unsigned long *pErrorCode
        );

unsigned long PDCAPI PDC_GetMaxRandomEndlessTriggerCount(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long *pMaxRandomCount,
    unsigned long *pErrorCode
    );


unsigned long PDCAPI
PDC_GetLowFrameRateMode(
        unsigned long nDeviceNo,
        unsigned long *pMode,
        unsigned long *pErrorCode
        );

unsigned long PDCAPI PDC_GetAccelerationSensorError(
        unsigned long nDeviceNo,
        unsigned long *pErrorNumber,
        unsigned long *pErrorCode
);


/*
 *	Set Device status
 */
unsigned long PDCAPI
PDC_SetActiveChild(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetStatus(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetRecReady(
        unsigned long			nDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetEndless(
        unsigned long			nDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_TriggerIn(
        unsigned long			nDeviceNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetShutterLockMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetResolutionLockMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetPartitionIncMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetKeyPadLock(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetVideoOutMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetExternalInMode(
        unsigned long			nDeviceNo,
        unsigned long			nPort,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetExternalOutMode(
        unsigned long			nDeviceNo,
        unsigned long			nPort,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetIRIG(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetIRIGSampleMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
);


unsigned long PDCAPI
PDC_SetMCDL(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetADC(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetADCRange(
        unsigned long			nDeviceNo,
        unsigned long			nADCChannel,
        unsigned long			nMode,
        unsigned long			*pErrorCode
    );

unsigned long PDCAPI
PDC_SetIRIGOffset(
        unsigned long			nDeviceNo,
        long					nValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetRecordRate(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nRate,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetTriggerMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			nAFrames,
        unsigned long			nRFrames,
        unsigned long			nRCount,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetResolution(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nWidth,
        unsigned long			nHeight,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetResolutionROI(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nWidth,
        unsigned long			nHeight,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetShutterSpeedFps(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nFps,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetCurrentPartition(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSensorGainMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSensorGammaMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetColorTempMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			nR,
        unsigned long			nG,
        unsigned long			nB,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSoftColorTempMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			nR,
        unsigned long			nG,
        unsigned long			nB,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetAutoExposure(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetLUTMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetDSShutterMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetDSShutterValue(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetEdgeEnhanceMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetShadingMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetPixelGainMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetTransferOption(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			n8BitSel,
        unsigned long			nBayer,
        unsigned long			nInterleave,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_EraseVariableChannel(
        unsigned long			nDeviceNo,
        unsigned long			nChannel,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetVariableChannel(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nChannel,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetVariableChannelInfo(
        unsigned long			nDeviceNo,
        unsigned long			nChannel,
        unsigned long			nRate,
        unsigned long			nWidth,
        unsigned long			nHeight,
        unsigned long			nXPos,
        unsigned long			nYPos,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetAutoExposureInfo(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nWidth,
        unsigned long			nHeight,
        unsigned long			nXPos,
        unsigned long			nYPos,
        unsigned long			nValue,
        unsigned long			nRange,
        unsigned long			nLimit,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetLUTUserParams(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nLUTMode,
        PPDC_LUT_PARAMS			pParams,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_CreatePixelGainData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        void					*pSrc,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetPixelGainData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        void					*pSrc,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetLUTUser(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetDelay(
        unsigned long			nDeviceNo,
        unsigned long			nSignal,
        unsigned long			nValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetColorEnhanceMode(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetDownloadMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetLowLightMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetProgSwitchMode(
        unsigned long			nDeviceNo,
        unsigned long			nSwitchNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSyncOutTimes(
        unsigned long			nDeviceNo,
        unsigned long			nRatio,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetStore(
        unsigned long			nDeviceNo,
        unsigned long			nNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetEthernetInfo(
        unsigned long			nDeviceNo,
        unsigned long			nTarget,
        unsigned long			nValue,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetIRIGPhaseLock(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetHighSpeedMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetBurstTransfer(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetHeadExchange(
        unsigned long			nDeviceNo,
        unsigned long			nNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_SetLiveResolutionMode( 
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetColorType(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetBitDepth(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					nDepth,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetBitDepth2(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        char					nDepth,
        unsigned long			nBitSel,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetCameraCommandBaudRate(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nRate,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSegmentPosition(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nXPos,
        unsigned long			nYPos,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSyncPriority(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetDeviceID(
        unsigned long			nDeviceNo,
        unsigned long			nID,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetVideoOutSignal(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetVideoOutSignalEnable(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetVideoOutHDSDI(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetRecordingType(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetAutoPlay(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetFactoryDefaults(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetStorePreset(
        unsigned long			nDeviceNo,
        unsigned long			nNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetInstructionSet(
        unsigned long			nDeviceNo,
        unsigned long			nInstSetCode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_SetLEDMode(
        unsigned long			nDeviceNo,
        unsigned long			nLEDMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_SetBatteryPowerMode(
        unsigned long			nDeviceNo,
        unsigned long			nBattery,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetBatteryFunction(
        unsigned long nDeviceNo,
        unsigned long nValue,
        unsigned long *pErrorCode
        );

unsigned long PDCAPI
PDC_SetKeyPadCommand(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetShadingType(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetBlackClipLevel(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetExposeExtension(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetImageTrigger(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetImageTriggerInfo(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nWidth,
        unsigned long			nHeight,
        unsigned long			nXPos,
        unsigned long			nYPos,
        unsigned long			nValue,
        unsigned long			nRange,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetRTC(
        unsigned long			nDeviceNo,
        unsigned long			nYear,
        unsigned long			nMonth,
        unsigned long			nDay,
        unsigned long			nHour,
        unsigned long			nMinute,
        unsigned long			nSecond,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetLensControlData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nSendDataSize,
        char					*pSendData,
        unsigned long			*pRecvDataSize,
        char					*pRecvData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetMemoryModePartition(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_SetGEtherTransferMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_SetMechaShutterMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetMechaShutterFunction(
        unsigned long			nDeviceNo,
        unsigned long			nValue,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_SetLowFrameRateMode(
        unsigned long nDeviceNo,
        unsigned long nMode,
        unsigned long *pErrorCode
        );

/*	Fan control	*/
unsigned long PDCAPI
PDC_SetFanCtrl(
        unsigned long			nDeviceNo,
        unsigned long			nValue,
        unsigned long			*pErrorCode
        );

/*	SD card control	*/
unsigned long PDCAPI
PDC_SetSdCardMemoryMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSdCardFormatRequest(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSdCardCancelRequest(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSdCardResetRequest(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_SetSdCardSaveRequest(
        unsigned long			nDeviceNo,
        unsigned long			nSlotNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetHeadLedLaser(
        unsigned long 			nDeviceNo,
        unsigned long 			nChildNo,
        unsigned long 			nLedStatus,
        unsigned long 			nLaserStatus,
        unsigned long 			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetFourThirdsLensControlData(
        unsigned long 			nDeviceNo,
        unsigned long 			nChildNo,
        unsigned char 			nCommandType,
        unsigned char 			nCommandCode,
        unsigned char 			nParam1,
        unsigned char 			nParam2,
        unsigned long 			nSendDataSize,
        char 					*pSendData,
        unsigned long 			*pRecvDataSize,
        char 					*pRecvData,
        unsigned long 			*pResult,
        unsigned long 			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetSelfSyncMode(
        unsigned long			nDeviceNo,
        unsigned long			nMode,
        unsigned long			*pErrorCode
        );

/*
 *	Get Image
 */
unsigned long PDCAPI
PDC_GetLiveImageData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nBitDepth,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLiveImageAddress(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        void					**pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemImageData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			nBitDepth,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemImageDataStart(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			nBitDepth,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemImageDataEnd(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nBitDepth,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemImageAddress(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        void					**pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemIRIGData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        PPDC_IRIG_INFO			pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemMCDLData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        PPDC_MCDL_INFO			pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemIRIGandMCDLData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			nFrameNum,
        PPDC_IRIGMCDL_INFO		pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemMCDLByteData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			nFrameNum,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemADCByteData(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			nFrameNum,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetFASTDriveADCByteData(
    unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    long nFrameNo,
    unsigned long nFrameNum,
    void *pData,
    unsigned long *pErrorCode);

unsigned long PDCAPI
PDC_GetFASTDriveMemBufUseByteData(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    long nFrameNo,
    unsigned long nFrameNum,
    void *pData,
    unsigned long *pErrorCode);

unsigned long PDCAPI
PDC_GetMemAutoExposureDataFps(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        PPDC_AUTO_EXPOSURE_INFO	pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemAutoExposureDataNsec(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			nFrameNum,
        PPDC_AUTO_EXPOSURE_INFO	pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_DrawLiveImage(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        HDC						hDC,
        unsigned long			nDisplayMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_DrawMemImage(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        HDC						hDC,
        unsigned long			nDisplayMode,
        long					nFrameNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLiveMemImageData(
                        unsigned long			nDeviceNo,
                        unsigned long			nChildNo,
                        unsigned long			nBitDepth,
                        void					*pData,
                        unsigned long			*pErrorCode
                        );

/*
 *	FPGA Setting
 */
unsigned long PDCAPI
PDC_FPGAConfigA(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCSTR					lpszFileName,
        unsigned long			nProgramMode,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_FPGAConfigW(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCWSTR					lpszFileName,
        unsigned long			nProgramMode,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_FPGAConfig  PDC_FPGAConfigW
#else
#define PDC_FPGAConfig  PDC_FPGAConfigA
#endif // !UNICODE

unsigned long PDCAPI
PDC_GetFPGAStatus(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pStatus,
        unsigned long 			*pBytesCompleted,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_LoadFPGAConfigFileA(
        unsigned long	nDeviceNo,
        LPCSTR			lpszPath,
        unsigned char	*pInfo,
        unsigned long	nSize,
        unsigned long	*pErrorCode
        );
unsigned long PDCAPI
PDC_LoadFPGAConfigFileW(
        unsigned long	nDeviceNo,
        LPCWSTR			lpszPath,
        unsigned char	*pInfo,
        unsigned long	nSize,
        unsigned long	*pErrorCode
        );
#ifdef UNICODE
#define PDC_LoadFPGAConfigFile  PDC_LoadFPGAConfigFileW
#else
#define PDC_LoadFPGAConfigFile  PDC_LoadFPGAConfigFileA
#endif // !UNICODE

unsigned long PDCAPI
PDC_SetReset_FPGA(
        unsigned long nDeviceNo,
        unsigned long nEnable,
        unsigned long nFPGAType,
        unsigned long *pErrorCode
        );

/*
 *	File Save
 */
unsigned long PDCAPI
PDC_BMPFileSaveA(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCSTR					lpszFileName,
        long					nFrameNo,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_BMPFileSaveW(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCWSTR					lpszFileName,
        long					nFrameNo,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_BMPFileSave  PDC_BMPFileSaveW
#else
#define PDC_BMPFileSave  PDC_BMPFileSaveA
#endif // !UNICODE

unsigned long PDCAPI
PDC_AVIFileSaveOpenA(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCSTR					lpszFileName,
        long					nRate,
        unsigned long			nShowCompressDlg,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_AVIFileSaveOpenW(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCWSTR					lpszFileName,
        long					nRate,
        unsigned long			nShowCompressDlg,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_AVIFileSaveOpen  PDC_AVIFileSaveOpenW
#else
#define PDC_AVIFileSaveOpen  PDC_AVIFileSaveOpenA
#endif // !UNICODE

unsigned long PDCAPI
PDC_AVIFileSave(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			*pSize,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_AVIFileSaveClose(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_MRAWFileSaveOpenA(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCSTR					lpszFileName,
        unsigned long			nMRawBitDepth,
        long					nMaxFrameNum,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_MRAWFileSaveOpenW(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCWSTR					lpszFileName,
        unsigned long			nMRawBitDepth,
        long					nMaxFrameNum,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_MRAWFileSaveOpen  PDC_MRAWFileSaveOpenW
#else
#define PDC_MRAWFileSaveOpen  PDC_MRAWFileSaveOpenA
#endif // !UNICODE

unsigned long PDCAPI 
PDC_MRAWFileSave(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_MRAWFileSaveClose(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo, 
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_MRAWFileSaveOpenExA(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCSTR					lpszFileName,
        unsigned long			nMRawBitDepth,
        long					nMaxFrameNum,
        long					nConnectMode2P,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_MRAWFileSaveOpenExW(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        LPCWSTR					lpszFileName,
        unsigned long			nMRawBitDepth,
        long					nMaxFrameNum,
        long					nConnectMode2P,
        unsigned long			*pErrorCode
        );
#ifdef UNICODE
#define PDC_MRAWFileSaveOpenEx PDC_MRAWFileSaveOpenExW
#else
#define PDC_MRAWFileSaveOpenEx PDC_MRAWFileSaveOpenExA
#endif // !UNICODE

unsigned long PDCAPI
PDC_MRAWFileSaveStartEx(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nStartFrameNum,
        long					nEndFrameNum,
        unsigned long			*pErrorCode
);

unsigned long PDCAPI
PDC_MRAWFileSaveCancelEx(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_MRAWFileSaveStatusEx(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					*pSaving,
        long					*pFrameNum,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_MRAWFileSaveCloseEx(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pErrorCode
);

/*
 *	File Load
 */
unsigned long PDCAPI 
PDC_MRAWFileLoadOpenA(
        LPCSTR					lpszFileName,
        PPDC_IMAGE_BUFF_INFO	pInfo,
        unsigned long			nMRawBitDepth,
        unsigned long			*pFileNo,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_MRAWFileLoadOpenW(
        LPCWSTR					lpszFileName,
        PPDC_IMAGE_BUFF_INFO	pInfo,
        unsigned long			nMRawBitDepth,
        unsigned long			*pFileNo,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_MRAWFileLoadOpen  PDC_MRAWFileLoadOpenW
#else
#define PDC_MRAWFileLoadOpen  PDC_MRAWFileLoadOpenA
#endif // !UNICODE

unsigned long PDCAPI 
PDC_MRAWFileLoadOpen2A(
        LPCSTR					lpszFileName,
        PPDC_IMAGE_BUFF_INFO	pInfo,
        unsigned long			nMRawBitDepth,
        unsigned long			*pSessionNo,
        PPDC_ORG_IMAGE_INFO		pOrgInfo,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_MRAWFileLoadOpen2W(
        LPCWSTR					lpszFileName,
        PPDC_IMAGE_BUFF_INFO	pInfo,
        unsigned long			nMRawBitDepth,
        unsigned long			*pSessionNo,
        PPDC_ORG_IMAGE_INFO		pOrgInfo,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_MRAWFileLoadOpen2  PDC_MRAWFileLoadOpen2W
#else
#define PDC_MRAWFileLoadOpen2  PDC_MRAWFileLoadOpen2A
#endif // !UNICODE

unsigned long PDCAPI 
PDC_MRAWFileLoad(
        unsigned long			nFileNo,
        long					nFrame,
        void					*pBuff,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_MRAWFileLoadClose(
        unsigned long			nFileNo,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_RAWFileLoadA(
        LPCSTR					lpszFileName,
        PPDC_IMAGE_BUFF_INFO	pInfo,
        unsigned long			nRawBitDepth,
        void					*pBuff,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_RAWFileLoadW(
        LPCWSTR					lpszFileName,
        PPDC_IMAGE_BUFF_INFO	pInfo,
        unsigned long			nRawBitDepth,
        void					*pBuff,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_RAWFileLoad  PDC_RAWFileLoadW
#else
#define PDC_RAWFileLoad  PDC_RAWFileLoadA
#endif // !UNICODE

unsigned long PDCAPI 
PDC_RAWFileLoad2A(
        LPCSTR					lpszFileName,
        PPDC_IMAGE_BUFF_INFO	pInfo,
        unsigned long			nRawBitDepth,
        void					*pBuff,
        PPDC_ORG_IMAGE_INFO		pOrgInfo,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_RAWFileLoad2W(
        LPCWSTR					lpszFileName,
        PPDC_IMAGE_BUFF_INFO	pInfo,
        unsigned long			nRawBitDepth,
        void					*pBuff,
        PPDC_ORG_IMAGE_INFO		pOrgInfo,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_RAWFileLoad2  PDC_RAWFileLoad2W
#else
#define PDC_RAWFileLoad2  PDC_RAWFileLoad2A
#endif // !UNICODE

/*
 *	Camera Link Control
 */
unsigned long PDCAPI
PDC_ReadCameraDefFileA(
        unsigned long			nDeviceNo,
        LPCSTR					lpszFileName,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_ReadCameraDefFileW(
        unsigned long			nDeviceNo,
        LPCWSTR					lpszFileName,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_ReadCameraDefFile  PDC_ReadCameraDefFileW
#else
#define PDC_ReadCameraDefFile  PDC_ReadCameraDefFileA
#endif // !UNICODE

unsigned long PDCAPI
PDC_WriteCameraDefFileA(
        unsigned long			nDeviceNo,
        LPCSTR					lpszFileName,
        unsigned long			*pErrorCode
        );
unsigned long PDCAPI
PDC_WriteCameraDefFileW(
        unsigned long			nDeviceNo,
        LPCWSTR					lpszFileName,
        unsigned long			*pErrorCode
);
#ifdef UNICODE
#define PDC_WriteCameraDefFile  PDC_WriteCameraDefFileW
#else
#define PDC_WriteCameraDefFile  PDC_WriteCameraDefFileA
#endif // !UNICODE

unsigned long PDCAPI
PDC_SetCameraCommand(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned char			*pBuf,
        unsigned long			nSize,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_GetCameraLinkStatus(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pMode,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_GetBayerAlignment(
        unsigned long			nDeviceNo,
        unsigned long			*pBayerAlign,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI 
PDC_SetBayerAlignment(
        unsigned long			nDeviceNo,
        unsigned long			nBayerAlign,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemory(
        unsigned long			nDeviceNo,
        unsigned long			*pBlockAvailable,
        unsigned long			*pBlockReserved,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetMemory(
        unsigned long			nDeviceNo,
        unsigned long			nOption,
        unsigned long			nBlocks,
        unsigned long			nFramePerBlock,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetNumofDropFrame(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pDropFrame,
        unsigned long			*pErrorCode
        );

#if _MSC_VER < 1300
#define ulonglong unsigned __int64
#else
#define ulonglong unsigned long long
#endif

unsigned long PDCAPI
PDC_GetMemoryInfo(
        unsigned long nDeviceNo,
            ulonglong* pAvailableMemory,
            ulonglong* pReservedMemory,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetDropFrameList(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        PPDC_DROP_FRAME_LIST	pList,
        unsigned long			*pSize,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetLiveImageAddress2(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			*pFrameNo,
        void					**pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemImageData2(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			nBitDepth,
        unsigned long			nPort,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemImageDataStart2(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        long					nFrameNo,
        unsigned long			nBitDepth,
        unsigned long			nPort,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_GetMemImageDataEnd2(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nBitDepth,
        unsigned long			nPort,
        void					*pData,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_SetMemImageMode(
        unsigned long nMemImageMode,
        unsigned long *pErrorCode
);

unsigned long PDCAPI
PDC_MultipleGetMemImageDataInit(
        unsigned long			nDeviceNo,
        unsigned long			nChildNo,
        unsigned long			nBitDepth,
        PPDC_SAVE_FRAME_INFO	pFrameInfo,
        long					nConnectMode2P,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI
PDC_MultipleGetMemImageData(
        unsigned long	nDeviceNo,
        unsigned long	nChildNo,
        long			nFrameNo,
        void			*pData,
        unsigned long   *pErrorCode
        );

unsigned long PDCAPI
PDC_MultipleGetMemImageDataCancel(
        unsigned long nDeviceNo,
        unsigned long nChildNo,
        unsigned long *pErrorCode
);

unsigned long PDCAPI
PDC_MultipleGetMemImageDataExit(
        unsigned long nDeviceNo,
        unsigned long nChildNo,
        unsigned long *pErrorCode
);

/*
 *	Image Processing
 */
unsigned long PDCAPI
PDC_ConvertBayerImageData(
        PPDC_IMAGE_BUFF_INFO	pInfo, 
        PPDC_BAYER_CONVERT_INFO	pBayerInfo,
        void					*pSrc,
        void					*pDes,
        unsigned long			*pErrorCode
        );

unsigned long PDCAPI PDC_SetRandomTriggerEnable(
        unsigned long nDeviceNo,
        unsigned long nMode,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetResetTriggerExposeDelay(
    unsigned long nDeviceNo,
    unsigned long *pValue,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetDeadTimeValue(
    unsigned long nDeviceNo,
    unsigned long *pValue,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetStraddlingDelay(
    unsigned long nDeviceNo,
    unsigned long *pPulse1,
    unsigned long *pPulse2,
    unsigned long *pErrorCode);

unsigned long PDCAPI
PDC_GetExposurePosition(unsigned long nDeviceNo,
unsigned long *pValue,
unsigned long *pErrorCode);

unsigned long PDCAPI
PDC_GetVSyncExposeDeviation(unsigned long nDeviceNo,
long *pValue,
unsigned long *pErrorCode);

// PIV
unsigned long PDCAPI PDC_GetLiveResetMode(
        unsigned long nDeviceNo,
        unsigned long *pLiveMode,
        unsigned long *pResetMode,
        unsigned long *pTotalFrame,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetLiveResetMode(
        unsigned long nDeviceNo,
        unsigned long nLiveMode,
        unsigned long nResetMode,
        unsigned long nTotalFrame,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetLiveResetImage(
        unsigned long nDeviceNo,
        unsigned long nChildNo,
        unsigned long nBitDepth,
        void *pData1,
        void *pData2,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetReadAheadTransfer(
        unsigned long nDeviceNo,
        unsigned long *pMode,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetReadAheadTransfer(
        unsigned long nDeviceNo,
        unsigned long nChildNo,
        unsigned long nMode,
        long		  nStartFrame,
        long		  nEndFrame,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetDirectRecordFASTDrive(
        unsigned long nDeviceNo,
        unsigned long *pMode,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetDirectRecordFASTDrive(
        unsigned long nDeviceNo,
        unsigned long nMode,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveRecordInfo(
        unsigned long nDeviceNo,
        unsigned long nSlotNo,
        unsigned long nDataNo,
        void *pRecInfo,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveImage(
        unsigned long nDeviceNo,
        unsigned long nSlotNo,
        unsigned long nDataNo,
        unsigned long nFrameNo,
        unsigned long nInterleave,
        void *pData,
        unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveLut(
    unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    void *pLutR,
    void *pLutG,
    void *pLutB,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveIRIG(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    long nFrameNo,
    PPDC_IRIG_INFO pData,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveAutoExposure(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    long nFrameNo,
    PPDC_AUTO_EXPOSURE_INFO pData,
    unsigned long *pErrorCode);


unsigned long PDCAPI PDC_GetFASTDriveTemperatureType(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    unsigned long* pType,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveTemperature(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    long nFrameNo,
    PVOID pData,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_FASTDriveOpen(
    unsigned long nDeviceNo,
    unsigned long *pDataNum,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_FASTDriveClose(
    unsigned long nDeviceNo,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveActivityRatio(
    unsigned long nDeviceNo,
    unsigned long nSlotNo,
    double *pActivityRatio,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveTotalWrittenSize(
    unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long long *pWrittenSize,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveImageDataStart(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    unsigned long nFrameNo,
    unsigned long nInterleave,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveImageDataEnd(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    unsigned long nFrameNo,
    unsigned long nInterleave,
    void *pData,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveDataCount(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long long *pDataCount,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_EnterFASTDrivePassword(unsigned long nDeviceNo,
    char *pPassword,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetFASTDrivePassword(unsigned long nDeviceNo,
    char *pOldPassword,
    char *pNewPassword,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetFASTDriveAcceleration(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    long nFrameNo,
    PVOID pData,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetMediaAcceleration(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    long nFrameNo,
    PVOID pData,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetDeviceSeries(
    unsigned long nDeviceNo,
    unsigned long *pSeries,
    unsigned long *pErrorCode); 
unsigned long PDCAPI PDC_GetStorageDownloadMode(
    unsigned long nDeviceNo,
    unsigned long *pMode,
    unsigned long *pErrorCode);
unsigned long PDCAPI PDC_SetStorageDownloadMode(
    unsigned long nDeviceNo,
    unsigned long nMode,
    unsigned long *pErrorCode);
unsigned long PDCAPI PDC_GetProgSwitchCount(
    unsigned long nDeviceNo,
    unsigned long *pCount,
    unsigned long *pErrorCode);
unsigned long PDCAPI PDC_GetLowLightMode2(
    unsigned long nDeviceNo,
    unsigned long *pMode,
    unsigned long *pErrorCode);
unsigned long PDCAPI PDC_SetLowLightMode2(
    unsigned long nDeviceNo,
    unsigned long nMode,
    unsigned long *pErrorCode);
unsigned long PDCAPI PDC_GetLowLightModeEx(
    unsigned long nDeviceNo,
    unsigned long *pLowLightMode,
    unsigned long *pErrorCode);
unsigned long PDCAPI PDC_SetLowLightModeEx(
    unsigned long nDeviceNo,
    unsigned long nLowLightMode,
    unsigned long *pErrorCode);
unsigned long PDCAPI PDC_GetPixelGainDataSize(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long *pSize,
    unsigned long *pErrorCode
);
unsigned long PDCAPI PDC_GetPixelGainDataMode3Size(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long *pSize,
    unsigned long *pErrorCode);
unsigned long PDCAPI PDC_GetDSShutterLimit(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long *pLimit,
    unsigned long *pErrorCode
    );
unsigned long PDCAPI PDC_GetDSShutterLower(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long* pLower,
    unsigned long* pErrorCode
);

unsigned long PDCAPI
PDC_SetWiFiScanRequest(
    unsigned long	nDeviceNo,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_GetWiFiScanCount(
    unsigned long	nDeviceNo,
    unsigned long	*pCount,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_GetWiFiScanInfoA(
    unsigned long	nDeviceNo,
    unsigned long	nSelectNo,
    PPDC_WIFI_INFOA	pInfo,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_GetWiFiScanInfoW(
    unsigned long	nDeviceNo,
    unsigned long	nSelectNo,
    PPDC_WIFI_INFOW	pInfo,
    unsigned long	*pErrorCode
    );

#ifdef UNICODE
#define PDC_GetWiFiScanInfo  PDC_GetWiFiScanInfoW
#else
#define PDC_GetWiFiScanInfo  PDC_GetWiFiScanInfoA
#endif // !UNICODE

unsigned long PDCAPI
PDC_SetWiFiPassword(
    unsigned long	nDeviceNo,
    unsigned long	nSelectNo,
    char*			strPassword,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_SetWiFiConnect(
    unsigned long	nDeviceNo,
    unsigned long	nSelectNo,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_SetWiFiDisconnect(
    unsigned long	nDeviceNo,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_GetBatteryInfo(
    unsigned long		nDeviceNo,
    PPDC_BATTERY_INFO	pInfo,
    unsigned long		*pErrorCode
    );

unsigned long PDCAPI
PDC_GetShutdownBatterySupply(
    unsigned long	nDeviceNo,
    unsigned long	*pMode,
    unsigned long	*pTime,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_SetShutdownBatterySupply(
    unsigned long	nDeviceNo,
    unsigned long	nMode,
    unsigned long	nTime,
    unsigned long	*pErrorCode
    );


unsigned long PDCAPI
PDC_GetShutdownBatterySupplyRange(
    unsigned long	nDeviceNo,
    unsigned long	*pMinTime,
    unsigned long	*pMaxTime,
    unsigned long	*pErrorCode
    );

#if 0
//TODO:削除4.0.5.1のマージに削除すべし
unsigned long PDCAPI
PDC_GetMediaSaveBatterySupply(
    unsigned long	nDeviceNo,
    unsigned long	*pMode,
    unsigned long	*pTime,
    unsigned long	*pErrorCode
    );
//TODO:削除4.0.5.1のマージに削除すべし
unsigned long PDCAPI
PDC_SetMediaSaveBatterySupply(
    unsigned long	nDeviceNo,
    unsigned long	nMode,
    unsigned long	nTime,
    unsigned long	*pErrorCode
    );
//TODO:削除4.0.5.1のマージに削除すべし
unsigned long PDCAPI
PDC_GetMediaSaveBatterySupplyRange(
    unsigned long	nDeviceNo,
    unsigned long	*pMinTime,
    unsigned long	*pMaxTime,
    unsigned long	*pErrorCode
    );
#endif

unsigned long PDCAPI
PDC_GetAutoPowerWhenSupply(
    unsigned long	nDeviceNo,
    unsigned long	*pMode,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_SetAutoPowerWhenSupply(
    unsigned long	nDeviceNo,
    unsigned long	nMode,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_GetPartitionLock(
    unsigned long	nDeviceNo,
    unsigned long	*pMode,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_SetPartitionLock(
    unsigned long	nDeviceNo,
    unsigned long	nMode,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_SetShutdownCamera(
    unsigned long	nDeviceNo,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_SetRebootCamera(
    unsigned long	nDeviceNo,
    unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_GetAccelerationTrigger(
    unsigned long	nDeviceNo,
    unsigned long	*pMode,
    unsigned long	*pAcceleration,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_SetAccelerationTrigger(
    unsigned long	nDeviceNo,
    unsigned long	nMode,
    unsigned long	nAcceleration,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI
PDC_GetAccelerationTriggerLimit(
unsigned long	nDeviceNo,
unsigned long	*pLimitLower,
unsigned long	*pLimitUpper,
unsigned long	*pStep,
unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_GetAccelerationTriggerTime(
unsigned long	nDeviceNo,
unsigned long	*pTime,
unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_SetAccelerationTriggerTime(
unsigned long	nDeviceNo,
unsigned long	nTime,
unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_GetAccelerationTriggerTimeLimit(
unsigned long	nDeviceNo,
unsigned long	*pLimitLower,
unsigned long	*pLimitUpper,
unsigned long	*pStep,
unsigned long	*pErrorCode
);

unsigned long PDCAPI
PDC_SetExternalOutSignalSpan(
    unsigned long nDeviceNo,
    unsigned long nPort,
    char nFlag,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI
PDC_GetExternalOutSignalSpan(
    unsigned long nDeviceNo,
    unsigned long nPort,
    char* pFlag,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI
PDC_ReqExternalOutSignalSpan(
    unsigned long nDeviceNo,
    unsigned long nPort,
    char* pFlag,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI
PDC_SetFanRecReadyStop(
    unsigned long nDeviceNo,
    char nFlag,
    unsigned long* pErrorCode
    );
unsigned long PDCAPI
PDC_GetFanRecReadyStop(
    unsigned long nDeviceNo,
    char* pFlag,
    unsigned long* pErrorCode
    );
unsigned long PDCAPI
PDC_ReqFanRecReadyStop(
    unsigned long nDeviceNo,
    char* pFlag,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI
PDC_GetLensParam(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long nType,
    unsigned long nOption,
    long* pParam,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI
PDC_ReqLensParam(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long nType,
    unsigned long nOption,
    long* pParam,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI
PDC_SetLensParam(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long nType,
    unsigned long nOption,
    long nParam,
    unsigned long* pErrorCode
);

unsigned long PDCAPI PDC_GetTemperature(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long nChannel,
    long* pValue,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_GetMemTemperatureData(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    void *pData,
    long nFrameNo,
    unsigned long nFrameCount,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_GetMemTemperatureType(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long* pType,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI PDC_GetTemperatureTypeList(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long *pSize,
    unsigned long *pList,
    unsigned long *pErrorCode
    );			

unsigned long PDCAPI PDC_GetMediaIRIG(unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    long nFrameNo,
    PPDC_IRIG_INFO pData,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetMediaSaveAfterInsert(
    unsigned long	nDeviceNo,
    unsigned long	*pMode,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI PDC_SetMediaSaveAfterInsert(
    unsigned long	nDeviceNo,
    unsigned long	nMode,
    unsigned long	*pErrorCode
    );

/*
* for MH6
*/
unsigned long PDCAPI PDC_GetWarningTemperature(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    char * pFlag,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetWarningCableCutting(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    char * pFlag,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetTriggerNoiseFilter(
    unsigned long nDeviceNo,
    unsigned long *pMode,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetTriggerNoiseFilter(
    unsigned long nDeviceNo,
    unsigned long nMode,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetTriggerNoiseFilterWidth(
    unsigned long nDeviceNo,
    unsigned long *pWidth,
    unsigned long *pLimitUpper,
    unsigned long *pLimitLower,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetTriggerNoiseFilterWidth(
    unsigned long nDeviceNo,
    unsigned long nWidth,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetVDAIOType(
    unsigned long nDeviceNo,
    unsigned long nPort,
    unsigned long *pValue,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetVDAIOType(
    unsigned long nDeviceNo,
    unsigned long nPort,
    unsigned long nValue,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetMemoryShare(
    unsigned long nDeviceNo,
    unsigned long *pMode,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetMemoryShare(
    unsigned long nDeviceNo,
    unsigned long nMode,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetMemAccelerationData(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    void *pData,
    long nFrameNo,
    unsigned long nFrameCount,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_GetVideoOSDCrosshairMode(
    unsigned long	nDeviceNo,
    unsigned long*	nMode,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI PDC_GetSerialNumber(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long long *pSerialNumber,
    unsigned long *pErrorCode);
    
unsigned long PDCAPI PDC_SetVideoOSDCrosshairMode(
    unsigned long	nDeviceNo,
    unsigned long	nMode,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI PDC_GetShutterSpeedPrecision(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    long *pValue,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_GetFASTDriveShutterSpeedPrecision(
    unsigned long nDeviceNo,
    unsigned long nSlotNo,
    unsigned long nDataNo,
    long *pValue,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_GetAutoExposureLimit(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long *pValue,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_StorageIsFunction(
    unsigned long nDeviceCode,
    unsigned long nOption,
    unsigned long nFunction,
    char *pFlag,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_GetDelayTypeList(
    unsigned long	nDeviceNo,
    unsigned long	*pSize,
    unsigned long	*pList,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI PDC_GetDeviceErrorList(
    unsigned long	nDeviceNo,
    unsigned long	nChildNo,
    unsigned long	*pSize,
    unsigned long	*pList,
    unsigned long	*pErrorCode
    );

unsigned long PDCAPI PDC_GetDeviceErrorObserve(
    unsigned long nDeviceNo,
    unsigned long *pMode,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_SetDeviceErrorObserve(
    unsigned long nDeviceNo,
    unsigned long nMode,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_SetPhaseAdjustment(
    unsigned long nDeviceNo,
    unsigned long *pErrorCode
    );

unsigned long PDCAPI PDC_GetBitDepthList(
    unsigned long   nDeviceNo,
    unsigned long   nChildNo,
    unsigned long* pSize,
    unsigned long* pList,
    unsigned long* pErrorCode
);

unsigned long PDCAPI PDC_GetBitSelList(
    unsigned long	nDeviceNo,
    unsigned long	nChildNo,
    unsigned long* pSize,
    unsigned long* pList,
    unsigned long* pErrorCode
);

/*
* for SHADING
*/
unsigned long PDCAPI PDC_GetShadingResponseType(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long *pResponseType,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetLiveImageIRIGData(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    PPDC_IRIG_INFO pData,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetCameraHeadType(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long *pType,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetHeadPortNumber(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long *pPortNo,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetMechanicalShutterError(
    unsigned long nDeviceNo,
    unsigned long *pMechanicalShutterError,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetLinkSpeed(
    unsigned long nDeviceNo,
    unsigned long *pLinkSpeed,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetPacketIntervalMode(
    unsigned long nDeviceNo,
    unsigned long nLinkSpeed,
    unsigned long *pMode,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetPacketIntervalMode(
    unsigned long nDeviceNo,
    unsigned long nLinkSpeed,
    unsigned long nMode,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetEthernetSpeedLimit(
    unsigned long nDeviceNo,
    unsigned long *pParam,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_SetCommunicationParameter(
    unsigned long nInterfaceCode,
    unsigned long nParamKey,
    unsigned long nParamValue,
    unsigned long *pErrorCode);

unsigned long PDCAPI PDC_GetCommunicationParameter(
    unsigned long nInterfaceCode,
    unsigned long nParamKey,
    unsigned long *pParamValue,
    unsigned long *pErrorCode);

/*
* for FAST Drive
*/
unsigned long PDCAPI PFDC_GetValidDrives(unsigned long *pDrives, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_OpenDrive(unsigned long nDriveNo, unsigned long *pNumOfData, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_CloseDrive(unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetDriveName(unsigned long nDriveNo, char *pName, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetRecordInfo(unsigned long nDataNo, PDC_RECORD_INFO *pRecordInfo, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetLUTData(unsigned long nDataNo, void *pLUTR, void *pLUTG, void *pLUTB, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetExposeTimeData(unsigned long nDataNo, unsigned long *pExposeTimeData, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_SetDataName(unsigned long nDataNo, char *pName, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetImageData(unsigned long nDataNo, long nFrameNo, long nInterleave, void *pImageData, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetIRIGInfo(unsigned long nDataNo, long nFrameNo, PDC_IRIG_INFO *pIRIGInfo, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetRecOnCmdTrigFrames(unsigned long nDataNo, unsigned long *pBuff, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetAutoExposureFps(unsigned long nDataNo, long nFrameNo, PPDC_AUTO_EXPOSURE_INFO pAE, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetAutoExposureNsec(unsigned long nDataNo, long nFrameNo, PPDC_AUTO_EXPOSURE_INFO pAE, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_StartImageBuffering(unsigned long nDataNo, unsigned long *pErrorCode);
void PDCAPI PFDC_FinishImageBuffering(void);
unsigned long PDCAPI PFDC_GetActivityRatio(double *pActivityRatio, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetTotalWrittenSize(unsigned long long *pTotalWrittenSize, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_FormatDrive(unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_TestDrive(unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetTemperatureType(unsigned long nDataNo, unsigned long* pType, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetTemperature(unsigned long nDataNo, long nFrameNo, void* pData, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetShutterSpeedPrecision(unsigned long nDataNo, long* pValue, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetADCByteData(unsigned long nDataNo, long nFrameNo, unsigned long nFrameNum, void* pData, unsigned long *pErrorCode);
unsigned long PDCAPI PFDC_GetAdcInfo(unsigned long nDataNo, unsigned long* pNumberOfChannel, unsigned long* pSamplePerFrame, unsigned long *pErrorCode);

/*
* for SD Card
*/
unsigned long PDCAPI PSDC_GetValidDrives(unsigned long *pDrives, unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_OpenDrive(unsigned long nDriveNo, unsigned long *pNumOfData, unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_CloseDrive(unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_GetRecordInfo(unsigned long nDataNo, PDC_RECORD_INFO *pRecordInfo, unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_GetLUTData(unsigned long nDataNo, void *pLUTR, void *pLUTG, void *pLUTB, unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_GetExposeTimeData(unsigned long nDataNo, unsigned long *pExposeTimeData, unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_GetRecOnCmdTrigFrames(unsigned long nDataNo, unsigned long *pBuff, unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_GetImageData(unsigned long nDataNo, long nFrameNo, long nInterleave, void *pImageData, unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_GetIRIGInfo(unsigned long nDataNo, long nFrameNo, PDC_IRIG_INFO *pIRIGInfo, unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_GetAutoExposureFps(unsigned long nDataNo, long nFrameNo, PDC_AUTO_EXPOSURE_INFO *pAEInfo, unsigned long *pErrorCode);
unsigned long PDCAPI PSDC_GetAutoExposureNsec(unsigned long nDataNo, long nFrameNo, PDC_AUTO_EXPOSURE_INFO *pAEInfo, unsigned long *pErrorCode);

/*
* for CFast
*/
unsigned long PDCAPI PCFC_GetValidDrives(unsigned long* pDrives, unsigned long* pErrorCode);
unsigned long PDCAPI PCFC_OpenDrive(unsigned long nDriveNo, unsigned long* pNumOfData, unsigned long* pErrorCode);
unsigned long PDCAPI PCFC_CloseDrive(unsigned long* pErrorCode);
unsigned long PDCAPI PCFC_GetRecordInfo(unsigned long nDataNo, PDC_RECORD_INFO* pRecordInfo, unsigned long* pErrorCode);
unsigned long PDCAPI PCFC_GetExposeTimeData(unsigned long nDataNo, unsigned long* pExposeTimeData, unsigned long* pErrorCode);
unsigned long PDCAPI PCFC_GetImageData(unsigned long nDataNo, long nFrameNo, long nInterleave, void* pImageData, unsigned long* pErrorCode);
unsigned long PDCAPI PCFC_GetAccelerationData(unsigned long nDataNo, long nFrameNo, PPDC_ACCELERATION_DATA pAcceleration, unsigned long *pErrorCode);
unsigned long PDCAPI PCFC_GetIRIGInfo(unsigned long nDataNo, long nFrameNo, PPDC_IRIG_INFO pIrig, unsigned long *pErrorCode);


/*
* CIHX I/O
*/

#define PDC_CHIX_OPTION_ADDMAP(OPTION, TYPE, MAP) OPTION.insert(std::make_pair(TYPE, &MAP))
#define PDC_CHIX_MAP_ADDMETA(MAP, KEY, VAL) MAP.insert(std::make_pair(KEY, VAL))
#define PDC_CHIX_DOWNLOAD(MAP, TYPE) MAP.insert(std::make_pair(TYPE, std::make_pair((unsigned long long)0, (char*)NULL)))
#define PDC_CHIX_MAP_ADDBIN(MAP, TYPE, SIZE, DATA) MAP.insert(std::make_pair(TYPE, std::make_pair(SIZE, DATA)))

unsigned long PDCAPI PDC_InitCihxSave(
    PDC_ARCHIVE_HANDLE* pHandle,
    unsigned long*		pErrorCode
    );

unsigned long PDCAPI PDC_ExitCihxSave(
    PDC_ARCHIVE_HANDLE	handle,
    unsigned long*		pErrorCode
    );

unsigned long PDCAPI PDC_CancelCihxSave(
    PDC_ARCHIVE_HANDLE	handle,
    unsigned long*		pErrorCode
    );

unsigned long PDCAPI PDC_GetCihxSaveStatusA(
    PDC_ARCHIVE_HANDLE		handle,
    PDC_ARCHIVE_DATA_TYPE*	pDataType,
    PDC_EXPORT_STATUS*		pStatus,
    unsigned long*			pProgress,
    char*                   pErrorInfo,
    unsigned long*			pErrorCode
    );

unsigned long PDCAPI PDC_GetCihxSaveStatusW(
    PDC_ARCHIVE_HANDLE		handle,
    PDC_ARCHIVE_DATA_TYPE*	pDataType,
    PDC_EXPORT_STATUS*		pStatus,
    unsigned long*			pProgress,
    wchar_t*                pErrorInfo,
    unsigned long*			pErrorCode
    );

#ifdef UNICODE
#define PDC_GetCihxSaveStatus  PDC_GetCihxSaveStatusW
#else
#define PDC_GetCihxSaveStatus  PDC_GetCihxSaveStatusA
#endif

unsigned long PDCAPI PDC_SaveCihxFromCameraA(
    PDC_ARCHIVE_HANDLE		handle,
    const char*				pPath,
    unsigned long			nDeviceNo,
    unsigned long			nChildNo,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

unsigned long PDCAPI PDC_SaveCihxFromCameraW(
    PDC_ARCHIVE_HANDLE		handle,
    const wchar_t*			pPath,
    unsigned long			nDeviceNo,
    unsigned long			nChildNo,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

#ifdef UNICODE
#define PDC_SaveCihxFromCamera  PDC_SaveCihxFromCameraW
#else
#define PDC_SaveCihxFromCamera  PDC_SaveCihxFromCameraA
#endif


unsigned long PDCAPI PDC_SaveCihxFromCameraForStorageA(
    PDC_ARCHIVE_HANDLE		handle,
    const char*				pPath,
    unsigned long			nDeviceNo,
    unsigned long			nChildNo,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

unsigned long PDCAPI PDC_SaveCihxFromCameraForStorageW(
    PDC_ARCHIVE_HANDLE		handle,
    const wchar_t*			pPath,
    unsigned long			nDeviceNo,
    unsigned long			nChildNo,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

#ifdef UNICODE
#define PDC_SaveCihxFromCameraForStorage  PDC_SaveCihxFromCameraForStorageW
#else
#define PDC_SaveCihxFromCameraForStorage  PDC_SaveCihxFromCameraForStorageA
#endif

unsigned long PDCAPI PDC_SaveCihxFromCameraStorageA(
    PDC_ARCHIVE_HANDLE		handle,
    const char*				pPath,
    PDC_SOURCE_STORAGE_TYPE storageType,
    unsigned long			nDeviceNo,
    unsigned long			nChildNo,
    unsigned long			nSlotNo,
    unsigned long			nDataNo,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

unsigned long PDCAPI PDC_SaveCihxFromCameraStorageW(
    PDC_ARCHIVE_HANDLE		handle,
    const wchar_t*			pPath,
    PDC_SOURCE_STORAGE_TYPE storageType,
    unsigned long			nDeviceNo,
    unsigned long			nChildNo,
    unsigned long			nSlotNo,
    unsigned long			nDataNo,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

#ifdef UNICODE
#define PDC_SaveCihxFromCameraStorage  PDC_SaveCihxFromCameraStorageW
#else
#define PDC_SaveCihxFromCameraStorage  PDC_SaveCihxFromCameraStorageA
#endif

unsigned long PDCAPI PDC_SaveCihxFromExternalStorageA(
    PDC_ARCHIVE_HANDLE		handle,
    const char*				pPath,
    PDC_SOURCE_STORAGE_TYPE storageType,
    unsigned long			nDriveNo,
    unsigned long			nDataNo,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

unsigned long PDCAPI PDC_SaveCihxFromExternalStorageW(
    PDC_ARCHIVE_HANDLE		handle,
    const wchar_t*			pPath,
    PDC_SOURCE_STORAGE_TYPE storageType,
    unsigned long			nDriveNo,
    unsigned long			nDataNo,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

#ifdef UNICODE
#define PDC_SaveCihxFromExternalStorage  PDC_SaveCihxFromExternalStorageW
#else
#define PDC_SaveCihxFromExternalStorage  PDC_SaveCihxFromExternalStorageA
#endif

unsigned long PDCAPI PDC_SaveCihxFromFileA(
    PDC_ARCHIVE_HANDLE		handle,
    const char*				pSource,
    const char*				pPath,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

unsigned long PDCAPI PDC_SaveCihxFromFileW(
    PDC_ARCHIVE_HANDLE		handle,
    const wchar_t*			pSource,
    const wchar_t*			pPath,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

#ifdef UNICODE
#define PDC_SaveCihxFromFile  PDC_SaveCihxFromFileW
#else
#define PDC_SaveCihxFromFile  PDC_SaveCihxFromFileA
#endif

unsigned long PDCAPI PDC_SaveCihxFromXmlA(
    PDC_ARCHIVE_HANDLE		handle,
    const char*				pSource,
    const char*				pPath,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

unsigned long PDCAPI PDC_SaveCihxFromXmlW(
    PDC_ARCHIVE_HANDLE		handle,
    const char* 			pSource,
    const wchar_t*			pPath,
    PPDC_ARCHIVE_PARAM      pRequired,
    PPDC_ARCHIVE_OPTION		pOptions,
    unsigned long			optionCount,
    unsigned long*			pErrorCode
    );

#ifdef UNICODE
#define PDC_SaveCihxFromXml  PDC_SaveCihxFromXmlW
#else
#define PDC_SaveCihxFromXml  PDC_SaveCihxFromXmlA
#endif

unsigned long PDCAPI PDC_GetCihxValueA(
    const char*		pPath,
    const char*		pKey,
    char*			pValue,
    unsigned long*	pErrorCode
    );

unsigned long PDCAPI PDC_GetCihxValueW(
    const wchar_t*	pPath,
    const wchar_t*	pKey,
    wchar_t*		pValue,
    unsigned long*	pErrorCode
    );

#ifdef UNICODE
#define PDC_GetCihxValue  PDC_GetCihxValueW
#else
#define PDC_GetCihxValue  PDC_GetCihxValueA
#endif

unsigned long PDCAPI PDC_GetCihxDataTypesA(
    const char*				pPath,
    PPDC_ARCHIVE_DATA_HEAD	pDataTypes,
    unsigned long*			pCount,
    unsigned long*			pErrorCode
    );

unsigned long PDCAPI PDC_GetCihxDataTypesW(
    const wchar_t*			pPath,
    PPDC_ARCHIVE_DATA_HEAD	pDataTypes,
    unsigned long*			pCount,
    unsigned long*			pErrorCode
    );

#ifdef UNICODE
#define PDC_GetCihxDataTypes  PDC_GetCihxDataTypesW
#else
#define PDC_GetCihxDataTypes  PDC_GetCihxDataTypesA
#endif

unsigned long PDCAPI PDC_GetCihxDataA(
    const char*				pPath,
    PDC_ARCHIVE_DATA_TYPE	dataType,
    char*					pData,
    unsigned long*			pErrorCode
    );

unsigned long PDCAPI PDC_GetCihxDataW(
    const wchar_t*			pPath,
    PDC_ARCHIVE_DATA_TYPE	dataType,
    char*					pData,
    unsigned long*			pErrorCode
    );

#ifdef UNICODE
#define PDC_GetCihxData  PDC_GetCihxDataW
#else
#define PDC_GetCihxData  PDC_GetCihxDataA
#endif

unsigned long PDCAPI PDC_AutoFocus(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long nX,
    unsigned long nY,
    unsigned long nWidth,
    unsigned long nHeight,
    unsigned long nMode,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI PDC_CancelAutoFocus(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI PDC_GetAutoFocusStatus(
    unsigned long nDeviceNo,
    unsigned long nChildNo,
    unsigned long* pAFStatus,
    unsigned long* pAFError,
    unsigned long* pErrorCode
    );

unsigned long PDCAPI PDC_OpenDeviceWithParameter(
    PPDC_DETECT_INFO	    pDetectInfo,
    const PPDC_OPEN_INFO    pParams,
    unsigned long           paramCount,
    unsigned long*          pDeviceNo,
    unsigned long*          pErrorCode
);

unsigned long PDCAPI PDC_GetLogParameter(
    unsigned long nOption,
    unsigned long* pValue,
    unsigned long* pErrorCode
);

unsigned long PDCAPI PDC_SetLogParameter(
    unsigned long nOption,
    unsigned long nValue,
    unsigned long* pErrorCode
);

unsigned long PDCAPI PDC_EraseCachedCorrectionData(
    unsigned long* pErrorCode
);


#ifdef __cplusplus
}
#endif

#endif	/*	_PDC_FUNC_H_	*/
