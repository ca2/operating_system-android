#include "framework.h"
#include "acme/id.h"
#include "_operating_system.h"
#include "_asset_manager.h"


__pointer(operating_system_driver) g_pandroiddriver;


operating_system_driver::operating_system_driver()
{

   m_passetmanager = nullptr;

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

}


void operating_system_driver::hide_software_keyboard()
{

   m_bShowKeyboard = true;

}


operating_system_driver* operating_system_driver::get()
{

   return g_pandroiddriver;

}



void operating_system_driver::set(operating_system_driver* pdriver)
{

   g_pandroiddriver = pdriver;

}



