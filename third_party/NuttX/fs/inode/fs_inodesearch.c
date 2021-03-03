#include "vfs_config.h"
#include "assert.h"
#include "errno.h"
#include "semaphore.h"
#include "stdlib.h"
#include "fs/fs.h"
#include "fs_other.h"
#include "inode/inode.h"
void inode_free(FAR struct inode *node)
{
  if (node != NULL)
    {
      inode_free(node->i_peer);
      inode_free(node->i_child);
      (VOID)LOS_MemFree(m_aucSysMem0, node);
    }
}
