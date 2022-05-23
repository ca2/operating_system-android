// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:35 <3TBS, Mummi and bilbo!!
// Adapted by Camilo for android 2022-01-05 04:34 <3TBS (Thomas likes number 5), Mummi and bilbo!!
#pragma once


namespace windowing_android
{


   class CLASS_DECL_WINDOWING_ANDROID windowing :
      virtual public ::windowing::windowing
   {
   public:


      bool                                            m_bRootSelectInput : 1;
      bool                                            m_bFirstWindowMap : 1;

      __pointer(::windowing_android::display)         m_pdisplay;
      //bool                                            m_bFinishX11Thread;
      //bool                                            m_bInitX11Thread;

      __pointer(::windowing_android::window)          m_pwindowKeyboardFocus;
      __pointer(::windowing_android::window)          m_pwindowMouseCapture;

      itask_t                                         m_itask;

//#ifdef WITH_XI
//
//      int                                             m_xi_opcode = -1;
//      __pointer(object_array)                         m_pobjectaExtendedEventListener;
//
//#endif

      ::procedure_list                                m_procedurelist;

      __pointer(host_interaction)                     m_phostinteraction;

      __pointer(::windowing::window)                  m_pwindowApplicationHost;


      windowing();
      ~windowing() override;


      void initialize(::object * pobject) override;


      bool is_branch_current() const override;


      virtual void initialize_windowing();

      virtual void terminate_windowing();

      void defer_initialize_host_window(const RECTANGLE_I32* lpcrect) override;

      ::windowing::window* get_application_host_window() override;

      ////virtual void post_ui_message(const MESSAGE & message);

      //virtual void post_ui_message(::message::message * pmessage);

      //void start() override;

      //void _libsn_start_context()  override;

      ::windowing::display * display() override;

      //void windowing_main() override;


      //void windowing_post_quit() override;


      void release_mouse_capture() override;


      void clear_keyboard_focus(::windowing::window* pwindowGainingFocusIfAny = nullptr) override;


      //virtual void x11_main();

      //virtual HCURSOR load_default_cursor(e_cursor ecursor) override;
      virtual __pointer(::windowing::cursor) load_default_cursor(enum_cursor ecursor) override;

      //virtual int_bool window_set_mouse_cursor(window * pwindow, HCURSOR hcursor) override;

      //virtual bool set_window_icon(window * pwindow, const ::file::path & path) override;

      //virtual ::windowing::window * new_message_window(::user::interaction_impl * pimpl) override;

      ::windowing::window * new_window(::user::interaction_impl * pimpl) override;

      void erase_window(::windowing::window * pwindow) override;

      //virtual ::windowing_android::window * _window(Window window);

      ::windowing::window* window(oswindow oswindow) override;

      virtual void _message_handler(void * p) override;

//      SnLauncheeContext* g_psncontext = nullptr;

      //void x_display_error_trap_push(SnDisplay * sndisplay, Display * display);

      //void x_display_error_trap_pop(SnDisplay * sndisplay, Display * display);
      //void x_display_error_trap_pop(SnDisplay * sndisplay, Display * display);


      //::windowing::window * get_active_window(::thread * pthread) override;

      ::windowing::window * get_keyboard_focus(::thread * pthread) override;

      ::windowing::window * get_mouse_capture(::thread * pthread) override;

      //void clear_active_window(::thread * pthread, ::windowing::window * pwindow) override;

      //virtual bool x11_on_event(XEvent * pevent);

      //virtual bool x11_message_handler(XEvent * pevent);

      //virtual bool __x11_hook_process_event(XEvent * pevent, XGenericEventCookie * cookie);

      //virtual bool __x11_hook_list_is_empty();
//
      //virtual bool x11_message_loop_step();

      void windowing_post(const ::procedure & procedure) override;

      virtual bool x11_runnable_step();

      //virtual ::windowing::window * window(oswindow oswindow) override;

      //virtual void _libsn_start_context() override;

//#ifdef WITH_XI
//
//      void x11_register_extended_event_listener(::matter * pdata, bool bMouse, bool bKeyboard);
//      bool x11_process_event(XEvent * pevent, XGenericEventCookie *cookie);
//
//#else
//
//      bool x11_process_event(Display * pdisplay, XEvent * pevent);
//
//#endif

      ::windowing::text_editor_interface * get_text_editor_interface() override;


      using ::windowing::windowing::get_cursor;


      __pointer(::windowing::cursor) get_cursor(enum_cursor ecursor) override;


   };


} // namespace windowing_android



