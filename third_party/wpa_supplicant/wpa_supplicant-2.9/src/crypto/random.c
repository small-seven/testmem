#include "utils/includes.h"
#ifdef __linux__
#include <fcntl.h>
#ifdef CONFIG_GETRANDOM
#include <sys/random.h>
#endif /* CONFIG_GETRANDOM */
#endif /* __linux__ */
#include <stdlib.h>
#include "utils/common.h"
#include "utils/eloop.h"
#include "crypto/crypto.h"
#include "sha1.h"
#include "random.h"
#define POOL_WORDS 32
#define POOL_WORDS_MASK (POOL_WORDS - 1)
#define POOL_TAP1 26
#define POOL_TAP2 20
#define POOL_TAP3 14
#define POOL_TAP4 7
#define POOL_TAP5 1
#define EXTRACT_LEN 16
#define MIN_READY_MARK 2
#ifdef __linux__
#endif /* __linux__ */
#define RANDOM_ENTROPY_SIZE 20
#define MIN_COLLECT_ENTROPY 1000
#ifdef CONFIG_TEST_RANDOM
#else /* CONFIG_TEST_RANDOM */
#ifdef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#endif /* CONFIG_TEST_RANDOM */
#ifdef CONFIG_TEST_RANDOM
#else /* CONFIG_TEST_RANDOM */
#ifdef __linux__
#ifdef CONFIG_GETRANDOM
#else /* CONFIG_GETRANDOM */
#endif /* CONFIG_GETRANDOM */
#else /* __linux__ */
#endif /* __linux__ */
#endif /* CONFIG_TEST_RANDOM */
#ifdef __linux__
#endif /* __linux__ */
#ifdef __linux__
#ifdef CONFIG_GETRANDOM
#endif /* CONFIG_GETRANDOM */
#endif /* __linux__ */
#ifdef __linux__
#endif /* __linux__ */
