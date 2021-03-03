#include <common.h>
#include <command.h>
#include <bios_emul.h>
#include <env.h>
#include <pci.h>
#include <asm/processor.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <malloc.h>
#include <video_fb.h>
#include "videomodes.h"
#include <radeon.h>
#include "ati_ids.h"
#include "ati_radeon_fb.h"
#undef DEBUG
#ifdef DEBUG
#define DPRINT(x...) printf(x)
#else
#define DPRINT(x...) do{}while(0)
#endif
#define MAX_MAPPED_VRAM	(2048*2048*4)
#define MIN_MAPPED_VRAM	(1024*768*1)
#define RADEON_BUFFER_ALIGN		0x00000fff
#define SURF_UPPER_BOUND(x,y,bpp)	(((((x) * (((y) + 15) & ~15) * (bpp)/8) + RADEON_BUFFER_ALIGN) \
#define RADEON_CRT_PITCH(width, bpp)	((((width) * (bpp) + ((bpp) * 8 - 1)) / ((bpp) * 8)) | \
#define CRTC_H_TOTAL_DISP_VAL(htotal, hdisp) \
#define CRTC_HSYNC_STRT_WID_VAL(hsync_srtr, hsync_wid) \
#define CRTC_V_TOTAL_DISP_VAL(vtotal, vdisp) \
#define CRTC_VSYNC_STRT_WID_VAL(vsync_srtr, vsync_wid) \
#define PCI_CHIP_RV280_5960		0x5960
#define PCI_CHIP_RV280_5961		0x5961
#define PCI_CHIP_RV280_5962		0x5962
#define PCI_CHIP_RV280_5964		0x5964
#define PCI_CHIP_RV280_5C63		0x5C63
#define PCI_CHIP_RV370_5B60		0x5B60
#define PCI_CHIP_RV380_5657		0x5657
#define PCI_CHIP_R420_554d		0x554d
#if 0
#endif
typedef struct {
	u16 reg;
	u32 val;
} reg_val;
#if 0	/* unused ? -> scheduled for removal */
#endif /* 0 */
#if defined(__BIG_ENDIAN)
#endif
#if defined(__BIG_ENDIAN)
#endif
#if defined(CONFIG_RADEON_VREFRESH_75HZ)
#else /* default @ 60 Hz */
#endif
#if defined(CONFIG_RADEON_VREFRESH_75HZ)
#else /* @ 60 Hz */
#endif
#if defined(CONFIG_RADEON_VREFRESH_75HZ)
#else /* @ 60 Hz */
#endif
#if defined(CONFIG_RADEON_VREFRESH_75HZ)
#else /* @ 60 Hz */
#endif
#include "../bios_emulator/include/biosemu.h"
#define CURSOR_SIZE	0x1000	/* in KByte for HW Cursor */
#define PATTERN_ADR	(pGD->dprBase + CURSOR_SIZE)	/* pattern Memory after Cursor Memory */
#define PATTERN_SIZE	8*8*4	/* 4 Bytes per Pixel 8 x 8 Pixel */
#define ACCELMEMORY	(CURSOR_SIZE + PATTERN_SIZE)	/* reserved Memory for BITBlt and hw cursor */
