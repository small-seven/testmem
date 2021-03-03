#include <asm/arch/platform.h>
#define W_WHETHER_WRITE     (1<<0)
#define W_WHETHER_PM        (1<<1)
#define W_WHETHER_BOOT_NORMAL   (1<<2)
#define W_BIT_OFFSET        3
#define W_BIT_MASK          (0x1f<<W_BIT_OFFSET)
#define W_REG_BIT_OFFSET    11
#define W_REG_BIT_MASK      (0x1f<<W_REG_BIT_OFFSET)
#define R_WHETHER_READ      (W_WHETHER_WRITE<<16)
#define R_WHETHER_PM        (W_WHETHER_PM<<16)
#define R_WHETHER_BOOT_NORMAL   (W_WHETHER_BOOT_NORMAL<<16)
#define R_BIT_OFFSET        (W_BIT_OFFSET + 16)
#define R_BIT_MASK          (W_BIT_MASK<<16)
#define R_REG_BIT_OFFSET    (W_REG_BIT_OFFSET + 16)
#define R_REG_BIT_MASK      (W_REG_BIT_MASK<<16)
#define RW_BIT_NUM	32
