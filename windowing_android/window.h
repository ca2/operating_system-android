// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:20 <3TBS, Mummi and bilbo!!
// Adapted by Camilo for android 2022-01-05 04:35 <3TBS (Thomas likes number 5), Mummi and bilbo!!
#pragma once


#define _NET_WM_STATE_REMOVE        0    // remove/unset property
#define _NET_WM_STATE_ADD           1    // add/set property
#define _NET_WM_STATE_TOGGLE        2    // toggle property


#define windowing_android_WINDOW_MEMBER
//using htask_t = pthread_t;


namespace windowing_android
{


   class CLASS_DECL_WINDOWING_ANDROID window :
      virtual public ::windowing::window
   {
   public:


      //XWindowAttributes                            m_attr;
      //XVisualInfo                                  m_visualinfo;
      //void * m_pgdkwindow;
      //__pointer(::windowing_android::x11data)          m_px11data;
      //::Window                                     m_parent;
      //Cursor                                       m_cursorLast;
      //int                                          m_iXic;
      //XIC                                          m_xic;
      //__pointer(::windowing_android::display)     m_pdisplay;
      //::Window                                     m_window;
      //::Visual                                     m_visual;
      //int                                          m_iDepth;
      //int                                          m_iScreen;
      bool                                         m_bMessageOnlyWindow;
      //__pointer(::user::interaction_impl)     m_pimpl;
      //__pointer(::message_queue)              m_pmessagequeue;
      htask_t                                    m_htask;
      //Colormap                                     m_colormap;
      ::duration                                       m_durationLastMouseMove;
      //Window                                       m_parent;
      ::rectangle_i32                              m_rect;
      //string                                       m_strWMClass;
      //int                                          m_iaNetWmState2[::x11::e_atom_net_wm_state_last - ::x11::e_atom_net_wm_state_first + 1];
      ::point_i32                                  m_pointCursor;
      //static oswindow_dataptra *                 s_pdataptra;
      //static::mutex *                            s_pmutex;

      //static Atom                                s_atomLongType;
      //static Atom                                s_atomLongStyle;
      //static Atom                                s_atomLongStyleEx;

      //__pointer(::xim::keyboard)                   m_pximkeyboard;


      window();
      //oswindow_data(::user::interaction * puibaseMessageOnlyWindow);
      //oswindow_data(const void * p);
      //oswindow_data(const LPARAM & lparam);
      //oswindow_data(const WPARAM & wparam);
      ~window() override;


      void create_window(::user::interaction_impl * pimpl) override;


      //static Atom get_window_long_atom(i32 nIndex);


      //inline int net_wm_state(::x11::enum_atom eatom) const
      //{

      //   return m_iaNetWmState2[eatom - ::x11::e_atom_net_wm_state_first];

      //}


      //virtual ::Display * Display();

      //virtual ::Display * Display() const;

      //virtual int Screen();

      //virtual int Screen() const;

      //virtual ::Window Window();

      //virtual ::Window Window() const;

      //virtual ::Visual * Visual();

      //virtual const ::Visual * Visual() const;

      //virtual ::Window root_window_raw() const;

      //virtual void unmapped_net_state_raw(Atom atom1, ...);

      //virtual ::e_status initialize_x11_window(::windowing_android::display * pdisplay, ::Window window, ::Visual * pvisual, int iDepth, int iScreen, Colormap colormap);

      //virtual void send_client_event(Atom atom, unsigned int numArgs, ...);
      //virtual i32 store_name(const char * psz);
      //virtual i32 select_input(i32 iInput);
      //virtual i32 select_all_input();
      //virtual i32 map_window();
      //virtual i32 unmap_window(bool bWithdraw);
      //virtual void set_wm_class(const char * psz);

      void exit_iconify() override;

      void full_screen(const ::rectangle_i32 & rect = nullptr) override;

      void exit_full_screen() override;

      void exit_zoomed() override;

      virtual void set_user_interaction(::user::interaction_impl * pinteraction);

      virtual void post_nc_destroy();

      virtual ::e_status set_window_icon(const ::file::path & path);

      virtual bool is_child(windowing_android_WINDOW_MEMBER::windowing::window * candidateChildOrDescendant); // or descendant
      ::windowing::window * get_parent() const override;
      //virtual ::Window get_parent_handle();
      oswindow get_parent_oswindow() const override;

      ::point_i32 get_mouse_cursor_position() override;

      //virtual ::Window get_parent_handle() const;

      ::windowing_android::windowing * android_windowing() const { return (::windowing_android::windowing *)m_pwindowing->m_pWindowing; }
      //::windowing_android::display * x11_display() const { return (::windowing_android::display *)m_pdisplay->m_pDisplay; }

      void set_parent(::windowing::window * pwindowNewParent) override;
      //virtual ::e_status set_parent(::windowing::window * pwindowNewParent) override;
      //virtual long get_state();
      virtual bool is_iconic() override;
      virtual bool is_window_visible() override;
      void show_window(const ::e_display & edisplay, const ::e_activation & eactivation) override;
      //virtual iptr get_window_long_ptr(i32 nIndex);
      //virtual iptr set_window_long_ptr(i32 nIndex, iptr l);
      virtual bool client_to_screen(POINT_I32 * ppoint) override;

      virtual bool screen_to_client(POINT_I32 * ppoint) override;


      //virtual bool set_window_pos(class::zorder zorder, i32 x, i32 y, i32 cx, i32 cy,::u32 nFlags);
      //virtual bool _set_window_pos(class::zorder zorder, i32 x, i32 y, i32 cx, i32 cy,::u32 nFlags);


      virtual bool is_destroying() override;


      //virtual bool bamf_set_icon();


      virtual bool set_icon(::image * pimage);

      //virtual int x_change_property(Atom property, Atom type, int format, int mode, const unsigned char * data, int nelements);

      void set_mouse_cursor(::windowing::cursor * pcursor) override;

      virtual void set_mouse_cursor2(::windowing::cursor * pcursor);

      void set_keyboard_focus() override;
      void set_mouse_capture() override;
      void set_active_window() override;


      void set_foreground_window() override;


      bool has_mouse_capture() const override;

      bool has_keyboard_focus() const override;




      //virtual Atom get_window_long_atom(i32 nIndex);
      //virtual void mapped_net_state_raw(bool add, windowing_android_WINDOW_MEMBER int iScreen, Atom state1, Atom state2);
      //virtual void unmapped_net_state_raw( windowing_android_WINDOW_MEMBER ...);
      //virtual bool x11_get_window_rect(windowing_android_WINDOW_MEMBER  RECTANGLE_I32 * prectangle);
      //virtual bool x11_get_client_rect(windowing_android_WINDOW_MEMBER  RECTANGLE_I32 * prectangle);
      //virtual oswindow set_capture( windowing_android_WINDOW_MEMBER );
      //virtual int_bool release_capture();
      //virtual oswindow set_focus( windowing_android_WINDOW_MEMBER );
      //virtual void x11_check_status(int status, unsigned long window);
      //virtual unsigned long x11_get_long_property( windowing_android_WINDOW_MEMBER char* property_name);
      //virtual string x11_get_name(windowing_android_WINDOW_MEMBER);
      //virtual ::e_status set_active_window();
      //virtual void upper_window_rects(windowing_android_WINDOW_MEMBER  rectangle_i32_array & ra);
      //virtual oswindow set_active_window( windowing_android_WINDOW_MEMBER );
//      virtual  windowing_android_WINDOW_MEMBER _get_if_found(Window w);
      //virtual oswindow get_parent( windowing_android_WINDOW_MEMBER );
      //virtual ::Window _get_window_relative(windowing_android_WINDOW_MEMBER enum_relative erelative, ::Window * windowa, int numItems);
      //virtual ::windowing::window * get_window(windowing_android_WINDOW_MEMBER enum_relative erelative);

      void destroy_window() override;
      //virtual int_bool destroy_window( windowing_android_WINDOW_MEMBER );
      virtual bool is_window() override;
      //virtual int_bool is_window( windowing_android_WINDOW_MEMBER );


      virtual void set_window_text(const char * pszString);


      void set_tool_window(bool bSet) override;


      bool set_window_position(const class ::zorder & zorder, i32 x, i32 y, i32 cx, i32 cy, ::u32 nFlags) override;



      //virtual comparable_array < Atom > wm_get_list_raw(windowing_android_WINDOW_MEMBER Atom atomList);
      //virtual int wm_test_state(windowing_android_WINDOW_MEMBER const char * pszNetStateFlag);
      //virtual int wm_test_state_raw(windowing_android_WINDOW_MEMBER const char * pszNetStateFlag);
      //virtual int wm_test_list_raw(windowing_android_WINDOW_MEMBER Atom atomList, Atom atomFlag);
      //virtual bool wm_add_remove_list_raw(windowing_android_WINDOW_MEMBER Atom atomList, Atom atomFlag, bool bSet);
      //virtual void wm_add_remove_state_mapped_raw(windowing_android_WINDOW_MEMBER::x11::enum_atom eatomNetWmState, bool bSet);
      //virtual void wm_add_remove_state_mapped(windowing_android_WINDOW_MEMBER::x11::enum_atom eatomNetWmState, bool bSet);
      //virtual void wm_add_remove_state_unmapped_raw(windowing_android_WINDOW_MEMBER::x11::enum_atom eatomNetWmState, bool bSet);
      //virtual void wm_add_remove_state_unmapped(windowing_android_WINDOW_MEMBER::x11::enum_atom eatomNetWmState, bool bSet);
      //virtual void wm_add_remove_state_raw(windowing_android_WINDOW_MEMBER::x11::enum_atom eatomNetWmState, bool bSet);
      //virtual void wm_add_remove_state(windowing_android_WINDOW_MEMBER::x11::enum_atom eatomNetWmState, bool bSet);
      //virtual void wm_state_clear_raw(windowing_android_WINDOW_MEMBER bool bSet);
      //virtual void wm_state_below_raw(windowing_android_WINDOW_MEMBER bool bSet);
      //virtual void wm_state_above_raw(windowing_android_WINDOW_MEMBER bool bSet);
      //virtual void wm_state_hidden_raw(windowing_android_WINDOW_MEMBER bool bSet);
      //virtual void wm_state_above(windowing_android_WINDOW_MEMBER bool bSet);
      //virtual void wm_state_below(windowing_android_WINDOW_MEMBER bool bSet);
      //virtual void wm_state_hidden(windowing_android_WINDOW_MEMBER bool bSet);
      //virtual void wm_toolwindow(windowing_android_WINDOW_MEMBER bool bToolWindow);
      //virtual void wm_normalwindow();
      //virtual void wm_hidden_state(windowing_android_WINDOW_MEMBER bool bHidden);
      //virtual void wm_desktopwindow(windowing_android_WINDOW_MEMBER bool bDesktopWindow);
      //virtual void wm_centerwindow(windowing_android_WINDOW_MEMBER bool bCenterWindow);
      //virtual void wm_splashwindow(windowing_android_WINDOW_MEMBER bool bCenterWindow);
      //virtual void wm_dockwindow(windowing_android_WINDOW_MEMBER bool bDockWindow);
      //virtual void wm_nodecorations(windowing_android_WINDOW_MEMBER int bMap);
      //virtual void _wm_nodecorations(windowing_android_WINDOW_MEMBER int bMap);
      //virtual int_bool IsWindowVisibleRaw(windowing_android_WINDOW_MEMBER);
      //virtual void wm_iconify_window(windowing_android_WINDOW_MEMBER);
      //virtual int_bool IsWindowVisibleRaw( windowing_android_WINDOW_MEMBER);
      //virtual int_bool IsWindowVisibleRaw(oswindow w);
//      virtual Atom * wm_get_list_raw( windowing_android_WINDOW_MEMBER Atom atomList, unsigned long int * pnum_items);
//      virtual int wm_test_list_raw( windowing_android_WINDOW_MEMBER Atom atomList, Atom atomFlag);
//      virtual int wm_test_state_raw( windowing_android_WINDOW_MEMBER const char * pszNetStateFlag);
//      virtual int wm_test_state( windowing_android_WINDOW_MEMBER const char * pszNetStateFlag);
//      virtual bool wm_add_remove_list_raw( windowing_android_WINDOW_MEMBER Atom atomList, Atom atomFlag, bool bSet);


      //virtual ::e_status x11_post_message(MESSAGE & msg);
      //virtual ::e_status post_ui_message(const MESSAGE & message);
      ////virtual bool x11_process_event(osdisplay_data * pdisplaydata, XEvent * pevent, XGenericEventCookie *cookie);
      ////virtual ::e_status set_window_position( windowing_android_WINDOW_MEMBER const ::zorder & zorder, i32 x, i32 y, i32 cx, i32 cy, ::u32 nFlags);
      //virtual ::e_status get_window_rect(windowing_android_WINDOW_MEMBER RECTANGLE_I32 * prectangle);
      //virtual ::e_status get_client_rect(windowing_android_WINDOW_MEMBER  RECTANGLE_I32 * prectangle);
      ////virtual ::e_status wm_full_screen( windowing_android_WINDOW_MEMBER const ::rectangle_i32 & rectangle);

      //virtual ::e_status x11_store_name(const char * pszName);
      //virtual ::e_status set_foreground_window();
      //virtual ::e_status set_active_window();
      //virtual void wm_toolwindow( windowing_android_WINDOW_MEMBER bool bToolWindow);
      //virtual void wm_state_hidden( windowing_android_WINDOW_MEMBER bool bSet);
      //virtual void wm_state_hidden_raw( windowing_android_WINDOW_MEMBER bool bSet);
      //virtual ::e_status mq_remove_window_from_all_queues(windowing_android_WINDOW_MEMBER);

      void update_screen() override;
      void window_show() override;

      bool is_active_window() const override;


      void bring_to_front() override;


   };


   //using window_map = map < ::Window, __pointer(window) >;


} // namespace windowing_android



