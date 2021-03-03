#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#include "mbedtls/memory_buffer_alloc.h"
#include "mbedtls/platform.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_MEMORY_BACKTRACE)
#include <execinfo.h>
#endif
#if defined(MBEDTLS_THREADING_C)
#include "mbedtls/threading.h"
#endif
#define MAGIC1       0xFF00AA55
#define MAGIC2       0xEE119966
#define MAX_BT 20
typedef struct _memory_header memory_header;
struct _memory_header
{
    size_t          magic1;
    size_t          size;
    size_t          alloc;
    memory_header   *prev;
    memory_header   *next;
    memory_header   *prev_free;
    memory_header   *next_free;
#if defined(MBEDTLS_MEMORY_BACKTRACE)
    char            **trace;
    size_t          trace_count;
#endif
    size_t          magic2;
};
typedef struct
{
    unsigned char   *buf;
    size_t          len;
    memory_header   *first;
    memory_header   *first_free;
    int             verify;
#if defined(MBEDTLS_MEMORY_DEBUG)
    size_t          alloc_count;
    size_t          free_count;
    size_t          total_used;
    size_t          maximum_used;
    size_t          header_count;
    size_t          maximum_header_count;
#endif
#if defined(MBEDTLS_THREADING_C)
    mbedtls_threading_mutex_t   mutex;
#endif
}
#if defined(MBEDTLS_MEMORY_DEBUG)
#if defined(MBEDTLS_MEMORY_BACKTRACE)
#endif
#if defined(MBEDTLS_MEMORY_BACKTRACE)
#endif
#endif /* MBEDTLS_MEMORY_DEBUG */
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
static void *buffer_alloc_calloc( size_t n, size_t size )
{
    memory_header *new, *cur = heap.first_free;
    unsigned char *p;
    void *ret;
    size_t original_len, len;
#if defined(MBEDTLS_MEMORY_BACKTRACE)
    void *trace_buffer[MAX_BT];
    size_t trace_cnt;
#endif

    if( heap.buf == NULL || heap.first == NULL )
        return( NULL );

    original_len = len = n * size;

    if( n == 0 || size == 0 || len / n != size )
        return( NULL );
    else if( len > (size_t)-MBEDTLS_MEMORY_ALIGN_MULTIPLE )
        return( NULL );

    if( len % MBEDTLS_MEMORY_ALIGN_MULTIPLE )
    {
        len -= len % MBEDTLS_MEMORY_ALIGN_MULTIPLE;
        len += MBEDTLS_MEMORY_ALIGN_MULTIPLE;
    }

    // Find block that fits
    //
    while( cur != NULL )
    {
        if( cur->size >= len )
            break;

        cur = cur->next_free;
    }

    if( cur == NULL )
        return( NULL );

    if( cur->alloc != 0 )
    {
#if defined(MBEDTLS_MEMORY_DEBUG)
        mbedtls_fprintf( stderr, "FATAL: block in free_list but allocated "
                                  "data\n" );
#endif
        mbedtls_exit( 1 );
    }

#if defined(MBEDTLS_MEMORY_DEBUG)
    heap.alloc_count++;
#endif

    // Found location, split block if > memory_header + 4 room left
    //
    if( cur->size - len < sizeof(memory_header) +
                          MBEDTLS_MEMORY_ALIGN_MULTIPLE )
    {
        cur->alloc = 1;

        // Remove from free_list
        //
        if( cur->prev_free != NULL )
            cur->prev_free->next_free = cur->next_free;
        else
            heap.first_free = cur->next_free;

        if( cur->next_free != NULL )
            cur->next_free->prev_free = cur->prev_free;

        cur->prev_free = NULL;
        cur->next_free = NULL;

#if defined(MBEDTLS_MEMORY_DEBUG)
        heap.total_used += cur->size;
        if( heap.total_used > heap.maximum_used )
            heap.maximum_used = heap.total_used;
#endif
#if defined(MBEDTLS_MEMORY_BACKTRACE)
        trace_cnt = backtrace( trace_buffer, MAX_BT );
        cur->trace = backtrace_symbols( trace_buffer, trace_cnt );
        cur->trace_count = trace_cnt;
#endif

        if( ( heap.verify & MBEDTLS_MEMORY_VERIFY_ALLOC ) && verify_chain() != 0 )
            mbedtls_exit( 1 );

        ret = (unsigned char *) cur + sizeof( memory_header );
        memset( ret, 0, original_len );

        return( ret );
    }

    p = ( (unsigned char *) cur ) + sizeof(memory_header) + len;
    new = (memory_header *) p;

    new->size = cur->size - len - sizeof(memory_header);
    new->alloc = 0;
    new->prev = cur;
    new->next = cur->next;
#if defined(MBEDTLS_MEMORY_BACKTRACE)
    new->trace = NULL;
    new->trace_count = 0;
#endif
    new->magic1 = MAGIC1;
    new->magic2 = MAGIC2;

    if( new->next != NULL )
        new->next->prev = new;

    // Replace cur with new in free_list
    //
    new->prev_free = cur->prev_free;
    new->next_free = cur->next_free;
    if( new->prev_free != NULL )
        new->prev_free->next_free = new;
    else
        heap.first_free = new;

    if( new->next_free != NULL )
        new->next_free->prev_free = new;

    cur->alloc = 1;
    cur->size = len;
    cur->next = new;
    cur->prev_free = NULL;
    cur->next_free = NULL;

#if defined(MBEDTLS_MEMORY_DEBUG)
    heap.header_count++;
    if( heap.header_count > heap.maximum_header_count )
        heap.maximum_header_count = heap.header_count;
    heap.total_used += cur->size;
    if( heap.total_used > heap.maximum_used )
        heap.maximum_used = heap.total_used;
#endif
#if defined(MBEDTLS_MEMORY_BACKTRACE)
    trace_cnt = backtrace( trace_buffer, MAX_BT );
    cur->trace = backtrace_symbols( trace_buffer, trace_cnt );
    cur->trace_count = trace_cnt;
#endif

    if( ( heap.verify & MBEDTLS_MEMORY_VERIFY_ALLOC ) && verify_chain() != 0 )
        mbedtls_exit( 1 );

    ret = (unsigned char *) cur + sizeof( memory_header );
    memset( ret, 0, original_len );

    return( ret );
}
static void buffer_alloc_free( void *ptr )
{
    memory_header *hdr, *old = NULL;
    unsigned char *p = (unsigned char *) ptr;

    if( ptr == NULL || heap.buf == NULL || heap.first == NULL )
        return;

    if( p < heap.buf || p >= heap.buf + heap.len )
    {
#if defined(MBEDTLS_MEMORY_DEBUG)
        mbedtls_fprintf( stderr, "FATAL: mbedtls_free() outside of managed "
                                  "space\n" );
#endif
        mbedtls_exit( 1 );
    }

    p -= sizeof(memory_header);
    hdr = (memory_header *) p;

    if( verify_header( hdr ) != 0 )
        mbedtls_exit( 1 );

    if( hdr->alloc != 1 )
    {
#if defined(MBEDTLS_MEMORY_DEBUG)
        mbedtls_fprintf( stderr, "FATAL: mbedtls_free() on unallocated "
                                  "data\n" );
#endif
        mbedtls_exit( 1 );
    }

    hdr->alloc = 0;

#if defined(MBEDTLS_MEMORY_DEBUG)
    heap.free_count++;
    heap.total_used -= hdr->size;
#endif

#if defined(MBEDTLS_MEMORY_BACKTRACE)
    free( hdr->trace );
    hdr->trace = NULL;
    hdr->trace_count = 0;
#endif

    // Regroup with block before
    //
    if( hdr->prev != NULL && hdr->prev->alloc == 0 )
    {
#if defined(MBEDTLS_MEMORY_DEBUG)
        heap.header_count--;
#endif
        hdr->prev->size += sizeof(memory_header) + hdr->size;
        hdr->prev->next = hdr->next;
        old = hdr;
        hdr = hdr->prev;

        if( hdr->next != NULL )
            hdr->next->prev = hdr;

        memset( old, 0, sizeof(memory_header) );
    }

    // Regroup with block after
    //
    if( hdr->next != NULL && hdr->next->alloc == 0 )
    {
#if defined(MBEDTLS_MEMORY_DEBUG)
        heap.header_count--;
#endif
        hdr->size += sizeof(memory_header) + hdr->next->size;
        old = hdr->next;
        hdr->next = hdr->next->next;

        if( hdr->prev_free != NULL || hdr->next_free != NULL )
        {
            if( hdr->prev_free != NULL )
                hdr->prev_free->next_free = hdr->next_free;
            else
                heap.first_free = hdr->next_free;

            if( hdr->next_free != NULL )
                hdr->next_free->prev_free = hdr->prev_free;
        }

        hdr->prev_free = old->prev_free;
        hdr->next_free = old->next_free;

        if( hdr->prev_free != NULL )
            hdr->prev_free->next_free = hdr;
        else
            heap.first_free = hdr;

        if( hdr->next_free != NULL )
            hdr->next_free->prev_free = hdr;

        if( hdr->next != NULL )
            hdr->next->prev = hdr;

        memset( old, 0, sizeof(memory_header) );
    }

    // Prepend to free_list if we have not merged
    // (Does not have to stay in same order as prev / next list)
    //
    if( old == NULL )
    {
        hdr->next_free = heap.first_free;
        if( heap.first_free != NULL )
            heap.first_free->prev_free = hdr;
        heap.first_free = hdr;
    }

    if( ( heap.verify & MBEDTLS_MEMORY_VERIFY_FREE ) && verify_chain() != 0 )
        mbedtls_exit( 1 );
}
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif /* MBEDTLS_MEMORY_DEBUG */
#if defined(MBEDTLS_THREADING_C)
#endif /* MBEDTLS_THREADING_C */
#if defined(MBEDTLS_THREADING_C)
#else
#endif
void mbedtls_memory_buffer_alloc_free( void )
{
#if defined(MBEDTLS_THREADING_C)
    mbedtls_mutex_free( &heap.mutex );
#endif
    mbedtls_platform_zeroize( &heap, sizeof(buffer_alloc_ctx) );
}
#if defined(MBEDTLS_SELF_TEST)
static int check_all_free( void )
{
    if(
#if defined(MBEDTLS_MEMORY_DEBUG)
        heap.total_used != 0 ||
#endif
        heap.first != heap.first_free ||
        (void *) heap.first != (void *) heap.buf )
    {
        return( -1 );
    }

    return( 0 );
}
#define TEST_ASSERT( condition )            \
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_MEMORY_BUFFER_ALLOC_C */
