#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <u-boot/crc.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "compiler.h"
#include <u-boot/crc.h>
#include <version.h>
#define CRC_SIZE sizeof(uint32_t)
#define CHUNK_SIZE 4096
