#pragma once



#include "platform/_.h"





#ifdef __cplusplus
extern "C"
{
#endif

   char* getcwd(char* buf, size_t size);



      void swab(const void* from, void* to, ssize_t n);
      // used deep inside FreeImage
      void* lfind(const void* key, const void* aura, size_t* num, size_t width, int(*fncomparison)(const void*, const void*));

      void* lsearch(const void* key, const void* aura, size_t* num, size_t width, int(*fncomparison)(const void*, const void*));

      double rint(double x);
      // The lockf() function is not available on Android; we translate to flock().
      int lockf(int fd, int cmd, off_t ignored_len);
      //i64 get_nanos();

#ifdef __cplusplus
}
#endif



