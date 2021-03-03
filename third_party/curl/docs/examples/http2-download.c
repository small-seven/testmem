#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <curl/curl.h>
#ifndef CURLPIPE_MULTIPLEX
#define CURLPIPE_MULTIPLEX 0
#endif
#define NUM_HANDLES 1000
#if (CURLPIPE_MULTIPLEX > 0)
#endif
#ifdef _WIN32
#else
#endif
