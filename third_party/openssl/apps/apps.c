#if !defined(_POSIX_C_SOURCE) && defined(OPENSSL_SYS_VMS)
# define _POSIX_C_SOURCE 2
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#ifndef OPENSSL_NO_POSIX_IO
# include <sys/stat.h>
# include <fcntl.h>
#endif
#include <ctype.h>
#include <errno.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/pem.h>
#include <openssl/pkcs12.h>
#include <openssl/ui.h>
#include <openssl/safestack.h>
#ifndef OPENSSL_NO_ENGINE
# include <openssl/engine.h>
#endif
#ifndef OPENSSL_NO_RSA
# include <openssl/rsa.h>
#endif
#include <openssl/bn.h>
#include <openssl/ssl.h>
#include "apps.h"
#ifdef _WIN32
# define rename(from,to) WIN32_rename((from),(to))
#endif
#if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_MSDOS)
# include <conio.h>
#endif
#if defined(OPENSSL_SYS_MSDOS) && !defined(_WIN32)
# define _kbhit kbhit
#endif
typedef struct {
    const char *name;
    unsigned long flag;
    unsigned long mask;
} NAME_EX_TBL;
#ifndef APP_INIT
#endif
#ifndef OPENSSL_NO_CT
#endif
#ifndef OPENSSL_NO_UI_CONSOLE
#endif
#if !defined(_WIN32)
#endif
#if !defined(OPENSSL_NO_OCSP) && !defined(OPENSSL_NO_SOCK)
#endif
#if !defined(OPENSSL_NO_OCSP) && !defined(OPENSSL_NO_SOCK)
#endif
#if !defined(OPENSSL_NO_OCSP) && !defined(OPENSSL_NO_SOCK)
#endif
#ifndef OPENSSL_NO_ENGINE
#else
#endif
#if !defined(OPENSSL_NO_RSA) && !defined(OPENSSL_NO_DSA) && !defined (OPENSSL_NO_RC4)
#endif
#ifndef OPENSSL_NO_ENGINE
#else
#endif
#ifndef OPENSSL_NO_RSA
#else
#endif
#ifndef OPENSSL_NO_RSA
#else
#endif
#if !defined(OPENSSL_NO_RSA) && !defined(OPENSSL_NO_DSA)
#endif
void* app_malloc(int sz, const char *what)
{
    void *vp = OPENSSL_malloc(sz);

    if (vp == NULL) {
        BIO_printf(bio_err, "%s: Could not allocate %d bytes for %s\n",
                opt_getprog(), sz, what);
        ERR_print_errors(bio_err);
        exit(1);
    }
    return vp;
}
#define X509V3_EXT_UNKNOWN_MASK         (0xfL << 16)
#define X509V3_EXT_DEFAULT              0
#define X509V3_EXT_ERROR_UNKNOWN        (1L << 16)
#define X509V3_EXT_PARSE_UNKNOWN        (2L << 16)
#define X509V3_EXT_DUMP_UNKNOWN         (3L << 16)
#define X509_FLAG_CA (X509_FLAG_NO_ISSUER | X509_FLAG_NO_PUBKEY | \
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
#undef BSIZE
#define BSIZE 256
#ifndef OPENSSL_SYS_VMS
#else
#endif
#ifndef OPENSSL_SYS_VMS
#else
#endif
#ifdef ENOTDIR
#endif
#ifndef OPENSSL_NO_POSIX_IO
#endif
#ifndef OPENSSL_NO_POSIX_IO
#endif
#ifndef OPENSSL_SYS_VMS
#else
#endif
#ifndef OPENSSL_NO_POSIX_IO
#endif
#ifndef OPENSSL_SYS_VMS
#else
#endif
#ifndef OPENSSL_SYS_VMS
#else
#endif
#ifdef ENOTDIR
#endif
#ifdef ENOTDIR
#endif
#if defined(_WIN32)
# ifdef fileno
#  undef fileno
#  define fileno(a) (int)_fileno(a)
# endif
# include <windows.h>
# include <tchar.h>
# if !defined(_WIN32_WCE) || _WIN32_WCE>=101
# endif
# if !defined(_WIN32_WCE) || _WIN32_WCE>=101
# endif
#endif
#if defined(_WIN32)
# ifdef _WIN32_WINNT
# endif
#elif defined(OPENSSL_SYS_VXWORKS)
# include <time.h>
# ifdef CLOCK_REALTIME
# else
# endif
# ifdef CLOCK_REALTIME
# else
# endif
#elif defined(OPENSSL_SYSTEM_VMS)
# include <time.h>
# include <times.h>
# ifdef __TMS
# else
# endif
#elif defined(_SC_CLK_TCK)      /* by means of unistd.h */
# include <sys/times.h>
#else
# include <sys/time.h>
# include <sys/resource.h>
#endif
#ifdef _WIN32
#else
#endif
#ifdef _WIN32
# if defined(UNICODE) || defined(_UNICODE)
#  if !defined(_WIN32_WCE) || _WIN32_WCE>=101
#  endif
# else
# endif
#else
# include <sys/stat.h>
# ifndef S_ISDIR
#  if defined(_S_IFMT) && defined(_S_IFDIR)
#   define S_ISDIR(a)   (((a) & _S_IFMT) == _S_IFDIR)
#  else
#   define S_ISDIR(a)   (((a) & S_IFMT) == S_IFDIR)
#  endif
# endif
# if defined(S_ISDIR)
# else
# endif
#endif
#if defined(__VMS)
# include "vms_term_sock.h"
#else
#endif
#if defined(_WIN32) && defined(STD_INPUT_HANDLE)
#elif defined(__VMS)
# include <sys/socket.h>
#else
#endif
#if defined(_WIN32) && defined(STD_OUTPUT_HANDLE)
#else
#endif
#ifdef OPENSSL_SYS_VMS
#endif
#ifdef OPENSSL_SYS_VMS
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma environment save
# pragma message disable maylosedata2
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma environment restore
#endif
#ifdef O_CREAT
#endif
#ifdef O_TRUNC
#endif
#ifdef O_BINARY
#elif defined(_O_BINARY)
#endif
#ifdef OPENSSL_SYS_VMS
#endif
#ifndef OPENSSL_SYS_WINDOWS
#endif
#if defined(OPENSSL_SYS_MSDOS)
# if defined(OPENSSL_SYS_WINDOWS)
# endif
#endif
