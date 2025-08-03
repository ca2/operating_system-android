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
#include "acme_windowing_android/android/android_asset_manager.h"
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


::string cpp_to_library_name(const ::scoped_string & scopedstr)
{

   ::string strLibraryName(scopedstr);

   strLibraryName.find_replace("/", "_");
   strLibraryName.find_replace("-", "_");

   return strLibraryName;

}


::string
cpp_application_library_main_name(const_char_pointer pszApplicationNamespace, const_char_pointer p)
{

   string str1(pszApplicationNamespace);
   string str2(p);

   return str1 + "_main_" + str2;

}

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

//
//class main_os_thread :
//   virtual public ::particle
//{
//public:
//
//
//   pthread_t         m_pthread;
//   PFN_MAIN          m_pfnMain;
//   char ** m_ppszArg;
//   const_char_pointer m_pszResourceStart;
//   const_char_pointer m_pszResourceEnd;
//   ::e_status        m_estatus;
//
//
//   main_os_thread(PFN_MAIN pfnMain, char ** ppszArg, const_char_pointer pszResourceStart, const_char_pointer pszResourceEnd)
//   {
//
//      m_pfnMain = pfnMain;
//      m_ppszArg = ppszArg;
//      m_pszResourceStart = pszResourceStart;
//      m_pszResourceEnd = pszResourceEnd;
//
//   }
//
//
//   void start()
//   {
//
//      pthread_attr_t taskAttr;
//
//      pthread_attr_init(&taskAttr);
//
//      pthread_attr_setdetachstate(&taskAttr, PTHREAD_CREATE_DETACHED); // Set task to detached state. No need for pthread_join
//
//      pthread_create(&m_pthread, &taskAttr, &main_os_thread::s_run, (void *)this);
//
//   }
//
//
//   static void * s_run(void * ptr)
//   {
//
//      auto pmainosthread = (main_os_thread *)ptr;
//
//      pmainosthread->run();
//
//      return (void *)(iptr)pmainosthread->m_estatus.exit_code();
//
//   }
//
//
//   void run() override
//   {
//
//      try
//      {
//
//         m_estatus = ::success;
//
//         m_pfnMain(1, (char **)m_ppszArg, nullptr, m_pszResourceStart, m_pszResourceEnd);
//
//      }
//      catch (const ::exception & exception)
//      {
//
//         string strMessage = exception.m_strMessage;
//
//         string strDetails = exception.m_strDetails;
//
//         auto pmessagebox = system()->message_box(
//            "Failed to load library?",
//            "Failed to Load Library?",
//            e_message_box_ok);
//
//         pmessagebox->async();
//
//      }
//
//   }
//
//};


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_main_1activity_application_1main(JNIEnv * penv,
                                                                               jobject obj)
{

try
{

set_jni_context(penv);


auto pbind = ::operating_system_bind::get();

::cast<::android::application_state> papplicationstate = ::platform::application_state::get();


string strLibrary;

//int main(int argc, char* argv[], char* envp[])

strLibrary = papplicationstate->m_strApplicationIdentifier;

strLibrary = cpp_to_library_name(strLibrary);

//papplicationstate->m_strApplicationIdentifier = pbind->getApplicationIdentifier();

///auto pszLibraryName = c_to_library_name(pszAppId);

auto strAppLibrary = "lib" + strLibrary + ".so";

//strcpy(pszAppLibrary, "lib");
//strcat(pszAppLibrary, pszLibraryName);
//strcat(pszAppLibrary, ".so");

// ---- Do something with 'arg' ----
// e.g., pass it to your C main loop

// When done, release it

void * handle = dlopen(strAppLibrary, RTLD_NOW);

if (!handle)
{

__android_log_print(ANDROID_LOG_ERROR,
"MyApp", "dlopen failed: %s",

dlerror()

);

return;

}

auto strCreateSystem = cpp_application_library_main_name(strLibrary, "create_system");

auto pfnCreateSystem = (PFN_CREATE_SYSTEM) dlsym(handle, strCreateSystem);

if (!pfnCreateSystem)
{

__android_log_print(ANDROID_LOG_ERROR,
"MyApp", "dlsym failed: %s",

dlerror()

);

dlclose(handle);

return;

}

pfnCreateSystem();


}
catch (...)
{

__android_log_write(ANDROID_LOG_WARN,
"com.ace.ace(native)", "aura_init exception");

}

}


