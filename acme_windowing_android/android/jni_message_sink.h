//
// Created by camilo on 2025-08-31 22:12 <3ThomasBorregaardSorensen!!
//
#pragma once


#include "jni_object.h"
#include "acme/platform/application_message.h"
#include "_internal.h"


class CLASS_DECL_ACME_WINDOWING_ANDROID jni_message_sink :
   public jni_object
{
public:

   ::pointer < jni_method > m_pmethodPostApplicationMessage;

   ::pointer_array_base<application_message> m_applicationmessagea;

   using jni_object::jni_object;

   void on_initialize_particle() override;


   virtual void post_simple_application_message(enum_application_message eapplicationmessage);
   virtual void post_application_message(::application_message * papplicationmessage);


   ::pointer < application_message > pick_application_message_to_post();


   virtual void dispatch_posted_messages();
   virtual void dispatch_application_message(::application_message * papplicationmessage);


};



