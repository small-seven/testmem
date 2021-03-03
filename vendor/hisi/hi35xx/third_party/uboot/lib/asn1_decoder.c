#ifdef __UBOOT__
#include <linux/compat.h>
#else
#include <linux/export.h>
#endif
#include <linux/kernel.h>
#include <linux/errno.h>
#ifndef __UBOOT__
#include <linux/module.h>
#endif
#include <linux/asn1_decoder.h>
#include <linux/asn1_ber_bytecode.h>
#define FLAG_INDEFINITE_LENGTH	0x01
#define FLAG_MATCHED		0x02
#define FLAG_LAST_MATCHED	0x04 /* Last tag matched */
#define FLAG_CONS		0x20 /* Corresponds to CONS bit in the opcode tag
#define NR_CONS_STACK 10
#define NR_JUMP_STACK 10
