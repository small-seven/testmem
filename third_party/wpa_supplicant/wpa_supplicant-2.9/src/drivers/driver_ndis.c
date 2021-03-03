#ifdef __CYGWIN__
#include "build_config.h"
#else /* __CYGWIN__ */
#include "includes.h"
#endif /* __CYGWIN__ */
#ifdef CONFIG_USE_NDISUIO
#include <winsock2.h>
#else /* CONFIG_USE_NDISUIO */
#include <Packet32.h>
#endif /* CONFIG_USE_NDISUIO */
#ifdef __MINGW32_VERSION
#include <ddk/ntddndis.h>
#else /* __MINGW32_VERSION */
#include <ntddndis.h>
#endif /* __MINGW32_VERSION */
#ifdef _WIN32_WCE
#include <winioctl.h>
#include <nuiouser.h>
#include <devload.h>
#endif /* _WIN32_WCE */
#include "common.h"
#include "driver.h"
#include "eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "driver_ndis.h"
#ifdef CONFIG_NDIS_EVENTS_INTEGRATED
#endif /* CONFIG_NDIS_EVENTS_INTEGRATED */
#ifndef OID_802_11_BSSID
#define OID_802_11_BSSID 			0x0d010101
#define OID_802_11_SSID 			0x0d010102
#define OID_802_11_INFRASTRUCTURE_MODE		0x0d010108
#define OID_802_11_ADD_WEP			0x0D010113
#define OID_802_11_REMOVE_WEP			0x0D010114
#define OID_802_11_DISASSOCIATE			0x0D010115
#define OID_802_11_BSSID_LIST 			0x0d010217
#define OID_802_11_AUTHENTICATION_MODE		0x0d010118
#define OID_802_11_PRIVACY_FILTER		0x0d010119
#define OID_802_11_BSSID_LIST_SCAN 		0x0d01011A
#define OID_802_11_WEP_STATUS	 		0x0d01011B
#define OID_802_11_ENCRYPTION_STATUS OID_802_11_WEP_STATUS
#define OID_802_11_ADD_KEY 			0x0d01011D
#define OID_802_11_REMOVE_KEY 			0x0d01011E
#define OID_802_11_ASSOCIATION_INFORMATION	0x0d01011F
#define OID_802_11_TEST 			0x0d010120
#define OID_802_11_CAPABILITY 			0x0d010122
#define OID_802_11_PMKID 			0x0d010123
#define NDIS_802_11_LENGTH_SSID 32
#define NDIS_802_11_LENGTH_RATES 8
#define NDIS_802_11_LENGTH_RATES_EX 16
typedef UCHAR NDIS_802_11_MAC_ADDRESS[6];

typedef struct NDIS_802_11_SSID {
	ULONG SsidLength;
	UCHAR Ssid[NDIS_802_11_LENGTH_SSID];
} NDIS_802_11_SSID;
typedef LONG NDIS_802_11_RSSI;

