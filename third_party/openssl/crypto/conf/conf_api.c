#include "e_os.h"
#include "internal/cryptlib.h"
#include <stdlib.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/conf_api.h>
typedef LHASH_OF(CONF_VALUE) LH_CONF_VALUE;

IMPLEMENT_LHASH_DOALL_ARG_CONST(CONF_VALUE, LH_CONF_VALUE);

void _CONF_free_data(CONF *conf)
{
    if (conf == NULL || conf->data == NULL)
        return;

    /* evil thing to make sure the 'OPENSSL_free()' works as expected */
    lh_CONF_VALUE_set_down_load(conf->data, 0);
    lh_CONF_VALUE_doall_LH_CONF_VALUE(conf->data, value_free_hash, conf->data);

    /*
     * We now have only 'section' entries in the hash table. Due to problems
     * with
     */

    lh_CONF_VALUE_doall(conf->data, value_free_stack_doall);
    lh_CONF_VALUE_free(conf->data);
}
