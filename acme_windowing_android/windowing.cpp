// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:35 <3TBS, Mummi and bilbo!!
// Adapted by Camilo for android 2022-01-05 04:36 <3TBS (Thomas likes number 5), Mummi and bilbo!!
#include "framework.h"
#include "windowing.h"
#include "window.h"
#include "display.h"
#include "acme/constant/user_message.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/application.h"
#include "acme/platform/application_state.h"
#include "acme/platform/node.h"
#include "acme/windowing/sandbox/host_interaction.h"
#include "android/jni_bind.h"
//#include "aura/user/user/interaction_impl.h"
//#include "aura/windowing/sandbox/host_interaction.h"
//#include "android/_internal.h"
//#include "aura/windowing/cursor_manager.h"


namespace android
{


    namespace acme
    {


        namespace windowing
        {


            windowing::windowing()
            {

               defer_create_synchronization();

               m_bRootSelectInput = false;

               //m_itask = -1;

               //m_pWindowing4 = this;

               m_bFirstWindowMap = false;

               //m_bInitX11Thread = false;

               //m_bFinishX11Thread = false;

               //defer_initialize_x11();

            }


            windowing::~windowing()
            {


            }


            void windowing::on_start_system()
            {

               system()->on_branch_system_from_main_thread_startup(this);

            }


            void windowing::on_start_windowing_application()
            {

               ::acme::sandbox_windowing::windowing::on_start_windowing_application();

            }


            bool windowing::is_branch_current() const
            {

               auto itaskCurrent = current_itask();

               return itaskCurrent == m_itask;


            }


//            ::windowing::window *windowing::new_window(::windowing::window *pimpl)
//            {
//
//               ::pointer<::windowing_android::window> pwindow = pimpl->__create<::windowing::window>();
//
//               if (!pwindow) {
//
//                  return nullptr;
//
//               }
//
//               pwindow->m_pwindowing = this;
//
//               pwindow->m_pwindow = pimpl;
//
//               pimpl->m_pwindow = pwindow;
//
//               pwindow->create_window(pimpl);
//
//               return pwindow;
//
//            }


//            void windowing::erase_window(::windowing::window *pwindow)
//            {
//
//               //m_pdisplay->erase_window(pwindow);
//
//            }


            void windowing::initialize(::particle *pparticle)
            {

               //auto estatus =
               //
               ::acme::windowing::windowing::initialize(pparticle);

               //      if(!estatus)
               //      {
               //
               //         return estatus;
               //
               //      }

               initialize_windowing();

               auto pdisplay = øcreate<::acme::windowing::display>();

               //      if(!pdisplay)
               //      {
               //
               //         output_debug_string("\nFailed to __create < ::windowing::display > at windowing_x11::windowing::initialize");
               //
               //         return ::error_no_factory;
               //
               //      }

               //estatus =
               //
               //pdisplay->initialize_display(this);

               //      if(!estatus)
               //      {
               //
               //         output_debug_string("\nFailed to initialize_display at windowing_x11::windowing::initialize");
               //
               //         return estatus;
               //
               //      }

               m_pacmedisplay = pdisplay;

               //if (!pdisplay)
               //{

               //   throw ::exception(error_no_interface, "Failed to cast pdisplay to m_pdisplay at windowing_x11::windowing::initialize");

               //}

               //m_pdisplay->open();


               //_libsn_start_context();


               //      if(!estatus)
               //      {
               //
               //         output_debug_string("\nFailed to m_pdisplay->open at windowing_x11::windowing::initialize");
               //
               //         return estatus;
               //
               //      }
               //
               //      return ::success;

            }


            void windowing::defer_initialize_host_window(const ::int_rectangle *lpcrect)
            {

               ::acme::sandbox_windowing::windowing::defer_initialize_host_window(lpcrect);

//               if (::is_set(m_phostinteraction)) {
//
//                  return;
//
//               }
//
//               øconstruct_new(m_phostinteraction);
//
//               m_phostinteraction->set_rectangle(*lpcrect);
//
//               //m_phostinteraction->create_host(e_parallelization_synchronous);
//               m_phostinteraction->create_window();
//
//               m_phostinteraction->display();
//
//               //m_phostinteraction->set_need_layout();
//
//               m_phostinteraction->set_need_redraw();
//
//               m_phostinteraction->post_redraw();

            }


          bool windowing::task_iteration()
          {
             if(!::acme::sandbox_windowing::windowing::task_iteration())
             {

                return false;

             }

             auto papplicationstate = ::platform::application_state::get();

             papplicationstate->on_main_task_iteration();

             return true;

          }


            void windowing::windowing_application_main_loop()
            {

                node()->notify_system_started();

                __task_init();


                init_task();

                //set_current_handles();

                //::set_main_thread();

                //system()->defer_post_initial_request();

                //run();

                on_activate();

                //system()->defer_post_initial_request();

                on_start_windowing_application();

                ::string strAppId = m_papplication->m_strAppId;
//
                //session()->get_application(strAppId, true);

                //m_papplication->_post([this]()
                //   {

                //      m_papplication->m_bReadyToAttendRequests = true;

                //   });

                main();

                //while (true)
                //{

                //   if (!_process_windowing_messages())
                //   {

                //      break;

                //   }

                //}

                //if (::system()->m_pmanualresethappeningMainLoopEnd)
                //{

                //   ::system()->m_pmanualresethappeningMainLoopEnd->set_happening();

                //}

            }


