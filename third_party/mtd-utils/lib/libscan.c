#define PROGRAM_NAME "libscan"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <mtd_swab.h>
#include <mtd/ubi-media.h>
#include <mtd/mtd-user.h>
#include <libmtd.h>
#include <libscan.h>
#include <crc32.h>
#include "common.h"
void ubi_scan_free(struct ubi_scan_info *si)
{
	free(si->ec);
	free(si);
}
