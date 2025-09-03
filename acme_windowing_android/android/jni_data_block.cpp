// From jni_bind.cpp by camilo on 2025-08-30 04:27 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "jni_data_block.h"
#include "jni_object_impl.h"
#include "jni_local.h"


//jni_data_block::jni_data_block(::jni_object_interface * pjniobjectinterface)
//{
//
//   initialize_jni_object(pjniobjectinterface);
//
//}


jni_data_block::jni_data_block(::data::block * pdatablock)
{

   auto pjniobject = create_jni_object(pdatablock);

   initialize_jni_object(pjniobject);

}


::pointer < ::jni_object_interface> jni_data_block::create_jni_object(::data::block * pdatablock)
{

//   øjni_object()

//   ::cast<::jni_context_impl> pjnicontext = ::jni_context::get();
//
//   auto pcontext = pjnicontext->m_pjnicontext;
//
//   //jclass jclassApplicationMessage = class_cache_get(pcontext, "platform.platform.message.message");
//
   auto pclass = s_class();

   auto pmethodConstructJZStrStr = pclass->jni_method_construct_JZStrStr();

   ;

   auto pjniobject = pclass->new_jni_object(
      pmethodConstructJZStrStr,
      (jlong) (::iptr) (void *) pdatablock,
      (jboolean ) pdatablock->m_bWrite ? 1 :0,
      (jstring) jni_local_string(pdatablock->m_strPath).m_jstring,
      (jstring) jni_local_string(pdatablock->m_strMime).m_jstring);

//
//   //jclass jclassApplicationMessage = pcontext->FindClass("platform/platform/message/message");
//
////   jmethodID jmethodApplicationMessageConstructor = pcontext->GetMethodID(
////      jclassApplicationMessage,
////      "<init>", "(IJJ)V");
//
////   jni_message jnimessage()
////
////   auto pjniobject = øjni_object(pcontext->NewObject(
////      jclassApplicationMessage,
////      jmethodApplicationMessageConstructor,
////   (jint) (int) pmessage->m_emessage,
////      (jlong) pmessage->m_llWparam,
////      (jlong) pmessage->m_llLparam));

   return pjniobject;


}