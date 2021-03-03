#include "apps.h"
#include <string.h>
#if !defined(OPENSSL_SYS_MSDOS)
# include OPENSSL_UNISTD
#endif
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <openssl/bio.h>
#include <openssl/x509v3.h>
#define MAX_OPT_HELP_WIDTH 30
#if defined(OPENSSL_SYS_WIN32)
#elif defined(OPENSSL_SYS_VMS)
#else
#endif
#ifndef NDEBUG
#endif
#ifndef NDEBUG
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L && \
#endif
