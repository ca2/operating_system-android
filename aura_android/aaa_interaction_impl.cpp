#include "framework.h"
#include "aaa_interaction_impl.h"
#include "acme/constant/message.h"
#include "acme/parallelization/synchronous_lock.h"
#include "aura/user/user/frame_interaction.h"
#include "aura/windowing/window.h"
#include "aura/windowing/windowing.h"
#include "acme/operating_system/cross.h"
//#include "aura/operating_system/android/windowing.h"
#include "aura/windowing/text_editor_interface.h"


CLASS_DECL_AURA ::particle * osmutex();


void android_edit_on_set_focus(int l, int t, int r, int b, const ::string & pszText, int iBeg, int iEnd);
void android_edit_on_kill_focus();


CLASS_DECL_AURA int g_iMouseDown = 0;


namespace aura_android
{


   interaction_impl::interaction_impl() 
   {

      m_bScreenRelativeMouseMessagePosition = true;
      //m_oswindow           = nullptr;
      //m_bMouseHover        = false;
      m_bUpdateGraphics    = false;
      //m_bEnabled           = true;
      m_pthreadDraw = nullptr;

      //zero(m_rectangleParentClient);
      zero(m_size);
      zero(m_point);



   }




   //void interaction_impl::construct(oswindow oswindow)
   //{

   //   m_bScreenRelativeMouseMessagePosition = true;
   //   m_oswindow           = nullptr;
   //   //m_bMouseHover        = false;
   //   m_bUpdateGraphics    = false;
   //   m_bEnabled           = true;
   //   m_pthreadDraw = nullptr;
   //   //zero(m_rectangleParentClient);
   //   zero(m_size);
   //   zero(m_point);

   //   set_handle(oswindow);

   //}


   //interaction_impl::interaction_impl(::particle * pparticle):
   //   ::object(pobject)
   //{
   //   m_bScreenRelativeMouseMessagePosition = true;
   //   //  m_bScreenRelativeMouseMessagePosition = false;
   //   m_oswindow           = nullptr;
   //   m_bUpdateGraphics    = false;
   //   m_bIgnoreSizeEvent   = false;
   //   m_bIgnoreMoveEvent   = false;
   //   m_bEnabled           = true;
   //   m_pthreadDraw = nullptr;
   //   zero(m_rectangleParentClient);
   //   zero(m_size);
   //   zero(m_point);

   //}


   interaction_impl::~interaction_impl()
   {

      //if(get_session() != nullptr)
      //{

      //   if(system()->m_pwindowmap != nullptr)
      //   {

      //      system()->m_pwindowmap->m_map.erase_key(get_handle());

      //   }

      //}

   }


   //::windowing::window * interaction_impl::from_os_data(void * pdata)
   //{

   //   return from_handle((oswindow)pdata);

   //}


   //void * interaction_impl::get_os_data() const
   //{

   //   return (void *)get_handle();

   //}



   // Change a interaction_impl's style

   //__STATIC bool CLASS_DECL_AURA __modify_style(oswindow oswindow,int nStyleOffset,
   //      unsigned int dwRemove,unsigned int dwAdd,unsigned int nFlags)
   //{
   //   ASSERT(oswindow != nullptr);
   //   unsigned int dwStyle = ::GetWindowLong(oswindow,nStyleOffset);
   //   unsigned int dwNewStyle = (dwStyle & ~dwRemove) | dwAdd;
   //   if(dwStyle == dwNewStyle)
   //      return false;

   //   ::SetWindowLong(oswindow,nStyleOffset,dwNewStyle);
   //   if(nFlags != 0)
   //   {
   //      ::SetWindowPos(oswindow,nullptr,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE | nFlags);
   //   }
   //   return true;
   //}


   //bool interaction_impl::ModifyStyle(oswindow oswindow,unsigned int dwRemove,unsigned int dwAdd,unsigned int nFlags)
   //{

   //   //return __modify_style(oswindow,GWL_STYLE,dwRemove,dwAdd,nFlags);

   //   return ::user

   //}


   //bool interaction_impl::ModifyStyleEx(oswindow oswindow,unsigned int dwRemove,unsigned int dwAdd,unsigned int nFlags)
   //{

   //   return __modify_style(oswindow,GWL_EXSTYLE,dwRemove,dwAdd,nFlags);

   //}


   //LRESULT interaction_impl::Default()
   //{

   //   return 0;

   //}


   //::user::interaction * interaction_impl::FromHandlePermanent(oswindow oswindow)
   //{

   //   if (oswindow->get_impl() == nullptr)
   //   {

   //      return nullptr;

   //   }

   //   return oswindow->get_impl()->m_puserinteraction;

   //}


   //bool interaction_impl::Attach(oswindow hWndNew)
   //{

   //   ASSERT(get_handle() == nullptr);

   //   if (hWndNew == nullptr)
   //      return false;

   //   m_oswindow = hWndNew;

   //   return true;

   //}


   //oswindow interaction_impl::Detach()
   //{

   //   oswindow hwnd = (oswindow)get_handle();

   //   if (hwnd != nullptr)
   //   {

   //      m_oswindow = nullptr;

   //   }

   //   return hwnd;

   //}


   void interaction_impl::pre_subclass_window()
   {


   }


   //void interaction_impl::native_create_host()
   //{

   //   //      auto pwindowMain = system()->m_pwindowMain;
   //   //
   //   //      if (pwindowMain && !pwindowMain->m_pwindow)
   //   //      {
   //   //
   //   //         m_pwindow = system()->m_pwindowMain;
   //   //
   //   //         m_pwindow->m_pwindow = this;
   //   //
   //   //         m_puserinteraction->m_pinteractionimpl = this;
   //   //
   //   //      }
   //   //      else
   //   //      {
   //   //
   //   //         //auto estatus =
   //   //
   //   //         __construct(m_pwindow);
   //   //
   //   //         //if (!estatus)
   //   //         //{
   //   //
   //   //         //   return estatus;
   //   //
   //   //         //}
   //   //
   //   //         if (!system()->m_pwindowMain)
   //   //         {
   //   //
   //   //            system()->m_pwindowMain = m_pwindow;
   //   //
   //   //         }
   //   //
   //   //      }
   //   //
   //   //      //auto estatus =
   //   //
   //   //      m_pwindow->create_window(this);
   //   //
   //   //      //if (!estatus)
   //   //      //{
   //   //
   //   //      //   return estatus;
   //   //
   //   //      //}
   //   //
   //   //      //return true;

   //   ::pointer<::user::system>pusersystem;

   //   if (m_puserinteraction->m_pusersystem)
   //   {

   //      pusersystem = m_puserinteraction->m_pusersystem;

   //   }
   //   else
   //   {

   //      pusersystem = __allocate ::user::system();

   //   }

   //   //      ENSURE_ARG(pusersystem->m_createstruct.lpszName == nullptr || is_string_ok(pusersystem->m_createstruct.lpszName));
   //   //
   //   if (!m_puserinteraction->pre_create_window(pusersystem))
   //   {

   //      //return false;

   //      throw ::exception(error_failed);

   //   }

   //   __refer(m_puserinteraction->m_pthreadUserInteraction, ::get_task());

   //   //m_pthreadUserImpl = m_puserinteraction->m_pthreadUserInteraction;

   //   install_message_routing(m_puserinteraction);

   //   bool bOk = true;

   //   //      if(pusersystem->m_createstruct.hwndParent == (oswindow) MESSAGE_WINDOW_PARENT)
   //   //      {
   //   //
   //   //         auto pwindowing = m_pwindowwindowing();
   //   //
   //   //         m_oswindow = pwindowing->new_message_window(this);
   //   //
   //   //         m_puserinteraction->m_bMessageWindow = true;
   //   //
   //   //         //send_message(e_message_create, 0, (LPARAM) &cs);
   //   //
   //   //      }
   //   //      else
   //   {

   //      m_puserinteraction->m_bMessageWindow = false;

   //      

   //      auto puser = user();

   //      auto pwindowing = system()->windowing();

   //      //pwindowing->windowing_send([&]()
   //      //   {

   //      //      

   //      //      auto puser = user();

   //      //      auto pwindowing = system()->windowing();

   //            m_pwindow = pwindowing->new_window(this);

   //            if (m_pwindow)
   //            {

   //               output_debug_string("window created");

   //            }
   //            else
   //            {

   //               output_debug_string("window not created");

   //            }

   //         //});

   //   }

   //   //      if(bOk)
   //   //      {
   //   //
   //   //         m_puserinteraction->send_message(e_message_create, 0, (lparam) &pusersystem->m_createstruct);
   //   //
   //   //         m_puserinteraction->m_ewindowflag |= e_window_flag_window_created;
   //   //
   //   //      }

   //   if (!bOk)
   //   {

   //      throw ::exception(error_failed);

   //   }





   //}


//   bool interaction_impl::create_window_ex(::user::interaction * pinteraction, ::pointer<::user::system>pusersystem, ::user::primitive * puiParent, atom atom)
//   {
//
//      auto oswindow = puiParent ? puiParent->get_safe_handle() : nullptr;
//
//      if(puiParent == nullptr)
//      {
//
//         if(!native_create_window_ex(pinteraction, pusersystem, oswindow, atom))
//         {
//
//            return false;
//
//         }
//
//      }
//      else
//      {
//
//         if(!native_create_window_ex(pinteraction, pusersystem, oswindow, atom))
//         {
//
//            return false;
//
//         }
//
//      }
//
//      return true;
//
//   }
//
//
//   bool interaction_impl::_native_create_window_ex(::pointer<::user::system>pusersystem)
//   {
//
////      throw ::exception(error_not_implemented, "no multiple native windows per application"));
//
////      return false;
//
//      ENSURE_ARG(pusersystem->m_createstruct.lpszClass == nullptr || is_string_ok(pusersystem->m_createstruct.lpszClass));
//
//      m_puserinteraction->m_pimpl = this;
//
//      m_puserinteraction->m_pimplBase = this;
//
//      if (pusersystem->m_createstruct.hwndParent == HWND_MESSAGE)
//      {
//
//         m_puserinteraction->m_bMessageWindow = true;
//
//         return true;
//
//      }
//      else
//      {
//
//         m_puserinteraction->m_bMessageWindow = false;
//
//         m_oswindow = oswindow_get(this);
//
//         m_puserinteraction->ModifyStyle(0, WS_VISIBLE);
//
//         ::int_rectangle rectangleCreate;
//
//         pusersystem->get_rect(rectangleCreate);
//
//         m_puserinteraction->place(rectangleCreate);
//
//         m_puserinteraction->display(e_display_full_screen);
//
//         //::e_status estatus = __construct(m_pgraphics);
//
//         //if (!estatus)
//         //{
//
//         //   return false;
//
//         //}
//
//         //m_pgraphics->initialize_graphics_graphics(this);
//         
//         m_oswindow->m_pimpl = this;
//
//      }
//
//      set_handle(m_oswindow);
//
//      if(m_oswindow == nullptr)
//      {
//
//         if (get_app() == nullptr)
//         {
//
//            post_non_client_destroy();
//
//            m_puserinteraction = nullptr;
//
//            return false;
//
//         }
//
//         ::e_status estatusLast = get_last_status();
//
//         //string strLastError = FormatMessageFromSystem(dwLastError);
//
//         string strMessage;
//
//         strMessage.formatf("::auraacmesystem() Error Code: %d", estatusLast);
//
//         //strMessage.formatf("%s\n\n::auraacmesystem() Error Code: %d",strLastError.c_str(),dwLastError);
//
//         informationf("Warning: Window creation failed: get_last_error returned:\n");
//
//         informationf("%s\n", strMessage.c_str());
//
//         try
//         {
//
//         /*   if(estatusLast == 0x0000057e.succeeded())
//            {
//
//               informationf("Cannot create a top-level child interaction_impl.");
//
//            }
//            else
//            {
//
//               informationf("%s", strMessage.c_str());
//
//            }*/
//
//         }
//         catch(...)
//         {
//
//         }
//
//      }
//
//      if(m_oswindow == nullptr)
//      {
//
//         post_non_client_destroy();
//
//         m_puserinteraction = nullptr;
//
//         return false;
//
//      }
//
//      install_message_routing(m_puserinteraction);
//
//      m_puserinteraction->__refer(m_puserinteraction->m_pthreadUserInteraction, ::get_task());
//
//      if (m_puserinteraction->m_pthreadUserInteraction != nullptr)
//      {
//
//         if (m_puserinteraction->m_pthreadUserInteraction->m_puiptraThread == nullptr)
//         {
//
//            m_puserinteraction->m_pthreadUserInteraction->m_puiptraThread = ___new user_interaction_ptr_array();
//
//         }
//
//         m_puserinteraction->m_pthreadUserInteraction->m_puiptraThread->add(m_puserinteraction);
//
//      }
//
//      output_debug_string("android_interaction_impl send e_message_create");
//
//      m_puserinteraction->send_message(e_message_create, 0, (::lparam)&pusersystem->m_createstruct);
//
//      m_puserinteraction->send_message(e_message_size);
//
//      if(m_oswindow != get_handle())
//      {
//
//         ASSERT(false); // should have been set in send msg hook
//
//      }
//
//      m_puserinteraction->m_ewindowflag |= e_window_flag_window_created;
//
//      m_puserinteraction->m_bTaskStarted = true;
//
//      return true;
//
//   }


   //bool interaction_impl::create_native_window(::user::native_window_initialize * pinitialize)
   //{

   //   m_oswindow = oswindow_get(this);

   //   m_oswindow->set_impl(this);

   //   install_message_routing(this);

   //   m_puserinteraction->set_window_position(e_zorder_top, pinitialize->m_rectangle, SWP_SHOWWINDOW);

   //   m_puserinteraction->ModifyStyle(0, WS_VISIBLE);

   //   output_debug_string("android_interaction_impl m_spgraphics alloc");

   //   //m_spgraphics.create(this);

   //   //m_spgraphics->on_create_window(this);

   //   m_puserinteraction->ModifyStyle(0, WS_VISIBLE);

   //   m_puserinteraction->send_message(e_message_create);

   //   m_puserinteraction->send_message(e_message_size);

   //   m_puserinteraction->send_message(e_message_move);

   //   m_puserinteraction->send_message(e_message_show_window, 1);

   //   output_debug_string("android_interaction_impl on _create_window");

   //   output_debug_string("android_interaction_impl initialize (width=" + __string(width(pinitialize->m_rectangle)) + ",height=" + __string(height(pinitialize->m_rectangle)) + ")");

   //   return true;

   //}


   // for child android
   bool interaction_impl::pre_create_window(::user::system * pusersystem)
   {

      return true;

   }


