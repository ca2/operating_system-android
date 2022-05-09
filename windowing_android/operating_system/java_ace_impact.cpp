#include "framework.h"
#include "_operating_system.h"
#include <android/bitmap.h>


#define LOG_TAG "ace.impact(native)"


void set_jni_context(JNIEnv* penv);


extern class ::system* g_psystem;


::windowing::window* __get_host_window()
{

   auto psystem = g_psystem;

   if (::is_set(psystem))
   {

      auto paurasystem = psystem->m_paurasystem;

      if (::is_set(paurasystem))
      {

         auto paurasession = psystem->m_paurasession;

         if (::is_set(paurasession))
         {

            auto puser = paurasession->m_puser;

            if (::is_set(puser))
            {

               auto pwindowing = puser->m_pwindowing;

               if (::is_set(pwindowing))
               {

                  auto pwindowApplicationHost = pwindowing->get_application_host_window();

                  if (::is_set(pwindowApplicationHost))
                  {

                     return pwindowApplicationHost;

                  }

               }

            }

         }

      }

   }

   return nullptr;

}


::user::interaction_impl* __get_host_user_impl()
{

   auto pwindowApplicationHost = __get_host_window();

   if (::is_set(pwindowApplicationHost))
   {

      return pwindowApplicationHost->m_puserinteractionimpl;

   }

   return nullptr;

}


