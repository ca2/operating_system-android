#include "framework.h"
#include "_operating_system.h"


void android_aura_main()
{

   auto pdirect = operating_system_direct::get();

   auto pdriver = operating_system_driver::get();

   string strApplicationIdentifier = pdriver->m_strApplicationIdentifier;

   auto psystem = platform_create_system(strApplicationIdentifier);

   psystem->m_pathCacheDirectory = pdirect->getCacheDirectory();

   psystem->system_construct("", e_display_default);

   //psystem->system_construct(plocal, e_display_default);

   //::e_status estatus = psystem->m_papexsystem->os_application_system_run();
   //
   //if (!estatus)
   //{

   //   printf("os_application_system_run failed\n");

   //   return;

   //}


   ::procedure procedure([psystem,pdirect]()
      {
         ::rectangle_i32 rectangle;

         rectangle.left = 0;
         rectangle.top = 0;
         rectangle.right = pdirect->getWidth();
         rectangle.bottom = pdirect->getHeight();

         auto psession = psystem->get_session();

         psession->defer_initialize_host_window(rectangle);

      });

   psystem->payload("on_finish_launching1") = procedure.m_p;



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


}


::mutex * osmutex();

void android_exchange()
{

   synchronous_lock synchronouslock(osmutex());

   auto plocal = ::operating_system_driver::get();

   auto pdirect = ::operating_system_direct::get();

   if (plocal->m_bHideKeyboard)
   {

      pdirect->setHideKeyboard(true);

      plocal->m_bHideKeyboard = false;

   }

   if (plocal->m_strOpenUrl.has_char())
   {

      pdirect->setOpenUrl(plocal->m_strOpenUrl);

      plocal->m_strOpenUrl.Empty();

   }

   if (plocal->m_bMessageBoxOn)
   {

      int iResult = pdirect->getMessageBoxResult();

      if (iResult > 0)
      {

         plocal->m_bMessageBoxOn = false;

      }

   }
   else
   {

      if (plocal->m_bMessageBox)
      {

         if (plocal->m_strMessageBox.has_char())
         {

            pdirect->setMessageBox(plocal->m_strMessageBox);

            plocal->m_strMessageBox.Empty();

         }

         if (plocal->m_strMessageBoxCaption.is_empty())
         {

            pdirect->setMessageBoxCaption(plocal->m_strMessageBoxCaption);

            plocal->m_strMessageBoxCaption.Empty();

         }

         pdirect->setMessageBoxButton(plocal->m_iMessageBoxButton);

         plocal->m_iMessageBoxButton = 0;

         pdirect->setShowMessageBox(1);

         plocal->m_bMessageBoxOn = true;

         plocal->m_bMessageBox = false;

      }

   }

   if (plocal->m_strSetUserWallpaper.has_char())
   {

      pdirect->setUserWallpaper(plocal->m_strSetUserWallpaper);

      plocal->m_strSetUserWallpaper.Empty();

   }

   if (plocal->m_bGetUserWallpaper)
   {

      plocal->m_strGetUserWallpaper = pdirect->getUserWallpaper();

      plocal->m_bGetUserWallpaper = false;

   }

   if (plocal->m_bEditorSelectionUpdated)
   {

      plocal->m_bEditorSelectionUpdated = false;

      pdirect->setEditorSelectionStart(plocal->m_iEditorSelectionStart);

      pdirect->setEditorSelectionEnd(plocal->m_iEditorSelectionEnd);

      pdirect->setEditorSelectionUpdated(true);

   }

   if (plocal->m_bEditorTextUpdated)
   {

      plocal->m_bEditorTextUpdated = false;

      pdirect->setEditorText(plocal->m_strEditorText);

      pdirect->setEditorTextUpdated(true);

   }

   if (plocal->m_bEditFocusSet)
   {

      plocal->m_bEditFocusSet = false;

      pdirect->setEditFocusSet(true);

      pdirect->setEditFocusLeft(plocal->m_rectangleEditFocus.left);

      pdirect->setEditFocusTop(plocal->m_rectangleEditFocus.top);

      pdirect->setEditFocusRight(plocal->m_rectangleEditFocus.right);

      pdirect->setEditFocusBottom(plocal->m_rectangleEditFocus.bottom);

   }

   if (plocal->m_bEditFocusKill)
   {

      plocal->m_bEditFocusKill = false;

      pdirect->setEditFocusKill(true);

   }

   if (plocal->m_bRedraw)
   {

      plocal->m_bRedraw = false;

      pdirect->setRedraw(true);

   }

   if (plocal->m_bInputMethodManagerUpdateSelection)
   {

      plocal->m_bInputMethodManagerUpdateSelection = false;

      pdirect->setInputMethodManagerSelectionStart(plocal->m_iInputMethodManagerSelectionStart);

      pdirect->setInputMethodManagerSelectionEnd(plocal->m_iInputMethodManagerSelectionEnd);

      pdirect->setInputMethodManagerCandidateStart(plocal->m_iInputMethodManagerCandidateStart);

      pdirect->setInputMethodManagerCandidateEnd(plocal->m_iInputMethodManagerCandidateEnd);

      pdirect->setInputMethodManagerUpdateSelection(true);

   }


   if (plocal->m_bShowKeyboard)
   {

      pdirect->setShowKeyboard(true);

      plocal->m_bShowKeyboard = false;

   }

}


void android_edit_on_set_focus(int l, int t, int r, int b, const ::string & pszText, int iBeg, int iEnd)
{

   synchronous_lock synchronouslock(osmutex());

   auto plocal = ::operating_system_driver::get();

   plocal->m_bEditFocusKill = false;

   plocal->m_rectangleEditFocus.left = l;
   plocal->m_rectangleEditFocus.top = t;
   plocal->m_rectangleEditFocus.right = r;
   plocal->m_rectangleEditFocus.bottom = b;

   plocal->m_iEditorSelectionStart = iBeg;
   plocal->m_iEditorSelectionEnd = iEnd;
   plocal->m_bEditorSelectionUpdated = true;

   plocal->m_strEditorText = pszText;
   plocal->m_bEditorTextUpdated = true;

   plocal->m_bEditFocusSet = true;

}


void android_edit_on_kill_focus()
{

   synchronous_lock synchronouslock(osmutex());

   auto plocal = ::operating_system_driver::get();

   plocal->m_bEditFocusKill = true;

   plocal->m_bEditFocusSet = false;

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
