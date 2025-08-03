#include "framework.h"
#include "application_state.h"
#include "acme/constant/id.h"
#include "acme_windowing_android/android/_internal.h"
#include "acme_windowing_android/android/android_asset_manager.h"
//#include "acme/platform/sequencer.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/system.h"


namespace android
{

//int e_message_box_to_button(const ::e_message_box& emessagebox);


//::pointer<application_state>g_pandroiddriver;


    application_state::application_state()
    {

       //defer_create_synchronization();

       m_passetmanager = nullptr;

       m_bLastShowSoftwareKeyboard = false;

    }


    application_state::~application_state()
    {

       if (::is_set(m_passetmanager)) {

          delete m_passetmanager;

       }

    }


    void application_state::set_input_method_manager_selection(character_count iSelBeg,
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


    void application_state::synchronize_input_method_manager_with_selection_end()
    {

       m_iInputMethodManagerCandidateStart = m_iInputMethodManagerSelectionEnd;

       m_iInputMethodManagerCandidateEnd = m_iInputMethodManagerSelectionEnd;

    }


    void application_state::set_editor_selection(character_count iStart, character_count iEnd)
    {

       m_iEditorSelectionStart = iStart;

       m_iEditorSelectionEnd = iEnd;

       m_bEditorTextUpdated = true;

    }


    void application_state::set_editor_text(const ::scoped_string & scopedstrText)
    {

       m_strEditorText = scopedstrText;

       m_bEditorTextUpdated = true;

    }


    void application_state::show_software_keyboard()
    {

       m_bShowKeyboard = true;

       m_bLastShowSoftwareKeyboard = true;

    }


    void application_state::hide_software_keyboard()
    {

       m_bHideKeyboard = true;

       m_bLastShowSoftwareKeyboard = false;

    }


//
//
//    void application_state::queue_message_box(::message_box *psequencer)
//    {
//
//       //synchronous_lock synchronouslock(m_pparticleMutexMessageBoxSequencer);
//
//       //m_sequenceraMessageBox.add(psequencer);
//
//    }
//
//
//    ::pointer<::message_box> application_state::pick_message_box()
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


//    void application_state::open_url(const ::scoped_string & scopedstrOpenUrl)
//    {
//
//       synchronous_lock lock(synchronization());
//
//       m_straOpenUrl.add(strOpenUrl);
//
//    }


    void application_state::exchange1()
    {

       {

          synchronous_lock synchronouslock(synchronization());

          auto pdirect = ::operating_system_bind::get();

          if (m_bHideKeyboard) {

             pdirect->setHideKeyboard(true);

             m_bHideKeyboard = false;

          }

          ::platform::application_state::exchange1();

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
//             pdirect->setOpenUrl(strOpenUrl);
//
//          }

          //if (m_bMessageBoxOn)
          //{

          //   int iResult = pdirect->getMessageBoxResult();

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
//             pdirect->setMessageBoxSequence((::iptr) pmessagebox.m_p);
//
//             pdirect->setMessageBox(pmessagebox->m_strMessage);
//
//             pdirect->setMessageBoxCaption(pmessagebox->m_strTitle);
//
//             pdirect->setMessageBoxButton(e_message_box_to_button(pmessagebox->m_emessagebox));
//
//          }

          if (m_strSetUserWallpaper.has_character()) {

             pdirect->setUserWallpaper(m_strSetUserWallpaper);

             m_strSetUserWallpaper.empty();

          }

          if (m_bGetUserWallpaper) {

             m_strGetUserWallpaper = pdirect->getUserWallpaper();

             m_bGetUserWallpaper = false;

          }

          if (m_bEditorSelectionUpdated) {

             m_bEditorSelectionUpdated = false;

             pdirect->setEditorSelectionStart(m_iEditorSelectionStart);

             pdirect->setEditorSelectionEnd(m_iEditorSelectionEnd);

             pdirect->setEditorSelectionUpdated(true);

          }

          if (m_bEditorTextUpdated) {

             m_bEditorTextUpdated = false;

             pdirect->setEditorText(m_strEditorText);

             pdirect->setEditorTextUpdated(true);

          }

          if (m_bEditFocusSet) {

             m_bEditFocusSet = false;

             pdirect->setEditFocusSet(true);

             pdirect->setEditFocusLeft(m_rectangleEditFocus.left());

             pdirect->setEditFocusTop(m_rectangleEditFocus.top());

             pdirect->setEditFocusRight(m_rectangleEditFocus.right());

             pdirect->setEditFocusBottom(m_rectangleEditFocus.bottom());

          }

          if (m_bEditFocusKill) {

             m_bEditFocusKill = false;

             pdirect->setEditFocusKill(true);

          }

//          if (m_bRedraw) {
//
//             m_bRedraw = false;
//
//             pdirect->setRedraw(true);
//
//          }

          if (m_bInputMethodManagerUpdateSelection) {

             m_bInputMethodManagerUpdateSelection = false;

             pdirect->setInputMethodManagerSelectionStart(m_iInputMethodManagerSelectionStart);

             pdirect->setInputMethodManagerSelectionEnd(m_iInputMethodManagerSelectionEnd);

             pdirect->setInputMethodManagerCandidateStart(m_iInputMethodManagerCandidateStart);

             pdirect->setInputMethodManagerCandidateEnd(m_iInputMethodManagerCandidateEnd);

             pdirect->setInputMethodManagerUpdateSelection(true);

          }


          if (m_bShowKeyboard) {

             pdirect->setShowKeyboard(true);

             m_bShowKeyboard = false;

          }

       }

       {

          //synchronous_lock sl(m_pparticleMutexListFileEnumerate);
          synchronous_lock sl(this->synchronization());

          if (m_straListFileEnumerate.has_element()) {

             auto pdirect = ::operating_system_bind::get();

             auto bLock = pdirect->getLockListFileEnumerate();

             if (!bLock) {

                string strEnumerate = m_straListFileEnumerate.pick_first();

                pdirect->setListFileEnumerate(strEnumerate);

                pdirect->setLockListFileEnumerate(true);

             }

          }

       }

//       {
//
//          auto pdirect = ::operating_system_bind::get();
//
//          string strUri = pdirect->getUri();
//
//          if (strUri.has_character()) {
//
//             pdirect->setUri("");
//
//             system()->handle_uri(strUri);
//
//          }
//
//       }

    }

//
//    void application_state::list_file_enumerate(const ::scoped_string & scopedstrListFileEnumerate)
//    {
//
//       synchronous_lock lock(m_pparticleMutexListFileEnumerate);
//
//       m_straListFileEnumerate.add(strListFileEnumerate);
//
//    }


} // namespace android



