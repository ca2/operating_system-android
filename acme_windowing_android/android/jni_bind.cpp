#include "framework.h"
#include "acme/constant/id.h"
#include "_internal.h"
#include "acme/platform/node.h"
#include "acme/user/interface/message_box.h"
#include "jni_data_block.h"
#include "jni_local.h"
#include "jni_object_impl.h"


::pointer < jni_bind > g_pandroidbind;
JavaVM * g_pjavavmBind = nullptr;


static void jni_bind_remember_java_vm(JNIEnv * penv)
{

   if(!penv || g_pjavavmBind)
   {

      return;

   }

   penv->GetJavaVM(&g_pjavavmBind);

}


CLASS_DECL_ACME_WINDOWING_ANDROID void operating_system_log_exception(::particle * pparticle, ::exception& exception, const ::scoped_string & scopedstrMoreDetails)
{

   string strMessage;

   strMessage += "Failed to initialize application\n";
   strMessage += "\n";
   strMessage += exception.m_strMessage + "\n";
   strMessage += "(" + ::as_string(exception.m_estatus) + ")";

   string strTitle;

   strTitle = "Exception during initialization";

   string strDetails;

   strDetails += strMessage + "\n";
   strDetails += exception.m_strDetails + "\n\n";
   strDetails += "\n";
   strDetails += "PID: " + ::as_string(pparticle->node()->current_process_identifier()) + "\n";
   //strDetails += "Working Directory: " + string(GetCurrentDirectory()) + "\n\n";

   if (scopedstrMoreDetails.has_character())
   {

      strDetails += scopedstrMoreDetails + "\n";

   }

   if (exception.m_strCallStackTrace)
   {

      strDetails += "\n\n" + string(exception.m_strCallStackTrace);

   }

   auto pmessagebox = pparticle->createø<::user_interface::message_box>();

   pmessagebox->initialize_message_box(strMessage, strTitle, ::user::e_message_box_ok | ::user::e_message_box_icon_exclamation, strDetails);

   pmessagebox->display(e_display_normal, {});

   pmessagebox->wait_for_dialog_response();

   __android_log_write(ANDROID_LOG_WARN, "com.ca2", strDetails);

}






jni_bind* jni_bind::get()
{

   return g_pandroidbind;

}



void jni_bind::set(jni_bind* pdirect)
{

   g_pandroidbind = pdirect;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   if(pjnicontext)
   {

      jni_bind_remember_java_vm(pjnicontext->m_pjnicontext);

   }

}


static JNIEnv * jni_bind_env()
{

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   if(!pjnicontext)
   {

      if(!g_pjavavmBind)
      {

         return nullptr;

      }

      JNIEnv * penv = nullptr;

      if(g_pjavavmBind->AttachCurrentThread(&penv, nullptr) != JNI_OK)
      {

         return nullptr;

      }

      set_jni_context(penv, 0);

      return penv;

   }

   auto penv = pjnicontext->m_pjnicontext;

   jni_bind_remember_java_vm(penv);

   return penv;

}


static void jni_bind_clear_exception(JNIEnv * penv)
{

   if(penv && penv->ExceptionCheck())
   {

      penv->ExceptionDescribe();
      penv->ExceptionClear();

   }

}


bool jni_bind::secure_app_storage_set(const ::scoped_string & scopedstrName, const ::scoped_string & scopedstrValue)
{

   auto penv = jni_bind_env();

   if(!penv)
   {

      return false;

   }

   jni_local_string jnistringName(scopedstrName);
   jni_local_string jnistringValue(scopedstrValue);
   auto jobjectBind = (jobject) p_jobject();
   jni_local jclassBind(penv->GetObjectClass(jobjectBind));
   auto jmethod = penv->GetMethodID((jclass) jclassBind.m_jobject, "secure_app_storage_set", "(Ljava/lang/String;Ljava/lang/String;)Z");

   if(!jmethod)
   {

      jni_bind_clear_exception(penv);
      return false;

   }

   auto bResult = penv->CallBooleanMethod(jobjectBind, jmethod, jnistringName.m_jstring, jnistringValue.m_jstring);

   jni_bind_clear_exception(penv);

   return bResult != 0;

}


