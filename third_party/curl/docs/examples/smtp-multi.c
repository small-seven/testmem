#include <string.h>
#include <curl/curl.h>
#define FROM     "<sender@example.com>"
#define TO       "<recipient@example.com>"
#define CC       "<info@example.com>"
#define MULTI_PERFORM_HANG_TIMEOUT 60 * 1000
#ifdef _WIN32
#else
#endif
