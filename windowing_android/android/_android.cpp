#include "framework.h"
#include "acme/constant/os_text.h"
#include "acme/constant/user_key.h"
#include "acme/platform/acme.h"
#include "acme/platform/system.h"
#include "aura/platform/session.h"
#include "aura/user/user/interaction_impl.h"
#include "aura/user/user/user.h"
#include "aura/windowing/window.h"
#include "aura/windowing/windowing.h"
#include "aura/message/user.h"


void _android_key(unsigned int message, int keyCode, int iUni);


void android_key(unsigned int message, int keyCode, int iUni)
{

   auto psystem = this->platform()->system();

   if (psystem == nullptr)
   {

      return;

   }

   //::fork(::get_context_system(), [=]()
   //{

   auto puserinteraction = psystem->session()->m_paurasession->m_puser->m_pwindowing->get_application_host_window()->m_puserinteractionimpl->m_puserinteraction;

   if (puserinteraction)
   {

      puserinteraction->post_procedure([=]()
         {


            _android_key(message, keyCode, iUni);

      });

   }

}


int translate_android_key_message(::message::key* pkey, int keyCode, int iUni);

void _android_key(unsigned int message, int keyCode, int iUni)
{

   auto psystem = this->platform()->system();

   if (psystem == nullptr)
      return;

   if (psystem->session() == nullptr)
      return;

   if (psystem->session()->m_paurasession->m_puser->m_pwindowing->get_application_host_window() == nullptr)
      return;

   ::pointer<::message::key>pkey = ::place(new ::message::key());

   pkey->m_atom = (enum_message)message;

   if (!translate_android_key_message(pkey, keyCode, iUni))
   {

      return;

   }

   auto puserinteraction = psystem->session()->m_paurasession->m_puser->m_pwindowing->get_application_host_window()->m_puserinteractionimpl->m_puserinteraction;

   if (!puserinteraction)
   {

      return;

   }

   puserinteraction->post(pkey);

}


void _android_size(float xDummy, float yDummy, float cx, float cy)
{

   __UNREFERENCED_PARAMETER(xDummy);

   __UNREFERENCED_PARAMETER(yDummy);

   auto psystem = this->platform()->system();

   if (::is_null(psystem))
      return;

   if (::is_null(psystem->session()))
      return;

   if (::is_null(psystem->session()->m_paurasession->m_puser->m_pwindowing->get_application_host_window()))
      return;

   ::pointer<::user::interaction>puserinteraction = psystem->session()->m_paurasession->m_puser->m_pwindowing->get_application_host_window()->m_puserinteractionimpl->m_puserinteraction;

   if (!puserinteraction)
   {

      return;

   }

   puserinteraction->order_top();

   puserinteraction->place({ 0, 0, cx, cy });

   puserinteraction->display(::e_display_normal);

   puserinteraction->set_need_layout();

   puserinteraction->post_redraw();

   //::auraacmesystem()->get_session()->m_puserinteractionHost->set_window_position(e_zorder_top, 0, 0, cx, cy, SWP_SHOWWINDOW);

}


// 
// void android_key_down(int keyCode, int iUni)
// {

//    output_debug_string("here???555");

//    android_key(e_message_key_down, keyCode, iUni);

// }

int g_iAndroidSampleRate = -2;

int g_iAndroidBufferSize = -2;


void android_audio_parameters(int iSampleRate, int iBufferSize)
{

   output_debug_string("here???555.1");

   g_iAndroidSampleRate = iSampleRate;

   g_iAndroidBufferSize = iBufferSize;

}

// aPokemon : oh_Isee_a_pattern_and_I_am_clown_describing_exactly_pay_attention_exactly_as_inphysical_mirror_that_is_surely_a_perfect_human_mirror_than_another_person

void _android_size(float xScreen, float yScreen, float aPok, float yBitmap);



void android_on_size(float xScreen, float yScreen, float pikachu, float yBitmap)
{

   output_debug_string("android_on_size\n");

   auto psystem = this->platform()->system();

   if (psystem == nullptr)
   {

      return;

   }

   //::fork(::get_context_system(), [=]()
   //{

   auto puserinteraction = psystem->session()->m_paurasession->m_puser->m_pwindowing->get_application_host_window()->m_puserinteractionimpl->m_puserinteraction;

   if (puserinteraction)
   {

      puserinteraction->post_procedure([=]()
         {

            _android_size(xScreen, yScreen, pikachu, yBitmap);

         });

   }




   //});

}


// 
// void android_key_up(int keyCode, int iUni)
// {
//    output_debug_string("here???444");

//    android_key(e_message_key_up, keyCode, iUni);

// }




