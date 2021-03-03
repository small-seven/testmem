#include "curl_setup.h"
#include <curl/curl.h>
#include "urldata.h"
#include "vtls/vtls.h"
#include "http2.h"
#include "vssh/ssh.h"
#include "quic.h"
#include "curl_printf.h"
#ifdef USE_ARES
#  if defined(CURL_STATICLIB) && !defined(CARES_STATICLIB) && \
#    define CARES_STATICLIB
#  endif
#  include <ares.h>
#endif
#ifdef USE_LIBIDN2
#include <idn2.h>
#endif
#ifdef USE_LIBPSL
#include <libpsl.h>
#endif
#if defined(HAVE_ICONV) && defined(CURL_DOES_CONVERSIONS)
#include <iconv.h>
#endif
#ifdef USE_LIBRTMP
#include <librtmp/rtmp.h>
#endif
#ifdef HAVE_ZLIB_H
#include <zlib.h>
#ifdef __SYMBIAN32__
#undef WIN32
#endif
#endif
#ifdef HAVE_BROTLI
#include <brotli/decode.h>
#endif
#ifdef HAVE_BROTLI
#endif
#ifdef USE_SSL
#endif
#ifdef HAVE_LIBZ
#endif
#ifdef HAVE_BROTLI
#endif
#ifdef USE_ARES
#endif
#if defined(USE_LIBIDN2) || defined(USE_WIN32_IDN)
#endif
#ifdef USE_LIBPSL
#endif
#if defined(HAVE_ICONV) && defined(CURL_DOES_CONVERSIONS)
#endif
#ifdef USE_SSH
#endif
#ifdef USE_NGHTTP2
#endif
#ifdef ENABLE_QUIC
#endif
#ifdef USE_LIBRTMP
#endif
#ifdef USE_SSL
#endif
#ifdef HAVE_LIBZ
#endif
#ifdef HAVE_BROTLI
#endif
#ifdef USE_ARES
#endif
#ifdef USE_LIBIDN2
#elif defined(USE_WIN32_IDN)
#endif
#ifdef USE_LIBPSL
#endif
#if defined(HAVE_ICONV) && defined(CURL_DOES_CONVERSIONS)
#ifdef _LIBICONV_VERSION
#else
#endif /* _LIBICONV_VERSION */
#endif
#ifdef USE_SSH
#endif
#ifdef USE_NGHTTP2
#endif
#ifdef ENABLE_QUIC
#endif
#ifdef USE_LIBRTMP
#endif
#ifndef CURL_DISABLE_DICT
#endif
#ifndef CURL_DISABLE_FILE
#endif
#ifndef CURL_DISABLE_FTP
#endif
#if defined(USE_SSL) && !defined(CURL_DISABLE_FTP)
#endif
#ifndef CURL_DISABLE_GOPHER
#endif
#ifndef CURL_DISABLE_HTTP
#endif
#if defined(USE_SSL) && !defined(CURL_DISABLE_HTTP)
#endif
#ifndef CURL_DISABLE_IMAP
#endif
#if defined(USE_SSL) && !defined(CURL_DISABLE_IMAP)
#endif
#ifndef CURL_DISABLE_LDAP
#if !defined(CURL_DISABLE_LDAPS) && \
#endif
#endif
#ifndef CURL_DISABLE_POP3
#endif
#if defined(USE_SSL) && !defined(CURL_DISABLE_POP3)
#endif
#ifdef USE_LIBRTMP
#endif
#ifndef CURL_DISABLE_RTSP
#endif
#if defined(USE_SSH) && !defined(USE_WOLFSSH)
#endif
#ifdef USE_SSH
#endif
#if !defined(CURL_DISABLE_SMB) && defined(USE_NTLM) && \
#  ifdef USE_SSL
#  endif
#endif
#ifndef CURL_DISABLE_SMTP
#endif
#if defined(USE_SSL) && !defined(CURL_DISABLE_SMTP)
#endif
#ifndef CURL_DISABLE_TELNET
#endif
#ifndef CURL_DISABLE_TFTP
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef USE_SSL
#endif
#ifdef USE_NTLM
#endif
#if !defined(CURL_DISABLE_HTTP) && defined(USE_NTLM) && \
#endif
#ifdef USE_SPNEGO
#endif
#ifdef USE_KERBEROS5
#endif
#ifdef HAVE_GSSAPI
#endif
#ifdef USE_WINDOWS_SSPI
#endif
#ifdef HAVE_LIBZ
#endif
#ifdef DEBUGBUILD
#endif
#ifdef CURLDEBUG
#endif
#ifdef CURLRES_ASYNCH
#endif
#if (CURL_SIZEOF_CURL_OFF_T > 4) && \
#endif
#if defined(CURL_DOES_CONVERSIONS)
#endif
#if defined(USE_TLS_SRP)
#endif
#if defined(USE_NGHTTP2)
#endif
#if defined(ENABLE_QUIC)
#endif
#if defined(USE_UNIX_SOCKETS)
#endif
#if defined(USE_LIBPSL)
#endif
#if defined(CURL_WITH_MULTI_SSL)
#endif
#if defined(HAVE_BROTLI)
#endif
#if defined(USE_ALTSVC)
#endif
#ifdef USE_ESNI
#endif
#if defined(USE_SSH)
#endif
#ifdef USE_SSL
#ifdef CURL_WITH_MULTI_SSL
#else
#endif
#endif
#ifdef HAVE_BROTLI
#endif
#ifdef USE_SSL
#endif
#ifdef HAVE_LIBZ
#endif
#ifdef USE_ARES
#endif
#ifdef USE_LIBIDN2
#elif defined(USE_WIN32_IDN)
#endif
#if defined(HAVE_ICONV) && defined(CURL_DOES_CONVERSIONS)
#ifdef _LIBICONV_VERSION
#else
#endif /* _LIBICONV_VERSION */
#endif
#if defined(USE_SSH)
#endif
#ifdef HAVE_BROTLI
#endif
#ifdef USE_NGHTTP2
#endif
#ifdef ENABLE_QUIC
#endif
