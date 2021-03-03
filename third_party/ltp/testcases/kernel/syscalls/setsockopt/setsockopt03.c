#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <limits.h>
#include <linux/netfilter_ipv4/ip_tables.h>
#include "tst_test.h"
#include "tst_safe_net.h"
#include "tst_kernel.h"
#define TOO_SMALL_OFFSET 74
#define OFFSET_OVERWRITE 0xFFFF
#define NEXT_OFFSET (sizeof(struct ipt_entry)		\
#define PADDING (OFFSET_OVERWRITE - NEXT_OFFSET)
#ifndef HAVE_STRUCT_XT_ENTRY_MATCH
#endif
#ifndef HAVE_STRUCT_XT_ENTRY_TARGET
#endif
