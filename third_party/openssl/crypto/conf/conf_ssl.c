#include <stdio.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include "internal/sslconf.h"
#include "conf_local.h"
static void ssl_module_free(CONF_IMODULE *md)
{
    size_t i, j;
    if (ssl_names == NULL)
        return;
    for (i = 0; i < ssl_names_count; i++) {
        struct ssl_conf_name_st *tname = ssl_names + i;

        OPENSSL_free(tname->name);
        for (j = 0; j < tname->cmd_count; j++) {
            OPENSSL_free(tname->cmds[j].cmd);
            OPENSSL_free(tname->cmds[j].arg);
        }
        OPENSSL_free(tname->cmds);
    }
    OPENSSL_free(ssl_names);
    ssl_names = NULL;
    ssl_names_count = 0;
}