typedef enum NDIS_802_11_NETWORK_TYPE {
	Ndis802_11FH,
	Ndis802_11DS,
	Ndis802_11OFDM5,
	Ndis802_11OFDM24,
	Ndis802_11NetworkTypeMax
} NDIS_802_11_NETWORK_TYPE;
typedef struct NDIS_802_11_CONFIGURATION_FH {
	ULONG Length;
	ULONG HopPattern;
	ULONG HopSet;
	ULONG DwellTime;
} NDIS_802_11_CONFIGURATION_FH;
typedef struct NDIS_802_11_CONFIGURATION {
	ULONG Length;
	ULONG BeaconPeriod;
	ULONG ATIMWindow;
	ULONG DSConfig;
	NDIS_802_11_CONFIGURATION_FH FHConfig;
} NDIS_802_11_CONFIGURATION;
typedef enum NDIS_802_11_NETWORK_INFRASTRUCTURE {
	Ndis802_11IBSS,
	Ndis802_11Infrastructure,
	Ndis802_11AutoUnknown,
	Ndis802_11InfrastructureMax
} NDIS_802_11_NETWORK_INFRASTRUCTURE;
typedef enum NDIS_802_11_AUTHENTICATION_MODE {
	Ndis802_11AuthModeOpen,
	Ndis802_11AuthModeShared,
	Ndis802_11AuthModeAutoSwitch,
	Ndis802_11AuthModeWPA,
	Ndis802_11AuthModeWPAPSK,
	Ndis802_11AuthModeWPANone,
	Ndis802_11AuthModeWPA2,
	Ndis802_11AuthModeWPA2PSK,
	Ndis802_11AuthModeMax
} NDIS_802_11_AUTHENTICATION_MODE;
typedef enum NDIS_802_11_WEP_STATUS {
	Ndis802_11WEPEnabled,
	Ndis802_11Encryption1Enabled = Ndis802_11WEPEnabled,
	Ndis802_11WEPDisabled,
	Ndis802_11EncryptionDisabled = Ndis802_11WEPDisabled,
	Ndis802_11WEPKeyAbsent,
	Ndis802_11Encryption1KeyAbsent = Ndis802_11WEPKeyAbsent,
	Ndis802_11WEPNotSupported,
	Ndis802_11EncryptionNotSupported = Ndis802_11WEPNotSupported,
	Ndis802_11Encryption2Enabled,
	Ndis802_11Encryption2KeyAbsent,
	Ndis802_11Encryption3Enabled,
	Ndis802_11Encryption3KeyAbsent
} NDIS_802_11_WEP_STATUS, NDIS_802_11_ENCRYPTION_STATUS;
typedef enum NDIS_802_11_PRIVACY_FILTER {
	Ndis802_11PrivFilterAcceptAll,
	Ndis802_11PrivFilter8021xWEP
} NDIS_802_11_PRIVACY_FILTER;
typedef UCHAR NDIS_802_11_RATES[NDIS_802_11_LENGTH_RATES];
typedef UCHAR NDIS_802_11_RATES_EX[NDIS_802_11_LENGTH_RATES_EX];

typedef struct NDIS_WLAN_BSSID_EX {
	ULONG Length;
	NDIS_802_11_MAC_ADDRESS MacAddress; /* BSSID */
	UCHAR Reserved[2];
	NDIS_802_11_SSID Ssid;
	ULONG Privacy;
	NDIS_802_11_RSSI Rssi;
	NDIS_802_11_NETWORK_TYPE NetworkTypeInUse;
	NDIS_802_11_CONFIGURATION Configuration;
	NDIS_802_11_NETWORK_INFRASTRUCTURE InfrastructureMode;
	NDIS_802_11_RATES_EX SupportedRates;
	ULONG IELength;
	UCHAR IEs[1];
} NDIS_WLAN_BSSID_EX;
typedef struct NDIS_802_11_BSSID_LIST_EX {
	ULONG NumberOfItems;
	NDIS_WLAN_BSSID_EX Bssid[1];
} NDIS_802_11_BSSID_LIST_EX;
typedef struct NDIS_802_11_FIXED_IEs {
	UCHAR Timestamp[8];
	USHORT BeaconInterval;
	USHORT Capabilities;
} NDIS_802_11_FIXED_IEs;
typedef struct NDIS_802_11_WEP {
	ULONG Length;
	ULONG KeyIndex;
	ULONG KeyLength;
	UCHAR KeyMaterial[1];
} NDIS_802_11_WEP;
typedef ULONG NDIS_802_11_KEY_INDEX;
typedef ULONGLONG NDIS_802_11_KEY_RSC;

