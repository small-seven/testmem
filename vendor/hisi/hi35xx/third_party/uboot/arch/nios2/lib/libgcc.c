typedef unsigned int UWtype;
typedef unsigned int UHWtype;
typedef unsigned long long UDWtype;
#define W_TYPE_SIZE 32

typedef unsigned char UQItype;
typedef long SItype;
typedef unsigned long USItype;
typedef long long DItype;
typedef unsigned long long DSItype;

#include "longlong.h"


typedef int word_type;
typedef long Wtype;
typedef long long DWtype;

struct DWstruct { Wtype low, high;};
typedef union
{
  struct DWstruct s;
  DWtype ll;
} DWunion;
#define BITS_PER_UNIT 8
#if !UDIV_NEEDS_NORMALIZATION
#else /* UDIV_NEEDS_NORMALIZATION */
#endif /* UDIV_NEEDS_NORMALIZATION */
