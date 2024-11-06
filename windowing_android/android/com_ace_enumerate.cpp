// Created by camilo on 2022-05-28 02:55 <3ThomasBorregaardSorensen!! (ThomasLikesNumber5 and will raise ca-square?)
#include "framework.h"
#include "_internal.h"
#include "media_library.h"


extern "C"
JNIEXPORT void JNICALL Java_com_ace_enumerate_music_announce(JNIEnv * env, jobject obj, jlong id, jstring display_name, jstring full_path, jstring mime_type, jstring title, jstring artist)
{

   try
   {

      set_jni_context(env);

      huge_integer iId = id;

      ::string strDisplayName = ::as_string(display_name);

      ::string strFullPath = ::as_string(full_path);

      ::string strMimeType = ::as_string(mime_type);

      ::string strTitle = ::as_string(title);

      ::string strArtist = ::as_string(artist);

      auto pitem = __allocate ::android::audio_item(id, strTitle, strArtist);

      pitem->m_strDisplayName = strDisplayName;

      pitem->m_strFullPath = strFullPath;

      pitem->m_strMimeType = strMimeType;

      ::android::add_media_library_item(pitem);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.list_files(native)", "new_song exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_enumerate_image_announce(JNIEnv * env, jobject  obj, jlong  id, jstring display_name, jstring full_path, jstring mime_type, jstring title)
{

   try
   {

      set_jni_context(env);

      huge_integer iId = id;

      ::string strDisplayName = ::as_string(display_name);

      ::string strFullPath = ::as_string(full_path);

      ::string strMimeType = ::as_string(mime_type);

      ::string strTitle = ::as_string(title);

      auto pitem = __allocate ::android::images_item(id, strTitle);

      pitem->m_strDisplayName = strDisplayName;

      pitem->m_strFullPath = strFullPath;

      pitem->m_strMimeType = strMimeType;

      ::android::add_media_library_item(pitem);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.list_files(native)", "new_image exception");

   }

}


extern "C"
JNIEXPORT void JNICALL Java_com_ace_enumerate_video_announce(JNIEnv * env, jobject  obj, jlong  id, jstring display_name, jstring full_path, jstring mime_type, jstring title, jstring artist)
{

   try
   {

      set_jni_context(env);

      huge_integer iId = id;

      ::string strDisplayName = ::as_string(display_name);

      ::string strFullPath = ::as_string(full_path);

      ::string strMimeType = ::as_string(mime_type);

      ::string strTitle = ::as_string(title);

      ::string strArtist = ::as_string(artist);

      auto pitem = __allocate ::android::video_item(id, strTitle, strArtist);

      pitem->m_strDisplayName = strDisplayName;

      pitem->m_strFullPath = strFullPath;

      pitem->m_strMimeType = strMimeType;

      ::android::add_media_library_item(pitem);

   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.list_files(native)", "new_video exception");

   }

}


