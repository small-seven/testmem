#include <sys/time.h>
#include <stdlib.h>
#include <debug.h>
#include <unistd.h>
#include "lwip/opt.h"
#include "lwip/sockets.h"
#include "xdr_subs.h"
#include "nfs_proto.h"
#include "rpc.h"
#ifdef CONFIG_NFS_STATISTICS
#  define rpc_statistics(n) do { rpcstats.n++; } while (0)
#else
#  define rpc_statistics(n)
#endif
#undef  OK
#define OK 0
#define RPCCLNT_FH_LEN                  4
#define RPCCLNT_RECV_BUF_MAX_LEN        64
#define RPCCLNT_CONNECT_MAX_RETRY_TIMES 1024
#ifdef CONFIG_NFS_STATISTICS
#endif
#if (NFS_PROTO_TYPE == NFS_IPPROTO_UDP)
#define CONFIG_NFS_RECV_TIMEOUT 200 /* udp-nfs recv timeout in milli seconds */
#elif (NFS_PROTO_TYPE == NFS_IPPROTO_TCP)
#define CONFIG_NFS_RECV_TIMEOUT 5000 /* tcp-nfs recv timeout in milli seconds */
#endif
#if (NFS_PROTO_TYPE == NFS_IPPROTO_UDP)
#endif
#if (NFS_PROTO_TYPE == NFS_IPPROTO_TCP)
#endif
#if (NFS_PROTO_TYPE == NFS_IPPROTO_TCP)
#endif
#if (NFS_PROTO_TYPE == NFS_IPPROTO_UDP)
#endif
#if (NFS_PROTO_TYPE == NFS_IPPROTO_UDP)
#else
#endif
