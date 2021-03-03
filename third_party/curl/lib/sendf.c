#include "curl_setup.h"
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_LINUX_TCP_H
#include <linux/tcp.h>
#endif
#include <curl/curl.h>
#include "urldata.h"
#include "sendf.h"
#include "connect.h"
#include "vtls/vtls.h"
#include "vssh/ssh.h"
#include "easyif.h"
#include "multiif.h"
#include "non-ascii.h"
#include "strerror.h"
#include "select.h"
#include "strdup.h"
#include "http2.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef CURL_DO_LINEEND_CONV
#endif /* CURL_DO_LINEEND_CONV */
#ifdef USE_RECV_BEFORE_SEND_WORKAROUND
#ifdef DEBUGBUILD
#endif /* DEBUGBUILD */
#ifdef DEBUGBUILD
#endif /* DEBUGBUILD */
#else  /* ! USE_RECV_BEFORE_SEND_WORKAROUND */
#define pre_receive_plain(c,n) do {} while(0)
#define get_pre_recved(c,n,b,l) 0
#endif /* ! USE_RECV_BEFORE_SEND_WORKAROUND */
#if defined(MSG_FASTOPEN) && !defined(TCP_FASTOPEN_CONNECT) /* Linux */
#endif
#ifdef WSAEWOULDBLOCK
#else
#endif
#ifdef WSAEWOULDBLOCK
#else
#endif
#ifdef CURL_DO_LINEEND_CONV
#endif /* CURL_DO_LINEEND_CONV */
#ifdef USE_WINSOCK
#else
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif /* CURL_DOES_CONVERSIONS */
#ifdef CURL_DOES_CONVERSIONS
#endif
#ifdef CURL_DOES_CONVERSIONS
#endif