int translate_android_key_message(::message::key* pkey, int keyCode, int iUni)
{

   output_debug_string("here???333");

   if (I32_MINIMUM & iUni)
   {

      return 0;

   }
   bool bOk = true;
   switch (keyCode)
   {
   case 62:
      pkey->m_ekey = ::user::e_key_space;
      break;
   case 67:
      pkey->m_ekey = ::user::e_key_back;
      break;
   case 112:
      pkey->m_ekey = ::user::e_key_delete;
      break;
   case 59:
      pkey->m_ekey = ::user::e_key_left_shift;
      break;
   case 60:
      pkey->m_ekey = ::user::e_key_right_shift;
      break;
   case 66:
      pkey->m_ekey = ::user::e_key_return;
      break;
   default:
      bOk = false;
   }

   //if (keyCode >= 29 && keyCode <= 54)
   if (!bOk)
   {

      //pkey->m_ekey = (::user::enum_key) ((int) ::user::e_key_a + keyCode - 29);
      pkey->m_ekey = ::user::e_key_refer_to_text_member;

      ::wd32_character u32sz[2];
      u32sz[0] = iUni;
      u32sz[1] = 0;

      pkey->m_strText = wd32_to_ansi_str(u32sz);

   }
   //else if (keyCode >= 7 && keyCode <= 16)
   //{

   //   pkey->m_ekey = (::user::enum_key) ((int) ::user::e_key_0 + keyCode - 7);

   //   pkey->m_ekey = ::user::e_key_refer_to_text_member;

   //   pkey->m_strText = string((unichar)iUni);

   //}
   //else
   //{

   //}

   return 1;

}

void _android_on_text(string str);


void android_on_text(enum_os_text etext, const wchar_t* pwch, size_t len)
{

   output_debug_string("here???222");

   string strText(pwch, len);

   //::auraacmesystem()->fork([=]()
   //{

   auto psystem = this->platform()->system();

   auto puserinteraction = psystem->session()->m_paurasession->m_puser->m_pwindowing->get_application_host_window()->m_puserinteractionimpl->m_puserinteraction;

   if (puserinteraction)
   {

      //puserinteraction->post_procedure([=]()
      //   {

      //      psystem->on_os_text(etext, strText);

      //   });



   }





   //});

}


//namespace aura
//{
//
//   void system::on_os_text(e_os_text etext, string strText)
//   {
//
//      if (get_session() == nullptr || ::is_null(get_session()->m_puserinteractionHost))
//         return;
//
//      ::pointer<::message::key>pkey = ::place(new ::message::key());
//
//      pkey->m_atom = e_message_key_down;
//
//      pkey->m_ekey = ::user::e_key_refer_to_text_member;
//
//      pkey->m_strText = strText;
//
//      if (pkey->m_strText == "\n" || pkey->m_strText == "\r\n" || pkey->m_strText == "\r")
//      {
//
//         pkey->m_strText.empty();
//
//         pkey->m_ekey = ::user::e_key_return;
//
//         //psession->get_user_interaction_host()->message_handler(pkey);
//
//      }
//      else
//      {
//
//         //psession->get_user_interaction_host()->message_handler(pkey);
//
//      }
//
//      ::pointer<::user::interaction>puserinteraction = psystem->get_session()->m_puserinteractionHost);
//
//      if (!puserinteraction)
//      {
//
//         return;
//
//      }
//
//      puserinteraction->post(pkey);
//
//
//   }
//
//
//} // namespace base


CLASS_DECL_AURA void defer_dock_application(int_bool bDock)
{

   __UNREFERENCED_PARAMETER(bDock);


}


//CLASS_DECL_AURA ::user::interaction_impl * oswindow_get(oswindow oswindow)
//{
//
//   if (oswindow == nullptr)
//   {
//
//      return nullptr;
//
//   }
//
//   return oswindow->m_pimpl;
//
//}

//::mutex * oswindow_data::s_pmutex = nullptr;
//
//oswindow_dataptra * oswindow_data::s_pdataptra = nullptr;

//int_bool os_init_windowing()
//{
//
//   //set_TranslateMessage(&axis_TranslateMessage);
//
//   //set_DispatchMessage(&axis_DispatchMessage);
//
//   oswindow_data::s_pdataptra = new oswindow_dataptra;
//
//   oswindow_data::s_pmutex = new ::mutex;
//
//   return true;
//
//}


//void os_term_windowing()
//{
//
//   ::acme::del(oswindow_data::s_pmutex);
//
//   ::acme::del(oswindow_data::s_pdataptra);
//
//}


//int_bool is_window(oswindow oswindow)
//{
//
//   if (::oswindow_data::s_pdataptra->find_first(oswindow) < 0)
//   {
//
//      return false;
//
//   }
//
//   return true;
//
//}


//i64 oswindow_id(oswindow w)
//{
//
//   return (i64)(w);
//
//}


