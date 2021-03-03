#include <config.h>
#include <linux/types.h>
#include <api_public.h>
#include <asm/u-boot.h>
#include <asm/global_data.h>
#include "api_private.h"
#if defined(CONFIG_MPC8xx) || defined(CONFIG_E500) || defined(CONFIG_MPC86xx)
#define bi_bar	bi_immr_base
#elif defined(CONFIG_MPC83xx)
#define bi_bar	bi_immrbar
#endif
#if defined(bi_bar)
#undef bi_bar
#else
#endif
