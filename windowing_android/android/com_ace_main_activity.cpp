#include "framework.h"
#include "_internal.h"
#include "_asset_manager.h"
#include "_asset.h"
//#include "acme/user/nano/_nano.h"
#include "acme/platform/acme.h"
#include "acme/platform/node.h"
#include "acme/platform/sequencer.h"
#include "acme/platform/system.h"
#include "acme/platform/system_setup.h"
#include "acme/user/nano/nano.h"
//typedef void(*PFN_factory)(::factory::factory* pfactory);

typedef int(*PFN_MAIN)(int argc, char * argv[], char * envp[], const char * p1, const char * p2);

extern ::pointer < ::particle > g_pmutexOs;


void android_aura_main();


bool g_bAuraStart = false;


void os_on_finish_launching();


int SetMainScreenRect(const ::rectangle_i32 &rect);


void set_jni_context(JNIEnv * penv);


const char * this_argv[] =
{
   "app",
   nullptr
};


class main_os_thread :
   virtual public ::particle
{
public:


   pthread_t         m_pthread;
   PFN_MAIN          m_pfnMain;
   char ** m_ppszArg;
   const char * m_pszResourceStart;
   const char * m_pszResourceEnd;
   ::e_status        m_estatus;


   main_os_thread(PFN_MAIN pfnMain, char ** ppszArg, const char * pszResourceStart, const char * pszResourceEnd)
   {

      m_pfnMain = pfnMain;
      m_ppszArg = ppszArg;
      m_pszResourceStart = pszResourceStart;
      m_pszResourceEnd = pszResourceEnd;

   }


   void start()
   {

      pthread_attr_t taskAttr;

      pthread_attr_init(&taskAttr);

      pthread_attr_setdetachstate(&taskAttr, PTHREAD_CREATE_DETACHED); // Set task to detached state. No need for pthread_join

      pthread_create(&m_pthread, &taskAttr, &main_os_thread::s_run, (void *)this);

   }


   static void * s_run(void * ptr)
   {

      auto pmainosthread = (main_os_thread *)ptr;

      pmainosthread->run();

      return (void *)(iptr)pmainosthread->m_estatus.exit_code();

   }


   void run() override
   {

      try
      {

         m_estatus = ::success;

         m_pfnMain(1, (char **)m_ppszArg, nullptr, m_pszResourceStart, m_pszResourceEnd);

      }
      catch (const ::exception & exception)
      {

         string strMessage = exception.m_strMessage;

         string strDetails = exception.m_strDetails;

         auto psequencer = acmesystem()->nano()->message_box(
            "Failed to load library?",
            "Failed to Load Library?",
            e_message_box_ok);

         psequencer->do_asynchronously();

      }

   }

};


extern "C"
JNIEXPORT void JNICALL Java_com_ace_main_1activity_aura_1init(JNIEnv * penv, jobject obj, jobject jobjectDirect, jobject jobjectAssetManager)
{

   try
   {

      set_jni_context(penv);

      if (!g_pmutexOs)
      {

         g_pmutexOs = ::acme::acme::g_pacme->m_psubsystem->acmesystem()->acmenode()->create_mutex();

      }

      if (::operating_system_bind::get())
      {

         delete ::operating_system_bind::get();

      }

      ::operating_system_bind::set(new operating_system_bind(jobjectDirect));

      if (!::operating_system_driver::get())
      {

         ::operating_system_driver::set(new operating_system_driver());

         auto pdirect = ::operating_system_bind::get();

         auto pdriver = ::operating_system_driver::get();

         pdriver->m_strApplicationIdentifier = pdirect->getApplicationIdentifier();

         pdriver->m_strCommandLineParameters = pdirect->getCommandLineParameters();

         pdriver->m_pathCacheDirectory = pdirect->getCacheDirectory();

         pdriver->m_iWidth = pdirect->getWidth();

         pdriver->m_iHeight = pdirect->getHeight();

         pdriver->m_fDpiX = pdirect->getDpiX();

         pdriver->m_fDpiY = pdirect->getDpiY();

         pdriver->m_fDensity = pdirect->getDensity();

         pdriver->m_bShowKeyboard = false;

         pdriver->m_passetmanager = new asset_manager(jobjectAssetManager);

         pdriver->m_passetResourceFolder = pdriver->m_passetmanager->get_asset("_matter.zip");

         string strLibrary;

         //int main(int argc, char* argv[], char* envp[])

         strLibrary = pdriver->m_strApplicationIdentifier;

         strLibrary.find_replace("/", "_");

         strLibrary.find_replace("-", "_");

         string strMain;

         strMain = "android_main";

         strLibrary = "libimpl_" + strLibrary + ".so";

         auto pLibrary = dlopen(strLibrary, 0);

         PFN_MAIN pfnMain = (PFN_MAIN)dlsym(pLibrary, strMain);

         const char * pResourceStart = nullptr;
         const char * pResourceEnd = nullptr;
         //auto pfactory = __new(::factory::factory);
         pdriver->m_passetResourceFolder->get_pointers(
            pResourceStart,
            pResourceEnd);


         auto pmainosthread = __new(main_os_thread(
            pfnMain, (char **)this_argv, pResourceStart,
            pResourceEnd));


         pdriver->m_pparticleMainOsThread = pmainosthread;


         //pfnFactory(pfactory);
         //pfnMain(1, (char**)this_argv, nullptr, p1, p2);

         //auto papp = pfactory->create<::acme::application>();

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

         pmainosthread->start();

         //if (acmesystem()->m_pchar_binary__matter_zip_start && acmesystem()->m_pchar_binary__matter_zip_end)

      //   g_psystem->m_pathCacheDirectory = pdriver->m_pathCacheDirectory;

         //papp->m_bConsole = false;
      }
      else
      {

         auto pdirect = ::operating_system_bind::get();

         ::rectangle_i32 r;

         r.left = 0;

         r.top = 0;

         r.right = pdirect->getWidth();

         r.bottom = pdirect->getHeight();

         SetMainScreenRect(r);

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.ace(native)", "aura_init exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_main_1activity_aura_1start(JNIEnv * penv, jobject obj)
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

      __android_log_write(ANDROID_LOG_WARN, "com.ace.ace(native)", "aura_start exception");

   }


}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_main_1activity_on_1aura_1message_1box_1response(JNIEnv * penv, jobject obj, jlong jlMicromessagebox, jlong jlResponse)
{

   auto psequencer = ::pointer_transfer((::sequencer < ::conversation> *)(::iptr) jlMicromessagebox);

   psequencer->m_psequence->m_payloadResult = (enum_dialog_result)jlResponse;

   psequencer->on_sequence();

}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_main_1activity_aura_1is_1started(JNIEnv * env, jobject obj)
{

   return g_bAuraStart;

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_main_1activity_sync_1mem_1free_1available(JNIEnv * env, jobject obj)
{

   try
   {

      set_jni_context(env);

      ::operating_system_driver::get()->m_lMemFreeAvailableKb = ::operating_system_bind::get()->getMemFreeAvailableKb();

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.ace(native)", "sync_mem_free_available exception");

   }

}



