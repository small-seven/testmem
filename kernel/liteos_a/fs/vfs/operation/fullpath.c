#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "errno.h"
#include "limits.h"
#include "los_process_pri.h"
#include "fs/fd_table.h"
#include "fs/file.h"
#ifdef LOSCFG_SHELL
#include "shell.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef LOSCFG_SHELL
#define TEMP_PATH_MAX (PATH_MAX + SHOW_MAX_LEN)
#else
#define TEMP_PATH_MAX  PATH_MAX
#endif
static void str_remove_path_end_slash(char *dest, const char *fullpath)
{
    if ((*dest == '.') && (*(dest - 1) == '/')) {
        *dest = '\0';
        dest--;
    }
    if ((dest != fullpath) && (*dest == '/')) {
        *dest = '\0';
    }
}
#ifdef VFS_USING_WORKDIR
#endif
#ifdef VFS_USING_WORKDIR
#else
#endif
#ifdef VFS_USING_WORKDIR
#endif
#ifdef VFS_USING_WORKDIR
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