typedef struct NDIS_802_11_KEY {
	ULONG Length;
	ULONG KeyIndex;
	ULONG KeyLength;
	NDIS_802_11_MAC_ADDRESS BSSID;
	NDIS_802_11_KEY_RSC KeyRSC;
	UCHAR KeyMaterial[1];
} NDIS_802_11_KEY;
typedef struct NDIS_802_11_REMOVE_KEY {
	ULONG Length;
	ULONG KeyIndex;
	NDIS_802_11_MAC_ADDRESS BSSID;
} NDIS_802_11_REMOVE_KEY;
typedef struct NDIS_802_11_AI_REQFI {
	USHORT Capabilities;
	USHORT ListenInterval;
	NDIS_802_11_MAC_ADDRESS CurrentAPAddress;
} NDIS_802_11_AI_REQFI;
typedef struct NDIS_802_11_AI_RESFI {
	USHORT Capabilities;
	USHORT StatusCode;
	USHORT AssociationId;
} NDIS_802_11_AI_RESFI;
typedef struct NDIS_802_11_ASSOCIATION_INFORMATION {
	ULONG Length;
	USHORT AvailableRequestFixedIEs;
	NDIS_802_11_AI_REQFI RequestFixedIEs;
	ULONG RequestIELength;
	ULONG OffsetRequestIEs;
	USHORT AvailableResponseFixedIEs;
	NDIS_802_11_AI_RESFI ResponseFixedIEs;
	ULONG ResponseIELength;
	ULONG OffsetResponseIEs;
} NDIS_802_11_ASSOCIATION_INFORMATION;
typedef struct NDIS_802_11_AUTHENTICATION_ENCRYPTION {
	NDIS_802_11_AUTHENTICATION_MODE AuthModeSupported;
	NDIS_802_11_ENCRYPTION_STATUS EncryptStatusSupported;
} NDIS_802_11_AUTHENTICATION_ENCRYPTION;
typedef struct NDIS_802_11_CAPABILITY {
	ULONG Length;
	ULONG Version;
	ULONG NoOfPMKIDs;
	ULONG NoOfAuthEncryptPairsSupported;
	NDIS_802_11_AUTHENTICATION_ENCRYPTION
		AuthenticationEncryptionSupported[1];
} NDIS_802_11_CAPABILITY;
typedef UCHAR NDIS_802_11_PMKID_VALUE[16];

typedef struct BSSID_INFO {
	NDIS_802_11_MAC_ADDRESS BSSID;
	NDIS_802_11_PMKID_VALUE PMKID;
} BSSID_INFO;
typedef struct NDIS_802_11_PMKID {
	ULONG Length;
	ULONG BSSIDInfoCount;
	BSSID_INFO BSSIDInfo[1];
} NDIS_802_11_PMKID;
typedef enum NDIS_802_11_STATUS_TYPE {
	Ndis802_11StatusType_Authentication,
	Ndis802_11StatusType_PMKID_CandidateList = 2,
	Ndis802_11StatusTypeMax
} NDIS_802_11_STATUS_TYPE;
typedef struct NDIS_802_11_STATUS_INDICATION {
	NDIS_802_11_STATUS_TYPE StatusType;
} NDIS_802_11_STATUS_INDICATION;
typedef struct PMKID_CANDIDATE {
	NDIS_802_11_MAC_ADDRESS BSSID;
	ULONG Flags;
} PMKID_CANDIDATE;
#define NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED 0x01
typedef struct NDIS_802_11_PMKID_CANDIDATE_LIST {
	ULONG Version;
	ULONG NumCandidates;
	PMKID_CANDIDATE CandidateList[1];
} NDIS_802_11_PMKID_CANDIDATE_LIST;
typedef struct NDIS_802_11_AUTHENTICATION_REQUEST {
	ULONG Length;
	NDIS_802_11_MAC_ADDRESS Bssid;
	ULONG Flags;
} NDIS_802_11_AUTHENTICATION_REQUEST;
#define NDIS_802_11_AUTH_REQUEST_REAUTH			0x01
#define NDIS_802_11_AUTH_REQUEST_KEYUPDATE		0x02
#define NDIS_802_11_AUTH_REQUEST_PAIRWISE_ERROR		0x06
#define NDIS_802_11_AUTH_REQUEST_GROUP_ERROR		0x0E
#endif /* OID_802_11_BSSID */
#ifndef OID_802_11_PMKID
#define OID_802_11_CAPABILITY 			0x0d010122
#define OID_802_11_PMKID 			0x0d010123
#define Ndis802_11AuthModeWPA2 6
#define Ndis802_11AuthModeWPA2PSK 7
#define Ndis802_11StatusType_PMKID_CandidateList 2
typedef struct NDIS_802_11_AUTHENTICATION_ENCRYPTION {
	NDIS_802_11_AUTHENTICATION_MODE AuthModeSupported;
	NDIS_802_11_ENCRYPTION_STATUS EncryptStatusSupported;
} NDIS_802_11_AUTHENTICATION_ENCRYPTION;
typedef struct NDIS_802_11_CAPABILITY {
	ULONG Length;
	ULONG Version;
	ULONG NoOfPMKIDs;
	ULONG NoOfAuthEncryptPairsSupported;
	NDIS_802_11_AUTHENTICATION_ENCRYPTION
		AuthenticationEncryptionSupported[1];
} NDIS_802_11_CAPABILITY;
typedef UCHAR NDIS_802_11_PMKID_VALUE[16];

