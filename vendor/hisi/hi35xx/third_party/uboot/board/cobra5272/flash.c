#include <common.h>
#include <console.h>
#include <cpu_func.h>
#include <irq_func.h>
#define PHYS_FLASH_1 CONFIG_SYS_FLASH_BASE
#define FLASH_BANK_SIZE 0x200000
#define CMD_READ_ARRAY		0x00F0
#define CMD_UNLOCK1		0x00AA
#define CMD_UNLOCK2		0x0055
#define CMD_ERASE_SETUP		0x0080
#define CMD_ERASE_CONFIRM	0x0030
#define CMD_PROGRAM		0x00A0
#define CMD_UNLOCK_BYPASS	0x0020
#define MEM_FLASH_ADDR1		(*(volatile u16 *)(CONFIG_SYS_FLASH_BASE + (0x00000555<<1)))
#define MEM_FLASH_ADDR2		(*(volatile u16 *)(CONFIG_SYS_FLASH_BASE + (0x000002AA<<1)))
#define BIT_ERASE_DONE		0x0080
#define BIT_RDY_MASK		0x0080
#define BIT_PROGRAM_ERROR	0x0020
#define BIT_TIMEOUT		0x80000000	/* our flag */
#define READY 1
#define ERR   2
#define TMO   4
#if 0
#endif
