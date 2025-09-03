//
// Created by camilo on 2025-08-31 22:12 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "jni_bind.h"
#include "jni_message.h"
#include "jni_context.h"
#include "jni_message_sink.h"
//#include "jni_object_impl.h"
//#include "_internal.h"




void jni_message_sink::on_initialize_particle()
{

   ::jni_object::on_initialize_particle();

   defer_create_synchronization();

}

//void jni_message_sink::post_simple_message(enum_message emessage)
//{
//
//   auto pmessage = øcreate_new < ::platform::message >();
//
//   pmessage->m_emessage = emessage;
//
//   post_message(pmessage);
//
//}
//
//void jni_message_sink::post_message(::platform::message * pmessage)
//{
//
//   _synchronous_lock synchronouslock(this->synchronization());
//
//   m_messagea.add(pmessage);
//
//}

//
//::pointer < ::platform::message > jni_message_sink::pick_message_to_post()
//{
//
//   _synchronous_lock synchronouslock(this->synchronization());
//
//   if(m_messagea.is_empty())
//   {
//
//      return nullptr;
//
//   }
//
//   auto pmessage = m_messagea.pick_first();
//
//   return pmessage;
//
//}
//

//
//void jni_message_sink::dispatch_posted_messages()
//{
//
//   while(true)
//   {
//
//      auto pmessage = pick_message_to_post();
//
//      if(!pmessage)
//      {
//
//         break;
//
//      }
//
//      dispatch_message(pmessage);
//
//   }
//
//}


void jni_message_sink::dispatch_message(::platform::message * pmessage)
{

   auto pcontext = ::jni_context::get();

   //auto pcontext = pjnicontext->m_pjnicontext;

   //if(!m_pmethodPostApplicationMessage)
   //{


   //}


   //auto pbind = ::jni_bind::get();

   //auto pmethod = this_class()->m_pmethodPostApplicationMessage;;
   //::cast < ::jni_method_impl > pmethod =m_pmethodPostApplicationMessage;

//   jclass  jclassDataBlock= pcontext->FindClass("platform/platform/data_block");
  // jmethodID jmethodDataBlockConstructor = pcontext->GetMethodID(jclassDataBlock, "<init>",
                                                                 //"(Ljava/lang/String;Ljava/lang/String;[B)V");

   jni_message message(pmessage);

   post_application_message(pcontext, message.p_jobject());

}