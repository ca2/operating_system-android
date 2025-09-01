#include "framework.h"
#include "display.h"
#include "acme/constant/message.h"
#include "acme/platform/acme.h"
#include "acme/platform/system.h"
#include "aura/user/user/user.h"
#include "aura/platform/session.h"
//#include "aura/user/user/interaction_impl.h"
#include "aura/windowing/window.h"
#include "aura/windowing/windowing.h"
#include "acme_windowing_android/android/_internal.h"
#include <android/log.h>
#include <android/bitmap.h>
#include "aura/windowing/monitor.h"


#define LOG_TAG "ace.impact(native)"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


void set_jni_context(JNIEnv* penv);


::windowing::window* __get_host_window()
{

   auto psystem = ::system();

   if (::is_set(psystem))
   {

      ::cast < ::windowing::windowing > pwindowing = psystem->windowing();

      if (::is_set(pwindowing))
      {

         ::cast < ::windowing::window > pwindowApplicationHost = pwindowing->get_application_host_window();

         if (::is_set(pwindowApplicationHost))
         {

            return pwindowApplicationHost;

         }

      }

   }

   return nullptr;

}


//::windowing::window* __get_host_user_impl()
//{
//
//   auto pwindowApplicationHost = __get_host_window();
//
//   if (::is_set(pwindowApplicationHost))
//   {
//
//      return pwindowApplicationHost->m_pwindow;
//
//   }
//
//   return nullptr;
//
//}


::user::interaction* __get_host_interaction()
{

   auto pwindow = __get_host_window();

   if (::is_set(pwindow))
   {

      ::cast < ::user::interaction > puserinteraction = pwindow->m_pacmeuserinteraction;

      if(puserinteraction)
      {

         return puserinteraction;

      }

   }

   return nullptr;

}


