#include "unity.h"
#include "unity_memory.h"
#include <string.h>
#define MALLOC_DONT_FAIL -1
#undef malloc
#undef free
#undef calloc
#undef realloc
#ifdef UNITY_EXCLUDE_STDLIB_MALLOC
#else
#include <stdlib.h>
#endif
typedef struct GuardBytes
{
    size_t size;
    size_t guard_space;
} Guard;
#define UNITY_MALLOC_ALIGNMENT (UNITY_POINTER_WIDTH / 8)
void* unity_malloc(size_t size)
{
    char* mem;
    Guard* guard;
    size_t total_size;

    total_size = sizeof(Guard) + unity_size_round_up(size + sizeof(end));

    if (malloc_fail_countdown != MALLOC_DONT_FAIL)
    {
        if (malloc_fail_countdown == 0)
            return NULL;
        malloc_fail_countdown--;
    }

    if (size == 0) return NULL;
#ifdef UNITY_EXCLUDE_STDLIB_MALLOC
    if (heap_index + total_size > UNITY_INTERNAL_HEAP_SIZE_BYTES)
    {
        guard = NULL;
    }
    else
    {
        /* We know we can get away with this cast because we aligned memory already */
        guard = (Guard*)(void*)(&unity_heap[heap_index]);
        heap_index += total_size;
    }
#else
    guard = (Guard*)UNITY_MALLOC(total_size);
#endif
    if (guard == NULL) return NULL;
    malloc_count++;
    guard->size = size;
    guard->guard_space = 0;
    mem = (char*)&(guard[1]);
    memcpy(&mem[size], end, sizeof(end));

    return (void*)mem;
}
#ifdef UNITY_EXCLUDE_STDLIB_MALLOC
#else
#endif
void unity_free(void* mem)
{
    int overrun;

    if (mem == NULL)
    {
        return;
    }

    overrun = isOverrun(mem);
    release_memory(mem);
    if (overrun)
    {
        UNITY_TEST_FAIL(Unity.CurrentTestLineNumber, "Buffer overrun detected during free()");
    }
}
void* unity_calloc(size_t num, size_t size)
{
    void* mem = unity_malloc(num * size);
    if (mem == NULL) return NULL;
    memset(mem, 0, num * size);
    return mem;
}
void* unity_realloc(void* oldMem, size_t size)
{
    Guard* guard = (Guard*)oldMem;
    void* newMem;

    if (oldMem == NULL) return unity_malloc(size);

    guard--;
    if (isOverrun(oldMem))
    {
        release_memory(oldMem);
        UNITY_TEST_FAIL(Unity.CurrentTestLineNumber, "Buffer overrun detected during realloc()");
    }

    if (size == 0)
    {
        release_memory(oldMem);
        return NULL;
    }

    if (guard->size >= size) return oldMem;

#ifdef UNITY_EXCLUDE_STDLIB_MALLOC /* Optimization if memory is expandable */
    {
        size_t old_total_size = unity_size_round_up(guard->size + sizeof(end));

        if ((oldMem == unity_heap + heap_index - old_total_size) &&
            ((heap_index - old_total_size + unity_size_round_up(size + sizeof(end))) <= UNITY_INTERNAL_HEAP_SIZE_BYTES))
        {
            release_memory(oldMem);    /* Not thread-safe, like unity_heap generally */
            return unity_malloc(size); /* No memcpy since data is in place */
        }
    }
#endif
    newMem = unity_malloc(size);
    if (newMem == NULL) return NULL; /* Do not release old memory */
    memcpy(newMem, oldMem, guard->size);
    release_memory(oldMem);
    return newMem;
}
