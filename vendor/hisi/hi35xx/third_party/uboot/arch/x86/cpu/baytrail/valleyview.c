#include <common.h>
#include <mmc.h>
#include <pci_ids.h>
#include <asm/irq.h>
#include <asm/mrccache.h>
#include <asm/post.h>
#include <asm/arch/iomap.h>
#define GPIO_SUS_PAD_BASE	(IO_BASE_ADDRESS + IO_BASE_OFFSET_GPSSUS)
#define GPIO_SUS_DFX5_CONF0	0x150
#define BYT_TRIG_LVL		BIT(24)
#define BYT_TRIG_POS		BIT(25)
#ifdef CONFIG_ENABLE_MRC_CACHE
#endif
