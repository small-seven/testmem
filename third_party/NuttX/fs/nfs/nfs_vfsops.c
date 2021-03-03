#include <sys/mount.h>
#include <sys/socket.h>
#include <sys/statfs.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <semaphore.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>
#include <pthread.h>
#include <unistd.h>
#include "lwip/opt.h"
#include "lwip/sockets.h"
#include "vfs_config.h"
#include "dirent.h"
#include "fs/fs.h"
#include "fs/dirent_fs.h"
#include "nfs.h"
#include "nfs_node.h"
#include "xdr_subs.h"
#include "los_tables.h"
#include "inode/inode.h"
#include "los_vm_filemap.h"
#include "user_copy.h"
#ifdef LOSCFG_FS_NFS
#define USE_GUARDED_CREATE    1
#if NFSX_V3FHMAX != DIRENT_NFS_MAXHANDLE
#  error "Length of file handle in fs_dirent_s is incorrect"
#endif
#if NFSX_V3COOKIEVERF != DIRENT_NFS_VERFLEN
#  error "Length of cookie verify in fs_dirent_s is incorrect"
#endif
#define MIN_IPv4_UDP_MSS (IP_FRAG_MAX_MTU - (14 + 20)) /* (Ethernet MTU - (Eth header size + IP header size)) */
#define FILENAME_MAX_LEN 50
#ifdef CONFIG_NFS_STATISTICS
#endif
#define NFS_DIR_ENTRY_MALLOC(entry)                                           \
#define NFS_DIR_ENTRY_FREE(entry)  \
static int nfs_filecreate(FAR struct nfsmount *nmp, FAR struct nfsnode *np,
                          FAR const char *relpath, int oflags, mode_t mode)
{
  struct file_handle      fhandle;
  struct nfs_fattr        fattr;
  char                    filename[NAME_MAX + 1];
  FAR uint32_t           *ptr;
  uint32_t                tmp;
  int                     namelen;
  int                     reqlen;
  int                     error;

  /* Find the NFS node of the directory containing the file to be created */

  error = nfs_finddir(nmp, relpath, &fhandle, &fattr, filename);
  if (error != OK)
    {
      ferr("ERROR: nfs_finddir returned: %d\n", error);
      return error;
    }

  /* Create the CREATE RPC call arguments */

  ptr    = (FAR uint32_t *)&nmp->nm_msgbuffer.create.create;
  reqlen = 0;

  /* Copy the variable length, directory file handle */

  *ptr++  = txdr_unsigned(fhandle.length);
  reqlen += sizeof(uint32_t);

  memcpy(ptr, &fhandle.handle, fhandle.length);
  reqlen += (int)fhandle.length;
  ptr    += uint32_increment(fhandle.length);

  /* Copy the variable-length file name */

  namelen = strlen(filename);

  *ptr++  = txdr_unsigned(namelen);
  reqlen += sizeof(uint32_t);

  memcpy(ptr, filename, namelen);
  ptr    += uint32_increment(namelen);
  reqlen += uint32_alignup(namelen);

  /* Set the creation mode */

#ifdef USE_GUARDED_CREATE
  *ptr++  = htonl(NFSV3CREATE_GUARDED);
#else
  *ptr++  = htonl(NFSV3CREATE_EXCLUSIVE);
#endif

  reqlen += sizeof(uint32_t);

  /* Mode information is not provided if EXCLUSIVE creation is used.
   * in this case, we must call SETATTR after successfully creating
   * the file.
   */

#ifndef USE_GUARDED_CREATE
  if ((oflags & O_CREAT) == 0)
#endif
    {
      /* Set the mode.  NOTE: Here we depend on the fact that the NuttX and NFS
       * bit settings are the same (at least for the bits of interest).
       */

      *ptr++  = nfs_true; /* True: mode value follows */
      reqlen += sizeof(uint32_t);

      tmp = mode & (NFSMODE_IWOTH | NFSMODE_IROTH | NFSMODE_IWGRP |
                    NFSMODE_IRGRP | NFSMODE_IWUSR | NFSMODE_IRUSR);
      *ptr++  = txdr_unsigned(tmp);
      reqlen += sizeof(uint32_t);

      /* Set the user ID to zero */

      *ptr++  = nfs_true;             /* True: Uid value follows */
      *ptr++  = 0;                    /* UID = 0 (nobody) */
      reqlen += 2*sizeof(uint32_t);

      /* Set the group ID to one */

      *ptr++  = nfs_true;            /* True: Gid value follows */
      *ptr++  = htonl(1);            /* GID = 1 (nogroup) */
      reqlen += 2*sizeof(uint32_t);

      /* Set the size to zero */

      *ptr++  = nfs_true;            /* True: Size value follows */
      *ptr++  = 0;                   /* Size = 0 */
      *ptr++  = 0;
      reqlen += 3*sizeof(uint32_t);

      /* Don't change times */

      *ptr++  = htonl(NFSV3SATTRTIME_DONTCHANGE); /* Don't change atime */
      *ptr++  = htonl(NFSV3SATTRTIME_DONTCHANGE); /* Don't change mtime */
      reqlen += 2*sizeof(uint32_t);
    }

  /* Send the NFS request.  Note there is special logic here to handle version 3
   * exclusive open semantics.
   */

  do
    {
      nfs_statistics(NFSPROC_CREATE);
      error = nfs_request(nmp, NFSPROC_CREATE,
                          (FAR void *)&nmp->nm_msgbuffer.create, reqlen,
                          (FAR void *)nmp->nm_iobuffer, nmp->nm_buflen);
    }
#ifdef USE_GUARDED_CREATE
  while (0);
#else
  while (((oflags & O_CREAT) != 0) && error == EOPNOTSUPP);
#endif

  /* Check for success */

  if (error == OK)
    {
      /* Parse the returned data */

      ptr = (FAR uint32_t *)&((FAR struct rpc_reply_create *)
        nmp->nm_iobuffer)->create;

      /* Save the file handle in the file data structure */

      tmp = *ptr++;  /* handle_follows */
      if (!tmp)
        {
          ferr("ERROR: no file handle follows\n");
          return EINVAL;
        }

      tmp = *ptr++;
      tmp = fxdr_unsigned(uint32_t, tmp);
      DEBUGASSERT(tmp <= NFSX_V3FHMAX);

      np->n_fhsize      = (uint8_t)tmp;
      memcpy(&np->n_fhandle, ptr, tmp);
      ptr += uint32_increment(tmp);

      /* Save the attributes in the file data structure */

      tmp = *ptr;  /* handle_follows */
      if (!tmp)
        {
          fwarn("WARNING: no file attributes\n");
        }
      else
        {
          /* Initialize the file attributes */

          nfs_attrupdate(np, (FAR struct nfs_fattr *)ptr);
        }

      /* Any following dir_wcc data is ignored for now */
    }

  return error;
}
#if 0
#endif
static int nfs_remove(struct inode *mountpt, const char *relpath)
{
  FAR struct nfsmount    *nmp;
  struct file_handle      fhandle;
  struct file_handle      obj_fhandle;
  struct nfs_fattr        fattr;
  struct nfs_fattr        obj_fattr;
  char                    filename[NAME_MAX + 1];
  FAR uint32_t           *ptr;
  uint32_t                f_type;
  int                     namelen;
  int                     reqlen;
  int                     error;

  /* Sanity checks */

  DEBUGASSERT(mountpt && mountpt->i_private);

  /* Get the mountpoint private data from the inode structure */

  nmp = (FAR struct nfsmount *)mountpt->i_private;

  /* Check if the mount is still healthy */

  nfs_mux_take(nmp);
  error = nfs_checkmount(nmp);
  if (error != OK)
    {
      ferr("ERROR: nfs_checkmount failed: %d\n", error);
      goto errout_with_mutex;
    }

  /* Find the NFS node of the directory containing the file to be deleted */

  error = nfs_finddir(nmp, relpath, &fhandle, &fattr, filename);
  if (error != OK)
    {
      ferr("ERROR: nfs_finddir returned: %d\n", error);
      goto errout_with_mutex;
    }

  /* Check whether the file to be deleted is a directory */

  memcpy(&obj_fhandle, &fhandle, sizeof(struct file_handle));
  error = nfs_lookup(nmp, filename, &obj_fhandle, &obj_fattr, NULL);
  if (error != OK)
    {
      ferr("ERROR: nfs_lookup returned: %d\n", error);
      goto errout_with_mutex;
    }
  f_type = fxdr_unsigned(uint32_t, obj_fattr.fa_type);
  if (f_type == NFDIR)
    {
      ferr("ERROR: try to remove a directory\n");
      error = NFSERR_ISDIR;
      goto errout_with_mutex;
    }

  /* Create the REMOVE RPC call arguments */

  ptr    = (FAR uint32_t *)&nmp->nm_msgbuffer.removef.remove;
  reqlen = 0;

  /* Copy the variable length, directory file handle */

  *ptr++  = txdr_unsigned(fhandle.length);
  reqlen += sizeof(uint32_t);

  memcpy(ptr, &fhandle.handle, fhandle.length);
  reqlen += (int)fhandle.length;
  ptr    += uint32_increment(fhandle.length);

  /* Copy the variable-length file name */

  namelen = strlen(filename);

  *ptr++  = txdr_unsigned(namelen);
  reqlen += sizeof(uint32_t);

  memcpy(ptr, filename, namelen);
  reqlen += uint32_alignup(namelen);

  /* Perform the REMOVE RPC call */

  nfs_statistics(NFSPROC_REMOVE);
  error = nfs_request(nmp, NFSPROC_REMOVE,
                      (FAR void *)&nmp->nm_msgbuffer.removef, reqlen,
                      (FAR void *)nmp->nm_iobuffer, nmp->nm_buflen);

errout_with_mutex:
  nfs_mux_release(nmp);
  return -error;
}
#if (NFS_PROTO_TYPE == NFS_IPPROTO_TCP)
#elif (NFS_PROTO_TYPE == NFS_IPPROTO_UDP)
#endif
#endif
