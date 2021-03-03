#include "avcodec.h"
#include "lzw.h"
#include "mathops.h"
#include "put_bits.h"
#define LZW_MAXBITS 12
#define LZW_SIZTABLE (1<<LZW_MAXBITS)
#define LZW_HASH_SIZE 16411
#define LZW_HASH_SHIFT 6
#define LZW_PREFIX_EMPTY -1
#define LZW_PREFIX_FREE -2
typedef struct Code{
    /// Hash code of prefix, LZW_PREFIX_EMPTY if empty prefix, or LZW_PREFIX_FREE if no code
    int hash_prefix;
    int code;               ///< LZW code
    uint8_t suffix;         ///< Last character in code block
}Code;
typedef struct LZWEncodeState {
    int clear_code;          ///< Value of clear code
    int end_code;            ///< Value of end code
    Code tab[LZW_HASH_SIZE]; ///< Hash table
    int tabsize;             ///< Number of values in hash table
    int bits;                ///< Actual bits code
    int bufsize;             ///< Size of output buffer
    PutBitContext pb;        ///< Put bit context for output
    int maxbits;             ///< Max bits code
    int maxcode;             ///< Max value of code
    int output_bytes;        ///< Number of written bytes
    int last_code;           ///< Value of last output code or LZW_PREFIX_EMPTY
    enum FF_LZW_MODES mode;  ///< TIFF or GIF
    void (*put_bits)(PutBitContext *, int, unsigned); ///< GIF is LE while TIFF is BE
}LZWEncodeState;
