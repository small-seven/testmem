#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/timerfd.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <curl/curl.h>
#define MSG_OUT stdout /* Send info to stdout, change to stderr if you want */
typedef struct _GlobalInfo
{
  int epfd;    /* epoll filedescriptor */
  int tfd;     /* timer filedescriptor */
  int fifofd;  /* fifo filedescriptor */
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
  GlobalInfo *global;
} SockInfo;
#define mycase(code) \
