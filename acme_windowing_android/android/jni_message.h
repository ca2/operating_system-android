//
// Created by camilo on 2025-08-31 02:11 <3ThomasBorregaardSorensen!!
//
#pragma once


#include "jni_class.h"
#include "jni_object.h"
//int m_iMessage;
//   //long m_lWparam;
//   //long m_lLpaam;
//   //byte[] m_baData;
#define JNI_MESSAGE_CLASS(JXDATA, JXFUNC) \
JXDATA(i, Message) \
JXDATA(l, Wparam) \
JXDATA(l, Lparam) \
JXDATA(ba, Data)                          \
JXFUNC(construct_IJJ, ::e_jni_call__init__, "(IJJ)V")



BEGIN_JNI_CLASS(JNI_MESSAGE_CLASS, jni_message)
END_JNI_CLASS()


class jni_message :
   public jni_object
{
public:

   IMPL_JNI_OBJECT(JNI_MESSAGE_CLASS, jni_message, "platform.platform.message.message")

   using jni_object::jni_object;


   //jni_message(::jni_object_interface * pjniobjectinterface);
   jni_message(::platform::message * pmessage);

//   //int m_iMessage;
//   JX(i, Message);
//   //long m_lWparam;
//   JX(l, Wparam);
//   //long m_lLpaam;
//   JX(l, Lparam);
//   //byte[] m_baData;
//   JX(ba, Data);


   ::pointer < ::platform::message > as_message();

   static ::pointer < ::jni_object_interface> create_jni_object(::platform::message * pmessage);

};



