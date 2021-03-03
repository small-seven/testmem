#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <curl/curl.h>
#ifdef WIN32
#  include <io.h>
#  define READ_3RD_ARG unsigned int
#else
#  include <unistd.h>
#  define READ_3RD_ARG size_t
#endif
#if LIBCURL_VERSION_NUM < 0x070c03
#error "upgrade your libcurl to no less than 7.12.3"
#endif