   //bool interaction_impl::create_window(::user::interaction * pinteraction, const ::string & lpszClassName, const ::string & lpszWindowName, unsigned int dwStyle, const ::int_rectangle & rectangle, ::user::primitive * pParentWnd, atom atom, ::request * prequest)
   //{

   //   // can't use for desktop or pop-up android (use create_window_ex instead)
   //   // can't use for desktop or pop-up windows (use create_window_ex instead)
   //   ASSERT(pParentWnd != nullptr);
   //   ASSERT((dwStyle & WS_POPUP) == 0);

   //   auto pusersystem = __allocate ::user::system();

   //   pusersystem->m_createstruct.dwExStyle = 0;
   //   pusersystem->m_createstruct.lpszClass = lpszClassName;
   //   pusersystem->m_createstruct.lpszName = lpszWindowName;
   //   pusersystem->m_createstruct.style = dwStyle | WS_CHILD;
   //   pusersystem->m_createstruct.x = rectangle.left();
   //   pusersystem->m_createstruct.y = rectangle.top();
   //   pusersystem->m_createstruct.cx = width(rectangle);
   //   pusersystem->m_createstruct.cy = height(rectangle);
   //   pusersystem->m_createstruct.hwndParent = pParentWnd->get_safe_handle();
   //   pusersystem->m_createstruct.lpCreateParams = (LPVOID)pcreate;

   //   return create_window_ex(pinteraction, pusersystem, pParentWnd, atom);

   //}


   // bool interaction_impl::create_message_queue(::user::interaction * pinteraction, const ::string & pszName)
   // {

   //    if(m_puserinteraction->is_window())
   //    {

   //       DestroyWindow();

   //    }

   //    ::user::system createstruct(0, nullptr, pszName, WS_CHILD, ::int_rectangle());

   //    pusersystem->m_createstruct.hwndParent = HWND_MESSAGE;

   //    if(!native_create_window_ex(pinteraction, createstruct))
   //    {

   //       return false;

   //    }

   //    return true;

   // }


   void interaction_impl::install_message_routing(::channel * pchannel)
   {

      last_install_message_routing(pchannel);
      ::windowing::window::install_message_routing(pchannel);

      if(!m_puserinteraction->m_bMessageWindow)
      {
         MESSAGE_LINK(e_message_paint, pchannel, this,&interaction_impl::_001OnPaint);
         //MESSAGE_LINK(e_message_print, pchannel, this,&interaction_impl::_001OnPrint);
      }
      m_puserinteraction->install_message_routing(pchannel);
      MESSAGE_LINK(e_message_create, pchannel, this,&interaction_impl::on_message_create);
      if(!m_puserinteraction->m_bMessageWindow)
      {

         //MESSAGE_LINK(e_message_set_cursor, pchannel, this,&interaction_impl::on_message_set_cursor);

         //MESSAGE_LINK(e_message_erase_background, pchannel, this,&interaction_impl::_001OnEraseBkgnd);

         MESSAGE_LINK(e_message_size, pchannel, this,&interaction_impl::on_message_size);

         //MESSAGE_LINK(e_message_window_position_changing, pchannel, this,&interaction_impl::_001OnWindowPosChanging);
         //MESSAGE_LINK(e_message_window_position_changed, pchannel, this,&interaction_impl::_001OnWindowPosChanged);
         //MESSAGE_LINK(WM_GETMINMAXINFO, pchannel, this,&interaction_impl::_001OnGetMinMaxInfo);

//         MESSAGE_LINK(e_message_show_window, pchannel, this,&interaction_impl::on_message_show_window);

         //MESSAGE_LINK(ca2m_PRODEVIAN_SYNCH, pchannel, this,&interaction_impl::_001OnProdevianSynch);

         prio_install_message_routing(pchannel);

      }

      MESSAGE_LINK(e_message_destroy, pchannel, this,&interaction_impl::on_message_destroy);

      //MESSAGE_LINK(e_message_non_client_calc_size, pchannel, this,&interaction_impl::on_message_non_client_calculate_size);

   }

//   void interaction_impl::win_update_graphics()
//   {
//
//      single_lock synchronouslock(m_puserinteraction->mutex(),false);
//
//      if(!synchronouslock.lock())
//      {
//         m_bUpdateGraphics = true;
//         return;
//      }
//
//      m_bUpdateGraphics = false;
//
//      ::int_rectangle rectangleWindow;
//
//      m_puserinteraction->window_rectangle(rectangleWindow);
//
//      m_point = rectangleWindow.top_left();
//
//      if (rectangleWindow.area() <= 0)
//      {
//
//         return;
//
//      }
//
//      if(m_size != rectangleWindow.size())
//      {
//
//         m_size = rectangleWindow.size();
//
//      }
//
//   }
//
//
//
//
//   void interaction_impl::on_message_destroy(::message::message * pmessage)
//   {
//
//      __UNREFERENCED_PARAMETER(pmessage);
//
//      //::parallelization::post_quit_and_wait(m_pprodevian, seconds(10));
//
//      //if (m_puserinteraction->m_pthreadUserInteraction != nullptr)
//      //{
//
//         //m_puserinteraction->m_pthreadUserInteraction->m_puiptraThread->erase(m_puserinteraction);
//
//      //}
//
//      Default();
//
//   }
//
//
//   void interaction_impl::on_message_non_client_calculate_size(::message::message * pmessage)
//   {
//
//      ::pointer<::user::message>pusermessage(pmessage);
//
//      pusermessage->set_lresult(0);
//
//      pmessage->m_bRet = true;
//
//   }
//
//
//   void interaction_impl::post_non_client_destroy()
//   {
//
//      //single_lock synchronouslock(m_puserinteraction->get_app()->mutex(), true);
//
//      //::windowing::window * pwindow;
//
//      //::thread* pthread = ::get_thread();
//
//      //if (pthread != nullptr)
//      //{
//
//      //   if (pthread->get_active_ui() == m_puserinteraction)
//      //   {
//
//      //      pthread->set_active_ui(nullptr);
//
//      //   }
//
//      //}
//
//      //detach();
//
//      //ASSERT(get_handle() == nullptr);
//
//      //set_handle(nullptr);
//
//      ::windowing::window::post_non_client_destroy();
//
//   }
//
//
//   //void interaction_impl::on_final_release()
//   //{
//   //   
//   //   //if(get_handle() != nullptr)
//   //   //   DestroyWindow();    // will call post_non_client_destroy
//   //   //else
//   //   //   post_non_client_destroy();
//
//   //}
//
//
//   void interaction_impl::assert_ok() const
//   {
//      //if(((::android::interaction_impl *)this)->get_handle() == nullptr)
//      //   return;     // null (unattached) android are valid
//
//      // check for special wnd??? values
/////      ASSERT(HWND_TOP == nullptr);       // same as desktop
//      //if(((::android::interaction_impl *)this)->get_handle() == HWND_BOTTOM)
//      //{
//      //}
//      //else if(((::android::interaction_impl *)this)->get_handle() == HWND_TOPMOST)
//      //{
//      //}
//      //else if(((::android::interaction_impl *)this)->get_handle() == HWND_NOTOPMOST)
//      //{
//      //}
//      //else
//      //{
//      //   // should be a normal interaction_impl
//      //   ASSERT(::is_window(((::android::interaction_impl *)this)->get_handle()));
//
//      //}
//   }
//
//
//   void interaction_impl::dump(dump_context & dumpcontext) const
//   {
//      
//      object::dump(dumpcontext);
//
//      //dumpcontext << "\nm_oswindow_ = " << ((::android::interaction_impl *)this)->get_handle();
//
//   }


//   void interaction_impl::on_set_parent(::user::interaction * pinteraction)
//   {
//
//      if(pinteraction != nullptr)
//      {
//
//         detach();
//
//      }
//
//   }
//
//
//   //bool interaction_impl::DestroyWindow()
//   //{
//
//   //   bool bResult = false;
//
//   //   if (get_handle() != nullptr)
//   //   {
//
//   //      bResult = ::destroy_window(get_handle()) != false;
//
//   //   }
//
//   //   return bResult;
//
//   //}
//
//
//   LRESULT interaction_impl::DefWindowProc(::enum_message emessage, ::wparam wparam, ::lparam lparam)
//   {
//
//      return 0;
//
//   }
//
//
   
   
   void interaction_impl::pre_translate_message(::message::message * pmessage)
   {
      
      ::windowing::window::pre_translate_message(pmessage);

      //__UNREFERENCED_PARAMETER(pmessage);
      // no default processing
   }



   void interaction_impl::route_command(::message::command * pcommand, bool bRouteToKeyDescendant)
   {

      channel::route_command(pcommand);

      if (pcommand->m_bRet)
      {

         return;

      }

      //      bool b;

      //if(_iguimessageDispatchCommandMessage(pcommand, b))
      // return b;

      channel * pcmdtarget = dynamic_cast <channel *> (this);

      pcmdtarget->channel::route_command(pcommand);

   }


   //void interaction_impl::_002OnDraw(::image::image * pimage)
   //{

   //   throw ::interface_only();
   //   //::CallWindowProc(*GetSuperWndProcAddr(), get_handle(), WM_PRINT, (WPARAM)((dynamic_cast<::android::graphics * >(pgraphics))->get_handle()), (LPARAM)(PRF_CHILDREN | PRF_CLIENT));

   //}


   void interaction_impl::message_handler(::message::message * pmessage)
   {

      ::windowing::window::message_handler(pmessage);

      return;

//      if(pmessage->m_emessage == e_message_size || pmessage->m_emessage == e_message_move)
//      {
//
//         //win_update_graphics();
//
//      }
//
//      if(pmessage->m_emessage == e_message_key_down ||
//            pmessage->m_emessage == e_message_key_up ||
//            pmessage->m_emessage == e_message_char ||
//            pmessage->m_emessage == e_message_sys_key_down ||
//            pmessage->m_emessage == e_message_sys_key_up ||
//            pmessage->m_emessage == e_message_sys_char)
//      {
//
//         auto pkey = pmessage->m_union.m_pkey;
//
//         
//
//         if(pmessage->m_emessage == e_message_key_down || pmessage->m_emessage == e_message_sys_key_down)
//         {
//            try
//            {
//               psession->set_key_pressed(pkey->m_ekey,true);
//            }
//            catch(...)
//            {
//            }
//         }
//         else if(pmessage->m_emessage == e_message_key_up || pmessage->m_emessage == e_message_sys_key_up)
//         {
//            try
//            {
//               psession->set_key_pressed(pkey->m_ekey,false);
//            }
//            catch(...)
//            {
//            }
//         }
//      }
//
//
//
//      if(m_puserinteraction != nullptr)
//      {
//         if(m_puserinteraction->layout().is_moving())
//         {
//            //informationf("moving: skip pre translate message");
//         }
//         else if(m_puserinteraction->layout().is_sizing())
//         {
//            //informationf("sizing: skip pre translate message");
//         }
//         else
//         {
//            m_puserinteraction->pre_translate_message(pmessage);
//            if(pmessage->m_bRet)
//               return;
//
//         }
//      }
//
//      
//
//      if(pmessage->m_emessage == e_message_timer)
//      {
////         m_puserinteraction->get_app()->step_timer();
//      }
//      else if(pmessage->m_emessage == e_message_left_button_down)
//      {
//         //::int_rectangle rectangleX;
//         //::this->rectangle(get_handle(),rectangleX);
//         //::int_rectangle rectangleWindow;
//         //::window_rectangle(get_handle(),rectangleWindow);
//         //::int_rectangle rectangleRegion;
//         //HRGN hrgn = CreateRectRgn(0,0,0,0);
//         //int regionType = ::GetWindowRgn(get_handle(),hrgn);
//         //if(regionType != ERROR)
//         //{
//         //   ::GetRgnBox(hrgn,rectangleRegion);
//         //}
//         //::DeleteObject(hrgn); /* finished with region */
//         //WINDOWPLACEMENT wp;
//         //zero(wp);
//         //wp.length = sizeof(WINDOWPLACEMENT);
//         //::GetWindowPlacement(get_handle(),&wp);
//         //bool bZoomed = ::IsZoomed(get_handle()) != false;
//         //bool bIconic = ::IsIconic(get_handle()) != false;
//         psession->m_puiLastLButtonDown = m_puserinteraction;
//      }
//      /*      else if(pusermessage->id() == CA2M_BERGEDGE)
//      {
//      if(pusermessage->m_wparam == BERGEDGE_GETAPP)
//      {
//      ::pointer<::aura::application> ppapp= (::pointer<::aura::application> pusermessage->m_lparam;
//      *ppapp = get_app();
//      pusermessage->m_bRet = true;
//      return;
//      }
//      }*/
//      pmessage->set_lresult(0);
//
//      if(pmessage->m_emessage == e_message_mouse_leave)
//      {
//
//         _000OnMouseLeave(pmessage);
//
//         return;
//
//      }
//
//      if(pmessage->m_emessage == e_message_left_button_down ||
//            pmessage->m_emessage == e_message_left_button_up ||
//            pmessage->m_emessage == e_message_middle_button_down ||
//            pmessage->m_emessage == e_message_middle_button_up ||
//            pmessage->m_emessage == e_message_right_button_down ||
//            pmessage->m_emessage == e_message_right_button_up ||
//            pmessage->m_emessage == e_message_left_button_double_click ||
//            pmessage->m_emessage == e_message_mouse_move ||
//            pmessage->m_emessage == e_message_non_client_mouse_move ||
//            pmessage->m_emessage == e_message_mouse_wheel)
//      {
//
//         message::mouse * pmouse = (::message::mouse *) pmessage->m_union.m_pmouse;
//
//         psession->on_ui_mouse_message(pmouse);
//
//         if(m_bTranslateMouseMessageCursor && !pmouse->m_bTranslated)
//         {
//            pmouse->m_bTranslated = true;
//            int_rectangle rectangleWindow;
//            if(m_bScreenRelativeMouseMessagePosition)
//            {
//               rectangleWindow.Null();
//               //::int_rectangle rectangleWindow32;
//               //::window_rectangle(get_handle(), rectangleWindow32);
//               //::copy(rectangleWindow,rectangleWindow32);
//            }
//            else
//            {
//               m_puserinteraction->window_rectangle(rectangleWindow);
//            }
//            /*if(::auraacmesystem()->get_monitor_count() > 0)
//            {
//            ::int_rectangle rcMonitor;
//            ::auraacmesystem()->get_monitor_rectangle(0,&rcMonitor);
//            if(rectangleWindow.left() >= rcMonitor.left())
//            pmouse->m_point.x += (int)rectangleWindow.left();
//            if(rectangleWindow.top() >= rcMonitor.top())
//            pmouse->m_point.y += (int)rectangleWindow.top();
//            }
//            else*/
//            //if(rectangleWindow.left() >= 0)
//            pmouse->m_point.x += (int)rectangleWindow.left();
//            //if(rectangleWindow.top() >= 0)
//            pmouse->m_point.y += (int)rectangleWindow.top();
//         }
//
//         if(pmessage->m_emessage == e_message_mouse_move)
//         {
//            // We are at the message handler procedure.
//            // mouse messages originated from message handler and that are mouse move happenings should end up with the correct cursor.
//            // So the procedure starts by setting to the default cursor,
//            // what forces, at the end of message processing, setting the bergedge cursor to the default cursor, if no other
//            // handler has set it to another one.
//            //pmouse->m_ecursor = cursor_default;
//            //pmouse->m_pcursor = cursor_default;
//         }
//         else if(pmessage->m_emessage == e_message_non_client_mouse_move)
//         {
//            // We are at the message handler procedure.
//            // mouse messages originated from message handler and that are mouse move happenings should end up with the correct cursor.
//            // So the procedure starts by setting to the default cursor,
//            // what forces, at the end of message processing, setting the bergedge cursor to the default cursor, if no other
//            // handler has set it to another one.
//            //pmouse->m_ecursor = cursor_default;
//         }
//
//         //_008OnMouse(pmouse);
//
//         return;
//
//      }
//
//      //if(pusermessage->id() == MESSAGE_OLE_DRAGENTER ||
//      //   pusermessage->id() == MESSAGE_OLE_DRAGOVER ||
//      //   pusermessage->id() == MESSAGE_OLE_DRAGLEAVE ||
//      //   pusermessage->id() == MESSAGE_OLE_DRAGDROP)
//      //{
//
//      //   message::drag_and_drop * pdrag = (::message::drag_and_drop *) pusermessage;
//
//
//      //   user::oswindow_array oswindowa;
//      //   user::interaction_ptra wnda;
//      //   wnda = ::auraacmesystem()->m_uiptraFrame;
//      //   oswindowa = wnda.get_hwnda();
//      //   user::window_util::SortByZOrder(oswindowa);
//      //   for(int i = 0; i < oswindowa.get_size(); i++)
//      //   {
//      //      ::pointer<::user::interaction>pinteraction = wnda.find_first(oswindowa[i]);
//      //      if(pinteraction != nullptr)
//      //      {
//      //         pinteraction->_000OnDrag(pdrag);
//      //         if(pdrag->m_bRet)
//      //            return;
//      //      }
//      //   }
//      //   return;
//      //}
//      if(pmessage->m_emessage == e_message_key_down ||
//            pmessage->m_emessage == e_message_key_up ||
//            pmessage->m_emessage == e_message_char ||
//            pmessage->m_emessage == e_message_sys_key_down ||
//            pmessage->m_emessage == e_message_sys_key_up ||
//            pmessage->m_emessage == e_message_sys_char)
//      {
//
//         message::key * pkey = (::message::key *) pmessage->m_union.m_pkey;
//
//         auto puserinteractionHost = m_puserinteraction->get_host_window();
//
//         ::pointer<::user::interaction>puiFocus = puserinteractionHost->get_keyboard_focus();
//
//         if(puiFocus != nullptr && puiFocus->is_window() && puiFocus != m_puserinteraction)
//         {
//
//            puiFocus->send(pkey);
//
//            if(pmessage->m_bRet)
//               return;
//
//         }
//         else if(!pkey->m_bRet)
//         {
//
//            if(m_puserinteraction != nullptr)
//            {
//
//               m_puserinteraction->_000OnKey(pkey);
//
//               if(pmessage->m_bRet)
//                  pmessage;
//
//            }
//
//         }
//
//         //pmessage->set_lresult(DefWindowProc(pmessage->m_emessage, pmessage->m_wparam, pmessage->m_lparam));
//
//         return;
//
//      }
//      //if(pmessage->m_emessage == e_message_event)
//      //{
//      //   if(m_puserinteraction != nullptr)
//      //   {
//
//      //      m_puserinteraction->handle_event((::user::control_event *) pmessage->m_lparam.m_lparam);
//
//      //   }
//      //   return;
//      //}
//
//      ::windowing::window::message_handler(pmessage);
//
//      //if(pmessage->m_bRet && !pmessage->m_bDoSystemDefault)
//      if(pmessage->m_bRet)
//         return;
//      if(m_puserinteraction != nullptr)
//      {
//         m_puserinteraction->default_message_handler(pmessage);
//      }
//      else
//      {
//         //pmessage->set_lresult(DefWindowProc(pmessage->m_emessage, pmessage->m_wparam, pmessage->m_lparam));
//      }


   }


