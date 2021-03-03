#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/statfs.h>
#include <errno.h>
#include "los_config.h"
#if defined(LOSCFG_SHELL_CMD_DEBUG) && defined(LOSCFG_FS_PROC)
#include "los_typedef.h"
#include "los_typedef.h"
#include "shell.h"
#include "shcmd.h"
#include "proc_file.h"
#include "inode/inode.h"
#include "dirent.h"
#include "fs/fs.h"
#include "proc_fs.h"

#define WRITEPROC_ARGC  3

int OsShellCmdWriteProc(int argc, char **argv)
{
    int i;
    int ret;
    const char *path = NULL;
    const char *value = NULL;
    unsigned int len;
    struct ProcDirEntry *handle = NULL;
    char realPath[PATH_MAX] = {'\0'};
#endif
