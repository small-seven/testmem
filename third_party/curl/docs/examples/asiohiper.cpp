#include <curl/curl.h>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#define MSG_OUT stdout /* Send info to stdout, change to stderr if you want */
typedef struct _GlobalInfo
{
  CURLM *multi;
  int still_running;
} GlobalInfo;
typedef struct _ConnInfo
{
  CURL *easy;
  char *url;
  GlobalInfo *global;
  char error[CURL_ERROR_SIZE];
} ConnInfo;
