#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#ifdef WIN32
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#define close closesocket
#else
#include <sys/types.h>        /*  socket types              */
#include <sys/socket.h>       /*  socket definitions        */
#include <netinet/in.h>
#include <arpa/inet.h>        /*  inet (3) functions         */
#include <unistd.h>           /*  misc. Unix functions      */
#endif
#include <errno.h>
#define IPADDR "127.0.0.1"
#define PORTNUM 80
#ifndef INADDR_NONE
#define INADDR_NONE 0xffffffff
#endif
#ifdef WIN32
#endif
#ifdef WIN32
#endif
