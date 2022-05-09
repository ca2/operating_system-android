#include "framework.h"
#include "_operating_system.h"


extern class ::system* g_psystem;


void android_aura_main()
{

   auto pdirect = operating_system_direct::get();

   auto pdriver = operating_system_driver::get();

   //string strApplicationIdentifier = pdriver->m_strApplicationIdentifier;

   //auto psystem = platform_create_system(strApplicationIdentifier);

   //psystem->m_pathCacheDirectory = pdirect->getCacheDirectory();

   //psystem->system_construct("", e_display_default);

   //psystem->system_construct(pdriver, e_display_default);

   //::e_status estatus = psystem->m_papexsystem->os_application_system_run();
   //
   //if (!estatus)
   //{

   //   printf("os_application_system_run failed\n");

   //   return;

   //}




   //psession->set_main_screen_rect(rectangle);

   //auto puserinteraction = __user_interaction(::aura::get_system()->get_session()->m_puserinteractionHost);

   //puserinteraction->place(rectangle);

   //puserinteraction->display(e_display_normal);

   //puserinteraction->set_need_layout();

   ////puserinteraction->post_redraw();

   //auto pimpl = puserinteraction->m_pimpl.cast < ::user::interaction_impl >();

   //if (pimpl)
   //{

   //   pimpl->m_pprodevian->prodevian_update_buffer(true);

   //   //operating_system_driver::get()->m_bRedraw = true;

   //}



//psystem->post_initial_request();

}


int e_message_box_to_button(const ::e_message_box& emessagebox)
{

   auto emessageboxType = emessagebox & e_message_box_type_mask;

//   e_message_box_ok = 0x00000000L,
  //    e_message_box_ok_cancel = 0x00000001L,
    //  e_message_box_abort_retry_ignore = 0x00000002L,
      //e_message_box_yes_no_cancel = 0x00000003L,
      //e_message_box_yes_no = 0x00000004L,
      //e_message_box_retry_cancel = 0x00000005L,
      //e_message_box_cancel_try_continue = 0x00000006L,

   bool bOk = false; // 16
   bool bYes = false; // 32
   bool bNo = false; // 64
   bool bAbort = false; // 128
   bool bRetry = false; // 256
   bool bIgnore = false; // 512
   bool bCancel = false; // 1024
   bool bTry = false; // 2048
   bool bContinue = false; // 4096

   switch (emessageboxType)
   {
   case e_message_box_ok_cancel:
      bOk = true;
      bCancel = true;
      break;
   case e_message_box_abort_retry_ignore:
      bAbort = true;
      bRetry = true;
      bIgnore = true;
      break;
   case e_message_box_yes_no_cancel:
      bYes = true;
      bNo = true;
      bCancel = true;
      break;
   case e_message_box_yes_no:
      bYes = true;
      bNo = true;
      break;
   case e_message_box_retry_cancel:
      bRetry = true;
      bCancel = true;
      break;
   case e_message_box_cancel_try_continue:
      bCancel = true;
      bTry = true;
      bContinue = true;
      break;
   default:
      break;
   }
   
   int iButton = 0;

   if (bOk)
   {

      iButton |= 16;

   }

   if (bYes)
   {

      iButton |= 32;

   }

   if (bNo)
   {

      iButton |= 64;

   }

   if (bAbort)
   {

      iButton |= 128;

   }

   if (bRetry)
   {

      iButton |= 256;

   }

   if (bIgnore)
   {

      iButton |= 512;

   }

   if (bCancel)
   {

      iButton |= 1024;

   }

   if (bTry)
   {

      iButton |= 2048;

   }
   
   if (bContinue)
   {

      iButton |= 4096;

   }

   return iButton;

}


::mutex * osmutex();

