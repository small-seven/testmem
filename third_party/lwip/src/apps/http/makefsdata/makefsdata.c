#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "tinydir.h"
#ifndef MAKEFS_SUPPORT_DEFLATE
#define MAKEFS_SUPPORT_DEFLATE 0
#endif
#define COPY_BUFSIZE (1024*1024) /* 1 MByte */
#if MAKEFS_SUPPORT_DEFLATE
#include "../miniz.c"
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint;

#define my_max(a,b) (((a) > (b)) ? (a) : (b))
#define my_min(a,b) (((a) < (b)) ? (a) : (b))

/* COMP_OUT_BUF_SIZE is the size of the output buffer used during compression.
   COMP_OUT_BUF_SIZE must be >= 1 and <= OUT_BUF_SIZE */
#define COMP_OUT_BUF_SIZE COPY_BUFSIZE

/* OUT_BUF_SIZE is the size of the output buffer used during decompression.
   OUT_BUF_SIZE must be a power of 2 >= TINFL_LZ_DICT_SIZE (because the low-level decompressor not only writes, but reads from the output buffer as it decompresses) */
#define OUT_BUF_SIZE COPY_BUFSIZE
static uint8 s_outbuf[OUT_BUF_SIZE];
static uint8 s_checkbuf[OUT_BUF_SIZE];

/* tdefl_compressor contains all the state needed by the low-level compressor so it's a pretty big struct (~300k).
   This example makes it a global vs. putting it on the stack, of course in real-world usage you'll probably malloc() or new it. */
tdefl_compressor g_deflator;
tinfl_decompressor g_inflator;

int deflate_level = 10; /* default compression level, can be changed via command line */
#define USAGE_ARG_DEFLATE " [-defl<:compr_level>]"
#else /* MAKEFS_SUPPORT_DEFLATE */
#define USAGE_ARG_DEFLATE ""
#endif /* MAKEFS_SUPPORT_DEFLATE */

#ifdef WIN32

#define GETCWD(path, len)             GetCurrentDirectoryA(len, path)
#define CHDIR(path)                   SetCurrentDirectoryA(path)
#define CHDIR_SUCCEEDED(ret)          (ret == TRUE)

#elif __linux__

#define GETCWD(path, len)             getcwd(path, len)
#define CHDIR(path)                   chdir(path)
#define CHDIR_SUCCEEDED(ret)          (ret == 0)

#else

#error makefsdata not supported on this platform

#endif

#define NEWLINE     "\r\n"
#define NEWLINE_LEN 2

/* define this to get the header variables we use to build HTTP headers */
#define LWIP_HTTPD_DYNAMIC_HEADERS 1
#define LWIP_HTTPD_SSI             1
#include "lwip/init.h"
#include "../httpd_structs.h"
#include "lwip/apps/fs.h"

#include "../core/inet_chksum.c"
#include "../core/def.c"

/** (Your server name here) */
const char *serverID = "Server: "HTTPD_SERVER_AGENT"\r\n";
char serverIDBuffer[1024];

/* change this to suit your MEM_ALIGNMENT */
#define PAYLOAD_ALIGNMENT 4
/* set this to 0 to prevent aligning payload */
#define ALIGN_PAYLOAD 1
/* define this to a type that has the required alignment */
#define PAYLOAD_ALIGN_TYPE "unsigned int"
static int payload_alingment_dummy_counter = 0;

#define HEX_BYTES_PER_LINE 16

#define MAX_PATH_LEN 256

struct file_entry {
  struct file_entry *next;
  const char *filename_c;
};
#if MAKEFS_SUPPORT_DEFLATE
#endif
#if MAKEFS_SUPPORT_DEFLATE
#endif
#if MAKEFS_SUPPORT_DEFLATE
#else
#endif
#if ALIGN_PAYLOAD
#endif
#if ALIGN_PAYLOAD
#endif
#if MAKEFS_SUPPORT_DEFLATE
#endif
#if (defined _MSC_VER || defined __MINGW32__) && (defined _UNICODE)
#else
#endif
#if (defined _MSC_VER || defined __MINGW32__) && (defined _UNICODE)
#else
#endif
#if MAKEFS_SUPPORT_DEFLATE
#else
#endif
#if LWIP_TCP_TIMESTAMPS
#endif
#if ALIGN_PAYLOAD
#endif /* ALIGN_PAYLOAD */
#if ALIGN_PAYLOAD
#endif /* ALIGN_PAYLOAD */
#if MAKEFS_SUPPORT_DEFLATE
#else
#endif
