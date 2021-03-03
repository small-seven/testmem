#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT && VJ_SUPPORT /* don't build if not configured for use in lwipopts.h */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/pppdebug.h"
#include "netif/ppp/vj.h"
#include <string.h>
#if LINK_STATS
#define INCR(counter) ++comp->stats.counter
#else
#define INCR(counter)
#endif
#if MAX_SLOTS == 0
#endif
#define ENCODE(n) { \
#define ENCODEZ(n) { \
#define DECODEL(f) { \
#define DECODES(f) { \
#define DECODEU(f) { \
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif
#if BYTE_ORDER == LITTLE_ENDIAN
#else
#endif
#if IP_FORWARD
#else /* IP_FORWARD */
#endif /* IP_FORWARD */
#endif /* PPP_SUPPORT && VJ_SUPPORT */
