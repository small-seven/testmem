#include <common.h>
#include <eeprom.h>
#include <asm/ic/ssi.h>
#define EEP_OPC_ERASE	0x7  /* 3-bit opcode */
#define EEP_OPC_WRITE	0x5  /* 3-bit opcode */
#define EEP_OPC_READ	        0x6  /* 3-bit opcode */
#define EEP_OPC_ERASE_ALL	0x12 /* 5-bit opcode */
#define EEP_OPC_ERASE_EN	0x13 /* 5-bit opcode */
#define EEP_OPC_WRITE_ALL	0x11 /* 5-bit opcode */
#define EEP_OPC_ERASE_DIS	0x10 /* 5-bit opcode */
