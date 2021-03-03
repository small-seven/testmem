#include "curl_setup.h"
#include <curl/curl.h>
#if defined(USE_THREADS_POSIX)
#  ifdef HAVE_PTHREAD_H
#    include <pthread.h>
#  endif
#elif defined(USE_THREADS_WIN32)
#  ifdef HAVE_PROCESS_H
#    include <process.h>
#  endif
#endif
#include "curl_threads.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(USE_THREADS_POSIX)
void Curl_thread_destroy(curl_thread_t hnd)
{
  if(hnd != curl_thread_t_null) {
    pthread_detach(*hnd);
    free(hnd);
  }
}
#elif defined(USE_THREADS_WIN32)
#ifdef _WIN32_WCE
  typedef HANDLE curl_win_thread_handle_t;
#elif defined(__MINGW32__) && !defined(__MINGW64_VERSION_MAJOR)
  typedef unsigned long curl_win_thread_handle_t;
#else
  typedef uintptr_t curl_win_thread_handle_t;
#endif
  curl_thread_t t;
  curl_win_thread_handle_t thread_handle;
#ifdef _WIN32_WCE
  thread_handle = CreateThread(NULL, 0, func, arg, 0, NULL);
#else
  thread_handle = _beginthreadex(NULL, 0, func, arg, 0, NULL);
#endif
  t = (curl_thread_t)thread_handle;
  if((t == 0) || (t == LongToHandle(-1L))) {
#ifdef _WIN32_WCE
    DWORD gle = GetLastError();
    errno = ((gle == ERROR_ACCESS_DENIED ||
              gle == ERROR_NOT_ENOUGH_MEMORY) ?
             EACCES : EINVAL);
#endif
    return curl_thread_t_null;
  }
void Curl_thread_destroy(curl_thread_t hnd)
{
  CloseHandle(hnd);
}
#if !defined(_WIN32_WINNT) || !defined(_WIN32_WINNT_VISTA) || \
#else
#endif
#endif /* USE_THREADS_* */
