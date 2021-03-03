#include "includes.h"
#ifdef __APPLE__
#include <PCSC/winscard.h>
#else
#include <winscard.h>
#endif
#include "common.h"
#include "pcsc_funcs.h"
#define SIM_CMD_SELECT			0xa0, 0xa4, 0x00, 0x00, 0x02
#define SIM_CMD_RUN_GSM_ALG		0xa0, 0x88, 0x00, 0x00, 0x10
#define SIM_CMD_GET_RESPONSE		0xa0, 0xc0, 0x00, 0x00
#define SIM_CMD_READ_BIN		0xa0, 0xb0, 0x00, 0x00
#define SIM_CMD_READ_RECORD		0xa0, 0xb2, 0x00, 0x00
#define SIM_CMD_VERIFY_CHV1		0xa0, 0x20, 0x00, 0x01, 0x08
#define USIM_CLA			0x00
#define USIM_CMD_RUN_UMTS_ALG		0x00, 0x88, 0x00, 0x81, 0x22
#define USIM_CMD_GET_RESPONSE		0x00, 0xc0, 0x00, 0x00
#define SIM_RECORD_MODE_ABSOLUTE 0x04
#define USIM_FSP_TEMPL_TAG		0x62
#define USIM_TLV_FILE_DESC		0x82
#define USIM_TLV_FILE_ID		0x83
#define USIM_TLV_DF_NAME		0x84
#define USIM_TLV_PROPR_INFO		0xA5
#define USIM_TLV_LIFE_CYCLE_STATUS	0x8A
#define USIM_TLV_FILE_SIZE		0x80
#define USIM_TLV_TOTAL_FILE_SIZE	0x81
#define USIM_TLV_PIN_STATUS_TEMPLATE	0xC6
#define USIM_TLV_SHORT_FILE_ID		0x88
#define USIM_TLV_SECURITY_ATTR_8B	0x8B
#define USIM_TLV_SECURITY_ATTR_8C	0x8C
#define USIM_TLV_SECURITY_ATTR_AB	0xAB
#define USIM_PS_DO_TAG			0x90
#define AKA_RAND_LEN 16
#define AKA_AUTN_LEN 16
#define AKA_AUTS_LEN 14
#define RES_MAX_LEN 16
#define IK_LEN 16
#define CK_LEN 16
#define SCARD_FILE_MF		0x3F00
#define SCARD_FILE_GSM_DF	0x7F20
#define SCARD_FILE_UMTS_DF	0x7F50
#define SCARD_FILE_GSM_EF_IMSI	0x6F07
#define SCARD_FILE_GSM_EF_AD	0x6FAD
#define SCARD_FILE_EF_DIR	0x2F00
#define SCARD_FILE_EF_ICCID	0x2FE2
#define SCARD_FILE_EF_CK	0x6FE1
#define SCARD_FILE_EF_IK	0x6FE2
#define SCARD_CHV1_OFFSET	13
#define SCARD_CHV1_FLAG		0x80
typedef enum { SCARD_GSM_SIM, SCARD_USIM } sim_types;

struct scard_data {
	SCARDCONTEXT ctx;
	SCARDHANDLE card;
#ifdef __APPLE__
	uint32_t protocol;
#else
	DWORD protocol;
#endif
	sim_types sim_type;
	int pin1_required;
};
#ifdef __MINGW32_VERSION
#undef SCARD_PCI_T0
#define SCARD_PCI_T0 (dll_g_rgSCardT0Pci)
#undef SCARD_PCI_T1
#define SCARD_PCI_T1 (dll_g_rgSCardT1Pci)
#define SCardEstablishContext dll_SCardEstablishContext
#define SCardReleaseContext dll_SCardReleaseContext
#undef SCardListReaders
#define SCardListReaders dll_SCardListReadersA
#undef SCardConnect
#define SCardConnect dll_SCardConnectA
#define SCardDisconnect dll_SCardDisconnect
#define SCardTransmit dll_SCardTransmit
#define SCardBeginTransaction dll_SCardBeginTransaction
#define SCardEndTransaction dll_SCardEndTransaction
#define LOADSYM(s) \
#undef LOADSYM
#else /* __MINGW32_VERSION */
#define mingw_load_symbols() 0
#define mingw_unload_symbols() do { } while (0)
#endif /* __MINGW32_VERSION */
#ifdef __APPLE__
#else
#endif
#ifdef CONFIG_NATIVE_WINDOWS
#else /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef UNICODE
#endif /* UNICODE */
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#ifdef __APPLE__
#else
#endif
