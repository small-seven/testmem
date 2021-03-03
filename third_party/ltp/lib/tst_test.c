#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/wait.h>
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#include "tst_device.h"
#include "lapi/futex.h"
#include "lapi/syscalls.h"
#include "tst_ansi_color.h"
#include "tst_safe_stdio.h"
#include "tst_timer_test.h"
#include "tst_clocks.h"
#include "tst_timer.h"
#include "tst_wallclock.h"
#include "tst_sys_conf.h"
#include "tst_kconfig.h"
#include "old_resource.h"
#include "old_device.h"
#include "old_tmpdir.h"
#define LINUX_GIT_URL "https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id="
#define CVE_DB_URL "https://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-"
#define IPC_ENV_VAR "LTP_IPC_PATH"
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#endif
#define WRITE_MSG(msg) do { \
