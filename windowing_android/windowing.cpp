// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:35 <3TBS, Mummi and bilbo!!
// Adapted by Camilo for android 2022-01-05 04:36 <3TBS (Thomas likes number 5), Mummi and bilbo!!
#include "framework.h"
#include "host_interaction.h"
#include "windowing.h"
#include "window.h"
#include "display.h"
#include "acme/constant/user_message.h"
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


   void windowing::erase_window(::windowing::window * pwindow)
   {

      //m_pdisplay->erase_window(pwindow);

   }


   void windowing::initialize(::particle * pparticle)
   {

      ::windowing::windowing::initialize(pparticle);

      initialize_windowing();

      auto pdisplay = øcreate < ::acme::windowing::display >();

      m_pdisplay = pdisplay;

   }


   ::particle * windowing::defer_initialize_host_window(const ::int_rectangle* lpcrect)
   {

      auto pparticleAcmeWindowingWindow = ::sandbox_windowing::windowing::defer_initialize_host_window(lpcrect);

      return pparticleAcmeWindowingWindow;

   }


   ::acme::windowing::window* windowing::get_application_host_window()
   {

      return m_pwindowApplicationHost;

   }

   ::windowing::display * windowing::display()
   {

      return m_pdisplay;

   }


   ::pointer<::windowing::cursor>windowing::load_default_cursor(enum_cursor ecursor)
   {

      synchronous_lock synchronouslock(synchronization());

      if (!m_pcursormanager)
      {

         øconstruct_new(m_pcursormanager);

      }


      windowing_output_debug_string("\n::x11_GetWindowRect 1");


      return nullptr;

   }


   ::acme::windowing::window* windowing::window(oswindow oswindow)
   {

      return oswindow;

   }


   void windowing::_message_handler(void * p)
   {

   }


   ::windowing::text_editor_interface * windowing::get_text_editor_interface()
   {

      ::cast < ::windowing::text_editor_interface> ptexteditorinterface=::platform::application_sink::get();

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
