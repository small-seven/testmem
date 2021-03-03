#include <common.h>
#include <handoff.h>
#include <init.h>
#include <asm/fsp/fsp_support.h>
#include <asm/e820.h>
#include <asm/mrccache.h>
#include <asm/post.h>
#ifdef CONFIG_HAVE_ACPI_RESUME
#endif
#if CONFIG_IS_ENABLED(HANDOFF) && IS_ENABLED(CONFIG_USE_HOB)
#endif
