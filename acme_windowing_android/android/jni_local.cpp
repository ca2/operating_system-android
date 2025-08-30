//
// Created by camilo on 2025-08-30 03:16 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "jni_local.h"

extern thread_local JNIEnv* t_pjnienv1;
jni_local::jni_local()
{
   m_jobject=nullptr;
}
jni_local::jni_local(jobject jobject)
{
   m_jobject=jobject;
}
jni_local::~jni_local()
{
   if (m_jobject) {
      t_pjnienv1->DeleteLocalRef(m_jobject);
      m_jobject = nullptr;

   }
}
jni_local_byte_array::jni_local_byte_array(const ::block & block)
{

   m_jbytearray = t_pjnienv1->NewByteArray(block.size());

   t_pjnienv1->SetByteArrayRegion(m_jbytearray, 0, block.size(), (const jbyte *)  block.data());

}

jni_local_string::jni_local_string(const ::scoped_string & scopedstr)
{
   if(*scopedstr.m_end == '\0') {
      m_jstring = t_pjnienv1->NewStringUTF(scopedstr.m_begin);
   } else
   {
::string str(scopedstr);
      m_jstring = t_pjnienv1->NewStringUTF(str);
   }

}
