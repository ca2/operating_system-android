//
// Created by camilo on 2025-08-31 02:11 <3ThomasBorregaardSorensen!!
//
#pragma once



#include "jni_object.h"



class jni_application_message :
   public jni_object
{
public:


   using jni_object::jni_object;


   jni_application_message(::platform::application_message * papplicationmessage);

   //int m_iMessage;
   JX(i, Message);
   //long m_lWparam;
   JX(l, Wparam);
   //long m_lLpaam;
   JX(str, Lparam);
   //byte[] m_baData;
   JX(ba, Data);


   ::pointer < ::platform::application_message > as_application_message();


};



