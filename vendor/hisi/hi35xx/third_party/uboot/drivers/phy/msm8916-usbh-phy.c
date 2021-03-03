#include <common.h>
#include <dm.h>
#include <generic-phy.h>
#include <usb/ehci-ci.h>
#include <usb/ulpi.h>
#include <asm/io.h>
#define ULPI_MISC_A_READ		0x96
#define ULPI_MISC_A_SET			0x97
#define ULPI_MISC_A_CLEAR		0x98
#define ULPI_MISC_A_VBUSVLDEXT		BIT(0)
#define ULPI_MISC_A_VBUSVLDEXTSEL	BIT(1)
#define GEN2_SESS_VLD_CTRL_EN		BIT(7)
#define SESS_VLD_CTRL			BIT(25)
