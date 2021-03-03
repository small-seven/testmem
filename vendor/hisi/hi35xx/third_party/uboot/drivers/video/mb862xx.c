#include <common.h>
#include <asm/io.h>
#include <env.h>
#include <pci.h>
#include <video_fb.h>
#include "videomodes.h"
#include <mb862xx.h>
#if defined(CONFIG_POST)
#include <post.h>
#endif
#define VIDEO_MEM_SIZE	0x01FC0000
#if defined(CONFIG_PCI)
#if defined(CONFIG_VIDEO_CORALP)
#endif
#endif
#if defined(CONFIG_VIDEO_CORALP)
#define	rd_io		in32r
#define	wr_io		out32r
#else
#define	rd_io(addr)	in_be32((volatile unsigned *)(addr))
#define	wr_io(addr, val)	out_be32((volatile unsigned *)(addr), (val))
#endif
#define HOST_RD_REG(off)	rd_io((dev->frameAdrs + GC_HOST_BASE + (off)))
#define HOST_WR_REG(off, val)	wr_io((dev->frameAdrs + GC_HOST_BASE + (off)), \
#define DISP_RD_REG(off)	rd_io((dev->frameAdrs + GC_DISP_BASE + (off)))
#define DISP_WR_REG(off, val)	wr_io((dev->frameAdrs + GC_DISP_BASE + (off)), \
#define DE_RD_REG(off)		rd_io((dev->dprBase + (off)))
#define DE_WR_REG(off, val)	wr_io((dev->dprBase + (off)), (val))
#if defined(CONFIG_VIDEO_CORALP)
#define DE_WR_FIFO(val)		wr_io((dev->dprBase + (GC_GEO_FIFO)), (val))
#else
#define DE_WR_FIFO(val)		wr_io((dev->dprBase + (GC_FIFO)), (val))
#endif
#define L0PAL_WR_REG(idx, val)	wr_io((dev->frameAdrs + \
#if defined(CONFIG_VIDEO_MB862xx_ACCEL)
#endif
#if !defined(CONFIG_VIDEO_CORALP)
#endif
#if defined(CONFIG_VIDEO_MB862xx_ACCEL)
#else
#endif
#if defined(CONFIG_VIDEO_CORALP)
#ifndef CONFIG_SYS_MB862xx_CCF
#define CONFIG_SYS_MB862xx_CCF	0x00090000
#endif
#ifndef CONFIG_SYS_MB862xx_MMR
#define CONFIG_SYS_MB862xx_MMR	0x11d7fa13
#endif
#endif
#if !defined(CONFIG_VIDEO_CORALP)
#endif
#if defined(CONFIG_VIDEO_CORALP)
#else
#endif
#if !defined(CONFIG_VIDEO_CORALP)
#endif
#if (defined(CONFIG_LWMON5) || \
#endif
#if defined(CONFIG_VIDEO_MB862xx_ACCEL)
#endif
