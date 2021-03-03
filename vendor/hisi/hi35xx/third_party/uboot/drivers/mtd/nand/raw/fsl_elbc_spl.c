#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/fsl_lbc.h>
#include <nand.h>
#ifdef CONFIG_MPC83xx
#include "../../../arch/powerpc/cpu/mpc83xx/elbc/elbc.h"
#endif
#define WINDOW_SIZE 8192
#ifdef CONFIG_TPL_BUILD
#else
#endif
#ifndef CONFIG_TPL_BUILD
#define nand_spl_load_image(offs, uboot_size, vdst) \
#endif
#ifdef CONFIG_NAND_ENV_DST
#ifdef CONFIG_ENV_OFFSET_REDUND
#endif
#endif
#ifdef CONFIG_SPL_FLUSH_IMAGE
#endif
