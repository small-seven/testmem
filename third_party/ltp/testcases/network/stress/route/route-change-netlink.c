#include "config.h"
#include "tst_test.h"
#ifdef HAVE_LIBMNL
#include <string.h>
#include <libmnl/libmnl.h>
#include <linux/rtnetlink.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include "tst_net.h"
#include "tst_safe_net.h"
#include "tst_safe_stdio.h"
#define IP_ADDR_DELIM ','
#define STR(x) #x
#define CHR2STR(x) STR(x)
#else
#endif /* HAVE_LIBMNL */
