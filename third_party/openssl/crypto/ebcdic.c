# include <openssl/e_os2.h>
#ifndef CHARSET_EBCDIC
#else
# include <openssl/ebcdic.h>
# ifdef CHARSET_EBCDIC_TEST
# elif defined(_OSD_POSIX)
# else /*_OSD_POSIX*/
# endif/*_OSD_POSIX*/
#endif
