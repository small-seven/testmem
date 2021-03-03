#include <common.h>
#include <time.h>
#include <asm/global_data.h>
#include <linux/stringify.h>
#if XCHAL_HAVE_CCOUNT
#else
#define get_ccount() fake_ccount
#endif
#if XCHAL_HAVE_CCOUNT
#else
#warning "Without Xtensa timer option, timing will not be accurate."
#endif
#if XCHAL_HAVE_CCOUNT
#else
#endif
#if XCHAL_HAVE_CCOUNT
#endif
