#if defined __linux__ || defined __LITEOS__
#include "linux_file.h"
#include "securec.h"
int32_t LinuxRemoveDir(const char* path)
{
    return rmdir(path);
}
#endif
