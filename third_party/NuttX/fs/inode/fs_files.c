#include "unistd.h"
#include "vfs_config.h"
#include "sys/types.h"
#include "string.h"
#include "semaphore.h"
#include "assert.h"
#include "errno.h"
#include "fs/fs.h"
#include "fs/file.h"
#include "stdio.h"
#include "stdlib.h"
#include "inode/inode.h"
#include "los_mux.h"
#include "fs/fd_table.h"
#ifdef LOSCFG_NET_LWIP_SACK
#include "lwip/sockets.h"
#include "fs_file.h"
#endif
#include "los_process_pri.h"
#include "los_vm_filemap.h"
#define ferr PRINTK
#if CONFIG_NFILE_DESCRIPTORS > 0
#endif
#if CONFIG_NFILE_STREAMS > 0
#endif
#if CONFIG_NFILE_DESCRIPTORS > 0
#else
#endif
#define _files_semgive(list)  (void)sem_post(&list->fl_sem)
void files_releaselist(FAR struct filelist *list)
{
  int i;

  DEBUGASSERT(list);

  /* Close each file descriptor .. Normally, you would need take the list
   * semaphore, but it is safe to ignore the semaphore in this context because
   * there should not be any references in this context.
   */

  for (i = 0; i < CONFIG_NFILE_DESCRIPTORS; i++)
    {
      (void)_files_close(&list->fl_files[i]);
    }

  /* Destroy the semaphore */

  (void)sem_destroy(&list->fl_sem);
}
#ifndef CONFIG_DISABLE_MOUNTPOINT
#endif
#define FILE_START_FD 3
int files_allocate(FAR struct inode *inode_ptr, int oflags, off_t pos,void* priv, int minfd)
{
  FAR struct filelist *list = NULL;
  unsigned int *p = NULL;
  unsigned int mask;
  unsigned int i;
  struct files_struct *process_files = NULL;

  /* minfd should be a positive number,and 0,1,2 had be distributed to stdin,stdout,stderr */

  if (minfd < FILE_START_FD)
    {
      minfd = FILE_START_FD;
    }
  i = (unsigned int)minfd;

  list = sched_getfiles();
  DEBUGASSERT(list);

  _files_semtake(list);

  while (i < CONFIG_NFILE_DESCRIPTORS)
    {
      p = ((unsigned int *)bitmap) + (i >> 5); /* Gets the location in the bitmap */
      mask = 1 << (i & 0x1f); /* Gets the mask for the current bit int bitmap */
      if ((~(*p) & mask))
        {
          set_bit(i, bitmap);
          list->fl_files[i].f_oflags   = oflags;
          list->fl_files[i].f_pos      = pos;
          list->fl_files[i].f_inode    = inode_ptr;
          list->fl_files[i].f_priv     = priv;
          list->fl_files[i].f_refcount = 1;
          list->fl_files[i].f_mapping  = NULL;
          list->fl_files[i].f_dir      = NULL;
          list->fl_files[i].f_magicnum = files_magic_generate();
          process_files = OsCurrProcessGet()->files;
          if (process_files)
            {
              FD_SET(i, process_files->fdt->open_fds);
            }
          else
            {
              PRINT_ERR("process files is NULL, %s %d\n", __FUNCTION__ ,__LINE__);
              _files_semgive(list);
              return VFS_ERROR;
            }
          _files_semgive(list);
          return (int)i;
        }
      i++;
    }


  _files_semgive(list);
  return VFS_ERROR;
}
void files_release(int fd)
{
  FAR struct filelist *list = NULL;
  struct files_struct *process_files = NULL;

  list = sched_getfiles();
  DEBUGASSERT(list);

  if (fd >=0 && fd < CONFIG_NFILE_DESCRIPTORS)
    {
      _files_semtake(list);

      list->fl_files[fd].f_magicnum = 0;
      list->fl_files[fd].f_oflags   = 0;
      list->fl_files[fd].f_inode    = NULL;
      list->fl_files[fd].f_pos      = 0;
      list->fl_files[fd].f_refcount = 0;
      list->fl_files[fd].f_path     = NULL;
      list->fl_files[fd].f_relpath  = NULL;
      list->fl_files[fd].f_priv     = NULL;
      list->fl_files[fd].f_mapping  = NULL;
      list->fl_files[fd].f_dir      = NULL;

      process_files = OsCurrProcessGet()->files;
      if (process_files)
        {
          FD_CLR(fd, process_files->fdt->open_fds);
        }
      clear_bit(fd, bitmap);
      _files_semgive(list);
    }
}
int alloc_fd(int minfd)
{
  FAR struct filelist *list = NULL;
  unsigned int *p = NULL;
  unsigned int mask;
  unsigned int i;

  /* minfd should be a positive number,and 0,1,2 had be distributed to stdin,stdout,stderr */

  if (minfd < FILE_START_FD)
    {
      minfd = FILE_START_FD;
    }
  i = (unsigned int)minfd;

  list = sched_getfiles();
  DEBUGASSERT(list);

  _files_semtake(list);

  while (i < CONFIG_NFILE_DESCRIPTORS)
    {
      p = ((unsigned int *)bitmap) + (i >> 5); /* Gets the location in the bitmap */
      mask = 1 << (i & 0x1f); /* Gets the mask for the current bit int bitmap */
      if ((~(*p) & mask))
        {
          set_bit(i, bitmap);
          _files_semgive(list);
          return (int)i;
        }
      i++;
    }
  _files_semgive(list);
  return VFS_ERROR;
}
#if defined(LOSCFG_NET_LWIP_SACK)
#endif
static struct fd_table_s * alloc_fd_table(unsigned int numbers)
{
  struct fd_table_s *fdt;
  void *data;

