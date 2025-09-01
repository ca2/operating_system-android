//
// Created by camilo on 2025-08-31 02:10 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "jni_application_message.h"
#include "jni_local.h"
#include "jni_object_impl.h"
#include "acme/platform/application_message.h"
#include "_internal.h"


jni_application_message::jni_application_message(::platform::application_message * papplicationmessage)
{

   auto pcontext = get_jni_context();

   jclass  jclassApplicationMessage = pcontext->FindClass("platform/platform/application_message");

   jmethodID jmethodApplicationMessageConstructor = pcontext->GetMethodID(
      jclassApplicationMessage,
      "<init>", "()V");

   m_pjniobjectinterface = øjni_object(pcontext->NewObject(
      jclassApplicationMessage,
      jmethodApplicationMessageConstructor,
      (jint) (int) papplicationmessage->m_emessage,
      (jlong) papplicationmessage->m_llWparam,
      (jlong) papplicationmessage->m_llLparam));

   if(papplicationmessage->m_memory.has_data())
   {

      setData(papplicationmessage->m_memory);

   }

}


::pointer < ::platform::application_message > jni_application_message::as_application_message()
{

   auto papplicationmessage = ::system()->øcreate_new<::platform::application_message>();

   int iMessage = getMessage();
   long long llWparam = getWparam();
   long long llLparam = getLparam();
   ::memory memory = getData();

   papplicationmessage->initialize_application_message(
      (::platform::application_message::enum_message) iMessage,
      llWparam,
      llLparam,
      memory);

   return papplicationmessage;

}



