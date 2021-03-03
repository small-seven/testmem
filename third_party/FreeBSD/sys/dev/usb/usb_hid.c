#include "implementation/global_implementation.h"
#include "input/usb_rdesc.h"
#ifndef nitems
#define nitems(_a)	(sizeof((_a)) / sizeof((_a)[0]))
#endif
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR usb_debug
#define	MAXUSAGE 64
#define	MAXPUSH 4
#define	MAXID 16
#define	MAXLOCCNT 1024
