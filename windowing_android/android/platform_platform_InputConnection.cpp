#include "framework.h"
#include "acme_windowing_android/android/_internal.h"
#include "aura/user/user/interaction.h"


::user::interaction* __get_host_interaction();


void input_connection_synchronize_selection(::user::element* pelementFocus);


#define LOG_PREFIX "TextInput"


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_InputConnection_BeginBatchEdit(JNIEnv * env, jobject  obj, jboolean bSuper)
{

   bool bReturn = true;

   set_jni_context(env);

   try
   {

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {

            bReturn = pelementFocus->InputConnectionBeginBatchEdit(bSuper);

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "BeginBatchEdit-(%d-%d)", bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "BeginBatchEdit(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "BeginBatchEdit(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "BeginBatchEdit(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_InputConnection_EndBatchEdit(JNIEnv * env, jobject  obj, jboolean bSuper)
{

   bool bReturn = true;

   set_jni_context(env);

   try
   {

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (::is_set(pelementFocus))
         {

            bReturn = pelementFocus->InputConnectionEndBatchEdit(bSuper);

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "EndBatchEdit-(%d-%d)", bSuper, bReturn);

            //::pointer<::user::plain_edit>pedit = pelementFocus;

            //if (pedit && pedit->m_iInputConnectionBatch == 0)
            //{

            //   input_connection_synchronize_selection(pelementFocus);

            //}

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "EndBatchEdit(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "EndBatchEdit(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "EndBatchEdit(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_InputConnection_CommitText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition, jboolean bSuper)
{

   bool bReturn = true;

   try
   {

      set_jni_context(env);

      const ::wd16_character* utf16 = (::wd16_character*)env->GetStringChars(text, NULL);

      if (utf16 == NULL)
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "CommitText(Null Text)");

         return false;

      }

      size_t length = (size_t)env->GetStringLength(text);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {

            wd16_string wstr(utf16, length);

            string str(wstr);

            const_char_pointer pszCommittingText = str;

            bReturn = pelementFocus->InputConnectionCommitText(str, newCursorPosition, bSuper);

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "CommitText(\"%s\", %d)-(%d-%d)", pszCommittingText, newCursorPosition, bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "CommitText(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "CommitText(NullInteraction)");

      }

      env->ReleaseStringChars(text, (jchar*)utf16);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "CommitText(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_InputConnection_DeleteSurroundingText(JNIEnv * env, jobject  obj, jint beforeLength, jint afterLength, jboolean bSuper)
{

   bool bReturn = true;

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (::is_set(pelementFocus))
         {

            bReturn = pelementFocus->InputConnectionDeleteSurroundingText(beforeLength, afterLength, bSuper);

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "DeleteSurroundingText(%d, %d)-(%d-%d)", beforeLength, afterLength, bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "DeleteSurroundingText(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "DeleteSurroundingText(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "DeleteSurroundingText(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_InputConnection_SetComposingText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition, jboolean bSuper)
{

   bool bReturn = true;

   try
   {

      set_jni_context(env);

      const ::wd16_character* utf16 = (::wd16_character*)env->GetStringChars(text, NULL);

      if (utf16 == NULL)
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetComposingText(Null Text)");

         return false;

      }

      size_t length = (size_t)env->GetStringLength(text);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {

            wd16_string wstr(utf16, length);

            string str(wstr);

            const_char_pointer pszComposingText = str;

            bReturn = pelementFocus->InputConnectionSetComposingText(str, newCursorPosition, bSuper);

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "SetComposingText(\"%s\", %d)-(%d-%d)", pszComposingText, newCursorPosition, bSuper, bReturn);

            //input_connection_synchronize_selection(pelementFocus);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetCompositingText(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetCompositingText(NullInteraction)");

      }

      env->ReleaseStringChars(text, (jchar*)utf16);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetCompositingText(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_InputConnection_SetComposingRegion(JNIEnv * env, jobject obj, jint start, jint end, jboolean bSuper)
{

   bool bReturn = true;

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {

            bReturn = pelementFocus->InputConnectionSetComposingRegion(start, end, bSuper);

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "SetComposingRegion(%d, %d)-(%d-%d)", start, end, bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetCompositingRegion(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetCompositingRegion(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetCompositingRegion(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_InputConnection_SetSelection(JNIEnv * env, jobject obj, jint start, jint end, jboolean bSuper)
{

   bool bReturn = true;

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (::is_set(pelementFocus))
         {

            bReturn = pelementFocus->InputConnectionSetSelection(start, end, bSuper);

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "SetSelection(%d, %d)-(%d-%d)", start, end, bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetSelection(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetSelection(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "SetSelection(Exception)");

   }

   return bReturn;

}


// This behaves like calling setComposingText(text, newCursorPosition) then finishComposingText().
extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_InputConnection_FinishComposingText(JNIEnv * env, jobject  obj, jboolean bSuper)
{

   bool bReturn = true;

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (::is_set(pelementFocus))
         {

            bReturn = pelementFocus->InputConnectionFinishComposingText(bSuper);

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "FinishComposingText-(%d-%d)", bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "FinishComposingText(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "FinishComposingText(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "FinishComposingText(Exception)");

   }

   return bReturn;

}

//
//void input_connection_synchronize_selection(::user::element* pelementFocus)
//{
//
//   try
//   {
//
//      pelementFocus->queue_selection_synchronization();
//
//   }
//   catch (...)
//   {
//
//   }
//
//}
//
//
//
