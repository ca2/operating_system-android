//
// Created by camilo on 2025-08-31 22:12 <3ThomasBorregaardSorensen!!
//
#pragma once


#include "jni_class.h"
#include "jni_object_interface.h"
#include "acme/platform/message.h"
#include "acme/platform/message_sink.h"


#define JNI_MESSAGE_SINK_CLASS(JXDATA, JXFUNC) \
JXFUNC(post_application_message, ::e_jni_call_void_method, "(Lplatform/platform/message/message;)V")


BEGIN_JNI_CLASS(JNI_MESSAGE_SINK_CLASS, jni_message_sink)
END_JNI_CLASS()


class CLASS_DECL_ACME_WINDOWING_ANDROID jni_message_sink :
   virtual public ::message_sink,
   virtual public jni_object
{
public:


   IMPL_JNI_OBJECT(JNI_MESSAGE_SINK_CLASS, jni_message_sink, "platform.platform.message.message_sink")


   using jni_object::jni_object;

   void on_initialize_particle() override;


   void dispatch_message(::platform::message * pmessage) override;


};



