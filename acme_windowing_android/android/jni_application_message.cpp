//
// Created by camilo on 2025-08-31 02:10 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "jni_application_message.h"
#include "jni_local.h"
#include "jni_object_impl.h"
#include "acme/platform/application_message.h"
#include "_internal.h"


jni_application_message::jni_application_message(::application_message * papplicationmessage)
{

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   jclass  jclassApplicationMessage = pcontext->FindClass("platform/platform/application_message");

   jmethodID jmethodApplicationMessageConstructor = pcontext->GetMethodID(
      jclassApplicationMessage,
      "<init>", "()V");

   m_pjniobjectinterface = øjni_object(pcontext->NewObject(
      jclassApplicationMessage,
      jmethodApplicationMessageConstructor,
      (jint) (int) papplicationmessage->m_eapplicationmessage,
      (jlong) papplicationmessage->m_llWparam,
      (jlong) papplicationmessage->m_llLparam));

   if(papplicationmessage->m_memory.has_data())
   {

      setData(papplicationmessage->m_memory);

   }

}


::pointer < ::application_message > jni_application_message::as_application_message()
{

   auto papplicationmessage = ::system()->øcreate_new<::application_message>();

   int iMessage = getMessage();
   long long llWparam = getWparam();
   long long llLparam = getLparam();
   ::memory memory = getData();

   papplicationmessage->initialize_application_message(
      (::enum_application_message) iMessage,
      llWparam,
      llLparam,
      memory);

   return papplicationmessage;

}



