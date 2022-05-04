#include "framework.h"
#include "_operating_system.h"
#include <android/bitmap.h>


#define LOG_TAG "com.ace.impact(native)"


void set_jni_context(JNIEnv * penv);


extern class ::system* g_psystem;


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_render_1impact(JNIEnv * env, jobject  obj, jobject bitmap, jlong  time_ms, jobject result)
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

   color32_t * pixels = nullptr;

   if ((ret = AndroidBitmap_lockPixels(env, bitmap, (void **)&pixels)) < 0)
   {

      LOGE("AndroidBitmap_lockPixels() failed ! error=%d", ret);

   }

   try
   {

      auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

      //auto puserinteraction = pwindowApplicationHost->m_puserinteractionimpl->m_puserinteraction;

      auto puserinteractionimpl = pwindowApplicationHost->m_puserinteractionimpl;

      puserinteractionimpl->android_fill_plasma(pixels, info.width, info.height, info.stride, time_ms);

      //android_fill_plasma(&info, pixels, time_ms);

   }
   catch (...)
   {

      LOGE("exception at g_android_fill_plasma");

   }

   AndroidBitmap_unlockPixels(env, bitmap);

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_native_1on_1timer(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

   try
   {

      android_exchange();

   }
   catch (...)
   {

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_keyDown(JNIEnv * env, jobject  obj, jint keyCode)
{

   set_jni_context(env);

   LOGI("%s\n", "Java_com_ace_impact_keyDown");

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_keyUp(JNIEnv * env, jobject  obj, jint keyCode)
{

   set_jni_context(env);

   LOGI("%s\n", "Java_com_ace_impact_keyUp");

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_keyPreImeDown(JNIEnv * env, jobject  obj, jint keyCode, jint iUni)
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


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_keyPreImeUp(JNIEnv * env, jobject  obj, jint keyCode, jint iUni)
{

   set_jni_context(env);

   try
   {

      android_key(e_message_key_up, keyCode, iUni);

   }
   catch (...)
   {

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_onReceivedShowKeyboard(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_onReceivedHideKeyboard(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_lButtonDown(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   set_jni_context(env);

   try
   {

      auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

      auto puserinteractionimpl = pwindowApplicationHost;

      pwindowApplicationHost->on_touch_down(x, y);

   }
   catch (...)
   {

   }

}


extern class ::system * g_psystem;


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionBeginBatchEdit(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

   auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

   auto pprimitiveFocus = pwindowApplicationHost->m_puserinteractionimpl->m_puserinteraction->get_keyboard_focus();

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

   return true;


}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionEndBatchEdit(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

   auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

   auto pprimitiveFocus = pwindowApplicationHost->m_puserinteractionimpl->m_puserinteraction->get_keyboard_focus();

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
   else
   {

      //android_on_text(os_text_keyboard, utf16, length);

   }

   return true;


}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionSetComposingText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition)
{

   set_jni_context(env);

   const wd16char * utf16 = (wd16char *)env->GetStringChars(text, NULL);

   if (utf16 == NULL)
   {

      return false;

   }

   size_t length = (size_t)env->GetStringLength(text);

   auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

   auto pprimitiveFocus = pwindowApplicationHost->m_puserinteractionimpl->m_puserinteraction->get_keyboard_focus();

   if (pprimitiveFocus)
   {

      wd16string wstr(utf16, length);

      string str(wstr);

      const char * pszComposingText = str;

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

   env->ReleaseStringChars(text, (jchar *)utf16);

   return true;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionSetComposingRegion(JNIEnv * env, jobject obj, jint start, jint end)
{

   set_jni_context(env);

   auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

   auto pprimitiveFocus = pwindowApplicationHost->m_puserinteractionimpl->m_puserinteraction->get_keyboard_focus();

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

   return true;

}

extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionSetSelection(JNIEnv * env, jobject obj, jint start, jint end)
{

   set_jni_context(env);

   auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

   auto pprimitiveFocus = pwindowApplicationHost->m_puserinteractionimpl->m_puserinteraction->get_keyboard_focus();

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

   return true;

}


// This behaves like calling setComposingText(text, newCursorPosition) then finishComposingText().

extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionCommitText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition)
{

   set_jni_context(env);

   const wd16char * utf16 = (wd16char *)env->GetStringChars(text, NULL);

   if (utf16 == NULL)
   {

      return false;

   }

   size_t length = (size_t)env->GetStringLength(text);

   auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

   auto pprimitiveFocus = pwindowApplicationHost->m_puserinteractionimpl->m_puserinteraction->get_keyboard_focus();

   if (pprimitiveFocus)
   {

      wd16string wstr(utf16, length);

      string str(wstr);

      const char * pszComposingText = str;

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

   env->ReleaseStringChars(text, (jchar *)utf16);

   return true;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_impact_InputConnectionFinishComposingText(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

   auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

   auto pprimitiveFocus = pwindowApplicationHost->m_puserinteractionimpl->m_puserinteraction->get_keyboard_focus();

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

   return true;

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_mouseMove(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   set_jni_context(env);

   try
   {

      auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

      auto puserinteractionimpl = pwindowApplicationHost;

      pwindowApplicationHost->on_touch_drag(x, y);

   }
   catch (...)
   {

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_lButtonUp(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   set_jni_context(env);

   try
   {

      auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

      auto puserinteractionimpl = pwindowApplicationHost;

      pwindowApplicationHost->on_touch_up(x, y);

   }
   catch (...)
   {

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_onText(JNIEnv * env, jobject  obj, jstring bytes)
{

   set_jni_context(env);

   if (bytes == NULL)
   {

      return;

   }

   const wchar_t * utf16 = (wchar_t *)env->GetStringChars(bytes, NULL);

   if (utf16 == NULL)
   {

      return;

   }

   size_t length = (size_t)env->GetStringLength(bytes);

   try
   {

      auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

      auto puserinteractionimpl = pwindowApplicationHost;

      pwindowApplicationHost->on_text(utf16, length);
      //      android_on_text(os_text_keyboard, utf16, length);

   }
   catch (...)
   {

   }

   env->ReleaseStringChars(bytes, (jchar *)utf16);

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_impact_aura_1size_1changed(JNIEnv * env, jobject  obj)
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

   try
   {

      auto pwindowApplicationHost = g_psystem->m_paurasystem->m_paurasession->m_puser->m_pwindowing->get_application_host_window();

      auto puserinteractionimpl = pwindowApplicationHost;

      pwindowApplicationHost->on_size(w, h);
      //      android_on_text(os_text_keyboard, utf16, length);

   }
   catch (...)
   {

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



