#include "hal_tick.h"
#include <cstdint>
#ifdef _WIN32
#include <windows.h>
#elif defined __linux__ || defined __LITEOS__
#include <ctime>
#else
#include "los_swtmr.h"
#endif
#ifdef _WIN32
#elif defined __linux__ || defined __LITEOS__
#else
#endif
