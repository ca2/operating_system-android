// From jni_bind.h by camilo on 2025-08-30 04:25 <3ThomasBorregaardSorensen!!
#pragma once


#include "jni_class.h"
#include "jni_object.h"

//String m_strPath;
//String m_strMime;
//byte[] m_strCommandLineParameters;
//long m_lCallback;

#define JNI_DATA_BLOCK_CLASS(JXDATA, JXFUNC) \
JXDATA(str, Path) \
JXDATA(str, Mime) \
JXDATA(ba, Data) \
JXDATA(l, DataBlock)                  \
JXFUNC(construct_JZStrStr, ::e_jni_call__init__, "(JZLjava/lang/String;Ljava/lang/String;)V")

//#define JNI_DATA_BLOCK_CLASS_FUNC(JX)

BEGIN_JNI_CLASS(JNI_DATA_BLOCK_CLASS,jni_data_block)
END_JNI_CLASS()


class jni_data_block :
   public jni_object
{
public:


   IMPL_JNI_OBJECT(JNI_DATA_BLOCK_CLASS, jni_data_block, "platform.platform.platform.data_block")

   using jni_object::jni_object;


   jni_data_block(::data::block * pdatablock);

   static ::pointer < ::jni_object_interface> create_jni_object(::data::block * pdatablock);


};



