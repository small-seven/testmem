#include <common.h>
#include <linux/stat.h>
#if ( S_ISUID != 04000 ) || ( S_ISGID != 02000 ) || ( S_ISVTX != 01000 ) \
#error permission bitflag value assumption(s) violated!
#endif
#if ( S_IFSOCK!= 0140000 ) || ( S_IFLNK != 0120000 ) \
#warning mode type bitflag value assumption(s) violated! falling back to larger version
#if (S_IRWXU | S_IRWXG | S_IRWXO | S_ISUID | S_ISGID | S_ISVTX) == 07777
#undef mode_t
#define mode_t unsigned short
#endif
#else
#endif
