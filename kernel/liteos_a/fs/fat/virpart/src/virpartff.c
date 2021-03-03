#include "ffconf.h"
#include "virpartff.h"
#include "string.h"
#include "diskio.h"
#ifdef LOSCFG_FS_FAT_VIRTUAL_PARTITION
#if FF_USE_LFN == 0 /* Non-LFN configuration */
#define DEF_NAMBUF
#define INIT_NAMBUF(fs)
#define FREE_NAMBUF()
#else /* LFN configuration */
#if (FF_MAX_LFN < 12) || (FF_MAX_LFN > 255)
#error Wrong _MAX_LFN value
#endif
#if FF_USE_LFN == 1 /* LFN enabled with static working buffer */
#define DEF_NAMBUF
#define INIT_NAMBUF(fs)
#define FREE_NAMBUF()
#elif FF_USE_LFN == 2 /* LFN enabled with dynamic working buffer on the stack */
#define DEF_NAMBUF      WCHAR lbuf[FF_MAX_LFN + 1];
#define INIT_NAMBUF(fs) { (fs)->lfnbuf = lbuf; }
#define FREE_NAMBUF()
#elif FF_USE_LFN == 3 /* LFN enabled with dynamic working buffer on the heap */
#define DEF_NAMBUF      WCHAR *lfn;
#define INIT_NAMBUF(fs) { lfn = ff_memalloc((FF_MAX_LFN + 1) * 2); if (!lfn) LEAVE_FF(fs, FR_NOT_ENOUGH_CORE); (fs)->lfnbuf = lfn; }
#define FREE_NAMBUF()   ff_memfree(lfn)
#else
#error Wrong FF_USE_LFN setting
#endif
#endif /* else FF_USE_LFN == 0 */
#if FF_FS_REENTRANT
#if FF_USE_LFN == 1
#error Static LFN work area cannot be used at thread-safe configuration
#endif
#define ENTER_FF(fs)        do { if (!lock_fs(fs)) return FR_TIMEOUT; } while (0)
#define LEAVE_FF(fs, res)   do { unlock_fs(fs, res); return res; } while (0)
#else
#define ENTER_FF(fs)
#define LEAVE_FF(fs, res) return (res)
#endif
#if FF_MAX_SS != FF_MIN_SS
#endif
#if FF_FS_RPATH != 0
#endif
FRESULT f_getvirfree(const TCHAR *path, DWORD *nclst, DWORD *cclst)
{
FATFS *fs = NULL;
FRESULT res;
DWORD clst, link;
DWORD nfree;
UINT i;
DIR dj;

/* Find volume to Update the global FSINFO */
res = find_volume(&path, &fs, 0);
if (res != FR_OK) {
LEAVE_FF(fs, res);
}
#endif
