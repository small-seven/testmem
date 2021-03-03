#include <common.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/pci.h>
#include <asm/io.h>
#define SH7780_VENDOR_ID	0x1912
#define SH7780_DEVICE_ID	0x0002
#define SH7780_PCICR_PREFIX	0xA5000000
#define SH7780_PCICR_PFCS	0x00000800
#define SH7780_PCICR_FTO	0x00000400
#define SH7780_PCICR_PFE	0x00000200
#define SH7780_PCICR_TBS	0x00000100
#define SH7780_PCICR_ARBM	0x00000040
#define SH7780_PCICR_IOCS	0x00000004
#define SH7780_PCICR_PRST	0x00000002
#define SH7780_PCICR_CFIN	0x00000001
#define p4_in(addr)			(*(vu_long *)addr)
#define p4_out(data, addr)	(*(vu_long *)addr) = (data)
#define p4_inw(addr)		(*(vu_short *)addr)
#define p4_outw(data, addr)	(*(vu_short *)addr) = (data)
