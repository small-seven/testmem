#include "compr.h"
#include "jffs2.h"
#include "user_copy.h"
void jffs2_free_comprbuf(unsigned char *comprbuf, unsigned char *orig)
{
	if (orig != comprbuf)
		kfree(comprbuf);
}
#ifdef CONFIG_JFFS2_ZLIB
#endif
#ifdef CONFIG_JFFS2_RTIME
#endif
#ifdef CONFIG_JFFS2_RUBIN
#endif
#ifdef CONFIG_JFFS2_LZO
#endif
#ifdef CONFIG_JFFS2_CMODE_NONE
#else
#ifdef CONFIG_JFFS2_CMODE_SIZE
#else
#ifdef CONFIG_JFFS2_CMODE_FAVOURLZO
#else
#endif
#endif
#endif
#ifdef CONFIG_JFFS2_LZO
#endif
#ifdef CONFIG_JFFS2_RUBIN
#endif
#ifdef CONFIG_JFFS2_RTIME
#endif
#ifdef CONFIG_JFFS2_ZLIB
#endif
