#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <openssl/opensslconf.h>
#include "fuzzer.h"
#ifndef OPENSSL_NO_FUZZ_LIBFUZZER
#elif !defined(OPENSSL_NO_FUZZ_AFL)
#define BUF_SIZE 65536
#else
#error "Unsupported fuzzer"
#endif
