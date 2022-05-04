#include "framework.h"
#include "_operating_system.h"


extern operating_system_driver* g_pandroiddriver;


thread_local JNIEnv* t_pjnienv;


::mutex* g_pmutexOs;


::mutex* osmutex()
{

   return g_pmutexOs;

}


extern thread_local JNIEnv* t_pjnienv;


int get_mem_free_available_kb()
{

   return g_pandroiddriver->m_lMemFreeAvailableKb;

}




string get_string(jstring jstring)
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
