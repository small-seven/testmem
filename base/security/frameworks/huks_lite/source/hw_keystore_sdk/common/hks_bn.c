#include "hks_bn.h"
void hks_bn_free(mbedtls_mpi *bn)
{
    mbedtls_mpi_free(bn);
}
