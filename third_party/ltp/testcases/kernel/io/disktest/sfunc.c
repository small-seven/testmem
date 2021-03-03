#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#ifdef WINDOWS
#include <winsock2.h>
#include <process.h>
#include <windows.h>
#include <winbase.h>
#include <winioctl.h>
#else
#ifdef AIX
#include <sys/ioctl.h>
#include <sys/devinfo.h>
#endif
#include <unistd.h>
#include <ctype.h>
#endif
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#ifdef LINUX
#include <endian.h>
#endif
#include "main.h"
#include "sfunc.h"
#include "defs.h"
#include "globals.h"
#include "io.h"
#include "threading.h"
#define FORMAT "| %s | %s | %d | %s | %s | %s"
#define TIME_FORMAT "%04d/%02d/%02d-%02d:%02d:%02d"
#define TIME_FMT_LEN 20
#ifndef WINDOWS
#endif
#ifndef WINDOWS
#endif
#ifndef WINDOWS
#endif
#ifdef WINDOWS
#endif
#ifdef AIX
#endif
#ifdef LINUX
#if __BYTE_ORDER == __LITTLE_ENDIAN
#else
#endif
#endif
#ifdef WINDOWS
#endif
#ifdef AIX
#endif
#ifdef LINUX
#if __BYTE_ORDER == __LITTLE_ENDIAN
#else
#endif
#endif
#ifdef WINDOWS
#endif
#ifdef AIX
#endif
#ifdef LINUX
#if __BYTE_ORDER == __LITTLE_ENDIAN
#else
#endif
#endif
#ifndef WINDOWS
#endif
#ifdef WINDOWS
#else
#endif
#ifdef PPC
#else
#endif
#ifdef WINDOWS
#else
#if AIX
#endif
#if AIX
#else
#endif
#endif
#ifdef PPC
#else
#endif
#ifndef WINDOWS
#endif
