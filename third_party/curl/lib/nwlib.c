#include "curl_setup.h"
#ifdef NETWARE /* Novell NetWare */
#ifdef __NOVELL_LIBC__
#include <library.h>
#include <netware.h>
#include <screen.h>
#include <nks/thread.h>
#include <nks/synch.h>
#include "curl_memory.h"
#include "memdebug.h"
typedef struct
{
  int     _errno;
  void    *twentybytes;
} libthreaddata_t;
typedef struct
{
  int         x;
  int         y;
  int         z;
  void        *tenbytes;
  NXKey_t     perthreadkey;   /* if -1, no key obtained... */
  NXMutex_t   *lock;
} libdata_t;
#ifndef __GNUC__
#pragma unused(cmdLine)
#pragma unused(loadDirPath)
#pragma unused(uninitializedDataLength)
#pragma unused(NLMFileHandle)
#pragma unused(readRoutineP)
#pragma unused(customDataOffset)
#pragma unused(customDataSize)
#pragma unused(messageCount)
#pragma unused(messages)
#endif
#else /* __NOVELL_LIBC__ */
#include <nwthread.h>
#endif /* __NOVELL_LIBC__ */
#else /* NETWARE */
#ifdef __POCC__
#  pragma warn(disable:2024)  /* Disable warning #2024: Empty input file */
#endif
#endif /* NETWARE */
