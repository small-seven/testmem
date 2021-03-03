#include <signal.h>
#include <errno.h>
#include <string.h>
#include "stdbool.h"
#include "syscall.h"
#include "pthread_impl.h"
#include "libc.h"
#include "lock.h"
#include "ksigaction.h"
#define DEFAULT_SIG_NUM 64
#define SIGNO2SET(s)            ((sigset_t)1 << (s))
#define NULL_SIGNAL_SET         ((sigset_t)0x00000000)
#define SET_BIT(bitmap, pos)    (bitmap |= (1u << pos))
#define CLEAR_BIT(bitmap, pos)  (bitmap &= ~(1u << pos))
#define CHECK_BIT(bitmap, pos)  ((bitmap & (1u << pos)) ? 1 : 0)
#define SIG_FLAG_NOIGNORE 1
typedef struct sigactq sigactq_t;




typedef void (*sa_sighandler_t)(int);
typedef struct sigaction sigaction_t;

static sigactq_t g_sig_arr[DEFAULT_SIG_NUM];
static pthread_spinlock_t sig_lite_lock;

struct sig_default_act {
	unsigned char singNo;
	unsigned char flag;
	sa_sighandler_t action;
};
