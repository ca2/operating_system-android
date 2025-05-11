#include "framework.h"
#include "_internal.h"


extern operating_system_driver* g_pandroiddriver;


thread_local JNIEnv* t_pjnienv;


::particle_pointer g_pmutexOs;


::particle* osmutex()
{

   return g_pmutexOs;

}


extern thread_local JNIEnv* t_pjnienv;


int get_mem_free_available_kb()
{

   return g_pandroiddriver->m_lMemFreeAvailableKb;

}




string as_string(const jstring & jstring)
{

   const char* nativeString = t_pjnienv->GetStringUTFChars(jstring, 0);

   string str = nativeString;

   t_pjnienv->ReleaseStringUTFChars(jstring, nativeString);

   return str;

}







void set_jni_context(JNIEnv* penv)
{

   t_pjnienv = penv;

}


JNIEnv* get_jni_env()
{

   return t_pjnienv;

}


::string __string(const jstring& jstring)
{

   auto env = get_jni_env();

   const ::wd16_character* utf16 = (::wd16_character*)env->GetStringChars(jstring, NULL);

   if (utf16 == NULL)
   {

      return "";

   }

   size_t length = (size_t)env->GetStringLength(jstring);

   wd16_string wstr(utf16, length);

   string str(wstr);

   env->ReleaseStringChars(jstring, (jchar*)utf16);

   return str;

}