typedef struct BSSID_INFO {
	NDIS_802_11_MAC_ADDRESS BSSID;
	NDIS_802_11_PMKID_VALUE PMKID;
} BSSID_INFO;
typedef struct NDIS_802_11_PMKID {
	ULONG Length;
	ULONG BSSIDInfoCount;
	BSSID_INFO BSSIDInfo[1];
} NDIS_802_11_PMKID;
typedef struct PMKID_CANDIDATE {
	NDIS_802_11_MAC_ADDRESS BSSID;
	ULONG Flags;
} PMKID_CANDIDATE;
#define NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED 0x01
typedef struct NDIS_802_11_PMKID_CANDIDATE_LIST {
	ULONG Version;
	ULONG NumCandidates;
	PMKID_CANDIDATE CandidateList[1];
} NDIS_802_11_PMKID_CANDIDATE_LIST;
#endif /* OID_802_11_CAPABILITY */
#ifndef OID_DOT11_CURRENT_OPERATION_MODE
#define OID_DOT11_NDIS_START 0x0D010300
#define OID_DOT11_CURRENT_OPERATION_MODE (OID_DOT11_NDIS_START + 8)
#define OID_DOT11_SCAN_REQUEST (OID_DOT11_NDIS_START + 11)
typedef enum _DOT11_BSS_TYPE {
	dot11_BSS_type_infrastructure = 1,
	dot11_BSS_type_independent = 2,
	dot11_BSS_type_any = 3
} DOT11_BSS_TYPE, * PDOT11_BSS_TYPE;
typedef UCHAR DOT11_MAC_ADDRESS[6];
typedef DOT11_MAC_ADDRESS * PDOT11_MAC_ADDRESS;

typedef enum _DOT11_SCAN_TYPE {
	dot11_scan_type_active = 1,
	dot11_scan_type_passive = 2,
	dot11_scan_type_auto = 3,
	dot11_scan_type_forced = 0x80000000
} DOT11_SCAN_TYPE, * PDOT11_SCAN_TYPE;
typedef struct _DOT11_SCAN_REQUEST_V2 {
	DOT11_BSS_TYPE dot11BSSType;
	DOT11_MAC_ADDRESS dot11BSSID;
	DOT11_SCAN_TYPE dot11ScanType;
	BOOLEAN bRestrictedScan;
	ULONG udot11SSIDsOffset;
	ULONG uNumOfdot11SSIDs;
	BOOLEAN bUseRequestIE;
	ULONG uRequestIDsOffset;
	ULONG uNumOfRequestIDs;
	ULONG uPhyTypeInfosOffset;
	ULONG uNumOfPhyTypeInfos;
	ULONG uIEsOffset;
	ULONG uIEsLength;
	UCHAR ucBuffer[1];
} DOT11_SCAN_REQUEST_V2, * PDOT11_SCAN_REQUEST_V2;
#endif /* OID_DOT11_CURRENT_OPERATION_MODE */
#ifdef CONFIG_USE_NDISUIO
#ifndef _WIN32_WCE
#ifdef __MINGW32_VERSION
typedef ULONG NDIS_OID;
#endif /* __MINGW32_VERSION */
/* from nuiouser.h */
#define FSCTL_NDISUIO_BASE      FILE_DEVICE_NETWORK

