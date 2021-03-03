#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <sys/poll.h>
#include <curl/curl.h>
#include <ev.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#define DPRINT(x...) printf(x)
#define MSG_OUT stdout /* Send info to stdout, change to stderr if you want */
typedef struct _GlobalInfo
{
  struct ev_loop *loop;
  struct ev_io fifo_event;
  struct ev_timer timer_event;
  CURLM *multi;
  int still_running;
  FILE *input;
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
  struct ev_io ev;
  int evset;
  GlobalInfo *global;
} SockInfo;