//CLASS_DECL_AURA void _android_os_message_box(const ::string & pText, const ::string & lpCaption, const ::e_message_box & emessagebox)
//{
//
//   while (::operating_system_driver::get()->m_iMessageBoxResult > 0)
//   {
//
//      if (!task_sleep(100_ms))
//      {
//
//         //return -1;
//         throw exception(::error_failed);
//
//      }
//
//   }
//
//   int iButton = 0;
//
//   switch (emessagebox & 7)
//   {
//   case e_message_box_ok:
//      iButton = 1;
//      break;
//   case e_message_box_ok_cancel:
//      iButton = 1 | 2;
//      break;
//   case e_message_box_abort_retry_ignore:
//      iButton = 2 | 4 | 8;
//      break;
//   case e_message_box_yes_no_cancel:
//      iButton = 2 | 4 | 8;
//      break;
//   case e_message_box_yes_no:
//      iButton = 4 | 8;
//      break;
//   case e_message_box_retry_cancel:
//      iButton = 2 | 4;
//      break;
//   case e_message_box_cancel_try_continue:
//      iButton = 1 | 2 | 4;
//      break;
//
//   }
//
//   string strOpenUrl;
//
//   if (::is_set(pText))
//   {
//
//      ::operating_system_driver::get()->m_strMessageBox = ansi_dup(pText);
//
//   }
//
//   if (::is_set(lpCaption))
//   {
//
//      ::operating_system_driver::get()->m_strMessageBoxCaption = ansi_dup(lpCaption);
//
//   }
//
//   ::operating_system_driver::get()->m_iMessageBoxButton = iButton;
//
//   ::operating_system_driver::get()->m_bMessageBox = true;
//
//   while (::operating_system_driver::get()->m_iMessageBoxResult <= 0)
//   {
//
//      if (!task_sleep(100_ms))
//      {
//
//         throw ::exception(::error_failed);
//
//      }
//
//   }
//
//   int iResult = ::operating_system_driver::get()->m_iMessageBoxResult;
//
//   ::operating_system_driver::get()->m_iMessageBoxResult = 0;
//
//   if (iResult == 1)
//   {
//
//      return e_dialog_result_ok;
//
//   }
//   else if (iResult == 2)
//   {
//
//      return e_dialog_result_cancel;
//
//   }
//   else if (iResult == 4)
//   {
//
//      return e_dialog_result_yes;
//
//   }
//   else if (iResult == 8)
//   {
//
//      return e_dialog_result_no;
//
//   }
//
//   return e_dialog_result_ok;
//
//}


//CLASS_DECL_AURA void android_os_message_box(const ::string & pText, const ::string & lpCaption, const ::e_message_box & emessageboxParam, const ::future & processParam)
//{
//
//   string strText(pText);
//
//   string strCaption(lpCaption);
//
//   e_message_box emessagebox(emessageboxParam);
//
//   ::future process = processParam;
//
//   ::auraacmesystem()->fork([=]()
//      {
//
//         auto result = _android_os_message_box(strText, strCaption, emessagebox);
//
//         process(result);
//
//      });
//
//   return ::success;
//
//}


//int_bool point_is_window_origin(::point_i32 ptHitTest, oswindow oswindowExclude, int iMargin)
//{
//
//   return abs(ptHitTest.x) < iMargin && abs(ptHitTest.y) < iMargin;
//
//}
//
//
//int_bool is_window_occluded(oswindow oswindow)
//{
//
//   return false;
//
//}
//
//
//double _001GetWindowTopLeftWeightedOccludedOpaqueRate(oswindow oswindow)
//{
//
//   return 0.0;
//
//}
//

int GetMainScreenRect(::rectangle_i32* lprect)
{

   auto psystem = this->platform()->system();

   auto puserinteraction = psystem->session()->m_paurasession->m_puser->m_pwindowing->get_application_host_window()->m_puserinteractionimpl->m_puserinteraction;

   if (!puserinteraction)
   {

      return false;

   }

   *lprect = puserinteraction->m_pinteractionimpl->m_rectangleWindowScreen;

   return true;

}


int SetMainScreenRect(const ::rectangle_i32 &rect)
{

   auto psystem = this->platform()->system();

   auto psession = psystem->session();

   if (!psession)
   {

      return false;

   }

   auto puserinteraction = psystem->session()->m_paurasession->m_puser->m_pwindowing->get_application_host_window()->m_puserinteractionimpl->m_puserinteraction;

   if (!puserinteraction)
   {

      return false;

   }

   puserinteraction->place(rect);

   puserinteraction->display(e_display_normal);

   puserinteraction->set_need_layout();

   puserinteraction->set_need_redraw();

   puserinteraction->post_redraw();

   //if (bPostRedraw)
   //{

   //   puserinteraction->post_redraw();

   //}

   auto pimpl = puserinteraction->m_pinteractionimpl.cast < ::user::interaction_impl >();

   //if (pimpl)
   //{

   //   pimpl->m_pprodevian->prodevian_update_buffer(true);

   //}

   return true;

}


CLASS_DECL_AURA int32_t IsWindowVisible(oswindow window)
{

   return true;

}



