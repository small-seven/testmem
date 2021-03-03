#include <common.h>
#include <console.h>
#include <bootretry.h>
#include <cli.h>
#include <command.h>
#include <console.h>
#include <hash.h>
#include <mapmem.h>
#include <watchdog.h>
#include <asm/io.h>
#include <linux/compiler.h>
#ifndef CONFIG_SYS_MEMTEST_SCRATCH
#define CONFIG_SYS_MEMTEST_SCRATCH 0
#endif
#define DISP_LINE_LEN	16
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#endif
#ifdef CONFIG_MX_CYCLIC
#endif /* CONFIG_MX_CYCLIC */
static int do_mem_cmp(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	ulong	addr1, addr2, count, ngood, bytes;
	int	size;
	int     rcode = 0;
	const char *type;
	const void *buf1, *buf2, *base;
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
	u64 word1, word2;
#else
	ulong word1, word2;
#endif

	if (argc != 4)
		return CMD_RET_USAGE;

	/* Check for size specification.
	*/
	if ((size = cmd_get_data_size(argv[0], 4)) < 0)
		return 1;
	type = size == 8 ? "double word" :
	       size == 4 ? "word" :
	       size == 2 ? "halfword" : "byte";

	addr1 = simple_strtoul(argv[1], NULL, 16);
	addr1 += base_address;

	addr2 = simple_strtoul(argv[2], NULL, 16);
	addr2 += base_address;

	count = simple_strtoul(argv[3], NULL, 16);

	bytes = size * count;
	base = buf1 = map_sysmem(addr1, bytes);
	buf2 = map_sysmem(addr2, bytes);
	for (ngood = 0; ngood < count; ++ngood) {
		if (size == 4) {
			word1 = *(u32 *)buf1;
			word2 = *(u32 *)buf2;
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
		} else if (size == 8) {
			word1 = *(u64 *)buf1;
			word2 = *(u64 *)buf2;
#endif
		} else if (size == 2) {
			word1 = *(u16 *)buf1;
			word2 = *(u16 *)buf2;
		} else {
			word1 = *(u8 *)buf1;
			word2 = *(u8 *)buf2;
		}
		if (word1 != word2) {
			ulong offset = buf1 - base;
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
			printf("%s at 0x%p (%#0*llx) != %s at 0x%p (%#0*llx)\n",
			       type, (void *)(addr1 + offset), size, word1,
			       type, (void *)(addr2 + offset), size, word2);
#else
			printf("%s at 0x%08lx (%#0*lx) != %s at 0x%08lx (%#0*lx)\n",
				type, (ulong)(addr1 + offset), size, word1,
				type, (ulong)(addr2 + offset), size, word2);
#endif
			rcode = 1;
			break;
		}

		buf1 += size;
		buf2 += size;

		/* reset watchdog from time to time */
		if ((ngood % (64 << 10)) == 0)
			WATCHDOG_RESET();
	}
	unmap_sysmem(buf1);
	unmap_sysmem(buf2);

	printf("Total of %ld %s(s) were the same\n", ngood, type);
	return rcode;
}
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#endif
#ifdef CONFIG_LOOPW
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#endif
#endif /* CONFIG_LOOPW */
#ifdef CONFIG_CMD_MEMTEST
#if defined(CONFIG_SYS_ALT_MEMTEST)
#else
#endif
#endif	/* CONFIG_CMD_MEMTEST */
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#endif
#ifdef CONFIG_BOOT_RETRY_TIME
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#endif
#ifdef CONFIG_CMD_CRC32
#ifdef CONFIG_CRC32_VERIFY
#endif
#endif
#ifdef CONFIG_CMD_RANDOM
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_CMD_CRC32
#ifndef CONFIG_CRC32_VERIFY
#else	/* CONFIG_CRC32_VERIFY */
#endif	/* CONFIG_CRC32_VERIFY */
#endif
#ifdef CONFIG_CMD_MEMINFO
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_LOOPW
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#endif /* CONFIG_LOOPW */
#ifdef CONFIG_CMD_MEMTEST
#endif	/* CONFIG_CMD_MEMTEST */
#ifdef CONFIG_MX_CYCLIC
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#ifdef CONFIG_SYS_SUPPORT_64BIT_DATA
#else
#endif
#endif /* CONFIG_MX_CYCLIC */
#ifdef CONFIG_CMD_MEMINFO
#endif
#ifdef CONFIG_CMD_RANDOM
#endif
