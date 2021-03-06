#include "vou_hal.h"
#include <asm/io.h>
#include "hi3559av100_vo.h"
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
#define CRG_PERCTL64_ADDR (0x0100 + CRG_REGS_ADDR) /* VDP low power CRG */
#define CRG_PERCTL72_ADDR (0x0120 + CRG_REGS_ADDR) /* VDP CRG */
#define CRG_PERCTL73_ADDR (0x0124 + CRG_REGS_ADDR) /* VDP CRG */
#define CRG_PERCTL15_ADDR (0x003C + CRG_REGS_ADDR)
#define HDMI_REGS_ADDR          0x201f0000L
#define HDMI_REGS_SIZE          0X10000
#define IO_CONFIG_ADDR          0x1F000000
#define IO_CONFIG_BT1120_CLK    (0x1084 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA0  (0x1088 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA1  (0x108C + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA2  (0x1090 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA3  (0x1094 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA4  (0x1098 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA5  (0x109C + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA6  (0x10A0 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA7  (0x10A4 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA8  (0x10A8 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA9  (0x10AC + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA10 (0x10B0 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA11 (0x10B4 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA12 (0x10B8 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA13 (0x10BC + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA14 (0x10C0 + IO_CONFIG_ADDR)
#define IO_CONFIG_BT1120_DATA15 (0x10C4 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_CLK    (0x10EC + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DE     (0x10A4 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_HSYNC  (0x109C + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_VSYNC  (0x10E4 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA0  (0x1098 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA1  (0x1094 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA2  (0x1090 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA3  (0x108C + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA4  (0x1088 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA5  (0x10C4 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA6  (0x10C0 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA7  (0x10A8 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA8  (0x10B8 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA9  (0x10B4 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA10 (0x10B0 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA11 (0x10AC + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA12 (0x1008 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA13 (0x100C + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA14 (0x1010 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA15 (0x1000 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA16 (0x1014 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA17 (0x1038 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA18 (0x101C + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA19 (0x1030 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA20 (0x1020 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA21 (0x1024 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA22 (0x1028 + IO_CONFIG_ADDR)
#define IO_CONFIG_LCD_DATA23 (0x102C + IO_CONFIG_ADDR)