::string jni_bind::secure_app_storage_get(const ::scoped_string & scopedstrName)
{

   auto penv = jni_bind_env();

   if(!penv)
   {

      return {};

   }

   jni_local_string jnistringName(scopedstrName);
   auto jobjectBind = (jobject) p_jobject();
   jni_local jclassBind(penv->GetObjectClass(jobjectBind));
   auto jmethod = penv->GetMethodID((jclass) jclassBind.m_jobject, "secure_app_storage_get", "(Ljava/lang/String;)Ljava/lang/String;");

   if(!jmethod)
   {

      jni_bind_clear_exception(penv);
      return {};

   }

   jni_local_string jnistringResult(penv->CallObjectMethod(jobjectBind, jmethod, jnistringName.m_jstring));

   jni_bind_clear_exception(penv);

   return jnistringResult.as_string();

}


bool jni_bind::secure_app_storage_delete(const ::scoped_string & scopedstrName)
{

   auto penv = jni_bind_env();

   if(!penv)
   {

      return false;

   }

   jni_local_string jnistringName(scopedstrName);
   auto jobjectBind = (jobject) p_jobject();
   jni_local jclassBind(penv->GetObjectClass(jobjectBind));
   auto jmethod = penv->GetMethodID((jclass) jclassBind.m_jobject, "secure_app_storage_delete", "(Ljava/lang/String;)Z");

   if(!jmethod)
   {

      jni_bind_clear_exception(penv);
      return false;

   }

   auto bResult = penv->CallBooleanMethod(jobjectBind, jmethod, jnistringName.m_jstring);

   jni_bind_clear_exception(penv);

   return bResult != 0;

}


bool jni_bind::secure_app_storage_contains(const ::scoped_string & scopedstrName)
{

   auto penv = jni_bind_env();

   if(!penv)
   {

      return false;

   }

   jni_local_string jnistringName(scopedstrName);
   auto jobjectBind = (jobject) p_jobject();
   jni_local jclassBind(penv->GetObjectClass(jobjectBind));
   auto jmethod = penv->GetMethodID((jclass) jclassBind.m_jobject, "secure_app_storage_contains", "(Ljava/lang/String;)Z");

   if(!jmethod)
   {

      jni_bind_clear_exception(penv);
      return false;

   }

   auto bResult = penv->CallBooleanMethod(jobjectBind, jmethod, jnistringName.m_jstring);

   jni_bind_clear_exception(penv);

   return bResult != 0;

}


int jni_bind::open_content_file_descriptor(const ::scoped_string & scopedstrUri, const ::scoped_string & scopedstrMode)
{

   auto penv = jni_bind_env();

   if(!penv)
   {

      return -1;

   }

   jni_local_string jnistringUri(scopedstrUri);
   jni_local_string jnistringMode(scopedstrMode);
   auto jobjectBind = (jobject) p_jobject();
   jni_local jclassBind(penv->GetObjectClass(jobjectBind));
   auto jmethod = penv->GetMethodID((jclass) jclassBind.m_jobject, "open_content_file_descriptor", "(Ljava/lang/String;Ljava/lang/String;)I");

   if(!jmethod)
   {

      jni_bind_clear_exception(penv);
      return -1;

   }

   auto iDescriptor = penv->CallIntMethod(jobjectBind, jmethod, jnistringUri.m_jstring, jnistringMode.m_jstring);

   jni_bind_clear_exception(penv);

   return iDescriptor;

}


