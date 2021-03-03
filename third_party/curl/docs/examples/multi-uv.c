#include <stdio.h>
#include <stdlib.h>
#include <uv.h>
#include <curl/curl.h>
typedef struct curl_context_s {
  uv_poll_t poll_handle;
  curl_socket_t sockfd;
} curl_context_t;
