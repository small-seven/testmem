#include "includes.h"
#include "common.h"
#include "crypto.h"
#define S_SWAP(a,b) do { u8 t = S[a]; S[a] = S[b]; S[b] = t; } while(0)
