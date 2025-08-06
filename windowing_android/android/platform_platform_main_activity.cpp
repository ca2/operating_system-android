#include "framework.h"
#include "application_state.h"
#include "acme_windowing_android/android/_internal.h"
#include "acme_windowing_android/android/android_asset_manager.h"
#include "acme_windowing_android/android/android_asset.h"
#include "acme/inline/application/main.h"
//#include "acme/user/nano/_nano.h"
#include "acme/platform/acme.h"
#include "acme/platform/node.h"
//#include "acme/platform/sequencer.h"
#include "acme/platform/application.h"
#include "acme/platform/system.h"
#include "acme/platform/system_setup.h"
#include "acme/prototype/string/c_string.h"
#include "acme_windowing_android/android/android_asset_manager.h"
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
JNIEXPORT void JNICALL Java_platform_platform_main_1activity_on_1aura_1message_1box_1response(
   JNIEnv * penv, jobject obj,
   jlong jlMicromessagebox, jlong
   jlResponse)
{

   auto pmessagebox = ::pointer_transfer((::message_box *) (::iptr) jlMicromessagebox);

   pmessagebox->
      m_payloadResult = (enum_dialog_result) jlResponse;

   pmessagebox->

      on_sequence();

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_main_1activity_aura_1is_1started(JNIEnv * env,
                                                                                   jobject obj)
{

   return
      g_bAuraStart;

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_main_1activity_sync_1mem_1free_1available(
   JNIEnv * env, jobject obj)
{

   try {

      set_jni_context(env);

      ::platform::application_state::get()->
         m_lMemFreeAvailableKb = ::operating_system_bind::get()->getMemFreeAvailableKb();

   }
   catch (...) {

      __android_log_write(ANDROID_LOG_WARN,
                          "com.ace.ace(native)", "sync_mem_free_available exception");

   }

}




extern "C"
JNIEXPORT void JNICALL Java_platform_platform_main_1activity_create_1system(JNIEnv * penv,
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
JNIEXPORT void JNICALL Java_platform_platform_main_1activity_initialize_1system(JNIEnv * penv,
                                                                                jobject obj,
                                                                                jobject jobjectBind,
                                                                                jobject
                                                                                jobjectAssetManager)
{

   set_jni_context(penv);

   if (::operating_system_bind::get()) {

      delete ::operating_system_bind::get();

   }

   auto pbind = __øjni<::operating_system_bind>(jobjectBind);

   ::operating_system_bind::set(pbind);

   if (!::platform::application_state::get())
{

::platform::application_state::set (___new

android::application_state()

);

auto pbind = ::operating_system_bind::get();

::cast<::android::application_state> papplicationstate = ::platform::application_state::get();

papplicationstate->
m_strApplicationIdentifier = pbind->getApplicationIdentifier();

papplicationstate->
m_strCommandLineParameters = pbind->getCommandLineParameters();

papplicationstate->
m_pathCacheDirectory = pbind->getCacheDirectory();


papplicationstate->
m_bShowKeyboard = false;

auto passetmanager = __øjni<::android::asset_manager>(jobjectAssetManager);

papplicationstate->
m_passetmanager = passetmanager;

papplicationstate->
m_passetResourceFolder = papplicationstate->m_passetmanager->get_asset("_matter.zip");

const_char_pointer pResourceStart = nullptr;
const_char_pointer pResourceEnd = nullptr;

papplicationstate->m_passetResourceFolder->
get_pointers(
   pResourceStart,
   pResourceEnd
);

c_application_namespace_library library(papplicationstate->
   m_strApplicationIdentifier.c_str());

auto pfnInitializeSystem = library.main_function<PFN_INITIALIZE_SYSTEM>("initialize_system");

pfnInitializeSystem(0, nullptr, nullptr, pResourceStart, pResourceEnd);

}

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_main_1activity_application_1main(JNIEnv * penv,
                                                                               jobject obj)
{

try
{

set_jni_context(penv);

auto pbind = ::operating_system_bind::get();

::cast<::android::application_state> papplicationstate = ::platform::application_state::get();


papplicationstate->
m_iWidth = pbind->getWidth();

papplicationstate->
m_iHeight = pbind->getHeight();

papplicationstate->
m_fDpiX = pbind->getDpiX();

papplicationstate->
m_fDpiY = pbind->getDpiY();

papplicationstate->
m_fDensity = pbind->getDensity();

auto strAppId = papplicationstate->m_strApplicationIdentifier;

c_application_namespace_library library(strAppId.c_str());


auto pfnMain = library.main_function<PFN_MAIN>("main");

int iExitCode = pfnMain();

}
catch(...)
{

}

}



extern "C"
JNIEXPORT jboolean JNICALL
Java_platform_platform_main_1activity_application_1is_1started(JNIEnv * env, jobject obj)
{

   return g_bAuraStart;

}