//extern "C"
//JNIEXPORT void JNICALL Java_platform_platform_main_1activity_aura_1start(JNIEnv * penv, jobject obj)
//{
//
//   try
//   {
//
//      set_jni_context(penv);
//
//      if (g_bAuraStart)
//      {
//
//         return;
//
//      }
//
//      g_bAuraStart = true;
//
//      android_aura_main();
//
//   }
//   catch (...)
//   {
//
//      __android_log_write(ANDROID_LOG_WARN, "com.ace.ace(native)", "aura_start exception");
//
//   }
//
//
//}


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

try
{

set_jni_context(env);

::platform::application_state::get()->
m_lMemFreeAvailableKb = ::operating_system_bind::get()->getMemFreeAvailableKb();

}
catch (...)
{

__android_log_write(ANDROID_LOG_WARN,
"com.ace.ace(native)", "sync_mem_free_available exception");

}

}







//extern "C"
//JNIEXPORT void JNICALL Java_platform_platform_main_1activity_aura_1init(JNIEnv * penv, jobject obj, jobject jobjectDirect, jobject jobjectAssetManager)
//{
//
//try
//{
//
//set_jni_context(penv);
//
//if (!g_pmutexOs)
//{
//
//g_pmutexOs = ::system()->node()->create_mutex();
//
//}
//
//if (::operating_system_bind::get())
//{
//
//delete ::operating_system_bind::get();
//
//}
//
//::operating_system_bind::set(___new operating_system_bind(jobjectDirect));
//
//if (!::platform::application_state::get())
//{
//
//::platform::application_state::set(___new platform::application_state());
//
//auto pbind = ::operating_system_bind::get();
//
//auto papplicationstate = ::platform::application_state::get();
//
//papplicationstate->m_strApplicationIdentifier = pbind->getApplicationIdentifier();
//
//papplicationstate->m_strCommandLineParameters = pbind->getCommandLineParameters();
//
//papplicationstate->m_pathCacheDirectory = pbind->getCacheDirectory();
//
//papplicationstate->m_iWidth = pbind->getWidth();
//
//papplicationstate->m_iHeight = pbind->getHeight();
//
//papplicationstate->m_fDpiX = pbind->getDpiX();
//
//papplicationstate->m_fDpiY = pbind->getDpiY();
//
//papplicationstate->m_fDensity = pbind->getDensity();
//
//papplicationstate->m_bShowKeyboard = false;
//
//papplicationstate->m_passetmanager = ___new asset_manager(jobjectAssetManager);
//
//papplicationstate->m_passetResourceFolder = papplicationstate->m_passetmanager->get_asset("_matter.zip");
//
//string strLibrary;
//
////int main(int argc, char* argv[], char* envp[])
//
//strLibrary = papplicationstate->m_strApplicationIdentifier;
//
//strLibrary.find_replace("/", "_");
//
//strLibrary.find_replace("-", "_");
//
//string strMain;
//
//strMain = "android_main";
//
//strLibrary = "libimpl_" + strLibrary + ".so";
//
//auto pLibrary = dlopen(strLibrary, 0);
//
//PFN_MAIN pfnMain = (PFN_MAIN)dlsym(pLibrary, strMain);
//
//const_char_pointer pResourceStart = nullptr;
//const_char_pointer pResourceEnd = nullptr;
////auto pfactory = __allocate ::factory::factory();
//papplicationstate->m_passetResourceFolder->get_pointers(
//   pResourceStart,
//   pResourceEnd);
//
//
//auto pmainosthread = __initialize_new main_os_thread(
//   pfnMain, (char **)this_argv, pResourceStart,
//   pResourceEnd));
//
//
//papplicationstate->m_pparticleMainOsThread = pmainosthread;
//
//
////pfnFactory(pfactory);
////pfnMain(1, (char**)this_argv, nullptr, p1, p2);
//
////auto papp = pfactory->create<::platform::application>();
//
////auto papp = ::app_factory::new_app();
//
////papp->m_argc = __argc;
//
////papp->m_argv = __argv;
//
////papp->m_wargv = __wargv;
//
////papp->m_envp = *__p__environ();
//
////papp->m_wenvp = *__p__wenviron();
//
////papp->m_hinstanceThis = hinstanceThis;
//
////papp->m_hinstancePrev = hinstancePrev;
//
////papp->m_strCommandLine = ::GetCommandLineW();
//
////papp->m_nCmdShow = nCmdShow;
//
//pmainosthread->start();
//
////if (system()->m_pchar_binary__matter_zip_start && system()->m_pchar_binary__matter_zip_end)
//
////   g_psystem->m_pathCacheDirectory = papplicationstate->m_pathCacheDirectory;
//
////papp->m_bConsole = false;
//}
//else
//{
//
//auto pbind = ::operating_system_bind::get();
//
//::int_rectangle r;
//
//r.left() = 0;
//
//r.top() = 0;
//
//r.right() = pbind->getWidth();
//
//r.bottom() = pbind->getHeight();
//
//SetMainScreenRect(r);
//
//}
//
//}
//catch (...)
//{
//
//__android_log_write(ANDROID_LOG_WARN, "com.ace.ace(native)", "aura_init exception");
//
//}
//
//}

