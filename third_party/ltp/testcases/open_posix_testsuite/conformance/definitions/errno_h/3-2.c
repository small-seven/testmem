#include <stdio.h>
#include <string.h>
#include <errno.h>
#define PTP_PASS        0
#define PTP_FAIL        1
#define PTP_UNRESOLVED  2
#define PTP_NOTINUSE    3
#define PTP_UNSUPPORTED 4
#define PTP_UNTESTED    5
#define PTP_UNINITIATED 6
#define PTP_NORESULT    7
#ifdef ENODATA
#endif
#ifdef ENOSR
#endif
#ifdef ENOSTR
#endif
