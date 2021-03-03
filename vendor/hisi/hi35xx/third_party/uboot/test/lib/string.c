#include <common.h>
#include <command.h>
#include <test/lib.h>
#include <test/test.h>
#include <test/ut.h>
#define MASK 0xA5
#define SWEEP 16
#define BUFLEN (SWEEP + 33)
static int test_memset(struct unit_test_state *uts, u8 buf[], u8 mask,
		       int offset, int len)
{
	int i;

	for (i = 0; i < BUFLEN; ++i) {
		if (i < offset || i >= offset + len) {
			ut_asserteq(i, buf[i]);
		} else {
			ut_asserteq(mask, buf[i]);
		}
	}
	return 0;
}
static int lib_memset(struct unit_test_state *uts)
{
	u8 buf[BUFLEN];
	int offset, len;
	void *ptr;

	for (offset = 0; offset <= SWEEP; ++offset) {
		for (len = 1; len < BUFLEN - SWEEP; ++len) {
			init_buffer(buf, 0);
			ptr = memset(buf + offset, MASK, len);
			ut_asserteq_ptr(buf + offset, (u8 *)ptr);
			if (test_memset(uts, buf, MASK, offset, len)) {
				debug("%s: failure %d, %d\n",
				      __func__, offset, len);
				return CMD_RET_FAILURE;
			}
		}
	}
	return 0;
}
static int test_memmove(struct unit_test_state *uts, u8 buf[], u8 mask,
			int offset1, int offset2, int len)
{
	int i;

	for (i = 0; i < BUFLEN; ++i) {
		if (i < offset2 || i >= offset2 + len) {
			ut_asserteq(i, buf[i]);
		} else {
			ut_asserteq((i + offset1 - offset2) ^ mask, buf[i]);
		}
	}
	return 0;
}
static int lib_memcpy(struct unit_test_state *uts)
{
	u8 buf1[BUFLEN];
	u8 buf2[BUFLEN];
	int offset1, offset2, len;
	void *ptr;

	init_buffer(buf1, MASK);

	for (offset1 = 0; offset1 <= SWEEP; ++offset1) {
		for (offset2 = 0; offset2 <= SWEEP; ++offset2) {
			for (len = 1; len < BUFLEN - SWEEP; ++len) {
				init_buffer(buf2, 0);
				ptr = memcpy(buf2 + offset2, buf1 + offset1,
					     len);
				ut_asserteq_ptr(buf2 + offset2, (u8 *)ptr);
				if (test_memmove(uts, buf2, MASK, offset1,
						 offset2, len)) {
					debug("%s: failure %d, %d, %d\n",
					      __func__, offset1, offset2, len);
					return CMD_RET_FAILURE;
				}
			}
		}
	}
	return 0;
}
static int lib_memmove(struct unit_test_state *uts)
{
	u8 buf[BUFLEN];
	int offset1, offset2, len;
	void *ptr;

	for (offset1 = 0; offset1 <= SWEEP; ++offset1) {
		for (offset2 = 0; offset2 <= SWEEP; ++offset2) {
			for (len = 1; len < BUFLEN - SWEEP; ++len) {
				init_buffer(buf, 0);
				ptr = memmove(buf + offset2, buf + offset1,
					      len);
				ut_asserteq_ptr(buf + offset2, (u8 *)ptr);
				if (test_memmove(uts, buf, 0, offset1, offset2,
						 len)) {
					debug("%s: failure %d, %d, %d\n",
					      __func__, offset1, offset2, len);
					return CMD_RET_FAILURE;
				}
			}
		}
	}
	return 0;
}
