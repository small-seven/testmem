#include <glib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <curl/curl.h>
#define MSG_OUT g_print   /* Change to "g_error" to write to stderr */
#define SHOW_VERBOSE 0    /* Set to non-zero for libcurl messages */
#define SHOW_PROGRESS 0   /* Set to non-zero to enable progress callback */
typedef struct _GlobalInfo {
  CURLM *multi;
  guint timer_event;
  int still_running;
} GlobalInfo;
typedef struct _ConnInfo {
  CURL *easy;
  char *url;
  GlobalInfo *global;
  char error[CURL_ERROR_SIZE];
} ConnInfo;
typedef struct _SockInfo {
  curl_socket_t sockfd;
  CURL *easy;
  int action;
  long timeout;
  GIOChannel *ch;
  guint ev;
  GlobalInfo *global;
} SockInfo;
#define BUF_SIZE 1024
