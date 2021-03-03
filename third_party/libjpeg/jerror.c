#ifdef USE_WINDOWS_MESSAGEBOX
#include <windows.h>
#endif
#include "jinclude.h"
#include "jpeglib.h"
#include "jversion.h"
#include "jerror.h"
#ifndef EXIT_FAILURE		/* define exit() codes if not provided */
#define EXIT_FAILURE  1
#endif
#ifdef NEED_SHORT_EXTERNAL_NAMES
#define jpeg_std_message_table	jMsgTable
#endif
#define JMESSAGE(code,string)	string ,
#include "jerror.h"
#ifdef USE_WINDOWS_MESSAGEBOX
#else
#endif
