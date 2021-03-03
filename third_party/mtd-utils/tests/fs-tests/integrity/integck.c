#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <dirent.h>
#include <getopt.h>
#include <assert.h>
#include <mntent.h>
#include <sys/mman.h>
#include <sys/vfs.h>
#include <sys/mount.h>
#include <sys/statvfs.h>
#define PROGRAM_NAME "integck"
#include "common.h"
#include "libubi.h"
#include "libmissing.h"
#ifdef INTEGCK_DEBUG
#define static
#endif
#define MAX_RANDOM_SEED 10000000
#define TEST_DIR_PATTERN "integck_test_dir_%u"
#define IO_BUFFER_SIZE 32768
#define stringify1(x) #x
#define stringify(x) stringify1(x)
#define CHECK(cond) do {                                                     \
#define pcv(fmt, ...) do {                                                   \
#define v(fmt, ...) do {                                                     \
static void *zalloc(size_t size)
{
	void *buf = malloc(size);

	CHECK(buf != NULL);
	memset(buf, 0, size);
	return buf;
}
static void open_file_remove(struct fd_info *fdi)
{
	struct open_file_info *ofi;
	struct open_file_info **prev;

	prev = &open_files;
	for (ofi = open_files; ofi; ofi = ofi->next) {
		if (ofi->fdi == fdi) {
			*prev = ofi->next;
			free(ofi);
			open_files_count -= 1;
			return;
		}
		prev = &ofi->next;
	}
	CHECK(0); /* We are trying to remove something that is not there */
}
static int dir_remove(struct dir_info *dir)
{
	char *path;

	/* Remove directory contents */
	while (dir->first) {
		struct dir_entry_info *entry;
		int ret = 0;

		entry = dir->first;
		if (entry->type == 'd')
			ret = dir_remove(entry->dir);
		else if (entry->type == 'f')
			ret = file_unlink(entry);
		else if (entry->type == 's')
			ret = symlink_remove(entry->symlink);
		else
			CHECK(0); /* Invalid struct dir_entry_info */
		if (ret)
			return -1;
	}

	/* Remove directory form the file-system */
	path = dir_path(dir->parent, dir->entry->name);
	if (rmdir(path) != 0) {
		pcv("cannot remove directory entry %s", path);
		free(path);
		return -1;
	}

	if (args.verify_ops) {
		struct stat st;

		CHECK(lstat(path, &st) == -1);
		CHECK(errno == ENOENT);
	}

	/* Remove entry from parent directory */
	remove_dir_entry(dir->entry, 1);

	free(path);
	return 0;
}
static int symlink_remove(struct symlink_info *symlink)
{
	char *path;

	path = dir_path(symlink->entry->parent, symlink->entry->name);
	if (unlink(path) != 0) {
		pcv("cannot unlink symlink %s", path);
		free(path);
		return -1;
	}

	if (args.verify_ops) {
		struct stat st;

		CHECK(lstat(path, &st) == -1);
		CHECK(errno == ENOENT);
	}

	remove_dir_entry(symlink->entry, 1);

	free(path);
	return 0;
}
