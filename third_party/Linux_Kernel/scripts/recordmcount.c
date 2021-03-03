#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <getopt.h>
#include <elf.h>
#include <fcntl.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifndef EM_METAG
#define EM_METAG      174
#define R_METAG_ADDR32                   2
#define R_METAG_NONE                     3
#endif
#ifndef EM_AARCH64
#define EM_AARCH64	183
#define R_AARCH64_NONE		0
#define R_AARCH64_ABS64	257
#endif
umalloc(size_t size)
{
	void *const addr = malloc(size);
	if (addr == 0) {
		fprintf(stderr, "malloc failed: %zu bytes\n", size);
		fail_file();
	}
	return addr;
}
#include "recordmcount.h"
#define RECORD_MCOUNT_64
#include "recordmcount.h"
 *	typedef unsigned char Elf64_Byte;
 * fails on MIPS64 because their <elf.h> already has it!
 */

typedef uint8_t myElf64_Byte;		/* Type for a 8-bit quantity.  */

union mips_r_info {
	Elf64_Xword r_info;
	struct {
		Elf64_Word r_sym;		/* Symbol index.  */
		myElf64_Byte r_ssym;		/* Special symbol.  */
		myElf64_Byte r_type3;		/* Third relocation.  */
		myElf64_Byte r_type2;		/* Second relocation.  */
		myElf64_Byte r_type;		/* First relocation.  */
	} r_mips;
