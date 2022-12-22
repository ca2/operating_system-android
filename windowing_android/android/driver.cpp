#include "framework.h"
#include "acme/constant/id.h"
#include "_internal.h"
#include "_asset_manager.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/system.h"


int e_message_box_to_button(const ::e_message_box& emessagebox);


::pointer<operating_system_driver>g_pandroiddriver;


operating_system_driver::operating_system_driver()
{

   defer_create_synchronization();

   m_passetmanager = nullptr;

   m_bLastShowSoftwareKeyboard = false;

}


operating_system_driver::~operating_system_driver()
{

   if (::is_set(m_passetmanager))
   {
    
      delete m_passetmanager;

   }

}


void operating_system_driver::set_input_method_manager_selection(strsize iSelBeg, strsize iSelEnd, strsize iCandidateBeg, strsize iCandidateEnd)
{

   m_iInputMethodManagerSelectionStart = iSelBeg;

   m_iInputMethodManagerSelectionEnd = iSelEnd;

   m_iInputMethodManagerCandidateStart = iCandidateBeg;

   m_iInputMethodManagerCandidateEnd = iCandidateEnd;

   m_bInputMethodManagerUpdateSelection = true;

   __android_log_print(ANDROID_LOG_INFO, "TextInput", "set_input_method_manager_selection:Sel(%d, %d),Composing:(%d, %d)", iSelBeg, iSelEnd, iCandidateBeg, iCandidateEnd);

}


void operating_system_driver::synchronize_input_method_manager_with_selection_end()
{

   m_iInputMethodManagerCandidateStart = m_iInputMethodManagerSelectionEnd;

   m_iInputMethodManagerCandidateEnd = m_iInputMethodManagerSelectionEnd;

}


void operating_system_driver::set_editor_selection(strsize iStart, strsize iEnd)
{

   m_iEditorSelectionStart = iStart;

   m_iEditorSelectionEnd = iEnd;

   m_bEditorTextUpdated = true;

}


void operating_system_driver::set_editor_text(const ::string& strText)
{

   m_strEditorText = strText;

   m_bEditorTextUpdated = true;

}


void operating_system_driver::show_software_keyboard()
{

   m_bShowKeyboard = true;

   m_bLastShowSoftwareKeyboard = true;

}


void operating_system_driver::hide_software_keyboard()
{

   m_bHideKeyboard = true;

   m_bLastShowSoftwareKeyboard = false;

}


operating_system_driver* operating_system_driver::get()
{

   return g_pandroiddriver;

}



void operating_system_driver::set(operating_system_driver* pdriver)
{

   g_pandroiddriver = pdriver;

}



void operating_system_driver::queue_message_box_sequencer(::sequencer< ::conversation >* psequencer)
{

   synchronous_lock synchronouslock(m_pparticleMutexMessageBoxSequencer);

   m_sequenceraMessageBox.add(psequencer);

}


pointer< ::sequencer < ::conversation > > operating_system_driver::pick_message_box_sequencer()
{

   synchronous_lock synchronouslock(m_pparticleMutexMessageBoxSequencer);

   if (m_sequenceraMessageBox.is_empty())
   {

      return nullptr;

   }

   auto psequencer = m_sequenceraMessageBox.pop_first();

   return psequencer;

}


void operating_system_driver::open_url(const ::string& strOpenUrl)
{

   synchronous_lock lock(synchronization());

   m_straOpenUrl.add(strOpenUrl);

}


