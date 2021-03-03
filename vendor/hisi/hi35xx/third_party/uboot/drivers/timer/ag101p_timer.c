#include <common.h>
#include <dm.h>
#include <errno.h>
#include <timer.h>
#include <linux/io.h>
#define T3_UPDOWN	(1 << 11)
#define T2_UPDOWN	(1 << 10)
#define T1_UPDOWN	(1 << 9)
#define T3_OFENABLE	(1 << 8)
#define T3_CLOCK	(1 << 7)
#define T3_ENABLE	(1 << 6)
#define T2_OFENABLE	(1 << 5)
#define T2_CLOCK	(1 << 4)
#define T2_ENABLE	(1 << 3)
#define T1_OFENABLE	(1 << 2)
#define T1_CLOCK	(1 << 1)
#define T1_ENABLE	(1 << 0)
#define T3_OVERFLOW	(1 << 8)
#define T3_MATCH2	(1 << 7)
#define T3_MATCH1	(1 << 6)
#define T2_OVERFLOW	(1 << 5)
#define T2_MATCH2	(1 << 4)
#define T2_MATCH1	(1 << 3)
#define T1_OVERFLOW	(1 << 2)
#define T1_MATCH2	(1 << 1)
#define T1_MATCH1	(1 << 0)
