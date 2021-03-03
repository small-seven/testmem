#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/time.h>
#include <linux/spinlock.h>
#include "fs/dirent_fs.h"
#include "los_tables.h"
#include "fs_tmpfs.h"
#include "los_vm_filemap.h"
#include "user_copy.h"
#ifdef LOSCFG_FS_RAMFS
#if CONFIG_FS_TMPFS_DIRECTORY_FREEGUARD <= CONFIG_FS_TMPFS_DIRECTORY_ALLOCGUARD
#  warning CONFIG_FS_TMPFS_DIRECTORY_FREEGUARD needs to be > ALLOCGUARD
#endif
#if CONFIG_FS_TMPFS_FILE_FREEGUARD <= CONFIG_FS_TMPFS_FILE_ALLOCGUARD
#  warning CONFIG_FS_TMPFS_FILE_FREEGUARD needs to be > ALLOCGUARD
#endif
#define tmpfs_lock_file(tfo) \
#define tmpfs_lock_directory(tdo) \
#define tmpfs_unlock_file(tfo) \
#define tmpfs_unlock_directory(tdo) \
static void tmpfs_release_lockedobject(FAR struct tmpfs_object_s *to)
{
  DEBUGASSERT(to && to->to_refs > 0);

  /* Is this a file object? */

  if (to->to_type == TMPFS_REGULAR)
    {
      tmpfs_release_lockedfile((FAR struct tmpfs_file_s *)to);
    }
  else
    {
      to->to_refs--;
      tmpfs_unlock_object(to);
    }
}
static void tmpfs_release_lockedfile(FAR struct tmpfs_file_s *tfo)
{
  DEBUGASSERT(tfo && tfo->tfo_refs > 0);

  /* If there are no longer any references to the file and the file has been
   * unlinked from its parent directory, then free the file object now.
   */

  if (tfo->tfo_refs == 1 && (tfo->tfo_flags & TFO_FLAG_UNLINKED) != 0)
    {
      sem_destroy(&tfo->tfo_exclsem.ts_sem);
      kmm_free(tfo->tfo_data);
      kmm_free(tfo);
    }

  /* Otherwise, just decrement the reference count on the file object */

  else
    {
      tfo->tfo_refs--;
      tmpfs_unlock_file(tfo);
    }
}
static int tmpfs_remove_dirent(FAR struct tmpfs_directory_s *tdo,
                               FAR struct tmpfs_object_s *to)
{
  struct tmpfs_dirent_s *tde;

  /* Search the list of directory entries for a match */

  tde = to->to_dirent;
  if (tde == NULL)
    {
      return -ENONET;
    }

  /* Free the object name */

  if (tde->tde_name != NULL)
    {
      kmm_free(tde->tde_name);
      tde->tde_name = NULL;
    }

  if (tdo->tdo_count == 0)
    {
      LOS_ListDelete(&tde->tde_node);
      kmm_free(tde);
    }
  else
    {
      tde->tde_inuse = false;
      tde->tde_object = NULL;
    }

  tdo->tdo_nentries--;
  return OK;
}
static FAR struct tmpfs_file_s *tmpfs_alloc_file(void)
{
  FAR struct tmpfs_file_s *tfo;
  size_t allocsize;

  /* Create a new zero length file object */

  allocsize = sizeof(struct tmpfs_file_s);
  tfo = (FAR struct tmpfs_file_s *)kmm_malloc(allocsize);
  if (tfo == NULL)
    {
      return NULL;
    }

  /* Initialize the new file object.  NOTE that the initial state is
   * locked with one reference count.
   */

  tfo->tfo_atime = tmpfs_timestamp();
  tfo->tfo_mtime = tfo->tfo_atime;
  tfo->tfo_ctime = tfo->tfo_atime;
  tfo->tfo_type  = TMPFS_REGULAR;
  tfo->tfo_refs  = 1;
  tfo->tfo_flags = 0;
  tfo->tfo_size  = 0;
  tfo->tfo_data  = NULL;

  tfo->tfo_exclsem.ts_holder = getpid();
  tfo->tfo_exclsem.ts_count  = 1;
  if (sem_init(&tfo->tfo_exclsem.ts_sem, 0, 0) != 0)
    {
      PRINT_ERR("%s %d, sem_init failed!\n", __FUNCTION__, __LINE__);
      kmm_free(tfo);
      return NULL;
    }

  return tfo;
}
static int tmpfs_create_file(FAR struct tmpfs_s *fs,
                             FAR const char *relpath,
                             FAR struct tmpfs_file_s **tfo)
{
  FAR struct tmpfs_directory_s *parent;
  FAR struct tmpfs_file_s *newtfo;
  struct tmpfs_dirent_s *tde;
  FAR char *copy;
  FAR char *name;
  int ret;

  /* Duplicate the path variable so that we can modify it */

  copy = strdup(relpath);
  if (copy == NULL)
    {
      return -ENOSPC;
    }

  /* Separate the path into the file name and the path to the parent
   * directory.
   */

  name = strrchr(copy, '/');
  if (name == NULL)
    {
      /* No subdirectories... use the root directory */

      name   = copy;
      parent = (FAR struct tmpfs_directory_s *)fs->tfs_root.tde_object;

      /* Lock the root directory to emulate the behavior of tmpfs_find_directory() */

      tmpfs_lock_directory(parent);
      parent->tdo_refs++;
    }
  else
    {
      /* Terminate the parent directory path */

      *name++ = '\0';

      /* Locate the parent directory that should contain this name.
       * On success, tmpfs_find_directory() will lock the parent
       * directory and increment the reference count.
       */

      ret = tmpfs_find_directory(fs, copy, &parent, NULL);
      if (ret < 0)
        {
          goto errout_with_copy;
        }
    }

  /* Verify that no object of this name already exists in the directory */

  tde = tmpfs_find_dirent(parent, name);
  if (tde != NULL)
    {
      /* Something with this name already exists in the directory.
       * OR perhaps some fatal error occurred.
       */

      ret = -EEXIST;
      goto errout_with_parent;
    }

  /* Allocate an empty file.  The initial state of the file is locked with one
   * reference count.
   */

  newtfo = tmpfs_alloc_file();
  if (newtfo == NULL)
    {
      ret = -ENOSPC;
      goto errout_with_parent;
    }

  /* Then add the new, empty file to the directory */

  ret = tmpfs_add_dirent(&parent, (FAR struct tmpfs_object_s *)newtfo, name);
  if (ret < 0)
    {
      goto errout_with_file;
    }

  /* Release the reference and lock on the parent directory */

  parent->tdo_refs--;
  tmpfs_unlock_directory(parent);

  /* Free the copy of the relpath and return success */

  kmm_free(copy);
  *tfo = newtfo;
  return OK;

  /* Error exits */

errout_with_file:
  sem_destroy(&newtfo->tfo_exclsem.ts_sem);
  kmm_free(newtfo);

errout_with_parent:
  parent->tdo_refs--;
  tmpfs_unlock_directory(parent);

errout_with_copy:
  kmm_free(copy);
  return ret;
}
static FAR struct tmpfs_directory_s *tmpfs_alloc_directory(void)
{
  FAR struct tmpfs_directory_s *tdo;
  size_t allocsize;

  allocsize = sizeof(struct tmpfs_directory_s);
  tdo = (FAR struct tmpfs_directory_s *)kmm_malloc(allocsize);
  if (tdo == NULL)
    {
      return NULL;
    }

  /* Initialize the new directory object */

  tdo->tdo_atime    = tmpfs_timestamp();
  tdo->tdo_mtime    = tdo->tdo_mtime;
  tdo->tdo_ctime    =  tdo->tdo_mtime;
  tdo->tdo_type     = TMPFS_DIRECTORY;
  tdo->tdo_refs     = 0;
  tdo->tdo_nentries = 0;
  tdo->tdo_count    = 0;
  LOS_ListInit(&tdo->tdo_entry);

  tdo->tdo_exclsem.ts_holder = TMPFS_NO_HOLDER;
  tdo->tdo_exclsem.ts_count  = 0;
  if (sem_init(&tdo->tdo_exclsem.ts_sem, 0, 1) != 0)
    {
      PRINT_ERR("%s %d, sem_init failed!\n", __FUNCTION__, __LINE__);
      kmm_free(tdo);
      return NULL;
    }
  return tdo;
}
static int tmpfs_create_directory(FAR struct tmpfs_s *fs,
                                  FAR const char *relpath,
                                  FAR struct tmpfs_directory_s **tdo)
{
  FAR struct tmpfs_directory_s *parent;
  FAR struct tmpfs_directory_s *newtdo;
  struct tmpfs_dirent_s *tde;
  FAR char *copy;
  FAR char *name;
  int ret;

  /* Duplicate the path variable so that we can modify it */

  copy = strdup(relpath);
  if (copy == NULL)
    {
      return -ENOSPC;
    }

  /* Separate the path into the file name and the path to the parent
   * directory.
   */

  name = strrchr(copy, '/');
  if (name == NULL)
    {
      /* No subdirectories... use the root directory */

      name   = copy;
      parent = (FAR struct tmpfs_directory_s *)fs->tfs_root.tde_object;

      tmpfs_lock_directory(parent);
      parent->tdo_refs++;
    }
  else
    {
      /* Terminate the parent directory path */

      *name++ = '\0';

      /* Locate the parent directory that should contain this name.
       * On success, tmpfs_find_directory() will lockthe parent
       * directory and increment the reference count.
       */

      ret = tmpfs_find_directory(fs, copy, &parent, NULL);
      if (ret < 0)
        {
          goto errout_with_copy;
        }
    }

  /* Verify that no object of this name already exists in the directory */

  tde = tmpfs_find_dirent(parent, name);
  if (tde != NULL)
    {
      /* Something with this name already exists in the directory.
       * OR perhaps some fatal error occurred.
       */

      ret = -EEXIST;

      goto errout_with_parent;
    }

  /* Allocate an empty directory object.  NOTE that there is no reference on
   * the new directory and the object is not locked.
   */

  newtdo = tmpfs_alloc_directory();
  if (newtdo == NULL)
    {
      ret = -ENOSPC;
      goto errout_with_parent;
    }

  /* Then add the new, empty file to the directory */

  ret = tmpfs_add_dirent(&parent, (FAR struct tmpfs_object_s *)newtdo, name);
  if (ret < 0)
    {
      goto errout_with_directory;
    }

  /* Free the copy of the relpath, release our reference to the parent directory,
   * and return success
   */

  parent->tdo_refs--;
  tmpfs_unlock_directory(parent);
  kmm_free(copy);

  /* Return the (unlocked, unreferenced) directory object to the caller */

  if (tdo != NULL)
    {
      *tdo = newtdo;
    }

  return OK;

  /* Error exits */

errout_with_directory:
  sem_destroy(&newtdo->tdo_exclsem.ts_sem);
  kmm_free(newtdo);

errout_with_parent:
  parent->tdo_refs--;
  tmpfs_unlock_directory(parent);

errout_with_copy:
  kmm_free(copy);
  return ret;
}
#if 0
#endif
#endif
