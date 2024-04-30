// created from windowing::display by camilo 2022-05-06 18:46 <3ThomasBorregaardSoerensen
// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:20
#pragma once


#include "aura/windowing/display.h"


namespace windowing_android
{

   // X11 contribution : a display may contain more than one monitor

   class CLASS_DECL_AURA display :
      virtual public ::windowing::display
   {
   public:


//      void* m_pDisplay;
//      void* m_pDisplay2;
//#ifdef LINUX
//      void* _m_pX11Display;
//#endif
//
//      pointer_array < monitor >      m_monitora;
//
//
//      ::pointer<windowing>         m_pwindowing;
//      bool                          m_bSystemSynchronizedScreen;
//
//      index                         m_iMainMonitor;
//      index                         m_iMainWorkspace;
//      double                        m_dpi;


      display();
      ~display() override;


//      virtual void initialize_display(::windowing::windowing* pwindowing);
//
//      virtual iptr get_os_data() const;
//
//      virtual window* default_root_window();
//
//
//      virtual float get_dpi();
//
//      virtual void open();
//
//      virtual bool set_main_monitor(::raw::index iMonitor);
//      //virtual ::raw::count get_monitor_count() //;
//      //virtual bool  get_monitor_rectangle(::raw::index iMonitor, ::rectangle_i32 * prectangle) //;
//
////      virtual ::raw::index get_main_workspace(::rectangle_i32 * prectangle = nullptr) ;
//
//      virtual bool set_main_workspace(::raw::index iWorkspace);
//      //virtual ::raw::count get_workspace_count() ;
//      //virtual bool  get_workspace_rectangle(::raw::index iWorkspace, ::rectangle_i32 * prectangle) ;
//
//      virtual bool workspace_to_monitor(::rectangle_i32* prectangle, ::raw::index iMonitor, ::raw::index iWorkspace);
//
//      virtual bool monitor_to_workspace(::rectangle_i32* prectangle, ::raw::index iWorkspace, ::raw::index iMonitor);
//
//      virtual bool workspace_to_monitor(::rectangle_i32* prectangle);
//
//      virtual bool monitor_to_workspace(::rectangle_i32* prectangle);
//
//      //virtual ::raw::count get_desk_monitor_count() ;
//      //virtual bool  get_desk_monitor_rect(::raw::index iMonitor, ::rectangle_i32 * prectangle) ;
//
//      virtual monitor* get_monitor(::raw::index iMonitor);
//
//      virtual void  get_monitor(rectangle_i32_array& rectaMonitor, rectangle_i32_array& rectaIntersect, const ::rectangle_i32& rectangle);
//
//      virtual ::raw::index initial_frame_position(::rectangle_i32* prectangle, const ::rectangle_i32& rectangle, bool bMove, ::user::interaction* pinteraction);
//
//      virtual ::raw::index _get_best_zoneing(edisplay* pedisplay, ::rectangle_i32* prectangle, const ::rectangle_i32& rectangle, bool bPreserveSize = false);
//
//      virtual ::raw::index get_best_monitor(::rectangle_i32* prectangle, const ::rectangle_i32& rectangle, ::e_activation eactivation = e_activation_default);
//
//      virtual ::raw::index get_best_workspace(::rectangle_i32* prectangle, const ::rectangle_i32& rectangle, ::e_activation eactivation = e_activation_default);
//
//      virtual ::raw::index get_good_iconify(::rectangle_i32* prectangle, const ::rectangle_i32& rectangle);
//
//      virtual ::raw::index get_good_restore(::rectangle_i32* prectangle, const ::rectangle_i32& rectangle, ::user::interaction* pinteraction, edisplay edisplayRestore);
//
//      virtual ::raw::index get_good_move(::rectangle_i32* prectangle, const ::rectangle_i32& rectangle, ::user::interaction* pinteraction);
//
//
//
//
//
//      virtual void enum_display_monitors();
//
//      virtual ::raw::index get_main_monitor(::rectangle_i32* prectangle = nullptr);
//      virtual ::size_i32 get_main_monitor_size();
//
//      virtual ::size_i32 get_monitor_union_size();
//
//      virtual ::raw::count get_monitor_count();
//      virtual bool  get_monitor_rectangle(::raw::index iMonitor, ::rectangle_i32* prectangle);
//
//      virtual ::raw::count get_desk_monitor_count();
//      virtual bool  get_desk_monitor_rect(::raw::index iMonitor, ::rectangle_i32* prectangle);
//
//
//      virtual ::raw::index get_main_workspace(::rectangle_i32* prectangle = nullptr);
//
//      virtual ::raw::count get_workspace_count();
//      virtual bool  get_workspace_rectangle(::raw::index iWorkspace, ::rectangle_i32* prectangle);
//
//      virtual ::raw::count get_desk_workspace_count();
//      virtual bool  get_desk_workspace_rect(::raw::index iWorkspace, ::rectangle_i32* prectangle);
//
//      virtual ::raw::index get_ui_workspace(::user::interaction* pinteraction);
//
//
//
//      virtual string get_wallpaper(::raw::index iScreen);
//      virtual bool set_wallpaper(::raw::index iScreen, string strWallpaper);
//
//
//      virtual string_array get_wallpaper();
//      virtual void set_wallpaper(const string_array& strWallpaper);
//
//
//      virtual string impl_get_wallpaper(::raw::index iScreen);
//      virtual bool impl_set_wallpaper(::raw::index iScreen, string strWallpaper);
//
//
//      virtual string os_get_user_theme();
//      virtual bool set_os_desktop_theme(string strTheme);
//
//
//      virtual string impl_get_os_desktop_theme();
//      virtual bool impl_set_os_desktop_theme(string strTheme);
//
//
//      virtual void enable_wallpaper_change_notification();



   };


   //using display_map = iptr_map < ::pointer<display >>


} // namespace windowing



