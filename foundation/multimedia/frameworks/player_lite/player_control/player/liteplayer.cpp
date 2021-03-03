#include "liteplayer.h"
#include "hi_liteplayer_err.h"
#include "liteplayer_comm.h"
#include <sys/prctl.h>
#include <sys/time.h>
#include <unistd.h>
#include "decoder.h"
#define CHECK_NULL_RETURN(value, ret, printfString) \
#define CHECK_FAILED_RETURN(value, target, ret, printfString) \
#define CHECK_STATE_SAME(srcState, dstState)                                                                         \
#ifndef __HI3518EV300__
#else
#endif
