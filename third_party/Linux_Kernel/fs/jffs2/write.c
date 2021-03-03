#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/pagemap.h>
#include <linux/semaphore.h>
#include "mtd_dev.h"
#include "nodelist.h"
#include "compr.h"
#include "los_crc32.h"
int jffs2_do_create(struct jffs2_sb_info *c, struct jffs2_inode_info *dir_f,
		    struct jffs2_inode_info *f, struct jffs2_raw_inode *ri,
		    const char *name, int namelen)
{
	struct jffs2_raw_dirent *rd;
	struct jffs2_full_dnode *fn;
	struct jffs2_full_dirent *fd;
	uint32_t alloclen;
	int ret;

	/* Try to reserve enough space for both node and dirent.
	 * Just the node will do for now, though
	 */
	ret = jffs2_reserve_space(c, sizeof(*ri), &alloclen, ALLOC_NORMAL,
				JFFS2_SUMMARY_INODE_SIZE);
	jffs2_dbg(1, "%s(): reserved 0x%x bytes\n", __func__, alloclen);
	if (ret)
		return ret;

	mutex_lock(&f->sem);

	ri->data_crc = cpu_to_je32(0);
	ri->node_crc = cpu_to_je32(crc32(0, ri, sizeof(*ri)-8));

	fn = jffs2_write_dnode(c, f, ri, NULL, 0, ALLOC_NORMAL);

	jffs2_dbg(1, "jffs2_do_create created file with mode 0x%x\n",
		  jemode_to_cpu(ri->mode));

	if (IS_ERR(fn)) {
		jffs2_dbg(1, "jffs2_write_dnode() failed,error:%ld\n",
		    PTR_ERR(fn));
		/* Eeek. Wave bye bye */
		mutex_unlock(&f->sem);
		jffs2_complete_reservation(c);
		return PTR_ERR(fn);
	}
	/* No data here. Only a metadata node, which will be
	   obsoleted by the first data write
	*/
	f->metadata = fn;

	mutex_unlock(&f->sem);
	jffs2_complete_reservation(c);

	ret = jffs2_reserve_space(c, sizeof(*rd)+ namelen, &alloclen,
				ALLOC_NORMAL, JFFS2_SUMMARY_DIRENT_SIZE(namelen));

	if (ret) {
		/* Eep. */
		jffs2_dbg(1, "jffs2_reserve_space() for dirent failed,ret:%d\n",ret);
		return ret;
	}

	rd = jffs2_alloc_raw_dirent();
	if (!rd) {
		/* Argh. Now we treat it like a normal delete */
		jffs2_complete_reservation(c);
		return -ENOMEM;
	}

	mutex_lock(&dir_f->sem);

	rd->magic = cpu_to_je16(JFFS2_MAGIC_BITMASK);
	rd->nodetype = cpu_to_je16(JFFS2_NODETYPE_DIRENT);
	rd->totlen = cpu_to_je32(sizeof(*rd) + namelen);
	rd->hdr_crc = cpu_to_je32(crc32(0, rd, sizeof(struct jffs2_unknown_node)-4));

	rd->pino = cpu_to_je32(dir_f->inocache->ino);
	rd->version = cpu_to_je32(++dir_f->highest_version);
	rd->ino = ri->ino;
	rd->mctime = ri->ctime;
	rd->nsize = namelen;
	rd->type = DT_REG;
	rd->node_crc = cpu_to_je32(crc32(0, rd, sizeof(*rd)-8));
	rd->name_crc = cpu_to_je32(crc32(0, name, namelen));

	fd = jffs2_write_dirent(c, dir_f, rd, (const unsigned char *)name, namelen, ALLOC_NORMAL);

	jffs2_free_raw_dirent(rd);

	if (IS_ERR(fd)) {
		/* dirent failed to write. Delete the inode normally
		   as if it were the final unlink() */
		jffs2_complete_reservation(c);
		mutex_unlock(&dir_f->sem);
		return PTR_ERR(fd);
	}

	/* Link the fd into the inode's list, obsoleting an old
	   one if necessary. */
	jffs2_add_fd_to_list(c, fd, &dir_f->dents);

	jffs2_complete_reservation(c);
	mutex_unlock(&dir_f->sem);

	return 0;
}
