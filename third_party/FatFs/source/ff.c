#include "ff.h"			/* Declarations of FatFs API */
#include <user_copy.h>
#include "diskio.h"		/* Declarations of device I/O functions */
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#include "virpartff.h"
#endif
#if FF_DEFINED != 86604	/* Revision ID */
#error Wrong include file (ff.h).
#endif
#define MAX_DIR		0x200000		/* Max size of FAT directory */
#define MAX_FAT12	0xFF5			/* Max FAT12 clusters (differs from specs, but right for real DOS/Windows behavior) */
#define MAX_FAT16	0xFFF5			/* Max FAT16 clusters (differs from specs, but right for real DOS/Windows behavior) */
#define MAX_FAT32	0x0FFFFFF5		/* Max FAT32 clusters (not specified, practical limit) */
#define IsUpper(c)		((c) >= 'A' && (c) <= 'Z')
#define IsLower(c)		((c) >= 'a' && (c) <= 'z')
#define IsDigit(c)		((c) >= '0' && (c) <= '9')
#define IsSurrogate(c)	((c) >= 0xD800 && (c) <= 0xDFFF)
#define IsSurrogateH(c)	((c) >= 0xD800 && (c) <= 0xDBFF)
#define IsSurrogateL(c)	((c) >= 0xDC00 && (c) <= 0xDFFF)
#define FA_SEEKEND	0x20	/* Seek to end of the file on file open */
#define FA_MODIFIED	0x40	/* File has been modified */
#define FA_DIRTY	0x80	/* FIL.buf[] needs to be written-back */
#define AM_VOL		0x08	/* Volume label */
#define AM_LFN		0x0F	/* LFN entry */
#define AM_MASK		0x3F	/* Mask of defined bits */
#define NSFLAG		11		/* Index of the name status byte */
#define NS_LOSS		0x01	/* Out of 8.3 format */
#define NS_LFN		0x02	/* Force to create LFN entry */
#define NS_LAST		0x04	/* Last segment */
#define NS_BODY		0x08	/* Lower case flag (body) */
#define NS_EXT		0x10	/* Lower case flag (ext) */
#define NS_DOT		0x20	/* Dot entry */
#define NS_NOLFN	0x40	/* Do not find LFN */
#define NS_NONAME	0x80	/* Not followed */
#define BS_JmpBoot			0		/* x86 jump instruction (3-byte) */
#define BS_OEMName			3		/* OEM name (8-byte) */
#define BPB_BytsPerSec		11		/* Sector size [byte] (WORD) */
#define BPB_SecPerClus		13		/* Cluster size [sector] (BYTE) */
#define BPB_RsvdSecCnt		14		/* Size of reserved area [sector] (WORD) */
#define BPB_NumFATs			16		/* Number of FATs (BYTE) */
#define BPB_RootEntCnt		17		/* Size of root directory area for FAT [entry] (WORD) */
#define BPB_TotSec16		19		/* Volume size (16-bit) [sector] (WORD) */
#define BPB_Media			21		/* Media descriptor byte (BYTE) */
#define BPB_FATSz16			22		/* FAT size (16-bit) [sector] (WORD) */
#define BPB_SecPerTrk		24		/* Number of sectors per track for int13h [sector] (WORD) */
#define BPB_NumHeads		26		/* Number of heads for int13h (WORD) */
#define BPB_HiddSec			28		/* Volume offset from top of the drive (DWORD) */
#define BPB_TotSec32		32		/* Volume size (32-bit) [sector] (DWORD) */
#define BS_DrvNum			36		/* Physical drive number for int13h (BYTE) */
#define BS_NTres			37		/* WindowsNT error flag (BYTE) */
#define BS_BootSig			38		/* Extended boot signature (BYTE) */
#define BS_VolID			39		/* Volume serial number (DWORD) */
#define BS_VolLab			43		/* Volume label string (8-byte) */
#define BS_FilSysType		54		/* Filesystem type string (8-byte) */
#define BS_BootCode			62		/* Boot code (448-byte) */
#define BS_55AA				510		/* Signature word (WORD) */
#define BPB_FATSz32			36		/* FAT32: FAT size [sector] (DWORD) */
#define BPB_ExtFlags32		40		/* FAT32: Extended flags (WORD) */
#define BPB_FSVer32			42		/* FAT32: Filesystem version (WORD) */
#define BPB_RootClus32		44		/* FAT32: Root directory cluster (DWORD) */
#define BPB_FSInfo32		48		/* FAT32: Offset of FSINFO sector (WORD) */
#define BPB_BkBootSec32		50		/* FAT32: Offset of backup boot sector (WORD) */
#define BS_DrvNum32			64		/* FAT32: Physical drive number for int13h (BYTE) */
#define BS_NTres32			65		/* FAT32: Error flag (BYTE) */
#define BS_BootSig32		66		/* FAT32: Extended boot signature (BYTE) */
#define BS_VolID32			67		/* FAT32: Volume serial number (DWORD) */
#define BS_VolLab32			71		/* FAT32: Volume label string (8-byte) */
#define BS_FilSysType32		82		/* FAT32: Filesystem type string (8-byte) */
#define BS_BootCode32		90		/* FAT32: Boot code (420-byte) */
#define DIR_Name			0		/* Short file name (11-byte) */
#define DIR_Attr			11		/* Attribute (BYTE) */
#define DIR_NTres			12		/* Lower case flag (BYTE) */
#define DIR_CrtTime10		13		/* Created time sub-second (BYTE) */
#define DIR_CrtTime			14		/* Created time (DWORD) */
#define DIR_LstAccDate		18		/* Last accessed date (WORD) */
#define DIR_FstClusHI		20		/* Higher 16-bit of first cluster (WORD) */
#define DIR_ModTime			22		/* Modified time (DWORD) */
#define DIR_FstClusLO		26		/* Lower 16-bit of first cluster (WORD) */
#define DIR_FileSize		28		/* File size (DWORD) */
#define LDIR_Ord			0		/* LFN: LFN order and LLE flag (BYTE) */
#define LDIR_Attr			11		/* LFN: LFN attribute (BYTE) */
#define LDIR_Type			12		/* LFN: Entry type (BYTE) */
#define LDIR_Chksum			13		/* LFN: Checksum of the SFN (BYTE) */
#define LDIR_FstClusLO		26		/* LFN: MBZ field (WORD) */
#define SZDIRE				32		/* Size of a directory entry */
#define DDEM				0xE5	/* Deleted directory entry mark set to DIR_Name[0] */
#define RDDEM				0x05	/* Replacement of the character collides with DDEM */
#define LLEF				0x40	/* Last long entry flag in LDIR_Ord */
#define FSI_LeadSig			0		/* FAT32 FSI: Leading signature (DWORD) */
#define FSI_StrucSig		484		/* FAT32 FSI: Structure signature (DWORD) */
#define FSI_Free_Count		488		/* FAT32 FSI: Number of free clusters (DWORD) */
#define FSI_Nxt_Free		492		/* FAT32 FSI: Last allocated cluster (DWORD) */
#define MBR_Table			446		/* MBR: Offset of partition table in the MBR */
#define SZ_PTE				16		/* MBR: Size of a partition table entry */
#define PTE_Boot			0		/* MBR PTE: Boot indicator */
#define PTE_StHead			1		/* MBR PTE: Start head */
#define PTE_StSec			2		/* MBR PTE: Start sector */
#define PTE_StCyl			3		/* MBR PTE: Start cylinder */
#define PTE_System			4		/* MBR PTE: System ID */
#define PTE_EdHead			5		/* MBR PTE: End head */
#define PTE_EdSec			6		/* MBR PTE: End sector */
#define PTE_EdCyl			7		/* MBR PTE: End cylinder */
#define PTE_StLba			8		/* MBR PTE: Start in LBA */
#define PTE_SizLba			12		/* MBR PTE: Size in LBA */
#define ABORT(fs, res)		{ fp->err = (BYTE)(res); LEAVE_FF(fs, res); }
#if FF_FS_REENTRANT
#if FF_USE_LFN == 1
#error Static LFN work area cannot be used at thread-safe configuration
#endif
#define LEAVE_FF(fs, res)	{ unlock_fs(fs, res); return res; }
#else
#define LEAVE_FF(fs, res)	return res
#endif
#if (FF_MAX_SS < FF_MIN_SS) || (FF_MAX_SS != 512 && FF_MAX_SS != 1024 && FF_MAX_SS != 2048 && FF_MAX_SS != 4096) || (FF_MIN_SS != 512 && FF_MIN_SS != 1024 && FF_MIN_SS != 2048 && FF_MIN_SS != 4096)
#error Wrong sector size configuration
#endif
#if FF_FS_NORTC == 1
#if FF_NORTC_YEAR < 1980 || FF_NORTC_YEAR > 2107 || FF_NORTC_MON < 1 || FF_NORTC_MON > 12 || FF_NORTC_MDAY < 1 || FF_NORTC_MDAY > 31
#error Invalid FF_FS_NORTC settings
#endif
#define GET_FATTIME()	((DWORD)(FF_NORTC_YEAR - 1980) << 25 | (DWORD)FF_NORTC_MON << 21 | (DWORD)FF_NORTC_MDAY << 16)
#else
#define GET_FATTIME()	get_fattime()
#endif
#if FF_FS_LOCK != 0
#if FF_FS_READONLY
#error FF_FS_LOCK must be 0 at read-only configuration
#endif
typedef struct {
	FATFS *fs;		/* Object ID 1, volume (NULL:blank entry) */
	DWORD clu;		/* Object ID 2, containing directory (0:root) */
	DWORD ofs;		/* Object ID 3, offset in the directory */
	WORD ctr;		/* Object open counter, 0:none, 0x01..0xFF:read mode open count, 0x100:write mode */
} FILESEM;
#endif
#define TBL_CT437  {0x80,0x9A,0x45,0x41,0x8E,0x41,0x8F,0x80,0x45,0x45,0x45,0x49,0x49,0x49,0x8E,0x8F, \
#define TBL_CT720  {0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F, \
#define TBL_CT737  {0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F, \
#define TBL_CT771  {0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F, \
#define TBL_CT775  {0x80,0x9A,0x91,0xA0,0x8E,0x95,0x8F,0x80,0xAD,0xED,0x8A,0x8A,0xA1,0x8D,0x8E,0x8F, \
#define TBL_CT850  {0x43,0x55,0x45,0x41,0x41,0x41,0x41,0x43,0x45,0x45,0x45,0x49,0x49,0x49,0x41,0x41, \
#define TBL_CT852  {0x80,0x9A,0x90,0xB6,0x8E,0xDE,0x8F,0x80,0x9D,0xD3,0x8A,0x8A,0xD7,0x8D,0x8E,0x8F, \
#define TBL_CT855  {0x81,0x81,0x83,0x83,0x85,0x85,0x87,0x87,0x89,0x89,0x8B,0x8B,0x8D,0x8D,0x8F,0x8F, \
#define TBL_CT857  {0x80,0x9A,0x90,0xB6,0x8E,0xB7,0x8F,0x80,0xD2,0xD3,0xD4,0xD8,0xD7,0x49,0x8E,0x8F, \
#define TBL_CT860  {0x80,0x9A,0x90,0x8F,0x8E,0x91,0x86,0x80,0x89,0x89,0x92,0x8B,0x8C,0x98,0x8E,0x8F, \
#define TBL_CT861  {0x80,0x9A,0x90,0x41,0x8E,0x41,0x8F,0x80,0x45,0x45,0x45,0x8B,0x8B,0x8D,0x8E,0x8F, \
#define TBL_CT862  {0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F, \
#define TBL_CT863  {0x43,0x55,0x45,0x41,0x41,0x41,0x86,0x43,0x45,0x45,0x45,0x49,0x49,0x8D,0x41,0x8F, \
#define TBL_CT864  {0x80,0x9A,0x45,0x41,0x8E,0x41,0x8F,0x80,0x45,0x45,0x45,0x49,0x49,0x49,0x8E,0x8F, \
#define TBL_CT865  {0x80,0x9A,0x90,0x41,0x8E,0x41,0x8F,0x80,0x45,0x45,0x45,0x49,0x49,0x49,0x8E,0x8F, \
#define TBL_CT866  {0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F, \
#define TBL_CT869  {0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F, \
#define TBL_DC932 {0x81, 0x9F, 0xE0, 0xFC, 0x40, 0x7E, 0x80, 0xFC, 0x00, 0x00}
#define TBL_DC936 {0x81, 0xFE, 0x00, 0x00, 0x40, 0x7E, 0x80, 0xFE, 0x00, 0x00}
#define TBL_DC949 {0x81, 0xFE, 0x00, 0x00, 0x41, 0x5A, 0x61, 0x7A, 0x81, 0xFE}
#define TBL_DC950 {0x81, 0xFE, 0x00, 0x00, 0x40, 0x7E, 0xA1, 0xFE, 0x00, 0x00}
#define MERGE_2STR(a, b) a ## b
#define MKCVTBL(hd, cp) MERGE_2STR(hd, cp)
#if FF_VOLUMES < 1
#error Wrong FF_VOLUMES setting
#endif
#if FF_FS_RPATH != 0 && FF_VOLUMES >= 2
#endif
#if FF_FS_LOCK != 0
#endif
#if FF_STR_VOLUME_ID
#ifdef FF_VOLUME_STRS
#endif
#endif
#if FF_USE_LFN == 0		/* Non-LFN configuration */
#define DEF_NAMBUF
#define INIT_NAMBUF(fs)
#define FREE_NAMBUF()
#define LEAVE_MKFS(res)	return res
#else					/* LFN configurations */
#if FF_MAX_LFN < 12 || FF_MAX_LFN > 255
#error Wrong setting of FF_MAX_LFN
#endif
#if FF_LFN_BUF < FF_SFN_BUF || FF_SFN_BUF < 12
#error Wrong setting of FF_LFN_BUF or FF_SFN_BUF
#endif
#if FF_LFN_UNICODE < 0 || FF_LFN_UNICODE > 3
#error Wrong setting of FF_LFN_UNICODE
#endif
#if FF_USE_LFN == 1		/* LFN enabled with static working buffer */
#define DEF_NAMBUF
#define INIT_NAMBUF(fs)
#define FREE_NAMBUF()
#define LEAVE_MKFS(res)	return res
#elif FF_USE_LFN == 2 	/* LFN enabled with dynamic working buffer on the stack */
#define DEF_NAMBUF		WCHAR lbuf[FF_MAX_LFN+1];	/* LFN working buffer */
#define INIT_NAMBUF(fs)	{ (fs)->lfnbuf = lbuf; }
#define FREE_NAMBUF()
#define LEAVE_MKFS(res)	return res
#elif FF_USE_LFN == 3 	/* LFN enabled with dynamic working buffer on the heap */
#define DEF_NAMBUF		WCHAR *lfn;	/* Pointer to LFN working buffer and directory entry block scratchpad buffer */
#define INIT_NAMBUF(fs)	{ lfn = ff_memalloc((FF_MAX_LFN+1)*2); if (!lfn) LEAVE_FF(fs, FR_NOT_ENOUGH_CORE); (fs)->lfnbuf = lfn; }
#define FREE_NAMBUF()	ff_memfree(lfn)
#define LEAVE_MKFS(res)	{ if (!work) ff_memfree(buf); return res; }
#define MAX_MALLOC	0x8000	/* Must be >=FF_MAX_SS */
#else
#error Wrong setting of FF_USE_LFN
#endif	/* FF_USE_LFN == 1 */
#endif	/* FF_USE_LFN == 0 */
#if FF_CODE_PAGE == 0		/* Run-time code page configuration */
#define CODEPAGE CodePage
#elif FF_CODE_PAGE < 900	/* Static code page configuration (SBCS) */
#define CODEPAGE FF_CODE_PAGE
#else					/* Static code page configuration (DBCS) */
#define CODEPAGE FF_CODE_PAGE
#endif
#if !FF_FS_READONLY
#endif /* !FF_FS_READONLY */
#if FF_CODE_PAGE == 0		/* Variable code page */
#elif FF_CODE_PAGE >= 900	/* DBCS fixed code page */
#else						/* SBCS fixed code page */
#endif
#if FF_CODE_PAGE == 0		/* Variable code page */
#elif FF_CODE_PAGE >= 900	/* DBCS fixed code page */
#else						/* SBCS fixed code page */
#endif
#if FF_USE_LFN
#if FF_LFN_UNICODE == 1		/* UTF-16 input */
#elif FF_LFN_UNICODE == 2	/* UTF-8 input */
#elif FF_LFN_UNICODE == 3	/* UTF-32 input */
#else		/* ANSI/OEM input */
#endif
#if FF_LFN_UNICODE == 1	/* UTF-16 output */
#elif FF_LFN_UNICODE == 2	/* UTF-8 output */
#elif FF_LFN_UNICODE == 3	/* UTF-32 output */
#else						/* ANSI/OEM output */
#endif
#endif	/* FF_USE_LFN */
#if FF_FS_REENTRANT
#endif
#if FF_FS_LOCK != 0
#endif	/* FF_FS_LOCK != 0 */
#if FF_FS_LOCK != 0
#endif
#if !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#if !FF_FS_READONLY
#endif
#if !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#if !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#endif /* !FF_FS_READONLY */
#if !FF_FS_READONLY
#if FF_USE_TRIM
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#if FF_USE_TRIM
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#endif /* !FF_FS_READONLY */
#if FF_USE_FASTSEEK
#endif	/* FF_USE_FASTSEEK */
#if !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#if FF_USE_LFN == 3		/* Quick table clear by using multi-secter write */
#endif
#endif	/* !FF_FS_READONLY */
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#if !FF_FS_READONLY
#else
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#if !FF_FS_READONLY
#endif	/* !FF_FS_READONLY */
#if !FF_FS_READONLY
#endif
#if FF_USE_LFN
#if FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >= 2 || FF_USE_LABEL
#endif
#if !FF_FS_READONLY
#endif	/* !FF_FS_READONLY */
#endif	/* FF_USE_LFN */
#if FF_USE_LFN && !FF_FS_READONLY
#endif	/* FF_USE_LFN && !FF_FS_READONLY */
#if FF_USE_LFN
#endif	/* FF_USE_LFN */
#if FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >= 2 || FF_USE_LABEL
#define DIR_READ_FILE(dp) dir_read(dp, 0)
#define DIR_READ_LABEL(dp) dir_read(dp, 1)
#if FF_USE_LFN
#endif
#if FF_USE_LFN		/* LFN configuration */
#else	/* Non LFN configuration */
#endif
#endif	/* FF_FS_MINIMIZE <= 1 || FF_USE_LABEL || FF_FS_RPATH >= 2 */
#if FF_USE_LFN
#endif
#if FF_USE_LFN
#endif
#if FF_USE_LFN		/* LFN configuration */
#else		/* Non LFN configuration */
#endif
#if !FF_FS_READONLY
#if FF_USE_LFN		/* LFN configuration */
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#else	/* Non LFN configuration */
#endif
#if FF_USE_LFN
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#endif /* !FF_FS_READONLY */
#if !FF_FS_READONLY && FF_FS_MINIMIZE == 0
#if FF_USE_LFN		/* LFN configuration */
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#else			/* Non LFN configuration */
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#endif
#endif /* !FF_FS_READONLY && FF_FS_MINIMIZE == 0 */
#if FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >= 2
#if FF_USE_LFN
#else
#endif
#if FF_USE_LFN		/* LFN configuration */
#if FF_LFN_UNICODE >= 1	/* Unicode output */
#else					/* ANSI/OEM output */
#endif
#else	/* Non-LFN configuration */
#endif
#if FF_USE_LFN != 0
#endif
#endif /* FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >= 2 */
#if FF_USE_FIND && FF_FS_MINIMIZE <= 1
#if FF_USE_LFN && FF_LFN_UNICODE >= 1	/* Unicode input */
#else									/* ANSI/OEM input */
#if FF_CODE_PAGE == 0
#elif FF_CODE_PAGE < 900
#endif
#if FF_CODE_PAGE == 0 || FF_CODE_PAGE >= 900
#endif
#endif
#endif /* FF_USE_FIND && FF_FS_MINIMIZE <= 1 */
#if FF_USE_LFN		/* LFN configuration */
#if FF_FS_RPATH != 0
#endif
#if FF_CODE_PAGE == 0
#elif FF_CODE_PAGE < 900	/* SBCS cfg */
#else						/* DBCS cfg */
#endif
#else	/* FF_USE_LFN : Non-LFN configuration */
#if FF_FS_RPATH != 0
#endif
#if FF_CODE_PAGE == 0
#elif FF_CODE_PAGE < 900
#endif
#endif /* FF_USE_LFN */
#if FF_FS_RPATH != 0
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#if FF_STR_VOLUME_ID		/* Find string volume ID */
#endif
#if FF_STR_VOLUME_ID == 1	/* Arbitrary string is enabled */
#endif
#if FF_STR_VOLUME_ID == 2		/* Unix style volume ID is enabled */
#endif
#if FF_FS_RPATH != 0
#else
#endif
#if FF_FS_REENTRANT
#endif
#if FF_MAX_SS != FF_MIN_SS				/* Get sector size (multiple sector size cfg only) */
#endif
#if !FF_FS_READONLY
#if (FF_FS_NOFSINFO & 3) != 3
#if (FF_FS_NOFSINFO & 1) == 0
#endif
#if (FF_FS_NOFSINFO & 2) == 0
#endif
#endif	/* (FF_FS_NOFSINFO & 3) != 3 */
#endif	/* !FF_FS_READONLY */
#if FF_USE_LFN == 1
#endif
#if FF_FS_RPATH != 0
#endif
#if FF_FS_LOCK != 0			/* Clear file lock semaphores */
#endif
#if FF_FS_REENTRANT
#else
#endif
#if FF_FS_LOCK != 0
#endif
#if FF_FS_REENTRANT						/* Discard sync object of the current volume */
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#if FF_FS_REENTRANT						/* Create sync object for the new volume */
#endif
#if !FF_FS_READONLY
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#if !FF_FS_READONLY	/* Read/Write configuration */
#if FF_FS_LOCK != 0
#endif
#if FF_FS_LOCK != 0
#else
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#if FF_FS_LOCK != 0
#endif
#else		/* R/O configuration */
#endif
#if FF_USE_FASTSEEK
#endif
#if !FF_FS_READONLY
#if !FF_FS_TINY
#endif
#if !FF_FS_TINY
#endif
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#if FF_USE_FASTSEEK
#endif
#if !FF_FS_READONLY && FF_FS_MINIMIZE <= 2		/* Replace one of the read sectors with cached data if it contains a dirty sector */
#if FF_FS_TINY
#else
#endif
#endif
#if !FF_FS_TINY
#if !FF_FS_READONLY
#endif
#endif
#if FF_FS_TINY
#else
#endif
#if !FF_FS_READONLY
#if FF_USE_FASTSEEK
#endif
#if FF_FS_TINY
#else
#endif
#if FF_FS_MINIMIZE <= 2
#if FF_FS_TINY
#else
#endif
#endif
#if FF_FS_TINY
#else
#endif
#if FF_FS_TINY
#else
#endif
#if !FF_FS_TINY
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#endif /* !FF_FS_READONLY */
#if !FF_FS_READONLY
#endif
#if FF_FS_LOCK != 0
#else
#endif
#if FF_FS_REENTRANT
#endif
#if FF_FS_RPATH >= 1
#if FF_STR_VOLUME_ID == 2
#endif
#if FF_STR_VOLUME_ID == 2	/* Also current drive is changed at Unix style volume ID */
#endif
#if FF_FS_RPATH >= 2
#if FF_VOLUMES >= 2
#endif
#if FF_STR_VOLUME_ID
#endif
#if FF_VOLUMES >= 2			/* Put drive prefix */
#if FF_STR_VOLUME_ID >= 1	/* String volume ID */
#else						/* Numeric volume ID */
#endif
#endif
#endif /* FF_FS_RPATH >= 2 */
#endif /* FF_FS_RPATH >= 1 */
#if FF_FS_MINIMIZE <= 2
#if FF_USE_FASTSEEK
#endif
#if FF_USE_FASTSEEK
#if !FF_FS_TINY
#if !FF_FS_READONLY
#endif
#endif
#endif
#if !FF_FS_READONLY
#endif
#if !FF_FS_READONLY
#endif
#if !FF_FS_TINY
#if !FF_FS_READONLY
#endif
#endif
#if FF_FS_MINIMIZE <= 1
#if FF_FS_LOCK != 0
#endif
#if FF_FS_LOCK != 0
#else
#endif
#if FF_FS_REENTRANT
#endif
#if FF_USE_FIND
#if FF_USE_LFN && FF_USE_FIND == 2
#endif
#endif	/* FF_USE_FIND */
#if FF_FS_MINIMIZE == 0
#if !FF_FS_READONLY
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#if !FF_FS_TINY
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#if FF_FS_LOCK != 0
#endif
#if FF_FS_RPATH != 0
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#if FF_FS_LOCK != 0
#endif
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#endif /* !FF_FS_READONLY */
#endif /* FF_FS_MINIMIZE == 0 */
#endif /* FF_FS_MINIMIZE <= 1 */
#endif /* FF_FS_MINIMIZE <= 2 */
#if FF_USE_CHMOD && !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#endif	/* FF_USE_CHMOD && !FF_FS_READONLY */
#if FF_USE_LABEL
#if FF_USE_LFN && FF_LFN_UNICODE >= 1 	/* Unicode output */
#else									/* ANSI/OEM output */
#endif
#if !FF_FS_READONLY
#if FF_USE_LFN
#endif
#if FF_USE_LFN
#else									/* ANSI/OEM input */
#if FF_CODE_PAGE == 0
#elif FF_CODE_PAGE < 900
#endif
#endif
#endif /* !FF_FS_READONLY */
#endif /* FF_USE_LABEL */
#if FF_USE_EXPAND && !FF_FS_READONLY
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#endif
#ifndef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#else
#endif
#endif /* FF_USE_EXPAND && !FF_FS_READONLY */
#if FF_USE_FORWARD
#if FF_FS_TINY
#else
#if !FF_FS_READONLY
#endif
#endif
#endif /* FF_USE_FORWARD */
#if FF_USE_MKFS && !FF_FS_READONLY
#if FF_MULTI_PARTITION
#endif
#if FF_USE_TRIM
#endif
#if FF_MAX_SS != FF_MIN_SS		/* Get sector size of the medium if variable sector size cfg. */
#else
#endif
#if FF_MULTI_PARTITION
#endif
#if FF_USE_TRIM
#endif
#if FF_MULTI_PARTITION
#endif
#if FF_MULTI_PARTITION
#endif
#if FF_MULTI_PARTITION
#if FF_USE_LFN == 3
#endif
#endif /* FF_MULTI_PARTITION */
#endif /* FF_USE_MKFS && !FF_FS_READONLY */
#if FF_USE_STRFUNC
#if FF_USE_LFN && FF_LFN_UNICODE && (FF_STRF_ENCODE < 0 || FF_STRF_ENCODE > 3)
#error Wrong FF_STRF_ENCODE setting
#endif
#if FF_USE_LFN && FF_LFN_UNICODE && FF_STRF_ENCODE <= 2
#endif
#if FF_USE_LFN && FF_LFN_UNICODE && FF_STRF_ENCODE == 3
#endif
#if FF_USE_LFN && FF_LFN_UNICODE			/* With code conversion (Unicode API) */
#if FF_STRF_ENCODE == 0		/* Read a character in ANSI/OEM */
#elif FF_STRF_ENCODE == 1 || FF_STRF_ENCODE == 2 	/* Read a character in UTF-16LE/BE */
#else	/* Read a character in UTF-8 */
#endif
#if FF_LFN_UNICODE == 1	|| FF_LFN_UNICODE == 3	/* Output it in UTF-16/32 encoding */
#elif FF_LFN_UNICODE == 2		/* Output it in UTF-8 encoding */
#endif
#else			/* Byte-by-byte without any conversion (ANSI/OEM API) */
#endif
#if !FF_FS_READONLY
#include <stdarg.h>
typedef struct {	/* Putchar output buffer and work area */
	FIL *fp;		/* Ptr to the writing file */
	int idx, nchr;	/* Write index of buf[] (-1:error), number of encoding units written */
#if FF_USE_LFN && FF_LFN_UNICODE == 1
	WCHAR hs;
#elif FF_USE_LFN && FF_LFN_UNICODE == 2
	BYTE bs[4];
	UINT wi, ct;
#endif
	BYTE buf[64];	/* Write buffer */
} putbuff;
#if FF_USE_LFN && FF_LFN_UNICODE
#if FF_LFN_UNICODE == 2
#endif
#endif
#if FF_USE_LFN && FF_LFN_UNICODE
#if FF_LFN_UNICODE == 1		/* UTF-16 input */
#elif FF_LFN_UNICODE == 2	/* UTF-8 input */
#elif FF_LFN_UNICODE == 3	/* UTF-32 input */
#endif
#if FF_STRF_ENCODE == 1		/* Write a character in UTF-16LE */
#elif FF_STRF_ENCODE == 2	/* Write a character in UTF-16BE */
#elif FF_STRF_ENCODE == 3	/* Write it in UTF-8 */
#else						/* Write it in ANSI/OEM */
#endif
#else									/* ANSI/OEM input (without re-encode) */
#endif
#endif /* !FF_FS_READONLY */
#endif /* FF_USE_STRFUNC */
#if !FF_FS_READONLY
#else
#endif
#if !FF_FS_READONLY
#else
#endif
#if FF_CODE_PAGE == 0
#endif	/* FF_CODE_PAGE == 0 */
