#include <openssl/crypto.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <string.h>
#include "internal/nelem.h"
#include "testutil.h"
#define TEST_SIZE       128
#define BIG_TEST_SIZE 10240
#if BIG_TEST_SIZE < TEST_SIZE
#error BIG_TEST_SIZE is smaller than TEST_SIZE
#endif
#define MAX_VECTOR_SIZE 64
