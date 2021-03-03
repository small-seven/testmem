#include <asm/emif.h>
#if defined(CONFIG_DRAM_1G) || defined(CONFIG_DRAM_512M)
#elif defined(CONFIG_DRAM_2G)
#endif
#ifdef CONFIG_DRAM_2G
#elif defined(CONFIG_DRAM_1G)
#elif defined(CONFIG_DRAM_512M)
#endif
