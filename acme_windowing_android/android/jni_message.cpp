//
// Created by camilo on 2025-08-31 02:10 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "jni_message.h"
#include "jni_local.h"
#include "jni_object_impl.h"
#include "acme/platform/message.h"
#include "_internal.h"


//
//jni_message::jni_message(::jni_object_interface * pjniobjectinterface)
//{
//
//   initialize_jni_object(pjniobjectinterface);
//
//}


jni_message::jni_message(::platform::message * pmessage)
{

   auto pjniobject = create_jni_object(pmessage);

   initialize_jni_object(pjniobject);

   if (pmessage->m_memory.has_data()) {

      setData(pmessage->m_memory);

   }

}


::pointer < ::platform::message > jni_message::as_message()
{

   auto pmessage = ::system()->øcreate_new<::platform::message>();

   int iMessage = getMessage();
   long long llWparam = getWparam();
   long long llLparam = getLparam();
   ::memory memory = getData();

   pmessage->initialize_message(
      (::enum_message) iMessage,
      llWparam,
      llLparam,
      memory);

   return pmessage;

}


::pointer < ::jni_object_interface> jni_message::create_jni_object(::platform::message * pmessage)
{


   auto pclass = s_class();

   auto pmethodConstructIJJ = pclass->jni_method_construct_IJJ();

   auto pjniobject = pclass->new_jni_object(
      pmethodConstructIJJ,
      (jint) (int) pmessage->m_emessage,
      (jlong) pmessage->m_llWparam,
      (jlong) pmessage->m_llLparam);


//   ::cast<::jni_context_impl> pjnicontext = ::jni_context::get();
//
//   auto pcontext = pjnicontext->m_pjnicontext;
//
//   jclass jclassApplicationMessage = class_cache_get(pcontext, "platform.platform.message.message");
//
//   //jclass jclassApplicationMessage = pcontext->FindClass("platform/platform/message/message");
//
//   jmethodID jmethodApplicationMessageConstructor = pcontext->GetMethodID(
//      jclassApplicationMessage,
//      "<init>", "(IJJ)V");
//
//   auto pjniobject = øjni_object(pcontext->NewObject(
//      jclassApplicationMessage,
//      jmethodApplicationMessageConstructor,
//      (jint) (int) pmessage->m_emessage,
//      (jlong) pmessage->m_llWparam,
//      (jlong) pmessage->m_llLparam));

 return pjniobject;


}