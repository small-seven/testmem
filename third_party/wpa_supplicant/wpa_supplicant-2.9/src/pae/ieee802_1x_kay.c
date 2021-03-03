#include <time.h>
#include "includes.h"
#include "common.h"
#include "list.h"
#include "eloop.h"
#include "wpabuf.h"
#include "state_machine.h"
#include "l2_packet/l2_packet.h"
#include "common/eapol_common.h"
#include "crypto/aes_wrap.h"
#include "ieee802_1x_cp.h"
#include "ieee802_1x_key.h"
#include "ieee802_1x_kay.h"
#include "ieee802_1x_kay_i.h"
#include "ieee802_1x_secy_ops.h"
#define DEFAULT_SA_KEY_LEN	16
#define DEFAULT_ICV_LEN		16
#define MAX_ICV_LEN		32  /* 32 bytes, 256 bits */
#define MAX_MISSING_SAK_USE 10  /* Accept up to 10 inbound MKPDUs without
#define PENDING_PN_EXHAUSTION 0xC0000000
#define MKA_ALIGN_LENGTH(len) (((len) + 0x3) & ~0x3)
#define MKA_ALGO_AGILITY_2009 { 0x00, 0x80, 0xC2, 0x01 }
#define CS_TABLE_SIZE (ARRAY_SIZE(cipher_suite_tbl))
#define DEFAULT_CS_INDEX  0
#define MKA_ALG_TABLE_SIZE (ARRAY_SIZE(mka_alg_tbl))
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
