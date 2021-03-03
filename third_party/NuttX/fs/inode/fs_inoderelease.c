#include "vfs_config.h"
#include "errno.h"
#include "stdlib.h"
#include "fs/fs.h"
#include "inode/inode.h"
void inode_release(FAR struct inode *node)
{
  if (node)
    {
      /* Decrement the references of the inode */

      inode_semtake();
      if (node->i_crefs)
        {
          node->i_crefs--;
        }

      /* If the subtree was previously deleted and the reference
       * count has decrement to zero,  then delete the inode
       * now.
       */

      if (node->i_crefs <= 0 && (node->i_flags & FSNODEFLAG_DELETED) != 0)
        {
          /* If the inode has been properly unlinked, then the peer pointer
           * should be NULL.
           */

          inode_free(node->i_child);
          (void)LOS_MemFree(m_aucSysMem0, node);
          inode_semgive();
        }
      else
        {
          inode_semgive();
        }
    }
}
