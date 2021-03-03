#include "e_os.h"
#include <stdio.h>
#include <stdlib.h>
#include "crypto/ctype.h"
#include <string.h>
#include <openssl/asn1.h>
#include <openssl/ocsp.h>
#include <openssl/err.h>
#include <openssl/buffer.h>
#define OCSP_MAX_RESP_LENGTH    (100 * 1024)
#define OCSP_MAX_LINE_LEN       4096;
#define OHS_NOREAD              0x1000
#define OHS_ERROR               (0 | OHS_NOREAD)
#define OHS_FIRSTLINE           1
#define OHS_HEADERS             2
#define OHS_ASN1_HEADER         3
#define OHS_ASN1_CONTENT        4
#define OHS_ASN1_WRITE_INIT     (5 | OHS_NOREAD)
#define OHS_ASN1_WRITE          (6 | OHS_NOREAD)
#define OHS_ASN1_FLUSH          (7 | OHS_NOREAD)
#define OHS_DONE                (8 | OHS_NOREAD)
#define OHS_HTTP_HEADER         (9 | OHS_NOREAD)
void OCSP_REQ_CTX_free(OCSP_REQ_CTX *rctx)
{
    if (!rctx)
        return;
    BIO_free(rctx->mem);
    OPENSSL_free(rctx->iobuf);
    OPENSSL_free(rctx);
}
