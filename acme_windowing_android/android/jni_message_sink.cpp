//
// Created by camilo on 2025-08-31 22:12 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "jni_application_message.h"
#include "jni_message_sink.h"
#include "jni_object_impl.h"
#include "_internal.h"


void jni_message_sink::on_initialize_particle()
{

   ::jni_object::on_initialize_particle();

   defer_create_synchronization();

}

void jni_message_sink::post_simple_application_message(enum_application_message eapplicationmessage)
{

   auto papplicationmessage = øcreate_new < application_message >();

   papplicationmessage->m_eapplicationmessage = eapplicationmessage;

   post_application_message(papplicationmessage);

}

void jni_message_sink::post_application_message(::application_message * papplicationmessage)
{

   _synchronous_lock synchronouslock(this->synchronization());
   m_applicationmessagea.add(papplicationmessage);

}


::pointer < application_message > jni_message_sink::pick_application_message_to_post()
{

   _synchronous_lock synchronouslock(this->synchronization());
   if(m_applicationmessagea.is_empty())
   {

      return nullptr;

   }
   auto papplicationmessage = m_applicationmessagea.pick_first();

   return papplicationmessage;

}



void jni_message_sink::dispatch_posted_messages()
{

   while(true)
   {

      auto pmessage = pick_application_message_to_post();

      if(!pmessage)
      {

         break;

      }

      dispatch_application_message(pmessage);

   }

}


void jni_message_sink::dispatch_application_message(::application_message * papplicationmessage)
{

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   if(!m_pmethodPostApplicationMessage)
   {
      m_pmethodPostApplicationMessage=
         method(jni_method::e_call_void_method, "post_application_message",
                    "(Lplatform/platform/message_sink)V");

   }

   ::cast < ::jni_method_impl > pmethod =m_pmethodPostApplicationMessage;

//   jclass  jclassDataBlock= pcontext->FindClass("platform/platform/data_block");
  // jmethodID jmethodDataBlockConstructor = pcontext->GetMethodID(jclassDataBlock, "<init>",
                                                                 //"(Ljava/lang/String;Ljava/lang/String;[B)V");


   ::pointer < ::jni_object_impl > pobject =
      øallocate jni_application_message(papplicationmessage);

   pobject->initialize(this);

   call(pmethod, pobject->m_jobject);

}