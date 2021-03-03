#include <stdlib.h>
#include "zlib.h"
#include "ioapi.h"
#include "iowin32.h"
#ifndef INVALID_HANDLE_VALUE
#define INVALID_HANDLE_VALUE (0xFFFFFFFF)
#endif
#ifndef INVALID_SET_FILE_POINTER
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#endif
#if defined(WINAPI_FAMILY_PARTITION) && (!(defined(IOWIN32_USING_WINRT_API)))
#if WINAPI_FAMILY_ONE_PARTITION(WINAPI_FAMILY, WINAPI_PARTITION_APP)
#define IOWIN32_USING_WINRT_API 1
#endif
#endif
typedef struct
{
    HANDLE hf;
    int error;
} WIN32FILE_IOWIN;
#ifdef IOWIN32_USING_WINRT_API
#ifdef UNICODE
#else
#endif
#else
#endif
#ifdef IOWIN32_USING_WINRT_API
#else
#endif
#ifdef IOWIN32_USING_WINRT_API
#else
#endif
#ifdef IOWIN32_USING_WINRT_API
#ifdef UNICODE
#else
#endif
#else
#endif
#ifdef IOWIN32_USING_WINRT_API
#else
#endif
