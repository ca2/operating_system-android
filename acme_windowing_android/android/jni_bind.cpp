#include "framework.h"
#include "acme/constant/id.h"
#include "_internal.h"
#include "acme/platform/node.h"
#include "jni_data_block.h"
#include "jni_local.h"
#include "jni_object_impl.h"


::pointer < jni_bind > g_pandroidbind;


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

    auto pmessagebox = øallocate ::message_box(strMessage, strTitle, ::user::e_message_box_ok | ::user::e_message_box_icon_exclamation, strDetails);

   pmessagebox->initialize(pparticle);

pmessagebox->sync();


   __android_log_write(ANDROID_LOG_WARN, "com.ca2", strDetails);

}






jni_bind* jni_bind::get()
{

   return g_pandroidbind;

}



void jni_bind::set(jni_bind* pdirect)
{

   g_pandroidbind = pdirect;

}


void jni_bind::post_media_store_operation(::data::block * pdatablock)
{

   auto pbind = ::jni_bind::get();

   ::cast < jni_object_impl > pjni = m_pjniobjectinterface;

   jobject     jobjectBind = pjni->m_jobject;
   //jclass      jclassBind = pjni->m_jclass;


   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   // 1. Get the class of the object
   //jclass cls = p->GetObjectClass(javaObj);

   // 2. Find method IDs
   //auto pmethod;

   ::jni_data_block datablock(pdatablock);

   post_media_store_operation(pjnicontext, datablock.p_jobject());

//   jmethodID methodPostMediaStoreOperation = pcontext->GetMethodID(jclassBind, "post_media_store_operation", "(Lplatform/platform/data_block)V");
//
//   if (methodPostMediaStoreOperation == nullptr) {
//      error() << "method not found";
//      return; // method not found
//   }
//
//   jni_local_string jnistringPath(pdatablock->m_strPath);
//   jni_local_string jnistringMime(pdatablock->m_strPath);
//
//   jclass  jclassDataBlock= pcontext->FindClass("platform/platform/data_block");
//   jmethodID jmethodDataBlockConstructor = pcontext->GetMethodID(jclassDataBlock, "<init>",
//                                                                 "(Ljava/lang/String;Ljava/lang/String;[B)V");
//
//// Prepare args
//   //jstring jname = (*pcontext)->NewStringUTF(pcontext, "example");
//   //jstring jmime = (*pcontext)->NewStringUTF(pcontext, "application/octet-stream");
//
//   //jbyte data[3] = {1, 2, 3};
//   //jbyteArray jdata = (*pcontext)->NewByteArray(pcontext, 3);
//   //(*pcontext)->SetByteArrayRegion(pcontext, jdata, 0, 3, data);
//
//// Create object
//pdatablock->increment_reference_count();
//jlong jlDataBlock = (long)(::uptr)(void*)(::data::block*)pdatablock;
//jboolean jbWrite = pdatablock->m_bWrite ? 1 : 0;
//   jni_local objDataBlock(pcontext->NewObject(jclassDataBlock, jmethodDataBlockConstructor,
//                                     jlDataBlock,
//                                     jbWrite,
//                                     jnistringPath.m_jstring,
//                                     jnistringMime.m_jstring));
//
//   if(pdatablock->m_bWrite && pdatablock->m_memory.has_data())
//   {
//
//      jni_local_byte_array jnibytearrayData(pdatablock->m_memory);
//
//
//      jmethodID jmethodDataBlockSetData = pcontext->GetMethodID(jclassDataBlock, "set_data",
//                                                                    "([B)V");
//
//      pcontext->CallVoidMethod(objDataBlock.m_jobject, jmethodDataBlockSetData, jnibytearrayData.m_jobject);
//
//   }
//
//   pcontext->CallVoidMethod(jobjectBind, methodPostMediaStoreOperation, objDataBlock.m_jobject);
//
//   pbind->call("post_media_store_operation", objDataBlock.m_jobject);

}



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
