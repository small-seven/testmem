#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>
#ifdef __MINGW32__
#undef fseeko
#define fseeko(x, y, z) fseeko64(x, y, z)
#undef ftello
#define ftello(x)       ftello64(x)
#elif defined(_WIN32)
#undef fseeko
#define fseeko(x, y, z) _fseeki64(x, y, z)
#undef ftello
#define ftello(x)       _ftelli64(x)
#endif
#define MIN(a,b) ((a) > (b) ? (b) : (a))
#define BE_32(x) (((uint32_t)(((uint8_t*)(x))[0]) << 24) |  \
#define BE_64(x) (((uint64_t)(((uint8_t*)(x))[0]) << 56) |  \
#define AV_WB32(p, val)    {                    \
#define AV_WB64(p, val)    {                    \
#define BE_FOURCC(ch0, ch1, ch2, ch3)           \
#define QT_ATOM BE_FOURCC
#define FREE_ATOM QT_ATOM('f', 'r', 'e', 'e')
#define JUNK_ATOM QT_ATOM('j', 'u', 'n', 'k')
#define MDAT_ATOM QT_ATOM('m', 'd', 'a', 't')
#define MOOV_ATOM QT_ATOM('m', 'o', 'o', 'v')
#define PNOT_ATOM QT_ATOM('p', 'n', 'o', 't')
#define SKIP_ATOM QT_ATOM('s', 'k', 'i', 'p')
#define WIDE_ATOM QT_ATOM('w', 'i', 'd', 'e')
#define PICT_ATOM QT_ATOM('P', 'I', 'C', 'T')
#define FTYP_ATOM QT_ATOM('f', 't', 'y', 'p')
#define UUID_ATOM QT_ATOM('u', 'u', 'i', 'd')
#define CMOV_ATOM QT_ATOM('c', 'm', 'o', 'v')
#define TRAK_ATOM QT_ATOM('t', 'r', 'a', 'k')
#define MDIA_ATOM QT_ATOM('m', 'd', 'i', 'a')
#define MINF_ATOM QT_ATOM('m', 'i', 'n', 'f')
#define STBL_ATOM QT_ATOM('s', 't', 'b', 'l')
#define STCO_ATOM QT_ATOM('s', 't', 'c', 'o')
#define CO64_ATOM QT_ATOM('c', 'o', '6', '4')
#define ATOM_PREAMBLE_SIZE    8
#define COPY_BUFFER_SIZE   33554432
#define MAX_FTYP_ATOM_SIZE 1048576
typedef struct {
    uint32_t type;
    uint32_t header_size;
    uint64_t size;
    unsigned char *data;
} atom_t;
typedef struct {
    uint64_t moov_atom_size;
    uint64_t stco_offset_count;
    uint64_t stco_data_size;
    int stco_overflow;
    uint32_t depth;
} update_chunk_offsets_context_t;
typedef struct {
    unsigned char *dest;
    uint64_t original_moov_size;
    uint64_t new_moov_size;
} upgrade_stco_context_t;
typedef int (*parse_atoms_callback_t)(void *context, atom_t *atom);

static int parse_atoms(
    unsigned char *buf,
    uint64_t size,
    parse_atoms_callback_t callback,
    void *context)
{
    unsigned char *pos = buf;
    unsigned char *end = pos + size;
    atom_t atom;
    int ret;

    while (end - pos >= ATOM_PREAMBLE_SIZE) {
        atom.size = BE_32(pos);
        atom.type = BE_32(pos + 4);
        pos += ATOM_PREAMBLE_SIZE;
        atom.header_size = ATOM_PREAMBLE_SIZE;

        switch (atom.size) {
        case 1:
            if (end - pos < 8) {
                fprintf(stderr, "not enough room for 64 bit atom size\n");
                return -1;
            }
