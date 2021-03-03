#include <inttypes.h>
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "libavcodec/bytestream.h"
#include "avformat.h"
#include "id3v2.h"
#include "internal.h"
#define ID_8SVX       MKTAG('8','S','V','X')
#define ID_16SV       MKTAG('1','6','S','V')
#define ID_MAUD       MKTAG('M','A','U','D')
#define ID_MHDR       MKTAG('M','H','D','R')
#define ID_MDAT       MKTAG('M','D','A','T')
#define ID_VHDR       MKTAG('V','H','D','R')
#define ID_ATAK       MKTAG('A','T','A','K')
#define ID_RLSE       MKTAG('R','L','S','E')
#define ID_CHAN       MKTAG('C','H','A','N')
#define ID_PBM        MKTAG('P','B','M',' ')
#define ID_ILBM       MKTAG('I','L','B','M')
#define ID_BMHD       MKTAG('B','M','H','D')
#define ID_DGBL       MKTAG('D','G','B','L')
#define ID_CAMG       MKTAG('C','A','M','G')
#define ID_CMAP       MKTAG('C','M','A','P')
#define ID_ACBM       MKTAG('A','C','B','M')
#define ID_DEEP       MKTAG('D','E','E','P')
#define ID_RGB8       MKTAG('R','G','B','8')
#define ID_RGBN       MKTAG('R','G','B','N')
#define ID_DSD        MKTAG('D','S','D',' ')
#define ID_DST        MKTAG('D','S','T',' ')
#define ID_DSTC       MKTAG('D','S','T','C')
#define ID_DSTF       MKTAG('D','S','T','F')
#define ID_FRTE       MKTAG('F','R','T','E')
#define ID_ANIM       MKTAG('A','N','I','M')
#define ID_ANHD       MKTAG('A','N','H','D')
#define ID_DLTA       MKTAG('D','L','T','A')
#define ID_DPAN       MKTAG('D','P','A','N')
#define ID_FORM       MKTAG('F','O','R','M')
#define ID_FRM8       MKTAG('F','R','M','8')
#define ID_ANNO       MKTAG('A','N','N','O')
#define ID_AUTH       MKTAG('A','U','T','H')
#define ID_CHRS       MKTAG('C','H','R','S')
#define ID_COPYRIGHT  MKTAG('(','c',')',' ')
#define ID_CSET       MKTAG('C','S','E','T')
#define ID_FVER       MKTAG('F','V','E','R')
#define ID_NAME       MKTAG('N','A','M','E')
#define ID_TEXT       MKTAG('T','E','X','T')
#define ID_ABIT       MKTAG('A','B','I','T')
#define ID_BODY       MKTAG('B','O','D','Y')
#define ID_DBOD       MKTAG('D','B','O','D')
#define ID_DPEL       MKTAG('D','P','E','L')
#define ID_DLOC       MKTAG('D','L','O','C')
#define ID_TVDC       MKTAG('T','V','D','C')
#define LEFT    2
#define RIGHT   4
#define STEREO  6
#define IFF_EXTRA_VIDEO_SIZE 41
typedef enum {
    COMP_NONE,
    COMP_FIB,
    COMP_EXP
} svx8_compression_type;
typedef struct IffDemuxContext {
    int      is_64bit;  ///< chunk size is 64-bit
    int64_t  body_pos;
    int64_t  body_end;
    uint32_t  body_size;
    svx8_compression_type   svx8_compression;
    unsigned  maud_bits;
    unsigned  maud_compression;
    unsigned  bitmap_compression;  ///< delta compression method used
    unsigned  bpp;          ///< bits per plane to decode (differs from bits_per_coded_sample if HAM)
    unsigned  ham;          ///< 0 if non-HAM or number of hold bits (6 for bpp > 6, 4 otherwise)
    unsigned  flags;        ///< 1 for EHB, 0 is no extra half darkening
    unsigned  transparency; ///< transparency color index in palette
    unsigned  masking;      ///< masking method used
    uint8_t   tvdc[32];     ///< TVDC lookup table
    int64_t   pts;
} IffDemuxContext;
#define DSD_SLFT MKTAG('S','L','F','T')
#define DSD_SRGT MKTAG('S','R','G','T')
#define DSD_MLFT MKTAG('M','L','F','T')
#define DSD_MRGT MKTAG('M','R','G','T')
#define DSD_C    MKTAG('C',' ',' ',' ')
#define DSD_LS   MKTAG('L','S',' ',' ')
#define DSD_RS   MKTAG('R','S',' ',' ')
#define DSD_LFE  MKTAG('L','F','E',' ')
typedef struct {
    uint64_t layout;
    const uint32_t * dsd_layout;
} DSDLayoutDesc;
