#include "framework.h"
#include "_android.h"


::user::interaction* __get_host_interaction();


void input_connection_synchronize_selection(::user::element* pelementFocus);


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_InputConnection_BeginBatchEdit(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

   try
   {

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {

            try
            {

               pelementFocus->InputConnectionBeginBatchEdit();

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
JNIEXPORT jboolean JNICALL Java_com_ace_InputConnection_EndBatchEdit(JNIEnv * env, jobject  obj)
{

   set_jni_context(env);

   try
   {

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {

            try
            {

               pelementFocus->InputConnectionEndBatchEdit();

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
JNIEXPORT jboolean JNICALL Java_com_ace_InputConnection_CommitText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition)
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

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {


            wd16string wstr(utf16, length);

            string str(wstr);

            const char* pszCommittingText = str;

            try
            {

               pelementFocus->InputConnectionCommitText(str, newCursorPosition);

            }
            catch (...)
            {

            }

            input_connection_synchronize_selection(pelementFocus);

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
JNIEXPORT jboolean JNICALL Java_com_ace_InputConnection_DeleteSurroundingText(JNIEnv * env, jobject  obj, jint beforeLength, jint afterLength)
{

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {

            try
            {

               pelementFocus->InputConnectionDeleteSurroundingText(beforeLength, afterLength);

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

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "InputConnectionSetComposingText exception");

   }


   return true;

}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_ace_InputConnection_SetComposingText(JNIEnv * env, jobject  obj, jstring text, jint newCursorPosition)
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

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {

            wd16string wstr(utf16, length);

            string str(wstr);

            const char* pszComposingText = str;

            try
            {

               pelementFocus->InputConnectionSetComposingText(str, newCursorPosition);

            }
            catch (...)
            {

            }

            input_connection_synchronize_selection(pelementFocus);

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
JNIEXPORT jboolean JNICALL Java_com_ace_InputConnection_SetComposingRegion(JNIEnv * env, jobject obj, jint start, jint end)
{

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {

            try
            {

               pelementFocus->InputConnectionSetComposingRegion(start, end);

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
JNIEXPORT jboolean JNICALL Java_com_ace_InputConnection_SetSelection(JNIEnv * env, jobject obj, jint start, jint end)
{

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {


            try
            {

               pelementFocus->InputConnectionSetSelection(start, end);

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
JNIEXPORT jboolean JNICALL Java_com_ace_InputConnection_FinishComposingText(JNIEnv * env, jobject  obj)
{

   try
   {

      set_jni_context(env);

      auto pinteraction = __get_host_interaction();

      if (::is_set(pinteraction))
      {

         auto pelementFocus = pinteraction->get_keyboard_focus();

         if (pelementFocus)
         {


            try
            {

               pelementFocus->InputConnectionFinishComposingText();

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


void input_connection_synchronize_selection(::user::element* pelementFocus)
{

   try
   {

      strsize iSelectionStart = 0;

      strsize iSelectionEnd = 0;

      strsize iComposingStart = 0;

      strsize iComposingEnd = 0;

      pelementFocus->_001GetSel(iSelectionStart, iSelectionEnd, iComposingStart, iComposingEnd);

      auto pdirect = ::operating_system_bind::get();

      pdirect->setInputMethodManagerSelectionStart(iSelectionStart);

      pdirect->setInputMethodManagerSelectionEnd(iSelectionEnd);

      pdirect->setInputMethodManagerCandidateStart(iComposingStart);

      pdirect->setInputMethodManagerCandidateEnd(iComposingEnd);

   }
   catch (...)
   {

   }

}



