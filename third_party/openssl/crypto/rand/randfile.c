#include "internal/cryptlib.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/crypto.h>
#include <openssl/rand.h>
#include <openssl/rand_drbg.h>
#include <openssl/buffer.h>
#ifdef OPENSSL_SYS_VMS
# include <unixio.h>
#endif
#include <sys/types.h>
#ifndef OPENSSL_NO_POSIX_IO
# include <sys/stat.h>
# include <fcntl.h>
# ifdef _WIN32
#  include <windows.h>
#  include <io.h>
#  define stat    _stat
#  define chmod   _chmod
#  define open    _open
#  define fdopen  _fdopen
#  define fstat   _fstat
#  define fileno  _fileno
# endif
#endif
# if !defined(S_ISREG)
#   define S_ISREG(m) ((m) & S_IFREG)
# endif
#define RAND_BUF_SIZE 1024
#define RFILE ".rnd"
#ifdef OPENSSL_SYS_VMS
# define VMS_OPEN_ATTRS \
# define openssl_fopen(fname, mode) vms_fopen((fname), (mode), VMS_OPEN_ATTRS)
#endif
#define RAND_LOAD_BUF_SIZE (RAND_BUF_SIZE + RAND_DRBG_STRENGTH)
#ifndef OPENSSL_NO_POSIX_IO
#endif
#ifndef OPENSSL_NO_POSIX_IO
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma environment save
# pragma message disable maylosedata2
#endif
#if defined(OPENSSL_SYS_VMS) && defined(__DECC)
# pragma environment restore
#endif
#ifdef EINTR
#endif
#ifndef OPENSSL_NO_POSIX_IO
#endif
#if defined(O_CREAT) && !defined(OPENSSL_NO_POSIX_IO) && \
# ifndef O_BINARY
#  define O_BINARY 0
# endif
#endif
#ifdef OPENSSL_SYS_VMS
#endif
#if !defined(NO_CHMOD) && !defined(OPENSSL_NO_POSIX_IO)
#endif
#if defined(_WIN32) && defined(CP_UTF8) && !defined(_WIN32_WCE)
#else
#endif
#ifdef DEFAULT_HOME
#endif
#ifndef OPENSSL_SYS_VMS
#endif
