#include "framework.h"
#include "_internal.h"
#include "jni_object_impl.h"


thread_local ::pointer < jni_context_impl > t_pjnipcontextContext;


jni_context * jni_context::get()
{

   return t_pjnipcontextContext;

}

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

   const_char_pointer nativeString = t_pjnipcontextContext->m_pjnicontext->GetStringUTFChars(jstring, 0);

   string str = nativeString;

   t_pjnipcontextContext->m_pjnicontext->ReleaseStringUTFChars(jstring, nativeString);

   return str;

}


void set_jni_context(JNIEnv* pcontext)
{

   if(!t_pjnipcontextContext)
   {

      t_pjnipcontextContext = øallocate jni_context_impl;

   }

   t_pjnipcontextContext->m_pjnicontext = pcontext;

}


//JNIEnv* get_jni_context()
//{
//
//   return t_pjnipcontextContext;
//
//}


::string __string(const jstring& jstring)
{

   auto pcontext = t_pjnipcontextContext;

   const ::wd16_character* utf16 = (::wd16_character*)pcontext->m_pjnicontext->GetStringChars(jstring, NULL);

   if (utf16 == NULL)
   {

      return "";

   }

   size_t length = (size_t)pcontext->m_pjnicontext->GetStringLength(jstring);

   wd16_string wstr(utf16, length);

   string str(wstr);

   pcontext->m_pjnicontext->ReleaseStringChars(jstring, (jchar*)utf16);

   return str;

}



