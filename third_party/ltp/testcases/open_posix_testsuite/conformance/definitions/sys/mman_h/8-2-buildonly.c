#include <sys/mman.h>
#include <unistd.h>
#if defined(_POSIX_TYPED_MEMORY_OBJECTS) && _POSIX_TYPED_MEMORY_OBJECTS != -1
#ifndef POSIX_TYPED_MEM_ALLOCATE_CONTIG
#error POSIX_TYPED_MEM_ALLOCATE_CONTIG not defined
#endif
#endif