  fdt = LOS_MemAlloc(m_aucSysMem0, sizeof(struct fd_table_s));
  if (!fdt)
    {
      goto out;
    }
  fdt->max_fds = numbers;
  if (!numbers)
    {
      fdt->ft_fds = NULL;
      fdt->open_fds = NULL;
      fdt->proc_fds = NULL;
      return fdt;
    }
  data = LOS_MemAlloc(m_aucSysMem0, numbers * sizeof(struct file_table_s));
  if (!data)
    {
      goto out_fdt;
    }
  fdt->ft_fds = data;

  /* 0,1,2 be distributed to stdin,stdout,stderr default */
  fdt->ft_fds[STDIN_FILENO].sysFd = STDIN_FILENO;
  fdt->ft_fds[STDOUT_FILENO].sysFd = STDOUT_FILENO;
  fdt->ft_fds[STDERR_FILENO].sysFd = STDERR_FILENO;
  for (int i = STDERR_FILENO + 1; i < numbers; i++)
    {
        fdt->ft_fds[i].sysFd = -1;
    }

  data = LOS_MemAlloc(m_aucSysMem0, sizeof(fd_set));
  if (!data)
    {
      goto out_arr;
    }
  (VOID)memset_s(data, sizeof(fd_set), 0, sizeof(fd_set));
  fdt->open_fds = data;
  FD_SET(STDIN_FILENO, fdt->open_fds);
  FD_SET(STDOUT_FILENO, fdt->open_fds);
  FD_SET(STDERR_FILENO, fdt->open_fds);

  data = LOS_MemAlloc(m_aucSysMem0, sizeof(fd_set));
  if (!data)
    {
      goto out_all;
    }
  (VOID)memset_s(data, sizeof(fd_set), 0, sizeof(fd_set));
  fdt->proc_fds = data;
  FD_SET(STDIN_FILENO, fdt->proc_fds);
  FD_SET(STDOUT_FILENO, fdt->proc_fds);
  FD_SET(STDERR_FILENO, fdt->proc_fds);

  (void)sem_init(&fdt->ft_sem, 0, 1);

  return fdt;

out_all:
  (VOID)LOS_MemFree(m_aucSysMem0, fdt->open_fds);
out_arr:
  (VOID)LOS_MemFree(m_aucSysMem0, fdt->ft_fds);
out_fdt:
  (VOID)LOS_MemFree(m_aucSysMem0, fdt);
out:
  return NULL;
}
struct files_struct *alloc_files(void)
{
  struct files_struct *files = LOS_MemAlloc(m_aucSysMem0, sizeof(struct files_struct));
  if (!files)
    {
      ferr("malloc file_struct error\n");
      return NULL;
    }
  files->count = 1;
  files->file_lock = 0;
  files->next_fd = 3;
#ifdef VFS_USING_WORKDIR
  spin_lock_init(&files->workdir_lock);
  memset_s(files->workdir, PATH_MAX, 0, PATH_MAX);
  files->workdir[0] = '/';
#endif
  files->fdt = alloc_fd_table(NR_OPEN_DEFAULT);
  if (!files->fdt)
    {
      ferr("malloc fdt error\n");
      (VOID)LOS_MemFree(m_aucSysMem0, files);
      return NULL;
    }

  return files;
}
#ifdef VFS_USING_WORKDIR
#endif
#if defined(LOSCFG_NET_LWIP_SACK)
#endif
struct files_struct *create_files_snapshot(const struct files_struct *old_files)
{
  struct fd_table_s *old_fdt = NULL;
  struct fd_table_s *new_fdt = NULL;
  struct files_struct *files = NULL;
  if ((old_files == NULL) || (old_files->fdt == NULL) || (old_files->fdt->max_fds == 0))
    {
      return NULL;
    }
  files = LOS_MemAlloc(m_aucSysMem0, sizeof(struct files_struct));
  if (!files)
    {
      PRINT_ERR("malloc file_struct error\n");
      return NULL;
    }
  files->count = 1;
  files->file_lock = 0;
  files->next_fd = old_files->next_fd;
#ifdef VFS_USING_WORKDIR
  spin_lock_init(&files->workdir_lock);
  memset_s(files->workdir, PATH_MAX, 0, PATH_MAX);
  strncpy_s(files->workdir, PATH_MAX - 1, old_files->workdir, PATH_MAX - 1);
#endif
  old_fdt = old_files->fdt;
  new_fdt = alloc_fd_table(old_fdt->max_fds);
  if (new_fdt == NULL)
    {
      PRINT_ERR("alloc fd_table failed\n");
      (VOID)LOS_MemFree(m_aucSysMem0, files);
      return NULL;
    }
  copy_fds((const struct fd_table_s *)new_fdt, (const struct fd_table_s *)old_fdt);
  files->fdt = new_fdt;

  return files;

}