#define _NDISUIO_CTL_CODE(_Function, _Method, _Access) \
	CTL_CODE(FSCTL_NDISUIO_BASE, _Function, _Method, _Access)

#define IOCTL_NDISUIO_OPEN_DEVICE \
	_NDISUIO_CTL_CODE(0x200, METHOD_BUFFERED, \
			  FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_NDISUIO_QUERY_OID_VALUE \
	_NDISUIO_CTL_CODE(0x201, METHOD_BUFFERED, \
			  FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_NDISUIO_SET_OID_VALUE \
	_NDISUIO_CTL_CODE(0x205, METHOD_BUFFERED, \
			  FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_NDISUIO_SET_ETHER_TYPE \
	_NDISUIO_CTL_CODE(0x202, METHOD_BUFFERED, \
			  FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_NDISUIO_QUERY_BINDING \
	_NDISUIO_CTL_CODE(0x203, METHOD_BUFFERED, \
			  FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_NDISUIO_BIND_WAIT \
	_NDISUIO_CTL_CODE(0x204, METHOD_BUFFERED, \
			  FILE_READ_ACCESS | FILE_WRITE_ACCESS)

typedef struct _NDISUIO_QUERY_OID
{
    NDIS_OID Oid;
    UCHAR Data[sizeof(ULONG)];
} NDISUIO_QUERY_OID, *PNDISUIO_QUERY_OID;
typedef struct _NDISUIO_SET_OID
{
    NDIS_OID Oid;
    UCHAR Data[sizeof(ULONG)];
} NDISUIO_SET_OID, *PNDISUIO_SET_OID;
typedef struct _NDISUIO_QUERY_BINDING
{
	ULONG BindingIndex;
	ULONG DeviceNameOffset;
	ULONG DeviceNameLength;
	ULONG DeviceDescrOffset;
	ULONG DeviceDescrLength;
} NDISUIO_QUERY_BINDING, *PNDISUIO_QUERY_BINDING;
#endif /* _WIN32_WCE */
#endif /* CONFIG_USE_NDISUIO */
#ifdef CONFIG_USE_NDISUIO
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#else /* CONFIG_USE_NDISUIO */
#endif /* CONFIG_USE_NDISUIO */
#ifdef CONFIG_USE_NDISUIO
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#else /* CONFIG_USE_NDISUIO */
#endif /* CONFIG_USE_NDISUIO */
#if 0 /* Setting bit30 does not seem to work with some NDIS drivers */
#endif
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifndef CONFIG_NDIS_EVENTS_INTEGRATED
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#endif /* CONFIG_NDIS_EVENTS_INTEGRATED */
#ifdef _WIN32_WCE
#define NDISUIO_MSG_SIZE (sizeof(NDISUIO_DEVICE_NOTIFICATION) + 512)
#ifdef NDISUIO_NOTIFICATION_ADAPTER_ARRIVAL
#endif
#ifdef NDISUIO_NOTIFICATION_ADAPTER_REMOVAL
#endif
#if _WIN32_WCE == 420 || _WIN32_WCE == 0x420
#else
#endif
#ifdef NDISUIO_NOTIFICATION_ADAPTER_ARRIVAL
#endif
#ifdef NDISUIO_NOTIFICATION_ADAPTER_REMOVAL
#endif
#endif /* _WIN32_WCE */
#ifdef CONFIG_USE_NDISUIO
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#else /* CONFIG_USE_NDISUIO */
#define MAX_ADAPTERS 32
#endif /* CONFIG_USE_NDISUIO */
#if defined(CONFIG_NATIVE_WINDOWS) || defined(__CYGWIN__)
#ifndef _WIN32_WCE
typedef struct {
	LPWSTR wszGuid;
} INTF_KEY_ENTRY, *PINTF_KEY_ENTRY;
typedef struct {
	DWORD dwNumIntfs;
	PINTF_KEY_ENTRY pIntfs;
} INTFS_KEY_TABLE, *PINTFS_KEY_TABLE;
typedef struct {
	DWORD dwDataLen;
	LPBYTE pData;
} RAW_DATA, *PRAW_DATA;
typedef struct {
	LPWSTR wszGuid;
	LPWSTR wszDescr;
	ULONG ulMediaState;
	ULONG ulMediaType;
	ULONG ulPhysicalMediaType;
	INT nInfraMode;
	INT nAuthMode;
	INT nWepStatus;
#ifndef _WIN32_WCE
	u8 pad[2]; /* why is this needed? */
#endif /* _WIN32_WCE */
	DWORD dwCtlFlags;
	DWORD dwCapabilities; /* something added for WinXP SP2(?) */
	RAW_DATA rdSSID;
	RAW_DATA rdBSSID;
	RAW_DATA rdBSSIDList;
	RAW_DATA rdStSSIDList;
	RAW_DATA rdCtrlData;
#ifdef UNDER_CE
	BOOL bInitialized;
#endif
	DWORD nWPAMCastCipher;
	/* add some extra buffer for later additions since this interface is
	 * far from stable */
	u8 later_additions[100];
} INTF_ENTRY, *PINTF_ENTRY;
#define INTF_ALL 0xffffffff
#define INTF_ALL_FLAGS 0x0000ffff
#define INTF_CTLFLAGS 0x00000010
#define INTFCTL_ENABLED 0x8000
#endif /* _WIN32_WCE */
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifdef _WIN32_WCE
#define WZC_DRIVER TEXT("Drivers\\BuiltIn\\ZeroConfig")
#else /* _WIN32_WCE */
#ifdef _WIN32_WCE
#else /* _WIN32_WCE */
#endif /* _WIN32_WCE */
#endif /* _WIN32_WCE */
#else /* CONFIG_NATIVE_WINDOWS || __CYGWIN__ */
#endif /* CONFIG_NATIVE_WINDOWS || __CYGWIN__ */
#ifdef CONFIG_USE_NDISUIO
#endif /* CONFIG_USE_NDISUIO */
#ifdef CONFIG_USE_NDISUIO
#ifndef _WIN32_WCE
#define NDISUIO_DEVICE_NAME TEXT("\\\\.\\\\Ndisuio")
#endif /* _WIN32_WCE */
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#else /* CONFIG_USE_NDISUIO */
#endif /* CONFIG_USE_NDISUIO */
#ifdef CONFIG_USE_NDISUIO
#define MAX_NDIS_DEVICE_NAME_LEN 256
#ifdef _WIN32_WCE
#else /* _WIN32_WCE */
#endif /* _WIN32_WCE */
#else /* CONFIG_USE_NDISUIO */
#endif /* CONFIG_USE_NDISUIO */
#ifdef CONFIG_USE_NDISUIO
#else /* CONFIG_USE_NDISUIO */
#endif /* CONFIG_USE_NDISUIO */
#ifdef CONFIG_NDIS_EVENTS_INTEGRATED
#endif /* CONFIG_NDIS_EVENTS_INTEGRATED */
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifdef CONFIG_NDIS_EVENTS_INTEGRATED
#endif /* CONFIG_NDIS_EVENTS_INTEGRATED */
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#ifdef CONFIG_USE_NDISUIO
#ifndef _WIN32_WCE
#endif /* _WIN32_WCE */
#else /* CONFIG_USE_NDISUIO */
#endif /* CONFIG_USE_NDISUIO */
