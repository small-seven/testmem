#include <common.h>
#include <linux/libfdt.h>
#include <dm/of_access.h>
#include <linux/ctype.h>
#include <linux/err.h>
#include <linux/ioport.h>
#define __for_each_child_of_node(parent, child) \
#define for_each_property_of_node(dn, pp) \
