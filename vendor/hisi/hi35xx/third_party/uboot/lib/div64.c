#include <linux/compat.h>
#include <linux/kernel.h>
#include <linux/math64.h>
#if BITS_PER_LONG == 32
#ifndef __div64_32
#endif
#ifndef div_s64_rem
#endif
#ifndef div64_u64_rem
#endif
#ifndef div64_u64
#endif
#ifndef div64_s64
#endif
#endif /* BITS_PER_LONG == 32 */
