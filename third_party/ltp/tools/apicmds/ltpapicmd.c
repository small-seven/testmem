#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "test.h"
#include "usctest.h"
#include "safe_macros.h"
int apicmd_fs_has_free(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: tst_fs_has_free path required_bytes\n"
			"path: the pathname of the mounted filesystem\n"
			"required_bytes: the required free space"
			" (supports kB, MB and GB suffixes)\n");
		exit(2);
	}

	char *endptr;
	unsigned int required_kib = strtoull(argv[1], &endptr, 0);
	unsigned int mul = TST_BYTES;

	if (*argv[1] == '\0')
		goto fs_has_free_err;

	if (*endptr != '\0') {
		if (!strcasecmp(endptr, "kB")) {
			mul = TST_KB;
		} else if (!strcasecmp(endptr, "MB")) {
			mul = TST_MB;
		} else if (!strcasecmp(endptr, "GB")) {
			mul = TST_GB;
		} else {
			goto fs_has_free_err;
		}
	}

	exit(!tst_fs_has_free(NULL, argv[0], required_kib, mul));

fs_has_free_err:
	fprintf(stderr, "%s is not a valid size\n", argv[1]);
	exit(2);
}
