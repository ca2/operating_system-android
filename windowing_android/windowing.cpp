// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:35 <3TBS, Mummi and bilbo!!
// Adapted by Camilo for android 2022-01-05 04:36 <3TBS (Thomas likes number 5), Mummi and bilbo!!
#include "framework.h"
#include "host_interaction.h"
#include "windowing.h"
#include "window.h"
#include "display.h"
#include "acme/constant/message.h"
#include "acme/parallelization/synchronous_lock.h"
//#include "aura/user/user/interaction_impl.h"
#include "aura/windowing/sandbox/host_interaction.h"
#include "aura/windowing/text_editor_interface.h"
#include "acme_windowing_android/android/_internal.h"
#include "aura/windowing/cursor_manager.h"


namespace windowing_android
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


   bool windowing::is_branch_current() const
   {

      auto itaskCurrent = current_itask();

      return itaskCurrent == m_itask;


   }


//   ::windowing::window * windowing::new_window(::windowing::window * pimpl)
//   {
//
//      ::pointer<::windowing_android::window>pwindow = pimpl->__create < ::windowing::window >();
//
//      if (!pwindow)
//      {
//
//         return nullptr;
//
//      }
//
//      pwindow->m_pwindowing = this;
//
//      pwindow->m_pwindow = pimpl;
//
//      pimpl->m_pwindow = pwindow;
//
//      pwindow->create_window(pimpl);
//
//      return pwindow;
//
//   }


   void windowing::erase_window(::windowing::window * pwindow)
   {

      //m_pdisplay->erase_window(pwindow);

   }


   void windowing::initialize(::particle * pparticle)
   {

      //auto estatus =
      //
      ::windowing::windowing::initialize(pparticle);

      //      if(!estatus)
      //      {
      //
      //         return estatus;
      //
      //      }

      initialize_windowing();

      auto pdisplay = __øcreate < ::acme::windowing::display >();

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

      m_pdisplay = pdisplay;

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


   void windowing::defer_initialize_host_window(const ::int_rectangle* lpcrect)
   {

      ::sandbox_windowing::windowing::defer_initialize_host_window(lpcrect);

//      if (::is_set(m_phostinteraction))
//      {
//
//         return;
//
//      }
//
//      __øconstruct(m_phostinteraction);
//
//      m_phostinteraction->set_rectangle(*lpcrect);
//
//      //m_phostinteraction->create_host(e_parallelization_synchronous);
//
//      m_phostinteraction->create_window();
//
//      m_phostinteraction->display();
//
//      //m_phostinteraction->set_need_layout();
//
//      m_phostinteraction->set_need_redraw();
//
//      m_phostinteraction->post_redraw();

   }


   ::acme::windowing::window* windowing::get_application_host_window()
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


//   bool windowing::x11_runnable_step()
//   {
//
//      bool bHandled = false;
//
//      //if (m_pdisplay)
//      //{
//
//      //   if (m_pdisplay->m_px11display)
//      //   {
//
//      //      while (m_pdisplay->m_px11display->x11_posted())
//      //      {
//
//      //         bHandled = true;
//
//      //      }
//
//      //   }
//
//      //}
//
//      synchronous_lock synchronouslock(synchronization());
//
//      if (m_procedurelist.is_empty())
//      {
//
//         return bHandled;
//
//      }
//
//      do
//      {
//
//         {
//
//            auto routine = m_procedurelist.pick_head();
//
//            synchronouslock.unlock();
//
//            routine();
//
//         }
//
//         synchronouslock.lock();
//
//      } while (m_procedurelist.has_element());
//
//      return true;
//
//   }


   ::windowing::display * windowing::display()
   {

      return m_pdisplay;

   }


   //::windowing_x11::window * windowing::_window(Window window)
   //{

   //   if (!m_pdisplay)
   //   {

   //      return nullptr;

   //   }

   //   auto pwindow = m_pdisplay->_window(window);

   //   return pwindow;

   //}


   ::pointer<::windowing::cursor>windowing::load_default_cursor(enum_cursor ecursor)
   {

      synchronous_lock synchronouslock(synchronization());

      if (!m_pcursormanager)
      {

         //auto estatus =
         //
         //
         __construct_new(m_pcursormanager);

         //         if (!estatus)
         //         {
         //
         //            return nullptr;
         //
         //         }

      }

      //auto & pcursor = m_pcursormanager->m_cursormap[ecursor];

      //if (pcursor)
      //{

      //   return pcursor;

      //}

      //int iCursor = 0;

      //if (ecursor == e_cursor_size_top_left)
      //{

      //   iCursor = XC_top_left_corner;

      //}
      //else if (ecursor == e_cursor_size_top_right)
      //{

      //   iCursor = XC_top_right_corner;

      //}
      //else if (ecursor == e_cursor_size_top)
      //{

      //   iCursor = XC_top_side;

      //}
      //else if (ecursor == e_cursor_size_right)
      //{

      //   iCursor = XC_right_side;

      //}
      //else if (ecursor == e_cursor_size_left)
      //{

      //   iCursor = XC_left_side;

      //}
      //else if (ecursor == e_cursor_size_bottom)
      //{

      //   iCursor = XC_bottom_side;

      //}
      //else if (ecursor == e_cursor_size_bottom_left)
      //{

      //   iCursor = XC_bottom_left_corner;

      //}
      //else if (ecursor == e_cursor_size_bottom_right)
      //{

      //   iCursor = XC_bottom_right_corner;

      //}
      //else if (ecursor == e_cursor_arrow)
      //{

      //   iCursor = XC_arrow;

      //}

      //if (iCursor == 0)
      //{

      //   return nullptr;

      //}

      //synchronous_lock sl(user_mutex());

      windowing_output_debug_string("\n::x11_GetWindowRect 1");

      //display_lock lock(m_pdisplay->Display());

      //auto cursor = XCreateFontCursor(m_pdisplay->Display(), iCursor);

      //auto pcursorX11 = __create < ::windowing_x11::cursor >();

      //pcursor = pcursorX11;

      //pcursorX11->m_cursor = cursor;

      //return pcursor;

      return nullptr;

   }


   ::acme::windowing::window* windowing::window(oswindow oswindow)
   {

      return oswindow;

   }


   void windowing::_message_handler(void * p)
   {

      XEvent * pevent = (XEvent *)p;

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


//   void windowing::release_mouse_capture(::thread * pthread)
//   {
//
//      if (!m_pwindowMouseCapture)
//      {
//
//         return;
//
//      }
//
//      auto pwindow = m_pwindowMouseCapture->m_pwindow;
//
//      if (pwindow)
//      {
//
//         pwindow->m_puserinteractionMouseCapture.release();
//
//      }
//
//      m_pwindowMouseCapture.release();
//
//      //auto estatus =
//      //
//      //m_pdisplay->release_mouse_capture();
//
//      //      if(!estatus)
//      //      {
//      //
//      //         return estatus;
//      //
//      //      }
//      //
//      //      return estatus;
//
//   }


//   void windowing::clear_keyboard_focus(::user::element * pelementGainingFocusIfAny)
//   {
//
//      if (!m_pwindowKeyboardFocus)
//      {
//
//         return;
//
//      }
//
//      auto pwindow = m_pwindowKeyboardFocus->m_pwindow;
//
//      if (pwindow)
//      {
//
//         if (pwindow->m_pacmeuserinteractionKeyboardFocus)
//         {
//
//            pwindow->m_puserinteractionKeyboardGainingFocusIfAny = pelementGainingFocusIfAny;
//
//            //pwindow->aaa_m_pacmeuserinteractionKeyboardFocus->post_message(e_message_kill_focus);
//
//         }
//
//         auto puserinteraction = pwindow->m_puserinteraction;
//
//         if (puserinteraction)
//         {
//
//            puserinteraction->post_message(e_message_kill_focus);
//
//         }
//
//         //if (pwindow->aaa_m_pacmeuserinteractionKeyboardFocus)
//         //{
//
//         //   pwindow->m_puserinteractionKeyboardGainingFocusIfAny = pwindowGainingFocusIfAny;
//
//         //   pwindow->aaa_m_pacmeuserinteractionKeyboardFocus->post_message(e_message_kill_focus);
//
//         //}
//
//         pwindow->m_pacmeuserinteractionKeyboardFocus.release();
//
//      }
//
//      m_pwindowKeyboardFocus.release();
//
//      //auto estatus =
//      //
//      //m_pdisplay->release_mouse_capture();
//
//      //      if(!estatus)
//      //      {
//      //
//      //         return estatus;
//      //
//      //      }
//      //
//      //      return estatus;
//
//   }


   ::windowing::text_editor_interface * windowing::get_text_editor_interface()
   {

      ::cast < ::windowing::text_editor_interface> ptexteditorinterface=::platform::application_state::get();

      return ptexteditorinterface;

   }


   ::pointer<::windowing::cursor>windowing::get_cursor(enum_cursor ecursor)
   {

      return nullptr;

   }


   bool windowing::defer_release_mouse_capture(::thread *pthread,
                                    ::acme::windowing::window *pwindow)
   {

      return sandbox_windowing::windowing::defer_release_mouse_capture(pthread, pwindow);

   }

   void windowing::windowing_application_main_loop()
   {

      ::android::acme::windowing::windowing::windowing_application_main_loop();

   }

} // namespace windowing_android




void defer_term_ui()
{



}
