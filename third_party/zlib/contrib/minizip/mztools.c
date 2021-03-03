#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zlib.h"
#include "unzip.h"
#define READ_8(adr)  ((unsigned char)*(adr))
#define READ_16(adr) ( READ_8(adr) | (READ_8(adr+1) << 8) )
#define READ_32(adr) ( READ_16(adr) | (READ_16((adr)+2) << 16) )
#define WRITE_8(buff, n) do { \
#define WRITE_16(buff, n) do { \
#define WRITE_32(buff, n) do { \
