#include "framework.h"


// https://stackoverflow.com/questions/8115192/android-ndk-getting-the-backtrace
// https://stackoverflow.com/users/1046167/louis-semprini


#include <unwind.h>
#include <dlfcn.h>
#include <cxxabi.h>

struct android_backtrace_state
{
   void ** current;
   void ** end;
};

_Unwind_Reason_Code android_unwind_callback(struct _Unwind_Context * context,
   void * arg)
{
   android_backtrace_state * state = (android_backtrace_state *)arg;
   uintptr_t pc = _Unwind_GetIP(context);
   if (pc)
   {
      if (state->current == state->end)
      {
         return _URC_END_OF_STACK;
      }
      else
      {
         *state->current++ = reinterpret_cast<void *>(pc);
      }
   }
   return _URC_NO_REASON;
}

string android_backtrace()
{
   //_my_log("android stack dump");

   string str;

   const int max = 100;
   void * buffer[max];

   android_backtrace_state state;
   state.current = buffer;
   state.end = buffer + max;

   _Unwind_Backtrace(android_unwind_callback, &state);

   int count = (int)(state.current - buffer);

   for (int idx = 0; idx < count; idx++)
   {
      const void * addr = buffer[idx];
      const_char_pointer symbol = "";

      Dl_info info;
      if (dladdr(addr, &info) && info.dli_sname)
      {
         symbol = info.dli_sname;
      }
      int status = 0;
      char * demangled = __cxxabiv1::__cxa_demangle(symbol, 0, 0, &status);

      str.append_formatf("%03d: 0x%p %s",
         idx,
         addr,
         (NULL != demangled && 0 == status) ?
         demangled : symbol);

      if (NULL != demangled)
         free(demangled);
   }

   //_my_log("android stack dump done");

   return str;

}