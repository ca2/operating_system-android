#include "framework.h"
#include <jni.h>
#include "acme/operating_system/android/_os_object.h"
#include "acme/operating_system/android/_os_remote.h"
//#include "_os_impl.h"


extern ::mutex * g_pmutexOs;


void android_aura_main();


extern __pointer(::os_local) g_poslocal;


extern __pointer(::os_remote) g_posremote;


bool g_bAuraStart = false;


void os_on_finish_launching();


void set_jni_context(JNIEnv * penv);


extern "C"
JNIEXPORT jboolean JNICALL Java_com_android_1app_app_aura_1is_1started(JNIEnv * env, jobject obj)
{

   return g_bAuraStart;

}


extern "C"
JNIEXPORT void JNICALL Java_com_android_1app_app_aura_1init(JNIEnv * penv, jobject obj, jobject os)
{

   set_jni_context(penv);

   if (!g_pmutexOs)
   {

      g_pmutexOs = new mutex();

   }

   if (!g_poslocal)
   {

      g_poslocal = __new(os_local);

   }

   g_posremote = __new(os_remote(os));

   auto premote = g_posremote;

   auto plocal = g_poslocal;

   plocal->m_strApplicationIdentifier = premote->getApplicationIdentifier();

   plocal->m_strCommandLineParameters = premote->getCommandLineParameters();

   plocal->m_pathCacheDirectory = premote->getCacheDirectory();

   plocal->m_iWidth = premote->getWidth();

   plocal->m_iHeight = premote->getHeight();

   plocal->m_fDpiX = premote->getDpiX();

   plocal->m_fDpiY = premote->getDpiY();

   plocal->m_fDensity = premote->getDensity();

   plocal->m_bShowKeyboard = false;


}


extern "C"
JNIEXPORT void JNICALL Java_com_android_1app_app_aura_1start(JNIEnv * penv, jobject obj)
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
JNIEXPORT void JNICALL Java_com_android_1app_app_sync_1mem_1free_1available(JNIEnv * env, jobject obj, jobject os)
{

   set_jni_context(env);

   g_poslocal->m_lMemFreeAvailableKb = g_posremote->getMemFreeAvailableKb();

}



