#include "curl_setup.h"
#ifndef CURL_DISABLE_FILE
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
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#include "strtoofft.h"
#include "urldata.h"
#include <curl/curl.h>
#include "progress.h"
#include "sendf.h"
#include "escape.h"
#include "file.h"
#include "speedcheck.h"
#include "getinfo.h"
#include "transfer.h"
#include "url.h"
#include "parsedate.h" /* for the week day and month names */
#include "warnless.h"
#include "curl_range.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(WIN32) || defined(MSDOS) || defined(__EMX__) || \
#define DOS_FILESYSTEM 1
#endif
#ifdef OPEN_NEEDS_ARG3
#  define open_readonly(p,f) open((p),(f),(0))
#else
#  define open_readonly(p,f) open((p),(f))
#endif
#ifdef DOS_FILESYSTEM
#endif
#ifdef DOS_FILESYSTEM
#else
#endif
#ifdef DOS_FILESYSTEM
#define DIRSEP '\\'
#else
#define DIRSEP '/'
#endif
#ifdef O_BINARY
#define MODE_DEFAULT O_WRONLY|O_CREAT|O_BINARY
#else
#define MODE_DEFAULT O_WRONLY|O_CREAT
#endif
#endif
