#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <memalign.h>
#include <sdhci.h>
#include <time.h>
#include <asm/arch/msg.h>
#include <asm/arch/mbox.h>
#include <mach/sdhci.h>
#include <mach/timer.h>
#define MIN_FREQ 400000
#define SDHCI_BUFFER 0x20