            ::acme::windowing::window * windowing::get_application_host_window()
            {

               return m_pwindowApplicationHost;

            }

            //   void windowing::start()
            //   {
            //
            //      auto psystem = system();
            //
            //      if (psystem->m_bUser)
            //      {
            //
            //         defer_initialize_x11();
            //
            //      }
            //
            //      auto pnode = psystem->node();
            //
            //      if(pnode)
            //      {
            //
            //         _libsn_start_context();
            //
            //         branch_element(pnode);
            //
            //      }
            //      else
            //      {
            //
            //         x11_main();
            //
            //      }
            //
            //      //return ::success;
            //
            //   }


            //void windowing::windowing_post(const ::procedure & procedure)
            //{

            //   if (!procedure)
            //   {

            //      throw ::exception(error_null_pointer);

            //   }

            //   synchronous_lock synchronouslock(synchronization());

            //   m_procedurelist.add_tail(procedure);

            //   //return ::success_scheduled;

            //}


//            bool windowing::x11_runnable_step()
//            {
//
//               bool bHandled = false;
//
//               //if (m_pdisplay)
//               //{
//
//               //   if (m_pdisplay->m_px11display)
//               //   {
//
//               //      while (m_pdisplay->m_px11display->x11_posted())
//               //      {
//
//               //         bHandled = true;
//
//               //      }
//
//               //   }
//
//               //}
//
//               synchronous_lock synchronouslock(synchronization());
//
//               if (m_procedurelist.is_empty()) {
//
//                  return bHandled;
//
//               }
//
//               do {
//
//                  {
//
//                     auto routine = m_procedurelist.pick_head();
//
//                     synchronouslock.unlock();
//
//                     routine();
//
//                  }
//
//                  synchronouslock.lock();
//
//               } while (m_procedurelist.has_element());
//
//               return true;
//
//            }


//            ::acme::windowing::display *windowing::display()
//            {
//
//               return m_pdisplay;
//
//            }


            //::windowing_x11::window * windowing::_window(Window window)
            //{

            //   if (!m_pdisplay)
            //   {

            //      return nullptr;

            //   }

            //   auto pwindow = m_pdisplay->_window(window);

            //   return pwindow;

            //}


//            ::pointer<::windowing::cursor> windowing::load_default_cursor(enum_cursor ecursor)
//            {
//
//               synchronous_lock synchronouslock(synchronization());
//
//               if (!m_pcursormanager) {
//
//                  //auto estatus =
//                  //
//                  //
//                  øconstruct_new(m_pcursormanager);
//
//                  //         if (!estatus)
//                  //         {
//                  //
//                  //            return nullptr;
//                  //
//                  //         }
//
//               }
//
//               //auto & pcursor = m_pcursormanager->m_cursormap[ecursor];
//
//               //if (pcursor)
//               //{
//
//               //   return pcursor;
//
//               //}
//
//               //int iCursor = 0;
//
//               //if (ecursor == e_cursor_size_top_left)
//               //{
//
//               //   iCursor = XC_top_left_corner;
//
//               //}
//               //else if (ecursor == e_cursor_size_top_right)
//               //{
//
//               //   iCursor = XC_top_right_corner;
//
//               //}
//               //else if (ecursor == e_cursor_size_top)
//               //{
//
//               //   iCursor = XC_top_side;
//
//               //}
//               //else if (ecursor == e_cursor_size_right)
//               //{
//
//               //   iCursor = XC_right_side;
//
//               //}
//               //else if (ecursor == e_cursor_size_left)
//               //{
//
//               //   iCursor = XC_left_side;
//
//               //}
//               //else if (ecursor == e_cursor_size_bottom)
//               //{
//
//               //   iCursor = XC_bottom_side;
//
//               //}
//               //else if (ecursor == e_cursor_size_bottom_left)
//               //{
//
//               //   iCursor = XC_bottom_left_corner;
//
//               //}
//               //else if (ecursor == e_cursor_size_bottom_right)
//               //{
//
//               //   iCursor = XC_bottom_right_corner;
//
//               //}
//               //else if (ecursor == e_cursor_arrow)
//               //{
//
//               //   iCursor = XC_arrow;
//
//               //}
//
//               //if (iCursor == 0)
//               //{
//
//               //   return nullptr;
//
//               //}
//
//               //synchronous_lock sl(user_mutex());
//
//               windowing_output_debug_string("\n::x11_GetWindowRect 1");
//
//               //display_lock lock(m_pdisplay->Display());
//
//               //auto cursor = XCreateFontCursor(m_pdisplay->Display(), iCursor);
//
//               //auto pcursorX11 = __create < ::windowing_x11::cursor >();
//
//               //pcursor = pcursorX11;
//
//               //pcursorX11->m_cursor = cursor;
//
//               //return pcursor;
//
//               return nullptr;
//
//            }

//
//            ::windowing::window *windowing::window(oswindow oswindow)
//            {
//
//               return oswindow;
//
//            }
//

