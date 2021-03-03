#include <sys/mman.h>
#include <unistd.h>
#if defined(_POSIX_TYPED_MEMORY_OBJECTS) && _POSIX_TYPED_MEMORY_OBJECTS != -1
#ifndef POSIX_TYPED_MEM_MAP_ALLOCATABLE
#error POSIX_TYPED_MEM_MAP_ALLOCATABLE not defined
#endif
#endif
