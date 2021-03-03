#include <common.h>
#include <malloc.h>
#include <linux/libfdt.h>
#include <tee/optee.h>
#define optee_hdr_err_msg \
#if defined(CONFIG_OF_LIBFDT)
#endif
