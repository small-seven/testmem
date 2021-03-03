#include <common.h>
#include <console.h> /* ctrlc */
#include <asm/io.h>
#include "hydra.h"
#define REFL_PATTERN (0xdededede)
#define REFL_PATTERN_INV (~REFL_PATTERN)
