#include "e_os.h"
#include "dso_local.h"
#if defined(DSO_WIN32)
# ifdef _WIN32_WCE
#  if _WIN32_WCE < 300
#  endif
#  undef GetProcAddress
#  define GetProcAddress GetProcAddressA
#  ifdef _MSC_VER
#  else
#  endif
#  if defined(_WIN32_WCE) && _WIN32_WCE>=101
#  endif
# endif
# define DSO_MAX_TRANSLATED_SIZE 256
# include <tlhelp32.h>
# ifdef _WIN32_WCE
#  define DLLNAME "TOOLHELP.DLL"
# else
#  ifdef MODULEENTRY32
#   undef MODULEENTRY32         /* unmask the ASCII version! */
#  endif
#  define DLLNAME "KERNEL32.DLL"
# endif
typedef HANDLE(WINAPI *CREATETOOLHELP32SNAPSHOT) (DWORD, DWORD);
typedef BOOL(WINAPI *CLOSETOOLHELP32SNAPSHOT) (HANDLE);
typedef BOOL(WINAPI *MODULE32) (HANDLE, MODULEENTRY32 *);

static int win32_pathbyaddr(void *addr, char *path, int sz)
{
    HMODULE dll;
    HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
    MODULEENTRY32 me32;
    CREATETOOLHELP32SNAPSHOT create_snap;
    CLOSETOOLHELP32SNAPSHOT close_snap;
    MODULE32 module_first, module_next;

    if (addr == NULL) {
        union {
            int (*f) (void *, char *, int);
            void *p;
        } t = {
# ifdef _WIN32_WCE
# else
# endif
# ifdef _WIN32_WCE
#  if _WIN32_WCE >= 101
#  else
#  endif
# else
# endif
# ifdef _WIN32_WCE
# else
# endif
#endif                          /* DSO_WIN32 */
