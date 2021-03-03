#ifndef OPENSSL_NO_SRP
# include "internal/cryptlib.h"
# include "crypto/evp.h"
# include <openssl/sha.h>
# include <openssl/srp.h>
# include <openssl/evp.h>
# include <openssl/buffer.h>
# include <openssl/rand.h>
# include <openssl/txt_db.h>
# include <openssl/err.h>
# define SRP_RANDOM_SALT_LEN 20
# define MAX_LEN 2500
void SRP_user_pwd_free(SRP_user_pwd *user_pwd)
{
    if (user_pwd == NULL)
        return;
    BN_free(user_pwd->s);
    BN_clear_free(user_pwd->v);
    OPENSSL_free(user_pwd->id);
    OPENSSL_free(user_pwd->info);
    OPENSSL_free(user_pwd);
}
void SRP_VBASE_free(SRP_VBASE *vb)
{
    if (!vb)
        return;
    sk_SRP_user_pwd_pop_free(vb->users_pwd, SRP_user_pwd_free);
    sk_SRP_gN_cache_free(vb->gN_cache);
    OPENSSL_free(vb->seed_key);
    OPENSSL_free(vb);
}
static void SRP_gN_free(SRP_gN_cache *gN_cache)
{
    if (gN_cache == NULL)
        return;
    OPENSSL_free(gN_cache->b64_bn);
    BN_free(gN_cache->bn);
    OPENSSL_free(gN_cache);
}
# if OPENSSL_API_COMPAT < 0x10100000L
# endif
#endif