::string jni_bind::get_google_access_token(const ::scoped_string & scopedstrScope)
{

   __android_log_print(ANDROID_LOG_INFO, "jni_bind", "get_google_access_token begin");

   auto penv = jni_bind_env();

   if(!penv)
   {

      __android_log_print(ANDROID_LOG_ERROR, "jni_bind", "get_google_access_token no JNIEnv");

      return {};

   }

   __android_log_print(ANDROID_LOG_INFO, "jni_bind", "get_google_access_token env=%p", penv);

   jni_local_string jnistringScope(scopedstrScope);
   auto jobjectBind = (jobject) p_jobject();

   __android_log_print(ANDROID_LOG_INFO, "jni_bind", "get_google_access_token bind=%p", jobjectBind);

   jni_local jclassBind(penv->GetObjectClass(jobjectBind));

   if(!jclassBind.m_jobject)
   {

      __android_log_print(ANDROID_LOG_ERROR, "jni_bind", "get_google_access_token no bind class");
      jni_bind_clear_exception(penv);
      return {};

   }

   auto jmethod = penv->GetMethodID((jclass) jclassBind.m_jobject, "get_google_access_token", "(Ljava/lang/String;)Ljava/lang/String;");

   if(!jmethod)
   {

      __android_log_print(ANDROID_LOG_ERROR, "jni_bind", "get_google_access_token no method");
      jni_bind_clear_exception(penv);
      return {};

   }

   __android_log_print(ANDROID_LOG_INFO, "jni_bind", "get_google_access_token before CallObjectMethod");

   auto jobjectResult = penv->CallObjectMethod(jobjectBind, jmethod, jnistringScope.m_jstring);

   __android_log_print(ANDROID_LOG_INFO, "jni_bind", "get_google_access_token after CallObjectMethod result=%p exception=%d",
      jobjectResult,
      penv->ExceptionCheck() ? 1 : 0);

   jni_bind_clear_exception(penv);

   jni_local_string jnistringResult(jobjectResult);

   auto strResult = jnistringResult.as_string();

   __android_log_print(ANDROID_LOG_INFO, "jni_bind", "get_google_access_token end result_length=%d", (int) strResult.length());

   return strResult;

}


void jni_bind::clear_google_access_token(const ::scoped_string & scopedstrScope, const ::scoped_string & scopedstrAccessToken)
{

   auto penv = jni_bind_env();

   if(!penv)
   {

      return;

   }

   jni_local_string jnistringScope(scopedstrScope);
   jni_local_string jnistringAccessToken(scopedstrAccessToken);
   auto jobjectBind = (jobject) p_jobject();
   jni_local jclassBind(penv->GetObjectClass(jobjectBind));
   auto jmethod = penv->GetMethodID((jclass) jclassBind.m_jobject, "clear_google_access_token", "(Ljava/lang/String;Ljava/lang/String;)V");

   if(!jmethod)
   {

      jni_bind_clear_exception(penv);
      return;

   }

   penv->CallVoidMethod(jobjectBind, jmethod, jnistringScope.m_jstring, jnistringAccessToken.m_jstring);

   jni_bind_clear_exception(penv);

}


