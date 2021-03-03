#include "lwip/apps/netbiosns.h"
#if LWIP_IPV4 && LWIP_UDP  /* don't build if not configured for use in lwipopts.h */
#include "lwip/def.h"
#include "lwip/udp.h"
#include "lwip/ip.h"
#include "lwip/netif.h"
#include "lwip/prot/iana.h"
#include <string.h>
#define NETBIOS_NAME_LEN 16
#define NETBIOS_NAME_TTL 300000u
#define NETB_HFLAG_RESPONSE           0x8000U
#define NETB_HFLAG_OPCODE             0x7800U
#define NETB_HFLAG_OPCODE_NAME_QUERY  0x0000U
#define NETB_HFLAG_AUTHORATIVE        0x0400U
#define NETB_HFLAG_TRUNCATED          0x0200U
#define NETB_HFLAG_RECURS_DESIRED     0x0100U
#define NETB_HFLAG_RECURS_AVAILABLE   0x0080U
#define NETB_HFLAG_BROADCAST          0x0010U
#define NETB_HFLAG_REPLYCODE          0x0008U
#define NETB_HFLAG_REPLYCODE_NOERROR  0x0000U
#define NETB_QTYPE_NB                 0x0020U
#define NETB_QTYPE_NBSTAT             0x0021U
#define NETB_NFLAG_UNIQUE             0x8000U
#define NETB_NFLAG_NODETYPE           0x6000U
#define NETB_NFLAG_NODETYPE_HNODE     0x6000U
#define NETB_NFLAG_NODETYPE_MNODE     0x4000U
#define NETB_NFLAG_NODETYPE_PNODE     0x2000U
#define NETB_NFLAG_NODETYPE_BNODE     0x0000U
#define NETB_NFLAG_NAME_IN_CONFLICT   0x0800U /* 1=Yes, 0=No */
#define NETB_NFLAG_NAME_IS_ACTIVE     0x0400U /* 1=Yes, 0=No */
#define NETB_NFLAG_NAME_IS_PERMANENT  0x0200U /* 1=Yes (Name is Permanent Node Name), 0=No */
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
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
#define OFFSETOF_STRUCT_NETBIOS_ANSWER_NUMBER_OF_NAMES 56
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif
#ifdef NETBIOS_LWIP_NAME
#define NETBIOS_LOCAL_NAME NETBIOS_LWIP_NAME
#else
#define NETBIOS_LOCAL_NAME netbiosns_local_name
#endif
#if 0 /* function currently unused */
#endif /* 0 */
#if LWIP_NETBIOS_RESPOND_NAME_QUERY
#endif /* LWIP_NETBIOS_RESPOND_NAME_QUERY */
#ifdef NETBIOS_LWIP_NAME
#endif
#ifndef NETBIOS_LWIP_NAME
#endif /* NETBIOS_LWIP_NAME */
#endif /* LWIP_IPV4 && LWIP_UDP */
