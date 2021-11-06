#include "activity.h"




#define  LOG_TAG    "app.activity (impact.cpp)"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


void start(int iScreenWidth, int iScreenHeight, const ::string & pszCommandLine, const ::string & pszCacheDir);



typedef int32_t  Fixed;


extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_renderImpact(JNIEnv * env, jobject  obj, jobject bitmap, jlong  time_ms, jobject result)
{


   AndroidBitmapInfo  info;
   void*              pixels;
   int                ret;
   //static Stats       stats;
   static int         init;

   if (!init)
   {
      init = 1;
      start(g_iScreenW, g_iScreenH, g_pszCommandLine, g_pszCacheDir);
      //init_tables();
      //stats_init(&stats);
   }

   if ((ret = AndroidBitmap_getInfo(env, bitmap, &info)) < 0) {
      LOGE("AndroidBitmap_getInfo() failed ! error=%d", ret);
      return;
   }

   if (info.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
      LOGE("Bitmap format is not RGB_565 !");
      return;
   }

   if ((ret = AndroidBitmap_lockPixels(env, bitmap, &pixels)) < 0) {
      LOGE("AndroidBitmap_lockPixels() failed ! error=%d", ret);
   }

   //stats_startFrame(&stats);

   /* Now fill the values with a nice little plasma */
   try
   {

      g_android_fill_plasma(&info, pixels, time_ms);

   }
   catch (...)
   {

      LOGE("exception at g_android_fill_plasma");

   }

   AndroidBitmap_unlockPixels(env, bitmap);

   //stats_endFrame(&stats);

   if(g_nodedataexchange.m_bShowKeyboard)
   {

      jfieldID fid;

      jmethodID mid;

      jclass myclass;

      jclass cls = env->GetObjectClass(result);

      fid = env->GetFieldID(cls,"m_bShowKeyboard","Z");

      env->SetBooleanField(result,fid,g_nodedataexchange.m_bShowKeyboard);

      g_nodedataexchange.m_bShowKeyboard = false;

   }

   if(g_nodedataexchange.m_bHideKeyboard)
   {

      jfieldID fid;

      jmethodID mid;

      jclass myclass;

      jclass cls = env->GetObjectClass(result);

      fid = env->GetFieldID(cls,"m_bHideKeyboard","Z");

      LOGI("%s\n", "Java_com_ca2_view_renderImpact g_nodedataexchange.m_bHideKeyboard : true");

      env->SetBooleanField(result,fid,g_nodedataexchange.m_bHideKeyboard);

      g_nodedataexchange.m_bHideKeyboard = false;

   }

   if(g_nodedataexchange.m_pszOpenUrl != NULL)
   {

      jfieldID fid;

      jmethodID mid;

      jclass myclass;

      jclass cls = env->GetObjectClass(result);

      fid = env->GetFieldID(cls,"m_strOpenUrl","Ljava/lang/String;");

      if (fid != NULL)
      {

         // String
         // Get the object given the Field ID
         //jstring message = (*env)->GetObjectField(env,result,fid);
         jstring message = env->NewStringUTF(g_nodedataexchange.m_pszOpenUrl);
         if (NULL == message) return;

         // modify the instance variables
         env->SetObjectField(result, fid, message);


         free((void *)g_nodedataexchange.m_pszOpenUrl);

      }

      g_nodedataexchange.m_pszOpenUrl = NULL;

   }
   
   if (g_nodedataexchange.m_bMessageBoxOn)
   {

      jfieldID fid;

      jmethodID mid;

      jclass myclass;

      jclass cls = env->GetObjectClass(result);

      fid = env->GetFieldID(cls, "m_iMessageBoxResult", "I");

      if (fid != NULL)
      {
         
         g_nodedataexchange.m_iMessageBoxResult = env->GetIntField(result, fid);

         if (g_nodedataexchange.m_iMessageBoxResult > 0)
         {

            g_nodedataexchange.m_bMessageBoxOn = false;

         }

      }

   }
   else
   {

      if (g_nodedataexchange.m_bMessageBox)
      {

         if (g_nodedataexchange.m_pszMessageBox != nullptr)
         {

            jfieldID fid;

            jmethodID mid;

            jclass myclass;

            jclass cls = env->GetObjectClass(result);

            fid = env->GetFieldID(cls, "m_strMessageBox", "Ljava/lang/String;");

            if (fid != NULL)
            {

               // String
               // Get the object given the Field ID
               //jstring message = (*env)->GetObjectField(env,result,fid);
               jstring message = env->NewStringUTF(g_nodedataexchange.m_pszMessageBox);
               if (NULL == message) return;

               // modify the instance variables
               env->SetObjectField(result, fid, message);


               free((void *)g_nodedataexchange.m_pszMessageBox);

            }

            g_nodedataexchange.m_pszMessageBox = NULL;

         }

         if (g_nodedataexchange.m_pszMessageBoxCaption != nullptr)
         {

            jfieldID fid;

            jmethodID mid;

            jclass myclass;

            jclass cls = env->GetObjectClass(result);

            fid = env->GetFieldID(cls, "m_strMessageBoxCaption", "Ljava/lang/String;");

            if (fid != NULL)
            {

               // String
               // Get the object given the Field ID
               //jstring message = (*env)->GetObjectField(env,result,fid);
               jstring message = env->NewStringUTF(g_nodedataexchange.m_pszMessageBoxCaption);
               if (NULL == message) return;

               // modify the instance variables
               env->SetObjectField(result, fid, message);


               free((void *)g_nodedataexchange.m_pszMessageBoxCaption);

            }

            g_nodedataexchange.m_pszMessageBoxCaption = NULL;

         }

         jfieldID fid;

         jmethodID mid;

         jclass myclass;

         jclass cls = env->GetObjectClass(result);

         fid = env->GetFieldID(cls, "m_iMessageBoxButton", "I");

         env->SetIntField(result, fid, g_nodedataexchange.m_iMessageBoxButton);

         g_nodedataexchange.m_iMessageBoxButton = 0;

         //jfieldID fid;

         //jmethodID mid;

         //jclass myclass;

         //jclass cls = env->GetObjectClass(result);

         fid = env->GetFieldID(cls, "m_iMessageBoxButton", "I");

         env->SetIntField(result, fid, g_nodedataexchange.m_iMessageBoxButton);

         g_nodedataexchange.m_bMessageBoxOn = true;

         g_nodedataexchange.m_bMessageBox = false;

      }

   }

   if (g_nodedataexchange.m_pszUserWallpaper != NULL)
   {

      jfieldID fid;

      jmethodID mid;

      jclass myclass;

      jclass cls = env->GetObjectClass(result);

      fid = env->GetFieldID(cls, "m_strWallpaper", "Ljava/lang/String;");

      if (fid != NULL)
      {

         // String
         // Get the object given the Field ID
         //jstring message = (*env)->GetObjectField(env,result,fid);
         jstring message = env->NewStringUTF(g_nodedataexchange.m_pszUserWallpaper);
         if (NULL == message) return;

         // modify the instance variables
         env->SetObjectField(result, fid, message);


         free((void *)g_nodedataexchange.m_pszUserWallpaper);

      }

      g_nodedataexchange.m_pszUserWallpaper = NULL;

   }

}

extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_keyDown(JNIEnv * env, jobject  obj, jint keyCode)
{

   LOGI("%s\n", "Java_com_ca2_view_keyDown");

}

extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_keyUp(JNIEnv * env, jobject  obj, jint keyCode)
{

   LOGI("%s\n", "Java_com_ca2_view_keyUp");

}

extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_keyPreImeDown(JNIEnv * env, jobject  obj, jint keyCode, jint iUni)
{

   //LOGI("%s\n", "Java_com_ca2_view_keyPreImeDown");

   key_down(keyCode, iUni);

}

extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_keyPreImeUp(JNIEnv * env, jobject  obj, jint keyCode, jint iUni)
{

   LOGI("%s\n", "Java_com_ca2_view_keyPreImeUp");

   key_up(keyCode, iUni);

}

extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_onReceivedShowKeyboard(JNIEnv * env, jobject  obj)
{

   LOGI("%s\n", "Java_com_view_onReceivedShowKeyboard");

}


extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_onReceivedHideKeyboard(JNIEnv * env,jobject  obj)
{

   LOGI("%s\n","Java_com_view_onReceivedHideKeyboard");

}

extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_lButtonDown(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   LOGI("%s\n","Java_com_ca2_view_lButtonDown");

   l_button_down(x, y);

}


extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_mouseMove(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   mouse_move(x, y);

}


extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_lButtonUp(JNIEnv * env, jobject  obj, jfloat x, jfloat y)
{

   LOGI("%s\n","Java_com_ca2_view_lButtonUp");

   l_button_up(x, y);

}


extern "C"
JNIEXPORT void JNICALL Java_com_ca2_view_onText(JNIEnv * env,jobject  obj,jstring bytes)
{

   LOGI("%s\n","Java_com_ca2_view_onText");

   if(bytes == NULL)
      return;

   const wchar_t * utf16 = (wchar_t *)env->GetStringChars(bytes,NULL);

   if(utf16 == NULL)
      return;

   size_t length = (size_t)env->GetStringLength(bytes);

   on_text(utf16,length);

   env->ReleaseStringChars(bytes,(jchar *)utf16);

}


