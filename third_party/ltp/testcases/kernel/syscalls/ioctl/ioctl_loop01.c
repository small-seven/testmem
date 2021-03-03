#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "lapi/loop.h"
#include "tst_test.h"
#define SET_FLAGS (LO_FLAGS_AUTOCLEAR | LO_FLAGS_PARTSCAN | LO_FLAGS_READ_ONLY | LO_FLAGS_DIRECT_IO)
#define GET_FLAGS (LO_FLAGS_AUTOCLEAR | LO_FLAGS_PARTSCAN)
