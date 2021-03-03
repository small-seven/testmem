#include "curl_setup.h"
#ifdef USE_LIBSSH2
#include <limits.h>
#include <libssh2.h>
#include <libssh2_sftp.h>
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef HAVE_UTSNAME_H
#include <sys/utsname.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef __VMS
#include <in.h>
#include <inet.h>
#endif
#if (defined(NETWARE) && defined(__NOVELL_LIBC__))
#undef in_addr_t
#define in_addr_t unsigned long
#endif
#include <curl/curl.h>
#include "urldata.h"
#include "sendf.h"
#include "hostip.h"
#include "progress.h"
#include "transfer.h"
#include "escape.h"
#include "http.h" /* for HTTP proxy tunnel stuff */
#include "ssh.h"
#include "url.h"
#include "speedcheck.h"
#include "getinfo.h"
#include "strdup.h"
#include "strcase.h"
#include "vtls/vtls.h"
#include "connect.h"
#include "strerror.h"
#include "inet_ntop.h"
#include "parsedate.h" /* for the week day and month names */
#include "sockaddr.h" /* required for Curl_sockaddr_storage */
#include "strtoofft.h"
#include "multiif.h"
#include "select.h"
#include "warnless.h"
#include "curl_path.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if LIBSSH2_VERSION_NUM >= 0x010206
#define HAS_STATVFS_SUPPORT 1
#endif
#define sftp_libssh2_last_error(s) curlx_ultosi(libssh2_sftp_last_error(s))
#define sftp_libssh2_realpath(s,p,t,m) \
#ifdef CURL_LIBSSH2_DEBUG
#else
#endif  /* CURL_LIBSSH2_DEBUG */
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifdef HAVE_LIBSSH2_KNOWNHOST_API
#endif
#ifdef HAVE_LIBSSH2_SFTP_SEEK64
#define SFTP_SEEK(x,y) libssh2_sftp_seek64(x, (libssh2_uint64_t)y)
#else
#define SFTP_SEEK(x,y) libssh2_sftp_seek(x, (size_t)y)
#endif
#ifndef HAVE_LIBSSH2_SCP_SEND64
#define SCP_SEND(a,b,c,d) libssh2_scp_send_ex(a, b, (int)(c), (size_t)d, 0, 0)
#else
#define SCP_SEND(a,b,c,d) libssh2_scp_send64(a, b, (int)(c),            \
#endif
#ifdef HAVE_LIBSSH2_SESSION_HANDSHAKE
#define libssh2_session_startup(x,y) libssh2_session_handshake(x,y)
#endif
#ifdef HAVE_LIBSSH2_KNOWNHOST_API
#ifdef LIBSSH2_HOSTKEY_TYPE_ECDSA_256
#endif
#ifdef LIBSSH2_HOSTKEY_TYPE_ECDSA_384
#endif
#ifdef LIBSSH2_HOSTKEY_TYPE_ECDSA_521
#endif
#ifdef LIBSSH2_HOSTKEY_TYPE_ED25519
#endif
#ifdef HAVE_LIBSSH2_KNOWNHOST_CHECKP
#else
#endif
#else /* HAVE_LIBSSH2_KNOWNHOST_API */
#endif
#ifdef HAVE_LIBSSH2_KNOWNHOST_API
#ifdef LIBSSH2_KNOWNHOST_KEY_ED25519
#endif
#ifdef LIBSSH2_KNOWNHOST_KEY_ECDSA_521
#endif
#ifdef LIBSSH2_KNOWNHOST_KEY_ECDSA_384
#endif
#ifdef LIBSSH2_KNOWNHOST_KEY_ECDSA_256
#endif
#ifdef LIBSSH2_KNOWNHOST_KEY_ED25519
#endif
#ifdef LIBSSH2_KNOWNHOST_KEY_ECDSA_521
#endif
#ifdef LIBSSH2_KNOWNHOST_KEY_ECDSA_384
#endif
#ifdef LIBSSH2_KNOWNHOST_KEY_ECDSA_256
#endif
#endif /* HAVE_LIBSSH2_KNOWNHOST_API */
#ifdef HAVE_LIBSSH2_AGENT_API
#endif /* HAVE_LIBSSH2_AGENT_API */
#ifdef HAVE_LIBSSH2_AGENT_API
#endif
#ifdef HAVE_LIBSSH2_AGENT_API
#endif
#ifdef HAS_STATVFS_SUPPORT
#endif
#ifdef HAS_STATVFS_SUPPORT
#endif
#if LIBSSH2_VERSION_NUM < 0x010700
#else
#endif
#if 0 /* PREV */
#endif
#ifdef HAVE_LIBSSH2_KNOWNHOST_API
#endif
#ifdef HAVE_LIBSSH2_AGENT_API
#endif
#ifdef HAVE_LIBSSH2_KNOWNHOST_API
#endif
#ifdef HAVE_LIBSSH2_AGENT_API
#endif
#ifdef HAVE_LIBSSH2_SESSION_BLOCK_DIRECTION
#else
#endif
#ifndef HAVE_LIBSSH2_SESSION_BLOCK_DIRECTION
#else
#endif
#ifdef HAVE_LIBSSH2_SESSION_BLOCK_DIRECTION
#else
#define ssh_block2waitfor(x,y) Curl_nop_stmt
#endif
#ifdef HAVE_LIBSSH2_SESSION_BLOCK_DIRECTION
#endif
#ifdef CURL_LIBSSH2_DEBUG
#endif
#ifdef CURL_LIBSSH2_DEBUG
#endif /* CURL_LIBSSH2_DEBUG */
#if LIBSSH2_VERSION_NUM >= 0x010208
#endif
#ifdef HAVE_LIBSSH2_KNOWNHOST_API
#endif /* HAVE_LIBSSH2_KNOWNHOST_API */
#ifdef CURL_LIBSSH2_DEBUG
#endif /* CURL_LIBSSH2_DEBUG */
#ifdef HAVE_LIBSSH2_INIT
#endif
#ifdef HAVE_LIBSSH2_EXIT
#endif
#endif /* USE_LIBSSH2 */
