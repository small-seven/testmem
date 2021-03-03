#include <stdio.h>
#include <time.h>
#ifndef __CYGWIN__
#include <winsock2.h>
#include <windows.h>
#endif
#include <curl/curl.h>
#define MAX_STRING              256
#define MAX_STRING1             MAX_STRING + 1
#define SYNCTIME_UA "synctime/1.0"
typedef struct
{
  char http_proxy[MAX_STRING1];
  char proxy_user[MAX_STRING1];
  char timeserver[MAX_STRING1];
} conf_t;
#define HTTP_COMMAND_HEAD       0
#define HTTP_COMMAND_GET        1
#ifdef SYNCTIME_UA
#endif
