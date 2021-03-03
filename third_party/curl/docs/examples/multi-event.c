#include <stdio.h>
#include <stdlib.h>
#include <event2/event.h>
#include <curl/curl.h>
typedef struct curl_context_s {
  struct event *event;
  curl_socket_t sockfd;
} curl_context_t;