            void windowing::_message_handler(void *p)
            {

               XEvent *pevent = (XEvent *) p;

            }


            //::windowing::window * windowing::get_keyboard_focus(::thread *)
            //{

            //   auto pwindowApplicationHost = get_application_host_window();

            //   if (!pwindowApplicationHost->m_pwindow->aaa_m_pacmeuserinteractionKeyboardFocus)
            //   {

            //      return nullptr;

            //   }

            //   return pwindowApplicationHost;

            //}


            //::windowing::window * windowing::get_mouse_capture(::thread *)
            //{

            //   //if (!m_pdisplay)
            //   //{

            //   //   return nullptr;

            //   //}

            //   ////auto pwindow = m_pdisplay->get_mouse_capture();

            //   ////return pwindow;

            //   return nullptr;

            //}


            //::windowing::window * windowing::window(oswindow oswindow)
            //{

            //   return oswindow;

            //}

            bool windowing::defer_release_mouse_capture(::thread *pthread,
                                             ::acme::windowing::window *pwindow)
            {

            //void windowing::release_mouse_capture(::thread *pthread)
            //{

               if (!m_pwindowMouseCapture) {

                  return false;

               }

               auto pacmeuserinteractionCapture = m_pwindowMouseCapture->m_pacmeuserinteractionMouseCapture;

               if (pacmeuserinteractionCapture)
               {

                  m_pwindowMouseCapture->m_pacmeuserinteractionMouseCapture.release();

               }

               m_pwindowMouseCapture.release();

               //auto estatus =
               //
               //m_pdisplay->release_mouse_capture();

               //      if(!estatus)
               //      {
               //
               //         return estatus;
               //
               //      }
               //
               //      return estatus;

               return true;

            }


//            void windowing::clear_keyboard_focus(::user::element *pelementGainingFocusIfAny)
//            {
//
//               if (!m_pwindowKeyboardFocus) {
//
//                  return;
//
//               }
//
//               auto pwindow = m_pwindowKeyboardFocus->m_pwindow;
//
//               if (pwindow) {
//
//                  if (pwindow->m_pacmeuserinteractionKeyboardFocus) {
//
//                     pwindow->m_puserinteractionKeyboardGainingFocusIfAny = pelementGainingFocusIfAny;
//
//                     //pwindow->aaa_m_pacmeuserinteractionKeyboardFocus->post_message(::user::e_message_kill_focus);
//
//                  }
//
//                  auto puserinteraction = pwindow->m_puserinteraction;
//
//                  if (puserinteraction) {
//
//                     puserinteraction->post_message(::user::e_message_kill_focus);
//
//                  }
//
//                  //if (pwindow->aaa_m_pacmeuserinteractionKeyboardFocus)
//                  //{
//
//                  //   pwindow->m_puserinteractionKeyboardGainingFocusIfAny = pwindowGainingFocusIfAny;
//
//                  //   pwindow->aaa_m_pacmeuserinteractionKeyboardFocus->post_message(::user::e_message_kill_focus);
//
//                  //}
//
//                  pwindow->m_pacmeuserinteractionKeyboardFocus.release();
//
//               }
//
//               m_pwindowKeyboardFocus.release();
//
//               //auto estatus =
//               //
//               //m_pdisplay->release_mouse_capture();
//
//               //      if(!estatus)
//               //      {
//               //
//               //         return estatus;
//               //
//               //      }
//               //
//               //      return estatus;
//
//            }


//            ::windowing::text_editor_interface *windowing::get_text_editor_interface()
//            {
//
//               return ::operating_system_driver::get();
//
//            }


//            ::pointer<::windowing::cursor> windowing::get_cursor(enum_cursor ecursor)
//            {
//
//               return nullptr;
//
//            }
//

        } // namespace windowing


    } // namespace acme


} // namespace android




void defer_term_ui()
{



}


//::user::interaction * get_system_window_interaction(::os_system_window * psystemwindow)
//{
//
//   if (psystemwindow == nullptr)
//   {
//
//      return nullptr;
//
//   }
//
//   return psystemwindow->m_puserinteraction;
//
//}


//CLASS_DECL_AURA int oswindow_find_message_only_window(::windowing::window * puibaseMessageWindow);
//CLASS_DECL_AURA int oswindow_find(Display * pdisplay,Window window);
//CLASS_DECL_AURA int oswindow_find(Window window);
//CLASS_DECL_AURA oswindow_data * oswindow_get_message_only_window(::windowing::window * puibaseMessageWindow);
//CLASS_DECL_AURA oswindow_data * oswindow_get(Display * pdisplay,Window window,Visual * pvisual = nullptr,int iDepth = -1,int iScreen = -1,Colormap colormap = None);
//CLASS_DECL_AURA oswindow_data * oswindow_get(Window window);
//CLASS_DECL_AURA oswindow oswindow_defer_get(Window w);
//CLASS_DECL_AURA bool oswindow_erase(Display * pdisplay,Window window);
//CLASS_DECL_AURA bool oswindow_erase_message_only_window(::windowing::window * puibaseMessageOnlyWindow);


