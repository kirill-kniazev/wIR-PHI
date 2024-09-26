/*
 *	PDCERROR.h
 *	Photron Device Control SDK
 *	Error Code
 *
 *	Copyright (C) 2006-2012 PHOTRON LIMITED
 */

#ifndef	_PDC_ERROR_H_
#define	_PDC_ERROR_H_

/*	Return Value	*/
#define	PDC_SUCCEEDED				1
#define	PDC_FAILED					0

/*	Error Code	*/
#define	PDC_ERROR_NOERROR			1	/*	Normal	*/
#define	PDC_ERROR_UNINITIALIZE		2	/*	Uninitialize	*/
#define	PDC_ERROR_ILLEGAL_DEV_NO	3	/*	Illegal device number	*/
#define	PDC_ERROR_ILLEGAL_CHILD_NO	4	/*	Illegal child number	*/
#define	PDC_ERROR_ILLEGAL_VALUE		5	/*	Illegal parameter	*/
#define	PDC_ERROR_ALLOCATE_FAILED	6	/*	Memory allocate failed	*/
#define	PDC_ERROR_INITIALIZED		7	/*	Initialized	*/
#define	PDC_ERROR_NO_DEVICE			8	/*	Device not found	*/
#define	PDC_ERROR_TIMEOUT			9	/*	Time out	*/
#define	PDC_ERROR_FUNCTION_FAILED	10	/*	Function failed	*/
#define	PDC_ERROR_FUNCTION_DISABLE	11	/*	Function disabled	*/
#define	PDC_ERROR_NO_DATA			12	/*	Recorded data does not exist	*/
#define	PDC_ERROR_UNKNOWN_FRAME		13	/*	Unknown frame number	*/
#define	PDC_ERROR_CAMERAMODE		14	/*	Camera mode error	*/
#define	PDC_ERROR_NO_ENDLESS		15	/*	No endress mode recording	*/
#define	PDC_ERROR_FILEREAD_FAILED	16	/*	File read failed	*/
#define	PDC_ERROR_FILEWRITE_FAILED	17	/*	File write failed	*/
#define	PDC_ERROR_IMAGE_SIZEOVER	18	/*	Image size error	*/
#define	PDC_ERROR_FRAME_AREAOVER	19	/*	Frame area error	*/
#define	PDC_ERROR_PLAYMODE			20	/*	Play mode error	*/
#define	PDC_ERROR_NOT_SUPPORTED		21	/*	Not supported	*/
#define	PDC_ERROR_DROP_FRAME		22	/*	Frame is not captured	*/
#define PDC_ERROR_FILE_OPEN_ALREADY	23	/*	File has been already opened	*/
#define	PDC_ERROR_FILE_NOTOPEN		24	/*	File is not opened	*/
#define	PDC_ERROR_CONVERSION_OF_STRING	25	/*	Conversion of string. Multi-byte and Unicode */
#define PDC_ERROR_DURING_AUTOFOCUS		26	/*  Restrict During AutoFocus  */

#define PDC_ERROR_COMPRESS                   50 /* compress error */
#define PDC_ERROR_COMPRESS_ILLEGAL_SIZE      51 /* compress error */

#define PDC_ERROR_DECOMPRESS                 60 /* decompress error */
#define PDC_ERROR_DECOMPRESS_ILLEGAL_OPTION  61 /* decompress illegal option error */
#define PDC_ERROR_DECOMPRESS_ILLEGAL_SIZE    62 /* decompress illegal size error */
#define PDC_ERROR_DECOMPRESS_ILLEGAL_DATA    63 /* decompress illegal data error */
#define PDC_ERROR_DECOMPRESS_ILLEGAL_PARAM   64 /* decompress illegal param error */

