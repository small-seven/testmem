#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && MSCHAP_SUPPORT  /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#endif /* UNUSED */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/chap-new.h"
#include "netif/ppp/chap_ms.h"
#include "netif/ppp/pppcrypt.h"
#include "netif/ppp/magic.h"
#if MPPE_SUPPORT
#include "netif/ppp/mppe.h" /* For mppe_sha1_pad*, mppe_set_key() */
#endif /* MPPE_SUPPORT */
#define SHA1_SIGNATURE_SIZE	20
#define MD4_SIGNATURE_SIZE	16	/* 16 bytes in a MD4 message digest */
#define MAX_NT_PASSWORD		256	/* Max (Unicode) chars in an NT pass */
#define MS_CHAP_RESPONSE_LEN	49	/* Response length for MS-CHAP */
#define MS_CHAP2_RESPONSE_LEN	49	/* Response length for MS-CHAPv2 */
#define MS_AUTH_RESPONSE_LENGTH	40	/* MS-CHAPv2 authenticator response, */
#define MS_CHAP_ERROR_RESTRICTED_LOGON_HOURS	646
#define MS_CHAP_ERROR_ACCT_DISABLED		647
#define MS_CHAP_ERROR_PASSWD_EXPIRED		648
#define MS_CHAP_ERROR_NO_DIALIN_PERMISSION	649
#define MS_CHAP_ERROR_AUTHENTICATION_FAILURE	691
#define MS_CHAP_ERROR_CHANGING_PASSWORD		709
#define MS_CHAP_LANMANRESP	0
#define MS_CHAP_LANMANRESP_LEN	24
#define MS_CHAP_NTRESP		24
#define MS_CHAP_NTRESP_LEN	24
#define MS_CHAP_USENT		48
#define MS_CHAP2_PEER_CHALLENGE	0
#define MS_CHAP2_PEER_CHAL_LEN	16
#define MS_CHAP2_RESERVED_LEN	8
#define MS_CHAP2_NTRESP		24
#define MS_CHAP2_NTRESP_LEN	24
#define MS_CHAP2_FLAGS		48
#if MPPE_SUPPORT
#if 0 /* UNUSED */
#define MPPE_ENC_POL_ENC_ALLOWED 1
#define MPPE_ENC_POL_ENC_REQUIRED 2
#define MPPE_ENC_TYPES_RC4_40 2
#define MPPE_ENC_TYPES_RC4_128 4
#endif /* UNUSED */
#endif /* MPPE_SUPPORT */
#define MS_CHAP2_AUTHENTICATEE 0
#define MS_CHAP2_AUTHENTICATOR 1
#ifdef MSLANMAN
#endif
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#ifdef MSLANMAN
#endif
#if MPPE_SUPPORT
#ifdef DEBUGMPPEKEY
#endif
#include "netif/ppp/fsm.h"		/* Need to poke MPPE options */
#include "netif/ppp/ccp.h"
#endif /* MPPE_SUPPORT */
#if PPP_OPTIONS
#ifdef MSLANMAN
#endif
#ifdef DEBUGMPPEKEY
#endif
#endif /* PPP_OPTIONS */
#if PPP_SERVER
#ifdef DEBUGMPPEKEY
#endif
#ifdef DEBUGMPPEKEY
#endif
#ifndef MSLANMAN
#endif
#ifdef MSLANMAN
#endif
#endif /* PPP_SERVER */
#ifdef DEBUGMPPEKEY
#else
#endif
#if 0
#endif
#if 0
#endif
#ifdef MSLANMAN
#endif
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if !MPPE_SUPPORT
#endif /* !MPPE_SUPPORT */
#ifdef MSLANMAN
#else
#endif
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if !MPPE_SUPPORT
#endif /* !MPPE_SUPPORT */
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if 0 /* UNUSED */
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#endif /* UNUSED */
#if PPP_SERVER
#endif /* PPP_SERVER */
#if PPP_SERVER
#endif /* PPP_SERVER */
#endif /* PPP_SUPPORT && MSCHAP_SUPPORT */
