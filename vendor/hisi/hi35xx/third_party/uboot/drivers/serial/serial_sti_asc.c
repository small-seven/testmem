#include <common.h>
#include <dm.h>
#include <serial.h>
#include <asm/io.h>
#define BAUDMODE	0x00001000
#define RXENABLE	0x00000100
#define RUN		0x00000080
#define MODE		0x00000001
#define MODE_8BIT	0x0001
#define STOP_1BIT	0x0008
#define PARITYODD	0x0020
#define STA_TF		BIT(9)
#define STA_RBF		BIT(0)
#define PCLK			(200ul * 1000000ul)
#define BAUDRATE_VAL_M0(bps)	(PCLK / (16 * (bps)))
#define BAUDRATE_VAL_M1(bps)	((bps * (1 << 14)) + (1<<13)) / (PCLK/(1 << 6))
