#include "framework.h"
#include "acme/constant/id.h"
#include "_internal.h"
#include "android_asset_manager.h"
//#include "acme/platform/sequencer.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/system.h"

namespace android
{

    namespace acme
    {


        int e_message_box_to_button(const ::e_message_box &emessagebox);


        ::pointer<::acme::driver> g_pandroiddriver;


        driver::driver()
        {

           defer_create_synchronization();

           m_passetmanager = nullptr;

           //m_bLastShowSoftwareKeyboard = false;

        }


        driver::~driver()
        {

           if (::is_set(m_passetmanager)) {

              delete m_passetmanager;

           }

        }


//    void driver::set_input_method_manager_selection(character_count iSelBeg,
//    {
//
//       m_iInputMethodManagerSelectionStart = iSelBeg;
//
//       m_iInputMethodManagerSelectionEnd = iSelEnd;
//
//       m_iInputMethodManagerCandidateStart = iCandidateBeg;
//
//       m_iInputMethodManagerCandidateEnd = iCandidateEnd;
//
//       m_bInputMethodManagerUpdateSelection = true;
//
//       __android_log_print(ANDROID_LOG_INFO, "TextInput",
//                           "set_input_method_manager_selection:Sel(%d, %d),Composing:(%d, %d)",
//                           iSelBeg, iSelEnd, iCandidateBeg, iCandidateEnd);
//
//    }


//    void driver::synchronize_input_method_manager_with_selection_end()
//    {
//
//       m_iInputMethodManagerCandidateStart = m_iInputMethodManagerSelectionEnd;
//
//       m_iInputMethodManagerCandidateEnd = m_iInputMethodManagerSelectionEnd;
//
//    }


//    void driver::set_editor_selection(character_count iStart, character_count iEnd)
//    {
//
//       m_iEditorSelectionStart = iStart;
//
//       m_iEditorSelectionEnd = iEnd;
//
//       m_bEditorTextUpdated = true;
//
//    }


//    void driver::set_editor_text(const ::scoped_string & scopedstrText)
//    {
//
//       m_strEditorText = strText;
//
//       m_bEditorTextUpdated = true;
//
//    }


//    void driver::show_software_keyboard()
//    {
//
//       m_bShowKeyboard = true;
//
//       m_bLastShowSoftwareKeyboard = true;
//
//    }


//    void driver::hide_software_keyboard()
//    {
//
//       m_bHideKeyboard = true;
//
//       m_bLastShowSoftwareKeyboard = false;
//
//    }


//    driver *driver::get()
//    {
//
//       return g_pandroiddriver;
//
//    }
//
//
//    void driver::set(driver *pdriver)
//    {
//
//       g_pandroiddriver = pdriver;
//
//    }







