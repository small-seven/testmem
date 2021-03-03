#include <string.h>
#include <openssl/buffer.h>
#ifdef __VMS
# pragma names save
# pragma names as_is,shortened
#endif
#include "../ssl/packet_local.h"
#ifdef __VMS
# pragma names restore
#endif
#include "testutil.h"
static int test_WPACKET_memcpy(void)
{
    WPACKET pkt;
    size_t written;
    const unsigned char bytes[] = { 0xfe, 0xff };

    if (!TEST_true(WPACKET_init_len(&pkt, buf, 1))
            || !TEST_true(WPACKET_memcpy(&pkt, bytes, sizeof(bytes)))
            || !TEST_true(WPACKET_finish(&pkt))
            || !TEST_true(WPACKET_get_total_written(&pkt, &written))
            || !TEST_mem_eq(buf->data, written, alloc, sizeof(alloc)))
        return cleanup(&pkt);

    /* Repeat with WPACKET_sub_memcpy() */
    if (!TEST_true(WPACKET_init_len(&pkt, buf, 1))
            || !TEST_true(WPACKET_sub_memcpy_u8(&pkt, bytes, sizeof(bytes)))
            || !TEST_true(WPACKET_finish(&pkt))
            || !TEST_true(WPACKET_get_total_written(&pkt, &written))
            || !TEST_mem_eq(buf->data, written, submem, sizeof(submem)))
        return cleanup(&pkt);

    return 1;
}
