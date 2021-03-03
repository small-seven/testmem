#include <string.h>
#include <stdint.h>
#include "libavutil/attributes.h"
#include "mqc.h"
typedef struct MqcCxState {
    uint16_t qe;
    uint8_t  nmps;
    uint8_t  nlps;
    uint8_t  sw;
} MqcCxState;