namespace user
{


   class primitive;
   class interaction;


} // namespace user



//oswindow_data::oswindow_data()
//{
//
//   m_pmq = nullptr;
//
//   m_htask = (htask) nullptr;
//
//   m_pimpl = nullptr;
//
//   m_bMessageOnlyWindow = false;
//
//   m_bDestroying = false;
//
//}
//
//
//oswindow_data::~oswindow_data()
//{
//
//}
//
//
//
//#define CA2_X11_WINDOW_LONG "ca2_ccwarehouse_fontopu_window_long"
//#define CA2_X11_WINDOW_LONG_STYLE "ca2_ccwarehouse_fontopu_window_long_style"
//#define CA2_X11_WINDOW_LONG_STYLE_EX "ca2_ccwarehouse_fontopu_window_long_style_ex"
//
////oswindow_dataptra * oswindow_data::s_pdataptra = ___new oswindow_dataptra;
////::mutex * oswindow_data::s_pmutex = ___new ::mutex;
//
//
//int oswindow_find_message_only_window(::windowing::window * pimpl)
//{
//
//   if (pimpl == nullptr)
//   {
//
//      return -1;
//
//   }
//
//   synchronous_lock slOsWindow(oswindow_data::s_pmutex);
//
//   for (int i = 0; i < ::oswindow_data::s_pdataptra->get_count(); i++)
//   {
//
//      if (::oswindow_data::s_pdataptra->element_at(i)->m_bMessageOnlyWindow
//            && ::oswindow_data::s_pdataptra->element_at(i)->m_pimpl == pimpl)
//      {
//
//         return i;
//
//      }
//
//   }
//
//   return -1;
//
//}
//
//
//
//int oswindow_find(::windowing::window * pimpl)
//{
//
//   synchronous_lock slOsWindow(::oswindow_data::s_pmutex);
//
//   for (int i = 0; i < ::oswindow_data::s_pdataptra->get_count(); i++)
//   {
//      if (!::oswindow_data::s_pdataptra->element_at(i)->m_bMessageOnlyWindow
//            &&  ::oswindow_data::s_pdataptra->element_at(i)->m_pimpl == pimpl)
//      {
//         return i;
//      }
//   }
//
//   return -1;
//
//}
//
//oswindow_data * oswindow_get_message_only_window(::windowing::window * pimpl)
//{
//
//   if (pimpl == nullptr)
//      return nullptr;
//
//   synchronous_lock slOsWindow(::oswindow_data::s_pmutex);
//
//   iptr iFind = oswindow_find_message_only_window(pimpl);
//
//   if (iFind >= 0)
//   {
//
//      return ::oswindow_data::s_pdataptra->element_at(iFind);
//
//   }
//
//   ::oswindow_data * pdata = ___new oswindow_data;
//
//   pdata->m_bMessageOnlyWindow = true;
//
//   pdata->m_pimpl = pimpl;
//
//   ::oswindow_data::s_pdataptra->add(pdata);
//
//   return pdata;
//
//}
//
//
//oswindow_data * oswindow_get(::windowing::window * pimpl)
//{
//
//   synchronous_lock slOsWindow(::oswindow_data::s_pmutex);
//
//   iptr iFind = oswindow_find(pimpl);
//
//   if (iFind >= 0)
//      return ::oswindow_data::s_pdataptra->element_at(iFind);
//
//   ::oswindow_data * pdata = ___new ::oswindow_data;
//
//   pdata->m_bMessageOnlyWindow = false;
//   pdata->m_pimpl = pimpl;
//
//   ::oswindow_data::s_pdataptra->add(pdata);
//
//   return pdata;
//
//}
//
//
//
///*
//oswindow::oswindow()
//{
//
//m_pdata = nullptr;
//
//}
//
//oswindow::oswindow(::user::interaction * pinteraction)
//{
//
//synchronous_lock slOsWindow(s_pmutex);
//
//m_pdata = get_message_only_window(pinteraction);
//
//
//
//}
//
//oswindow::oswindow(Display * pdisplay, Window interaction_impl, Visual * pvisual)
//{
//
//synchronous_lock slOsWindow(s_pmutex);
//
//m_pdata = get(pdisplay, interaction_impl);
//
//if(pvisual != nullptr)
//{
//
//m_pdata->m_pvisual = pvisual;
//
//}
//
//
//}
//
//oswindow::oswindow(const oswindow & oswindow)
//{
//
//m_pdata = oswindow.m_pdata;
//
//}
//
//oswindow::oswindow(const void * p)
//{
//
//m_pdata = (data *) p;
//
//}
//
//oswindow::oswindow(const LPARAM & lparam)
//{
//
//m_pdata = (data *) lparam;
//
//}
//
//oswindow::oswindow(const WPARAM & wparam)
//{
//
//m_pdata = (data *) wparam;
//
//}
//
//
//
//
//
//
//oswindow & oswindow::operator = (const oswindow & oswindow)
//{
//
//m_pdata = oswindow.m_pdata;
//
//return *this;
//
//}
//
//
//
//*/
//
//
//oswindow oswindow_defer_get(::windowing::window * pimpl)
//{
//
//   return pimpl->m_oswindow;
//
//}
//
//
//
////int_bool oswindow_erase(::user::interaction * pinteraction)
////{
////
////   synchronous_lock slOsWindow(::oswindow_data::s_pmutex);
////
////   iptr iFind = oswindow_find(pinteraction);
////
////   if(iFind < 0)
////      return false;
////
////   ::oswindow_data::s_pdataptra->erase_at(iFind);
////
////   return true;
////
////}
//
//
//bool oswindow_erase_message_only_window(::windowing::window * pinteraction)
//{
//
//   synchronous_lock slOsWindow(::oswindow_data::s_pmutex);
//
//   iptr iFind = oswindow_find_message_only_window(pinteraction);
//
//   if (iFind < 0)
//      return false;
//
//   ::oswindow_data::s_pdataptra->erase_at(iFind);
//
//   return true;
//
//}
//
//
//int oswindow_data::store_name(const ::scoped_string & scopedstr)
//{
//
//   synchronous_lock synchronouslock(m_pimpl == nullptr || m_pimpl->m_puserinteraction ? nullptr : m_pimpl->m_puserinteraction->synchronization());
//
//   synchronous_lock slOsWindow(s_pmutex);
//
//   /*
//
//   xdisplay d(display());
//
//   return XStoreName(display(), interaction_impl(), psz);
//
//   */
//
//   return 0;
//
//}
//
//
//int oswindow_data::select_input(int iInput)
//{
//
//   synchronous_lock synchronouslock(m_pimpl == nullptr || m_pimpl->m_puserinteraction ? nullptr : m_pimpl->m_puserinteraction->synchronization());
//
//   synchronous_lock slOsWindow(s_pmutex);
//
//   /*
//
//   xdisplay d(display());
//
//   return XSelectInput(display(), interaction_impl(), iInput);
//
//   */
//
//   return 0;
//
//}
//
//
//int oswindow_data::select_all_input()
//{
//
//   /*
//
//   xdisplay d(display());
//
//   return select_input(ExposureMask | ButtonPressMask);
//
//   */
//
//   return 0;
//
//}
//
//
//int oswindow_data::map_window()
//{
//
//   /*
//
//   synchronous_lock synchronouslock(m_puserinteraction == nullptr ? nullptr : m_puserinteraction->synchronization());
//
//   synchronous_lock slOsWindow(s_pmutex);
//
//   xdisplay d(display());
//
//   return XMapWindow(display(), interaction_impl());
//
//   */
//
//   return 0;
//
//}
//
//
//void oswindow_data::post_nc_destroy()
//{
//
//   synchronous_lock slOsWindow(s_pmutex);
//
//   oswindow_erase(this);
//
//}
//
//
//void oswindow_data::set_impl(::windowing::window * pimpl)
//{
//
//   synchronous_lock slOsWindow(s_pmutex);
//
//   if (::is_null(this))
//   {
//
//      throw ::exception(::exception("error, m_pdata cannot be nullptr to ::oswindow::set_user_interaction"));
//
//   }
//
//   m_pimpl = pimpl;
//
//   m_htask = m_pimpl->m_puserinteraction->get_app()->get_os_handle();
//
//}
//
//
//::windowing::window * oswindow_data::get_impl()
//{
//
//   single_lock slOsWindow(s_pmutex, true);
//
//   if (::is_null(this))
//   {
//
//      return nullptr;
//
//   }
//
//   return m_pimpl;
//
//}
//
//
//::windowing::window * oswindow_data::get_impl() const
//{
//
//   single_lock slOsWindow(s_pmutex, true);
//
//   if (::is_null(this))
//   {
//
//      return nullptr;
//
//   }
//
//   return m_pimpl;
//
//}
//
//
//::user::interaction * oswindow_data::get_user_interaction()
//{
//
//   ::windowing::window * pimpl = get_impl();
//
//   try
//   {
//
//      return pimpl->m_puserinteraction;
//
//   }
//   catch (...)
//   {
//
//   }
//
//   return nullptr;
//
//}
//
//
//::user::interaction * oswindow_data::get_user_interaction() const
//{
//
//   ::windowing::window * pimpl = get_impl();
//
//   try
//   {
//
//      return pimpl->m_puserinteraction;
//
//   }
//   catch (...)
//   {
//
//   }
//
//   return nullptr;
//
//}
//
//
//
//bool oswindow_data::is_child(::oswindow oswindow)
//{
//
//   synchronous_lock synchronouslock(m_pimpl == nullptr || m_pimpl->m_puserinteraction ? nullptr : m_pimpl->m_puserinteraction->synchronization());
//
//   synchronous_lock slOsWindow(s_pmutex);
//
//   oswindow = oswindow->get_parent();
//
//   while (!oswindow->is_null())
//   {
//      if (oswindow == this)
//         return true;
//   }
//
//   return false;
//
//}
//
//
//oswindow oswindow_data::get_parent()
//{
//
//   return nullptr;
//
//}
//
//
//oswindow oswindow_data::set_parent(oswindow oswindow)
//{
//
//   return nullptr;
//
//}
//
//
//bool oswindow_data::show_window(const ::e_display & edisplay, const ::user::e_activation & useractivation)
//{
//
//   synchronous_lock synchronouslock(m_pimpl == nullptr || m_pimpl->m_puserinteraction ? nullptr : m_pimpl->m_puserinteraction->synchronization());
//
//   synchronous_lock slOsWindow(s_pmutex);
//
//   if(is_visible(edisplay))
//   {
//
//      m_pimpl->m_puserinteraction->ModifyStyle(0, WS_VISIBLE);
//
//   }
//   else
//   {
//
//      m_pimpl->m_puserinteraction->ModifyStyle(WS_VISIBLE, 0);
//
//   }
//
//   return false;
//
//}
//
//
//iptr oswindow_data::get_window_long_ptr(int nIndex)
//{
//
//   return m_pimpl->get_window_long_ptr(nIndex);
//
//}
//
//
//iptr oswindow_data::set_window_long_ptr(int nIndex, iptr l)
//{
//
//   return m_pimpl->set_window_long_ptr(nIndex, l);
//
//}
//
//
//bool oswindow_data::client_to_screen(::int_point * pp)
//{
//
//   return true;
//
//}
//
//
//bool oswindow_data::screen_to_client(::int_point * pp)
//{
//
//   return true;
//
//}
//
//
//long oswindow_data::get_state()
//{
//
//   return -1;
//
//}
//
//
//bool oswindow_data::is_iconic()
//{
//
//   return m_bIconic;
//}
//
//
//bool oswindow_data::is_window_visible()
//{
//
//   synchronous_lock synchronouslock(m_pimpl == nullptr || m_pimpl->m_puserinteraction ? nullptr : m_pimpl->m_puserinteraction->synchronization());
//
//   if (m_pimpl == nullptr)
//   {
//
//      return false;
//
//   }
//
//   return get_window_long_ptr(GWL_STYLE) & WS_VISIBLE;
//
//}
//
//
//
//
//
//
///* Copyright (c) 2012 the authors listed at the following URL, and/or
//the authors of referenced articles or incorporated external code:
//http://en.literateprograms.org/Hello_World_(C,_Cairo)?action=history&offset=20070528220552
//
//Permission is hereby granted, free of charge, to any person obtaining
//a copy of this software and associated documentation files (the
//"Software"), to deal in the Software without restriction, including
//without limitation the rights to use, copy, modify, merge, publish,
//distribute, sublicense, and/or sell copies of the Software, and to
//permit persons to whom the Software is furnished to do so, topic to
//the following conditions:
//
//The above copyright notice and this permission notice shall be
//included in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
//CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
//TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//Retrieved from: http://en.literateprograms.org/Hello_World_(C,_Cairo)?oldid=10388
//*/
//
//
//void message_box_paint(::draw2d::graphics_pointer & pgraphics, string_array_base & stra, bool_array  & baTab, ::int_array_base  & ya, ::int_size * psize)
//{
//
//   pgraphics->fill_solid_rect_dim(0, 0, psize->cx, psize->cy, rgb(84, 90, 80));
//
//   draw2d::brush_pointer pen(e_create_new);
//
//   ppen->create_solid(0);
//
//   for (::collection::index i = 0; i < stra.get_count(); i++)
//   {
//      pgraphics->text_out(10.0 + 50.0 + (baTab[i] ? 25.0 : 0), 10.0 + 50.0 + ya[i], stra[i]);
//   }
//
//
//
//}
//
//