   //bool interaction_impl::OnCommand(::user::message * pusermessage)
   //{
   //   __UNREFERENCED_PARAMETER(pusermessage);
   //   return false;
   //}


   //bool interaction_impl::OnNotify(::user::message * pusermessage)
   //{

   //   ASSERT(pusermessage != nullptr);
   //   NMHDR* pNMHDR = (NMHDR*)pusermessage->m_lparam.m_lparam;
   //   oswindow oswindow_Ctrl = pNMHDR->hwndFrom;

   //   // get the child ID from the interaction_impl itself
   //   //      uptr nID = __get_dialog_control_id(oswindow_Ctrl);
   //   //      int nCode = pNMHDR->code;

   //   ASSERT(oswindow_Ctrl != nullptr);
   //   ASSERT(::is_window(oswindow_Ctrl));

   //   //      if (gen_ThreadState->m_hLockoutNotifyWindow == get_handle())
   //   //       return true;        // locked out - ignore control notification

   //   // reflect notification to child interaction_impl control
   //   //if(ReflectMessage(oswindow_Ctrl,pusermessage))
   //   // return true;        // eaten by child

   //   //      __NOTIFY notify;
   //   //    notify.pResult = pResult;
   //   //  notify.pNMHDR = pNMHDR;
   //   //xxx   return _001OnCommand(pusermessage);

   //   return false;

   //}


   //bool interaction_impl::IsTopParentActive()
   //{
   //   ASSERT(get_handle() != nullptr);
   //   ASSERT_VALID(this);

   //   ::pointer<::user::interaction>WndTopLevel=EnsureTopLevel();

   //   return interaction_impl::GetForegroundWindow() == pWndTopLevel->GetLastActivePopup();
   //}

   //void interaction_impl::ActivateTopParent()
   //{
   //   // special activate logic for floating toolbars and palettes
   //   //::windowing::window * pActiveWnd = GetForegroundWindow();
   //   //if(pActiveWnd == nullptr || !(NODE_WINDOW(pActiveWnd)->get_handle() == get_handle() || ::IsChild(NODE_WINDOW(pActiveWnd)->get_handle(),get_handle())))
   //   {
   //      // clicking on floating frame when it does not have
   //      // focus itself -- activate the toplevel frame instead.
   //      EnsureTopLevel()->set_foreground_window();
   //   }
   //}



   //::user::interaction * interaction_impl::get_safe_owner(::user::interaction * pParent,oswindow* pWndTop)
   //{
   //   oswindow oswindow = get_safe_owner(pParent->get_handle(),pWndTop);
   //   return ::android::interaction_impl::from_handle(oswindow);
   //}

   //int interaction_impl::message_box(const ::string & lpszText, const ::string & lpszCaption,unsigned int nType)
   //{
   //   if(lpszCaption == nullptr)
   //      lpszCaption = papp->m_strAppName;
   //   int nResult = ::message_box(get_handle(),lpszText,lpszCaption,nType);
   //   return nResult;
   //}


   //int interaction_impl::SetScrollPos(int nBar,int nPos,bool bRedraw)
   //{
   //   //return ::SetScrollPos(get_handle(),nBar,nPos,bRedraw);
   //   return -1;
   //}

   //int interaction_impl::GetScrollPos(int nBar) const
   //{
   //   //return ::GetScrollPos(((::android::interaction_impl *)this)->get_handle(),nBar);
   //   return -1;
   //}

   //void interaction_impl::SetScrollRange(int nBar,int nMinPos,int nMaxPos,bool bRedraw)
   //{
   //   //::SetScrollRange(get_handle(),nBar,nMinPos,nMaxPos,bRedraw);

   //}

   //void interaction_impl::GetScrollRange(int nBar,LPINT lpMinPos,LPINT lpMaxPos) const
   //{
   //   //::GetScrollRange(((::android::interaction_impl *)this)->get_handle(),nBar,lpMinPos,lpMaxPos);
   //}

   //// Turn on/off non-control scrollbars
   ////   for WS_?SCROLL scrollbars - show/hide them
   ////   for control scrollbar - enable/disable them
   //void interaction_impl::EnableScrollBarCtrl(int nBar,bool bEnable)
   //{
   //   // WS_?SCROLL scrollbar - show or hide
   //   ShowScrollBar(nBar,bEnable);
   //}

   //bool interaction_impl::SetScrollInfo(int nBar,LPSCROLLINFO lpScrollInfo,bool bRedraw)
   //{
   //   ASSERT(lpScrollInfo != nullptr);

   //   oswindow oswindow = get_handle();
   //   lpScrollInfo->cbSize = sizeof(*lpScrollInfo);
   //   ::SetScrollInfo(oswindow,nBar,lpScrollInfo,bRedraw);
   //   return true;
   //}

   //bool interaction_impl::GetScrollInfo(int nBar,LPSCROLLINFO lpScrollInfo,unsigned int nMask)
   //{
   //   __UNREFERENCED_PARAMETER(nMask);
   //   ASSERT(lpScrollInfo != nullptr);

   //   oswindow oswindow = get_handle();
   //   return ::GetScrollInfo(oswindow,nBar,lpScrollInfo) != false;
   //}

   //int interaction_impl::GetScrollLimit(int nBar)
   //{
   //   //int nMin,nMax;
   //   //GetScrollRange(nBar,&nMin,&nMax);
   //   //SCROLLINFO info;
   //   //if(GetScrollInfo(nBar,&info,SIF_PAGE))
   //   //{
   //   //   nMax -= maximum(info.nPage - 1,0);
   //   //}
   //   //return nMax;
   //   return -1;
   //}

   //void interaction_impl::ScrollWindow(int xAmount,int yAmount,
   //                                    const ::int_rectangle * lpRect,const ::int_rectangle * lpClipRect)
   //{
   //   //ASSERT(::is_window(get_handle()));

   //   //if(is_window_visible() || lpRect != nullptr || lpClipRect != nullptr)
   //   //{
   //   //   // When visible, let Windows do the scrolling
   //   //   ::ScrollWindow(get_handle(),xAmount,yAmount,lpRect,lpClipRect);
   //   //}
   //   //else
   //   //{
   //   //   // Windows does not perform any scrolling if the interaction_impl is
   //   //   // not visible.  This leaves child android unscrolled.
   //   //   // To ac::collection::count for this oversight, the child android are moved
   //   //   // directly instead.
   //   //   oswindow oswindow_Child = ::GetWindow(get_handle(),GW_CHILD);
   //   //   if(oswindow_Child != nullptr)
   //   //   {
   //   //      for(; oswindow_Child != nullptr;
   //   //         oswindow_Child = ::GetNextWindow(oswindow_Child,GW_HWNDNEXT))
   //   //      {
   //   //         ::int_rectangle rectangle;
   //   //         ::window_rectangle(oswindow_Child,&rectangle);
   //   //         screen_to_client(&rectangle);
   //   //         ::set_window_position(oswindow_Child,nullptr,rectangle.left() + xAmount,rectangle.top() + yAmount,0,0,SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOZORDER);
   //   //      }
   //   //   }
   //   //}

   //}




   //void interaction_impl::CalcWindowRect(::int_rectangle * lpClientRect, unsigned int nAdjustType)
   //{
   //   /*unsigned int dwExStyle = GetExStyle();
   //   if (nAdjustType == 0)
   //   dwExStyle &= ~WS_EX_CLIENTEDGE;
   //   ::AdjustWindowRectEx(lpClientRect, GetStyle(), false, dwExStyle);*/
   //}

/////////////////////////////////////////////////////////////////////////////
// Special keyboard/system command processing

   //bool interaction_impl::HandleFloatingSysCommand(unsigned int nID, lparam lparam)
   //{

   //   return false;
   //   /*      ::pointer<::user::interaction>pParent = GetTopLevelParent();
   //   switch (nID & 0xfff0)
   //   {
   //   case SC_PREVWINDOW:
   //   case SC_NEXTWINDOW:
   //   if (LOWORD(lparam) == VK_F6 && pParent != nullptr)
   //   {
   //   pParent->XXXSetFocus();
   //   return true;
   //   }
   //   break;

   //   case SC_CLOSE:
   //   case SC_KEYMENU:
   //   // Check lparam.  If it is 0L, then the ::account::user may have done
   //   // an Alt+Tab, so just ignore it.  This breaks the ability to
   //   // just press the Alt-key and have the first menu selected,
   //   // but this is minor compared to what happens in the Alt+Tab
   //   // case.
   //   if ((nID & 0xfff0) == SC_CLOSE || lparam != 0L)
   //   {
   //   if (pParent != nullptr)
   //   {
   //   // Sending the above WM_SYSCOMMAND may destroy the cast,
   //   // so we have to be careful about restoring activation
   //   // and focus after sending it.
   //   oswindow hWndSave = get_handle();
   //   oswindow hWndFocus = ::GetFocus();
   //   pParent->XXXSetActiveWindow();
   //   pParent->XXXsend_message(WM_SYSCOMMAND, nID, lparam);

   //   // be very careful here...
   //   if (::XXXis_window(hWndSave))
   //   ::XXXSetActiveWindow(hWndSave);
   //   if (::XXXis_window(hWndFocus))
   //   ::XXXSetFocus(hWndFocus);
   //   }
   //   }
   //   return true;
   //   }
   //   return false;*/
   //}

   //void interaction_impl::WalkPreTranslateTree(::user::interaction * puiStop, ::message::message * pmessage)
   //{
   //   ASSERT(puiStop == nullptr || puiStop->is_window());
   //   ASSERT(pmessage != nullptr);

   //   ::pointer<::user::message>pusermessage(pmessage);
   //   // walk from the target interaction_impl up to the hWndStop interaction_impl checking
   //   //  if any interaction_impl wants to translate this message

   //   for (::pointer<::user::interaction>pinteraction = pusermessage->m_puserinteraction; pinteraction != nullptr; pinteraction->get_parent())
   //   {

   //      pinteraction->pre_translate_message(pmessage);

   //      if (pmessage->m_bRet)
   //         return; // trapped by target interaction_impl (eg: accelerators)

   //      // got to hWndStop interaction_impl without interest
   //      if (pinteraction == puiStop)
   //         break;

   //   }
   //   // no special processing
   //}


   //bool interaction_impl::SendChildNotifyLastMsg(LRESULT* pResult)
   //{

