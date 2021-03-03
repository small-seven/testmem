#include <sys/socket.h>   /* struct sockaddr_storage, setsockopt() */
#include <netinet/in.h>
#include <netinet/sctp.h> /* SCTP_SOCKOPT_CONNECTX_* */
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define __SYMPFX(pfx, sym) #pfx sym
#define _SYMPFX(pfx, sym) __SYMPFX(pfx, sym)
#define SYMPFX(sym) _SYMPFX(__USER_LABEL_PREFIX__, #sym)
#define SYMVER(name, name2) __asm__(".symver " SYMPFX(name) "," SYMPFX(name2))
