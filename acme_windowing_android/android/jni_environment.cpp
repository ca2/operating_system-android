#include "framework.h"
#include "_internal.h"


//extern operating_system_driver* g_pandroiddriver;


thread_local JNIEnv* t_pjnienv1;

//JNIEnv * task_jnienv()
//{
//
//   return t_pjnienv1;
//}

//void set_task_jnienv(JNIEnv * pjnienv1)
//{
//
//   t_pjnienv1 = pjnienv1;
//}

::particle_pointer g_pmutexOs;


::particle* osmutex()
{

   return g_pmutexOs;

}


//extern thread_local JNIEnv* t_pjnienv;


int get_mem_free_available_kb()
{

   return ::acme::driver::get()->m_lMemFreeAvailableKb;

}




string as_string(const jstring & jstring)
{

   const_char_pointer  nativeString = t_pjnienv1->GetStringUTFChars(jstring, 0);

   string str = nativeString;

   t_pjnienv1->ReleaseStringUTFChars(jstring, nativeString);

   return str;

}







void set_jni_context(JNIEnv* penv)
{

   t_pjnienv1 = penv;

}


JNIEnv* get_jni_env()
{

   return t_pjnienv1;

}


::string __string(const jstring& jstring)
{

   auto env = t_pjnienv1;

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



