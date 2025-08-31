#include "framework.h"
#include "_internal.h"


thread_local JNIEnv* t_pjnipcontextContext;


::particle_pointer g_pmutexOs;


::particle* osmutex()
{

   return g_pmutexOs;

}


int get_mem_free_available_kb()
{

   return ::platform::application_state::get()->m_lMemFreeAvailableKb;

}


string as_string(const jstring & jstring)
{

   const_char_pointer nativeString = t_pjnipcontextContext->GetStringUTFChars(jstring, 0);

   string str = nativeString;

   t_pjnipcontextContext->ReleaseStringUTFChars(jstring, nativeString);

   return str;

}


void set_jni_context(JNIEnv* ppcontext)
{

   t_pjnipcontextContext = ppcontext;

}


JNIEnv* get_jni_context()
{

   return t_pjnipcontextContext;

}


::string __string(const jstring& jstring)
{

   auto pcontext = t_pjnipcontextContext;

   const ::wd16_character* utf16 = (::wd16_character*)pcontext->GetStringChars(jstring, NULL);

   if (utf16 == NULL)
   {

      return "";

   }

   size_t length = (size_t)pcontext->GetStringLength(jstring);

   wd16_string wstr(utf16, length);

   string str(wstr);

   pcontext->ReleaseStringChars(jstring, (jchar*)utf16);

   return str;

}



