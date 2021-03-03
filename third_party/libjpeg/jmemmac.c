#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "jmemsys.h"    /* import the system-dependent declarations */
#ifndef USE_MAC_MEMMGR	/* make sure user got configuration right */
#endif
#include <Memory.h>     /* we use the MacOS memory manager */
#include <Files.h>      /* we use the MacOS File stuff */
#include <Folders.h>    /* we use the MacOS HFS stuff */
#include <Script.h>     /* for smSystemScript */
#include <Gestalt.h>    /* we use Gestalt to test for specific functionality */
#ifndef TEMP_FILE_NAME		/* can override from jconfig.h or Makefile */
#define TEMP_FILE_NAME  "JPG%03d.TMP"
#endif