void android_exchange()
{

   synchronous_lock synchronouslock(osmutex());

   auto pdriver = ::operating_system_driver::get();

   auto pdirect = ::operating_system_direct::get();

   if (pdriver->m_bHideKeyboard)
   {

      pdirect->setHideKeyboard(true);

      pdriver->m_bHideKeyboard = false;

   }

   if (pdriver->m_strOpenUrl.has_char())
   {

      pdirect->setOpenUrl(pdriver->m_strOpenUrl);

      pdriver->m_strOpenUrl.Empty();

   }

   //if (pdriver->m_bMessageBoxOn)
   //{

   //   int iResult = pdirect->getMessageBoxResult();

   //   if (iResult > 0)
   //   {

   //      pdriver->m_bMessageBoxOn = false;

   //   }

   //}
   //else
   //{

   auto psequence = pdriver->pick_message_box_sequence();

   if (::is_set(psequence))
   {

      psequence->increment_reference_count();

      pdirect->setMessageBoxSequence((::iptr)psequence.m_p);

      auto& sequence = *psequence;

      pdirect->setMessageBox(sequence->get_message_box_message());

      pdirect->setMessageBoxCaption(sequence->get_message_box_title());

      pdirect->setMessageBoxButton(e_message_box_to_button(sequence->get_message_box_flags()));

   }

   if (pdriver->m_strSetUserWallpaper.has_char())
   {

      pdirect->setUserWallpaper(pdriver->m_strSetUserWallpaper);

      pdriver->m_strSetUserWallpaper.Empty();

   }

   if (pdriver->m_bGetUserWallpaper)
   {

      pdriver->m_strGetUserWallpaper = pdirect->getUserWallpaper();

      pdriver->m_bGetUserWallpaper = false;

   }

   if (pdriver->m_bEditorSelectionUpdated)
   {

      pdriver->m_bEditorSelectionUpdated = false;

      pdirect->setEditorSelectionStart(pdriver->m_iEditorSelectionStart);

      pdirect->setEditorSelectionEnd(pdriver->m_iEditorSelectionEnd);

      pdirect->setEditorSelectionUpdated(true);

   }

   if (pdriver->m_bEditorTextUpdated)
   {

      pdriver->m_bEditorTextUpdated = false;

      pdirect->setEditorText(pdriver->m_strEditorText);

      pdirect->setEditorTextUpdated(true);

   }

   if (pdriver->m_bEditFocusSet)
   {

      pdriver->m_bEditFocusSet = false;

      pdirect->setEditFocusSet(true);

      pdirect->setEditFocusLeft(pdriver->m_rectangleEditFocus.left);

      pdirect->setEditFocusTop(pdriver->m_rectangleEditFocus.top);

      pdirect->setEditFocusRight(pdriver->m_rectangleEditFocus.right);

      pdirect->setEditFocusBottom(pdriver->m_rectangleEditFocus.bottom);

   }

   if (pdriver->m_bEditFocusKill)
   {

      pdriver->m_bEditFocusKill = false;

      pdirect->setEditFocusKill(true);

   }

   if (pdriver->m_bRedraw)
   {

      pdriver->m_bRedraw = false;

      pdirect->setRedraw(true);

   }

   if (pdriver->m_bInputMethodManagerUpdateSelection)
   {

      pdriver->m_bInputMethodManagerUpdateSelection = false;

      pdirect->setInputMethodManagerSelectionStart(pdriver->m_iInputMethodManagerSelectionStart);

      pdirect->setInputMethodManagerSelectionEnd(pdriver->m_iInputMethodManagerSelectionEnd);

      pdirect->setInputMethodManagerCandidateStart(pdriver->m_iInputMethodManagerCandidateStart);

      pdirect->setInputMethodManagerCandidateEnd(pdriver->m_iInputMethodManagerCandidateEnd);

      pdirect->setInputMethodManagerUpdateSelection(true);

   }


   if (pdriver->m_bShowKeyboard)
   {

      pdirect->setShowKeyboard(true);

      pdriver->m_bShowKeyboard = false;

   }

}


void android_edit_on_set_focus(int l, int t, int r, int b, const ::string & pszText, int iBeg, int iEnd)
{

   synchronous_lock synchronouslock(osmutex());

   auto pdriver = ::operating_system_driver::get();

   pdriver->m_bEditFocusKill = false;

   pdriver->m_rectangleEditFocus.left = l;
   pdriver->m_rectangleEditFocus.top = t;
   pdriver->m_rectangleEditFocus.right = r;
   pdriver->m_rectangleEditFocus.bottom = b;

   pdriver->m_iEditorSelectionStart = iBeg;
   pdriver->m_iEditorSelectionEnd = iEnd;
   pdriver->m_bEditorSelectionUpdated = true;

   pdriver->m_strEditorText = pszText;
   pdriver->m_bEditorTextUpdated = true;

   pdriver->m_bEditFocusSet = true;

}


void android_edit_on_kill_focus()
{

   synchronous_lock synchronouslock(osmutex());

   auto pdriver = ::operating_system_driver::get();

   pdriver->m_bEditFocusKill = true;

   pdriver->m_bEditFocusSet = false;

}

//
//pinputmethodmanager->sync_candidate_with_sel_end();
//operating_system_driver::get()->m_iInputMethodManagerCandidateStart = operating_system_driver::get()->m_iInputMethodManagerSelectionEnd;
//
//operating_system_driver::get()->m_iInputMethodManagerCandidateEnd = operating_system_driver::get()->m_iInputMethodManagerSelectionEnd;
//
//
//
//
//
//operating_system_driver::get()->m_strEditorText = strText;
//
//operating_system_driver::get()->m_bEditorTextUpdated = true;
//
//#endif


//
//
//
//
//
//void set_operating_system_direct(operating_system_direct* pdirect)
//{
//
//   g_pandroiddirect = pdirect;
//
//}
//
//
//operating_system_direct* operating_system_direct::get()
//{
//
//   return g_pandroiddirect;
//
//}
//
//
//__pointer(operating_system_driver) g_pandroiddriver;
//
//
//void set_operating_system_driver(operating_system_driver* poslocal)
//{
//
//   g_pandroiddriver = poslocal;
//
//}
//
//
//operating_system_driver* operating_system_driver::get()
//{
//
//   return g_pandroiddriver;
//
//}
