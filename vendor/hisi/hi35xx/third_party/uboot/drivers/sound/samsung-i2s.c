#include <common.h>
#include <dm.h>
#include <i2s.h>
#include <sound.h>
#include <asm/arch/clk.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/i2s-regs.h>
#include <asm/io.h>
#define FIC_TX2COUNT(x)		(((x) >>  24) & 0xf)
#define FIC_TX1COUNT(x)		(((x) >>  16) & 0xf)
#define FIC_TXCOUNT(x)		(((x) >>  8) & 0xf)
#define FIC_RXCOUNT(x)		(((x) >>  0) & 0xf)
#define FICS_TXCOUNT(x)		(((x) >>  8) & 0x7f)
#define TIMEOUT_I2S_TX		100	/* i2s transfer timeout */
