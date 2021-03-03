#include "curl_setup.h"
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef HAVE_NET_IF_H
#include <net/if.h>
#endif
#ifdef HAVE_IPHLPAPI_H
#include <Iphlpapi.h>
#endif
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#ifdef __VMS
#include <in.h>
#include <inet.h>
#endif
#ifdef HAVE_SYS_UN_H
#include <sys/un.h>
#endif
#ifndef HAVE_SOCKET
#error "We can't compile without socket() support!"
#endif
#include <limits.h>
#ifdef USE_LIBIDN2
#include <idn2.h>
#elif defined(USE_WIN32_IDN)
#endif  /* USE_LIBIDN2 */
#include "urldata.h"
#include "netrc.h"
#include "formdata.h"
#include "mime.h"
#include "vtls/vtls.h"
#include "hostip.h"
#include "transfer.h"
#include "sendf.h"
#include "progress.h"
#include "cookie.h"
#include "strcase.h"
#include "strerror.h"
#include "escape.h"
#include "strtok.h"
#include "share.h"
#include "content_encoding.h"
#include "http_digest.h"
#include "http_negotiate.h"
#include "select.h"
#include "multiif.h"
#include "easyif.h"
#include "speedcheck.h"
#include "warnless.h"
#include "non-ascii.h"
#include "inet_pton.h"
#include "getinfo.h"
#include "urlapi-int.h"
#include "system_win32.h"
#include "ftp.h"
#include "dict.h"
#include "telnet.h"
#include "tftp.h"
#include "http.h"
#include "http2.h"
#include "file.h"
#include "curl_ldap.h"
#include "vssh/ssh.h"
#include "imap.h"
#include "url.h"
#include "connect.h"
#include "inet_ntop.h"
#include "http_ntlm.h"
#include "curl_rtmp.h"
#include "gopher.h"
#include "http_proxy.h"
#include "conncache.h"
#include "multihandle.h"
#include "dotdot.h"
#include "strdup.h"
#include "setopt.h"
#include "altsvc.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if READBUFFER_SIZE < READBUFFER_MIN
# error READBUFFER_SIZE is too small
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#if defined(USE_SSL) && !defined(CURL_DISABLE_HTTP)
#endif
#ifndef CURL_DISABLE_FTP
#endif
#if defined(USE_SSL) && !defined(CURL_DISABLE_FTP)
#endif
#ifndef CURL_DISABLE_TELNET
#endif
#ifndef CURL_DISABLE_DICT
#endif
#ifndef CURL_DISABLE_LDAP
#if !defined(CURL_DISABLE_LDAPS) && \
#endif
#endif
#ifndef CURL_DISABLE_FILE
#endif
#ifndef CURL_DISABLE_TFTP
#endif
#if defined(USE_SSH) && !defined(USE_WOLFSSH)
#endif
#if defined(USE_SSH)
#endif
#ifndef CURL_DISABLE_IMAP
#ifdef USE_SSL
#endif
#endif
#ifndef CURL_DISABLE_POP3
#ifdef USE_SSL
#endif
#endif
#if !defined(CURL_DISABLE_SMB) && defined(USE_NTLM) && \
#ifdef USE_SSL
#endif
#endif
#ifndef CURL_DISABLE_SMTP
#ifdef USE_SSL
#endif
#endif
#ifndef CURL_DISABLE_RTSP
#endif
#ifndef CURL_DISABLE_GOPHER
#endif
#ifdef USE_LIBRTMP
#endif
static void up_free(struct Curl_easy *data)
{
  struct urlpieces *up = &data->state.up;
  Curl_safefree(up->scheme);
  Curl_safefree(up->hostname);
  Curl_safefree(up->port);
  Curl_safefree(up->user);
  Curl_safefree(up->password);
  Curl_safefree(up->options);
  Curl_safefree(up->path);
  Curl_safefree(up->query);
  curl_url_cleanup(data->state.uh);
  data->state.uh = NULL;
}
#ifdef USE_ALTSVC
#endif
#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_CRYPTO_AUTH)
#endif
#ifndef CURL_DISABLE_DOH
#endif
#ifndef CURL_DISABLE_FTP
#endif
#ifdef USE_TLS_SRP
#endif
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif
#if defined(CURL_CA_BUNDLE)
#endif
#if defined(CURL_CA_PATH)
#endif
#ifdef USE_NGHTTP2
#else
#endif
#ifdef USE_RECV_BEFORE_SEND_WORKAROUND
#ifdef DEBUGBUILD
#endif /* DEBUGBUILD */
#else  /* ! USE_RECV_BEFORE_SEND_WORKAROUND */
#define conn_reset_all_postponed_data(c) do {} while(0)
#endif /* ! USE_RECV_BEFORE_SEND_WORKAROUND */
static void conn_free(struct connectdata *conn)
{
  DEBUGASSERT(conn);

  Curl_free_idnconverted_hostname(&conn->host);
  Curl_free_idnconverted_hostname(&conn->conn_to_host);
  Curl_free_idnconverted_hostname(&conn->http_proxy.host);
  Curl_free_idnconverted_hostname(&conn->socks_proxy.host);

  Curl_safefree(conn->user);
  Curl_safefree(conn->passwd);
  Curl_safefree(conn->sasl_authzid);
  Curl_safefree(conn->options);
  Curl_safefree(conn->http_proxy.user);
  Curl_safefree(conn->socks_proxy.user);
  Curl_safefree(conn->http_proxy.passwd);
  Curl_safefree(conn->socks_proxy.passwd);
  Curl_safefree(conn->allocptr.proxyuserpwd);
  Curl_safefree(conn->allocptr.uagent);
  Curl_safefree(conn->allocptr.userpwd);
  Curl_safefree(conn->allocptr.accept_encoding);
  Curl_safefree(conn->allocptr.te);
  Curl_safefree(conn->allocptr.rangeline);
  Curl_safefree(conn->allocptr.ref);
  Curl_safefree(conn->allocptr.host);
  Curl_safefree(conn->allocptr.cookiehost);
  Curl_safefree(conn->allocptr.rtsp_transport);
  Curl_safefree(conn->trailer);
  Curl_safefree(conn->host.rawalloc); /* host name buffer */
  Curl_safefree(conn->conn_to_host.rawalloc); /* host name buffer */
  Curl_safefree(conn->hostname_resolve);
  Curl_safefree(conn->secondaryhostname);
  Curl_safefree(conn->http_proxy.host.rawalloc); /* http proxy name buffer */
  Curl_safefree(conn->socks_proxy.host.rawalloc); /* socks proxy name buffer */
  Curl_safefree(conn->connect_state);

  conn_reset_all_postponed_data(conn);
  Curl_llist_destroy(&conn->easyq, NULL);
  Curl_safefree(conn->localdev);
  Curl_free_primary_ssl_config(&conn->ssl_config);
  Curl_free_primary_ssl_config(&conn->proxy_ssl_config);

#ifdef USE_UNIX_SOCKETS
  Curl_safefree(conn->unix_domain_socket);
#endif

#ifdef USE_SSL
  Curl_safefree(conn->ssl_extra);
#endif
  free(conn); /* free all the connection oriented data */
}
#ifndef CURL_DISABLE_PROXY
#else
#define proxy_info_matches(x,y) FALSE
#define socks_proxy_info_matches(x,y) FALSE
#endif
#ifdef USE_NTLM
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#if defined(USE_NTLM)
#endif
#ifdef USE_NGHTTP2
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#ifndef USE_LIBIDN2
#elif defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifdef USE_LIBIDN2
#if IDN2_VERSION_NUMBER >= 0x00140000
#else
#endif
#elif defined(USE_WIN32_IDN)
#else
#endif
#if defined(USE_LIBIDN2)
#elif defined(USE_WIN32_IDN)
#else
#endif
#ifdef USE_SSL
#endif
#if defined(USE_RECV_BEFORE_SEND_WORKAROUND) && defined(DEBUGBUILD)
#endif /* USE_RECV_BEFORE_SEND_WORKAROUND && DEBUGBUILD */
#if !defined(CURL_DISABLE_PROXY)
#endif /* CURL_DISABLE_PROXY */
#ifndef CURL_DISABLE_FTP
#endif
#if !defined(CURL_DISABLE_HTTP) && defined(USE_NTLM) && \
#endif
#ifdef HAVE_GSSAPI
#endif
#ifdef USE_SSL
#endif
#if defined(HAVE_IF_NAMETOINDEX)
#elif defined(WIN32)
#endif
#if defined(HAVE_IF_NAMETOINDEX) || defined(WIN32)
#if defined(WIN32)
#else
#endif
#endif /* HAVE_IF_NAMETOINDEX || WIN32 */
#ifndef CURL_DISABLE_DOH
#endif
#ifndef CURL_DISABLE_PROXY
#ifndef CURL_DISABLE_HTTP
#endif /* CURL_DISABLE_HTTP */
#ifdef USE_SSL
#endif
#ifndef CURL_DISABLE_HTTP
#endif /* CURL_DISABLE_HTTP */
#ifdef USE_UNIX_SOCKETS
#endif
#ifdef CURL_DISABLE_HTTP
#else
#endif
#endif /* CURL_DISABLE_PROXY */
#if defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifdef ENABLE_IPV6
#else
#endif
#ifdef USE_ALTSVC
#ifdef USE_NGHTTP2
#endif
#ifdef ENABLE_QUIC
#endif
#ifdef USE_NGHTTP2
#endif
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#ifndef CURL_DISABLE_PROXY
#endif
#ifndef CURL_DISABLE_FILE
#endif
#ifdef USE_TLS_SRP
#endif
#ifdef USE_SSL
#endif
#if defined(USE_NTLM)
#endif
#ifdef CURL_DO_LINEEND_CONV
#endif /* CURL_DO_LINEEND_CONV */