//static oswindow g_oswindowCapture;
//static oswindow g_oswindowFocus;
//static oswindow g_oswindowActive;



//oswindow get_capture()
//{
//
//   return g_oswindowCapture;
//
//}

//oswindow set_capture(oswindow oswindow)
//{
//
//   synchronous_lock synchronouslock(::aura::g_pmutexWindowing);
//
//   ::oswindow oswindowCapturePrevious = g_oswindowCapture;
//
//   g_oswindowCapture = oswindow;
//
//   return oswindowCapturePrevious;
//
//}


//int_bool release_capture()
//{
//
//   synchronous_lock synchronouslock(::aura::g_pmutexWindowing);
//
//   g_oswindowCapture = nullptr;
//
//   return true;
//
//}
//
//
//oswindow set_focus(oswindow oswindow)
//{
//
//   synchronous_lock synchronouslock(::aura::g_pmutexWindowing);
//
//   ::oswindow oswindowFocusPrevious = g_oswindowFocus;
//
//   g_oswindowFocus = oswindow;
//
//   return g_oswindowFocus;
//
//}


//bool erase_focus(oswindow oswindow)
//{
//
//   synchronous_lock synchronouslock(::aura::g_pmutexWindowing);
//
//   ::oswindow oswindowFocusPrevious = g_oswindowFocus;
//
//   if (oswindowFocusPrevious != oswindow)
//   {
//
//      return false;
//
//   }
//
//   g_oswindowFocus = nullptr;
//
//   return true;
//
//}


