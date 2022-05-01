#include "framework.h"
#include <jni.h>
#include "acme/operating_system/android/_os_object.h"
#include "acme/operating_system/android/_os_remote.h"


void android_aura_main()
{

   auto premote = osremote();

   auto plocal = oslocal();

   string strApplicationIdentifier = plocal->m_strApplicationIdentifier;

   auto psystem = platform_create_system(strApplicationIdentifier);

   psystem->m_pathCacheDirectory = premote->getCacheDirectory();

   psystem->system_construct(plocal, e_display_default);

   //::e_status estatus = psystem->m_papexsystem->os_application_system_run();
   //
   //if (!estatus)
   //{

   //   printf("os_application_system_run failed\n");

   //   return;

   //}

   ::rectangle_i32 rectangle;

   rectangle.left = 0;
   rectangle.top = 0;
   rectangle.right = premote->getWidth();
   rectangle.bottom = premote->getHeight();

   auto psession = psystem->get_session();

   psession->defer_initialize_host_window(rectangle);

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

   //   //oslocal()->m_bRedraw = true;

   //}


}


::mutex * osmutex();

void android_exchange()
{

   synchronous_lock synchronouslock(osmutex());

   auto plocal = ::oslocal();

   auto premote = ::osremote();

   if (plocal->m_bHideKeyboard)
   {

      premote->setHideKeyboard(true);

      plocal->m_bHideKeyboard = false;

   }

   if (plocal->m_strOpenUrl.has_char())
   {

      premote->setOpenUrl(plocal->m_strOpenUrl);

      plocal->m_strOpenUrl.Empty();

   }

   if (plocal->m_bMessageBoxOn)
   {

      int iResult = premote->getMessageBoxResult();

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

            premote->setMessageBox(plocal->m_strMessageBox);

            plocal->m_strMessageBox.Empty();

         }

         if (plocal->m_strMessageBoxCaption.is_empty())
         {

            premote->setMessageBoxCaption(plocal->m_strMessageBoxCaption);

            plocal->m_strMessageBoxCaption.Empty();

         }

         premote->setMessageBoxButton(plocal->m_iMessageBoxButton);

         plocal->m_iMessageBoxButton = 0;

         premote->setShowMessageBox(1);

         plocal->m_bMessageBoxOn = true;

         plocal->m_bMessageBox = false;

      }

   }

   if (plocal->m_strSetUserWallpaper.has_char())
   {

      premote->setUserWallpaper(plocal->m_strSetUserWallpaper);

      plocal->m_strSetUserWallpaper.Empty();

   }

   if (plocal->m_bGetUserWallpaper)
   {

      plocal->m_strGetUserWallpaper = premote->getUserWallpaper();

      plocal->m_bGetUserWallpaper = false;

   }

   if (plocal->m_bEditorSelectionUpdated)
   {

      plocal->m_bEditorSelectionUpdated = false;

      premote->setEditorSelectionStart(plocal->m_iEditorSelectionStart);

      premote->setEditorSelectionEnd(plocal->m_iEditorSelectionEnd);

      premote->setEditorSelectionUpdated(true);

   }

   if (plocal->m_bEditorTextUpdated)
   {

      plocal->m_bEditorTextUpdated = false;

      premote->setEditorText(plocal->m_strEditorText);

      premote->setEditorTextUpdated(true);

   }

   if (plocal->m_bEditFocusSet)
   {

      plocal->m_bEditFocusSet = false;

      premote->setEditFocusSet(true);

      premote->setEditFocusLeft(plocal->m_rectangleEditFocus.left);

      premote->setEditFocusTop(plocal->m_rectangleEditFocus.top);

      premote->setEditFocusRight(plocal->m_rectangleEditFocus.right);

      premote->setEditFocusBottom(plocal->m_rectangleEditFocus.bottom);

   }

   if (plocal->m_bEditFocusKill)
   {

      plocal->m_bEditFocusKill = false;

      premote->setEditFocusKill(true);

   }

   if (plocal->m_bRedraw)
   {

      plocal->m_bRedraw = false;

      premote->setRedraw(true);

   }

   if (plocal->m_bInputMethodManagerUpdateSelection)
   {

      plocal->m_bInputMethodManagerUpdateSelection = false;

      premote->setInputMethodManagerSelectionStart(plocal->m_iInputMethodManagerSelectionStart);

      premote->setInputMethodManagerSelectionEnd(plocal->m_iInputMethodManagerSelectionEnd);

      premote->setInputMethodManagerCandidateStart(plocal->m_iInputMethodManagerCandidateStart);

      premote->setInputMethodManagerCandidateEnd(plocal->m_iInputMethodManagerCandidateEnd);

      premote->setInputMethodManagerUpdateSelection(true);

   }


   if (plocal->m_bShowKeyboard)
   {

      premote->setShowKeyboard(true);

      plocal->m_bShowKeyboard = false;

   }

}


void android_edit_on_set_focus(int l, int t, int r, int b, const ::string & pszText, int iBeg, int iEnd)
{

   synchronous_lock synchronouslock(osmutex());

   auto plocal = ::oslocal();

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

   auto plocal = ::oslocal();

   plocal->m_bEditFocusKill = true;

   plocal->m_bEditFocusSet = false;

}



