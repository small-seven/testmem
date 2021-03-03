#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined (WIN32)
#  include <conio.h>  /* _getch() */
#else
#  include <termios.h>
#  include <unistd.h>
#endif
#include <curl/curl.h>
#define VERSION_STR  "V1.0"
#define my_curl_easy_setopt(A, B, C)                             \
#define my_curl_easy_perform(A)                                     \
#if 1
#else
#endif