//void jni_bind::post_media_store_operation(::data::block * pdatablock)
//{
//
//   auto pbind = ::jni_bind::get();
//
//   ::cast < jni_object_impl > pjni = m_pjniobjectinterface;
//
//   jobject     jobjectBind = pjni->m_jobject;
//   //jclass      jclassBind = pjni->m_jclass;
//
//
//   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
//
//   auto pcontext = pjnicontext->m_pjnicontext;
//
//   // 1. Get the class of the object
//   //jclass cls = p->GetObjectClass(javaObj);
//
//   // 2. Find method IDs
//   //auto pmethod;
//
//   ::jni_data_block datablock(pdatablock);
//
//   post_media_store_operation(pjnicontext, datablock.p_jobject());
//
////   jmethodID methodPostMediaStoreOperation = pcontext->GetMethodID(jclassBind, "post_media_store_operation", "(Lplatform/platform/data_block)V");
////
////   if (methodPostMediaStoreOperation == nullptr) {
////      error() << "method not found";
////      return; // method not found
////   }
////
////   jni_local_string jnistringPath(pdatablock->m_strPath);
////   jni_local_string jnistringMime(pdatablock->m_strPath);
////
////   jclass  jclassDataBlock= pcontext->FindClass("platform/platform/data_block");
////   jmethodID jmethodDataBlockConstructor = pcontext->GetMethodID(jclassDataBlock, "<init>",
////                                                                 "(Ljava/lang/String;Ljava/lang/String;[B)V");
////
////// Prepare args
////   //jstring jname = (*pcontext)->NewStringUTF(pcontext, "example");
////   //jstring jmime = (*pcontext)->NewStringUTF(pcontext, "application/octet-stream");
////
////   //jbyte data[3] = {1, 2, 3};
////   //jbyteArray jdata = (*pcontext)->NewByteArray(pcontext, 3);
////   //(*pcontext)->SetByteArrayRegion(pcontext, jdata, 0, 3, data);
////
////// Create object
////pdatablock->increment_reference_count();
////jlong jlDataBlock = (long)(::uptr)(void*)(::data::block*)pdatablock;
////jboolean jbWrite = pdatablock->m_bWrite ? 1 : 0;
////   jni_local objDataBlock(pcontext->NewObject(jclassDataBlock, jmethodDataBlockConstructor,
////                                     jlDataBlock,
////                                     jbWrite,
////                                     jnistringPath.m_jstring,
////                                     jnistringMime.m_jstring));
////
////   if(pdatablock->m_bWrite && pdatablock->m_memory.has_data())
////   {
////
////      jni_local_byte_array jnibytearrayData(pdatablock->m_memory);
////
////
////      jmethodID jmethodDataBlockSetData = pcontext->GetMethodID(jclassDataBlock, "set_data",
////                                                                    "([B)V");
////
////      pcontext->CallVoidMethod(objDataBlock.m_jobject, jmethodDataBlockSetData, jnibytearrayData.m_jobject);
////
////   }
////
////   pcontext->CallVoidMethod(jobjectBind, methodPostMediaStoreOperation, objDataBlock.m_jobject);
////
////   pbind->call("post_media_store_operation", objDataBlock.m_jobject);
//
//}



//void jni_bind::media_store_get_data(::data::block * pdatablock)
//{
//
//   ASSERT(!pdatablock->m_bWrite);
//
//   auto pbind = ::jni_bind::get();
//
//   ::cast < jni_object_impl > pjni = m_pjniobjectinterface;
//
//   jobject     jobjectBind = pjni->m_jobject;
//   jclass      jclassBind = pjni->m_jclass;
//
//
//   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
//
//   auto pcontext = pjnicontext->m_pjnicontext;
//
//
//   // 1. Get the class of the object
//   //jclass cls = p->GetObjectClass(javaObj);
//
//   // 2. Find method IDs
//   jmethodID methodGetDataBlock = pcontext->GetMethodID(jclassBind, "media_store_get_data", "(Ljava/lang/String;Ljava/lang/String;[BI)V");
//
//   if (methodGetDataBlock == nullptr) {
//      error() << "method not found";
//      return; // method not found
//   }
//
//   jni_local_string jnistringPath(pdatablock->m_strPath);
//   jni_local_string jnistringMime(pdatablock->m_strPath);
//   //jni_local_byte_array jnibytearrayData(pdatablock->m_memory);
//
//   jclass  jclassDataBlock= pcontext->FindClass("platform/platform/data_block");
//   jmethodID jmethodDataBlockConstructor = pcontext->GetMethodID(jclassDataBlock, "<init>",
//                                                                 "(Ljava/lang/String;Ljava/lang/String;J)V");
//
//// Prepare args
//   //jstring jname = (*pcontext)->NewStringUTF(pcontext, "example");
//   //jstring jmime = (*pcontext)->NewStringUTF(pcontext, "application/octet-stream");
//
//   //jbyte data[3] = {1, 2, 3};
//   //jbyteArray jdata = (*pcontext)->NewByteArray(pcontext, 3);
//   //(*pcontext)->SetByteArrayRegion(pcontext, jdata, 0, 3, data);
//
//   pdatablock->increment_reference_count();
//// Create object
//   jni_local obj(pcontext->NewObject(jclassDataBlock, jmethodDataBlockConstructor,
//                                     jnistringPath.m_jstring,
//                                     jnistringMime.m_jstring,
//                                     (jlong) (::uptr)(void *) pdatablock));
//
//   pcontext->CallVoidMethod(jobjectBind, methodGetDataBlock, obj.m_jobject);
//
//
//
//}
