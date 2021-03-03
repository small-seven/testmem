#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "zlib.h"
#include "zip.h"
#ifdef STDC
#  include <stddef.h>
#  include <string.h>
#  include <stdlib.h>
#endif
#ifdef NO_ERRNO_H
#else
#   include <errno.h>
#endif
#ifndef local
#  define local static
#endif
#ifndef VERSIONMADEBY
# define VERSIONMADEBY   (0x0) /* platform depedent */
#endif
#ifndef Z_BUFSIZE
#define Z_BUFSIZE (64*1024) //(16384)
#endif
#ifndef Z_MAXFILENAMEINZIP
#define Z_MAXFILENAMEINZIP (256)
#endif
#ifndef ALLOC
# define ALLOC(size) (malloc(size))
#endif
#ifndef TRYFREE
# define TRYFREE(p) {if (p) free(p);}
#endif
#define SIZECENTRALDIRITEM (0x2e)
#define SIZEZIPLOCALHEADER (0x1e)
#define MAKEULONG64(a, b) ((ZPOS64_T)(((unsigned long)(a)) | ((ZPOS64_T)((unsigned long)(b))) << 32))
#ifndef SEEK_CUR
#define SEEK_CUR    1
#endif
#ifndef SEEK_END
#define SEEK_END    2
#endif
#ifndef SEEK_SET
#define SEEK_SET    0
#endif
#ifndef DEF_MEM_LEVEL
#if MAX_MEM_LEVEL >= 8
#  define DEF_MEM_LEVEL 8
#else
#  define DEF_MEM_LEVEL  MAX_MEM_LEVEL
#endif
#endif
#define SIZEDATA_INDATABLOCK (4096-(4*4))
#define LOCALHEADERMAGIC    (0x04034b50)
#define CENTRALHEADERMAGIC  (0x02014b50)
#define ENDHEADERMAGIC      (0x06054b50)
#define ZIP64ENDHEADERMAGIC      (0x6064b50)
#define ZIP64ENDLOCHEADERMAGIC   (0x7064b50)
#define FLAG_LOCALHEADER_OFFSET (0x06)
#define CRC_LOCALHEADER_OFFSET  (0x0e)
#define SIZECENTRALHEADER (0x2e) /* 46 */
typedef struct linkedlist_datablock_internal_s
{
  struct linkedlist_datablock_internal_s* next_datablock;
  uLong  avail_in_this_block;
  uLong  filled_in_this_block;
  uLong  unused; /* for future use and alignment */
  unsigned char data[SIZEDATA_INDATABLOCK];
} linkedlist_datablock_internal;
typedef struct linkedlist_data_s
{
    linkedlist_datablock_internal* first_block;
    linkedlist_datablock_internal* last_block;
} linkedlist_data;
typedef struct
{
    z_stream stream;            /* zLib stream structure for inflate */
#ifdef HAVE_BZIP2
    bz_stream bstream;          /* bzLib stream structure for bziped */
#endif

    int  stream_initialised;    /* 1 is stream is initialised */
    uInt pos_in_buffered_data;  /* last written byte in buffered_data */

    ZPOS64_T pos_local_header;     /* offset of the local header of the file
                                     currenty writing */
    char* central_header;       /* central header data for the current file */
    uLong size_centralExtra;
    uLong size_centralheader;   /* size of the central header for cur file */
    uLong size_centralExtraFree; /* Extra bytes allocated to the centralheader but that are not used */
    uLong flag;                 /* flag of the file currently writing */

    int  method;                /* compression method of file currenty wr.*/
    int  raw;                   /* 1 for directly writing raw data */
    Byte buffered_data[Z_BUFSIZE];/* buffer contain compressed data to be writ*/
    uLong dosDate;
    uLong crc32;
    int  encrypt;
    int  zip64;               /* Add ZIP64 extened information in the extra field */
    ZPOS64_T pos_zip64extrainfo;
    ZPOS64_T totalCompressedData;
    ZPOS64_T totalUncompressedData;
#ifndef NOCRYPT
    unsigned long keys[3];     /* keys defining the pseudo-random sequence */
    const z_crc_t* pcrc_32_tab;
    int crypt_header_size;
#endif
} curfile64_info;
typedef struct
{
    zlib_filefunc64_32_def z_filefunc;
    voidpf filestream;        /* io structore of the zipfile */
    linkedlist_data central_dir;/* datablock with central dir in construction*/
    int  in_opened_file_inzip;  /* 1 if a file in the zip is currently writ.*/
    curfile64_info ci;            /* info on the file curretly writing */

    ZPOS64_T begin_pos;            /* position of the beginning of the zipfile */
    ZPOS64_T add_position_when_writing_offset;
    ZPOS64_T number_entry;

#ifndef NO_ADDFILEINEXISTINGZIP
    char *globalcomment;
#endif

} zip64_internal;
#ifndef NOCRYPT
#define INCLUDECRYPTINGCODE_IFCRYPTALLOWED
#include "crypt.h"
#endif
local linkedlist_datablock_internal* allocate_new_datablock()
{
    linkedlist_datablock_internal* ldi;
    ldi = (linkedlist_datablock_internal*)
                 ALLOC(sizeof(linkedlist_datablock_internal));
    if (ldi!=NULL)
    {
        ldi->next_datablock = NULL ;
        ldi->filled_in_this_block = 0 ;
        ldi->avail_in_this_block = SIZEDATA_INDATABLOCK ;
    }
    return ldi;
}
local void free_datablock(linkedlist_datablock_internal* ldi)
{
    while (ldi!=NULL)
    {
        linkedlist_datablock_internal* ldinext = ldi->next_datablock;
        TRYFREE(ldi);
        ldi = ldinext;
    }
}
local void free_linkedlist(linkedlist_data* ll)
{
    free_datablock(ll->first_block);
    ll->first_block = ll->last_block = NULL;
}
#ifndef NO_ADDFILEINEXISTINGZIP
#ifndef BUFREADCOMMENT
#define BUFREADCOMMENT (0x400)
#endif
#endif /* !NO_ADDFILEINEXISTINGZIP*/
#    ifndef NO_ADDFILEINEXISTINGZIP
#    endif /* !NO_ADDFILEINEXISTINGZIP*/
#    ifndef NO_ADDFILEINEXISTINGZIP
#    endif /* !NO_ADDFILEINEXISTINGZIP*/
#    ifdef NOCRYPT
#    endif
#ifdef HAVE_BZIP2
#else
#endif
#ifdef HAVE_BZIP2
#endif
#ifdef HAVE_BZIP2
#else
#endif
#ifdef HAVE_BZIP2
#endif
#    ifndef NOCRYPT
#    endif
#ifndef NOCRYPT
#endif
#ifdef HAVE_BZIP2
#endif
#ifdef HAVE_BZIP2
#endif
#ifdef HAVE_BZIP2
#endif
#ifdef HAVE_BZIP2
#endif
#    ifndef NOCRYPT
#    endif
#ifndef NO_ADDFILEINEXISTINGZIP
#endif
#ifndef NO_ADDFILEINEXISTINGZIP
#endif
