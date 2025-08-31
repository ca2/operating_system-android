//
// Created by camilo on 2025-08-30 03:11 <3ThomasBorregaardSorensen!!
//
#pragma once

#include "_internal.h"


class jni_local
{
public:

   union
   {
jobject m_jobject;
      jstring m_jstring;
      jbyteArray  m_jbytearray;
   };

   jni_local();
   jni_local(jobject jobject);
   ~jni_local();

};

class jni_local_string :
   public jni_local
{
public:

   jni_local_string():jni_local(){}
   jni_local_string(jobject jobject) : jni_local(jobject){}
   jni_local_string(const ::scoped_string & scopedstr);
~jni_local_string(){}

::string as_string();

};

class jni_local_byte_array :
   public jni_local
{
public:

   jni_local_byte_array():jni_local(){}
   jni_local_byte_array(jobject jobject) : jni_local(jobject){}
   jni_local_byte_array(const ::block & block);
   ~jni_local_byte_array(){}

   ::memory as_memory();

};

//#endif //ANDROID_STUDIO_BUILD_ALL_JNI_STRING_H