   //   return false;

   //}


   void interaction_impl::on_message_create(::message::message * pmessage)
   {

      __UNREFERENCED_PARAMETER(pmessage);

      //Default();

      if (m_puserinteraction->is_message_only_window())
      {

         informationf("good : opt out!");

      }
      else
      {

         //m_pthreadDraw = ::fork(get_app(), [&]()
         //{

         //   unsigned int tickStart;

         //   while (::task_get_run())
         //   {

         // auto tickStart = ::time::now();

         //      if (!m_puserinteraction->m_bLockWindowUpdate)
         //      {

         //         if (m_puserinteraction->has_pending_graphical_update())
         //         {

         //            set_need_redraw(nullptr, nullptr, RDW_INVALIDATE | RDW_UPDATENOW | RDW_NOERASE);

         //            m_puserinteraction->on_after_graphical_update();

         //         }

         //      }

         //      _001UpdateBuffer();

         //      if (m_spgraphics.is_set())
         //      {

         //         m_spgraphics->update_window();

         //      }

         //      if (tickStart.elapsed() < 5)
         //      {

         //         sleep(5_ms);

         //      }

         //   }

         //});

      }

   }


   //bool CALLBACK interaction_impl::GetAppsEnumWindowsProc(oswindow hwnd, lparam lparam)
   //{
   //   user::oswindow_array * phwnda = (user::oswindow_array *) lparam;
   //   phwnda->add(hwnd);
   //   return true;
   //}


   //void interaction_impl::get_app_wnda(user::oswindow_array & wnda)
   //{

   //   // throw ::not_implemented();
   //   // EnumWindows(GetAppsEnumWindowsProc, (LPARAM) &wnda);

   //}


   /*   void interaction_impl::_001OnDeferPaintLayeredWindowBackground(::image::image * pimage)
   {
   _001DeferPaintLayeredWindowBackground(pgraphics);
   }*/


   //class print_window :
   //   virtual ::object
   //{
   //public:



   //   manual_reset_happening m_happening;
   //   oswindow m_hwnd;
   //   HDC m_hdc;

   //   print_window(oswindow hwnd, HDC hdc, unsigned int tickTimeout)
   //   {

   //      m_happening.reset_happening();
   //      m_hwnd = hwnd;
   //      m_hdc = hdc;
   //      begin_thread( &print_window::s_print_window, (LPVOID) this, ::e_priority_normal);
   //      if (m_happening.wait(::time(tickTimeout)).timeout())
   //      {
   //         informationf("print_window::time_out");
   //      }
   //   }


   //   static void     c_cdecl s_print_window(LPVOID pvoid)
   //   {
   //      print_window * pprintwindow = (print_window *)pvoid;
   //      try
   //      {
   //         HANDLE hevent = (HANDLE)pprintwindow->m_happening.get_os_data();
   //         throw ::exception(not_implemented(pprintwindow->get_app()));
   //         /*            ::PrintWindow(pprintwindow->m_hwnd, pprintwindow->m_hdc, 0);
   //         ::SetEvent(hevent);*/
   //      }
   //      catch (...)
   //      {
   //      }
   //      return 0;
   //   }
   //};

   //void interaction_impl::_001DeferPaintLayeredWindowBackground(HDC hdc)
   //{

   //   ::int_rectangle rectangleX;

   //   m_puserinteraction->rectangle(rectangleX);


   //   //pgraphics->FillSolidRect(rectangleX, 0x00000000);

   //   //return;
   //   ::int_rectangle rectangleUpdate;
   //   m_puserinteraction->window_rectangle(rectangleUpdate);
   //   //      SetViewportOrgEx(hdc, 0, 0, nullptr);
   //   ::int_rectangle rectanglePaint;
   //   rectanglePaint = rectangleUpdate;
   //   m_puserinteraction->screen_to_client(rectanglePaint);
   //   user::oswindow_array wndaApp;


   //   HRGN rgnWindow;
   //   HRGN rgnIntersect;
   //   HRGN rgnUpdate = nullptr;

   //   throw ::not_implemented();

   //}

   //void interaction_impl::_001OnProdevianSynch(::message::message * pmessage)
   //{

   //   __UNREFERENCED_PARAMETER(pmessage);

   //}

   //void interaction_impl::_001OnPaint(::message::message * pmessage)
   //{

   //}


   //void interaction_impl::_001OnPrint(::message::message * pmessage)
   //{
   //   throw ::not_implemented();
   //   //      ::pointer<::user::message>pusermessage(pmessage);
   //   //
   //   //      if(pusermessage->m_wparam == nullptr)
   //   //         return;
   //   //
   //   //      ::draw2d::graphics_pointer graphics(this);
   //   //      WIN_DC(graphics.m_p)->Attach((HDC) pusermessage->m_wparam);
   //   //      ::int_rectangle rectx;
   //   //      ::draw2d::bitmap * pbitmap = &pgraphics->GetCurrentBitmap();
   //   //      ::GetCurrentObject((HDC) pusermessage->m_wparam, OBJ_BITMAP);
   //   //      //      unsigned int dw = ::get_last_error();
   //   //      ::int_size size = pbitmap->get_size();
   //   //      rectx.left() = 0;
   //   //      rectx.top() = 0;
   //   //      rectx.right() = size.cx;
   //   //      rectx.bottom() = size.cy;
   //   //      try
   //   //      {
   //   //         ::int_rectangle rectangleWindow;
   //   //         window_rectangle(rectangleWindow);
   //   //
   //   //         ::image::image_pointer pimage(this);
   //   //         if(!pimage = create_image(rectangleWindow.bottom_right()))
   //   //            return;
   //   //
   //   //         ::draw2d::graphics_pointer & pgraphics = pimage->get_graphics();
   //   //
   //   //         if(pgraphics->get_handle() == nullptr)
   //   //            return;
   //   //
   //   //         ::int_rectangle rectanglePaint;
   //   //         ::int_rectangle rectangleUpdate;
   //   //         rectangleUpdate = rectangleWindow;
   //   //         rectanglePaint = rectangleWindow;
   //   //         rectanglePaint.offset(-rectanglePaint.top_left());
   //   //         (dynamic_cast<::android::graphics * >(pgraphics))->SelectClipRgn(nullptr);
   //   //         if(m_puserinteraction != nullptr && m_puserinteraction != this)
   //   //         {
   //   //            m_puserinteraction->_001OnDeferPaintLayeredWindowBackground(pgraphics);
   //   //         }
   //   //         else
   //   //         {
   //   //            _001OnDeferPaintLayeredWindowBackground(pgraphics);
   //   //         }
   //   //         (dynamic_cast<::android::graphics * >(pgraphics))->SelectClipRgn(nullptr);
   //   //         (dynamic_cast<::android::graphics * >(pgraphics))->SetViewportOrg(::int_point());
   //   //         _000OnDraw(pgraphics);
   //   //         (dynamic_cast<::android::graphics * >(pgraphics))->SetViewportOrg(::int_point());
   //   //         //(dynamic_cast<::android::graphics * >(pgraphics))->FillSolidRect(rectangleUpdate.left(), rectangleUpdate.top(), 100, 100, 255);
   //   //         (dynamic_cast<::android::graphics * >(pgraphics))->SelectClipRgn(nullptr);
   //   //         (dynamic_cast<::android::graphics * >(pgraphics))->SetViewportOrg(::int_point());
   //   //
   //   //         pgraphics->SelectClipRgn( nullptr);
   //   //         pgraphics->BitBlt(rectanglePaint.left(), rectanglePaint.top(),
   //   //            rectanglePaint.width(), rectanglePaint.height(),
   //   //            pgraphics, rectangleUpdate.left(), rectangleUpdate.top(),
   //   //            SRCCOPY);
   //   //
   //   //         pgraphics->text_out(0, 0, "Te Amo Carlinhos!!", 11);
   //   //      }
   //   //      catch(...)
   //   //      {
   //   //      }
   //   //      pgraphics->FillSolidRect(rectx, rgb(255, 255, 255));
   //   //      WIN_DC(graphics.m_p)->Detach();
   //   //      pmessage->m_bRet = true;
   //   //      pusermessage->set_lresult(0);
   //}


   //void interaction_impl::OnEnterIdle(unsigned int /*nWhy*/ , ::user::interaction  /*pWho*/)
   //{
   //   // In some OLE inplace active scenarios, OLE will post a
   //   // message instead of sending it.  This causes so many WM_ENTERIDLE
   //   // messages to be sent that tasks running in the background stop
   //   // running.  By dispatching the pending WM_ENTERIDLE messages
   //   // when the first one is received, we trick oswindows into thinking
   //   // that only one was really sent and dispatched.
   //   {
   //      MESSAGE msg;
   //      throw ::not_implemented();
   //      //while (PeekMessage(&msg, nullptr, WM_ENTERIDLE, WM_ENTERIDLE, PM_REMOVE))
   //      //while (PeekMessage(&msg, nullptr, WM_ENTERIDLE, WM_ENTERIDLE, true))
   //      // DispatchMessage(&msg);
   //   }

   //   Default();
   //}

   //HBRUSH interaction_impl::OnCtlColor(::draw2d::graphics *, ::user::interaction * pWnd, unsigned int)
   //{
   //   ASSERT(pWnd != nullptr && pWnd->get_handle() != nullptr);
   //   LRESULT lResult;
   //   if (pWnd->m_pimpl.cast < interaction_impl >()->SendChildNotifyLastMsg(&lResult))
   //      return (HBRUSH)lResult;     // eat it
   //   return (HBRUSH)Default();
   //}

//// implementation of OnCtlColor for default gray backgrounds
////   (works for any interaction_impl containing controls)
////  return value of false means caller must call DefWindowProc's default
////  true means that 'hbrGray' will be used and the appropriate text
////    ('clrText') and background colors are set.
//   bool PASCAL interaction_impl::GrayCtlColor(HDC hDC, oswindow hWnd, unsigned int nCtlColor,
//         HBRUSH hbrGray, color32_t clrText)
//   {
//      throw ::not_implemented();
//      //      if (hDC == nullptr)
//      //      {
//      //         // sometimes Win32 passes a nullptr hDC in the WM_CTLCOLOR message.
//      //         //         information(::ca2::trace::category_AppMsg, 0, "Warning: hDC is nullptr in interaction_impl::GrayCtlColor; WM_CTLCOLOR not processed.\n");
//      //         return false;
//      //      }
//      //
//      //      if (hbrGray == nullptr ||
//      //         nCtlColor == CTLCOLOR_EDIT || nCtlColor == CTLCOLOR_MSGBOX ||
//      //         nCtlColor == CTLCOLOR_SCROLLBAR)
//      //      {
//      //         return false;
//      //      }
//      //
//      //      if (nCtlColor == CTLCOLOR_LISTBOX)
//      //      {
//      //         // only handle requests to draw the space between edit and drop button
//      //         //  in a drop-down combo (not a drop-down list)
//      //         if (!__is_combo_box_control(hWnd, (unsigned int)CBS_DROPDOWN))
//      //            return false;
//      //      }
//      //
//      //      // set background color and return handle to brush
//      //      LOGBRUSH logbrush;
//      //      VERIFY(::GetObject(hbrGray, sizeof(LOGBRUSH), (LPVOID)&logbrush));
//      //      ::SetBkColor(hDC, logbrush.lbColor);
//      //      if (clrText == (color32_t)-1)
//      //         clrText = ::GetSysColor(COLOR_WINDOWTEXT);  // normal text
//      //      ::SetTextColor(hDC, clrText);
//      //      return true;
//   }


   //void interaction_impl::CenterWindow(::user::interaction * pAlternateOwner)
   //{
   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //
   //   //      // determine owner interaction_impl to center against
   //   //      unsigned int dwStyle = GetStyle();
   //   //      ::pointer<::user::interaction>hWndCenter = pAlternateOwner;
   //   //      if (pAlternateOwner == nullptr)
   //   //      {
   //   //         if (dwStyle & WS_CHILD)
   //   //            hWndCenter = get_parent();
   //   //         else
   //   //            hWndCenter = GetWindow(GW_OWNER);
   //   //         if (hWndCenter != nullptr)
   //   //         {
   //   //            // let parent determine alternate center interaction_impl
   //   //            ::pointer<::user::interaction>hWndTemp =
   //   //               (::pointer<::user::interaction>)hWndCenter->send_message(WM_QUERYCENTERWND, 0, 0);
   //   //            if (hWndTemp != nullptr)
   //   //               hWndCenter = hWndTemp;
   //   //         }
   //   //      }
   //   //
   //   //      // get coordinates of the interaction_impl relative to its parent
   //   //      int_rectangle rcDlg;
   //   //      window_rectangle(&rcDlg);
   //   //      int_rectangle rcarea;
   //   //      int_rectangle rcCenter;
   //   //      ::pointer<::user::interaction>hWndParent;
   //   //      if (!(dwStyle & WS_CHILD))
   //   //      {
   //   //         // don't center against invisible or minimized windows
   //   //         if (hWndCenter != nullptr)
   //   //         {
   //   //            unsigned int dwAlternateStyle = hWndCenter->GetWindowLong(GWL_STYLE);
   //   //            if (!(dwAlternateStyle & WS_VISIBLE) || (dwAlternateStyle & WS_MINIMIZE))
   //   //               hWndCenter = nullptr;
   //   //         }
   //   //
   //   //         MONITORINFO mi;
   //   //         mi.cbSize = sizeof(mi);
   //   //
   //   //         // center within appropriate monitor coordinates
   //   //         if (hWndCenter == nullptr)
   //   //         {
   //   //            oswindow hwDefault = ::auraacmesystem()->GetMainWnd()->get_handle();
   //   //
   //   //            GetMonitorInfo(
   //   //               MonitorFromWindow(hwDefault, MONITOR_DEFAULTTOPRIMARY), &mi);
   //   //            rcCenter = mi.rcWork;
   //   //            rcarea = mi.rcWork;
   //   //         }
   //   //         else
   //   //         {
   //   //            hWndCenter->window_rectangle(&rcCenter);
   //   //            GetMonitorInfo(
   //   //               MonitorFromWindow(hWndCenter->get_handle(), MONITOR_DEFAULTTONEAREST), &mi);
   //   //            rcarea = mi.rcWork;
   //   //         }
   //   //      }
   //   //      else
   //   //      {
   //   //         // center within parent client coordinates
   //   //         hWndParent = get_parent();
   //   //         ASSERT(hWndParent->is_window());
   //   //
   //   //         hWndParent->rectangle(&rcarea);
   //   //         ASSERT(hWndCenter->is_window());
   //   //         hWndCenter->rectangle(&rcCenter);
   //   //         ::MapWindowPoints(hWndCenter->get_handle(), hWndParent->get_handle(), (::int_point*)&rcCenter, 2);
   //   //      }
   //   //
   //   //      // find dialog's upper left based on rcCenter
   //   //      int xLeft = (rcCenter.left() + rcCenter.right()) / 2 - rcDlg.width() / 2;
   //   //      int yTop = (rcCenter.top() + rcCenter.bottom()) / 2 - rcDlg.height() / 2;
   //   //
   //   //      // if the dialog is outside the screen, move it inside
   //   //      if (xLeft < rcarea.left())
   //   //         xLeft = rcarea.left();
   //   //      else if (xLeft + rcDlg.width() > rcarea.right())
   //   //         xLeft = rcarea.right() - rcDlg.width();
   //   //
   //   //      if (yTop < rcarea.top())
   //   //         yTop = rcarea.top();
   //   //      else if (yTop + rcDlg.height() > rcarea.bottom())
   //   //         yTop = rcarea.bottom() - rcDlg.height();
   //   //
   //   //      // ::collection::map screen coordinates to child coordinates
   //   //      set_window_position(nullptr, xLeft, yTop, -1, -1,
   //   //         SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
   //}