::user::interaction* __get_host_interaction()
{

   auto pimpl = __get_host_user_impl();

   if (::is_set(pimpl))
   {

      return pimpl->m_puserinteraction;

   }

   return nullptr;

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_render_1impact(JNIEnv * env, jobject  obj, jobject bitmap, jlong  time_ms, jobject result)
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

         auto puserinteractionimpl = __get_host_user_impl();

         if (::is_set(puserinteractionimpl))
         {

            ::duration duration;

            duration.Now();

            puserinteractionimpl->android_fill_plasma(pixels, info.width, info.height, info.stride, time_ms);

            LOGE("render_impact: %lld ms duration=%f ms", time_ms, duration.elapsed().floating_millisecond().m_d);

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
JNIEXPORT void JNICALL Java_com_ace_impact_native_1on_1timer(JNIEnv * env, jobject  obj)
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


   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "native_on_timer exception");

   }


}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_keyDown(JNIEnv * env, jobject  obj, jint keyCode)
{

   try
   {

      set_jni_context(env);

      LOGI("%s\n", "Java_com_ace_impact_keyDown");


   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "keyDown exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_keyUp(JNIEnv * env, jobject  obj, jint keyCode)
{
   try
   {


      set_jni_context(env);

      LOGI("%s\n", "Java_com_ace_impact_keyUp");


   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "keyUp exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_keyPreImeDown(JNIEnv * env, jobject  obj, jint keyCode, jint iUni)
{
   try
   {

      set_jni_context(env);

      try
      {

         android_key(e_message_key_down, keyCode, iUni);

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
JNIEXPORT void JNICALL Java_com_ace_impact_keyPreImeUp(JNIEnv * env, jobject  obj, jint keyCode, jint iUni)
{

   try
   {

      set_jni_context(env);

      android_key(e_message_key_up, keyCode, iUni);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "keyPreImeUp exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_onReceivedShowKeyboard(JNIEnv * env, jobject  obj)
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
JNIEXPORT void JNICALL Java_com_ace_impact_onReceivedHideKeyboard(JNIEnv * env, jobject  obj)
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


extern class ::system* g_psystem;


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionBeginBatchEdit(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

   try
   {

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pprimitiveFocus = pinteraction->get_keyboard_focus();

         if (pprimitiveFocus)
         {

            try
            {

               pprimitiveFocus->InputConnectionBeginBatchEdit();

            }
            catch (...)
            {

            }

         }
         else
         {

            //android_on_text(os_text_keyboard, utf16, length);

         }

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "InputConnectionBeginBatchEdit exception");

   }

   return true;


}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionEndBatchEdit(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

   try
   {

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pprimitiveFocus = pinteraction->get_keyboard_focus();

         if (pprimitiveFocus)
         {

            try
            {

               pprimitiveFocus->InputConnectionEndBatchEdit();

            }
            catch (...)
            {

            }

         }

      }
      else
      {

         //android_on_text(os_text_keyboard, utf16, length);

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "InputConnectionEndBatchEdit exception");

   }


   return true;


}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionSetComposingText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition)
{

   try
   {

      set_jni_context(env);

      const wd16char* utf16 = (wd16char*)env->GetStringChars(text, NULL);

      if (utf16 == NULL)
      {

         return false;

      }

      size_t length = (size_t)env->GetStringLength(text);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pprimitiveFocus = pinteraction->get_keyboard_focus();

         if (pprimitiveFocus)
         {

            wd16string wstr(utf16, length);

            string str(wstr);

            const char* pszComposingText = str;

            try
            {

               pprimitiveFocus->InputConnectionSetComposingText(str, newCursorPosition);

            }
            catch (...)
            {

            }

         }
         else
         {

            //android_on_text(os_text_keyboard, utf16, length);

         }

      }

      env->ReleaseStringChars(text, (jchar*)utf16);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "InputConnectionSetComposingText exception");

   }


   return true;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionSetComposingRegion(JNIEnv * env, jobject obj, jint start, jint end)
{

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pprimitiveFocus = pinteraction->get_keyboard_focus();

         if (pprimitiveFocus)
         {

            try
            {

               pprimitiveFocus->InputConnectionSetComposingRegion(start, end);

            }
            catch (...)
            {

            }

         }
         else
         {

            //android_on_text(os_text_keyboard, utf16, length);

         }

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "InputConnectionSetComposingRegion exception");

   }


   return true;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionSetSelection(JNIEnv * env, jobject obj, jint start, jint end)
{

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pprimitiveFocus = pinteraction->get_keyboard_focus();

         if (pprimitiveFocus)
         {


            try
            {

               pprimitiveFocus->InputConnectionSetSelection(start, end);

            }
            catch (...)
            {

            }

         }
         else
         {

            //android_on_text(os_text_keyboard, utf16, length);

         }

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "InputConnectionSetSelection exception");

   }


   return true;

}


// This behaves like calling setComposingText(text, newCursorPosition) then finishComposingText().

extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionCommitText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition)
{

   try
   {

      set_jni_context(env);

      const wd16char* utf16 = (wd16char*)env->GetStringChars(text, NULL);

      if (utf16 == NULL)
      {

         return false;

      }

      size_t length = (size_t)env->GetStringLength(text);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pprimitiveFocus = pinteraction->get_keyboard_focus();

         if (pprimitiveFocus)
         {


            wd16string wstr(utf16, length);

            string str(wstr);

            const char* pszComposingText = str;

            try
            {

               pprimitiveFocus->InputConnectionCommitText(str, newCursorPosition);

            }
            catch (...)
            {

            }

         }
         else
         {

            //android_on_text(os_text_keyboard, utf16, length);

         }

      }

      env->ReleaseStringChars(text, (jchar*)utf16);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "InputConnectionCommitText exception");

   }


   return true;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionFinishComposingText(JNIEnv * env, jobject  obj)
{

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pprimitiveFocus = pinteraction->get_keyboard_focus();

         if (pprimitiveFocus)
         {


            try
            {

               pprimitiveFocus->InputConnectionFinishComposingText();

            }
            catch (...)
            {

            }

         }
         else
         {

            //android_on_text(os_text_keyboard, utf16, length);

         }

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "InputConnectionFinishComposingText exception");

   }


   return true;

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_mouseMove(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   try
   {

      set_jni_context(env);

      auto pwindowApplicationHost = __get_host_window();

      if (::is_set(pwindowApplicationHost))
      {

         pwindowApplicationHost->on_touch_drag(x, y);

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "mouseMove exception");

   }


}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_lButtonDown(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   try
   {

      set_jni_context(env);

      auto pwindowHost = __get_host_window();

      if (::is_set(pwindowHost))
      {

         pwindowHost->on_touch_down(x, y);

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "lButtonDown exception");

   }


}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_lButtonUp(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   try
   {

      set_jni_context(env);

      auto pwindowApplicationHost = __get_host_window();

      if (::is_set(pwindowApplicationHost))
      {

         pwindowApplicationHost->on_touch_up(x, y);

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "lButtonUp exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_onText(JNIEnv * env, jobject  obj, jstring bytes)
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


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_aura_1size_1changed(JNIEnv * env, jobject  obj)
{


   try
   {

      set_jni_context(env);

      //::rectangle_i32 rectangle;

      //rectangle.left = 0;
      //rectangle.top = 0;
      //rectangle.right = ::operating_system_direct::get()->getWidth();
      //rectangle.bottom = ::operating_system_direct::get()->getHeight();

      auto w = ::operating_system_direct::get()->getWidth();
      auto h = ::operating_system_direct::get()->getHeight();

      //android_on_size(0, 0, w, h);

      //try
   //   {

      auto pwindowApplicationHost = __get_host_window();

      if (::is_set(pwindowApplicationHost))
      {

         pwindowApplicationHost->on_size(w, h);

      }
      //      android_on_text(os_text_keyboard, utf16, length);



   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "aura_size_changed exception");

   }


   //try
   //{

      //g_psystem->m_paurasystem->m_puser->(rectangle);

   //}
   //catch (...)
   //{

   //}

   //auto pimpl = puserinteraction->m_pimpl.cast < ::user::interaction_impl >();

   //if (pimpl)
   //{

   //   pimpl->m_pprodevian->prodevian_update_buffer(true);

   //   //operating_system_driver::get()->m_bRedraw = true;

   //}

   //auto puserinteractionpointeraChild = puserinteraction->m_puserinteractionpointeraChild;

   //if (puserinteractionpointeraChild)
   //{

   //   for (auto & puserinteractionChild : puserinteractionpointeraChild->interactiona())
   //   {

   //      try
   //      {

   //         puserinteractionChild->send_message(e_message_display_change);

   //         //__pointer(::user::interaction_impl) pimpl = puserinteraction->m_pimpl;

   //         //if (pimpl)
   //         //{

   //         //   pimpl->m_puserthread->do_events();

   //         //   pimpl->m_pprodevian->do_events();

   //         //   pimpl->m_puserthread->do_events();

   //         //   pimpl->m_pprodevian->do_events();

   //         //   pimpl->m_puserthread->do_events();

   //         //   pimpl->m_pprodevian->do_events();

   //         //}

   //      }
   //      catch (...)
   //      {

   //      }

   //   }

   //}

}