char *
c_application_library_main_name(const_char_pointer pszApplicationNamespace, const_char_pointer p)
{

   int iLen1 = strlen(pszApplicationNamespace);
   int iLen2 = strlen(p);

   auto pname = (char *) malloc(iLen1 + iLen2 + 256);

   strcpy(pname, pszApplicationNamespace);
   strcat(pname, "_main_");
   strcat(pname, p);

   return pname;

}

char * c_to_library_name(char * p)
{

   auto p2 = strdup(p);

   auto pos = p2;

   while (*pos)
   {

      if (*pos == '/')
      {

         *pos = '_';

      }
      else if (*pos == '-')
      {

         *pos = '_';

      }

      pos++;

   }

   return p2;

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_main_1activity_create_1system(JNIEnv * penv,
                                                                            jclass clazz,
jstring jstrAppId
)
{

// Attention!!
// When this function starts, platform::system doesn't exist yet.

char * pszAppId = nullptr;

{

// Convert Java string to C string
const_char_pointer arg = penv->GetStringUTFChars(jstrAppId, NULL);


if (arg == NULL)
{

// Out of memory
return;

}

__android_log_print(ANDROID_LOG_INFO,
"MyApp", "Got string from Java: %s", pszAppId);

pszAppId = strdup(arg);

penv->
ReleaseStringUTFChars(jstrAppId, arg
);

}

auto pszLibraryName = c_to_library_name(pszAppId);

auto pszAppLibrary = (char *) malloc(strlen(pszLibraryName) + 256);

strcpy(pszAppLibrary,
"lib");
strcat(pszAppLibrary, pszLibraryName
);
strcat(pszAppLibrary,
".so");

// ---- Do something with 'arg' ----
// e.g., pass it to your C main loop

// When done, release it

void * handle = dlopen(pszAppLibrary, RTLD_NOW);

if (!handle)
{

__android_log_print(ANDROID_LOG_ERROR,
"MyApp", "dlopen failed: %s",

dlerror()

);

return;

}

auto pszCreateSystem = c_application_library_main_name(pszLibraryName, "create_system");

auto pfnCreateSystem = (PFN_CREATE_SYSTEM) dlsym(handle, pszCreateSystem);

if (!pfnCreateSystem)
{

__android_log_print(ANDROID_LOG_ERROR,
"MyApp", "dlsym failed: %s",

dlerror()

);

dlclose(handle);

return;

}

pfnCreateSystem();

if(!::system())
{

__android_log_print(ANDROID_LOG_ERROR,
"MyApp", "system creation failed");

}


}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_main_1activity_initialize_1system(JNIEnv * penv,
                                                                                jobject obj,
jobject jobjectBind, jobject
jobjectAssetManager)
{


set_jni_context(penv);

if (::operating_system_bind::get())
{

delete ::operating_system_bind::get();

}

auto pbind = ___new operating_system_bind(jobjectBind);

::operating_system_bind::set (pbind);

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
m_iWidth = pbind->getWidth();

papplicationstate->
m_iHeight = pbind->getHeight();

papplicationstate->
m_fDpiX = pbind->getDpiX();

papplicationstate->
m_fDpiY = pbind->getDpiY();

papplicationstate->
m_fDensity = pbind->getDensity();

papplicationstate->
m_bShowKeyboard = false;

auto passetmanager = ___new ::android::asset_manager();

passetmanager->
set_AAssetManager(jobjectAssetManager);

papplicationstate->
m_passetmanager = passetmanager;

papplicationstate->
m_passetResourceFolder = papplicationstate->m_passetmanager->get_asset("_matter.zip");

//string strLibrary;
//
////int main(int argc, char* argv[], char* envp[])
//
//strLibrary = papplicationstate->m_strApplicationIdentifier;
//
//strLibrary = cpp_to_library_name(strLibrary);
//
//string strMain;
//
//strMain = "android_main";
//
//strLibrary = "libimpl_" + strLibrary + ".so";
//
//auto pLibrary = dlopen(strLibrary, 0);
//
//PFN_MAIN pfnMain = (PFN_MAIN) dlsym(pLibrary, strMain);

const_char_pointer pResourceStart = nullptr;
const_char_pointer pResourceEnd = nullptr;
//auto pfactory = __allocate ::factory::factory();
papplicationstate->m_passetResourceFolder->
get_pointers(
   pResourceStart,
   pResourceEnd
);


//auto pmainosthread = __initialize_new main_os_thread(
//   pfnMain, (char **)this_argv, pResourceStart,
//   pResourceEnd));
//
//
//papplicationstate->m_pparticleMainOsThread = pmainosthread;


//pfnFactory(pfactory);
//pfnMain(1, (char**)this_argv, nullptr, p1, p2);

//auto papp = pfactory->create<::platform::application>();

//auto papp = ::app_factory::new_app();

//papp->m_argc = __argc;

//papp->m_argv = __argv;

//papp->m_wargv = __wargv;

//papp->m_envp = *__p__environ();

//papp->m_wenvp = *__p__wenviron();

//papp->m_hinstanceThis = hinstanceThis;

//papp->m_hinstancePrev = hinstancePrev;

//papp->m_strCommandLine = ::GetCommandLineW();

//papp->m_nCmdShow = nCmdShow;

//pmainosthread->start();



//if (system()->m_pchar_binary__matter_zip_start && system()->m_pchar_binary__matter_zip_end)

//   g_psystem->m_pathCacheDirectory = papplicationstate->m_pathCacheDirectory;

//papp->m_bConsole = false;
}


}