   //void interaction_impl::CheckAutoCenter()
   //{
   //   
   //   //return true;

   //}


   ///////////////////////////////////////////////////////////////////////////////
   //// Dialog initialization support


   //bool interaction_impl::ExecuteDlgInit(const ::string & lpszResourceName)
   //{

   //   // find resource handle
   //   LPVOID lpResource = nullptr;

   //   HGLOBAL hResource = nullptr;

   //   if (lpszResourceName != nullptr)
   //   {
   //      //         HINSTANCE hInst = ::ca2::FindResourceHandle(lpszResourceName, RT_DLGINIT);
   //      //       HRSRC hDlgInit = ::FindResource(hInst, lpszResourceName, RT_DLGINIT);
   //      /*     if (hDlgInit != nullptr)
   //      {
   //      // load it
   //      hResource = LoadResource(hInst, hDlgInit);
   //      if (hResource == nullptr)
   //      return false;
   //      // lock it
   //      lpResource = LockResource(hResource);
   //      ASSERT(lpResource != nullptr);
   //      }*/
   //   }

   //   // execute it
   //   bool bResult = ExecuteDlgInit(lpResource);

   //   // cleanup
   //   if (lpResource != nullptr && hResource != nullptr)
   //   {

   //      throw ::not_implemented();

   // 

   //   }

   //   return bResult;

   //}


   //bool interaction_impl::ExecuteDlgInit(LPVOID lpResource)
   //{

   //   throw ::not_implemented();

   //}


   //void interaction_impl::UpdateDialogControls(channel* pTarget, bool bDisableIfNoHndler)
   //{

   //   //__UNREFERENCED_PARAMETER(pTarget);

   //   //__UNREFERENCED_PARAMETER(bDisableIfNoHndler);

   //   //::message::command state(this);

   //}


   //bool interaction_impl::is_frame_window()
   //{

   //   return false;

   //}


   //bool interaction_impl::SubclassWindow(oswindow hWnd)
   //{

   //   if (!Attach(hWnd))
   //   {

   //      return false;

   //   }

   //   // allow any other subclassing to occur
   //   pre_subclass_window();

   //   throw ::not_implemented();


   //}


   //oswindow interaction_impl::UnsubclassWindow()
   //{

   //   ASSERT(::is_window((oswindow)get_handle()));

   //   throw ::not_implemented();

   //}


   //bool interaction_impl::IsChild(::user::interaction * pWnd)
   //{

   //   ASSERT(::is_window((oswindow)get_handle()));

   //   if (pWnd->get_handle() == nullptr)
   //   {

   //      return ::windowing::window::is_child(pWnd);

   //   }
   //   else
   //   {

   //      return ::IsChild((oswindow)get_handle(), pWnd->get_handle()) != false;

   //   }

   //}


   //bool interaction_impl::_is_window() const
   //{

   //   return ::is_window((oswindow)get_safe_handle()) != false;

   //}


   //oswindow interaction_impl::get_handle() const
   //{

   //   return m_oswindow;

   //}


//#define SWP_IGNOREPALACEGUARD I32_MINIMUM
//
//   bool interaction_impl::set_window_position(iptr z, int x, int y, int cx, int cy, unsigned int nFlags)
//   {
//
//      return ::windowing::window::set_window_position(z, x, y, cx, cy, nFlags);
//
//      //      single_lock synchronouslock(&user_mutex(), true);
//
//      //xdisplay d(m_oswindow->display());
//
//      ::int_rectangle rectangleScreen;
//
//      m_puserinteraction->best_monitor(rectangleScreen);
//
//      int iPalaceGuard = 256;
//
//      if (nFlags & SWP_IGNOREPALACEGUARD)
//         iPalaceGuard = 1;
//
//      if (x > rectangleScreen.right() - iPalaceGuard)
//         x = rectangleScreen.right() - iPalaceGuard;
//
//      if (x < 0)
//         x = 0;
//
//      if (y > rectangleScreen.bottom() - iPalaceGuard)
//         y = rectangleScreen.bottom() - iPalaceGuard;
//
//      if (y < 0)
//         y = 0;
//
//      if (cx > rectangleScreen.width())
//         cx = rectangleScreen.width();
//
//      if (cx < iPalaceGuard)
//         cx = iPalaceGuard;
//
//      if (cy > rectangleScreen.height())
//         cy = rectangleScreen.height();
//
//      if (cy < iPalaceGuard)
//         cy = iPalaceGuard;
//
//
//      ASSERT(::is_window((oswindow)get_handle()));
//      /*   return ::set_window_position(get_handle(), pWndInsertAfter->get_handle(),
//      x, y, cx, cy, nFlags) != false; */
//
//      //throw ::not_implemented();
//
//      //XSizeHints hints;
//
//      ::set_window_position((oswindow) get_handle(), 0, x, y, cx, cy, nFlags);
//      if (nFlags & SWP_NOMOVE)
//      {
//         if (nFlags & SWP_NOSIZE)
//         {
//            //hints.flags = 0;
//         }
//         else
//         {
//            //hints.flags = PSize;
//            //hints.width = cx;
//            //hints.height = cy;
//            //XResizeWindow(m_oswindow->display(), m_oswindow->window(), cx, cy);
//            //            XClearWindow(m_oswindow->display(), m_oswindow->interaction_impl());
//         }
//      }
//      else
//      {
//      }
//
//      if (!is_window_visible())
//      {
//
//         /*XSetNormalHints(m_oswindow->display(), m_oswindow->window(), &hints);*/
//
//      }
//
//      ::int_rectangle rectangle;
//
//      ::window_rectangle(get_handle(), rectangle);
//
//      ::copy(m_rectangleParentClient, rectangle);
//
//      if ((nFlags & SWP_SHOWWINDOW))
//      {
//
//         if (!is_window_visible())
//         {
//
//            /*XMapWindow(m_oswindow->display(), m_oswindow->window());*/
//
//            ::show_window(get_handle(), e_display_normal);
//
//         }
//
//      }
//
//
//      return true;
//
//   }


   //void interaction_impl::MoveWindow(int x, int y, int nWidth, int nHeight, bool bRepaint)
   //{
   //   ASSERT(::is_window((oswindow)get_handle()));
   //   SetWindowPos(0, x, y, nWidth, nHeight, bRepaint ? SWP_SHOWWINDOW : 0);
   //}


   //bool interaction_impl::client_to_screen(::int_rectangle * lprect)
   //{

   //   ::long_long_rectangle rectangleWindow;

   //   if(!window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lprect->left() += (int)rectangleWindow.left();
   //   lprect->right() += (int)rectangleWindow.left();
   //   lprect->top() += (int)rectangleWindow.top();
   //   lprect->bottom() += (int)rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::client_to_screen(::int_point * lppoint)
   //{

   //   ::long_long_rectangle rectangleWindow;

   //   if(!window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lppoint->x += (int)rectangleWindow.left();
   //   lppoint->y += (int)rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::client_to_screen(::long_long_rectangle * lprect)
   //{

   //   ::int_rectangle rectangleWindow;

   //   if(!window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lprect->left() += rectangleWindow.left();
   //   lprect->right() += rectangleWindow.left();
   //   lprect->top() += rectangleWindow.top();
   //   lprect->bottom() += rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::client_to_screen(::long_long_point * lppoint)
   //{

   //   ::long_long_rectangle rectangleWindow;

   //   if(!window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lppoint->x += rectangleWindow.left();
   //   lppoint->y += rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::screen_to_client(::int_rectangle * lprect)
   //{

   //   ::long_long_rectangle rectangleWindow;

   //   if(!window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lprect->left() -= (int)rectangleWindow.left();
   //   lprect->right() -= (int)rectangleWindow.left();
   //   lprect->top() -= (int)rectangleWindow.top();
   //   lprect->bottom() -= (int)rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::screen_to_client(::int_point * lppoint)
   //{

   //   ::long_long_rectangle rectangleWindow;

   //   if(!m_puserinteraction->window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lppoint->x -= (int)rectangleWindow.left();
   //   lppoint->y -= (int)rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::screen_to_client(::long_long_rectangle * lprect)
   //{

   //   ::long_long_rectangle rectangleWindow;

   //   if(!window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lprect->left() -= rectangleWindow.left();
   //   lprect->right() -= rectangleWindow.left();
   //   lprect->top() -= rectangleWindow.top();
   //   lprect->bottom() -= rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::screen_to_client(::long_long_point * lppoint)
   //{

   //   ::long_long_rectangle rectangleWindow;

   //   if(!window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lppoint->x -= rectangleWindow.left();
   //   lppoint->y -= rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::window_rectangle(::long_long_rectangle * lprect)
   //{

   //   if (!::is_window((oswindow)get_handle()))
   //   {

   //      return false;

   //   }

   //   // if it is temporary interaction_impl - probably not ca2 wrapped interaction_impl
   //   //if(m_puserinteraction == nullptr || m_puserinteraction == this)
   //   {
   //      ::int_rectangle rect32;

   //      if(!::window_rectangle((oswindow)get_handle(),rect32))
   //      {

   //         return false;

   //      }

   //      ::copy(lprect, rect32);
   //   }
   //   //else
   //   {
   //      //  interaction::window_rectangle(lprect);
   //   }

   //   return true;

   //}


   //bool interaction_impl::this->rectangle(::long_long_rectangle * lprect)
   //{

   //   if(!::is_window((oswindow)get_handle()))
   //   {

   //      return false;

   //   }
   //   // if it is temporary interaction_impl - probably not ca2 wrapped interaction_impl
   //   //if(m_puserinteraction == nullptr || m_puserinteraction == this)
   //   {
   //      ::int_rectangle rect32;
   //      if(!::this->rectangle((oswindow)get_handle(),rect32))
   //      {

   //         return false;

   //      }
   //      ::copy(lprect, rect32);
   //   }
   //   //else
   //   {
   //      // interaction::this->rectangle(lprect);
   //   }

   //   return true;

   //}


   //atom interaction_impl::SetDlgCtrlId(atom atom)
   //{

   //   return m_puserinteraction->SetDlgCtrlId(atom);
   //}

   //atom interaction_impl::GetDlgCtrlId()
   //{
   //   return m_puserinteraction->GetDlgCtrlId();
   //}



   //void interaction_impl::_001WindowMaximize()
   //{
   //   ::windowing::window::_001WindowMaximize();
   //}


   //void interaction_impl::_001WindowRestore()
   //{

   //   if (m_puserinteraction != nullptr)
   //   {

   //      m_puserinteraction->m_edisplay = ::e_display_normal;

   //   }

   //   ::show_window((oswindow)get_handle(), SW_RESTORE);

   //}


//   bool interaction_impl::show_window(const ::e_display & edisplay)
//   {
//
//      if (!::is_window((oswindow)get_handle()))
//      {
//
//         return false;
//
//      }
//
//      ::show_window((oswindow)get_handle(), edisplay);
//
//      return m_puserinteraction->is_window_visible();
//
//   }
//
//
//   //bool interaction_impl::layout().is_iconic()
//   //{
//
//   //   if (GetExStyle() & WS_EX_LAYERED)
//   //   {
//
//   //      return m_puserinteraction->m_edisplay == ::e_display_iconic;
//
//   //   }
//   //   else
//   //   {
//
//   //      return ::IsIconic((oswindow)get_handle()) != false;
//
//   //   }
//
//   //}
//
//   
//   //int interaction_impl::GetWindowLong(int nIndex)
//   //{
//
//   //   return ::GetWindowLong((oswindow)get_handle(), nIndex);
//
//   //}
//
//
//   //int interaction_impl::SetWindowLong(int nIndex, int lValue)
//   //{
//   //   return ::SetWindowLong((oswindow)get_handle(), nIndex, lValue);
//   //}
//
//
//
//
//// interaction_impl
//   /* interaction_impl::operator oswindow() const
//   { return this == nullptr ? nullptr : get_handle(); }*/
//   bool interaction_impl::operator==(const ::windowing::window& wnd) const
//   {
//      return const_cast < ::windowing::window * >  (&wnd)->get_handle() == ((interaction_impl *)this)->get_handle();
//   }
//
//   bool interaction_impl::operator!=(const ::windowing::window& wnd) const
//   {
//      return const_cast < ::windowing::window * >  (&wnd)->get_handle() != ((interaction_impl *)this)->get_handle();
//   }
//
////unsigned int interaction_impl::GetStyle() const
////{
////   ASSERT(::is_window((oswindow)get_handle()));
////   return (unsigned int)::GetWindowLong((oswindow)get_handle(), GWL_STYLE);
////}
////
////unsigned int interaction_impl::GetExStyle() const
////{
////   ASSERT(::is_window((oswindow)get_handle()));
////   return (unsigned int)::GetWindowLong((oswindow)get_handle(), GWL_EXSTYLE);
////}
//
//
//   //bool interaction_impl::ModifyStyle(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
//   //{
//   //
//   //   ASSERT(::is_window((oswindow)get_handle()));
//   //
//   //   return ModifyStyle((oswindow)get_handle(), dwRemove, dwAdd, nFlags);
//
//   //}
//
//
//   //bool interaction_impl::ModifyStyleEx(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
//   //{
//
//   //   ASSERT(::is_window((oswindow)get_handle()));
//
//   //   return ModifyStyleEx((oswindow)get_handle(), dwRemove, dwAdd, nFlags);
//
//   //}
//
//   
//   void interaction_impl::set_owner(::user::interaction * pOwnerWnd)
//   {
//      //      m_puiOwner = pOwnerWnd;
//      m_puserinteraction->SetOwner((pOwnerWnd));
//   }
//
//   LRESULT interaction_impl::send_message(::enum_message emessage, ::wparam wparam, ::lparam lparam)
//   {
//
//      //if (::get_task() == nullptr)
//      //{
//
//      //   ::set_thread(m_puserinteraction->get_app());
//
//      //}
//
//      return ::windowing::window::send_message(emessage, wparam, lparam);
//
//   }
//
//
//   bool interaction_impl::post_message(::enum_message emessage, ::wparam wparam, ::lparam lparam)
//   {
//
//      return ::windowing::window::post_message(emessage, wparam, lparam);
//      //return ::post_me((oswindow)get_handle(), message, wparam, lparam) != false;
//
//   }
//
//
//   //bool interaction_impl::DragDetect(::int_point pt) const
//   //{
//
//   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));

