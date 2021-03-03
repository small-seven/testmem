#include <common.h>
#include <config.h>
#include <command.h>
#include <image.h>
#include <irq_func.h>
#undef	FDC_DEBUG
#ifdef	FDC_DEBUG
#define	PRINTF(fmt,args...)	printf (fmt ,##args)
#else
#define PRINTF(fmt,args...)
#endif
typedef struct {
	int		flags;		/* connected drives ect */
	unsigned long	blnr;		/* Logical block nr */
	uchar		drive;		/* drive no */
	uchar		cmdlen;		/* cmd length */
	uchar		cmd[16];	/* cmd desc */
	uchar		dma;		/* if > 0 dma enabled */
	uchar		result[11];	/* status information */
	uchar		resultlen;	/* lenght of result */
} FDC_COMMAND_STRUCT;
#define COMMAND			0
#define DRIVE			1
#define CONFIG0			1
#define SPEC_HUTSRT		1
#define TRACK			2
#define CONFIG1			2
#define SPEC_HLT		2
#define HEAD			3
#define CONFIG2			3
#define SECTOR			4
#define SECTOR_SIZE		5
#define LAST_TRACK		6
#define GAP			7
#define DTL			8
#define STATUS_0		0
#define STATUS_PCN		1
#define STATUS_1		1
#define STATUS_2		2
#define STATUS_TRACK		3
#define STATUS_HEAD		4
#define STATUS_SECT		5
#define STATUS_SECT_SIZE	6
#define FDC_BASE	0x3F0
#define FDC_SRA		FDC_BASE + 0	/* Status Register A */
#define FDC_SRB		FDC_BASE + 1	/* Status Register B */
#define FDC_DOR		FDC_BASE + 2	/* Digital Output Register */
#define FDC_TDR		FDC_BASE + 3	/* Tape Drive Register */
#define FDC_DSR		FDC_BASE + 4	/* Data rate Register */
#define FDC_MSR		FDC_BASE + 4	/* Main Status Register */
#define FDC_FIFO	FDC_BASE + 5	/* FIFO */
#define FDC_DIR		FDC_BASE + 6	/* Digital Input Register */
#define FDC_CCR		FDC_BASE + 7	/* Configuration Control */
#define FDC_CMD_SENSE_INT	0x08
#define FDC_CMD_CONFIGURE	0x13
#define FDC_CMD_SPECIFY		0x03
#define FDC_CMD_RECALIBRATE	0x07
#define FDC_CMD_READ		0x06
#define FDC_CMD_READ_TRACK	0x02
#define FDC_CMD_READ_ID		0x0A
#define FDC_CMD_DUMP_REG	0x0E
#define FDC_CMD_SEEK		0x0F
#define FDC_CMD_SENSE_INT_LEN	0x01
#define FDC_CMD_CONFIGURE_LEN	0x04
#define FDC_CMD_SPECIFY_LEN	0x03
#define FDC_CMD_RECALIBRATE_LEN	0x02
#define FDC_CMD_READ_LEN	0x09
#define FDC_CMD_READ_TRACK_LEN	0x09
#define FDC_CMD_READ_ID_LEN	0x02
#define FDC_CMD_DUMP_REG_LEN	0x01
#define FDC_CMD_SEEK_LEN	0x03
#define FDC_FIFO_THR		0x0C
#define FDC_FIFO_DIS		0x00
#define FDC_IMPLIED_SEEK	0x01
#define FDC_POLL_DIS		0x00
#define FDC_PRE_TRK		0x00
#define FDC_CONFIGURE		FDC_FIFO_THR | (FDC_POLL_DIS<<4) | (FDC_FIFO_DIS<<5) | (FDC_IMPLIED_SEEK << 6)
#define FDC_MFM_MODE		0x01 /* MFM enable */
#define FDC_SKIP_MODE		0x00 /* skip enable */
#define FDC_TIME_OUT 100000 /* time out */
#define	FDC_RW_RETRIES		3 /* read write retries */
#define FDC_CAL_RETRIES		3 /* calibration and seek retries */
typedef struct  {
	unsigned int size;	/* nr of sectors total */
	unsigned int sect;	/* sectors per track */
	unsigned int head;	/* nr of heads */
	unsigned int track;	/* nr of tracks */
	unsigned int stretch;	/* !=0 means double track steps */
	unsigned char	gap;	/* gap1 size */
	unsigned char	rate;	/* data rate. |= 0x40 for perpendicular */
	unsigned char	spec1;	/* stepping rate, head unload time */
	unsigned char	fmt_gap;/* gap2 size */
	unsigned char hlt;	/* head load time */
	unsigned char sect_code;/* Sector Size code */
	const char	* name;	/* used only for predefined formats */
} FD_GEO_STRUCT;
#ifndef CONFIG_SYS_FDC_DRIVE_NUMBER
#define CONFIG_SYS_FDC_DRIVE_NUMBER 0
#endif
#ifndef CONFIG_SYS_ISA_IO_STRIDE
#define CONFIG_SYS_ISA_IO_STRIDE 1
#endif
#ifndef CONFIG_SYS_ISA_IO_OFFSET
#define CONFIG_SYS_ISA_IO_OFFSET 0
#endif
#ifdef CONFIG_SYS_FDC_HW_INIT
#endif
#if defined(CONFIG_LEGACY_IMAGE_FORMAT)
#endif
#if defined(CONFIG_FIT)
#endif
#if defined(CONFIG_LEGACY_IMAGE_FORMAT)
#endif
#if defined(CONFIG_FIT)
#endif
#if defined(CONFIG_FIT)
#endif
