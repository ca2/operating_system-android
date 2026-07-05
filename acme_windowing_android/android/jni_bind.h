#pragma once


#include "jni_class.h"
#include "jni_object.h"



//#define JNI_BIND_CLASS(DO) \
//      //String m_strApplicationName; \
//JX(str, ApplicationName); \
////String m_strApplicationIdentifier; \
//JX(str, ApplicationIdentifier); \
////String m_strCommandLineParameters; \
//JX(str, CommandLineParameters); \
////String m_strCacheDir; \
//JX(str, CacheDirectory); \
////int m_iWidth; \
//JX(i, Width); \
////int m_iHeight; \
//JX(i, Height); \
////float m_fDpiX; \
//JX(f, DpiX); \
////float m_fDpiY; \
//JX(f, DpiY); \
////float m_fDensity; \
//JX(f, Density); \
////boolean m_bShowKeyboard;  \
//JX(b, ShowKeyboard);  \
////boolean m_bHideKeyboard;  \
//JX(b, HideKeyboard);  \
////boolean m_bApplicationReady;  \
////JX(b, ApplicationReady);  \
////boolean m_bFpsRedraw;  \
//JX(b, FpsRedraw);  \
////boolean m_fRequestFps;  \
//JX(f, RequestFps);  \
////String m_strOpenUrl;  \
////JX(str, OpenUrl); \
////String m_strUserWallpaper;  \
//JX(str, UserWallpaper);  \
////int m_iShowMessageBox;  \
////JX(l, MessageBoxSequence);  \
//////String m_strMessageBox;  \
////JX(str, MessageBox);  \
//////String m_strMessageBoxCaption;  \
////JX(str, MessageBoxCaption);  \
//////int m_iMessageBoxButton;  \
////JX(i, MessageBoxButton);  \
//////int m_iMessageBoxResult;  \
////JX(i, MessageBoxResult);  \
////long m_lMemFreeAvailableKb;  \
//JX(l, MemFreeAvailableKb);  \
////boolean m_bEditFocusSet;  \
//JX(b, EditFocusSet);  \
////int m_iEditFocusLeft;  \
//JX(i, EditFocusLeft);  \
////int m_iEditFocusTop;  \
//JX(i, EditFocusTop);  \
////int m_iEditFocusRight;   \
//JX(i, EditFocusRight);  \
////int m_iEditFocusBottom;  \
//JX(i, EditFocusBottom);  \
////boolean m_bEditFocusKill;  \
//JX(b, EditFocusKill);  \
////boolean m_bRedraw;  \
//JX(b, Redraw);  \
////boolean m_bEditorSelectionUpdated;  \
//JX(b, EditorSelectionUpdated);  \
////int m_iEditorSelectionStart;  \
//JX(i, EditorSelectionStart);  \
////int m_iEditorSelectionEnd;  \
//JX(i, EditorSelectionEnd);  \
//////boolean m_bEditorTextUpdated;  \
////JX(b, EditorTextUpdated);  \
////int m_strEditorText;  \
//JX(str, EditorText);  \
////boolean m_bInputMethodManagerUpdateSelection;  \
//JX(b, InputMethodManagerUpdateSelection);  \
////int m_iInputMethodManagerSelectionStart;  \
//JX(i, InputMethodManagerSelectionStart);  \
////int m_iInputMethodManagerSelectionEnd;  \
//JX(i, InputMethodManagerSelectionEnd);  \
////int m_iInputMethodManagerCandidateStart;  \
//JX(i, InputMethodManagerCandidateStart);  \
////int m_iInputMethodManagerCandidateEnd;  \
//JX(i, InputMethodManagerCandidateEnd);  \
////boolean m_bLockListFileEnumerate;  \
//JX(b, LockListFileEnumerate);  \
////String m_strListFileEnumerate;  \
//JX(str, ListFileEnumerate);  \
//JX(str, Uri);  \
////JX(i, DocumentFolderRequest);  \
////JX(i, DocumentFolderResponse);  \
////JX(str, DocumentFolder);

#define JNI_BIND_CLASS(JXDATA, JXFUNC) \
JXDATA(str, ApplicationName); \
JXDATA(str, ApplicationIdentifier); \
JXDATA(str, CommandLineParameters); \
JXDATA(str, CacheDirectory);           \
JXDATA(str, AppMusicDirectory); \
JXDATA(i, Width); \
JXDATA(i, Height); \
JXDATA(f, DpiX); \
JXDATA(f, DpiY); \
JXDATA(f, Density); \
JXDATA(b, ShowKeyboard);  \
JXDATA(b, HideKeyboard);  \
JXDATA(b, FpsRedraw);  \
JXDATA(f, RequestFps);  \
JXDATA(str, UserWallpaper);  \
JXDATA(l, MemFreeAvailableKb);         \
JXDATA(l, MemTotalKb);         \
JXDATA(b, EditFocusSet);  \
JXDATA(i, EditFocusLeft);  \
JXDATA(i, EditFocusTop);  \
JXDATA(i, EditFocusRight);  \
JXDATA(i, EditFocusBottom);  \
JXDATA(b, EditFocusKill);  \
JXDATA(b, Redraw);  \
JXDATA(b, EditorSelectionUpdated);  \
JXDATA(i, EditorSelectionStart);  \
JXDATA(i, EditorSelectionEnd);  \
JXDATA(str, EditorText);  \
JXDATA(b, InputMethodManagerUpdateSelection);  \
JXDATA(i, InputMethodManagerSelectionStart);  \
JXDATA(i, InputMethodManagerSelectionEnd);  \
JXDATA(i, InputMethodManagerCandidateStart);  \
JXDATA(i, InputMethodManagerCandidateEnd);  \
JXDATA(b, LockListFileEnumerate);  \
JXDATA(str, ListFileEnumerate);  \
JXDATA(str, Uri);                      \
JXFUNC(post_media_store_operation, ::e_jni_call_void_method, "(Lplatform/platform/platform/data_block;)V");



namespace data { class block;}



BEGIN_JNI_CLASS(JNI_BIND_CLASS, jni_bind)
END_JNI_CLASS()

class jni_bind :
   public jni_object
{
public:


   IMPL_JNI_OBJECT(
      JNI_BIND_CLASS,
      jni_bind,
      "platform.platform.platform.bind")

   using jni_object::jni_object;

   static jni_bind* get();
   static void set(jni_bind* pdirect);


   bool m_bFpsRedrawNew = false;
   bool m_bFpsRedraw = true;
   ::f32 m_fRequestFpsNew = 30.f;
   ::f32 m_fRequestFps = 1.f;

   bool secure_app_storage_set(const ::scoped_string & scopedstrName, const ::scoped_string & scopedstrValue);
   ::string secure_app_storage_get(const ::scoped_string & scopedstrName);
   bool secure_app_storage_delete(const ::scoped_string & scopedstrName);
   bool secure_app_storage_contains(const ::scoped_string & scopedstrName);
   int open_content_file_descriptor(const ::scoped_string & scopedstrUri, const ::scoped_string & scopedstrMode);
   ::string get_google_access_token(const ::scoped_string & scopedstrScope);
   void clear_google_access_token(const ::scoped_string & scopedstrScope, const ::scoped_string & scopedstrAccessToken);



};



