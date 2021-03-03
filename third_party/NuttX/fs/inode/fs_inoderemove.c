#include "vfs_config.h"
#include "errno.h"
#include "stdlib.h"
#include "fs/fs.h"
#include "inode/inode.h"
int inode_remove(FAR const char *path)
{
  FAR struct inode *node;

  /* Find the inode and unlink it from the in-memory inode tree */

  node = inode_unlink(path);
  if (node)
    {
      /* Found it! But we cannot delete the inode if there are references
       * to it
       */

      if (node->i_crefs)
        {
          /* In that case, we will mark it deleted, when the filesystem
           * releases the inode, we will then, finally delete the subtree
           */

          node->i_flags |= FSNODEFLAG_DELETED;
          return -EBUSY;
        }
      else
        {
          /* And delete it now -- recursively to delete all of its children.
           * Since it has been unlinked, then the peer pointer should be NULL.
           */

          inode_free(node->i_child);
          (void)LOS_MemFree(m_aucSysMem0, node);
          return OK;
        }
    }

  /* The node does not exist */

  return -ENOENT;
}
