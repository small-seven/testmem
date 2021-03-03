#include "vou_hal.h"
#include <asm/io.h>
#include "hi3516cv500_vo.h"
#define IO_ADDRESS(x) (x)
#define HI_INVALID_LAYER (-1)
#define CRG_REGS_ADDR 0x12010000
#define CRG_REGS_SIZE 0X10000
#define CRG_PERCTL2_ADDR (0x0008 + CRG_REGS_ADDR)
#define CRG_PERCTL3_ADDR (0x000C + CRG_REGS_ADDR)
#define CRG_PERCTL4_ADDR (0x0010 + CRG_REGS_ADDR)
#define CRG_PERCTL5_ADDR (0x0014 + CRG_REGS_ADDR)
#define CRG_PERCTL6_ADDR (0x0018 + CRG_REGS_ADDR)
#define CRG_PERCTL7_ADDR (0x001c + CRG_REGS_ADDR)
#define CRG_PERCTL10_ADDR (0x0028 + CRG_REGS_ADDR)
#define CRG_PERCTL11_ADDR (0x002c + CRG_REGS_ADDR)
#define CRG_PERCTL18_ADDR (0x0048 + CRG_REGS_ADDR)
#define CRG_PERCTL19_ADDR (0x004c + CRG_REGS_ADDR)
#define CRG_PERCTL59_ADDR (0x00ec + CRG_REGS_ADDR)
#define CRG_PERCTL65_ADDR (0x0104 + CRG_REGS_ADDR) /* LCD CRG */
#define CRG_PERCTL66_ADDR (0x0108 + CRG_REGS_ADDR) /* VDP low power CRG */
#define CRG_PERCTL72_ADDR (0x0120 + CRG_REGS_ADDR)
#define CRG_PERCTL73_ADDR (0x0124 + CRG_REGS_ADDR) /* VDP CRG */
#define CRG_PERCTL15_ADDR (0x003C + CRG_REGS_ADDR)
#define LCD_CRG_PERCTL_ADDR CRG_PERCTL65_ADDR
#define VOU_CRG_PERCTL_ADDR CRG_PERCTL66_ADDR
#define MISC_REGS_ADDR 0x12030000
#define MISC_REGS_SIZE 0x8000
#define MISC_CTL18_ADDR (0x18 + MISC_REGS_ADDR)