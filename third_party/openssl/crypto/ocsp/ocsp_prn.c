#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/ocsp.h>
#include "ocsp_local.h"
#include "internal/cryptlib.h"
#include <openssl/pem.h>
typedef struct {
    long t;
    const char *m;
} OCSP_TBLSTR;
#define table2string(s, tbl) do_table2string(s, tbl, OSSL_NELEM(tbl))
