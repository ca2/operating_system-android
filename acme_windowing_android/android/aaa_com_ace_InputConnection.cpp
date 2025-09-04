#include "framework.h"
#include "_internal.h"
#include "aura/user/user/interaction.h"


::user::interaction* __get_host_interaction();


void input_connection_synchronize_selection(::user::element* pelementFocus);


#define LOG_PREFIX "TextInput"


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_user_InputConnection_jniBeginBatchEdit(JNIEnv * env, jobject  obj, jboolean bSuper)
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

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "jniBeginBatchEdit-(%d-%d)", bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniBeginBatchEdit(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniBeginBatchEdit(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniBeginBatchEdit(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_user_InputConnection_jniEndBatchEdit(JNIEnv * env, jobject  obj, jboolean bSuper)
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

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "jniEndBatchEdit-(%d-%d)", bSuper, bReturn);

            //::pointer<::user::plain_edit>pedit = pelementFocus;

            //if (pedit && pedit->m_iInputConnectionBatch == 0)
            //{

            //   input_connection_synchronize_selection(pelementFocus);

            //}

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniEndBatchEdit(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniEndBatchEdit(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniEndBatchEdit(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_user_InputConnection_jniCommitText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition, jboolean bSuper)
{

   bool bReturn = true;

   try
   {

      set_jni_context(env);

      const ::wd16_character* utf16 = (::wd16_character*)env->GetStringChars(text, NULL);

      if (utf16 == NULL)
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniCommitText(Null Text)");

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

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "jniCommitText(\"%s\", %d)-(%d-%d)", pszCommittingText, newCursorPosition, bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniCommitText(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniCommitText(NullInteraction)");

      }

      env->ReleaseStringChars(text, (jchar*)utf16);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniCommitText(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_user_InputConnection_jniDeleteSurroundingText(JNIEnv * env, jobject  obj, jint beforeLength, jint afterLength, jboolean bSuper)
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

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "jniDeleteSurroundingText(%d, %d)-(%d-%d)", beforeLength, afterLength, bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniDeleteSurroundingText(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniDeleteSurroundingText(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniDeleteSurroundingText(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_user_InputConnection_jniSetComposingText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition, jboolean bSuper)
{

   bool bReturn = true;

   try
   {

      set_jni_context(env);

      const ::wd16_character* utf16 = (::wd16_character*)env->GetStringChars(text, NULL);

      if (utf16 == NULL)
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetComposingText(Null Text)");

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

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "jniSetComposingText(\"%s\", %d)-(%d-%d)", pszComposingText, newCursorPosition, bSuper, bReturn);

            //input_connection_synchronize_selection(pelementFocus);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetCompositingText(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetCompositingText(NullInteraction)");

      }

      env->ReleaseStringChars(text, (jchar*)utf16);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetCompositingText(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_user_InputConnection_jniSetComposingRegion(JNIEnv * env, jobject obj, jint start, jint end, jboolean bSuper)
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

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "jniSetComposingRegion(%d, %d)-(%d-%d)", start, end, bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetCompositingRegion(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetCompositingRegion(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetCompositingRegion(Exception)");

   }

   return bReturn;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_user_InputConnection_jniSetSelection(JNIEnv * env, jobject obj, jint start, jint end, jboolean bSuper)
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

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "jniSetSelection(%d, %d)-(%d-%d)", start, end, bSuper, bReturn);
jni
         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetSelection(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetSelection(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniSetSelection(Exception)");

   }

   return bReturn;

}


// This behaves like calling setComposingText(text, newCursorPosition) then finishComposingText().
extern "C"
JNIEXPORT jboolean JNICALL Java_platform_platform_user_InputConnection_jniFinishComposingText(JNIEnv * env, jobject  obj, jboolean bSuper)
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

            __android_log_print(ANDROID_LOG_INFO, LOG_PREFIX, "jniFinishComposingText-(%d-%d)", bSuper, bReturn);

         }
         else
         {

            __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniFinishComposingText(NullFocus)");

         }

      }
      else
      {

         __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniFinishComposingText(NullInteraction)");

      }

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, LOG_PREFIX, "jniFinishComposingText(Exception)");

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
