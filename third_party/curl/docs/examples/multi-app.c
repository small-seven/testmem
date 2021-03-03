#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <curl/curl.h>
#define HANDLECOUNT 2   /* Number of simultaneous transfers */
#define HTTP_HANDLE 0   /* Index for the HTTP transfer */
#define FTP_HANDLE 1    /* Index for the FTP transfer */
#ifdef _WIN32
#else
#endif
