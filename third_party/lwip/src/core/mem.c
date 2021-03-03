#include "lwip/opt.h"
#include "lwip/mem.h"
#include "lwip/def.h"
#include "lwip/sys.h"
#include "lwip/stats.h"
#include "lwip/err.h"
#include <string.h>
#if MEM_LIBC_MALLOC
#include <stdlib.h> /* for malloc()/free() */
#endif
#ifndef LWIP_MEM_ILLEGAL_FREE
#define LWIP_MEM_ILLEGAL_FREE(msg)         LWIP_ASSERT(msg, 0)
#endif
#define MEM_STATS_INC_LOCKED(x)         SYS_ARCH_LOCKED(MEM_STATS_INC(x))
#define MEM_STATS_INC_USED_LOCKED(x, y) SYS_ARCH_LOCKED(MEM_STATS_INC_USED(x, y))
#define MEM_STATS_DEC_USED_LOCKED(x, y) SYS_ARCH_LOCKED(MEM_STATS_DEC_USED(x, y))
#if MEM_OVERFLOW_CHECK
#define MEM_SANITY_OFFSET   MEM_SANITY_REGION_BEFORE_ALIGNED
#define MEM_SANITY_OVERHEAD (MEM_SANITY_REGION_BEFORE_ALIGNED + MEM_SANITY_REGION_AFTER_ALIGNED)
#else
#define MEM_SANITY_OFFSET   0
#define MEM_SANITY_OVERHEAD 0
#endif
#if MEM_OVERFLOW_CHECK || MEMP_OVERFLOW_CHECK
#if MEM_SANITY_REGION_AFTER_ALIGNED || MEM_SANITY_REGION_BEFORE_ALIGNED
#if MEM_SANITY_REGION_AFTER_ALIGNED > 0
#endif /* MEM_SANITY_REGION_AFTER_ALIGNED > 0 */
#if MEM_SANITY_REGION_BEFORE_ALIGNED > 0
#endif /* MEM_SANITY_REGION_BEFORE_ALIGNED > 0 */
#else
#endif
#if MEM_SANITY_REGION_BEFORE_ALIGNED > 0 || MEM_SANITY_REGION_AFTER_ALIGNED > 0
#if MEM_SANITY_REGION_BEFORE_ALIGNED > 0
#endif
#if MEM_SANITY_REGION_AFTER_ALIGNED > 0
#endif
#else /* MEM_SANITY_REGION_BEFORE_ALIGNED > 0 || MEM_SANITY_REGION_AFTER_ALIGNED > 0 */
#endif /* MEM_SANITY_REGION_BEFORE_ALIGNED > 0 || MEM_SANITY_REGION_AFTER_ALIGNED > 0 */
#endif /* MEM_OVERFLOW_CHECK || MEMP_OVERFLOW_CHECK */
#if MEM_LIBC_MALLOC || MEM_USE_POOLS
mem_init(void)
{
}
mem_trim(void *mem, mem_size_t size)
{
  LWIP_UNUSED_ARG(size);
  return mem;
}
#endif /* MEM_LIBC_MALLOC || MEM_USE_POOLS */
#if MEM_LIBC_MALLOC
#ifndef mem_clib_free
#define mem_clib_free free
#endif
#ifndef mem_clib_malloc
#define mem_clib_malloc malloc
#endif
#ifndef mem_clib_calloc
#define mem_clib_calloc calloc
#endif
#if LWIP_STATS && MEM_STATS
#define MEM_LIBC_STATSHELPER_SIZE LWIP_MEM_ALIGN_SIZE(sizeof(mem_size_t))
#else
#define MEM_LIBC_STATSHELPER_SIZE 0
#endif
mem_malloc(mem_size_t size)
{
  void *ret = mem_clib_malloc(size + MEM_LIBC_STATSHELPER_SIZE);
  if (ret == NULL) {
    MEM_STATS_INC_LOCKED(err);
  } else {
    LWIP_ASSERT("malloc() must return aligned memory", LWIP_MEM_ALIGN(ret) == ret);
#if LWIP_STATS && MEM_STATS
    *(mem_size_t *)ret = size;
    ret = (u8_t *)ret + MEM_LIBC_STATSHELPER_SIZE;
    MEM_STATS_INC_USED_LOCKED(used, size);
#endif
  }
  return ret;
}
mem_free(void *rmem)
{
  LWIP_ASSERT("rmem != NULL", (rmem != NULL));
  LWIP_ASSERT("rmem == MEM_ALIGN(rmem)", (rmem == LWIP_MEM_ALIGN(rmem)));
#if LWIP_STATS && MEM_STATS
  rmem = (u8_t *)rmem - MEM_LIBC_STATSHELPER_SIZE;
  MEM_STATS_DEC_USED_LOCKED(used, *(mem_size_t *)rmem);
#endif
  mem_clib_free(rmem);
}
#elif MEM_USE_POOLS
mem_malloc(mem_size_t size)
{
  void *ret;
  struct memp_malloc_helper *element = NULL;
  memp_t poolnr;
  mem_size_t required_size = size + LWIP_MEM_ALIGN_SIZE(sizeof(struct memp_malloc_helper));

  for (poolnr = MEMP_POOL_FIRST; poolnr <= MEMP_POOL_LAST; poolnr = (memp_t)(poolnr + 1)) {
    /* is this pool big enough to hold an element of the required size
       plus a struct memp_malloc_helper that saves the pool this element came from? */
    if (required_size <= memp_pools[poolnr]->size) {
      element = (struct memp_malloc_helper *)memp_malloc(poolnr);
      if (element == NULL) {
        /* No need to DEBUGF or ASSERT: This error is already taken care of in memp.c */
#if MEM_USE_POOLS_TRY_BIGGER_POOL
        /** Try a bigger pool if this one is empty! */
        if (poolnr < MEMP_POOL_LAST) {
          continue;
        }
#endif /* MEM_USE_POOLS_TRY_BIGGER_POOL */
        MEM_STATS_INC_LOCKED(err);
        return NULL;
      }
      break;
    }
  }
  if (poolnr > MEMP_POOL_LAST) {
    LWIP_ASSERT("mem_malloc(): no pool is that big!", 0);
    MEM_STATS_INC_LOCKED(err);
    return NULL;
  }

  /* save the pool number this element came from */
  element->poolnr = poolnr;
  /* and return a pointer to the memory directly after the struct memp_malloc_helper */
  ret = (u8_t *)element + LWIP_MEM_ALIGN_SIZE(sizeof(struct memp_malloc_helper));

#if MEMP_OVERFLOW_CHECK || (LWIP_STATS && MEM_STATS)
  /* truncating to u16_t is safe because struct memp_desc::size is u16_t */
  element->size = (u16_t)size;
  MEM_STATS_INC_USED_LOCKED(used, element->size);
#endif /* MEMP_OVERFLOW_CHECK || (LWIP_STATS && MEM_STATS) */
#if MEMP_OVERFLOW_CHECK
  /* initialize unused memory (diff between requested size and selected pool's size) */
  memset((u8_t *)ret + size, 0xcd, memp_pools[poolnr]->size - size);
#endif /* MEMP_OVERFLOW_CHECK */
  return ret;
}
mem_free(void *rmem)
{
  struct memp_malloc_helper *hmem;

  LWIP_ASSERT("rmem != NULL", (rmem != NULL));
  LWIP_ASSERT("rmem == MEM_ALIGN(rmem)", (rmem == LWIP_MEM_ALIGN(rmem)));

  /* get the original struct memp_malloc_helper */
  /* cast through void* to get rid of alignment warnings */
  hmem = (struct memp_malloc_helper *)(void *)((u8_t *)rmem - LWIP_MEM_ALIGN_SIZE(sizeof(struct memp_malloc_helper)));

  LWIP_ASSERT("hmem != NULL", (hmem != NULL));
  LWIP_ASSERT("hmem == MEM_ALIGN(hmem)", (hmem == LWIP_MEM_ALIGN(hmem)));
  LWIP_ASSERT("hmem->poolnr < MEMP_MAX", (hmem->poolnr < MEMP_MAX));

  MEM_STATS_DEC_USED_LOCKED(used, hmem->size);
#if MEMP_OVERFLOW_CHECK
  {
    u16_t i;
    LWIP_ASSERT("MEM_USE_POOLS: invalid chunk size",
                hmem->size <= memp_pools[hmem->poolnr]->size);
    /* check that unused memory remained untouched (diff between requested size and selected pool's size) */
    for (i = hmem->size; i < memp_pools[hmem->poolnr]->size; i++) {
      u8_t data = *((u8_t *)rmem + i);
      LWIP_ASSERT("MEM_USE_POOLS: mem overflow detected", data == 0xcd);
    }
  }
#endif /* MEMP_OVERFLOW_CHECK */

  /* and put it in the pool we saved earlier */
  memp_free(hmem->poolnr, hmem);
}
#else /* MEM_USE_POOLS */
#if MEM_OVERFLOW_CHECK
#endif
#ifndef MIN_SIZE
#define MIN_SIZE             12
#endif /* MIN_SIZE */
#define MIN_SIZE_ALIGNED     LWIP_MEM_ALIGN_SIZE(MIN_SIZE)
#define SIZEOF_STRUCT_MEM    LWIP_MEM_ALIGN_SIZE(sizeof(struct mem))
#define MEM_SIZE_ALIGNED     LWIP_MEM_ALIGN_SIZE(MEM_SIZE)
#ifndef LWIP_RAM_HEAP_POINTER
#define LWIP_RAM_HEAP_POINTER ram_heap
#endif /* LWIP_RAM_HEAP_POINTER */
#if !NO_SYS
#endif
#if LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT
#define LWIP_MEM_FREE_DECL_PROTECT()  SYS_ARCH_DECL_PROTECT(lev_free)
#define LWIP_MEM_FREE_PROTECT()       SYS_ARCH_PROTECT(lev_free)
#define LWIP_MEM_FREE_UNPROTECT()     SYS_ARCH_UNPROTECT(lev_free)
#define LWIP_MEM_ALLOC_DECL_PROTECT() SYS_ARCH_DECL_PROTECT(lev_alloc)
#define LWIP_MEM_ALLOC_PROTECT()      SYS_ARCH_PROTECT(lev_alloc)
#define LWIP_MEM_ALLOC_UNPROTECT()    SYS_ARCH_UNPROTECT(lev_alloc)
#define LWIP_MEM_LFREE_VOLATILE       volatile
#else /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */
#define LWIP_MEM_FREE_DECL_PROTECT()
#define LWIP_MEM_FREE_PROTECT()    sys_mutex_lock(&mem_mutex)
#define LWIP_MEM_FREE_UNPROTECT()  sys_mutex_unlock(&mem_mutex)
#define LWIP_MEM_ALLOC_DECL_PROTECT()
#define LWIP_MEM_ALLOC_PROTECT()
#define LWIP_MEM_ALLOC_UNPROTECT()
#define LWIP_MEM_LFREE_VOLATILE
#endif /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */
#if MEM_SANITY_CHECK
#define MEM_SANITY() mem_sanity()
#else
#define MEM_SANITY()
#endif
#if MEM_OVERFLOW_CHECK
#else /* MEM_OVERFLOW_CHECK */
#define mem_overflow_init_element(mem, size)
#define mem_overflow_check_element(mem)
#endif /* MEM_OVERFLOW_CHECK */
mem_init(void)
{
  struct mem *mem;

  LWIP_ASSERT("Sanity check alignment",
              (SIZEOF_STRUCT_MEM & (MEM_ALIGNMENT - 1)) == 0);

  /* align the heap */
  ram = (u8_t *)LWIP_MEM_ALIGN(LWIP_RAM_HEAP_POINTER);
  /* initialize the start of the heap */
  mem = (struct mem *)(void *)ram;
  mem->next = MEM_SIZE_ALIGNED;
  mem->prev = 0;
  mem->used = 0;
  /* initialize the end of the heap */
  ram_end = ptr_to_mem(MEM_SIZE_ALIGNED);
  ram_end->used = 1;
  ram_end->next = MEM_SIZE_ALIGNED;
  ram_end->prev = MEM_SIZE_ALIGNED;
  MEM_SANITY();

  /* initialize the lowest-free pointer to the start of the heap */
  lfree = (struct mem *)(void *)ram;

  MEM_STATS_AVAIL(avail, MEM_SIZE_ALIGNED);

  if (sys_mutex_new(&mem_mutex) != ERR_OK) {
    LWIP_ASSERT("failed to create mem_mutex", 0);
  }
}
#if MEM_SANITY_CHECK
#endif /* MEM_SANITY_CHECK */
mem_free(void *rmem)
{
  struct mem *mem;
  LWIP_MEM_FREE_DECL_PROTECT();

  if (rmem == NULL) {
    LWIP_DEBUGF(MEM_DEBUG | LWIP_DBG_TRACE | LWIP_DBG_LEVEL_SERIOUS, ("mem_free(p == NULL) was called.\n"));
    return;
  }
  if ((((mem_ptr_t)rmem) & (MEM_ALIGNMENT - 1)) != 0) {
    LWIP_MEM_ILLEGAL_FREE("mem_free: sanity check alignment");
    LWIP_DEBUGF(MEM_DEBUG | LWIP_DBG_LEVEL_SEVERE, ("mem_free: sanity check alignment\n"));
    /* protect mem stats from concurrent access */
    MEM_STATS_INC_LOCKED(illegal);
    return;
  }

  /* Get the corresponding struct mem: */
  /* cast through void* to get rid of alignment warnings */
  mem = (struct mem *)(void *)((u8_t *)rmem - (SIZEOF_STRUCT_MEM + MEM_SANITY_OFFSET));

  if ((u8_t *)mem < ram || (u8_t *)rmem + MIN_SIZE_ALIGNED > (u8_t *)ram_end) {
    LWIP_MEM_ILLEGAL_FREE("mem_free: illegal memory");
    LWIP_DEBUGF(MEM_DEBUG | LWIP_DBG_LEVEL_SEVERE, ("mem_free: illegal memory\n"));
    /* protect mem stats from concurrent access */
    MEM_STATS_INC_LOCKED(illegal);
    return;
  }
#if MEM_OVERFLOW_CHECK
  mem_overflow_check_element(mem);
#endif
  /* protect the heap from concurrent access */
  LWIP_MEM_FREE_PROTECT();
  /* mem has to be in a used state */
  if (!mem->used) {
    LWIP_MEM_ILLEGAL_FREE("mem_free: illegal memory: double free");
    LWIP_MEM_FREE_UNPROTECT();
    LWIP_DEBUGF(MEM_DEBUG | LWIP_DBG_LEVEL_SEVERE, ("mem_free: illegal memory: double free?\n"));
    /* protect mem stats from concurrent access */
    MEM_STATS_INC_LOCKED(illegal);
    return;
  }

  if (!mem_link_valid(mem)) {
    LWIP_MEM_ILLEGAL_FREE("mem_free: illegal memory: non-linked: double free");
    LWIP_MEM_FREE_UNPROTECT();
    LWIP_DEBUGF(MEM_DEBUG | LWIP_DBG_LEVEL_SEVERE, ("mem_free: illegal memory: non-linked: double free?\n"));
    /* protect mem stats from concurrent access */
    MEM_STATS_INC_LOCKED(illegal);
    return;
  }

  /* mem is now unused. */
  mem->used = 0;

  if (mem < lfree) {
    /* the newly freed struct is now the lowest */
    lfree = mem;
  }

  MEM_STATS_DEC_USED(used, mem->next - (mem_size_t)(((u8_t *)mem - ram)));

  /* finally, see if prev or next are free also */
  plug_holes(mem);
  MEM_SANITY();
#if LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT
  mem_free_count = 1;
#endif /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */
  LWIP_MEM_FREE_UNPROTECT();
}
mem_trim(void *rmem, mem_size_t new_size)
{
  mem_size_t size, newsize;
  mem_size_t ptr, ptr2;
  struct mem *mem, *mem2;
  /* use the FREE_PROTECT here: it protects with sem OR SYS_ARCH_PROTECT */
  LWIP_MEM_FREE_DECL_PROTECT();

  /* Expand the size of the allocated memory region so that we can
     adjust for alignment. */
  newsize = (mem_size_t)LWIP_MEM_ALIGN_SIZE(new_size);
  if (newsize < MIN_SIZE_ALIGNED) {
    /* every data block must be at least MIN_SIZE_ALIGNED long */
    newsize = MIN_SIZE_ALIGNED;
  }
#if MEM_OVERFLOW_CHECK
  newsize += MEM_SANITY_REGION_BEFORE_ALIGNED + MEM_SANITY_REGION_AFTER_ALIGNED;
#endif
  if ((newsize > MEM_SIZE_ALIGNED) || (newsize < new_size)) {
    return NULL;
  }

  LWIP_ASSERT("mem_trim: legal memory", (u8_t *)rmem >= (u8_t *)ram &&
              (u8_t *)rmem < (u8_t *)ram_end);

  if ((u8_t *)rmem < (u8_t *)ram || (u8_t *)rmem >= (u8_t *)ram_end) {
    LWIP_DEBUGF(MEM_DEBUG | LWIP_DBG_LEVEL_SEVERE, ("mem_trim: illegal memory\n"));
    /* protect mem stats from concurrent access */
    MEM_STATS_INC_LOCKED(illegal);
    return rmem;
  }
  /* Get the corresponding struct mem ... */
  /* cast through void* to get rid of alignment warnings */
  mem = (struct mem *)(void *)((u8_t *)rmem - (SIZEOF_STRUCT_MEM + MEM_SANITY_OFFSET));
#if MEM_OVERFLOW_CHECK
  mem_overflow_check_element(mem);
#endif
  /* ... and its offset pointer */
  ptr = mem_to_ptr(mem);

  size = (mem_size_t)((mem_size_t)(mem->next - ptr) - (SIZEOF_STRUCT_MEM + MEM_SANITY_OVERHEAD));
  LWIP_ASSERT("mem_trim can only shrink memory", newsize <= size);
  if (newsize > size) {
    /* not supported */
    return NULL;
  }
  if (newsize == size) {
    /* No change in size, simply return */
    return rmem;
  }

  /* protect the heap from concurrent access */
  LWIP_MEM_FREE_PROTECT();

  mem2 = ptr_to_mem(mem->next);
  if (mem2->used == 0) {
    /* The next struct is unused, we can simply move it at little */
    mem_size_t next;
    LWIP_ASSERT("invalid next ptr", mem->next != MEM_SIZE_ALIGNED);
    /* remember the old next pointer */
    next = mem2->next;
    /* create new struct mem which is moved directly after the shrinked mem */
    ptr2 = (mem_size_t)(ptr + SIZEOF_STRUCT_MEM + newsize);
    if (lfree == mem2) {
      lfree = ptr_to_mem(ptr2);
    }
    mem2 = ptr_to_mem(ptr2);
    mem2->used = 0;
    /* restore the next pointer */
    mem2->next = next;
    /* link it back to mem */
    mem2->prev = ptr;
    /* link mem to it */
    mem->next = ptr2;
    /* last thing to restore linked list: as we have moved mem2,
     * let 'mem2->next->prev' point to mem2 again. but only if mem2->next is not
     * the end of the heap */
    if (mem2->next != MEM_SIZE_ALIGNED) {
      ptr_to_mem(mem2->next)->prev = ptr2;
    }
    MEM_STATS_DEC_USED(used, (size - newsize));
    /* no need to plug holes, we've already done that */
  } else if (newsize + SIZEOF_STRUCT_MEM + MIN_SIZE_ALIGNED <= size) {
    /* Next struct is used but there's room for another struct mem with
     * at least MIN_SIZE_ALIGNED of data.
     * Old size ('size') must be big enough to contain at least 'newsize' plus a struct mem
     * ('SIZEOF_STRUCT_MEM') with some data ('MIN_SIZE_ALIGNED').
     * @todo we could leave out MIN_SIZE_ALIGNED. We would create an empty
     *       region that couldn't hold data, but when mem->next gets freed,
     *       the 2 regions would be combined, resulting in more free memory */
    ptr2 = (mem_size_t)(ptr + SIZEOF_STRUCT_MEM + newsize);
    LWIP_ASSERT("invalid next ptr", mem->next != MEM_SIZE_ALIGNED);
    mem2 = ptr_to_mem(ptr2);
    if (mem2 < lfree) {
      lfree = mem2;
    }
    mem2->used = 0;
    mem2->next = mem->next;
    mem2->prev = ptr;
    mem->next = ptr2;
    if (mem2->next != MEM_SIZE_ALIGNED) {
      ptr_to_mem(mem2->next)->prev = ptr2;
    }
    MEM_STATS_DEC_USED(used, (size - newsize));
    /* the original mem->next is used, so no need to plug holes! */
  }
  /* else {
    next struct mem is used but size between mem and mem2 is not big enough
    to create another struct mem
    -> don't do anyhting.
    -> the remaining space stays unused since it is too small
  } */
#if MEM_OVERFLOW_CHECK
  mem_overflow_init_element(mem, new_size);
#endif
  MEM_SANITY();
#if LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT
  mem_free_count = 1;
#endif /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */
  LWIP_MEM_FREE_UNPROTECT();
  return rmem;
}
mem_malloc(mem_size_t size_in)
{
  mem_size_t ptr, ptr2, size;
  struct mem *mem, *mem2;
#if LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT
  u8_t local_mem_free_count = 0;
#endif /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */
  LWIP_MEM_ALLOC_DECL_PROTECT();

  if (size_in == 0) {
    return NULL;
  }

  /* Expand the size of the allocated memory region so that we can
     adjust for alignment. */
  size = (mem_size_t)LWIP_MEM_ALIGN_SIZE(size_in);
  if (size < MIN_SIZE_ALIGNED) {
    /* every data block must be at least MIN_SIZE_ALIGNED long */
    size = MIN_SIZE_ALIGNED;
  }
#if MEM_OVERFLOW_CHECK
  size += MEM_SANITY_REGION_BEFORE_ALIGNED + MEM_SANITY_REGION_AFTER_ALIGNED;
#endif
  if ((size > MEM_SIZE_ALIGNED) || (size < size_in)) {
    return NULL;
  }

  /* protect the heap from concurrent access */
  sys_mutex_lock(&mem_mutex);
  LWIP_MEM_ALLOC_PROTECT();
#if LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT
  /* run as long as a mem_free disturbed mem_malloc or mem_trim */
  do {
    local_mem_free_count = 0;
#endif /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */

    /* Scan through the heap searching for a free block that is big enough,
     * beginning with the lowest free block.
     */
    for (ptr = mem_to_ptr(lfree); ptr < MEM_SIZE_ALIGNED - size;
         ptr = ptr_to_mem(ptr)->next) {
      mem = ptr_to_mem(ptr);
#if LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT
      mem_free_count = 0;
      LWIP_MEM_ALLOC_UNPROTECT();
      /* allow mem_free or mem_trim to run */
      LWIP_MEM_ALLOC_PROTECT();
      if (mem_free_count != 0) {
        /* If mem_free or mem_trim have run, we have to restart since they
           could have altered our current struct mem. */
        local_mem_free_count = 1;
        break;
      }
#endif /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */

      if ((!mem->used) &&
          (mem->next - (ptr + SIZEOF_STRUCT_MEM)) >= size) {
        /* mem is not used and at least perfect fit is possible:
         * mem->next - (ptr + SIZEOF_STRUCT_MEM) gives us the 'user data size' of mem */

        if (mem->next - (ptr + SIZEOF_STRUCT_MEM) >= (size + SIZEOF_STRUCT_MEM + MIN_SIZE_ALIGNED)) {
          /* (in addition to the above, we test if another struct mem (SIZEOF_STRUCT_MEM) containing
           * at least MIN_SIZE_ALIGNED of data also fits in the 'user data space' of 'mem')
           * -> split large block, create empty remainder,
           * remainder must be large enough to contain MIN_SIZE_ALIGNED data: if
           * mem->next - (ptr + (2*SIZEOF_STRUCT_MEM)) == size,
           * struct mem would fit in but no data between mem2 and mem2->next
           * @todo we could leave out MIN_SIZE_ALIGNED. We would create an empty
           *       region that couldn't hold data, but when mem->next gets freed,
           *       the 2 regions would be combined, resulting in more free memory
           */
          ptr2 = (mem_size_t)(ptr + SIZEOF_STRUCT_MEM + size);
          LWIP_ASSERT("invalid next ptr",ptr2 != MEM_SIZE_ALIGNED);
          /* create mem2 struct */
          mem2 = ptr_to_mem(ptr2);
          mem2->used = 0;
          mem2->next = mem->next;
          mem2->prev = ptr;
          /* and insert it between mem and mem->next */
          mem->next = ptr2;
          mem->used = 1;

          if (mem2->next != MEM_SIZE_ALIGNED) {
            ptr_to_mem(mem2->next)->prev = ptr2;
          }
          MEM_STATS_INC_USED(used, (size + SIZEOF_STRUCT_MEM));
        } else {
          /* (a mem2 struct does no fit into the user data space of mem and mem->next will always
           * be used at this point: if not we have 2 unused structs in a row, plug_holes should have
           * take care of this).
           * -> near fit or exact fit: do not split, no mem2 creation
           * also can't move mem->next directly behind mem, since mem->next
           * will always be used at this point!
           */
          mem->used = 1;
          MEM_STATS_INC_USED(used, mem->next - mem_to_ptr(mem));
        }
#if LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT
mem_malloc_adjust_lfree:
#endif /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */
        if (mem == lfree) {
          struct mem *cur = lfree;
          /* Find next free block after mem and update lowest free pointer */
          while (cur->used && cur != ram_end) {
#if LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT
            mem_free_count = 0;
            LWIP_MEM_ALLOC_UNPROTECT();
            /* prevent high interrupt latency... */
            LWIP_MEM_ALLOC_PROTECT();
            if (mem_free_count != 0) {
              /* If mem_free or mem_trim have run, we have to restart since they
                 could have altered our current struct mem or lfree. */
              goto mem_malloc_adjust_lfree;
            }
#endif /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */
            cur = ptr_to_mem(cur->next);
          }
          lfree = cur;
          LWIP_ASSERT("mem_malloc: !lfree->used", ((lfree == ram_end) || (!lfree->used)));
        }
        LWIP_MEM_ALLOC_UNPROTECT();
        sys_mutex_unlock(&mem_mutex);
        LWIP_ASSERT("mem_malloc: allocated memory not above ram_end.",
                    (mem_ptr_t)mem + SIZEOF_STRUCT_MEM + size <= (mem_ptr_t)ram_end);
        LWIP_ASSERT("mem_malloc: allocated memory properly aligned.",
                    ((mem_ptr_t)mem + SIZEOF_STRUCT_MEM) % MEM_ALIGNMENT == 0);
        LWIP_ASSERT("mem_malloc: sanity check alignment",
                    (((mem_ptr_t)mem) & (MEM_ALIGNMENT - 1)) == 0);

#if MEM_OVERFLOW_CHECK
        mem_overflow_init_element(mem, size_in);
#endif
        MEM_SANITY();
        return (u8_t *)mem + SIZEOF_STRUCT_MEM + MEM_SANITY_OFFSET;
      }
    }
#if LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT
    /* if we got interrupted by a mem_free, try again */
  } while (local_mem_free_count != 0);
#endif /* LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT */
  MEM_STATS_INC(err);
  LWIP_MEM_ALLOC_UNPROTECT();
  sys_mutex_unlock(&mem_mutex);
  LWIP_DEBUGF(MEM_DEBUG | LWIP_DBG_LEVEL_SERIOUS, ("mem_malloc: could not allocate %"S16_F" bytes\n", (s16_t)size));
  return NULL;
}
#endif /* MEM_USE_POOLS */
#if MEM_LIBC_MALLOC && (!LWIP_STATS || !MEM_STATS)
mem_calloc(mem_size_t count, mem_size_t size)
{
  return mem_clib_calloc(count, size);
}
#else /* MEM_LIBC_MALLOC && (!LWIP_STATS || !MEM_STATS) */
mem_calloc(mem_size_t count, mem_size_t size)
{
  void *p;
  size_t alloc_size = (size_t)count * (size_t)size;

  if ((size_t)(mem_size_t)alloc_size != alloc_size) {
    LWIP_DEBUGF(MEM_DEBUG | LWIP_DBG_LEVEL_SERIOUS, ("mem_calloc: could not allocate %"SZT_F" bytes\n", alloc_size));
    return NULL;
  }

  /* allocate 'count' objects of size 'size' */
  p = mem_malloc((mem_size_t)alloc_size);
  if (p) {
    /* zero the memory */
    memset(p, 0, alloc_size);
  }
  return p;
}
#endif /* MEM_LIBC_MALLOC && (!LWIP_STATS || !MEM_STATS) */
