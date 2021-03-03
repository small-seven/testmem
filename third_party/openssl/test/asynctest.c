#ifdef _WIN32
# include <windows.h>
#endif
#include <stdio.h>
#include <string.h>
#include <openssl/async.h>
#include <openssl/crypto.h>
#define MAGIC_WAIT_FD   ((OSSL_ASYNC_FD)99)