   //   //return ::DragDetect(get_handle(), int_point) != false;

   //}
//
//
////void interaction_impl::RedrawWindo
//   void interaction_impl::SetFont(::write_text::font* pfont, bool bRedraw)
//   {
//
//      __UNREFERENCED_PARAMETER(bRedraw);
//
//      //ASSERT(::is_window((oswindow) get_handle())); m_pfont = ___new ::write_text::font(*pfont);
//
//   }
//
//
//   ::write_text::font* interaction_impl::GetFont()
//   {
//
//      //ASSERT(::is_window((oswindow) get_handle()));
//
//      //return m_pfont;
//      return nullptr;
//
//   }
//
//
//   void interaction_impl::DragAcceptFiles(bool bAccept)
//   {
//
//      throw ::not_implemented();
//
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::DragAcceptFiles(get_handle(), bAccept);
//
//   }
//
//   /*
//   ::pointer<::user::frame_window>interaction_impl::EnsureParentFrame()
//   {
//
//   ::pointer<::user::frame_window>pFrameWnd=get_parent_frame();
//
//   ENSURE_VALID(pFrameWnd);
//
//   return pFrameWnd;
//
//   }
//
//
//   ::user::interaction * interaction_impl::EnsureTopLevelParent()
//   {
//
//   ::pointer<::user::interaction>Wnd=GetTopLevelParent();
//
//   ENSURE_VALID(pWnd);
//
//   return pWnd;
//
//   }
//
//   */
//

   //void interaction_impl::set_window_text(const ::string & lpszString)
   //{

   //   m_strWindowText = lpszString;

   //}


   //character_count interaction_impl::get_window_text(char * lpszStringBuf, character_count nMaxCount)
   //{

   //   strncpy(lpszStringBuf, m_strWindowText, nMaxCount);

   //   return minimum(nMaxCount, m_strWindowText.length());

   //}


   //void interaction_impl::get_window_text(string & rString)
   //{

   //   m_strWindowText = rString;

   //}


   //character_count interaction_impl::get_window_text_length()
   //{

   //   return m_strWindowText.length();

   //}


   //::user::interaction * interaction_impl::get_parent()
   //{

   //   if (!::is_window((oswindow)get_handle()))
   //      return nullptr;

   //   if (get_handle() == nullptr)
   //      return nullptr;

   //   //return ::linux::interaction_impl::from_handle(::get_parent(get_handle()));

   //   return nullptr;

   //}

   //void interaction_impl::MoveWindow(const ::int_rectangle * lpRect, bool bRepaint)
   //{

   //   MoveWindow(lpRect->left(), lpRect->top(), lpRect->right() - lpRect->left(), lpRect->bottom() - lpRect->top(), bRepaint);

   //}


   //unsigned int interaction_impl::ArrangeIconicWindows()
   //{

   //   throw ::not_implemented();

   //   //      ASSERT(::is_window((oswindow) get_handle())); return ::ArrangeIconicWindows(get_handle());

   //}


   //int interaction_impl::SetWindowRgn(HRGN hRgn, bool bRedraw)
   //{

   //   __UNREFERENCED_PARAMETER(hRgn);
   //   __UNREFERENCED_PARAMETER(bRedraw);

   //   //throw ::not_implemented();

   //   //      ASSERT(::is_window((oswindow) get_handle())); return ::SetWindowRgn(get_handle(), hRgn, bRedraw);

   //   return 0;

   //}


   //int interaction_impl::GetWindowRgn(HRGN hRgn)
   //{

   //   throw ::not_implemented();

   //   //      ASSERT(::is_window((oswindow) get_handle()) && hRgn != nullptr); return ::GetWindowRgn(get_handle(), hRgn);
   //   return 0;

   //}


   //bool interaction_impl::BringWindowToTop()
   //{

   //   //      throw ::not_implemented();
   //   //      return ::BringWindowToTop(get_handle()) != false;

   //   return true;

   //}


   //void interaction_impl::MapWindowPoints(::user::interaction * puserinteractionTo, ::int_point * lpPoint, unsigned int nCount)
   //{

   //   throw ::not_implemented();

   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      ::MapWindowPoints(get_handle(), (oswindow) puserinteractionTo->get_handle(), lpPoint, nCount);

   //}


   //void interaction_impl::MapWindowPoints(::user::interaction * puserinteractionTo, ::int_rectangle * lpRect)
   //{

   //   throw ::not_implemented();

   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      ::MapWindowPoints(get_handle(), (oswindow) puserinteractionTo->get_handle(), (::int_point *)lpRect, 2);

   //}


   //::draw2d::graphics * interaction_impl::GetDC()
   //{

   //   ::draw2d::graphics_pointer g(e_create);

   //   //xdisplay d(m_oswindow->display());

   //   oswindow oswindow;

   //   if (get_handle() == nullptr)
   //   {

   //      //         oswindow = ::get_desktop_window();

   //   }
   //   else
   //   {

   //      oswindow = (::oswindow) get_handle();

   //   }

   //   ::int_rectangle rectangleX;

   //   //oswindow->rectangle(rectangleX);

   //   rectangleX.left() = 0;
   //   rectangleX.top() = 0;
   //   rectangleX.right() = 500;
   //   rectangleX.bottom() = 500;
   //   //      (dynamic_cast < ::android::graphics * >(g.m_p))->attach(cairo_create(cairo_xlib_surface_create(oswindow->display(), oswindow->interaction_impl(), oswindow->draw2d(),rectangleX.width(), rectangleX.height())));
   //   return g.detach();
   //}

   //::draw2d::graphics * interaction_impl::GetWindowDC()
   //{
   //   /*ASSERT(::is_window((oswindow)get_handle()));
   //   ::draw2d::graphics_pointer g(e_create);
   //   g->attach(::GetWindowDC(get_handle()));
   //   return g.detach();*/
   //   return GetDC();
   //}

   //bool interaction_impl::ReleaseDC(::image::image * pimage)
   //{

   //   //if (pgraphics == nullptr)
   //   // return false;

   //   /*      cairo_t * pcairo = (cairo_t *) pgraphics->get_os_data();

   //   cairo_surface_t * psurface = cairo_get_target(pcairo);
   //   if(pcairo ==  g_cairo)
   //   {
   //   printf("123");

   //   }

   //   cairo_destroy(pcairo);

   //   if(psurface == g_cairosurface)
   //   {
   //   printf("123");
   //   }      cairo_surface_destroy(psurface);*/

   //   //      if(((Gdiplus::Graphics *)(dynamic_cast<::android::graphics * >(pgraphics))->get_handle()) == nullptr)
   //   //       return false;

   //   //::ReleaseDC(get_handle(), (dynamic_cast < ::android::graphics * > (pgraphics))->detach());

   //   //      (dynamic_cast<::android::graphics * >(pgraphics))->m_hdc = nullptr;

   //   //      pgraphics->release();

   //   return true;

   //}

   //void interaction_impl::UpdateWindow()
   //{
   //   throw ::not_implemented();
   //   //::UpdateWindow(get_handle());
   //}

   //void interaction_impl::SetRedraw(bool bRedraw)
   //{
   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //::SendMessage(get_handle(), WM_SETREDRAW, bRedraw, 0);
   //}

   //bool interaction_impl::GetUpdateRect(::int_rectangle * lpRect, bool bErase)
   //{
   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //return ::GetUpdateRect(get_handle(), lpRect, bErase) != false;
   //}

   //int interaction_impl::GetUpdateRgn(draw2d::region * pRgn, bool bErase)
   //{
   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //return ::GetUpdateRgn(get_handle(), (HRGN)pRgn->get_handle(), bErase);
   //}

   //void interaction_impl::Invalidate(bool bErase)
   //{
   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //::InvalidateRect(get_handle(), nullptr, bErase);
   //}

   //void interaction_impl::InvalidateRect(const ::int_rectangle * lpRect, bool bErase)
   //{
   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //::InvalidateRect(get_handle(), lpRect, bErase);
   //}

   //void interaction_impl::InvalidateRgn(::draw2d::region* pRgn, bool bErase)
   //{
   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //::InvalidateRgn(get_handle(), (HRGN)pRgn->get_handle(), bErase);
   //}

   //void interaction_impl::ValidateRect(const ::int_rectangle * lpRect)
   //{
   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //::ValidateRect(get_handle(), lpRect);
   //}

   //void interaction_impl::ValidateRgn(::draw2d::region* pRgn)
   //{
   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //::ValidateRgn(get_handle(), (HRGN)pRgn->get_handle());
   //}

   //bool interaction_impl::is_window_visible()
   //{

   //   if (!::is_window((oswindow)get_handle()))
   //   {

   //      return false;

   //   }

   //   if (m_puserinteraction != nullptr)
   //   {

   //      if (!m_puserinteraction->is_this_visible())
   //      {

   //         return false;

   //      }

   //      if (m_puserinteraction->get_parent() != nullptr && !m_puserinteraction->get_parent()->is_window_visible())
   //         return false;

   //   }

   //   //if (!::IsWindowVisible(get_handle()))
   //   //   return false;

   //   return true;

   //}


   //void interaction_impl::ShowOwnedPopups(bool bShow)
   //{

   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //::ShowOwnedPopups(get_handle(), bShow);

   //}

   //void interaction_impl::send_message_to_descendants(::enum_message emessage, ::wparam wparam, ::lparam lparam, bool bDeep, bool bOnlyPerm)
   //{
   //   ASSERT(::is_window((oswindow)get_handle()));
   //   //interaction_impl::send_message_to_descendants(get_handle(), message, wparam, lparam, bDeep, bOnlyPerm);

   //   // walk through oswindows to avoid creating temporary interaction_impl objects
   //   // unless we need to call this function recursively
   //   user::interaction * pinteraction = m_puserinteraction->first_child();
   //   while (pinteraction != nullptr)
   //   {
   //      try
   //      {
   //         pinteraction->send_message(message, wparam, lparam);
   //      }
   //      catch (...)
   //      {
   //      }
   //      if (bDeep)
   //      {
   //         // send to child windows after parent
   //         try
   //         {
   //            pinteraction->send_message_to_descendants(message, wparam, lparam, bDeep, bOnlyPerm);
   //         }
   //         catch (...)
   //         {
   //         }
   //      }
   //      try
   //      {
   //         pinteraction = pinteraction->next_sibling();
   //      }
   //      catch (...)
   //      {
   //         break;
   //      }
   //   }
   //}

   //::draw2d::graphics * interaction_impl::GetDCEx(::draw2d::region * prgnClip, unsigned int flags)
   //{

   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //::draw2d::graphics_pointer g(this);
   //   //g->attach(::GetDCEx(get_handle(), (HRGN)prgnClip->get_handle(), flags));
   //   //return g.detach();

   //}

   //bool interaction_impl::LockWindowUpdate()
   //{

   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //return ::LockWindowUpdate(get_handle()) != false;

   //}

   //void interaction_impl::UnlockWindowUpdate()
   //{

   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //::LockWindowUpdate(nullptr);

   //}


   //bool interaction_impl::RedrawWindow(const ::int_rectangle & rectangleUpdate, ::draw2d::region * prgnUpdate, unsigned int flags)
   //{

   //   if (!is_window_visible())
   //   {

   //      return true;

   //   }

   //   if (flags & RDW_UPDATENOW)
   //   {

   //      _001UpdateWindow();

   //   }
   //   else
   //   {

   //      m_puserinteraction->m_bRedraw = true;

   //   }

   //   return true;

   //}

   /*
   bool interaction_impl::EnableScrollBar(int nSBFlags, unsigned int nArrowFlags)
   {

   ASSERT(::is_window((oswindow) get_handle()));

   return ::EnableScrollBar(get_handle(), nSBFlags, nArrowFlags) != false;

   }
   */

   //bool interaction_impl::DrawAnimatedRects(int idAni, const ::int_rectangle *lprcFrom, const ::int_rectangle *lprcTo)
   //{

   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //return ::DrawAnimatedRects(get_handle(), idAni, lprcFrom, lprcTo) != false;

   //}

   //bool interaction_impl::DrawCaption(::draw2d::graphics_pointer & pgraphics, const ::int_rectangle * lprc, unsigned int uFlags)
   //{

   //   throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //return ::DrawCaption(get_handle(), (HDC)(dynamic_cast<::android::graphics * >(pgraphics))->get_handle(), lprc, uFlags) != false;

   //}

   //bool interaction_impl::SetTimer(uptr uEvent, unsigned int nElapse, PFN_TIMER pfnTimer)
   //{

   //   return ::windowing::window::SetTimer(uEvent, nElapse, pfnTimer);

   //   //return ::windowing::window::SetTimer(uEvent, nElapse, lpfnTimer);


   //   //__UNREFERENCED_PARAMETER(lpfnTimer);

   //   //m_puserinteraction->get_app()->set_timer(m_puserinteraction, uEvent, nElapse);

   //   //return uEvent;

   //   //throw ::not_implemented();
   //   //ASSERT(::is_window((oswindow) get_handle()));
   //   //return ::SetTimer(get_handle(), uEvent, nElapse, lpfnTimer);

   //}


   ////bool interaction_impl::KillTimer(uptr uEvent)
   ////{

   ////   return ::windowing::window::KillTimer(uEvent);

   ////   //m_puserinteraction->get_app()->unset_timer(m_puserinteraction, uEvent);

   ////   //return true;

   ////   //ASSERT(::is_window((oswindow) get_handle()));
   ////   //return ::KillTimer(get_handle(), uEvent)  != false;

   ////}

   ////bool interaction_impl::IsWindowEnabled()
   ////{

   ////   return m_bEnabled;

   ////}


   ////bool interaction_impl::EnableWindow(bool bEnable)
   ////{

   ////   return m_bEnabled = bEnable;

   ////}

   //::user::interaction * interaction_impl::GetActiveWindow()
   //{

   //   return ::android::interaction_impl::ui_from_handle(::get_active_window());

   //}

   //::user::interaction * interaction_impl::set_active_window()
   //{

   //   return ::android::interaction_impl::ui_from_handle(::set_active_window(get_handle()));

