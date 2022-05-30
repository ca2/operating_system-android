#include "framework.h"
#include "acme/id.h"
#include "_android.h"
#include "_asset_manager.h"


int e_message_box_to_button(const ::e_message_box& emessagebox);


__pointer(operating_system_driver) g_pandroiddriver;


operating_system_driver::operating_system_driver()
{

   defer_create_mutex();

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


void operating_system_driver::set_input_method_manager_selection(strsize iStart, strsize iEnd)
{

   m_iInputMethodManagerSelectionStart = iStart;

   m_iInputMethodManagerSelectionEnd = iEnd;

   m_bInputMethodManagerUpdateSelection = true;

}


void operating_system_driver::set_input_method_manager_candidate_position(strsize iStart, strsize iEnd)
{

   m_iInputMethodManagerCandidateStart = iStart;

   m_iInputMethodManagerCandidateEnd = iEnd;

   m_bInputMethodManagerUpdateSelection = true;

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



void operating_system_driver::add_message_box_sequence(::sequence < ::conversation >* psequence)
{

   synchronous_lock synchronouslock(&m_mutexMessageBoxSequence);

   m_sequenceaMessageBox.add(psequence);

}


__pointer(::sequence < ::conversation >) operating_system_driver::pick_message_box_sequence()
{

   synchronous_lock synchronouslock(&m_mutexMessageBoxSequence);

   if (m_sequenceaMessageBox.is_empty())
   {

      return nullptr;

   }

   auto psequence = m_sequenceaMessageBox.pop_first();

   return psequence;

}


void operating_system_driver::open_url(const ::string& strOpenUrl)
{

   synchronous_lock lock(mutex());

   m_straOpenUrl.add(strOpenUrl);

}


void operating_system_driver::exchange()
{

   {

      synchronous_lock synchronouslock(mutex());

      auto pdirect = ::operating_system_bind::get();

      if (m_bHideKeyboard)
      {

         pdirect->setHideKeyboard(true);

         m_bHideKeyboard = false;

      }

      string strOpenUrl;

      {

         //synchronous_lock lock(mutex());

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

      auto psequence = pick_message_box_sequence();

      if (::is_set(psequence))
      {

         psequence->increment_reference_count();

         pdirect->setMessageBoxSequence((::iptr)psequence.m_p);

         auto& sequence = *psequence;

         pdirect->setMessageBox(sequence->get_message_box_message());

         pdirect->setMessageBoxCaption(sequence->get_message_box_title());

         pdirect->setMessageBoxButton(e_message_box_to_button(sequence->get_message_box_flags()));

      }

      if (m_strSetUserWallpaper.has_char())
      {

         pdirect->setUserWallpaper(m_strSetUserWallpaper);

         m_strSetUserWallpaper.Empty();

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

      synchronous_lock sl(&m_mutexListFileEnumerate);

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

}


void operating_system_driver::list_file_enumerate(const ::string& strListFileEnumerate)
{

   synchronous_lock lock(&m_mutexListFileEnumerate);

   m_straListFileEnumerate.add(strListFileEnumerate);

}


