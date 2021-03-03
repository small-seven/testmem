#include "vfs_config.h"
#include "assert.h"
#include "errno.h"
#include "stdlib.h"
#include "fs/fs.h"
#include "fs/dirent_fs.h"
#include "string.h"
#include "inode/inode.h"
#include "capability_api.h"
#include "fs_other.h"
static FAR struct inode *inode_alloc(FAR const char *name)
{
  FAR struct inode *node;
  int namelen;

  namelen = inode_namelen(name);
  node = (FAR struct inode*)LOS_MemAlloc(m_aucSysMem0, FSNODE_SIZE(namelen));
  if (node)
    {
      (void)memset_s(node, FSNODE_SIZE(namelen), 0, FSNODE_SIZE(namelen));
      inode_namecpy(node->i_name, name);
    }

  return node;
}
#ifndef CONFIG_DISABLE_MOUNTPOINT
#endif
