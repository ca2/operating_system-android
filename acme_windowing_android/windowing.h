// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:35 <3TBS, Mummi and bilbo!!
// Adapted by Camilo for android 2022-01-05 04:34 <3TBS (Thomas likes number 5), Mummi and bilbo!!
#pragma once


#include "acme/windowing/sandbox/windowing.h"


namespace android
{

    namespace acme
    {

        namespace windowing
        {


            class CLASS_DECL_ACME_WINDOWING_ANDROID windowing :
        virtual public ::acme::sandbox_windowing::windowing
            {
            public:


                bool m_bRootSelectInput: 1;
                bool m_bFirstWindowMap: 1;

                //::pointer<::windowing_android::display> m_pdisplay;

                //itask                                         m_itask;

//#ifdef WITH_XI
//
//      int                                             m_xi_opcode = -1;
//      ::pointer<object_array>                        m_pobjectaExtendedEventListener;
//
//#endif

                //::procedure_list                                m_procedurelist;

                //::pointer<::windowing::window>                 m_pwindowApplicationHost;


                windowing();

                ~windowing() override;


                void initialize(::particle *pparticle) override;


                bool is_branch_current() const override;


                void initialize_windowing() override;


                //void terminate_windowing() override;


                void defer_initialize_host_window(const ::int_rectangle *lpcrect) override;

                ::acme::windowing::window *get_application_host_window() override;

                ////virtual void post_ui_message(const MESSAGE & message);

                //virtual void post_ui_message(::message::message * pmessage);

                //void start() override;

                //void _libsn_start_context()  override;

                //::acme::windowing::display *display() override;

                //void windowing_main() override;


                //void windowing_post_quit() override;

                void on_start_system() override;


                void on_start_windowing_application() override;


                //void release_mouse_capture(::thread * pthread) override;
                bool defer_release_mouse_capture(::thread *pthread,
                                                 ::acme::windowing::window *pwindow) override;


                //void clear_keyboard_focus(::user::element * pelementGainingFocusIfAny = nullptr) override;

            void windowing_application_main_loop() override;
                //virtual void x11_main();

                //virtual HCURSOR load_default_cursor(e_cursor ecursor) override;
                //virtual ::pointer<::windowing::cursor>
                //load_default_cursor(enum_cursor ecursor) override;

                //virtual int_bool window_set_mouse_cursor(window * pwindow, HCURSOR hcursor) override;

                //virtual bool set_window_icon(window * pwindow, const ::file::path & path) override;

                //virtual ::windowing::window * new_message_window(::windowing::window * pimpl) override;

                //::windowing::window * new_window(::windowing::window * pimpl) override;

                ///::pointer<::acme::windowing::window> get_new_window() override;

                //void erase_window(::windowing::window *pwindow) override;

                //virtual ::windowing_android::window * _window(Window window);

                //::windowing::window* window(oswindow oswindow) override;

                //::acme::windowing::window *window(oswindow oswindow) override;

                virtual void _message_handler(void *p) override;

//      SnLauncheeContext* g_psncontext = nullptr;

                //void x_display_error_trap_push(SnDisplay * sndisplay, Display * display);

                //void x_display_error_trap_pop(SnDisplay * sndisplay, Display * display);
                //void x_display_error_trap_pop(SnDisplay * sndisplay, Display * display);


                //::windowing::window * get_active_window(::thread * pthread) override;

                //::windowing::window * get_keyboard_focus(::thread * pthread) override;

                //::windowing::window * get_mouse_capture(::thread * pthread) override;

                //void clear_active_window(::thread * pthread, ::windowing::window * pwindow) override;

                //virtual bool x11_on_event(XEvent * pevent);

                //virtual bool x11_message_handler(XEvent * pevent);

                //virtual bool __x11_hook_process_event(XEvent * pevent, XGenericEventCookie * cookie);

                //virtual bool __x11_hook_list_is_empty();
//
                //virtual bool x11_message_loop_step();

                //void user_post(const ::procedure & procedure) override;

                //bool x11_runnable_step() override;

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

                //::windowing::text_editor_interface *get_text_editor_interface() override;


                //using ::windowing::windowing::get_cursor;


                //::pointer<::windowing::cursor> get_cursor(enum_cursor ecursor) override;


            };


        } // namespace windowing


   } // namespace acme


} // namespace android



