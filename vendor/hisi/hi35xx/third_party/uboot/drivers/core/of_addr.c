#include <common.h>
#include <linux/libfdt.h>
#include <dm/of_access.h>
#include <dm/of_addr.h>
#include <linux/err.h>
#include <linux/ioport.h>
#define OF_MAX_ADDR_CELLS	4
#define OF_CHECK_ADDR_COUNT(na)	((na) > 0 && (na) <= OF_MAX_ADDR_CELLS)
#define OF_CHECK_COUNTS(na, ns)	(OF_CHECK_ADDR_COUNT(na) && (ns) > 0)
#ifdef DEBUG
#else
#endif
