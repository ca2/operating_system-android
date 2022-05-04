#include "framework.h"
#include "_operating_system.h"


extern ::mutex * g_pmutexOs;


void android_aura_main();


//extern __pointer(::operating_system_driver) g_pandroiddriver;
//
//
//extern __pointer(::operating_system_direct) g_pandroidcontext;


bool g_bAuraStart = false;


void os_on_finish_launching();


void set_jni_context(JNIEnv * penv);


extern class ::system * g_psystem;


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_ace_aura_1is_1started(JNIEnv * env, jobject obj)
{

   return g_bAuraStart;

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_ace_aura_1init(JNIEnv * penv, jobject obj, jobject os)
{

   set_jni_context(penv);

   if (!g_pmutexOs)
   {

      g_pmutexOs = new mutex();

   }

   if (!::operating_system_direct::get())
   {

      ::operating_system_direct::set(new operating_system_direct(obj));

   }

   if (!::operating_system_driver::get())
   {

      ::operating_system_driver::set(new operating_system_driver());

   }

   auto pdirect = ::operating_system_direct::get();

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

   ::app* papp = ::app::g_p;

   //papp->m_argc = __argc;

   //papp->m_argv = __argv;

   //papp->m_wargv = __wargv;

   //papp->m_envp = *__p__environ();

   //papp->m_wenvp = *__p__wenviron();

   //papp->m_hinstanceThis = hinstanceThis;

   //papp->m_hinstancePrev = hinstancePrev;

   //papp->m_strCommandLine = ::GetCommandLineW();

   //papp->m_nCmdShow = nCmdShow;

   papp->m_bConsole = false;

   int iExitCode = papp->main_loop();

   g_psystem->m_bIsReadyForUserInteraction = true;

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_ace_aura_1start(JNIEnv * penv, jobject obj)
{

   set_jni_context(penv);

   if (g_bAuraStart)
   {

      return;

   }

   g_bAuraStart = true;

   android_aura_main();

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_ace_sync_1mem_1free_1available(JNIEnv * env, jobject obj, jobject os)
{

   set_jni_context(env);

   ::operating_system_driver::get()->m_lMemFreeAvailableKb = ::operating_system_direct::get()->getMemFreeAvailableKb();

}



