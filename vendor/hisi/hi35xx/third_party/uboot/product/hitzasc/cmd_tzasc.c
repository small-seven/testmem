#include <common.h>
#define writel(addr, value) ((*(volatile unsigned int *)(addr)) = (value))
#define io_address(x)             (x)
#define TZASC_BASE_ADDR           io_address(0x04601000)
#define SEC_BYPASS                ((TZASC_BASE_ADDR) + (0x4))
#define SEC_INTEN                 ((TZASC_BASE_ADDR) + (0x20))
#define sec_rgn_map(n)            ((TZASC_BASE_ADDR) + (0x100) + (0x10 * (n)))
#define sec_rgn_map_ext(n)        ((TZASC_BASE_ADDR) + (0x200) + (0x10 * (n)))
#define sec_rgn_attrib(n)         ((TZASC_BASE_ADDR) + (0x104) + (0x10 * (n)))
typedef struct {
	unsigned int index;

	unsigned int start_addr;
	unsigned int size;

	unsigned int secure_mode;
#define NON_SECURE_W    0x1 << 0
#define NON_SECURE_R    0x1 << 1
#define SECURE_W        0x1 << 2
#define SECURE_R        0x1 << 3
} region_attr_t;
