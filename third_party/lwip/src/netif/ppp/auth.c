#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <utmp.h>
#include <fcntl.h>
#if defined(_PATH_LASTLOG) && defined(__linux__)
#include <lastlog.h>
#endif
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#ifdef HAS_SHADOW
#include <shadow.h>
#ifndef PW_PPP
#define PW_PPP PW_LOGIN
#endif
#endif
#include <time.h>
#endif /* UNUSED */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/fsm.h"
#include "netif/ppp/lcp.h"
#if CCP_SUPPORT
#include "netif/ppp/ccp.h"
#endif /* CCP_SUPPORT */
#if ECP_SUPPORT
#include "netif/ppp/ecp.h"
#endif /* ECP_SUPPORT */
#include "netif/ppp/ipcp.h"
#if PAP_SUPPORT
#include "netif/ppp/upap.h"
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#include "netif/ppp/chap-new.h"
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#include "netif/ppp/eap.h"
#endif /* EAP_SUPPORT */
#if CBCP_SUPPORT
#include "netif/ppp/cbcp.h"
#endif
#if 0 /* UNUSED */
#include "session.h"
#endif /* UNUSED */
#if 0 /* UNUSED */
#define NONWILD_SERVER	1
#define NONWILD_CLIENT	2
#define ISWILD(word)	(word[0] == '*' && word[1] == 0)
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#ifdef HAVE_MULTILINK
#endif
#if PPP_NOTIFY
#endif /* PPP_NOTIFY */
#if 0 /* MOVED TO ppp_settings */
#if MSCHAP_SUPPORT
#else /* MSCHAP_SUPPORT */
#endif /* MSCHAP_SUPPORT */
#endif /* UNUSED */
#if PPP_IDLETIMELIMIT
#endif /* PPP_IDLETIMELIMIT */
#if PPP_MAXCONNECT
#endif /* PPP_MAXCONNECT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#ifdef MAXOCTETS
#endif
#if PPP_OPTIONS
#if MSCHAP_SUPPORT
#endif /* MSCHAP_SUPPORT */
#if 0
#endif
#if MSCHAP_SUPPORT
#if 0
#endif
#endif /* MSCHAP_SUPPORT*/
#if EAP_SUPPORT
#if 0
#endif
#endif /* EAP_SUPPORT */
#if 0
#endif
#endif /* PPP_OPTIONS */
#if 0 /* UNUSED */
#endif
#if 0
#endif
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_STATS_SUPPORT
#endif /* PPP_STATS_SUPPORT */
#if 0
#endif
#if PPP_NOTIFY
#endif /* PPP_NOTIFY */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if PPP_AUTH_SUPPORT
#if PPP_SERVER
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#endif /* PPP_SERVER */
#endif /* PPP_AUTH_SUPPORT */
#if PPP_AUTH_SUPPORT
#if PPP_SERVER
#if PPP_ALLOWED_ADDRS
#endif /* PPP_ALLOWED_ADDRS */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if PPP_ALLOWED_ADDRS
#endif /* PPP_ALLOWED_ADDRS */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* PPP_SERVER */
#if PPP_SERVER
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#endif /* PPP_SERVER */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#endif /* PPP_AUTH_SUPPORT */
#if CBCP_SUPPORT
#endif
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_NOTIFY
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#endif /* PPP_NOTIFY */
#if CBCP_SUPPORT
#endif
#if PPP_OPTIONS
#endif /* PPP_OPTIONS */
#if CCP_SUPPORT || ECP_SUPPORT
#endif /* CCP_SUPPORT || ECP_SUPPORT */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#ifdef PPP_FILTER
#endif
#if CCP_SUPPORT || ECP_SUPPORT
#if ECP_SUPPORT
#endif /* ECP_SUPPORT */
#if CCP_SUPPORT
#endif /* CCP_SUPPORT */
#endif /* CCP_SUPPORT || ECP_SUPPORT */
#if ECP_SUPPORT
#endif /* ECP_SUPPORT */
#if MPPE_SUPPORT
#endif /* MPPE_SUPPORT */
#if CCP_SUPPORT
#endif /* CCP_SUPPORT */
#if ECP_SUPPORT
#endif /* ECP_SUPPORT */
#if PPP_AUTH_SUPPORT
#if PPP_SERVER
#if 0 /* UNUSED */
#endif /* UNUSED */
#ifndef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if CHAP_SUPPORT
#if MSCHAP_SUPPORT
#endif /* MSCHAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#ifdef HAVE_MULTILINK
#endif /* HAVE_MULTILINK */
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* PPP_SERVER */
#if CHAP_SUPPORT
#if MSCHAP_SUPPORT
#endif /* MSCHAP_SUPPORT */
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#endif /* PPP_AUTH_SUPPORT */
#if PPP_IDLETIMELIMIT
#endif /* PPP_IDLETIMELIMIT */
#if PPP_IDLETIMELIMIT
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* PPP_IDLETIMELIMIT */
#if PPP_MAXCONNECT
#endif /* PPP_MAXCONNECT */
#ifdef MAXOCTETS
#endif
#if 0 /* Unused */
#endif /* Unused */
#if PPP_IDLETIMELIMIT
#endif /* PPP_IDLETIMELIMIT */
#if PPP_MAXCONNECT
#endif /* PPP_MAXCONNECT */
#ifdef MAXOCTETS
#endif
#ifdef MAXOCTETS
#if PPP_STATS_SUPPORT
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* PPP_STATS_SUPPORT */
#endif /* MAXOCTETS */
#if PPP_IDLETIMELIMIT
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* PPP_IDLETIMELIMIT */
#if PPP_MAXCONNECT
#endif /* PPP_MAXCONNECT */
#if PPP_OPTIONS
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if PAP_SUPPORT
#endif /* PAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if PAP_SUPPORT
#else
#endif /* PAP_SUPPORT */
#if CHAP_SUPPORT
#endif /* CHAP_SUPPORT */
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#if CHAP_SUPPORT
#else
#endif
#if EAP_SUPPORT
#endif /* EAP_SUPPORT */
#endif /* PPP_OPTIONS */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PPP_AUTH_SUPPORT
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* PPP_AUTH_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#endif /* PPP_SUPPORT */
