#include "libavutil/attributes.h"
#include "libavutil/crc.h"
#include "libavutil/fifo.h"
#include "bytestream.h"
#include "parser.h"
#include "flac.h"
#define FLAC_MAX_SEQUENTIAL_HEADERS 4
#define FLAC_MIN_HEADERS 10
#define FLAC_AVG_FRAME_SIZE 8192
#define FLAC_HEADER_BASE_SCORE        10
#define FLAC_HEADER_CHANGED_PENALTY   7
#define FLAC_HEADER_CRC_FAIL_PENALTY  50
#define FLAC_HEADER_NOT_PENALIZED_YET 100000
#define FLAC_HEADER_NOT_SCORED_YET    -100000
#define MAX_FRAME_HEADER_SIZE 16
typedef struct FLACHeaderMarker {
    int offset;       /**< byte offset from start of FLACParseContext->buffer */
    int *link_penalty;  /**< pointer to array of local scores between this header
                           and the one at a distance equal array position     */
    int max_score;    /**< maximum score found after checking each child that
                           has a valid CRC                                    */
    FLACFrameInfo fi; /**< decoded frame header info                          */
    struct FLACHeaderMarker *next;       /**< next CRC-8 verified header that
                                              immediately follows this one in
                                              the bytestream                  */
    struct FLACHeaderMarker *best_child; /**< following frame header with
                                              which this frame has the best
                                              score with                      */
} FLACHeaderMarker;
typedef struct FLACParseContext {
    AVCodecParserContext *pc;      /**< parent context                        */
    AVCodecContext *avctx;         /**< codec context pointer for logging     */
    FLACHeaderMarker *headers;     /**< linked-list that starts at the first
                                        CRC-8 verified header within buffer   */
    FLACHeaderMarker *best_header; /**< highest scoring header within buffer  */
    int nb_headers_found;          /**< number of headers found in the last
                                        flac_parse() call                     */
    int nb_headers_buffered;       /**< number of headers that are buffered   */
    int best_header_valid;         /**< flag set when the parser returns junk;
                                        if set return best_header next time   */
    AVFifoBuffer *fifo_buf;        /**< buffer to store all data until headers
                                        can be verified                       */
    int end_padded;                /**< specifies if fifo_buf's end is padded */
    uint8_t *wrap_buf;             /**< general fifo read buffer when wrapped */
    int wrap_buf_allocated_size;   /**< actual allocated size of the buffer   */
    FLACFrameInfo last_fi;         /**< last decoded frame header info        */
    int last_fi_valid;             /**< set if last_fi is valid               */
} FLACParseContext;
