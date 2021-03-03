#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sg_include.h"
#include "sg_err.h"
#define OUTP stderr
#define COMMAND_SIZE(opcode) scsi_command_size[((opcode) >> 5) & 7]
#define group(opcode) (((opcode) >> 5) & 7)
#define RESERVED_GROUP  0
#define VENDOR_GROUP    1
#define D 0x0001		/* DIRECT ACCESS DEVICE (disk) [SBC-2: 0] */
#define T 0x0002		/* SEQUENTIAL ACCESS DEVICE (tape) [SSC: 1] */
#define L 0x0004		/* PRINTER DEVICE [SSC: 2] */
#define P 0x0008		/* PROCESSOR DEVICE [SPC-2: 3] */
#define W 0x0010		/* WRITE ONCE READ MULTIPLE DEVICE [SBC-2: 4] */
#define R 0x0020		/* CD/DVD DEVICE [MMC-2: 5] */
#define S 0x0040		/* SCANNER DEVICE [SCSI-2 (obsolete): 6] */
#define O 0x0080		/* OPTICAL MEMORY DEVICE [SBC-2: 7] */
#define M 0x0100		/* MEDIA CHANGER DEVICE [SMC-2: 8] */
#define C 0x0200		/* COMMUNICATION DEVICE [SCSI-2 (obsolete): 9] */
#define A 0x0400		/* ARRAY STORAGE [SCC-2: 12] */
#define E 0x0800		/* ENCLOSURE SERVICES DEVICE [SES: 13] */
#define B 0x1000		/* SIMPLIFIED DIRECT ACCESS DEVICE [RBC: 14] */
#define K 0x2000		/* OPTICAL CARD READER/WRITER DEVICE [OCRW: 15] */
#define SC_ALL_DEVS ( D|T|L|P|W|R|S|O|M|C|A|E|B|K )
#define SC_AUDIO_PLAY_OPERATION "\x1"
#define SC_LOGICAL_UNIT "\x2"
#define SC_NOT_READY "\x3"
#define SC_OPERATION "\x4"
#define SC_IN_PROGRESS "\x5"
#define SC_HARDWARE_IF "\x6"
#define SC_CONTROLLER_IF "\x7"
#define SC_DATA_CHANNEL_IF "\x8"
#define SC_SERVO_IF "\x9"
#define SC_SPINDLE_IF "\xa"
#define SC_FIRMWARE_IF "\xb"
#define SC_RECOVERED_DATA "\xc"
#define SC_ERROR_RATE_TOO_HIGH "\xd"
#define SC_TIMES_TOO_HIGH "\xe"
#ifdef SG_IO
#endif
#ifdef SG_IO
#endif
