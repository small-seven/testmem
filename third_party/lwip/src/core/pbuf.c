#include "lwip/opt.h"
#include "lwip/pbuf.h"
#include "lwip/stats.h"
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/sys.h"
#include "lwip/netif.h"
#if LWIP_TCP && TCP_QUEUE_OOSEQ
#include "lwip/priv/tcp_priv.h"
#endif
#if LWIP_CHECKSUM_ON_COPY
#include "lwip/inet_chksum.h"
#endif
#include <string.h>
#define SIZEOF_STRUCT_PBUF        LWIP_MEM_ALIGN_SIZE(sizeof(struct pbuf))
#define PBUF_POOL_BUFSIZE_ALIGNED LWIP_MEM_ALIGN_SIZE(PBUF_POOL_BUFSIZE)
#if !LWIP_TCP || !TCP_QUEUE_OOSEQ || !PBUF_POOL_FREE_OOSEQ
#define PBUF_POOL_IS_EMPTY()
#else /* !LWIP_TCP || !TCP_QUEUE_OOSEQ || !PBUF_POOL_FREE_OOSEQ */
#if !NO_SYS
#ifndef PBUF_POOL_FREE_OOSEQ_QUEUE_CALL
#include "lwip/tcpip.h"
#define PBUF_POOL_FREE_OOSEQ_QUEUE_CALL()  do { \
#endif /* PBUF_POOL_FREE_OOSEQ_QUEUE_CALL */
#endif /* !NO_SYS */
#define PBUF_POOL_IS_EMPTY() pbuf_pool_is_empty()
#if !NO_SYS
#endif /* !NO_SYS */
pbuf_free_ooseq(void)
{
  struct tcp_pcb *pcb;
  SYS_ARCH_SET(pbuf_free_ooseq_pending, 0);

  for (pcb = tcp_active_pcbs; NULL != pcb; pcb = pcb->next) {
    if (pcb->ooseq != NULL) {
      /** Free the ooseq pbufs of one PCB only */
      LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_TRACE, ("pbuf_free_ooseq: freeing out-of-sequence pbufs\n"));
      tcp_free_ooseq(pcb);
      return;
    }
  }
}
#if !NO_SYS
pbuf_free_ooseq_callback(void *arg)
{
  LWIP_UNUSED_ARG(arg);
  pbuf_free_ooseq();
}
#endif /* !NO_SYS */
#ifndef PBUF_POOL_FREE_OOSEQ_QUEUE_CALL
#else /* PBUF_POOL_FREE_OOSEQ_QUEUE_CALL */
#endif /* PBUF_POOL_FREE_OOSEQ_QUEUE_CALL */
#endif /* !LWIP_TCP || !TCP_QUEUE_OOSEQ || !PBUF_POOL_FREE_OOSEQ */
pbuf_init_alloced_pbuf(struct pbuf *p, void *payload, u16_t tot_len, u16_t len, pbuf_type type, u8_t flags)
{
  p->next = NULL;
  p->payload = payload;
  p->tot_len = tot_len;
  p->len = len;
  p->type_internal = (u8_t)type;
  p->flags = flags;
  p->ref = 1;
  p->if_idx = NETIF_NO_INDEX;
}
pbuf_alloc(pbuf_layer layer, u16_t length, pbuf_type type)
{
  struct pbuf *p;
  u16_t offset = (u16_t)layer;
  LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_TRACE, ("pbuf_alloc(length=%"U16_F")\n", length));

  switch (type) {
    case PBUF_REF: /* fall through */
    case PBUF_ROM:
      p = pbuf_alloc_reference(NULL, length, type);
      break;
    case PBUF_POOL: {
      struct pbuf *q, *last;
      u16_t rem_len; /* remaining length */
      p = NULL;
      last = NULL;
      rem_len = length;
      do {
        u16_t qlen;
        q = (struct pbuf *)memp_malloc(MEMP_PBUF_POOL);
        if (q == NULL) {
          PBUF_POOL_IS_EMPTY();
          /* free chain so far allocated */
          if (p) {
            pbuf_free(p);
          }
          /* bail out unsuccessfully */
          return NULL;
        }
        qlen = LWIP_MIN(rem_len, (u16_t)(PBUF_POOL_BUFSIZE_ALIGNED - LWIP_MEM_ALIGN_SIZE(offset)));
        pbuf_init_alloced_pbuf(q, LWIP_MEM_ALIGN((void *)((u8_t *)q + SIZEOF_STRUCT_PBUF + offset)),
                               rem_len, qlen, type, 0);
        LWIP_ASSERT("pbuf_alloc: pbuf q->payload properly aligned",
                    ((mem_ptr_t)q->payload % MEM_ALIGNMENT) == 0);
        LWIP_ASSERT("PBUF_POOL_BUFSIZE must be bigger than MEM_ALIGNMENT",
                    (PBUF_POOL_BUFSIZE_ALIGNED - LWIP_MEM_ALIGN_SIZE(offset)) > 0 );
        if (p == NULL) {
          /* allocated head of pbuf chain (into p) */
          p = q;
        } else {
          /* make previous pbuf point to this pbuf */
          last->next = q;
        }
        last = q;
        rem_len = (u16_t)(rem_len - qlen);
        offset = 0;
      } while (rem_len > 0);
      break;
    }
    case PBUF_RAM: {
      u16_t payload_len = (u16_t)(LWIP_MEM_ALIGN_SIZE(offset) + LWIP_MEM_ALIGN_SIZE(length));
      mem_size_t alloc_len = (mem_size_t)(LWIP_MEM_ALIGN_SIZE(SIZEOF_STRUCT_PBUF) + payload_len);

      /* bug #50040: Check for integer overflow when calculating alloc_len */
      if ((payload_len < LWIP_MEM_ALIGN_SIZE(length)) ||
          (alloc_len < LWIP_MEM_ALIGN_SIZE(length))) {
        return NULL;
      }

      /* If pbuf is to be allocated in RAM, allocate memory for it. */
      p = (struct pbuf *)mem_malloc(alloc_len);
      if (p == NULL) {
        return NULL;
      }
      pbuf_init_alloced_pbuf(p, LWIP_MEM_ALIGN((void *)((u8_t *)p + SIZEOF_STRUCT_PBUF + offset)),
                             length, length, type, 0);
      LWIP_ASSERT("pbuf_alloc: pbuf->payload properly aligned",
                  ((mem_ptr_t)p->payload % MEM_ALIGNMENT) == 0);
      break;
    }
    default:
      LWIP_ASSERT("pbuf_alloc: erroneous type", 0);
      return NULL;
  }
  LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_TRACE, ("pbuf_alloc(length=%"U16_F") == %p\n", length, (void *)p));
  return p;
}
pbuf_alloc_reference(void *payload, u16_t length, pbuf_type type)
{
  struct pbuf *p;
  LWIP_ASSERT("invalid pbuf_type", (type == PBUF_REF) || (type == PBUF_ROM));
  /* only allocate memory for the pbuf structure */
  p = (struct pbuf *)memp_malloc(MEMP_PBUF);
  if (p == NULL) {
    LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_LEVEL_SERIOUS,
                ("pbuf_alloc_reference: Could not allocate MEMP_PBUF for PBUF_%s.\n",
                 (type == PBUF_ROM) ? "ROM" : "REF"));
    return NULL;
  }
  pbuf_init_alloced_pbuf(p, payload, length, length, type, 0);
  return p;
}
#if LWIP_SUPPORT_CUSTOM_PBUF
pbuf_alloced_custom(pbuf_layer l, u16_t length, pbuf_type type, struct pbuf_custom *p,
                    void *payload_mem, u16_t payload_mem_len)
{
  u16_t offset = (u16_t)l;
  void *payload;
  LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_TRACE, ("pbuf_alloced_custom(length=%"U16_F")\n", length));

  if (LWIP_MEM_ALIGN_SIZE(offset) + length > payload_mem_len) {
    LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_LEVEL_WARNING, ("pbuf_alloced_custom(length=%"U16_F") buffer too short\n", length));
    return NULL;
  }

  if (payload_mem != NULL) {
    payload = (u8_t *)payload_mem + LWIP_MEM_ALIGN_SIZE(offset);
  } else {
    payload = NULL;
  }
  pbuf_init_alloced_pbuf(&p->pbuf, payload, length, length, type, PBUF_FLAG_IS_CUSTOM);
  return &p->pbuf;
}
#endif /* LWIP_SUPPORT_CUSTOM_PBUF */
pbuf_realloc(struct pbuf *p, u16_t new_len)
{
  struct pbuf *q;
  u16_t rem_len; /* remaining length */
  u16_t shrink;

  LWIP_ASSERT("pbuf_realloc: p != NULL", p != NULL);

  /* desired length larger than current length? */
  if (new_len >= p->tot_len) {
    /* enlarging not yet supported */
    return;
  }

  /* the pbuf chain grows by (new_len - p->tot_len) bytes
   * (which may be negative in case of shrinking) */
  shrink = (u16_t)(p->tot_len - new_len);

  /* first, step over any pbufs that should remain in the chain */
  rem_len = new_len;
  q = p;
  /* should this pbuf be kept? */
  while (rem_len > q->len) {
    /* decrease remaining length by pbuf length */
    rem_len = (u16_t)(rem_len - q->len);
    /* decrease total length indicator */
    q->tot_len = (u16_t)(q->tot_len - shrink);
    /* proceed to next pbuf in chain */
    q = q->next;
    LWIP_ASSERT("pbuf_realloc: q != NULL", q != NULL);
  }
  /* we have now reached the new last pbuf (in q) */
  /* rem_len == desired length for pbuf q */

  /* shrink allocated memory for PBUF_RAM */
  /* (other types merely adjust their length fields */
  if (pbuf_match_allocsrc(q, PBUF_TYPE_ALLOC_SRC_MASK_STD_HEAP) && (rem_len != q->len)
#if LWIP_SUPPORT_CUSTOM_PBUF
      && ((q->flags & PBUF_FLAG_IS_CUSTOM) == 0)
#endif /* LWIP_SUPPORT_CUSTOM_PBUF */
     ) {
    /* reallocate and adjust the length of the pbuf that will be split */
    q = (struct pbuf *)mem_trim(q, (mem_size_t)(((u8_t *)q->payload - (u8_t *)q) + rem_len));
    LWIP_ASSERT("mem_trim returned q == NULL", q != NULL);
  }
  /* adjust length fields for new last pbuf */
  q->len = rem_len;
  q->tot_len = q->len;

  /* any remaining pbufs in chain? */
  if (q->next != NULL) {
    /* free remaining pbufs in chain */
    pbuf_free(q->next);
  }
  /* q is last packet in chain */
  q->next = NULL;

}
pbuf_remove_header(struct pbuf *p, size_t header_size_decrement)
{
  void *payload;
  u16_t increment_magnitude;

  LWIP_ASSERT("p != NULL", p != NULL);
  if ((p == NULL) || (header_size_decrement > 0xFFFF)) {
    return 1;
  }
  if (header_size_decrement == 0) {
    return 0;
  }

  increment_magnitude = (u16_t)header_size_decrement;
  /* Check that we aren't going to move off the end of the pbuf */
  LWIP_ERROR("increment_magnitude <= p->len", (increment_magnitude <= p->len), return 1;);

  /* remember current payload pointer */
  payload = p->payload;
  LWIP_UNUSED_ARG(payload); /* only used in LWIP_DEBUGF below */

  /* increase payload pointer (guarded by length check above) */
  p->payload = (u8_t *)p->payload + header_size_decrement;
  /* modify pbuf length fields */
  p->len = (u16_t)(p->len - increment_magnitude);
  p->tot_len = (u16_t)(p->tot_len - increment_magnitude);

  LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_TRACE, ("pbuf_remove_header: old %p new %p (%"U16_F")\n",
              (void *)payload, (void *)p->payload, increment_magnitude));

  return 0;
}
pbuf_free_header(struct pbuf *q, u16_t size)
{
  struct pbuf *p = q;
  u16_t free_left = size;
  while (free_left && p) {
    if (free_left >= p->len) {
      struct pbuf *f = p;
      free_left = (u16_t)(free_left - p->len);
      p = p->next;
      f->next = 0;
      pbuf_free(f);
    } else {
      pbuf_remove_header(p, free_left);
      free_left = 0;
    }
  }
  return p;
}
pbuf_free(struct pbuf *p)
{
  u8_t alloc_src;
  struct pbuf *q;
  u8_t count;

  if (p == NULL) {
    LWIP_ASSERT("p != NULL", p != NULL);
    /* if assertions are disabled, proceed with debug output */
    LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_LEVEL_SERIOUS,
                ("pbuf_free(p == NULL) was called.\n"));
    return 0;
  }
  LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_TRACE, ("pbuf_free(%p)\n", (void *)p));

  PERF_START;

  count = 0;
  /* de-allocate all consecutive pbufs from the head of the chain that
   * obtain a zero reference count after decrementing*/
  while (p != NULL) {
    LWIP_PBUF_REF_T ref;
    SYS_ARCH_DECL_PROTECT(old_level);
    /* Since decrementing ref cannot be guaranteed to be a single machine operation
     * we must protect it. We put the new ref into a local variable to prevent
     * further protection. */
    SYS_ARCH_PROTECT(old_level);
    /* all pbufs in a chain are referenced at least once */
    LWIP_ASSERT("pbuf_free: p->ref > 0", p->ref > 0);
    /* decrease reference count (number of pointers to pbuf) */
    ref = --(p->ref);
    SYS_ARCH_UNPROTECT(old_level);
    /* this pbuf is no longer referenced to? */
    if (ref == 0) {
      /* remember next pbuf in chain for next iteration */
      q = p->next;
      LWIP_DEBUGF( PBUF_DEBUG | LWIP_DBG_TRACE, ("pbuf_free: deallocating %p\n", (void *)p));
      alloc_src = pbuf_get_allocsrc(p);
#if LWIP_SUPPORT_CUSTOM_PBUF
      /* is this a custom pbuf? */
      if ((p->flags & PBUF_FLAG_IS_CUSTOM) != 0) {
        struct pbuf_custom *pc = (struct pbuf_custom *)p;
        LWIP_ASSERT("pc->custom_free_function != NULL", pc->custom_free_function != NULL);
        pc->custom_free_function(p);
      } else
#endif /* LWIP_SUPPORT_CUSTOM_PBUF */
      {
        /* is this a pbuf from the pool? */
        if (alloc_src == PBUF_TYPE_ALLOC_SRC_MASK_STD_MEMP_PBUF_POOL) {
          memp_free(MEMP_PBUF_POOL, p);
          /* is this a ROM or RAM referencing pbuf? */
        } else if (alloc_src == PBUF_TYPE_ALLOC_SRC_MASK_STD_MEMP_PBUF) {
          memp_free(MEMP_PBUF, p);
          /* type == PBUF_RAM */
        } else if (alloc_src == PBUF_TYPE_ALLOC_SRC_MASK_STD_HEAP) {
          mem_free(p);
        } else {
          /* @todo: support freeing other types */
          LWIP_ASSERT("invalid pbuf type", 0);
        }
      }
      count++;
      /* proceed to next pbuf */
      p = q;
      /* p->ref > 0, this pbuf is still referenced to */
      /* (and so the remaining pbufs in chain as well) */
    } else {
      LWIP_DEBUGF( PBUF_DEBUG | LWIP_DBG_TRACE, ("pbuf_free: %p has ref %"U16_F", ending here.\n", (void *)p, (u16_t)ref));
      /* stop walking through the chain */
      p = NULL;
    }
  }
  PERF_STOP("pbuf_free");
  /* return number of de-allocated pbufs */
  return count;
}
#if LWIP_TCP && TCP_QUEUE_OOSEQ && LWIP_WND_SCALE
#endif /* LWIP_TCP && TCP_QUEUE_OOSEQ && LWIP_WND_SCALE */
#if LWIP_CHECKSUM_ON_COPY
#endif /* LWIP_CHECKSUM_ON_COPY */
pbuf_memcmp(const struct pbuf *p, u16_t offset, const void *s2, u16_t n)
{
  u16_t start = offset;
  const struct pbuf *q = p;
  u16_t i;

  /* pbuf long enough to perform check? */
  if (p->tot_len < (offset + n)) {
    return 0xffff;
  }

  /* get the correct pbuf from chain. We know it succeeds because of p->tot_len check above. */
  while ((q != NULL) && (q->len <= start)) {
    start = (u16_t)(start - q->len);
    q = q->next;
  }

  /* return requested data if pbuf is OK */
  for (i = 0; i < n; i++) {
    /* We know pbuf_get_at() succeeds because of p->tot_len check above. */
    u8_t a = pbuf_get_at(q, (u16_t)(start + i));
    u8_t b = ((const u8_t *)s2)[i];
    if (a != b) {
      return (u16_t)LWIP_MIN(i + 1, 0xFFFF);
    }
  }
  return 0;
}
pbuf_memfind(const struct pbuf *p, const void *mem, u16_t mem_len, u16_t start_offset)
{
  u16_t i;
  u16_t max_cmp_start = (u16_t)(p->tot_len - mem_len);
  if (p->tot_len >= mem_len + start_offset) {
    for (i = start_offset; i <= max_cmp_start; i++) {
      u16_t plus = pbuf_memcmp(p, i, mem, mem_len);
      if (plus == 0) {
        return i;
      }
    }
  }
  return 0xFFFF;
}
