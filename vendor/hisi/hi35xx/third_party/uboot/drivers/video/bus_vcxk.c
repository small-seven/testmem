#include <common.h>
#include <bmp_layout.h>
#include <asm/io.h>
#ifdef CONFIG_AT91RM9200
#define VCXK_INIT_PIN(PORT, PIN, DDR, I0O1) \
#define VCXK_SET_PIN(PORT, PIN)	writel(PIN, &pio->PORT.sodr);
#define VCXK_CLR_PIN(PORT, PIN)	writel(PIN, &pio->PORT.codr);
#define VCXK_ACKNOWLEDGE	\
#elif defined(CONFIG_MCF52x2)
#else
#endif
#define VCXK_DISABLE\
#define VCXK_ENABLE\
#ifndef CONFIG_SYS_VCXK_DOUBLEBUFFERED
#else
#endif
#define VC4K16_Bright1	vcxk_bws_word[0x20004 / 2]
#define VC4K16_Bright2 	vcxk_bws_word[0x20006 / 2]
#define VC2K_Bright	vcxk_bws[0x8000]
#define VC8K_BrightH	vcxk_bws[0xC000]
#define VC8K_BrightL	vcxk_bws[0xC001]
#ifdef CONFIG_SYS_VCXK_RESET_PORT
#endif
#ifdef CONFIG_SYS_VCXK_DOUBLEBUFFERED
#endif
#if (CONFIG_SYS_VCXK_DEFAULT_LINEALIGN == 4)
#elif (CONFIG_SYS_VCXK_DEFAULT_LINEALIGN == 2)
#else
#endif
#ifdef CONFIG_SYS_VCXK_AUTODETECT
#else
#endif