   //}


//::user::interaction * interaction_impl::SetCapture(::user::interaction * pinterface)
//{
//
//
//}


   //::user::interaction * PASCAL interaction_impl::GetFocus()
   //{

   //   oswindow w = ::get_focus();

   //   if (!::is_window(w))
   //   {

   //      return nullptr;

   //   }

   //   return w->get_user_interaction();

   //}


   //bool interaction_impl::XXXSetFocus()
   //{

   //   ASSERT(::is_window((oswindow)get_handle()));

   //   oswindow w = ::set_focus(get_handle());

   //   if (!::is_window(w))
   //      return false;

   //   return w->get_user_interaction();

   //}


   //bool interaction_impl::has_keyboard_focus()
   //{

   //   return get_handle() == ::get_focus();

   //}


   //bool interaction_impl::is_active()
   //{

   //   return get_handle() == ::get_active_window();

   //}


   //::user::interaction * PASCAL interaction_impl::get_desktop_window()
   //{

   //   return nullptr;

   //}


   //// Helper for radio buttons
   //int interaction_impl::GetCheckedRadioButton(int nIDFirstButton, int nIDLastButton)
   //{

   //   for (int nID = nIDFirstButton; nID <= nIDLastButton; nID++)
   //   {

   //      if (IsDlgButtonChecked(nID))
   //      {

   //         return nID; // atom that matched

   //      }

   //   }

   //   return 0; // invalid ID

   //}


   //void interaction_impl::CheckDlgButton(int nIDButton, unsigned int nCheck)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      ::CheckDlgButton(get_handle(), nIDButton, nCheck);

   //}

   //void interaction_impl::CheckRadioButton(int nIDFirstButton, int nIDLastButton, int nIDCheckButton)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      ::CheckRadioButton(get_handle(), nIDFirstButton, nIDLastButton, nIDCheckButton);

   //}

   //int interaction_impl::DlgDirList(char * lpPathSpec, int nIDListBox, int nIDStaticPath, unsigned int nFileType)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::DlgDirList(get_handle(), lpPathSpec, nIDListBox, nIDStaticPath, nFileType);

   //}

   //int interaction_impl::DlgDirListComboBox(char * lpPathSpec, int nIDComboBox, int nIDStaticPath, unsigned int nFileType)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::DlgDirListComboBox(get_handle(), lpPathSpec, nIDComboBox, nIDStaticPath, nFileType);

   //}

   //bool interaction_impl::DlgDirSelect(char * lpString, int nSize, int nIDListBox)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::DlgDirSelectEx(get_handle(), lpString, nSize, nIDListBox) != false;

   //}

   //bool interaction_impl::DlgDirSelectComboBox(char * lpString, int nSize, int nIDComboBox)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::DlgDirSelectComboBoxEx(get_handle(), lpString, nSize, nIDComboBox) != false;

   //}

   /*
   void interaction_impl::GetDlgItem(atom atom, oswindow* phWnd) const
   {

   ASSERT(::is_window((oswindow) get_handle()));
   ASSERT(phWnd != nullptr);
   *phWnd = ::GetDlgItem(get_handle(), (int) atom);

   }
   */

   /*
   unsigned int interaction_impl::GetDlgItemInt(int nID, int_bool * lpTrans, bool bSigned) const
   {

   ASSERT(::is_window((oswindow) get_handle()));

   return ::GetDlgItemInt(get_handle(), nID, lpTrans, bSigned);

   }
   */

//   int interaction_impl::GetDlgItemText(int nID, char * lpStr, int nMaxCount) const
//   {
//
//      throw ::not_implemented();
//      ASSERT(::is_window((oswindow) get_handle())); return ::GetDlgItemText(get_handle(), nID, lpStr, nMaxCount);}

   //::user::interaction * interaction_impl::GetNextDlgGroupItem(::user::interaction * pWndCtl, bool bPrevious) const
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::android::interaction_impl::from_handle(::GetNextDlgGroupItem(get_handle(), (oswindow) pWndCtl->get_handle(), bPrevious));

   //}

   //::user::interaction * interaction_impl::GetNextDlgTabItem(::user::interaction * pWndCtl, bool bPrevious) const
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::android::interaction_impl::from_handle(::GetNextDlgTabItem(get_handle(), (oswindow) pWndCtl->get_handle(), bPrevious));

   //}

   //unsigned int interaction_impl::IsDlgButtonChecked(int nIDButton) const
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::IsDlgButtonChecked(get_handle(), nIDButton);

   //}

   //LPARAM interaction_impl::SendDlgItemMessage(int nID, ::enum_message emessage, ::wparam wparam, ::lparam lparam)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::SendDlgItemMessage(get_handle(), nID, message, wparam, lparam);

   //}

   //void interaction_impl::SetDlgItemInt(int nID, unsigned int nValue, bool bSigned)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      ::SetDlgItemInt(get_handle(), nID, nValue, bSigned);

   //}

   //void interaction_impl::SetDlgItemText(int nID, const ::string & lpszString)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      ::SetDlgItemText(get_handle(), nID, lpszString);

   //}

   //int interaction_impl::ScrollWindowEx(int dx, int dy, const ::int_rectangle * lpRectScroll, const ::int_rectangle * lpRectClip, ::draw2d::region * prgnUpdate, ::int_rectangle * lpRectUpdate, unsigned int flags)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::ScrollWindowEx(get_handle(), dx, dy, lpRectScroll, lpRectClip, (HRGN)prgnUpdate->get_handle(), lpRectUpdate, flags);

   //}

   //void interaction_impl::ShowScrollBar(unsigned int nBar, bool bShow)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      ::ShowScrollBar(get_handle(), nBar, bShow);

   //}

   //::user::interaction * interaction_impl::ChildWindowFromPoint(::int_point int_point)
   //{


   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::android::interaction_impl::from_handle(::ChildWindowFromPoint(get_handle(), int_point));

   //}

   //::user::interaction * interaction_impl::ChildWindowFromPoint(::int_point point, unsigned int nFlags)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::android::interaction_impl::from_handle(::ChildWindowFromPointEx(get_handle(), point, nFlags));

   //}






   //::user::interaction * interaction_impl::GetTopWindow() const
   //{



   //   if (m_puserinteraction->m_uiptraChild.get_size() <= 0)
   //      return nullptr;

   //   return m_puserinteraction->m_uiptraChild[0];
   //   //  throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::android::interaction_impl::from_handle(::GetTopWindow(get_handle()));

   //}

   //::user::interaction * interaction_impl::GetWindow(unsigned int nCmd)
   //{

   //   ASSERT(::is_window((oswindow)get_handle()));
   //   //      return ::android::interaction_impl::from_handle(::GetWindow(get_handle(), nCmd));
   //   return nullptr;

   //}

   //::user::interaction * interaction_impl::GetLastActivePopup()
   //{


   //   throw ::exception(todo);
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::android::interaction_impl::from_handle(::GetLastActivePopup(get_handle()));

   //}


   //::user::interaction * interaction_impl::SetParent(::user::interaction * pWndNewParent)
   //{

   //   ASSERT(::is_window((oswindow)get_handle()));

   //   return ::android::interaction_impl::ui_from_handle(::SetParent(get_handle(), (oswindow)pWndNewParent->get_handle()));

   //}


   //::user::interaction * PASCAL interaction_impl::oswindowFromPoint(::int_point int_point)
   //{


   //   throw ::not_implemented();
   //   //      return ::android::interaction_impl::from_handle(::oswindowFromPoint(point));

   //}

   //bool interaction_impl::FlashWindow(bool bInvert)
   //{


   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::FlashWindow(get_handle(), bInvert) != false;

   //}

   //bool interaction_impl::ChangeClipboardChain(oswindow hWndNext)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::ChangeClipboardChain(get_handle(), hWndNext) != false;

   //}

   //oswindow interaction_impl::SetClipboardViewer()
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::SetClipboardViewer(get_handle());

   //}

   //bool interaction_impl::OpenClipboard()
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::OpenClipboard(get_handle()) != false;

   //}

   //::user::interaction * PASCAL interaction_impl::GetOpenClipboardWindow()
   //{

   //   throw ::not_implemented();
   //   //      return ::android::interaction_impl::from_handle(::GetOpenClipboardWindow());

   //}

   //::user::interaction * PASCAL interaction_impl::GetClipboardOwner()
   //{

   //   throw ::not_implemented();
   //   //      return ::android::interaction_impl::from_handle(::GetClipboardOwner());

   //}

   //::user::interaction * PASCAL interaction_impl::GetClipboardViewer()
   //{

   //   throw ::not_implemented();
   //   //      return ::android::interaction_impl::from_handle(::GetClipboardViewer());

   //}



   //int_point PASCAL interaction_impl::GetCaretPos()
   //{

   //   throw ::not_implemented();
   //   //      ::int_point point;
   //   //      ::GetCaretPos((::int_point *)&point); return point;

   //}

   //void PASCAL interaction_impl::SetCaretPos(::int_point int_point)
   //{

   //   throw ::not_implemented();
   //   //      ::SetCaretPos(point.x, point.y);

   //}

   //void interaction_impl::HideCaret()
   //{

   //   throw ::not_implemented();
   //   //      ::HideCaret(get_handle());

   //}

   //void interaction_impl::ShowCaret()
   //{

   //   throw ::not_implemented();
   //   //    ::ShowCaret(get_handle());

   //}

   //bool interaction_impl::set_foreground_window()
   //{

   //   //    throw ::not_implemented();
   //   //      return ::XXXSetForegroundWindow(get_handle()) != false;

   //   return false;

   //}

   //::user::interaction * PASCAL interaction_impl::GetForegroundWindow()
   //{

   //   return nullptr;

   //   throw ::not_implemented();
   //   //      return ::android::interaction_impl::from_handle(::GetForegroundWindow());

   //}

   //bool interaction_impl::SendNotifyMessage(::enum_message emessage, ::wparam wparam, ::lparam lparam)
   //{

   //   throw ::not_implemented();
   //   //      return ::SendNotifyMessage(get_handle(), message, wparam, lparam) != false;

   //}

   //void interaction_impl::Print(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      const_cast < interaction_impl * > (this)->send_message(WM_PRINT, (WPARAM)(dynamic_cast<::android::graphics * >(pgraphics))->get_handle(), dwFlags);

   //}

   //void interaction_impl::PrintClient(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      const_cast < interaction_impl * > (this)->send_message(WM_PRINTCLIENT, (WPARAM)(dynamic_cast<::android::graphics * >(pgraphics))->get_handle(), dwFlags);

   //}

   //bool interaction_impl::SetWindowContextHelpId(unsigned int dwContextHelpId)
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::SetWindowContextHelpId(get_handle(), dwContextHelpId) != false;

   //}

   //unsigned int interaction_impl::GetWindowContextHelpId() const
   //{

   //   throw ::not_implemented();
   //   //      ASSERT(::is_window((oswindow) get_handle()));
   //   //      return ::GetWindowContextHelpId(get_handle());

   //}


// Default message ::collection::map implementations
   //void interaction_impl::OnActivateApp(bool, unsigned int)
   //{
   //   Default();
   //}
   //void interaction_impl::OnActivate(unsigned int, ::user::interaction *, bool)
   //{
   //   Default();
   //}
   //void interaction_impl::OnCancelMode()
   //{
   //   Default();
   //}
   //void interaction_impl::OnChildActivate()
   //{
   //   Default();
   //}
   //void interaction_impl::OnClose()
   //{
   //   Default();
   //}
   //void interaction_impl::OnContextMenu(::user::interaction *, int_point)
   //{
   //   Default();
   //}

   //bool interaction_impl::OnCopyData(::user::interaction *, COPYDATASTRUCT*)
   //{

   //   return Default() != false;

   //}

   //void interaction_impl::OnEnable(bool)
   //{
   //   Default();
   //}
   //void interaction_impl::OnEndSession(bool)
   //{
   //   Default();
   //}

   //bool interaction_impl::OnEraseBkgnd(::draw2d::graphics *)
   //{

   //   return Default() != false;

   //}

   //void interaction_impl::OnGetMinMaxInfo(MINMAXINFO*)
   //{
   //   Default();
   //}
   //void interaction_impl::OnIconEraseBkgnd(::draw2d::graphics *)
   //{
   //   Default();
   //}
   //void interaction_impl::OnKillFocus(::user::interaction *)
   //{
   //   Default();
   //}
   //LRESULT interaction_impl::OnMenuChar(unsigned int, unsigned int, ::user::menu*)
   //{
   //   return Default();
   //}
   //void interaction_impl::OnMenuSelect(unsigned int, unsigned int, HMENU)
   //{
   //   Default();
   //}
   //void interaction_impl::OnMove(int, int)
   //{
   //   Default();
   //}

   //bool interaction_impl::OnQueryEndSession()
   //{

   //   return Default() != false;

   //}

   //bool interaction_impl::OnQueryNewPalette()
   //{

   //   return Default() != false;

   //}

   //bool interaction_impl::OnQueryOpen()
   //{

   //   return Default() != false;

   //}


   // void interaction_impl::on_message_set_cursor(::message::message * pmessage)
   // {

   //    ::pointer<::user::message>pusermessage(pmessage);

   //    

   //    if (psession->get_cursor() != nullptr
   //          && psession->get_cursor()->m_ecursor != ::cursor_system)
   //    {

   //       throw ::not_implemented();
   //       //         ::SetCursor(nullptr);
   //    }
   //    pusermessage->set_lresult(1);
   //    pusermessage->m_bRet = true;
   //    //(bool)Default();
   // }



   //void interaction_impl::on_message_size(::message::message * pmessage)
   //{
   //   __UNREFERENCED_PARAMETER(pmessage);

   //   //int_size sizeRequest = m_puserinteraction->m_rectangleParentClientRequest.size();

   //   //for (auto & pinteraction : m_puserinteraction->m_uiptraChild)
   //   //{

   //   //   pinteraction->ResizeWindow(sizeRequest);

   //   //}



   //}



