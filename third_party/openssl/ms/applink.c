#define APPLINK_STDIN   1
#define APPLINK_STDOUT  2
#define APPLINK_STDERR  3
#define APPLINK_FPRINTF 4
#define APPLINK_FGETS   5
#define APPLINK_FREAD   6
#define APPLINK_FWRITE  7
#define APPLINK_FSETMOD 8
#define APPLINK_FEOF    9
#define APPLINK_FCLOSE  10      /* should not be used */
#define APPLINK_FOPEN   11      /* solely for completeness */
#define APPLINK_FSEEK   12
#define APPLINK_FTELL   13
#define APPLINK_FFLUSH  14
#define APPLINK_FERROR  15
#define APPLINK_CLEARERR 16
#define APPLINK_FILENO  17      /* to be used with below */
#define APPLINK_OPEN    18      /* formally can't be used, as flags can vary */
#define APPLINK_READ    19
#define APPLINK_WRITE   20
#define APPLINK_LSEEK   21
#define APPLINK_CLOSE   22
#define APPLINK_MAX     22      /* always same as last macro */
#ifndef APPMACROS_ONLY
# include <stdio.h>
# include <io.h>
# include <fcntl.h>
#ifdef __cplusplus
#endif
# if defined(__BORLANDC__)
# else
# endif
#ifdef __cplusplus
#endif
#endif
