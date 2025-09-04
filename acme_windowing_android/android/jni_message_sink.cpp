//
// Created by camilo on 2025-08-31 22:12 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "jni_bind.h"
#include "jni_message.h"
#include "jni_context.h"
#include "jni_message_sink.h"


void jni_message_sink::on_initialize_particle()
{

   ::jni_object::on_initialize_particle();

   defer_create_synchronization();

}


void jni_message_sink::dispatch_message(::platform::message * pmessage)
{

   auto pcontext = ::jni_context::get();

   jni_message message(pmessage);

   post_application_message(pcontext, message.p_jobject());

   debug() << "jni_message_sink::dispatch_message end";

}



