#include "framework.h"
#include "application_sink.h"
#include "acme_windowing_android/android/_internal.h"
#include "acme_windowing_android/android/android_asset_manager.h"
#include "acme_windowing_android/android/android_asset.h"
#include "acme/inline/application/main.h"
//#include "acme/user/nano/_nano.h"
#include "acme/platform/acme.h"
#include "acme/platform/node.h"
//#include "acme/platform/sequencer.h"
#include "acme/parallelization/manual_reset_happening.h"
#include "acme/platform/application.h"
#include "acme/platform/system.h"
#include "acme/platform/system_setup.h"
#include "acme/prototype/string/c_string.h"
#include "acme_windowing_android/android/android_asset_manager.h"
#include "acme_windowing_android/android/jni_message.h"
#include "acme_windowing_android/android/jni_data_block.h"
#include "acme_windowing_android/android/jni_local.h"
#include "acme_windowing_android/android/jni_message_sink.h"
#include "acme_windowing_android/android/jni_object_impl.h"

//#include "acme/user/nano/nano.h"
//typedef void(*PFN_factory)(::factory::factory* pfactory);

//typedef int(*PFN_MAIN)(int argc, char * argv[], char * envp[], const_char_pointer p1, const_char_pointer p2);

extern "C"
{

typedef void (* PFN_CREATE_SYSTEM)();
typedef void (* PFN_INITIALIZE_SYSTEM)(int argc, char * argv[], char * envp[],
                                       const_char_pointer p1, const_char_pointer p2);
typedef int (* PFN_MAIN)();

}


//void * g_pHandleAppSo = nullptr;
//::c::string g_cstrCurrentAppId;
//::c::string g_cstrCurrentAppLibraryTitle;
//::c::string g_cstrCurrentAppLibraryName;


class c_library
{
public:


   ::c::string m_cstrLibrary;

   void * m_pHandle;

   bool m_bAutoClose = false;

   c_library()
   {

      m_pHandle = nullptr;

   }


   ~c_library()
   {

      if(m_bAutoClose)
      {

         close();

      }


   }


   void open(const_char_pointer pszLibraryName)
   {

      m_pHandle = ::dlopen(pszLibraryName, RTLD_NOW);

      if(::is_null(m_pHandle))
      {

         __android_log_print(
            ANDROID_LOG_ERROR,
            pszLibraryName,
            "dlopen failed: %s", dlerror());

         throw ::error_resource;

      }

      m_cstrLibrary = pszLibraryName;

   }


   void close()
   {

      if(::is_set(m_pHandle))
      {

         ::dlclose(m_pHandle);

         m_pHandle = nullptr;

      }

   }

   virtual void * handle()
   {

      return m_pHandle;

   }


   template < typename PFN >
   PFN function(const_char_pointer p)
   {

      auto pfn = (PFN) ::dlsym(this->handle(), p);

      if (!pfn) {

         __android_log_print(
            ANDROID_LOG_ERROR,
            p,
            "dlsym failed: %s", dlerror());


      }

      return pfn;

   }


};


class c_application_namespace_library :
   virtual public c_library
{
public:

   ::c::string m_cstrAppId;

   c_application_namespace_library(::c::string cstrAppId)
      :   m_cstrAppId(cstrAppId)
   {

      m_pHandle = nullptr;

   }


   ~c_application_namespace_library()
   {

      if(::is_set(m_pHandle)) {

         ::dlclose(m_pHandle);

      }

   }

   ::c::string title()
   {

      ::c::string cstrLibraryTitle(m_cstrAppId);

      cstrLibraryTitle.find_replace('/', '_');
      cstrLibraryTitle.find_replace('-', '_');

      return ::transfer(cstrLibraryTitle);

   }

   ::c::string application_namespace_name()
   {

      return this->title();

   }

   ::c::string name()
   {

      ::c::string cstrLibraryName("lib");

      cstrLibraryName += this->title();

      cstrLibraryName += ".so";

      return ::transfer(cstrLibraryName);

   }


   ::c::string main_name(const_char_pointer p)
   {

      ::c::string cstrApplicationNamespaceMainName(this->application_namespace_name());

      cstrApplicationNamespaceMainName += "_main_";

      cstrApplicationNamespaceMainName += p;

      return ::transfer(cstrApplicationNamespaceMainName);

   }


   void * handle() override
   {

      if(m_pHandle)
      {

         return m_pHandle;

      }

      auto cstrName = this->name();

      auto pHandle = ::dlopen(cstrName, RTLD_NOW);

      if(::is_null(pHandle))
      {

         __android_log_print(
            ANDROID_LOG_ERROR,
            cstrName,
            "dlopen failed: %s", dlerror());

         throw ::error_resource;

      }

      m_pHandle = pHandle;

      return m_pHandle;

   }


   template < typename PFN >
   PFN main_function(const_char_pointer p)
   {

      return this->function<PFN >(this->main_name(p));

   }


};



