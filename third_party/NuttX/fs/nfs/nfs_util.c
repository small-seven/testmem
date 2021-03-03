#include <sys/types.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <debug.h>
#include <pthread.h>
#include "vfs_config.h"
#include "dirent.h"
#include "rpc.h"
#include "nfs.h"
#include "nfs_node.h"
#include "xdr_subs.h"
#undef  OK
#define OK 0
void nfs_mux_release(struct nfsmount *nmp)
{
  (void)pthread_mutex_unlock(&nmp->nm_mux);
}
