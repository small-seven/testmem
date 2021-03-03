#include "e_os.h"
#include <openssl/crypto.h>
#include <string.h>
#ifdef OPENSSL_SECURE_MEMORY
# include <stdlib.h>
# include <assert.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/mman.h>
# if defined(OPENSSL_SYS_LINUX)
#  include <sys/syscall.h>
#  if defined(SYS_mlock2)
#   include <linux/mman.h>
#   include <errno.h>
#  endif
# endif
# include <sys/param.h>
# include <sys/stat.h>
# include <fcntl.h>
#endif
#define CLEAR(p, s) OPENSSL_cleanse(p, s)
#ifndef PAGE_SIZE
# define PAGE_SIZE    4096
#endif
#if !defined(MAP_ANON) && defined(MAP_ANONYMOUS)
# define MAP_ANON MAP_ANONYMOUS
#endif
#ifdef OPENSSL_SECURE_MEMORY
#endif
#ifdef OPENSSL_SECURE_MEMORY
#else
#endif /* OPENSSL_SECURE_MEMORY */
#ifdef OPENSSL_SECURE_MEMORY
#endif /* OPENSSL_SECURE_MEMORY */
#ifdef OPENSSL_SECURE_MEMORY
#else
#endif /* OPENSSL_SECURE_MEMORY */
void *CRYPTO_secure_malloc(size_t num, const char *file, int line)
{
#ifdef OPENSSL_SECURE_MEMORY
    void *ret;
    size_t actual_size;

    if (!secure_mem_initialized) {
        return CRYPTO_malloc(num, file, line);
    }
    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    ret = sh_malloc(num);
    actual_size = ret ? sh_actual_size(ret) : 0;
    secure_mem_used += actual_size;
    CRYPTO_THREAD_unlock(sec_malloc_lock);
    return ret;
#else
    return CRYPTO_malloc(num, file, line);
#endif /* OPENSSL_SECURE_MEMORY */
}
void *CRYPTO_secure_zalloc(size_t num, const char *file, int line)
{
#ifdef OPENSSL_SECURE_MEMORY
    if (secure_mem_initialized)
        /* CRYPTO_secure_malloc() zeroes allocations when it is implemented */
        return CRYPTO_secure_malloc(num, file, line);
#endif
    return CRYPTO_zalloc(num, file, line);
}
void CRYPTO_secure_free(void *ptr, const char *file, int line)
{
#ifdef OPENSSL_SECURE_MEMORY
    size_t actual_size;

    if (ptr == NULL)
        return;
    if (!CRYPTO_secure_allocated(ptr)) {
        CRYPTO_free(ptr, file, line);
        return;
    }
    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    actual_size = sh_actual_size(ptr);
    CLEAR(ptr, actual_size);
    secure_mem_used -= actual_size;
    sh_free(ptr);
    CRYPTO_THREAD_unlock(sec_malloc_lock);
#else
    CRYPTO_free(ptr, file, line);
#endif /* OPENSSL_SECURE_MEMORY */
}
void CRYPTO_secure_clear_free(void *ptr, size_t num,
                              const char *file, int line)
{
#ifdef OPENSSL_SECURE_MEMORY
    size_t actual_size;

    if (ptr == NULL)
        return;
    if (!CRYPTO_secure_allocated(ptr)) {
        OPENSSL_cleanse(ptr, num);
        CRYPTO_free(ptr, file, line);
        return;
    }
    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    actual_size = sh_actual_size(ptr);
    CLEAR(ptr, actual_size);
    secure_mem_used -= actual_size;
    sh_free(ptr);
    CRYPTO_THREAD_unlock(sec_malloc_lock);
#else
    if (ptr == NULL)
        return;
    OPENSSL_cleanse(ptr, num);
    CRYPTO_free(ptr, file, line);
#endif /* OPENSSL_SECURE_MEMORY */
}
#ifdef OPENSSL_SECURE_MEMORY
#else
#endif /* OPENSSL_SECURE_MEMORY */
#ifdef OPENSSL_SECURE_MEMORY
#else
#endif /* OPENSSL_SECURE_MEMORY */
#ifdef OPENSSL_SECURE_MEMORY
#else
#endif
#ifdef OPENSSL_SECURE_MEMORY
#define ONE ((size_t)1)
# define TESTBIT(t, b)  (t[(b) >> 3] &  (ONE << ((b) & 7)))
# define SETBIT(t, b)   (t[(b) >> 3] |= (ONE << ((b) & 7)))
# define CLEARBIT(t, b) (t[(b) >> 3] &= (0xFF & ~(ONE << ((b) & 7))))
#define WITHIN_ARENA(p) \
#define WITHIN_FREELIST(p) \
typedef struct sh_list_st
{
    struct sh_list_st *next;
    struct sh_list_st **p_next;
} SH_LIST;
typedef struct sh_st
{
    char* map_result;
    size_t map_size;
    char *arena;
    size_t arena_size;
    char **freelist;
    ossl_ssize_t freelist_size;
    size_t minsize;
    unsigned char *bittable;
    unsigned char *bitmalloc;
    size_t bittable_size; /* size in bits */
} SH;
#if defined(_SC_PAGE_SIZE) || defined (_SC_PAGESIZE)
# if defined(_SC_PAGE_SIZE)
# else
# endif
#else
#endif
#ifdef MAP_ANON
#endif
#if defined(OPENSSL_SYS_LINUX) && defined(MLOCK_ONFAULT) && defined(SYS_mlock2)
#else
#endif
#ifdef MADV_DONTDUMP
#endif
static void *sh_malloc(size_t size)
{
    ossl_ssize_t list, slist;
    size_t i;
    char *chunk;

    if (size > sh.arena_size)
        return NULL;

    list = sh.freelist_size - 1;
    for (i = sh.minsize; i < size; i <<= 1)
        list--;
    if (list < 0)
        return NULL;

    /* try to find a larger entry to split */
    for (slist = list; slist >= 0; slist--)
        if (sh.freelist[slist] != NULL)
            break;
    if (slist < 0)
        return NULL;

    /* split larger entry */
    while (slist != list) {
        char *temp = sh.freelist[slist];

        /* remove from bigger list */
        OPENSSL_assert(!sh_testbit(temp, slist, sh.bitmalloc));
        sh_clearbit(temp, slist, sh.bittable);
        sh_remove_from_list(temp);
        OPENSSL_assert(temp != sh.freelist[slist]);

        /* done with bigger list */
        slist++;

        /* add to smaller list */
        OPENSSL_assert(!sh_testbit(temp, slist, sh.bitmalloc));
        sh_setbit(temp, slist, sh.bittable);
        sh_add_to_list(&sh.freelist[slist], temp);
        OPENSSL_assert(sh.freelist[slist] == temp);

        /* split in 2 */
        temp += sh.arena_size >> slist;
        OPENSSL_assert(!sh_testbit(temp, slist, sh.bitmalloc));
        sh_setbit(temp, slist, sh.bittable);
        sh_add_to_list(&sh.freelist[slist], temp);
        OPENSSL_assert(sh.freelist[slist] == temp);

        OPENSSL_assert(temp-(sh.arena_size >> slist) == sh_find_my_buddy(temp, slist));
    }

    /* peel off memory to hand back */
    chunk = sh.freelist[list];
    OPENSSL_assert(sh_testbit(chunk, list, sh.bittable));
    sh_setbit(chunk, list, sh.bitmalloc);
    sh_remove_from_list(chunk);

    OPENSSL_assert(WITHIN_ARENA(chunk));

    /* zero the free list header as a precaution against information leakage */
    memset(chunk, 0, sizeof(SH_LIST));

    return chunk;
}
static void sh_free(void *ptr)
{
    size_t list;
    void *buddy;

    if (ptr == NULL)
        return;
    OPENSSL_assert(WITHIN_ARENA(ptr));
    if (!WITHIN_ARENA(ptr))
        return;

    list = sh_getlist(ptr);
    OPENSSL_assert(sh_testbit(ptr, list, sh.bittable));
    sh_clearbit(ptr, list, sh.bitmalloc);
    sh_add_to_list(&sh.freelist[list], ptr);

    /* Try to coalesce two adjacent free areas. */
    while ((buddy = sh_find_my_buddy(ptr, list)) != NULL) {
        OPENSSL_assert(ptr == sh_find_my_buddy(buddy, list));
        OPENSSL_assert(ptr != NULL);
        OPENSSL_assert(!sh_testbit(ptr, list, sh.bitmalloc));
        sh_clearbit(ptr, list, sh.bittable);
        sh_remove_from_list(ptr);
        OPENSSL_assert(!sh_testbit(ptr, list, sh.bitmalloc));
        sh_clearbit(buddy, list, sh.bittable);
        sh_remove_from_list(buddy);

        list--;

        /* Zero the higher addressed block's free list pointers */
        memset(ptr > buddy ? ptr : buddy, 0, sizeof(SH_LIST));
        if (ptr > buddy)
            ptr = buddy;

        OPENSSL_assert(!sh_testbit(ptr, list, sh.bitmalloc));
        sh_setbit(ptr, list, sh.bittable);
        sh_add_to_list(&sh.freelist[list], ptr);
        OPENSSL_assert(sh.freelist[list] == ptr);
    }
}
#endif /* OPENSSL_SECURE_MEMORY */
