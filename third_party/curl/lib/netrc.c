#include "curl_setup.h"
#ifndef CURL_DISABLE_NETRC
#ifdef HAVE_PWD_H
#include <pwd.h>
#endif
#include <curl/curl.h>
#include "netrc.h"
#include "strtok.h"
#include "strcase.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define NETRC_FILE_MISSING 1
#define NETRC_FAILED -1
#define NETRC_SUCCESS 0
#if defined(HAVE_GETPWUID_R) && defined(HAVE_GETEUID)
#elif defined(HAVE_GETPWUID) && defined(HAVE_GETEUID)
#endif
#ifdef WIN32
#endif
#endif
