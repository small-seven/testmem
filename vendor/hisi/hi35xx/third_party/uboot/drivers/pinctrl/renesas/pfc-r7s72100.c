#include <common.h>
#include <dm.h>
#include <dm/lists.h>
#include <dm/pinctrl.h>
#include <linux/io.h>
#include <linux/err.h>
#define P(bank)			(0x0000 + (bank) * 4)
#define PSR(bank)		(0x0100 + (bank) * 4)
#define PPR(bank)		(0x0200 + (bank) * 4)
#define PM(bank)		(0x0300 + (bank) * 4)
#define PMC(bank)		(0x0400 + (bank) * 4)
#define PFC(bank)		(0x0500 + (bank) * 4)
#define PFCE(bank)		(0x0600 + (bank) * 4)
#define PNOT(bank)		(0x0700 + (bank) * 4)
#define PMSR(bank)		(0x0800 + (bank) * 4)
#define PMCSR(bank)		(0x0900 + (bank) * 4)
#define PFCAE(bank)		(0x0A00 + (bank) * 4)
#define PIBC(bank)		(0x4000 + (bank) * 4)
#define PBDC(bank)		(0x4100 + (bank) * 4)
#define PIPC(bank)		(0x4200 + (bank) * 4)
#define RZA1_PINS_PER_PORT	16
