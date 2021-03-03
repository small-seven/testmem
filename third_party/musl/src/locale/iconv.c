#include <iconv.h>
#include <errno.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include "locale_impl.h"
#define UTF_32BE    0300
#define UTF_16LE    0301
#define UTF_16BE    0302
#define UTF_32LE    0303
#define UCS2BE      0304
#define UCS2LE      0305
#define WCHAR_T     0306
#define US_ASCII    0307
#define UTF_8       0310
#define UTF_16      0312
#define UTF_32      0313
#define UCS2        0314
#define EUC_JP      0320
#define SHIFT_JIS   0321
#define ISO2022_JP  0322
#define GB18030     0330
#define GBK         0331
#define GB2312      0332
#define BIG5        0340
#define EUC_KR      0350
#include "codepages.h"
#include "legacychars.h"
#include "jis0208.h"
#include "gb18030.h"
#include "big5.h"
#include "hkscs.h"
#include "ksc.h"
#include "revjis.h"
#define mbrtowc_utf8 mbrtowc
#define wctomb_utf8 wctomb
