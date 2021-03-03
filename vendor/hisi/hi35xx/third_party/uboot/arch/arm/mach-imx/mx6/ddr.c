#include <common.h>
#include <linux/types.h>
#include <asm/arch/clock.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#include <asm/types.h>
#include <wait_bit.h>
#if defined(CONFIG_MX6_DDRCAL)
#endif
#if defined(CONFIG_MX6SX)
#endif
#if defined(CONFIG_MX6UL) || defined(CONFIG_MX6ULL)
#endif
#if defined(CONFIG_MX6SL)
#endif
#if defined(CONFIG_MX6QDL) || defined(CONFIG_MX6Q) || defined(CONFIG_MX6D)
#endif
#if defined(CONFIG_MX6QDL) || defined(CONFIG_MX6DL) || defined(CONFIG_MX6S)
#endif
#define MR(val, ba, cmd, cs1) \
#define MMDC1(entry, value) do {					  \
