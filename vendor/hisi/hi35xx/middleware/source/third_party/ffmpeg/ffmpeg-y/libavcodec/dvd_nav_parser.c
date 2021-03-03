#include "avcodec.h"
#include "get_bits.h"
#include "parser.h"
#define PCI_SIZE  980
#define DSI_SIZE 1018
typedef struct DVDNavParseContext {
    uint32_t     lba;
    uint8_t      buffer[PCI_SIZE+DSI_SIZE];
    int          copied;
} DVDNavParseContext;
