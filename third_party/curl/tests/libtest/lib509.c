#include "test.h"
#include <string.h>
#include "memdebug.h"
void *custom_calloc(size_t nmemb, size_t size)
{
  if(!seen_calloc) {
    printf("seen custom_calloc()\n");
    seen_calloc = 1;
  }
  return (calloc)(nmemb, size);
}
void *custom_malloc(size_t size)
{
  if(!seen_malloc && seen_calloc) {
    printf("seen custom_malloc()\n");
    seen_malloc = 1;
  }
  return (malloc)(size);
}
void *custom_realloc(void *ptr, size_t size)
{
  if(!seen_realloc && seen_malloc) {
    printf("seen custom_realloc()\n");
    seen_realloc = 1;
  }
  return (realloc)(ptr, size);
}
void custom_free(void *ptr)
{
  if(!seen_free && seen_realloc) {
    printf("seen custom_free()\n");
    seen_free = 1;
  }
  (free)(ptr);
}
