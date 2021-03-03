#include <ft2build.h>
#include FT_CONFIG_CONFIG_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_MEMORY_H
#include FT_SYSTEM_H
#include FT_ERRORS_H
#include FT_TYPES_H
#ifdef FT_DEBUG_MEMORY
#define  KEEPALIVE /* `Keep alive' means that freed blocks aren't released
#include FT_CONFIG_STANDARD_LIBRARY_H
  typedef struct FT_MemSourceRec_*  FT_MemSource;
  typedef struct FT_MemNodeRec_*    FT_MemNode;
  typedef struct FT_MemTableRec_*   FT_MemTable;


#define FT_MEM_VAL( addr )  ( (FT_PtrDist)(FT_Pointer)( addr ) )

  /*
   * This structure holds statistics for a single allocation/release
   * site.  This is useful to know where memory operations happen the
   * most.
   */
  typedef struct  FT_MemSourceRec_
  {
    const char*   file_name;
    long          line_no;

    FT_Long       cur_blocks;   /* current number of allocated blocks */
    FT_Long       max_blocks;   /* max. number of allocated blocks    */
    FT_Long       all_blocks;   /* total number of blocks allocated   */

    FT_Long       cur_size;     /* current cumulative allocated size */
    FT_Long       max_size;     /* maximum cumulative allocated size */
    FT_Long       all_size;     /* total cumulative allocated size   */

    FT_Long       cur_max;      /* current maximum allocated size */

    FT_UInt32     hash;
    FT_MemSource  link;

  } FT_MemSourceRec;
#define FT_MEM_SOURCE_BUCKETS  128
  typedef struct  FT_MemNodeRec_
  {
    FT_Byte*      address;
    FT_Long       size;     /* < 0 if the block was freed */

    FT_MemSource  source;

#ifdef KEEPALIVE
    const char*   free_file_name;
    FT_Long       free_line_no;
#endif

    FT_MemNode    link;

  } FT_MemNodeRec;
  typedef struct  FT_MemTableRec_
  {
    FT_Long          size;
    FT_Long          nodes;
    FT_MemNode*      buckets;

    FT_Long          alloc_total;
    FT_Long          alloc_current;
    FT_Long          alloc_max;
    FT_Long          alloc_count;

    FT_Bool          bound_total;
    FT_Long          alloc_total_max;

    FT_Bool          bound_count;
    FT_Long          alloc_count_max;

    FT_MemSource     sources[FT_MEM_SOURCE_BUCKETS];

    FT_Bool          keep_alive;

    FT_Memory        memory;
    FT_Pointer       memory_user;
    FT_Alloc_Func    alloc;
    FT_Free_Func     free;
    FT_Realloc_Func  realloc;

  } FT_MemTableRec;
#define FT_MEM_SIZE_MIN  7
#define FT_MEM_SIZE_MAX  13845163
#define FT_FILENAME( x )  ( (x) ? (x) : "unknown file" )
#if 0
#endif
#else  /* !FT_DEBUG_MEMORY */
