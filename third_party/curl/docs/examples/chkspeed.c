#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>
#define URL_BASE "http://speedtest.your.domain/"
#define URL_1M   URL_BASE "file_1M.bin"
#define URL_2M   URL_BASE "file_2M.bin"
#define URL_5M   URL_BASE "file_5M.bin"
#define URL_10M  URL_BASE "file_10M.bin"
#define URL_20M  URL_BASE "file_20M.bin"
#define URL_50M  URL_BASE "file_50M.bin"
#define URL_100M URL_BASE "file_100M.bin"
#define CHKSPEED_VERSION "1.0"
