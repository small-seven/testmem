#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/sysmacros.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <linux/major.h>
#include "sg_include.h"
#include "sg_err.h"
#include "llseek.h"
#define ME "scsimain: "
#ifndef O_DIRECT
#define O_DIRECT 040000
#endif
#define NUMERIC_SCAN_DEF 1	/* change to 0 to make alpha scan default */
#define BPI (signed)(sizeof(int))
#define READWRITE_BASE_NUM 0x12345678
#define DEF_BLOCK_SIZE 512
#define DEF_NUM_THREADS 16
#define MAX_NUM_THREADS SG_MAX_QUEUE
#define DEF_BLOCKS_PER_TRANSFER 128
#define DEF_SCSI_CDBSZ 10
#define MAX_SCSI_CDBSZ 16
#define TUR_CMD_LEN 6
#define DEVNAME_SZ 256
#define MAX_HOLES 4
#define OFF sizeof(struct sg_header)
#define INQ_REPLY_LEN 96	/* logic assumes >= sizeof(inqCmdBlk) */
#define INQUIRY_CMDLEN  6
#define INQUIRY_CMD     0x12
#define SENSE_BUFF_LEN 32	/* Arbitrary, could be larger */
#define DEF_TIMEOUT 60000	/* 60,000 millisecs == 60 seconds */
#define REASON_SZ 128
#define SENSE_BUFF_SZ 64
#define RCAP_REPLY_LEN 8
#define LOG_SENSE_CMD     0x4d
#define LOG_SENSE_CMDLEN  10
#define MX_ALLOC_LEN (1024 * 17)
#define D_ROOT_SZ 512
#define STR_SZ 1024
#define INOUTF_SZ 512
#define EBUFF_SZ 512
#define MDEV_NAME_SZ 256
#define PG_CODE_ALL 0x00
#define TRUE 1
#define FALSE 0
#define MAX_DEVICES 50
#define NAME_LEN_MAX 256
#define LEVELS 4
#define SENSE_BUFF_LEN 32	/* Arbitrary, could be larger */
#define INQ_ALLOC_LEN 255
#ifndef SCSI_IOCTL_GET_PCI
#define SCSI_IOCTL_GET_PCI 0x5387
#endif
#define READ_CAP_REPLY_LEN 8
#ifndef RAW_MAJOR
#define RAW_MAJOR 255		/*unlikey value */
#endif
#define FT_OTHER 1		/* filetype is probably normal */
#define FT_SG 2			/* filetype is sg char device or supports
#define FT_RAW 4		/* filetype is raw char device */
#define FT_DEV_NULL 8		/* either "/dev/null" or "." as filename */
#define FT_ST 16		/* filetype is st char device (tape) */
#define FT_BLOCK 32		/* filetype is block device */
#define DEV_NULL_MINOR_NUM 3
#ifdef SG_GET_RESERVED_SIZE
#define OPEN_FLAG O_RDONLY
#else
#define OPEN_FLAG O_RDWR
#endif
#ifndef SG_MAX_SENSE
#define SG_MAX_SENSE 16
#endif
#define TEST_START 0
#define TEST_BREAK 1
#define TEST_STOP  2
#define MAX_SG_DEVS 128
#define MAX_SD_DEVS 128
#define MAX_SR_DEVS 128
#define MAX_ST_DEVS 128
#define MAX_OSST_DEVS 128
#define MAX_ERRORS 5
#define LIN_DEV_TYPE_UNKNOWN 0
#define LIN_DEV_TYPE_SD 1
#define LIN_DEV_TYPE_SR 2
#define LIN_DEV_TYPE_ST 3
#define LIN_DEV_TYPE_SCD 4
#define LIN_DEV_TYPE_OSST 5
#define MODE_SENSE6_CMD      0x1a
#define MODE_SENSE6_CMDLEN   6
#define MODE_SENSE10_CMD     0x5a
#define MODE_SENSE10_CMDLEN  10
#define INQUIRY_CMD     0x12
#define INQUIRY_CMDLEN  6
#define MODE_ALLOC_LEN (1024 * 4)
#define MODE_CODE_ALL 0x3f
#define RB_MODE_DESC 3
#define RB_MODE_DATA 2
#define RB_DESC_LEN 4
#define RB_MB_TO_READ 200
#define RB_OPCODE 0x3C
#define RB_CMD_LEN 10
#ifndef SG_FLAG_MMAP_IO
#define SG_FLAG_MMAP_IO 4
#endif
#ifndef SG_SCSI_RESET
#define SG_SCSI_RESET 0x2284
#endif
#ifndef SG_SCSI_RESET_NOTHING
#define SG_SCSI_RESET_NOTHING 0
#define SG_SCSI_RESET_DEVICE 1
#define SG_SCSI_RESET_BUS 2
#define SG_SCSI_RESET_HOST 3
#endif
#define LONG_TIMEOUT 2400000	/* 2,400,000 millisecs == 40 minutes */
#define SEND_DIAGNOSTIC_CMD     0x1d
#define SEND_DIAGNOSTIC_CMDLEN  6
#define RECEIVE_DIAGNOSTIC_CMD     0x1c
#define RECEIVE_DIAGNOSTIC_CMDLEN  6
#define START_STOP		0x1b
#define SYNCHRONIZE_CACHE	0x35
#define DEF_START_TIMEOUT 120000	/* 120,000 millisecs == 2 minutes */
#define DEVICE_RESET 0
#define HOST_RESET   1
#define BUS_RESET    2
#define SG_HSZ sizeof(struct sg_header)
#define OFFSET_HEADER (SG_HSZ - (2 * sizeof(int)))
#define SIZEOF_BUFFER (256*1024)
#define SIZEOF_BUFFER1 (16*1024)
#define MAXPARM 32
#define SETUP_MODE_PAGE(NPAGE, NPARAM)          \
typedef struct request_collection {	/* one instance visible to all threads */
	int infd;
	int skip;
	int in_type;
	int in_scsi_type;
	int in_blk;		/* -\ next block address to read */
	int in_count;		/*  | blocks remaining for next read */
	int in_done_count;	/*  | count of completed in blocks */
	int in_partial;		/*  | */
	int in_stop;		/*  | */
	pthread_mutex_t in_mutex;	/* -/ */
	int outfd;
	int seek;
	int out_type;
	int out_scsi_type;
	int out_blk;		/* -\ next block address to write */
	int out_count;		/*  | blocks remaining for next write */
	int out_done_count;	/*  | count of completed out blocks */
	int out_partial;	/*  | */
	int out_stop;		/*  | */
	pthread_mutex_t out_mutex;	/*  | */
	pthread_cond_t out_sync_cv;	/* -/ hold writes until "in order" */
	int bs;
	int bpt;
	int fua_mode;
	int dio;
	int dio_incomplete;	/* -\ */
	int sum_of_resids;	/*  | */
	pthread_mutex_t aux_mutex;	/* -/ (also serializes some printf()s */
	int coe;
	int cdbsz;
	int debug;
} Rq_coll;
typedef struct request_element {	/* one instance per worker thread */
	int infd;
	int outfd;
	int wr;
	int blk;
	int num_blks;
	unsigned char *buffp;
	unsigned char *alloc_bp;
	sg_io_hdr_t io_hdr;
	unsigned char cmd[MAX_SCSI_CDBSZ];
	unsigned char sb[SENSE_BUFF_LEN];
	int bs;
	int fua_mode;
	int dio;
	int dio_incomplete;
	int resid;
	int in_scsi_type;
	int out_scsi_type;
	int cdbsz;
	int debug;
} Rq_elem;
typedef struct my_map_info {
	int active;
	int lin_dev_type;
	int oth_dev_num;
	struct sg_scsi_id sg_dat;
	char vendor[8];
	char product[16];
	char revision[4];
} my_map_info_t;
typedef struct sg_map {
	int bus;
	int channel;
	int target_id;
	int lun;
	char *dev_name;
} Sg_map;
typedef struct my_scsi_idlun {
/* why can't userland see this structure ??? */
	int dev_id;
	int host_unique_id;
} My_scsi_idlun;
#define MAX_PAGENO (sizeof(page_names)/sizeof(char *))
#define err_exit(code,text) do { \
typedef struct my_sg_scsi_id {
	int host_no;		/* as in "scsi<n>" where 'n' is one of 0, 1, 2 etc */
	int channel;
	int scsi_id;		/* scsi id of target device */
	int lun;
	int scsi_type;		/* TYPE_... defined in scsi/scsi.h */
	short h_cmd_per_lun;	/* host (adapter) maximum commands per lun */
	short d_queue_depth;	/* device (or adapter) maximum queue length */
	int unused1;		/* probably find a good use, set 0 for now */
	int unused2;		/* ditto */
} My_sg_scsi_id;
#ifdef SG_IO
#endif
#ifdef SG_EMULATED_HOST
#else
#endif
#if 0
#endif
#ifdef SG_GET_RESERVED_SIZE
#else
#endif
#ifdef SG_IO
#endif
#ifdef SG_GET_RESERVED_SIZE
#else
#endif
#ifdef SG_IO
#endif
#if 0
#endif
#if SG_DEBUG
#endif
#ifdef SG_DEBUG
#endif
#ifdef SG_DEBUG
#endif
#ifdef SG_DEBUG
#endif
#if 0
#ifndef IGN_CLOSE_ERR
#else
#endif
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef SG_DEBUG
#endif
#ifdef SG_DEBUG
#endif
#ifdef SG_DEBUG
#endif
#ifdef SG_DEBUG
#endif
#ifndef SG_GET_RESERVED_SIZE
#endif
#ifdef SG_GET_RESERVED_SIZE
#else
#endif
#ifdef SG_DEF_RESERVED_SIZE
#endif
int mymemcmp(unsigned char *bf1, unsigned char *bf2, int len)
{
	int df;
	for (df = 0; df < len; df++)
		if (bf1[df] != bf2[df])
			return df;
	return 0;
}
#ifndef SG_GET_RESERVED_SIZE
#endif
#if 0
#endif
#ifdef SG_IO_DEBUG
#endif
#ifdef SG_IO_DEBUG
#endif
#ifdef SG_GET_RESERVED_SIZE
#ifdef SG_IO_DEBUG
#endif
#else
#ifdef SG_IO_DEBUG
#endif
#ifdef SG_IO_DEBUG
#endif
#endif
#if 0
#endif
#ifdef SG_GET_RESERVED_SIZE
#endif
#if SG_DEBUG
#endif
#if 0
#endif
#if 0
#endif
#ifdef SG_DEBUG
#endif
#ifdef SG_DEBUG
#endif
#if 0
#endif
#if 0
#endif