//bool clear_focus()
//{
//
//   synchronous_lock synchronouslock(::aura::g_pmutexWindowing);
//
//   g_oswindowFocus = nullptr;
//
//   return true;
//
//}
//
//
//oswindow get_focus()
//{
//
//   return g_oswindowFocus;
//
//}


//int_bool this->rectangle(oswindow_data * pdata, ::int_rectangle * prectangle)
//{
//
//   pdata->m_pimpl->m_puserinteraction->rectangle(prectangle);
//
//   //prectangle->right() -= prectangle->left();
//   //prectangle->bottom() -= prectangle->top();
//   //prectangle->left() = 0;
//   //prectangle->top() = 0;
//
//   return true;
//
//}


//int_bool window_rectangle(oswindow_data * pdata, ::int_rectangle * prectangle)
//{
//
//   pdata->m_pimpl->m_puserinteraction->window_rectangle(prectangle);
//
//   return true;
//
//}


//int_bool show_window(oswindow_data * pdata, const ::e_display & edisplay, const ::user::e_activation & useractivation)
//{
//
//   return pdata->show_window(edisplay, useractivation);
//
//}
//
//
//int_bool SetWindowPos(oswindow_data * pdata, oswindow_data * pdataAfter, int x, int y, int cx, int cy, unsigned int uFlags)
//{
//   
//   pdata->m_pimpl->m_puserinteraction->order(pdata);
//
//   pdata->m_pimpl->m_puserinteraction->set_dim(x, y, cx, cy);
//
//   if (uFlags & SWP_SHOWWINDOW)
//   {
//
//      auto useractivation = uFlags & SWP_NOACTIVATE ? ::user::e_activation_no_activate : ::user::e_activation_default;
//
//      pdata->m_pimpl->m_puserinteraction->display(e_display_normal, useractivation);
//
//   }
//   else if(uFlags & SWP_HIDEWINDOW)
//   {
//
//      pdata->m_pimpl->m_puserinteraction->display(e_display_hide);
//
//   }
//
//   if (!(uFlags & SWP_NOREDRAW))
//   {
//
//      pdata->m_pimpl->m_puserinteraction->set_need_redraw();
//
//      pdata->m_pimpl->m_puserinteraction->post_redraw();
//
//   }
//
//   return true;
//
//}
//

