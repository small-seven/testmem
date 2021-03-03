#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/types.h>
#include <asm/arch/powergate.h>
#include <asm/arch/tegra.h>
#include <asm/arch-tegra/pmc.h>
#define PWRGATE_TOGGLE 0x30
#define  PWRGATE_TOGGLE_START (1 << 8)
#define REMOVE_CLAMPING 0x34
#define PWRGATE_STATUS 0x38
