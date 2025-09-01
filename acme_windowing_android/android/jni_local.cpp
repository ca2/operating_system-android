//
// Created by camilo on 2025-08-30 03:16 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "jni_local.h"


jni_local::jni_local()
{

   m_jobject = nullptr;

}


jni_local::jni_local(jobject jobject)
{

   m_jobject = jobject;

}


jni_local::~jni_local()
{

   if (m_jobject)
   {
      
      auto pcontext = get_jni_context();

      pcontext->DeleteLocalRef(m_jobject);

      m_jobject = nullptr;

   }

}


jni_local_byte_array::jni_local_byte_array(const ::block & block)
{

   auto pcontext = get_jni_context();

   m_jbytearray = pcontext->NewByteArray(block.size());

   pcontext->SetByteArrayRegion(m_jbytearray, 0, block.size(), (const jbyte *)  block.data());

}


jni_local_string::jni_local_string(const ::scoped_string & scopedstr)
{

   auto pcontext = get_jni_context();

   if(*scopedstr.m_end == '\0')
   {

      m_jstring = pcontext->NewStringUTF(scopedstr.m_begin);

   }
   else
   {

      ::string str(scopedstr);

      m_jstring = pcontext->NewStringUTF(str);

   }

}


::string jni_local_string::as_string()
{

   if(!m_jstring)
   {

      return {};

   }

   auto pcontext = get_jni_context();

   const_char_pointer nativeString = pcontext->GetStringUTFChars(m_jstring, 0);

   string str = nativeString;

   pcontext->ReleaseStringUTFChars(m_jstring, nativeString);

   return str;

}


::memory jni_local_byte_array::as_memory()
{

   auto pcontext = get_jni_context();

   jbyte* buffer = pcontext->GetByteArrayElements(m_jbytearray, NULL);

   jsize length = pcontext->GetArrayLength(m_jbytearray);

   memory memory;

   memory.assign(buffer, length);

   pcontext->ReleaseByteArrayElements(m_jbytearray, buffer, 0);

   return ::transfer(memory);

}



