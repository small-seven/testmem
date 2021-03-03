#include "curl_setup.h"
#ifndef CURL_DISABLE_FTP
#include <curl/curl.h>
#include "urldata.h"
#include "fileinfo.h"
#include "llist.h"
#include "strtoofft.h"
#include "ftp.h"
#include "ftplistparser.h"
#include "curl_fnmatch.h"
#include "curl_memory.h"
#include "multiif.h"
#include "memdebug.h"
#define FTP_BUFFER_ALLOCSIZE 160
typedef enum {
  PL_UNIX_TOTALSIZE = 0,
  PL_UNIX_FILETYPE,
  PL_UNIX_PERMISSION,
  PL_UNIX_HLINKS,
  PL_UNIX_USER,
  PL_UNIX_GROUP,
  PL_UNIX_SIZE,
  PL_UNIX_TIME,
  PL_UNIX_FILENAME,
  PL_UNIX_SYMLINK
} pl_unix_mainstate;
typedef union {
  enum {
    PL_UNIX_TOTALSIZE_INIT = 0,
    PL_UNIX_TOTALSIZE_READING
  } total_dirsize;
typedef enum {
  PL_WINNT_DATE = 0,
  PL_WINNT_TIME,
  PL_WINNT_DIRORSIZE,
  PL_WINNT_FILENAME
} pl_winNT_mainstate;
typedef union {
  enum {
    PL_WINNT_TIME_PRESPACE = 0,
    PL_WINNT_TIME_TIME
  } time;
void Curl_ftp_parselist_data_free(struct ftp_parselist_data **parserp)
{
  struct ftp_parselist_data *parser = *parserp;
  if(parser)
    Curl_fileinfo_cleanup(parser->file_data);
  free(parser);
  *parserp = NULL;
}
#define FTP_LP_MALFORMATED_PERM 0x01000000
#endif /* CURL_DISABLE_FTP */
