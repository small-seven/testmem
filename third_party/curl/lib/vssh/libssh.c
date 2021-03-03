#include "curl_setup.h"
#ifdef USE_LIBSSH
#include <limits.h>
#include <libssh/libssh.h>
#include <libssh/sftp.h>
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
#include "http.h"               /* for HTTP proxy tunnel stuff */
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
#include "parsedate.h"          /* for the week day and month names */
#include "sockaddr.h"           /* required for Curl_sockaddr_storage */
#include "strtoofft.h"
#include "multiif.h"
#include "select.h"
#include "warnless.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#include "curl_path.h"
#ifndef SSH_STRING_FREE_CHAR
#define SSH_STRING_FREE_CHAR(x)                 \
#endif
#ifndef DEBUGBUILD
#define state(x,y) mystate(x,y)
#else
#define state(x,y) mystate(x,y, __LINE__)
#endif
#ifdef DEBUGBUILD
#endif
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#if LIBSSH_VERSION_INT >= SSH_VERSION_INT(0,9,0)
#endif
#if LIBSSH_VERSION_INT >= SSH_VERSION_INT(0,8,0)
#else
#endif
#if LIBSSH_VERSION_INT >= SSH_VERSION_INT(0,9,0)
#else
#endif
#if LIBSSH_VERSION_INT >= SSH_VERSION_INT(0,7,0)
#endif
#if LIBSSH_VERSION_INT >= SSH_VERSION_INT(0,8,0)
#else
#endif
#if LIBSSH_VERSION_INT >= SSH_VERSION_INT(0,9,0)
#endif
#define MOVE_TO_ERROR_STATE(_r) { \
#define MOVE_TO_SFTP_CLOSE_STATE() { \
#define MOVE_TO_LAST_AUTH \
#define MOVE_TO_TERTIARY_AUTH \
#define MOVE_TO_SECONDARY_AUTH \
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0 /* not returned by libssh on write */
#endif
#ifdef HAS_STATVFS_SUPPORT
#endif
#endif                          /* USE_LIBSSH */
