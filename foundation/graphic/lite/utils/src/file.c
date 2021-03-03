#include "file.h"
#if defined(_LITEOS) && defined(_WIN32)
#error platform define err, check _LITEOS and _WIN32
#endif // _LITEOS && _WIN32
#if defined(_LITEOS) && defined(__linux__)
#error platform define err, check _LITEOS and __linux__
#endif // _LITEOS && __linux__
#if defined(_LITEOS)
#include "mc_file.h"
#elif defined _WIN32
#include "win_file.h"
#elif defined __linux__ || defined __LITEOS__
#include "linux_file.h"
#endif
#ifdef _LITEOS
#elif defined _WIN32
#elif defined __linux__ || defined __LITEOS__
#else
#error must define one at least
#endif
