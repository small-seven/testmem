#include <common.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <asm/byteorder.h>
#define P_ID_AMD_STD CFI_CMDSET_AMD_LEGACY
#define AM29DL800BB	0x22CB
#define AM29DL800BT	0x224A
#define AM29F400BB	0x22AB
#define AM29F800BB	0x2258
#define AM29F800BT	0x22D6
#define AM29LV400BB	0x22BA
#define AM29LV400BT	0x22B9
#define AM29LV800BB	0x225B
#define AM29LV800BT	0x22DA
#define AM29LV160DT	0x22C4
#define AM29LV160DB	0x2249
#define AM29F017D	0x003D
#define AM29F016D	0x00AD
#define AM29F080	0x00D5
#define AM29F040	0x00A4
#define AM29LV040B	0x004F
#define AM29F032B	0x0041
#define AM29F002T	0x00B0
#define SST39LF800	0x2781
#define SST39LF160	0x2782
#define SST39VF1601	0x234b
#define SST39LF512	0x00D4
#define SST39LF010	0x00D5
#define SST39LF020	0x00D6
#define SST39LF040	0x00D7
#define SST39SF010A	0x00B5
#define SST39SF020A	0x00B6
#define STM29F400BB	0x00D6
#define MX29LV040	0x004F
#define W39L040A	0x00D6
#define A29L040		0x0092
#define EN29LV040A	0x004F
#define ERASEINFO(size,blocks) (size<<8)|(blocks-1)
#define SIZE_64KiB  16
#define SIZE_128KiB 17
#define SIZE_256KiB 18
#define SIZE_512KiB 19
#define SIZE_1MiB   20
#define SIZE_2MiB   21
#define SIZE_4MiB   22
#define SIZE_8MiB   23
#ifdef CONFIG_SYS_FLASH_LEGACY_256Kx8
#endif
#ifdef CONFIG_SYS_FLASH_LEGACY_512Kx8
#endif
#ifdef CONFIG_SYS_FLASH_LEGACY_512Kx16
#endif
