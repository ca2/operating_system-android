#include "framework.h"
#include "_operating_system.h"
#include "_asset_manager.h"
#include "_asset.h"


extern ::mutex * g_pmutexOs;


void android_aura_main();


bool g_bAuraStart = false;


void os_on_finish_launching();


int SetMainScreenRect(const RECTANGLE_I32* lpcrect);


void set_jni_context(JNIEnv * penv);


extern class ::system * g_psystem;


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_ace_aura_1is_1started(JNIEnv * env, jobject obj)
{
   
   return g_bAuraStart;

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_ace_aura_1init(JNIEnv * penv, jobject obj, jobject jobjectDirect, jobject jobjectAssetManager)
{

   try
   {

      set_jni_context(penv);

      if (!g_pmutexOs)
      {

         g_pmutexOs = new mutex();

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

         pdriver->m_passetResourceFolder->get_pointers(
            papp->m_pchar_binary__matter_zip_start,
            papp->m_pchar_binary__matter_zip_end);

         //if (m_psystem->m_pchar_binary__matter_zip_start && m_psystem->m_pchar_binary__matter_zip_end)

      //   g_psystem->m_pathCacheDirectory = pdriver->m_pathCacheDirectory;

         papp->m_bConsole = false;

         int iExitCode = papp->main_loop();

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
JNIEXPORT void JNICALL Java_com_ace_ace_aura_1start(JNIEnv * penv, jobject obj)
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
JNIEXPORT void JNICALL Java_com_ace_ace_on_1aura_1message_1box_1response(JNIEnv * penv, jobject obj, jlong jlMicromessagebox, jlong jlResponse)
{

   auto psequence = ::move_transfer((::sequence < ::conversation> *)(::iptr) jlMicromessagebox);

   auto & sequence = *psequence;

   sequence->m_atomResult = (enum_dialog_result) jlResponse;

   psequence->on_sequence();

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_ace_sync_1mem_1free_1available(JNIEnv * env, jobject obj, jobject os)
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



