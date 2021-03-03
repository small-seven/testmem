#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <curl/curl.h>
#ifndef CURLPIPE_MULTIPLEX
#error "too old libcurl, can't do HTTP/2 server push!"
#endif
#define OUTPUTFILE "dl"
#if (CURLPIPE_MULTIPLEX > 0)
#endif
#ifdef _WIN32
#else
#endif
