#include "pngpriv.h"
#if defined(PNG_READ_SUPPORTED) || defined(PNG_WRITE_SUPPORTED)
png_destroy_png_struct(png_structrp png_ptr)
{
   if (png_ptr != NULL)
   {
      /* png_free might call png_error and may certainly call
       * png_get_mem_ptr, so fake a temporary png_struct to support this.
       */
      png_struct dummy_struct = *png_ptr;
      memset(png_ptr, 0, (sizeof *png_ptr));
      png_free(&dummy_struct, png_ptr);

#     ifdef PNG_SETJMP_SUPPORTED
         /* We may have a jmp_buf left to deallocate. */
         png_free_jmpbuf(&dummy_struct);
#     endif
   }
}
#ifndef PNG_USER_MEM_SUPPORTED
#endif
#     ifdef PNG_MAX_MALLOC_64K
#     endif
#ifdef PNG_USER_MEM_SUPPORTED
#endif
#if defined(PNG_TEXT_SUPPORTED) || defined(PNG_sPLT_SUPPORTED) ||\
png_malloc_array_checked(png_const_structrp png_ptr, int nelements,
    size_t element_size)
{
   png_alloc_size_t req = (png_alloc_size_t)nelements; /* known to be > 0 */

   if (req <= PNG_SIZE_MAX/element_size)
      return png_malloc_base(png_ptr, req * element_size);

   /* The failure case when the request is too large */
   return NULL;
}
#endif /* TEXT || sPLT || STORE_UNKNOWN_CHUNKS */
#ifdef PNG_USER_MEM_SUPPORTED
#endif /* USER_MEM */
png_free(png_const_structrp png_ptr, png_voidp ptr)
{
   if (png_ptr == NULL || ptr == NULL)
      return;

#ifdef PNG_USER_MEM_SUPPORTED
   if (png_ptr->free_fn != NULL)
      png_ptr->free_fn(png_constcast(png_structrp,png_ptr), ptr);

   else
      png_free_default(png_ptr, ptr);
}
#endif /* USER_MEM */
#ifdef PNG_USER_MEM_SUPPORTED
png_set_mem_fn(png_structrp png_ptr, png_voidp mem_ptr, png_malloc_ptr
  malloc_fn, png_free_ptr free_fn)
{
   if (png_ptr != NULL)
   {
      png_ptr->mem_ptr = mem_ptr;
      png_ptr->malloc_fn = malloc_fn;
      png_ptr->free_fn = free_fn;
   }
}
png_get_mem_ptr(png_const_structrp png_ptr)
{
   if (png_ptr == NULL)
      return NULL;

   return png_ptr->mem_ptr;
}
#endif /* USER_MEM */
#endif /* READ || WRITE */
