#ifdef __VMS
# define OPENSSL_SYS_VMS
# pragma message disable DOLLARID
# include <openssl/opensslconf.h>
# if !defined(_POSIX_C_SOURCE) && defined(OPENSSL_SYS_VMS)
#  define _POSIX_C_SOURCE 2
# endif
# include <stdio.h>
# undef _POSIX_C_SOURCE
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <inet.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <starlet.h>
# include <iodef.h>
# ifdef __alpha
#  include <iosbdef.h>
# else
typedef struct _iosb {           /* Copied from IOSBDEF.H for Alpha  */
#  pragma __nomember_alignment
    __union  {
        __struct  {
            unsigned short int iosb$w_status; /* Final I/O status           */
            __union  {
                __struct  {             /* 16-bit byte count variant        */
                    unsigned short int iosb$w_bcnt; /* 16-bit byte count    */
                    __union  {
                        unsigned int iosb$l_dev_depend; /* 32-bit device dependent info */
                        unsigned int iosb$l_pid; /* 32-bit pid              */
                    } iosb$r_l;
#  if !defined(__VAXC)
#   define iosb$w_status iosb$r_io_get.iosb$r_io_64.iosb$w_status
#   define iosb$w_bcnt iosb$r_io_get.iosb$r_io_64.iosb$r_devdepend.iosb$r_bcnt_16.iosb$w_bcnt
#   define iosb$r_l        iosb$r_io_get.iosb$r_io_64.iosb$r_devdepend.iosb$r_bcnt_16.iosb$r_l
#   define iosb$l_dev_depend iosb$r_l.iosb$l_dev_depend
#   define iosb$l_pid iosb$r_l.iosb$l_pid
#   define iosb$l_bcnt iosb$r_io_get.iosb$r_io_64.iosb$r_devdepend.iosb$r_bcnt_32.iosb$l_bcnt
#   define iosb$w_dev_depend_high iosb$r_io_get.iosb$r_io_64.iosb$r_devdepend.iosb$r_bcnt_32.iosb$w_dev_depend_high
#   define iosb$l_getxxi_status iosb$r_io_get.iosb$r_get_64.iosb$r_l_status.iosb$l_getxxi_status
#   define iosb$l_reg_status iosb$r_io_get.iosb$r_get_64.iosb$r_l_status.iosb$l_reg_status
#  endif          /* #if !defined(__VAXC) */
# endif  /* End of IOSBDEF */
# include <efndef.h>
# include <stdlib.h>
# include <ssdef.h>
# include <time.h>
# include <stdarg.h>
# include <descrip.h>
# include "vms_term_sock.h"
# ifdef __alpha
# else
# endif
# define SOCKET_PAIR_TIMEOUT_VALUE 20
typedef struct _SocketPairTimeoutBlock {
    unsigned short SockChan1;
    unsigned short SockChan2;
} SPTB;
# ifdef TERM_SOCK_TEST
# endif
# ifdef __alpha
# else
# endif
#endif
