#include "pngpriv.h"
#if defined(PNG_READ_SUPPORTED) || defined(PNG_WRITE_SUPPORTED)
#ifdef PNG_WARNINGS_SUPPORTED
#endif /* WARNINGS */
#ifdef PNG_ERROR_TEXT_SUPPORTED
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
#endif
#else
#endif /* ERROR_TEXT */
#if defined(PNG_WARNINGS_SUPPORTED) || defined(PNG_TIME_RFC1123_SUPPORTED)
#endif
#ifdef PNG_WARNINGS_SUPPORTED
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
#endif
#endif /* WARNINGS */
#ifdef PNG_BENIGN_ERRORS_SUPPORTED
#     ifdef PNG_READ_SUPPORTED
#     endif
#     ifdef PNG_READ_SUPPORTED
#     endif
#  ifndef PNG_ERROR_TEXT_SUPPORTED
#  endif
#  ifndef PNG_ERROR_TEXT_SUPPORTED
#  endif
#  ifndef PNG_ERROR_TEXT_SUPPORTED
#  endif
#endif /* BENIGN_ERRORS */
#define PNG_MAX_ERROR_TEXT 196 /* Currently limited by profile_error in png.c */
#if defined(PNG_WARNINGS_SUPPORTED) || \
#define isnonalpha(c) ((c) < 65 || (c) > 122 || ((c) > 90 && (c) < 97))
#endif /* WARNINGS || ERROR_TEXT */
#if defined(PNG_READ_SUPPORTED) && defined(PNG_ERROR_TEXT_SUPPORTED)
#endif /* READ && ERROR_TEXT */
#ifdef PNG_WARNINGS_SUPPORTED
#endif /* WARNINGS */
#ifdef PNG_READ_SUPPORTED
#ifdef PNG_BENIGN_ERRORS_SUPPORTED
#  ifndef PNG_ERROR_TEXT_SUPPORTED
#  endif
#endif
#endif /* READ */
#  ifndef PNG_WARNINGS_SUPPORTED
#  endif
#  if defined(PNG_READ_SUPPORTED) && defined(PNG_WRITE_SUPPORTED)
#  endif
#  ifdef PNG_READ_SUPPORTED
#  endif
#  if defined(PNG_READ_SUPPORTED) && defined(PNG_WRITE_SUPPORTED)
#  endif
#  ifdef PNG_WRITE_SUPPORTED
#  endif
#ifdef PNG_ERROR_TEXT_SUPPORTED
#ifdef PNG_FLOATING_POINT_SUPPORTED
#  define fixed_message "fixed point overflow in "
#  define fixed_message_ln ((sizeof fixed_message)-1)
#endif
#endif
#ifdef PNG_SETJMP_SUPPORTED
png_free_jmpbuf(png_structrp png_ptr)
{
   if (png_ptr != NULL)
   {
      jmp_buf *jb = png_ptr->jmp_buf_ptr;

      /* A size of 0 is used to indicate a local, stack, allocation of the
       * pointer; used here and in png.c
       */
      if (jb != NULL && png_ptr->jmp_buf_size > 0)
      {

         /* This stuff is so that a failure to free the error control structure
          * does not leave libpng in a state with no valid error handling: the
          * free always succeeds, if there is an error it gets ignored.
          */
         if (jb != &png_ptr->jmp_buf_local)
         {
            /* Make an internal, libpng, jmp_buf to return here */
            jmp_buf free_jmp_buf;

            if (!setjmp(free_jmp_buf))
            {
               png_ptr->jmp_buf_ptr = &free_jmp_buf; /* come back here */
               png_ptr->jmp_buf_size = 0; /* stack allocation */
               png_ptr->longjmp_fn = longjmp;
               png_free(png_ptr, jb); /* Return to setjmp on error */
            }
         }
      }

      /* *Always* cancel everything out: */
      png_ptr->jmp_buf_size = 0;
      png_ptr->jmp_buf_ptr = NULL;
      png_ptr->longjmp_fn = 0;
   }
}
#endif
#ifdef PNG_CONSOLE_IO_SUPPORTED
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
#endif
#else
#endif
#ifdef PNG_SETJMP_SUPPORTED
#else
#endif
#ifdef PNG_WARNINGS_SUPPORTED
#ifdef PNG_CONSOLE_IO_SUPPORTED
#  ifdef PNG_ERROR_NUMBERS_SUPPORTED
#  endif
#else
#endif
#endif /* WARNINGS */
#ifdef PNG_WARNINGS_SUPPORTED
#else
#endif
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
#endif
#if defined(PNG_SIMPLIFIED_READ_SUPPORTED) ||\
#ifdef PNG_WARNINGS_SUPPORTED
#endif
#endif /* SIMPLIFIED READ || SIMPLIFIED_WRITE */
#endif /* READ || WRITE */