extern ::particle_pointer g_pmutexOs;


void android_aura_main();


bool g_bAuraStart = false;


void os_on_finish_launching();


int SetMainScreenRect(const ::int_rectangle & rect);


void set_jni_context(JNIEnv * penv);


const_char_pointer this_argv[] =
   {
      "app",
      nullptr
   };



extern "C"
JNIEXPORT void JNICALL Java_platform_platform_platform_application_jni_1on_1aura_1message_1box_1response(
   JNIEnv * penv, jobject obj,
   jlong jlMicromessagebox, jlong
   jlResponse)
{

   set_jni_context(penv);

   auto pmessagebox = ::pointer_transfer((::message_box *) (::iptr) jlMicromessagebox);

   pmessagebox->
      m_payloadResult = (enum_dialog_result) jlResponse;

   pmessagebox->

      on_sequence();

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_platform_application_jni_1aura_1is_1started(JNIEnv * env,
                                                                                   jobject obj)
{

   return
      g_bAuraStart;

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_platform_application_jni_1sync_1mem_1free_1available(
   JNIEnv * env, jobject obj)
{

   try {

      set_jni_context(env);

      ::platform::application_sink::get()->
         m_lMemFreeAvailableKb = ::jni_bind::get()->getMemFreeAvailableKb();

   }
   catch (...) {

      __android_log_write(ANDROID_LOG_WARN,
                          "com.ace.ace(native)", "sync_mem_free_available exception");

   }

}




extern "C"
JNIEXPORT void JNICALL Java_platform_platform_platform_application_jni_1create_1system(JNIEnv * penv,
                                                                            jclass clazz,
                                                                            jstring jstrAppId
)
{

// Attention!!
// When this function starts, platform::system doesn't exist yet.

   ::c::string cstrAppId;

   {

      const_char_pointer arg = penv->GetStringUTFChars(jstrAppId, NULL);

      if (arg == NULL)
      {

         return;

      }

      __android_log_print(ANDROID_LOG_INFO,
                          "MyApp", "Got string from Java: %s", arg);

      cstrAppId = arg;

      penv->
         ReleaseStringUTFChars(jstrAppId, arg
      );

   }

   c_application_namespace_library library(cstrAppId);

   auto pfnCreateSystem = library.main_function< PFN_CREATE_SYSTEM > ("create_system");

   pfnCreateSystem();

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_platform_application_jni_1initialize_1system(
   JNIEnv * penv,
   jobject obj,
   jobject jobjectBind,
   jobject jobjectMessageSink,
   jobject jobjectMessageSinkMediaStore,
   jobject jobjectAssetManager)
{

   set_jni_context(penv);

   if (::jni_bind::get())
   {

      delete ::jni_bind::get();

   }

   bool bApplicationSinkCreated = false;

   if (!::platform::application_sink::get()) {

      auto papplicationsink = ___new android::application_sink();

      papplicationsink->initialize(nullptr);

      ::platform::application_sink::set(papplicationsink);

      bApplicationSinkCreated = true;

   }

   auto pbind = øjni<::jni_bind>(jobjectBind);

   ::jni_bind::set(pbind);

   if (bApplicationSinkCreated)
   {

      auto pbind = ::jni_bind::get();

      ::cast<::android::application_sink> papplicationsink = ::platform::application_sink::get();

      papplicationsink->m_strApplicationIdentifier = pbind->getApplicationIdentifier();

      papplicationsink->m_strCommandLineParameters = pbind->getCommandLineParameters();

      papplicationsink->m_pathCacheDirectory = pbind->getCacheDirectory();

      papplicationsink->m_bShowKeyboard = false;

      auto pmessagesink = øjni<::jni_message_sink>(jobjectMessageSink);

      papplicationsink->m_pmessagesink = pmessagesink;

      auto pmessagesinkMediaStore = øjni<::jni_message_sink>(jobjectMessageSinkMediaStore);

      papplicationsink->m_pmessagesinkMediaStore = pmessagesinkMediaStore;

      auto passetmanager = øjni<::android::asset_manager>(jobjectAssetManager);

      papplicationsink->m_passetmanager = passetmanager;

      auto passet = papplicationsink->m_passetmanager->get_asset("_matter.zip");

      papplicationsink->m_passetResourceFolder = passet;

      const_char_pointer pResourceStart = nullptr;

      const_char_pointer pResourceEnd = nullptr;

      papplicationsink->m_passetResourceFolder->get_pointers(
         pResourceStart,
         pResourceEnd
      );

      c_application_namespace_library library(papplicationsink->m_strApplicationIdentifier.c_str());

      auto pfnInitializeSystem = library.main_function<PFN_INITIALIZE_SYSTEM>("initialize_system");

      pfnInitializeSystem(0, nullptr, nullptr, pResourceStart, pResourceEnd);

   }

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_message_message_1sender_jni_1on_1message(
   JNIEnv * penv,
   jobject obj,
   jobject jobjectMessage)
{

   try
   {

      set_jni_context(penv);

      jni_message message(øjni_object(jobjectMessage));

      auto pmessage = message.as_message();

      auto psystem = ::system();

      auto papplication = psystem->m_papplication;

      papplication->on_application_message(pmessage);

   }
   catch(...)
   {

   }

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_platform_application_jni_1return_1read_1data_1block(
   JNIEnv * penv,
   jobject obj,
   jobject jobjectDataBlock)
{

   try
   {

      set_jni_context(penv);

      jni_data_block jnidatablock(øjni_object(jobjectDataBlock));

      ::pointer < ::data::block > pdatablock
      {
         transfer_t{},
         (::data::block *)(void *)(::uptr) jnidatablock.getDataBlock()
      };

      jni_local_byte_array jnilocalbytea(jnidatablock.getData());

      pdatablock->m_memory = ::transfer(jnilocalbytea.as_memory());

      if(pdatablock->m_pmanualresethappening)
      {

         pdatablock->m_pmanualresethappening->set_happening();

      }

   }
   catch(...)
   {


   }

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_platform_application_jni_1application_1main(JNIEnv * penv,
                                                                               jobject obj)
{

   try
   {

      set_jni_context(penv);

      auto pbind = ::jni_bind::get();

      ::cast<::android::application_sink> papplicationsink = ::platform::application_sink::get();

      papplicationsink->m_iWidth = pbind->getWidth();

      papplicationsink->m_iHeight = pbind->getHeight();

      papplicationsink->m_fDpiX = pbind->getDpiX();

      papplicationsink->m_fDpiY = pbind->getDpiY();

      papplicationsink->m_fDensity = pbind->getDensity();

      auto strAppId = papplicationsink->m_strApplicationIdentifier;

      c_application_namespace_library library(strAppId.c_str());

      auto pfnMain = library.main_function<PFN_MAIN>("main");

      int iExitCode = pfnMain();

      ::information("application main exited (already?!?)");

   }
   catch(...)
   {

      ::error("application main exited with exception");

   }

}


extern "C"
JNIEXPORT void JNICALL
Java_platform_platform_platform_application_jni_1on_1media_1store_1output_1operation_1ready(JNIEnv * env, jobject obj, jlong lCallback)
{

   set_jni_context(env);

   ::pointer < ::data::block > pdatablock
   {
      transfer_t{},
      (::data::block *)(void *)(::uptr) lCallback
   };

   if(pdatablock->m_pmanualresethappening)
   {

      pdatablock->m_pmanualresethappening->set_happening();

   }

}

extern "C"
JNIEXPORT void JNICALL
Java_platform_platform_platform_application_jni_1on_1media_1store_1input_1operation_1ready(JNIEnv * env, jobject obj, jlong lCallback, jbyteArray jbytea)
{

   set_jni_context(env);

   ::pointer < ::data::block > pdatablock
      {
         transfer_t{},
         (::data::block *)(void *)(::uptr) lCallback
      };

   if(jbytea)
   {

      jni_local_byte_array jnilocalbytea(jbytea);

      pdatablock->m_memory = ::transfer(jnilocalbytea.as_memory());

   }

   if(pdatablock->m_pmanualresethappening)
   {

      pdatablock->m_pmanualresethappening->set_happening();

   }

}


extern "C"
JNIEXPORT jboolean JNICALL
Java_platform_platform_platform_application_application_1is_1started(JNIEnv * env, jobject obj)
{

   return g_bAuraStart;

}



