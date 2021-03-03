#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
typedef struct Page {
    int base_record;
    unsigned int nb_records;
    int size;
} Page;
typedef struct AnmDemuxContext {
    unsigned int nb_pages;    /**< total pages in file */
    unsigned int nb_records;  /**< total records in file */
    int page_table_offset;
#define MAX_PAGES  256        /**< Deluxe Paint hardcoded value */
    Page pt[MAX_PAGES];       /**< page table */
    int page;                 /**< current page (or AVERROR_xxx code) */
    int record;               /**< current record (with in page) */
} AnmDemuxContext;
#define LPF_TAG  MKTAG('L','P','F',' ')
#define ANIM_TAG MKTAG('A','N','I','M')
