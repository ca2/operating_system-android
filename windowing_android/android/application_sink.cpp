#include "framework.h"
#include "application_sink.h"
#include "acme/constant/id.h"
#include "acme_windowing_android/android/_internal.h"
#include "acme_windowing_android/android/android_asset_manager.h"
#include "acme_windowing_android/android/jni_message_sink.h"
//#include "acme/platform/sequencer.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/application.h"
#include "acme/platform/system.h"
#include "acme/windowing/message/types.h"
#include "aura/windowing/window.h"


namespace android
{

//int ::user::e_message_box_to_button(const ::user::e_message_box& emessagebox);


//::pointer<application_sink>g_pandroiddriver;


    application_sink::application_sink()
    {

       //defer_create_synchronization();

       m_passetmanager = nullptr;

       m_bLastShowSoftwareKeyboard = false;

    }


    application_sink::~application_sink()
    {

       if (::is_set(m_passetmanager)) {

          delete m_passetmanager;

       }

    }


    void application_sink::set_input_method_manager_selection(character_count iSelBeg,
                                                                     character_count iSelEnd,
                                                                     character_count iCandidateBeg,
                                                                     character_count iCandidateEnd)
    {

       m_iInputMethodManagerSelectionStart = iSelBeg;

       m_iInputMethodManagerSelectionEnd = iSelEnd;

       m_iInputMethodManagerCandidateStart = iCandidateBeg;

       m_iInputMethodManagerCandidateEnd = iCandidateEnd;

       m_bInputMethodManagerUpdateSelection = true;

       __android_log_print(ANDROID_LOG_INFO, "TextInput",
                           "set_input_method_manager_selection:Sel(%d, %d),Composing:(%d, %d)",
                           (int) iSelBeg, (int) iSelEnd,(int)  iCandidateBeg, (int) iCandidateEnd);

    }


    void application_sink::synchronize_input_method_manager_with_selection_end()
    {

       m_iInputMethodManagerCandidateStart = m_iInputMethodManagerSelectionEnd;

       m_iInputMethodManagerCandidateEnd = m_iInputMethodManagerSelectionEnd;

    }


    void application_sink::set_editor_selection(character_count iStart, character_count iEnd)
    {

       m_iEditorSelectionStart = iStart;

       m_iEditorSelectionEnd = iEnd;

       m_bEditorTextUpdated = true;

       auto pmessage = øcreate_new<::platform::message>();

       pmessage->m_emessage = ::e_message_set_editor_selection;

       ::message::set_editor_selection selection;

       selection.m_iSelectionStart = iStart;

       selection.m_iSelectionEnd = iEnd;

       ::output_byte2_stream stream(pmessage->m_memory);

       stream << selection;

       m_pmessagesink->post_message(pmessage);


    }


    void application_sink::set_editor_text(const ::scoped_string & scopedstrText)
    {

       m_strEditorText = scopedstrText;

       m_bEditorTextUpdated = true;

       auto pmessage = øcreate_new<::platform::message>();

       pmessage->m_emessage = ::e_message_editor_text_updated;

       ::message::editor_text_updated updated;

       updated.m_strEditorText = scopedstrText;

       ::output_byte2_stream stream(pmessage->m_memory);

       stream << updated;

       m_pmessagesink->post_message(pmessage);

    }


    void application_sink::show_software_keyboard()
    {

       m_bShowKeyboard = true;

       m_bLastShowSoftwareKeyboard = true;

       message_sink()->post_simple_message(e_message_show_software_keyboard);

    }


