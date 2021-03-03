#include "tst_test.h"
#include "lapi/fsmount.h"
#define MNTPOINT	"mntpoint"
#define TCASE_ENTRY(_flags, _attrs)	{.name = "Flag " #_flags ", Attr " #_attrs, .flags = _flags, .attrs = _attrs}