#define	PDC_ERROR_LOAD_FAILED		100	/*	Module load failed	*/
#define	PDC_ERROR_FREE_FAILED		101	/*	Module free failed	*/
#define	PDC_ERROR_LOADED			102	/*	Module loaded	*/
#define	PDC_ERROR_NOTLOADED			103	/*	Module is not loaded	*/
#define	PDC_ERROR_UNDETECTED		104	/*	Device not yet detect	*/
#define	PDC_ERROR_OVER_DEVICE		105	/*	Device kind is too multi	*/
#define	PDC_ERROR_INIT_FAILED		106	/*	Initialize failed	*/
#define	PDC_ERROR_OPEN_ALREADY		107	/*	Device is opened	*/
#define	PDC_ERROR_NOTOPEN			108	/*	Device is not opened	*/
#define	PDC_ERROR_LIVEONLY			110	/*	Not become LIVE mode	*/
#define	PDC_ERROR_PLAYBACKONLY		111	/*	Not become PLAYBACK mode	*/
#define PDC_ERROR_FASTDRIVE_PLAYBACKONLY	112	/*	Not become FASTDrive PLAYBACK mode	*/
#define PDC_ERROR_NOTCONNECTDEVICE	113	/*	Device is not connected	*/
#define PDC_ERROR_ICMP_TIMEOUT		114

#define	PDC_ERROR_SEND_ERROR		200	/*	Send error	*/
#define	PDC_ERROR_RECEIVE_ERROR		201	/*	Receive error	*/
#define	PDC_ERROR_CLEAR_ERROR		202	/*	Initialize error	*/
#define	PDC_ERROR_COMMAND_ERROR		203	/*	Command error	*/

#define	PDC_ERROR_COMPARE_DATA_ERROR	204	/*	Compare data error	*/

#define PDC_ERROR_ENABLE_CONFIG_ERROR	300	/* Enable Configuration FPGA Failed	*/
#define	PDC_ERROR_REG_ACCESS_ERROR	301	/*	Register Access Failed	*/

#define	PDC_ERROR_DEVICE_ACCESS_FAILED	400	/* Device Access Failed for FAST Drive/SD Card */
#define PDC_ERROR_UNUSUAL_DATA			401 /* Unusual Data for FAST Drive/SD Card */

#define PDC_ERROR_STORAGE_NO_CARD		402	
#define PDC_ERROR_STORAGE_WRITE			403
#define PDC_ERROR_STORAGE_READ			404
#define PDC_ERROR_STORAGE_SIZE			405
#define	PDC_ERROR_STORAGE_FORMAT		406
#define PDC_ERROR_STORAGE_LOCKED_PASSWORD	407
#define PDC_ERROR_STORAGE_INVALID_PASSWORD	408
#define PDC_ERROR_STORAGE_DOWNLOADING	409

#define PDC_ERROR_DETECTDEVICE_WITH_TX  500 /* Disable DetectDevice when Multi(TX) is Opened*/
#define PDC_ERROR_PARTITION_LOCKED		501	/* Partition Locked */
#define PDC_ERROR_INITIALERROR			502 /* Initial error */

#define PDC_ERROR_NONE PDC_ERROR_NOERROR
#define PDC_ERROR_UNKOWN 0
#define PDC_ERROR_INTERANL_ERROR 1000

#define PDC_ERROR_FILE_NOT_FOUND 1100
#define PDC_ERROR_DLL_BAT_FORMAT 1101
#define PDC_ERROR_INTERFACE_DLL_LOAD_FAILED 1102
#define PDC_ERROR_ILLEGAL_CHILD_NO_MAINUNIT_NOT_SUPPORTED 1103
#define PDC_ERROR_ILLEGAL_FRAME_NUMBER 1104
#define PDC_ERROR_THREAD_START_FAILED 1105
//#define PDC_ERROR_THREAD_RESULT_ALEADY_RECIEVED 1106
#define PDC_ERROR_THREAD_ALEADY_STARTED 1107
#define PDC_ERROR_THREAD_NOT_STARTED 1108
#define PDC_ERROR_BUSY 1109
#define PDC_ERROR_IMAGE_ACQUISITION 1110

#define PDC_INT_ERROR_UNEXPECTED        2000
#define PDC_INT_ERROR_TIMEOUT           2001
#define PDC_INT_ERROR_SEND              2002
#define PDC_INT_ERROR_RECV              2003
#define PDC_INT_ERROR_COMMUNICATION     2004
#define PDC_INT_ERROR_ILLEGAL_PARAM     2005
#define PDC_INT_ERROR_CONNECTION        2006
#define PDC_INT_ERROR_PING              2007
#define PDC_INT_NOT_INITIALIZED         2008


#endif	/*	_PDC_ERROR_H_	*/

