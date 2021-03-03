#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <curl/curl.h>
#ifdef _WIN32
#define WAITMS(x) Sleep(x)
#else
#define WAITMS(x)                               \
#endif
