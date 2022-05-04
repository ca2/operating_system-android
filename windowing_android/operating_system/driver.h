#pragma once


#include "aura/windowing/text_editor_interface.h"


class operating_system_driver :
   virtual public ::windowing::text_editor_interface

{
public:


   string         m_strApplicationIdentifier;
   string         m_strCommandLineParameters;
   ::file::path   m_pathCacheDirectory;
   int            m_iWidth;
   int            m_iHeight;
   float          m_fDpiX;
   float          m_fDpiY;
   float          m_fDensity;
   bool           m_bShowKeyboard;
   bool           m_bHideKeyboard;
   string         m_strOpenUrl;
   
   string         m_strSetUserWallpaper;
   string         m_strGetUserWallpaper;
   bool           m_bGetUserWallpaper;

   int            m_iMessageBoxButton;
   string         m_strMessageBox;
   string         m_strMessageBoxCaption;
   bool           m_bMessageBox;
   bool           m_bMessageBoxOn;
   bool           m_iMessageBoxResult;
   long long      m_lMemFreeAvailableKb;


   bool           m_bEditFocusSet;
   rectangle_i32  m_rectangleEditFocus;
   bool           m_bEditFocusKill;
   
   bool           m_bRedraw;

   bool           m_bEditorSelectionUpdated;
   int            m_iEditorSelectionStart;
   int            m_iEditorSelectionEnd;

   bool           m_bEditorTextUpdated;
   string         m_strEditorText;


   bool           m_bInputMethodManagerUpdateSelection;
   int            m_iInputMethodManagerSelectionStart;
   int            m_iInputMethodManagerSelectionEnd;
   int            m_iInputMethodManagerCandidateStart;
   int            m_iInputMethodManagerCandidateEnd;


   // windowing::text_editor_interface
   virtual void set_input_method_manager_selection(strsize iStart, strsize iEnd);
   virtual void set_input_method_manager_candidate_position(strsize iStart, strsize iEnd);
   virtual void synchronize_input_method_manager_with_selection_end();
   virtual void set_editor_selection(strsize iStart, strsize iEnd);
   virtual void set_editor_text(const ::string& strText);
   virtual void show_software_keyboard();
   virtual void hide_software_keyboard();


   static operating_system_driver* get();
   static void set(operating_system_driver* pdriver);


};