extern "C"
JNIEXPORT void JNICALL Java_platform_platform_main_1activity_aura_1start(JNIEnv * penv, jobject obj)
{

try
{

set_jni_context(penv);

if (g_bAuraStart)
{

return;

}

g_bAuraStart = true;

android_aura_main();

}
catch (...)
{

__android_log_write(ANDROID_LOG_WARN,
"com.ace.ace(native)", "aura_start exception");

}


}


//extern "C"
//JNIEXPORT void JNICALL Java_platform_platform_main_1activity_on_1aura_1message_1box_1response(JNIEnv * penv, jobject obj, jlong jlMicromessagebox, jlong jlResponse)
//{
//
//auto psequencer = ::pointer_transfer((::sequencer < ::conversation> *)(::iptr) jlMicromessagebox);
//
//psequencer->m_psequence->m_payloadResult = (enum_dialog_result)jlResponse;
//
//psequencer->on_sequence();
//
//}

//
//extern "C"
//JNIEXPORT jboolean JNICALL Java_platform_platform_main_1activity_aura_1is_1started(JNIEnv * env, jobject obj)
//{
//
//return g_bAuraStart;
//
//}
//
//
//extern "C"
//JNIEXPORT void JNICALL Java_platform_platform_main_1activity_sync_1mem_1free_1available(JNIEnv * env, jobject obj)
//{
//
//try
//{
//
//set_jni_context(env);
//
//::platform::application_state::get()->m_lMemFreeAvailableKb = ::operating_system_bind::get()->getMemFreeAvailableKb();
//
//}
//catch (...)
//{
//
//__android_log_write(ANDROID_LOG_WARN, "com.ace.ace(native)", "sync_mem_free_available exception");
//
//}
//
//}
//


