#include "zutil.h"
#include "infblock.h"
#define  DONE  INFLATE_DONE
#define  BAD   INFLATE_BAD
typedef enum {
      METHOD,   /* waiting for method byte */
      FLAG,     /* waiting for flag byte */
      DICT4,    /* four dictionary check bytes to go */
      DICT3,    /* three dictionary check bytes to go */
      DICT2,    /* two dictionary check bytes to go */
      DICT1,    /* one dictionary check byte to go */
      DICT0,    /* waiting for inflateSetDictionary */
      BLOCKS,   /* decompressing blocks */
      CHECK4,   /* four check bytes to go */
      CHECK3,   /* three check bytes to go */
      CHECK2,   /* two check bytes to go */
      CHECK1,   /* one check byte to go */
      DONE,     /* finished check, done */
      BAD}      /* got an error--stay here */
#undef  NEEDBYTE
#define NEEDBYTE {if(z->avail_in==0)return r;r=f;}
#undef  NEXTBYTE
#define NEXTBYTE (z->avail_in--,z->total_in++,*z->next_in++)
#ifdef NEED_DUMMY_RETURN
#endif