//oswindow_data * get_parent(oswindow_data * pdata)
//{
//
//   if (pdata == nullptr)
//      return nullptr;
//
//   if (!IsWindow(pdata))
//      return nullptr;
//
//   return pdata->get_parent();
//
//
//}
//
//int_bool IsAscendant(oswindow_data * pdata, oswindow_data * pdataAscendant)
//{
//
//   if (pdata == nullptr)
//      return false;
//
//   oswindow_data * pdataParent = pdata->get_parent();
//
//   if (pdataAscendant == nullptr)
//   {
//      if (pdataParent == nullptr)
//         return true;
//      else
//         return false;
//   }
//
//   while (pdataParent != nullptr)
//   {
//
//      if (pdataParent == pdataAscendant)
//         return true;
//
//      pdataParent = pdataParent->get_parent();
//   }
//
//   return false;
//
//}
//
//
////oswindow g_oswindowActive = nullptr;
//
//
//oswindow get_active_window()
//{
//
//   return g_oswindowActive;
//
//}
//
//
//oswindow set_active_window(oswindow oswindow)
//{
//
//   ::oswindow oswindowPrevious = g_oswindowActive;
//
//   g_oswindowActive = oswindow;
//
//   return g_oswindowActive;
//
//}
//
//
//oswindow get_window(oswindow windowParam, enum_relative erelative)
//{
//
//   synchronous_lock synchronouslock(windowParam == nullptr ? nullptr : (windowParam->m_pimpl == nullptr || windowParam->m_pimpl->m_puserinteraction == nullptr ? nullptr : windowParam->m_pimpl->m_puserinteraction->mutex()));
//
//   oswindow interaction_impl = windowParam;
//
//   if (interaction_impl == nullptr)
//   {
//
//      return nullptr;
//
//   }
//
//   return nullptr;
//
//}
//
//
//
//int_bool destroy_window(oswindow w)
//{
//
//   synchronous_lock synchronouslock(w == nullptr || w->m_pimpl == nullptr || w->m_pimpl->m_puserinteraction == nullptr ? nullptr : w->m_pimpl->m_puserinteraction->synchronization());
//
//   if (!is_window(w))
//   {
//
//      return false;
//
//   }
//
//   return false;
//
//}
//
//
//bool oswindow_data::is_destroying()
//{
//
//   if (::is_null(this))
//      return true;
//
//   if (m_bDestroying)
//      return true;
//
//   return false;
//
//}
//
//
////bool IsWindow(oswindow oswindow)
////{
////
////   return oswindow->get_user_interaction() != nullptr && !oswindow->is_destroying();
////
////}
//
//
//oswindow g_oswindowDesktop;
//
//
//bool c_xstart()
//{
//
//   /*
//   Display * dpy = XOpenDisplay(nullptr);
//
//   g_oswindowDesktop = oswindow_get(dpy, DefaultRootWindow(dpy));
//
//   XSelectInput(g_oswindowDesktop->display(), g_oswindowDesktop->interaction_impl(), StructureNotifyMask);
//
//
//   return true;
//
//   */
//
//
//   return false;
//
//}
//
//
//
//oswindow get_desktop_window()
//{
//
//   return g_oswindowDesktop;
//}
//
//
//::int_point g_pointCursor;
//
//
//int_bool SetCursorPos(::int_point * lppt)
//{
//   g_pointCursor = *lppt;
//   return true;
//}
//
//
//int_bool GetCursorPos(::int_point * lppt)
//{
//   *lppt = g_pointCursor;
//   return true;
//}
//
//
//
//
//
//