void operating_system_driver::exchange()
{

   {

      synchronous_lock synchronouslock(synchronization());

      auto pdirect = ::operating_system_bind::get();

      if (m_bHideKeyboard)
      {

         pdirect->setHideKeyboard(true);

         m_bHideKeyboard = false;

      }

      string strOpenUrl;

      {

         //synchronous_lock lock(synchronization());

         while (m_straOpenUrl.has_element())
         {

            strOpenUrl = m_straOpenUrl.pick_first();

            if (strOpenUrl.has_char())
            {

               break;

            }

         }

      }

      if (strOpenUrl.has_char())
      {

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

      auto psequencer = pick_message_box_sequencer();

      if (::is_set(psequencer))
      {

         psequencer->increment_reference_count();

         pdirect->setMessageBoxSequence((::iptr)psequencer.m_p);

         pdirect->setMessageBox(psequencer->m_psequence->get_conversation_message());

         pdirect->setMessageBoxCaption(psequencer->m_psequence->get_conversation_title());

         pdirect->setMessageBoxButton(e_message_box_to_button(psequencer->m_psequence->get_conversation_flags()));

      }

      if (m_strSetUserWallpaper.has_char())
      {

         pdirect->setUserWallpaper(m_strSetUserWallpaper);

         m_strSetUserWallpaper.empty();

      }

      if (m_bGetUserWallpaper)
      {

         m_strGetUserWallpaper = pdirect->getUserWallpaper();

         m_bGetUserWallpaper = false;

      }

      if (m_bEditorSelectionUpdated)
      {

         m_bEditorSelectionUpdated = false;

         pdirect->setEditorSelectionStart(m_iEditorSelectionStart);

         pdirect->setEditorSelectionEnd(m_iEditorSelectionEnd);

         pdirect->setEditorSelectionUpdated(true);

      }

      if (m_bEditorTextUpdated)
      {

         m_bEditorTextUpdated = false;

         pdirect->setEditorText(m_strEditorText);

         pdirect->setEditorTextUpdated(true);

      }

      if (m_bEditFocusSet)
      {

         m_bEditFocusSet = false;

         pdirect->setEditFocusSet(true);

         pdirect->setEditFocusLeft(m_rectangleEditFocus.left);

         pdirect->setEditFocusTop(m_rectangleEditFocus.top);

         pdirect->setEditFocusRight(m_rectangleEditFocus.right);

         pdirect->setEditFocusBottom(m_rectangleEditFocus.bottom);

      }

      if (m_bEditFocusKill)
      {

         m_bEditFocusKill = false;

         pdirect->setEditFocusKill(true);

      }

      if (m_bRedraw)
      {

         m_bRedraw = false;

         pdirect->setRedraw(true);

      }

      if (m_bInputMethodManagerUpdateSelection)
      {

         m_bInputMethodManagerUpdateSelection = false;

         pdirect->setInputMethodManagerSelectionStart(m_iInputMethodManagerSelectionStart);

         pdirect->setInputMethodManagerSelectionEnd(m_iInputMethodManagerSelectionEnd);

         pdirect->setInputMethodManagerCandidateStart(m_iInputMethodManagerCandidateStart);

         pdirect->setInputMethodManagerCandidateEnd(m_iInputMethodManagerCandidateEnd);

         pdirect->setInputMethodManagerUpdateSelection(true);

      }


      if (m_bShowKeyboard)
      {

         pdirect->setShowKeyboard(true);

         m_bShowKeyboard = false;

      }

   }

   {

      synchronous_lock sl(m_pparticleMutexListFileEnumerate);

      if (m_straListFileEnumerate.has_element())
      {

         auto pdirect = ::operating_system_bind::get();

         auto bLock = pdirect->getLockListFileEnumerate();

         if (!bLock)
         {

            string strEnumerate = m_straListFileEnumerate.pick_first();

            pdirect->setListFileEnumerate(strEnumerate);

            pdirect->setLockListFileEnumerate(true);

         }

      }

   }

   {

      auto pdirect = ::operating_system_bind::get();

      string strUri = pdirect->getUri();

      if (strUri.has_char())
      {

         pdirect->setUri("");

         acmesystem()->handle_uri(strUri);

      }

   }

}


void operating_system_driver::list_file_enumerate(const ::string& strListFileEnumerate)
{

   synchronous_lock lock(m_pparticleMutexListFileEnumerate);

   m_straListFileEnumerate.add(strListFileEnumerate);

}



