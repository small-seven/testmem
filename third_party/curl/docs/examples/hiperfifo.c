#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <sys/poll.h>
#include <curl/curl.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/cdefs.h>
#define MSG_OUT stdout /* Send info to stdout, change to stderr if you want */
typedef struct _GlobalInfo
{
  struct event_base *evbase;
  struct event fifo_event;
  struct event timer_event;
  CURLM *multi;
  int still_running;
  FILE *input;
  int stopped;
} GlobalInfo;
typedef struct _ConnInfo
{
  CURL *easy;
  char *url;
  GlobalInfo *global;
  char error[CURL_ERROR_SIZE];
} ConnInfo;
typedef struct _SockInfo
{
  curl_socket_t sockfd;
  CURL *easy;
  int action;
  long timeout;
  struct event ev;
  GlobalInfo *global;
} SockInfo;
#define mycase(code) \
