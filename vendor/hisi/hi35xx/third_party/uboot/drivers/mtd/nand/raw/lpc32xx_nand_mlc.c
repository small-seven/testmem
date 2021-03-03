#include <common.h>
#include <nand.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <nand.h>
#include <asm/arch/clk.h>
#include <asm/arch/sys_proto.h>
#define LOCK_PR_UNLOCK_KEY 0x0000A25E  /* Magic unlock value */
#define ICR_LARGE_BLOCKS 0x00000004	/* configure for 2KB blocks */
#define ICR_ADDR4        0x00000002	/* configure for 4-word addrs */
#define CEH_NORMAL_CE  0x00000001	/* do not force CE ON */
#define ISR_NAND_READY        0x00000001
#define ISR_CONTROLLER_READY  0x00000002
#define ISR_ECC_READY         0x00000004
#define ISR_DECODER_ERRORS(s) ((((s) >> 4) & 3)+1)
#define ISR_DECODER_FAILURE   0x00000040
#define ISR_DECODER_ERROR     0x00000008
#define LPC32X_NAND_TIMEOUT 5000
#if !defined(CONFIG_SYS_MAX_NAND_CHIPS)
#define CONFIG_SYS_MAX_NAND_CHIPS	1
#endif
#define clkdiv(v, w, o) (((1+(clk/v)) & w) << o)
#if !defined(CONFIG_SPL_BUILD)
#else /* defined(CONFIG_SPL_BUILD) */
#define BYTES_PER_PAGE 2048
#define PAGES_PER_BLOCK 64
#define BYTES_PER_BLOCK (BYTES_PER_PAGE * PAGES_PER_BLOCK)
#define PAGES_PER_CHIP_MAX 524288
#endif /* CONFIG_SPL_BUILD */