   //void interaction_impl::OnShowWindow(bool, unsigned int)
   //{
   //   Default();
   //}
   //void interaction_impl::OnSize(unsigned int, int, int)
   //{
   //   Default();
   //}
   //void interaction_impl::OnTCard(unsigned int, unsigned int)
   //{
   //   Default();
   //}
   //void interaction_impl::OnWindowPosChanging(WINDOWPOS*)
   //{
   //   Default();
   //}
   //void interaction_impl::OnWindowPosChanged(WINDOWPOS*)
   //{
   //   Default();
   //}
   //void interaction_impl::OnDropFiles(HDROP)
   //{
   //   Default();
   //}
//   void interaction_impl::OnPaletteIsChanging(::user::interaction *)
//   {
//      Default();
//   }
//
//   bool interaction_impl::OnNcActivate(bool)
//   {
//
//      return Default() != false;
//
//   }
//
//   /*void interaction_impl::OnNcCalcSize(bool, NCCALCSIZE_PARAMS*)
//   {
//      Default();
//   }*/
//
//   bool interaction_impl::OnNcCreate(::user::system *)
//   {
//
//      return Default() != false;
//
//   }
//
//   LRESULT interaction_impl::OnNcHitTest(point)
//   {
//      return Default();
//   }
//   //void interaction_impl::OnNcLButtonDblClk(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnNcLButtonDown(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnNcLButtonUp(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnNcMButtonDblClk(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnNcMButtonDown(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnNcMButtonUp(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnNcMouseMove(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   void interaction_impl::OnNcPaint()
//   {
//      Default();
//   }
//   //void interaction_impl::OnNcRButtonDblClk(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnNcRButtonDown(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnNcRButtonUp(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   void interaction_impl::OnSysChar(unsigned int, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnSysCommand(unsigned int, LPARAM)
//   {
//      Default();
//   }
//   void interaction_impl::OnSysDeadChar(unsigned int, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnSysKeyDown(unsigned int, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnSysKeyUp(unsigned int, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnCompacting(unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnFontChange()
//   {
//      Default();
//   }
//   void interaction_impl::OnPaletteChanged(::user::interaction *)
//   {
//      Default();
//   }
//   void interaction_impl::OnSpoolerStatus(unsigned int, unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnTimeChange()
//   {
//      Default();
//   }
//   void interaction_impl::OnChar(unsigned int, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnDeadChar(unsigned int, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnKeyDown(unsigned int, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnKeyUp(unsigned int, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   //void interaction_impl::OnLButtonDblClk(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnLButtonDown(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnLButtonUp(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnMButtonDblClk(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnMButtonDown(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnMButtonUp(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //int interaction_impl::OnMouseActivate(::user::interaction *, unsigned int, unsigned int)
//   //{
//   //   return (int)Default();
//   //}
//   //void interaction_impl::OnMouseMove(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//
//   //bool interaction_impl::OnMouseWheel(unsigned int, short, int_point)
//   //{
//
//   //   return Default() != false;
//
//   //}
//
//   LRESULT interaction_impl::OnRegisteredMouseWheel(WPARAM, LPARAM)
//   {
//      return Default();
//   }
//   //void interaction_impl::OnRButtonDblClk(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnRButtonDown(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnRButtonUp(unsigned int, int_point)
//   //{
//   //   Default();
//   //}
//   void interaction_impl::OnTimer(uptr)
//   {
//      Default();
//   }
//   //void interaction_impl::OnInitMenu(::user::menu*)
//   //{
//   //   Default();
//   //}
//   //void interaction_impl::OnInitMenuPopup(::user::menu*, unsigned int, bool)
//   //{
//   //   Default();
//   //}
//   void interaction_impl::OnAskCbFormatName(unsigned int nMaxCount, char * pszName)
//   {
//      (nMaxCount);
//      if (nMaxCount>0)
//      {
//         /* defwindow proc should do this for us, but to be safe, we'hi do it here too */
//         pszName[0] = '\0';
//      }
//      Default();
//   }
//   void interaction_impl::OnChangeCbChain(oswindow, oswindow)
//   {
//      Default();
//   }
//   void interaction_impl::OnDestroyClipboard()
//   {
//      Default();
//   }
//   void interaction_impl::OnDrawClipboard()
//   {
//      Default();
//   }
//   void interaction_impl::OnHScrollClipboard(::user::interaction *, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   //void interaction_impl::OnPaintClipboard(::user::interaction *, HGLOBAL)
//   //{
//   //   Default();
//   //}
//   void interaction_impl::OnRenderAllFormats()
//   {
//      Default();
//   }
//   void interaction_impl::OnRenderFormat(unsigned int)
//   {
//      Default();
//   }
//   //void interaction_impl::OnSizeClipboard(::user::interaction *, HGLOBAL)
//   //{
//   //   Default();
//   //}
//   void interaction_impl::OnVScrollClipboard(::user::interaction *, unsigned int, unsigned int)
//   {
//      Default();
//   }
//   unsigned int interaction_impl::OnGetDlgCode()
//   {
//      return (unsigned int)Default();
//   }
//   void interaction_impl::OnMDIActivate(bool, ::user::interaction *, ::user::interaction *)
//   {
//      Default();
//   }
//   void interaction_impl::OnEnterMenuLoop(bool)
//   {
//      Default();
//   }
//   void interaction_impl::OnExitMenuLoop(bool)
//   {
//      Default();
//   }
//// Win4 support
////   void interaction_impl::OnStyleChanged(int, LPSTYLESTRUCT)
////   { Default(); }
////   void interaction_impl::OnStyleChanging(int, LPSTYLESTRUCT)
////   { Default(); }
//   void interaction_impl::OnSizing(unsigned int, ::int_rectangle *)
//   {
//      Default();
//   }
//   void interaction_impl::OnMoving(unsigned int, ::int_rectangle *)
//   {
//      Default();
//   }
//   void interaction_impl::OnCaptureChanged(::user::interaction *)
//   {
//      Default();
//   }
//
//   bool interaction_impl::OnDeviceChange(unsigned int, dword_ptr)
//   {
//
//      return Default() != false;
//
//   }
//
//   void interaction_impl::OnWinIniChange(const ::string &)
//   {
//      Default();
//   }
//   void interaction_impl::OnChangeUIState(unsigned int, unsigned int)
//   {
//      Default();
//   }
//   void interaction_impl::OnUpdateUIState(unsigned int, unsigned int)
//   {
//      Default();
//   }
//
//   unsigned int interaction_impl::OnQueryUIState()
//   {
//
//      return (unsigned int)Default();
//
//   }
//
// interaction_impl dialog data support
//    void interaction_impl::DoDataExchange(CDataExchange*)
//   { } // default does nothing

// interaction_impl modality support

//   void interaction_impl::BeginModalState()
//   {
//
//      throw ::exception(todo);
//
//      //::EnableWindow(get_handle(), false);
//
//   }
//
//   void interaction_impl::EndModalState()
//   {
//
//      throw ::exception(todo);
//
//      //::EnableWindow(get_handle(), true);
//
//   }
//
//// frame_window
//   /*    void frame_window::DelayUpdateFrameTitle()
//   { m_nIdleFlags |= idleTitle; }
//   void frame_window::DelayRecalcLayout(bool bNotify)
//   { m_nIdleFlags |= (idleLayout | (bNotify ? idleNotify : 0)); };
//   bool frame_window::InModalState() const
//   { return m_cModalStack != 0; }
//   void frame_window::set_title(const ::string & lpszTitle)
//   { m_strTitle = lpszTitle; }
//   string frame_window::get_title() const
//   { return m_strTitle; }
//   */
//
//
//
//   void interaction_impl::CloseWindow()
//   {
//
//      throw ::not_implemented();
//      //      ASSERT(::is_window((oswindow) get_handle()));
//      //      ::CloseWindow(get_handle());
//
//   }
//
//   bool interaction_impl::OpenIcon()
//   {
//
//      throw ::not_implemented();
//      //      ASSERT(::is_window((oswindow) get_handle()));
//      //      return ::OpenIcon(get_handle()) != false;
//
//   }
//
////////////////////////////////////////////////////////////////////////////////
////// UI related ::windowing::window functions
////
////   oswindow PASCAL interaction_impl::GetSafeOwner_(oswindow hParent, oswindow* pWndTop)
////   {
////      // get ::windowing::window to start with
////      oswindow hWnd = hParent;
////      if (hWnd == nullptr)
////      {
////         /* trans      ::pointer<frame_window>pFrame = channel::GetRoutingFrame_();
////         if (pFrame != nullptr)
////         hWnd = pFrame->get_handle();
////         else
////         hWnd = ::auraacmesystem()->GetMainWnd()->get_handle();*/
////      }
////
////      // a popup ::windowing::window cannot be owned by a child ::windowing::window
////      while (hWnd != nullptr && (::GetWindowLong(hWnd, GWL_STYLE) & WS_CHILD))
////         hWnd = ::get_parent(hWnd);
////
////      // determine toplevel ::windowing::window to disable as well
////      oswindow hWndTop = hWnd, hWndTemp = hWnd;
////      for (;;)
////      {
////         if (hWndTemp == nullptr)
////            break;
////         else
////            hWndTop = hWndTemp;
////         hWndTemp = ::get_parent(hWndTop);
////      }
////
////      throw ::exception(todo);
////      // get last active popup of first non-child that was found
////      //    if (hParent == nullptr && hWnd != nullptr)
////      //       hWnd = ::GetLastActivePopup(hWnd);
////
////      // disable and store top level parent ::windowing::window if specified
////      if (pWndTop != nullptr)
////      {
////         /*         if (hWndTop != nullptr && ::IsWindowEnabled(hWndTop) && hWndTop != hWnd)
////         {
////         *pWndTop = hWndTop;
////         ::EnableWindow(hWndTop, false);
////         }
////         else
////         *pWndTop = nullptr;*/
////      }
////
////      return hWnd;    // return the owner as oswindow
////   }
//
////void interaction_impl::on_delete(::object * pinteraction)
////{
////   __UNREFERENCED_PARAMETER(pinteraction);
////}
//
//
////
////
////void interaction_impl::_001OnEraseBkgnd(::message::message * pmessage)
////{
////   ::pointer<::message::erase_bkgnd>perasebkgnd(pmessage);
////   perasebkgnd->m_bRet = true;
////   perasebkgnd->set_result(true);
////}
//
//   void interaction_impl::_001BaseWndInterfaceMap()
//   {
//
//      ::auraacmesystem()->window_map().set(get_handle(), this);
//
//   }
//
//
   //void interaction_impl::_001OnTriggerMouseInside()
   //{


   //   ::windowing::window::_001OnTriggerMouseInside();

   //}


   //void interaction_impl::set_context_org(::draw2d::graphics_pointer & pgraphics)
   //{
   //   // graphics will be already set its impact port to the interaction_impl for android - cairo with xlib

   //   pgraphics->SetViewportOrg(::int_point());

   //   /*      long_long_rectangle rectangleWindow;
   //   window_rectangle(rectangleWindow);
   //   get_wnd()->screen_to_client(rectangleWindow);
   //   pgraphics->SetViewportOrg(int_point(rectangleWindow.top_left()));
   //   pgraphics->SelectClipRgn(nullptr);
   //   */

   //}


   //::user::interaction * interaction_impl::GetNextWindow(unsigned int nFlag)
   //{

   //   if (nFlag == GW_HWNDNEXT)
   //   {

   //      return get_next(true, nullptr);

   //   }
   //   else
   //   {

   //      throw ::interface_only();

   //   }

   //}


   //::user::interaction * interaction_impl::get_next(bool bIgnoreChildren, int * piLevel)
   //{

   //   return  m_puserinteraction->get_next(bIgnoreChildren, piLevel);

   //}





   //::windowing::window * interaction_impl::from_handle(oswindow oswindow)
   //{

   //   return oswindow_interaction_impl(oswindow);

   //}


   //::user::interaction * interaction_impl::ui_from_handle(oswindow oswindow)
   //{

   //   return oswindow_interaction(oswindow);

   //}

   bool interaction_impl::has_pending_graphical_update()
   {

      {

         synchronous_lock synchronouslock(m_puserinteraction->synchronization());

         auto puserinteractionpointeraChild = m_puserinteraction->m_puserinteractionpointeraChild;

         if (puserinteractionpointeraChild)
         {

            for (auto & p : puserinteractionpointeraChild->interactiona())
            {

               if (p->has_pending_graphical_update())
               {

                  return true;

               }

            }

         }

      }

      return false;

   }


   void interaction_impl::edit_on_set_focus(::user::interaction* pinteraction)
   {

      auto puserinteraction = pinteraction->parent_frame();

      ::int_rectangle rWindowFrame;

      puserinteraction->window_rectangle(rWindowFrame);

      ::int_rectangle r1;

      pinteraction->window_rectangle(r1);

      ::int_size size = m_puserinteraction->get_client_size();

      int iSoftwareKeyboardTop = size.cy() / 2;

      if (r1.top() > iSoftwareKeyboardTop)
      {

         m_iSoftwareKeyboardScroll = r1.bottom() - iSoftwareKeyboardTop;

         puserinteraction->m_pointScroll.y() = m_iSoftwareKeyboardScroll;

      }

      puserinteraction->set_need_redraw();

      puserinteraction->post_redraw();

      ::int_rectangle r2;

      pinteraction->window_rectangle(r2);

      string strText;

      pinteraction->get_text(strText);

      character_count iBeg = 0;

      character_count iEnd = 0;

      pinteraction->_001GetSel(iBeg, iEnd);

      android_edit_on_set_focus(r2.left(), r2.top(), r2.right(), r2.bottom(), strText, iBeg, iEnd);

   }


   void interaction_impl::edit_on_kill_focus(::user::interaction* pinteraction)
   {

      auto puserinteraction = pinteraction->parent_frame();

      ::int_rectangle rWindowFrame;

      puserinteraction->window_rectangle(rWindowFrame);

      if (m_iSoftwareKeyboardScroll > 0)
      {

         puserinteraction->m_pointScroll.y() -= m_iSoftwareKeyboardScroll;

         m_iSoftwareKeyboardScroll = 0;

      }

      android_edit_on_kill_focus();

   }
   

   void interaction_impl::show_software_keyboard(::user::element * pelement)
   {

      auto pwindowing = m_puserinteraction->windowing();

      auto ptexteditorinterface = pwindowing->get_text_editor_interface();

      if (::is_set(ptexteditorinterface))
      {

         ptexteditorinterface->show_software_keyboard();

      }

      m_pelementSoftwareKeyboard = pelement;

   }


   void interaction_impl::hide_software_keyboard(::user::element * pelement)
   {

      if (!::is_null(pelement) && pelement != m_pelementSoftwareKeyboard)
      {

         throw ::exception(::error_bad_argument);

      }

      m_pelementSoftwareKeyboard = nullptr;

      auto pwindowing = m_puserinteraction->windowing();

      auto ptexteditorinterface = pwindowing->get_text_editor_interface();

      if (::is_set(ptexteditorinterface))
      {

         ptexteditorinterface->hide_software_keyboard();

      }

   }

   
   void interaction_impl::on_after_graphical_update()
   {

      auto pwindowing = m_puserinteraction->windowing();

      auto papplicationhostwindow = pwindowing->get_application_host_window();

      if (::is_set(papplicationhostwindow))
      {

         papplicationhostwindow->m_pwindow->m_puserinteraction->set_need_redraw();

      }

   }


} // namespace aura_android



