#include "framework.h"
#include "_internal.h"
#include "acme/parallelization/synchronous_lock.h"


void android_aura_main()
{


   auto pdirect = jni_bind::get();

   auto pdriver = operating_system_driver::get();

   //string strApplicationIdentifier = pdriver->m_strApplicationIdentifier;

   //auto psystem = platform_create_system(strApplicationIdentifier);

   //psystem->m_pathCacheDirectory = pdirect->getCacheDirectory();

   //psystem->system_construct("", e_display_default);

   //psystem->system_construct(pdriver, e_display_default);

   //::e_status estatus = psystem->os_application_system_run();
   //
   //if (!estatus)
   //{

   //   printf("os_application_system_run failed\n");

   //   return;

   //}




   //psession->set_main_screen_rect(rectangle);

   //auto puserinteraction = __user_interaction(::auraacmesystem()->get_session()->m_puserinteractionHost);

   //puserinteraction->place(rectangle);

   //puserinteraction->display(e_display_normal);

   //puserinteraction->set_need_layout();

   ////puserinteraction->post_redraw();

   //auto pimpl = puserinteraction->m_pimpl.cast < ::windowing::window >();

   //if (pimpl)
   //{

   //   pimpl->m_pprodevian->prodevian_update_buffer(true);

   //   //operating_system_driver::get()->m_bRedraw = true;

   //}



//psystem->aaa_post_initial_request();

}


int ::user::e_message_box_to_button(const ::::user::e_message_box& emessagebox)
{

   auto emessageboxType = emessagebox & ::user::e_message_box_type_mask;

//   ::user::e_message_box_ok = 0x00000000L,
  //    ::user::e_message_box_ok_cancel = 0x00000001L,
    //  ::user::e_message_box_abort_retry_ignore = 0x00000002L,
      //::user::e_message_box_yes_no_cancel = 0x00000003L,
      //::user::e_message_box_yes_no = 0x00000004L,
      //::user::e_message_box_retry_cancel = 0x00000005L,
      //::user::e_message_box_cancel_try_continue = 0x00000006L,

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
   case ::user::e_message_box_ok_cancel:
      bOk = true;
      bCancel = true;
      break;
   case ::user::e_message_box_abort_retry_ignore:
      bAbort = true;
      bRetry = true;
      bIgnore = true;
      break;
   case ::user::e_message_box_yes_no_cancel:
      bYes = true;
      bNo = true;
      bCancel = true;
      break;
   case ::user::e_message_box_yes_no:
      bYes = true;
      bNo = true;
      break;
   case ::user::e_message_box_retry_cancel:
      bRetry = true;
      bCancel = true;
      break;
   case ::user::e_message_box_cancel_try_continue:
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


::particle * osmutex();

void android_exchange()
{

   auto pdriver = ::operating_system_driver::get();

   pdriver->exchange();

}


void android_edit_on_set_focus(int l, int t, int r, int b, const ::scoped_string & scopedstrText, int iBeg, int iEnd)
{

   synchronous_lock synchronouslock(osmutex());

   auto pdriver = ::operating_system_driver::get();

   pdriver->m_bEditFocusKill = false;

   pdriver->m_rectangleEditFocus.left() = l;
   pdriver->m_rectangleEditFocus.top() = t;
   pdriver->m_rectangleEditFocus.right() = r;
   pdriver->m_rectangleEditFocus.bottom() = b;

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
//void set_operating_system_direct(jni_bind* pdirect)
//{
//
//   g_pandroidbind = pdirect;
//
//}
//
//
//jni_bind* jni_bind::get()
//{
//
//   return g_pandroidbind;
//
//}
//
//
//::pointer<operating_system_driver>g_pandroiddriver;
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
