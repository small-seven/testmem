#include "e_os.h"
#include <openssl/e_os2.h>
#include <openssl/err.h>
#include <openssl/ui.h>
#ifndef OPENSSL_NO_UI_CONSOLE
# if defined(OPENSSL_SYS_VXWORKS)
#  include <sys/types.h>
# endif
# if !defined(_POSIX_C_SOURCE) && defined(OPENSSL_SYS_VMS)
#  ifndef _POSIX_C_SOURCE
#   define _POSIX_C_SOURCE 2
#  endif
# endif
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# if !defined(OPENSSL_SYS_MSDOS) && !defined(OPENSSL_SYS_VMS)
#  ifdef OPENSSL_UNISTD
#   include OPENSSL_UNISTD
#  else
#   include <unistd.h>
#  endif
#  if defined(_POSIX_VERSION) && _POSIX_VERSION>=199309L
#   define SIGACTION
#   if !defined(TERMIOS) && !defined(TERMIO) && !defined(SGTTY)
#    define TERMIOS
#   endif
#  endif
# endif
# include "ui_local.h"
# include "internal/cryptlib.h"
# ifdef OPENSSL_SYS_VMS          /* prototypes for sys$whatever */
#  include <starlet.h>
#  ifdef __DECC
#   pragma message disable DOLLARID
#  endif
# endif
# ifdef WIN_CONSOLE_BUG
#  include <windows.h>
#  ifndef OPENSSL_SYS_WINCE
#   include <wincon.h>
#  endif
# endif
# if !defined(TERMIOS) && !defined(TERMIO) && !defined(SGTTY)
#  if defined(_LIBC)
#   undef  TERMIOS
#   define TERMIO
#   undef  SGTTY
#  elif !defined(OPENSSL_SYS_VMS) \
#   define TERMIOS
#   undef  TERMIO
#   undef  SGTTY
#  endif
# endif
# if defined(OPENSSL_SYS_VXWORKS)
#  undef TERMIOS
#  undef TERMIO
#  undef SGTTY
# endif
# ifdef TERMIOS
#  include <termios.h>
#  define TTY_STRUCT             struct termios
#  define TTY_FLAGS              c_lflag
#  define TTY_get(tty,data)      tcgetattr(tty,data)
#  define TTY_set(tty,data)      tcsetattr(tty,TCSANOW,data)
# endif
# ifdef TERMIO
#  include <termio.h>
#  define TTY_STRUCT             struct termio
#  define TTY_FLAGS              c_lflag
#  define TTY_get(tty,data)      ioctl(tty,TCGETA,data)
#  define TTY_set(tty,data)      ioctl(tty,TCSETA,data)
# endif
# ifdef SGTTY
#  include <sgtty.h>
#  define TTY_STRUCT             struct sgttyb
#  define TTY_FLAGS              sg_flags
#  define TTY_get(tty,data)      ioctl(tty,TIOCGETP,data)
#  define TTY_set(tty,data)      ioctl(tty,TIOCSETP,data)
# endif
# if !defined(_LIBC) && !defined(OPENSSL_SYS_MSDOS) && !defined(OPENSSL_SYS_VMS)
#  include <sys/ioctl.h>
# endif
# ifdef OPENSSL_SYS_MSDOS
#  include <conio.h>
# endif
# ifdef OPENSSL_SYS_VMS
#  include <ssdef.h>
#  include <iodef.h>
#  include <ttdef.h>
#  include <descrip.h>
# endif
# ifndef NX509_SIG
#  define NX509_SIG 32
# endif
# ifdef SIGACTION
# else
# endif
# ifdef OPENSSL_SYS_VMS
# elif defined(_WIN32) && !defined(_WIN32_WCE)
# else
#  if !defined(OPENSSL_SYS_MSDOS) || defined(__DJGPP__)
#  endif
# endif
# if !defined(OPENSSL_SYS_WINCE)
# endif
# if defined(OPENSSL_SYS_MSDOS) && !defined(_WIN32)
# endif
# if !defined(OPENSSL_SYS_WINCE)
#  define SIZE 4
# endif
# if !defined(OPENSSL_SYS_WINCE)
#  if defined(_WIN32)
#   if defined(CP_UTF8)
#   endif
#  elif defined(OPENSSL_SYS_MSDOS)
#  endif
# else
# endif
# if defined(OPENSSL_SYS_VXWORKS)
# elif defined(_WIN32) && !defined(_WIN32_WCE)
# else
#  ifdef OPENSSL_SYS_MSDOS
#   define DEV_TTY "con"
#  else
#   define DEV_TTY "/dev/tty"
#  endif
# endif
# if defined(TTY_get) && !defined(OPENSSL_SYS_VMS)
#  ifdef ENOTTY
#  endif
#  ifdef EINVAL
#  endif
#  ifdef ENXIO
#  endif
#  ifdef EIO
#  endif
#  ifdef ENODEV
#  endif
# endif
# ifdef OPENSSL_SYS_VMS
# endif
# ifdef TTY_FLAGS
# endif
# if defined(TTY_set) && !defined(OPENSSL_SYS_VMS)
# endif
# ifdef OPENSSL_SYS_VMS
# endif
# if defined(_WIN32) && !defined(_WIN32_WCE)
# endif
# if defined(TTY_set) && !defined(OPENSSL_SYS_VMS)
# endif
# ifdef OPENSSL_SYS_VMS
# endif
# if defined(_WIN32) && !defined(_WIN32_WCE)
# endif
# ifdef OPENSSL_SYS_VMS
# endif
# if !defined(OPENSSL_SYS_WINCE)
#  ifndef OPENSSL_SYS_WIN32
#  endif
#  ifdef SIGACTION
#  endif
#  ifdef OPENSSL_SYS_WIN32
#  else
#   ifdef SIGUSR1
#   endif
#   ifdef SIGUSR2
#   endif
#   ifdef SIGKILL
#   endif
#   ifdef SIGACTION
#   else
#   endif
#  endif
#  ifdef SIGWINCH
#  endif
#  ifdef OPENSSL_SYS_WIN32
#  else
#   ifdef SIGUSR1
#   endif
#   ifdef SIGUSR2
#   endif
#   ifdef SIGACTION
#   else
#   endif
#  endif
# endif
# if defined(OPENSSL_SYS_MSDOS) && !defined(_WIN32)
#  if defined(_WIN32)
#  else
#  endif
#  ifdef WIN_CONSOLE_BUG
#  endif
# endif
#else
#endif