    void application_sink::hide_software_keyboard()
    {

       m_bHideKeyboard = true;

       m_bLastShowSoftwareKeyboard = false;

       message_sink()->post_simple_message(e_message_hide_software_keyboard);

    }


//
//
//    void application_sink::queue_message_box(::message_box *psequencer)
//    {
//
//       //synchronous_lock synchronouslock(m_pparticleMutexMessageBoxSequencer);
//
//       //m_sequenceraMessageBox.add(psequencer);
//
//    }
//
//
//    ::pointer<::message_box> application_sink::pick_message_box()
//    {
//
//       synchronous_lock synchronouslock(m_pparticleMutexMessageBoxSequencer);
//
////   if (m_sequenceraMessageBox.is_empty())
////   {
////
////      return nullptr;
////
////   }
////
////   auto psequencer = m_sequenceraMessageBox.pop_first();
//
////   return psequencer;
//
//       return {};
//
//    }


//    void application_sink::open_url(const ::scoped_string & scopedstrOpenUrl)
//    {
//
//       synchronous_lock lock(synchronization());
//
//       m_straOpenUrl.add(strOpenUrl);
//
//    }


    void application_sink::exchange1()
    {

       {

          synchronous_lock synchronouslock(synchronization());

          auto pbind = ::jni_bind::get();

          if (m_bHideKeyboard) {

             pbind->setHideKeyboard(true);

             m_bHideKeyboard = false;

          }

          ::android::acme::application_sink::exchange1();

//          string strOpenUrl;
//
//          {
//
//             //synchronous_lock lock(synchronization());
//
//             while (m_straOpenUrl.has_element()) {
//
//                strOpenUrl = m_straOpenUrl.pick_first();
//
//                if (strOpenUrl.has_character()) {
//
//                   break;
//
//                }
//
//             }
//
//          }
//
//          if (strOpenUrl.has_character()) {
//
//             pbind->setOpenUrl(strOpenUrl);
//
//          }

          //if (m_bMessageBoxOn)
          //{

          //   int iResult = pbind->getMessageBoxResult();

          //   if (iResult > 0)
          //   {

          //      m_bMessageBoxOn = false;

          //   }

          //}
          //else
          //{

//          auto pmessagebox = pick_message_box();
//
//          if (::is_set(pmessagebox)) {
//
//             pmessagebox->increment_reference_count();
//
//             pbind->setMessageBoxSequence((::iptr) pmessagebox.m_p);
//
//             pbind->setMessageBox(pmessagebox->m_strMessage);
//
//             pbind->setMessageBoxCaption(pmessagebox->m_strTitle);
//
//             pbind->setMessageBoxButton(::user::e_message_box_to_button(pmessagebox->m_emessagebox));
//
//          }

          if (m_strSetUserWallpaper.has_character()) {

             pbind->setUserWallpaper(m_strSetUserWallpaper);

             m_strSetUserWallpaper.empty();

          }

          if (m_bGetUserWallpaper) {

             m_strGetUserWallpaper = pbind->getUserWallpaper();

             m_bGetUserWallpaper = false;

          }

          if (m_bEditorSelectionUpdated) {

             m_bEditorSelectionUpdated = false;

             pbind->setEditorSelectionStart(m_iEditorSelectionStart);

             pbind->setEditorSelectionEnd(m_iEditorSelectionEnd);

             pbind->setEditorSelectionUpdated(true);

          }

//          if (m_bEditorTextUpdated) {
//
//             m_bEditorTextUpdated = false;
//
//             pbind->setEditorText(m_strEditorText);
//
//             pbind->setEditorTextUpdated(true);
//
//          }

          if (m_bEditFocusSet) {

             m_bEditFocusSet = false;

             pbind->setEditFocusSet(true);

             pbind->setEditFocusLeft(m_rectangleEditFocus.left());

             pbind->setEditFocusTop(m_rectangleEditFocus.top());

             pbind->setEditFocusRight(m_rectangleEditFocus.right());

             pbind->setEditFocusBottom(m_rectangleEditFocus.bottom());

          }

          if (m_bEditFocusKill) {

             m_bEditFocusKill = false;

             pbind->setEditFocusKill(true);

          }

//          if (m_bRedraw) {
//
//             m_bRedraw = false;
//
//             pbind->setRedraw(true);
//
//          }

          if (m_bInputMethodManagerUpdateSelection) {

             m_bInputMethodManagerUpdateSelection = false;

             pbind->setInputMethodManagerSelectionStart(m_iInputMethodManagerSelectionStart);

             pbind->setInputMethodManagerSelectionEnd(m_iInputMethodManagerSelectionEnd);

             pbind->setInputMethodManagerCandidateStart(m_iInputMethodManagerCandidateStart);

             pbind->setInputMethodManagerCandidateEnd(m_iInputMethodManagerCandidateEnd);

             pbind->setInputMethodManagerUpdateSelection(true);

          }


          if (m_bShowKeyboard) {

             pbind->setShowKeyboard(true);

             m_bShowKeyboard = false;

          }

       }

       {

          //synchronous_lock sl(m_pparticleMutexListFileEnumerate);
          synchronous_lock sl(this->synchronization());

          if (m_straListFileEnumerate.has_element()) {

             auto pbind = ::jni_bind::get();

             auto bLock = pbind->getLockListFileEnumerate();

             if (!bLock) {

                string strEnumerate = m_straListFileEnumerate.pick_first();

                pbind->setListFileEnumerate(strEnumerate);

                pbind->setLockListFileEnumerate(true);

             }

          }

       }


//       {
//
//          //synchronous_lock sl(m_pparticleMutexListFileEnumerate);
//          synchronous_lock sl(this->synchronization());
//
//          if (m_bSetApplicationReady) {
//
//             m_bSetApplicationReady = false;
//
//             auto pbind = ::jni_bind::get();
//
//             pbind->setApplicationReady(true);
//
//          }
//
//       }

//       {
//
//          auto pbind = ::jni_bind::get();
//
//          string strUri = pbind->getUri();
//
//          if (strUri.has_character()) {
//
//             pbind->setUri("");
//
//             system()->handle_uri(strUri);
//
//          }
//
//       }

    }

//
//    void application_sink::list_file_enumerate(const ::scoped_string & scopedstrListFileEnumerate)
//    {
//
//       synchronous_lock lock(m_pparticleMutexListFileEnumerate);
//
//       m_straListFileEnumerate.add(strListFileEnumerate);
//
//    }

//extern "C"
//JNIEXPORT void JNICALL Java_platform_platform_user_impact_aura_1size_1changed(JNIEnv * env, jobject  obj)
void application_sink::context_on_size_changed()
{


   try
   {

  //    set_jni_context(env);

      //::int_rectangle rectangle;

      //rectangle.left() = 0;
      //rectangle.top() = 0;
      //rectangle.right() = ::jni_bind::get()->getWidth();
      //rectangle.bottom() = ::jni_bind::get()->getHeight();

      auto w = ::jni_bind::get()->getWidth();
      auto h = ::jni_bind::get()->getHeight();

      //android_on_size(0, 0, w, h);

      //try
   //   {

      auto pwindowApplicationHost = ::system()->get_main_host_window();

      if (::is_set(pwindowApplicationHost))
      {

         ::system()->m_papplication->post([this, pwindowApplicationHost, w, h]()
                                          {

                                             pwindowApplicationHost->on_size(w, h);

                                          });

      }
      //      android_on_text(os_text_keyboard, utf16, length);



   }
   catch (...)
   {

      __android_log_write(ANDROID_LOG_WARN, "com.ace.impact(native)", "aura_size_changed exception");

   }


   //try
   //{

      //g_psystem->m_puser->(rectangle);

   //}
   //catch (...)
   //{

   //}

   //auto pimpl = puserinteraction->m_pimpl.cast < ::windowing::window >();

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

   //         puserinteractionChild->send_message(::user::e_message_display_change);

   //         //::pointer<::windowing::window>pimpl = puserinteraction->m_pimpl;

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


} // namespace android