        void driver::exchange1()
        {

           {

              synchronous_lock synchronouslock(synchronization());

              auto pdirect = ::operating_system_bind::get();

//          if (m_bHideKeyboard) {
//
//             pdirect->setHideKeyboard(true);
//
//             m_bHideKeyboard = false;
//
//          }

              string strOpenUrl;

              {

                 //synchronous_lock lock(synchronization());

                 while (m_straOpenUrl.has_element()) {

                    strOpenUrl = m_straOpenUrl.pick_first();

                    if (strOpenUrl.has_character()) {

                       break;

                    }

                 }

              }

              if (strOpenUrl.has_character()) {

                 pdirect->setOpenUrl(strOpenUrl);

              }

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

              auto pmessagebox = pick_message_box();

              if (::is_set(pmessagebox)) {

                 pmessagebox->increment_reference_count();

                 pdirect->setMessageBoxSequence((::iptr) pmessagebox.m_p);

                 pdirect->setMessageBox(pmessagebox->m_strMessage);

                 pdirect->setMessageBoxCaption(pmessagebox->m_strTitle);

                 pdirect->setMessageBoxButton(
                         e_message_box_to_button(pmessagebox->m_emessagebox));

              }

//          if (m_strSetUserWallpaper.has_character()) {
//
//             pdirect->setUserWallpaper(m_strSetUserWallpaper);
//
//             m_strSetUserWallpaper.empty();
//
//          }
//
//          if (m_bGetUserWallpaper) {
//
//             m_strGetUserWallpaper = pdirect->getUserWallpaper();
//
//             m_bGetUserWallpaper = false;
//
//          }
//
//          if (m_bEditorSelectionUpdated) {
//
//             m_bEditorSelectionUpdated = false;
//
//             pdirect->setEditorSelectionStart(m_iEditorSelectionStart);
//
//             pdirect->setEditorSelectionEnd(m_iEditorSelectionEnd);
//
//             pdirect->setEditorSelectionUpdated(true);
//
//          }
//
//          if (m_bEditorTextUpdated) {
//
//             m_bEditorTextUpdated = false;
//
//             pdirect->setEditorText(m_strEditorText);
//
//             pdirect->setEditorTextUpdated(true);
//
//          }
//
//          if (m_bEditFocusSet) {
//
//             m_bEditFocusSet = false;
//
//             pdirect->setEditFocusSet(true);
//
//             pdirect->setEditFocusLeft(m_rectangleEditFocus.left());
//
//             pdirect->setEditFocusTop(m_rectangleEditFocus.top());
//
//             pdirect->setEditFocusRight(m_rectangleEditFocus.right());
//
//             pdirect->setEditFocusBottom(m_rectangleEditFocus.bottom());
//
//          }
//
//          if (m_bEditFocusKill) {
//
//             m_bEditFocusKill = false;
//
//             pdirect->setEditFocusKill(true);
//
//          }
//
//          if (m_bRedraw) {
//
//             m_bRedraw = false;
//
//             pdirect->setRedraw(true);
//
//          }

//          if (m_bInputMethodManagerUpdateSelection) {
//
//             m_bInputMethodManagerUpdateSelection = false;
//
//             pdirect->setInputMethodManagerSelectionStart(m_iInputMethodManagerSelectionStart);
//
//             pdirect->setInputMethodManagerSelectionEnd(m_iInputMethodManagerSelectionEnd);
//
//             pdirect->setInputMethodManagerCandidateStart(m_iInputMethodManagerCandidateStart);
//
//             pdirect->setInputMethodManagerCandidateEnd(m_iInputMethodManagerCandidateEnd);
//
//             pdirect->setInputMethodManagerUpdateSelection(true);
//
//          }
//
//
//          if (m_bShowKeyboard) {
//
//             pdirect->setShowKeyboard(true);
//
//             m_bShowKeyboard = false;
//
//          }
//
//       }
//
//       {
//
//          synchronous_lock sl(m_pparticleMutexListFileEnumerate);
//
//          if (m_straListFileEnumerate.has_element()) {
//
//             auto pdirect = ::operating_system_bind::get();
//
//             auto bLock = pdirect->getLockListFileEnumerate();
//
//             if (!bLock) {
//
//                string strEnumerate = m_straListFileEnumerate.pick_first();
//
//                pdirect->setListFileEnumerate(strEnumerate);
//
//                pdirect->setLockListFileEnumerate(true);
//
//             }
//
//          }

           }


        }


        void driver::after_exchange()
        {

           {

              auto pdirect = ::operating_system_bind::get();

              string strUri = pdirect->getUri();

              if (strUri.has_character()) {

                 pdirect->setUri("");

                 system()->handle_uri(strUri);

              }

           }

        }


//    void driver::list_file_enumerate(const ::scoped_string & scopedstrListFileEnumerate)
//    {
//
//       synchronous_lock lock(m_pparticleMutexListFileEnumerate);
//
//       m_straListFileEnumerate.add(strListFileEnumerate);
//
//    }


    } // namespace acme



} // namespace android


