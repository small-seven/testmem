#define JPEG_INTERNALS
#define AM_MEMORY_MANAGER	/* we define jvirt_Xarray_control structs */
#include "jinclude.h"
#include "jpeglib.h"
#include "jmemsys.h"		/* import the system-dependent declarations */
#ifndef NO_GETENV
#ifndef HAVE_STDLIB_H		/* <stdlib.h> should declare getenv() */
#endif
#endif
#ifndef ALIGN_TYPE		/* so can override from jconfig.h */
#define ALIGN_TYPE  double
#endif
typedef union small_pool_struct * small_pool_ptr;

typedef union small_pool_struct {
  struct {
    small_pool_ptr next;	/* next in list of pools */
    size_t bytes_used;		/* how many bytes already used within pool */
    size_t bytes_left;		/* bytes still available in this pool */
  } hdr;
typedef union large_pool_struct FAR * large_pool_ptr;

typedef union large_pool_struct {
  struct {
    large_pool_ptr next;	/* next in list of pools */
    size_t bytes_used;		/* how many bytes already used within pool */
    size_t bytes_left;		/* bytes still available in this pool */
  } hdr;
typedef struct {
  struct jpeg_memory_mgr pub;	/* public fields */

  /* Each pool identifier (lifetime class) names a linked list of pools. */
  small_pool_ptr small_list[JPOOL_NUMPOOLS];
  large_pool_ptr large_list[JPOOL_NUMPOOLS];

  /* Since we only have one lifetime class of virtual arrays, only one
   * linked list is necessary (for each datatype).  Note that the virtual
   * array control blocks being linked together are actually stored somewhere
   * in the small-pool list.
   */
  jvirt_sarray_ptr virt_sarray_list;
  jvirt_barray_ptr virt_barray_list;

  /* This counts total space obtained from jpeg_get_small/large */
  size_t total_space_allocated;

  /* alloc_sarray and alloc_barray set this value for use by virtual
   * array routines.
   */
  JDIMENSION last_rowsperchunk;	/* from most recent alloc_sarray/barray */
} my_memory_mgr;
typedef my_memory_mgr * my_mem_ptr;


/*
 * The control blocks for virtual arrays.
 * Note that these blocks are allocated in the "small" pool area.
 * System-dependent info for the associated backing store (if any) is hidden
 * inside the backing_store_info struct.
 */

struct jvirt_sarray_control {
  JSAMPARRAY mem_buffer;	/* => the in-memory buffer */
  JDIMENSION rows_in_array;	/* total virtual array height */
  JDIMENSION samplesperrow;	/* width of array (and of memory buffer) */
  JDIMENSION maxaccess;		/* max rows accessed by access_virt_sarray */
  JDIMENSION rows_in_mem;	/* height of memory buffer */
  JDIMENSION rowsperchunk;	/* allocation chunk size in mem_buffer */
  JDIMENSION cur_start_row;	/* first logical row # in the buffer */
  JDIMENSION first_undef_row;	/* row # of first uninitialized row */
  boolean pre_zero;		/* pre-zero mode requested? */
  boolean dirty;		/* do current buffer contents need written? */
  boolean b_s_open;		/* is backing-store data valid? */
  jvirt_sarray_ptr next;	/* link to next virtual sarray control block */
  backing_store_info b_s_info;	/* System-dependent control info */
};
#ifdef MEM_STATS		/* optional extra stuff for statistics */
#endif /* MEM_STATS */
#ifdef MEM_STATS
#endif
#define MIN_SLOP  50		/* greater than 0 to avoid futile looping */
#ifdef MEM_STATS
#endif
#ifndef NO_GETENV
#endif
