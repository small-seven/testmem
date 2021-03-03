#include <common.h>
#include <cpu_func.h>
#include <efi_loader.h>
#include <init.h>
#include <time.h>
#include <asm/arch/clock.h>
#include <asm/arch/display.h>
#include <asm/arch/gpio.h>
#include <asm/arch/lcdc.h>
#include <asm/arch/pwm.h>
#include <asm/arch/tve.h>
#include <asm/global_data.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <axp_pmic.h>
#include <errno.h>
#include <fdtdec.h>
#include <fdt_support.h>
#include <i2c.h>
#include <malloc.h>
#include <video_fb.h>
#include "../videomodes.h"
#include "../anx9804.h"
#include "../hitachi_tx18d42vm_lcd.h"
#include "../ssd2828.h"
#include "simplefb_common.h"
#ifdef CONFIG_VIDEO_LCD_BL_PWM_ACTIVE_LOW
#define PWM_ON 0
#define PWM_OFF 1
#else
#define PWM_ON 1
#define PWM_OFF 0
#endif
#define SUNXI_MONITOR_LAST sunxi_monitor_composite_pal_nc
#ifdef CONFIG_VIDEO_HDMI
#ifdef CONFIG_SUNXI_GEN_SUN6I
#endif
#ifdef CONFIG_SUNXI_GEN_SUN6I
#endif
#ifndef CONFIG_MACH_SUN6I
#else
#endif
#ifndef CONFIG_MACH_SUN6I
#endif
#endif /* CONFIG_VIDEO_HDMI */
#ifdef CONFIG_MACH_SUN4I
#else
#endif
#ifdef CONFIG_SUNXI_GEN_SUN6I
#endif
#ifndef CONFIG_MACH_SUN4I /* On sun4i the frontend does the dma */
#endif
#ifndef CONFIG_MACH_SUN4I /* On sun4i the frontend does the dma */
#else
#endif
#ifndef CONFIG_MACH_SUN5I
#endif
#ifdef CONFIG_SUNXI_GEN_SUN6I
#else
#endif
#ifdef CONFIG_VIDEO_LCD_IF_LVDS
#ifdef CONFIG_SUNXI_GEN_SUN6I
#else
#endif
#endif
#ifdef SUNXI_PWM_PIN0
#endif
#if defined CONFIG_MACH_SUN8I && defined CONFIG_VIDEO_LCD_IF_LVDS
#else
#endif
#ifdef CONFIG_VIDEO_LCD_IF_PARALLEL
#endif
#ifdef CONFIG_VIDEO_LCD_IF_LVDS
#endif
#ifdef CONFIG_VIDEO_LCD_PANEL_EDP_4_LANE_1620M_VIA_ANX9804
#endif
#if defined CONFIG_VIDEO_HDMI || defined CONFIG_VIDEO_VGA || defined CONFIG_VIDEO_COMPOSITE
#endif /* CONFIG_VIDEO_HDMI || defined CONFIG_VIDEO_VGA || CONFIG_VIDEO_COMPOSITE */
#ifdef CONFIG_VIDEO_HDMI
#endif /* CONFIG_VIDEO_HDMI */
#if defined CONFIG_VIDEO_VGA || defined CONFIG_VIDEO_COMPOSITE
#endif /* CONFIG_VIDEO_VGA || defined CONFIG_VIDEO_COMPOSITE */
#ifdef CONFIG_SUNXI_GEN_SUN6I
#ifdef CONFIG_MACH_SUN8I_A33
#endif
#endif
#ifdef CONFIG_VIDEO_VGA_VIA_LCD
#endif /* CONFIG_VIDEO_VGA_VIA_LCD */
#ifdef CONFIG_VIDEO_LCD_SSD2828
#ifdef CONFIG_VIDEO_LCD_PANEL_MIPI_4_LANE_513_MBPS_VIA_SSD2828
#else
#error MIPI LCD panel needs configuration parameters
#endif
#endif /* CONFIG_VIDEO_LCD_SSD2828 */
#ifdef CONFIG_VIDEO_HDMI
#endif
#ifdef CONFIG_VIDEO_LCD_SSD2828
#endif
#ifdef CONFIG_VIDEO_VGA
#elif defined CONFIG_VIDEO_VGA_VIA_LCD
#endif
#ifdef CONFIG_VIDEO_COMPOSITE
#endif
#ifdef CONFIG_VIDEO_HDMI
#else
#endif
#if defined CONFIG_VIDEO_VGA || defined CONFIG_VIDEO_VGA_VIA_LCD
#else
#endif
#ifdef CONFIG_VIDEO_COMPOSITE
#else
#endif
#ifdef CONFIG_VIDEO_HDMI
#endif
#ifdef CONFIG_VIDEO_HDMI
#endif
#ifdef CONFIG_VIDEO_HDMI
#endif
#ifdef CONFIG_EFI_LOADER
#endif
#if defined(CONFIG_OF_BOARD_SETUP) && defined(CONFIG_VIDEO_DT_SIMPLEFB)
#ifdef CONFIG_MACH_SUN4I
#define PIPELINE_PREFIX "de_fe0-"
#else
#define PIPELINE_PREFIX
#endif
#ifdef CONFIG_VIDEO_VGA
#elif defined CONFIG_VIDEO_VGA_VIA_LCD
#endif
#endif /* CONFIG_OF_BOARD_SETUP && CONFIG_VIDEO_DT_SIMPLEFB */