//bool IsWindow(oswindow oswindow)
//{
//   return (oswindow->get_user_interaction() == nullptr && oswindow->display() != nullptr && oswindow->window() != None)
//      || (oswindow->get_user_interaction() != nullptr && !oswindow->is_destroying());
//}





//int IsWindowVisible(oswindow window)
//{
//
//   if (!IsWindow(window))
//      return false;
//
//   return window->is_window_visible();
//
//}
//


//int GetWindowLongA(oswindow window, int nIndex)
//{
//
//   if (!IsWindow(window))
//      return false;
//
//   return (int) window->get_window_long_ptr(nIndex);
//
//}
//
//
//int SetWindowLongA(oswindow window, int nIndex, int lValue)
//{
//
//   if (!IsWindow(window))
//      return false;
//
//   return (int) window->set_window_long_ptr(nIndex, lValue);
//
//}

//
//oswindow SetParent(oswindow window, oswindow windowNewParent)
//{
//
//   if (!IsWindow(window) || !(windowNewParent == nullptr || ::IsWindow(windowNewParent)))
//      return nullptr;
//
//   return window->SetParent(windowNewParent);
//
//}



//int IsIconic(oswindow window)
//{
//
//   if (!IsWindow(window))
//      return false;
//
//   return window->is_iconic();
//
//}
//
//
//::windowing::window * window_from_handle(oswindow oswindow)
//{
//
//   if (oswindow == nullptr)
//      return nullptr;
//
//   return oswindow->m_pimpl;
//
//}
//
//
//
////bool IsChild(oswindow windowParent, oswindow oswindowCandidateChildOrDescendant)
////{
////
////   if (!IsWindow(windowParent) || !IsWindow(oswindowCandidateChildOrDescendant))
////      return false;
////
////
////   return windowParent->is_child(oswindowCandidateChildOrDescendant);
////
////
////}
//
//void on_post_nc_destroy(oswindow window)
//{
//
//   window->post_nc_destroy();
//
//}
//
//
//bool is_message_only_window(oswindow window)
//{
//
//   return window->m_bMessageOnlyWindow;
//
//}
//
//
//int translate_android_key_message(::message::key * pkey, int keyCode, int iUni);
//
//
//
//
//void android_mouse(unsigned int message, float x, float y)
//{
//
//   if (::get_context_system() == nullptr)
//      return;
//
//   if (::auraacmesystem()->get_session() == nullptr)
//      return;
//
//   if (::auraacmesystem()->get_session()->m_puserinteractionHost == nullptr)
//      return;
//
//   MESSAGE msg;
//
//   auto puserinteraction = __user_interaction(::auraacmesystem()->get_session()->m_puserinteractionHost);
//
//   if (puserinteraction)
//   {
//
//      msg.hwnd = puserinteraction->get_handle();
//
//   }
//   else
//   {
//
//      msg.hwnd = nullptr;
//
//   }
//
//   msg.message = message;
//
//   msg.wParam = 0;
//
//   msg.lParam = MAKELPARAM((long)x, (long)y);
//
//   msg.pt.x = (long)x;
//
//   msg.pt.y = (long)y;
//
//   //auto puserinteraction = __user_interaction(::auraacmesystem()->get_session()->m_puserinteractionHost);
//
//   if (puserinteraction)
//   {
//
//      puserinteraction->post_message(msg.message, msg.wParam, msg.lParam);
//
//   }
//
//}
//
//
//// 
//// void android_l_button_down(float x, float y)
//// {
//
////    android_mouse(::user::e_message_left_button_down, x, y);
//
//// }
//
//
//
//
//
//// 
//// void android_mouse_move(float x, float y)
//// {
//
////    android_mouse(::user::e_message_mouse_move, x, y);
//
//// }
//
//
//
//

// 
// void android_l_button_up(float x, float y)
// {

//    android_mouse(::user::e_message_left_button_up, x, y);

// }





