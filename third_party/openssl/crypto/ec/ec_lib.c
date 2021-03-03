#include <string.h>
#include <openssl/err.h>
#include <openssl/opensslv.h>
#include "ec_local.h"
void EC_pre_comp_free(EC_GROUP *group)
{
    switch (group->pre_comp_type) {
    case PCT_none:
        break;
    case PCT_nistz256:
#ifdef ECP_NISTZ256_ASM
        EC_nistz256_pre_comp_free(group->pre_comp.nistz256);
#endif
        break;
#ifndef OPENSSL_NO_EC_NISTP_64_GCC_128
    case PCT_nistp224:
        EC_nistp224_pre_comp_free(group->pre_comp.nistp224);
        break;
    case PCT_nistp256:
        EC_nistp256_pre_comp_free(group->pre_comp.nistp256);
        break;
    case PCT_nistp521:
        EC_nistp521_pre_comp_free(group->pre_comp.nistp521);
        break;
#else
    case PCT_nistp224:
    case PCT_nistp256:
    case PCT_nistp521:
        break;
#endif
    case PCT_ec:
        EC_ec_pre_comp_free(group->pre_comp.ec);
        break;
    }
    group->pre_comp.ec = NULL;
}
void EC_GROUP_free(EC_GROUP *group)
{
    if (!group)
        return;

    if (group->meth->group_finish != 0)
        group->meth->group_finish(group);

    EC_pre_comp_free(group);
    BN_MONT_CTX_free(group->mont_data);
    EC_POINT_free(group->generator);
    BN_free(group->order);
    BN_free(group->cofactor);
    OPENSSL_free(group->seed);
    OPENSSL_free(group);
}
void EC_GROUP_clear_free(EC_GROUP *group)
{
    if (!group)
        return;

    if (group->meth->group_clear_finish != 0)
        group->meth->group_clear_finish(group);
    else if (group->meth->group_finish != 0)
        group->meth->group_finish(group);

    EC_pre_comp_free(group);
    BN_MONT_CTX_free(group->mont_data);
    EC_POINT_clear_free(group->generator);
    BN_clear_free(group->order);
    BN_clear_free(group->cofactor);
    OPENSSL_clear_free(group->seed, group->seed_len);
    OPENSSL_clear_free(group, sizeof(*group));
}
#ifdef ECP_NISTZ256_ASM
#endif
#ifndef OPENSSL_NO_EC_NISTP_64_GCC_128
#else
#endif
#if OPENSSL_API_COMPAT < 0x10200000L
# ifndef OPENSSL_NO_EC2M
# endif
#endif
void EC_POINT_free(EC_POINT *point)
{
    if (!point)
        return;

    if (point->meth->point_finish != 0)
        point->meth->point_finish(point);
    OPENSSL_free(point);
}
void EC_POINT_clear_free(EC_POINT *point)
{
    if (!point)
        return;

    if (point->meth->point_clear_finish != 0)
        point->meth->point_clear_finish(point);
    else if (point->meth->point_finish != 0)
        point->meth->point_finish(point);
    OPENSSL_clear_free(point, sizeof(*point));
}
#if OPENSSL_API_COMPAT < 0x10200000L
# ifndef OPENSSL_NO_EC2M
# endif
#endif
#if OPENSSL_API_COMPAT < 0x10200000L
# ifndef OPENSSL_NO_EC2M
# endif
#endif
