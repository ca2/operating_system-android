// From jni_bind.h by camilo on 2025-08-30 04:25 <3ThomasBorregaardSorensen!!
#pragma once


#include "jni_object.h"


class jni_data_block :
   public jni_object
{
public:


   using jni_object::jni_object;


   //String m_strPath;
   JX(str, Path);
   //String m_strMime;
   JX(str, Mime);
   //byte[] m_strCommandLineParameters;
   JX(ba, Data);
   //long m_lCallback;
   JX(l, DataBlock);




};



