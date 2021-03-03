#include "internal/cryptlib.h"
#include "packet_local.h"
#include <openssl/sslerr.h>
#define DEFAULT_BUF_SIZE    256
#define GETBUF(p)   (((p)->staticbuf != NULL) \
int WPACKET_memset(WPACKET *pkt, int ch, size_t len)
{
    unsigned char *dest;

    if (len == 0)
        return 1;

    if (!WPACKET_allocate_bytes(pkt, len, &dest))
        return 0;

    memset(dest, ch, len);

    return 1;
}
int WPACKET_memcpy(WPACKET *pkt, const void *src, size_t len)
{
    unsigned char *dest;

    if (len == 0)
        return 1;

    if (!WPACKET_allocate_bytes(pkt, len, &dest))
        return 0;

    memcpy(dest, src, len);

    return 1;
}