extern "C"
//JNIEXPORT void JNICALL Java_platform_platform_impact_render_1impact(JNIEnv * env, jobject  obj, jobject bitmap, jlong  time_ms, jobject result)
JNIEXPORT void JNICALL Java_platform_platform_impact_render_1impact(JNIEnv * env, jobject  obj, jobject bitmap, jlong  time_ms)
{

   try
   {

      set_jni_context(env);

      AndroidBitmapInfo    info = {};

      int                  ret;

      if ((ret = AndroidBitmap_getInfo(env, bitmap, &info)) < 0)
      {

         LOGE("AndroidBitmap_getInfo() failed ! error=%d", ret);

         return;

      }

      if (info.format != ANDROID_BITMAP_FORMAT_RGBA_8888)
      {

         LOGE("Bitmap format is not RGB_565 !");

         return;

      }

      color32_t* pixels = nullptr;

      if ((ret = AndroidBitmap_lockPixels(env, bitmap, (void**)&pixels)) < 0)
      {

         LOGE("AndroidBitmap_lockPixels() failed ! error=%d", ret);

      }

      try
      {

         auto pwindow = __get_host_window();

         if (::is_set(pwindow))
         {

            class ::time time;

            time.Now();

            pwindow->android_fill_plasma(pixels, info.width, info.height, info.stride, time_ms);

            LOGE("render_impact: %ld ms time=%f ms", time_ms, time.elapsed().floating_millisecond());

         }

         //android_fill_plasma(&info, pixels, time_ms);

      }
      catch (...)
      {

         LOGE("exception at g_android_fill_plasma");

      }

      AndroidBitmap_unlockPixels(env, bitmap);

   }
   catch (...)
   {

      LOGW("render_impact exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_native_1on_1timer(JNIEnv * env, jobject  obj)
{

   try
   {

      set_jni_context(env);

      try
      {

         //LOGI("native_on_timer");

         android_exchange();

      }
      catch (...)
      {

      }


//      try {
//
//         auto psystem = system();
//
//         if (psystem)
//         {
//
//            if (psystem->m_pacmewindowing)
//            {
//
//               auto pwindowing = system()->windowing();
//
//               auto pdisplay = pwindowing->display();
//
//               if(pdisplay) {
//
//                  auto pmonitor = psystem->øcreate_new<::windowing::monitor>();
//
//                  pmonitor->m_pdisplay = pdisplay;
//
//                  auto pbind = ::jni_bind::get();
//
//                  int w = pbind->getWidth();
//
//                  int h = pbind->getHeight();
//
//                  ::int_rectangle r(0, 0, w, h);
//
//                  pmonitor->
//                     m_rectangle = r;
//                  pmonitor->
//                     m_rectangleFixedWorkspace = r;
//                  pmonitor->
//                     m_rectangleWorkspace = r;
//
//                  pdisplay->m_monitora.set_at_grow(0, pmonitor);
//
//               }
//
//            }
//
//
//         }
//
//      }
//      catch(...)
//      {
//
//
//      }
//
   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "native_on_timer exception");

   }


}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_keyDown(JNIEnv * env, jobject  obj, jint keyCode)
{

   try
   {

      set_jni_context(env);

      LOGI("%s\n", "Java_platform_platform_impact_keyDown");


   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "keyDown exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_keyUp(JNIEnv * env, jobject  obj, jint keyCode)
{
   try
   {


      set_jni_context(env);

      LOGI("%s\n", "Java_platform_platform_impact_keyUp");


   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "keyUp exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_keyPreImeDown(JNIEnv * env, jobject  obj, jint keyCode, jint iUni)
{
   try
   {

      set_jni_context(env);

      try
      {

         android_key(::user::e_message_key_down, keyCode, iUni);

      }
      catch (...)
      {

      }



   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "keyPreImeDown");

   }


}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_keyPreImeUp(JNIEnv * env, jobject  obj, jint keyCode, jint iUni)
{

   try
   {

      set_jni_context(env);

      android_key(::user::e_message_key_up, keyCode, iUni);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "keyPreImeUp exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_onReceivedShowKeyboard(JNIEnv * env, jobject  obj)
{

   try
   {

      set_jni_context(env);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "onReceivedShowKeyboard exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_onReceivedHideKeyboard(JNIEnv * env, jobject  obj)
{

   try
   {

      set_jni_context(env);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "onReceivedShowKeyboard exception");

   }

}




extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_mouseMove(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   try
   {

      set_jni_context(env);

      auto pwindowApplicationHost = __get_host_window();

      if (::is_set(pwindowApplicationHost))
      {

         pwindowApplicationHost->on_touch_drag(x, y, x, y);

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "mouseMove exception");

   }


}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_lButtonDown(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   try
   {

      set_jni_context(env);

      auto pwindowHost = __get_host_window();

      if (::is_set(pwindowHost))
      {

         pwindowHost->on_touch_down(x, y, x, y);

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "lButtonDown exception");

   }


}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_lButtonUp(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   try
   {

      set_jni_context(env);

      auto pwindowApplicationHost = __get_host_window();

      if (::is_set(pwindowApplicationHost))
      {

         pwindowApplicationHost->on_touch_up(x, y, x, y);

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "lButtonUp exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_platform_platform_impact_onText(JNIEnv * env, jobject  obj, jstring bytes)
{

   try
   {
      set_jni_context(env);

      if (bytes == NULL)
      {

         return;

      }

      const wchar_t* utf16 = (wchar_t*)env->GetStringChars(bytes, NULL);

      if (utf16 == NULL)
      {

         return;

      }

      size_t length = (size_t)env->GetStringLength(bytes);

      try
      {

         auto pwindowApplicationHost = __get_host_window();

         if (::is_set(pwindowApplicationHost))
         {

            pwindowApplicationHost->on_text(utf16, length);

         }

         //      android_on_text(os_text_keyboard, utf16, length);

      }
      catch (...)
      {

      }

      env->ReleaseStringChars(bytes, (jchar*)utf16);



   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "onText exception");

   }


}


//extern "C"
//JNIEXPORT void JNICALL Java_platform_platform_impact_aura_1size_1changed(JNIEnv * env, jobject  obj)
//{
//
//
//   try
//   {
//
//      set_jni_context(env);
//
//      //::int_rectangle rectangle;
//
//      //rectangle.left() = 0;
//      //rectangle.top() = 0;
//      //rectangle.right() = ::jni_bind::get()->getWidth();
//      //rectangle.bottom() = ::jni_bind::get()->getHeight();
//
//      auto w = ::jni_bind::get()->getWidth();
//      auto h = ::jni_bind::get()->getHeight();
//
//      //android_on_size(0, 0, w, h);
//
//      //try
//   //   {
//
//      auto pwindowApplicationHost = __get_host_window();
//
//      if (::is_set(pwindowApplicationHost))
//      {
//
//         pwindowApplicationHost->on_size(w, h);
//
//      }
//      //      android_on_text(os_text_keyboard, utf16, length);
//
//
//
//   }
//   catch (...)
//   {
//
//      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "aura_size_changed exception");
//
//   }
//
//
//   //try
//   //{
//
//      //g_psystem->m_puser->(rectangle);
//
//   //}
//   //catch (...)
//   //{
//
//   //}
//
//   //auto pimpl = puserinteraction->m_pimpl.cast < ::windowing::window >();
//
//   //if (pimpl)
//   //{
//
//   //   pimpl->m_pprodevian->prodevian_update_buffer(true);
//
//   //   //operating_system_driver::get()->m_bRedraw = true;
//
//   //}
//
//   //auto puserinteractionpointeraChild = puserinteraction->m_puserinteractionpointeraChild;
//
//   //if (puserinteractionpointeraChild)
//   //{
//
//   //   for (auto & puserinteractionChild : puserinteractionpointeraChild->interactiona())
//   //   {
//
//   //      try
//   //      {
//
//   //         puserinteractionChild->send_message(::user::e_message_display_change);
//
//   //         //::pointer<::windowing::window>pimpl = puserinteraction->m_pimpl;
//
//   //         //if (pimpl)
//   //         //{
//
//   //         //   pimpl->m_puserthread->do_events();
//
//   //         //   pimpl->m_pprodevian->do_events();
//
//   //         //   pimpl->m_puserthread->do_events();
//
//   //         //   pimpl->m_pprodevian->do_events();
//
//   //         //   pimpl->m_puserthread->do_events();
//
//   //         //   pimpl->m_pprodevian->do_events();
//
//   //         //}
//
//   //      }
//   //      catch (...)
//   //      {
//
//   //      }
//
//   //   }
//
//   //}
//
//}



