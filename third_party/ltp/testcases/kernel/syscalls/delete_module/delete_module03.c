#include <errno.h>
#include "tst_test.h"
#include "old_module.h"
#include "lapi/syscalls.h"
#define DUMMY_MOD		"dummy_del_mod"
#define DUMMY_MOD_KO		"dummy_del_mod.ko"
#define DUMMY_MOD_DEP_KO	"dummy_del_mod_dep.ko"
