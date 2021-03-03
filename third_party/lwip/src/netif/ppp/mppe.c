#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && MPPE_SUPPORT  /* don't build if not configured for use in lwipopts.h */
#include <string.h>
#include "lwip/err.h"
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/ccp.h"
#include "netif/ppp/mppe.h"
#include "netif/ppp/pppdebug.h"
#include "netif/ppp/pppcrypt.h"
#define SHA1_SIGNATURE_SIZE 20
#define MPPE_BIT_A	0x80	/* Encryption table were (re)inititalized */
#define MPPE_BIT_B	0x40	/* MPPC only (not implemented) */
#define MPPE_BIT_C	0x20	/* MPPC only (not implemented) */
#define MPPE_BIT_D	0x10	/* This is an encrypted frame */
#define MPPE_BIT_FLUSHED	MPPE_BIT_A
#define MPPE_BIT_ENCRYPTED	MPPE_BIT_D
#define MPPE_BITS(p) ((p)[0] & 0xf0)
#define MPPE_CCOUNT(p) ((((p)[0] & 0x0f) << 8) + (p)[1])
#define MPPE_CCOUNT_SPACE 0x1000	/* The size of the ccount space */
#define MPPE_OVHD	2	/* MPPE overhead/packet */
#define SANITY_MAX	1600	/* Max bogon factor we will tolerate */
#if PPP_DEBUG
#endif /* PPP_DEBUG */
#if PPP_DEBUG
#endif /* PPP_DEBUG */
#endif /* PPP_SUPPORT && MPPE_SUPPORT */
