#include <common.h>
#include <dm.h>
#include <init.h>
#include <ram.h>
#include <asm/io.h>
#include <asm/arch-rockchip/sdram.h>
#include <dm/uclass-internal.h>
#define TRUST_PARAMETER_OFFSET    (34 * 1024 * 1024)
#ifdef CONFIG_ARM64
#else
#ifdef CONFIG_SPL_OPTEE
#else
#endif
#endif
