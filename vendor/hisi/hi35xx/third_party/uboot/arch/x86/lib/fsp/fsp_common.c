#include <common.h>
#include <acpi_s3.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <rtc.h>
#include <asm/cmos_layout.h>
#include <asm/early_cmos.h>
#include <asm/io.h>
#include <asm/mrccache.h>
#include <asm/post.h>
#include <asm/processor.h>
#include <asm/fsp/fsp_support.h>
#ifdef CONFIG_HAVE_ACPI_RESUME
#endif
