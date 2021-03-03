#include "compiler.h"
typedef struct bitmap_s {		/* bitmap description */
	uint16_t width;
	uint16_t height;
	uint8_t	palette[256*3];
	uint8_t	*data;
} bitmap_t;
#define DEFAULT_CMAP_SIZE	16	/* size of default color map	*/
