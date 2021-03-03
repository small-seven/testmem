#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "internal/cryptlib.h"
#include "internal/thread_once.h"
#include <openssl/crypto.h>
#include <openssl/buffer.h>
#include "internal/bio.h"
#include <openssl/lhash.h>
#ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
# include <execinfo.h>
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
#ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
#endif
static void app_info_free(APP_INFO *inf)
{
    if (inf == NULL)
        return;
    if (--(inf->references) <= 0) {
        app_info_free(inf->next);
        OPENSSL_free(inf);
    }
}
#endif
#ifdef OPENSSL_NO_CRYPTO_MDEBUG
#else
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
static int mem_cmp(const MEM *a, const MEM *b)
{
#ifdef _WIN64
    const char *ap = (const char *)a->addr, *bp = (const char *)b->addr;
    if (ap == bp)
        return 0;
    else if (ap > bp)
        return 1;
    else
        return -1;
#else
    return (const char *)a->addr - (const char *)b->addr;
#endif
}
void CRYPTO_mem_debug_malloc(void *addr, size_t num, int before_p,
                             const char *file, int line)
{
    MEM *m, *mm;
    APP_INFO *amim;

    switch (before_p & 127) {
    case 0:
        break;
    case 1:
        if (addr == NULL)
            break;

        if (mem_check_on()) {
            CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);

            if (!RUN_ONCE(&memdbg_init, do_memdbg_init)
                || (m = OPENSSL_malloc(sizeof(*m))) == NULL) {
                OPENSSL_free(addr);
                CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
                return;
            }
            if (mh == NULL) {
                if ((mh = lh_MEM_new(mem_hash, mem_cmp)) == NULL) {
                    OPENSSL_free(addr);
                    OPENSSL_free(m);
                    addr = NULL;
                    goto err;
                }
            }

            m->addr = addr;
            m->file = file;
            m->line = line;
            m->num = num;
            m->threadid = CRYPTO_THREAD_get_current_id();

            if (order == break_order_num) {
                /* BREAK HERE */
                m->order = order;
            }
            m->order = order++;
# ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
            m->array_siz = backtrace(m->array, OSSL_NELEM(m->array));
# endif
            m->time = time(NULL);

            amim = (APP_INFO *)CRYPTO_THREAD_get_local(&appinfokey);
            m->app_info = amim;
            if (amim != NULL)
                amim->references++;

            if ((mm = lh_MEM_insert(mh, m)) != NULL) {
                /* Not good, but don't sweat it */
                if (mm->app_info != NULL) {
                    mm->app_info->references--;
                }
                OPENSSL_free(mm);
            }
 err:
            CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
        }
        break;
    }
    return;
}
void CRYPTO_mem_debug_free(void *addr, int before_p,
        const char *file, int line)
{
    MEM m, *mp;

    switch (before_p) {
    case 0:
        if (addr == NULL)
            break;

        if (mem_check_on() && (mh != NULL)) {
            CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);

            m.addr = addr;
            mp = lh_MEM_delete(mh, &m);
            if (mp != NULL) {
                app_info_free(mp->app_info);
                OPENSSL_free(mp);
            }

            CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
        }
        break;
    case 1:
        break;
    }
}
void CRYPTO_mem_debug_realloc(void *addr1, void *addr2, size_t num,
                              int before_p, const char *file, int line)
{
    MEM m, *mp;

    switch (before_p) {
    case 0:
        break;
    case 1:
        if (addr2 == NULL)
            break;

        if (addr1 == NULL) {
            CRYPTO_mem_debug_malloc(addr2, num, 128 | before_p, file, line);
            break;
        }

        if (mem_check_on()) {
            CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);

            m.addr = addr1;
            mp = lh_MEM_delete(mh, &m);
            if (mp != NULL) {
                mp->addr = addr2;
                mp->num = num;
#ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
                mp->array_siz = backtrace(mp->array, OSSL_NELEM(mp->array));
#endif
                (void)lh_MEM_insert(mh, mp);
            }

            CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
        }
        break;
    }
    return;
}
typedef struct mem_leak_st {
    int (*print_cb) (const char *str, size_t len, void *u);
    void *print_cb_arg;
    int chunks;
    long bytes;
} MEM_LEAK;
#ifndef OPENSSL_NO_CRYPTO_MDEBUG_BACKTRACE
#endif
# ifndef OPENSSL_NO_STDIO
# endif
#endif
