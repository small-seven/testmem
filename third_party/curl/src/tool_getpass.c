#include "tool_setup.h"
#if defined(__AMIGA__) && !defined(__amigaos4__)
#  undef HAVE_TERMIOS_H
#endif
#ifndef HAVE_GETPASS_R
#ifdef HAVE_FCNTL_H
#  include <fcntl.h>
#endif
#ifdef HAVE_TERMIOS_H
#  include <termios.h>
#elif defined(HAVE_TERMIO_H)
#  include <termio.h>
#endif
#ifdef __VMS
#  include descrip
#  include starlet
#  include iodef
#endif
#ifdef WIN32
#  include <conio.h>
#endif
#ifdef NETWARE
#  ifdef __NOVELL_LIBC__
#    include <screen.h>
#  else
#    include <nwconio.h>
#  endif
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include "tool_getpass.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef __VMS
#define DONE
#endif /* __VMS */
#ifdef __SYMBIAN32__
#  define getch() getchar()
#endif
#if defined(WIN32) || defined(__SYMBIAN32__)
#ifndef __SYMBIAN32__
#endif
#define DONE
#endif /* WIN32 || __SYMBIAN32__ */
#ifdef NETWARE
#ifdef __NOVELL_LIBC__
#else
#endif /* __NOVELL_LIBC__ */
#define DONE
#endif /* NETWARE */
#ifndef DONE /* not previously provided */
#ifdef HAVE_TERMIOS_H
#  define struct_term  struct termios
#elif defined(HAVE_TERMIO_H)
#  define struct_term  struct termio
#else
#  undef  struct_term
#endif
#ifdef struct_term
#endif
#ifdef HAVE_TERMIOS_H
#elif defined(HAVE_TERMIO_H)
#else
#endif
#ifdef HAVE_TERMIOS_H
#elif defined(HAVE_TERMIO_H)
#else
#endif
#endif /* DONE */
#endif /* HAVE_GETPASS_R */
