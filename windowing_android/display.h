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
//      virtual bool set_main_monitor(::collection::index iMonitor);
//      //virtual ::collection::count get_monitor_count() //;
//      //virtual bool  get_monitor_rectangle(::collection::index iMonitor, ::int_rectangle * prectangle) //;
//
////      virtual ::collection::index get_main_workspace(::int_rectangle * prectangle = nullptr) ;
//
//      virtual bool set_main_workspace(::collection::index iWorkspace);
//      //virtual ::collection::count get_workspace_count() ;
//      //virtual bool  get_workspace_rectangle(::collection::index iWorkspace, ::int_rectangle * prectangle) ;
//
//      virtual bool workspace_to_monitor(::int_rectangle* prectangle, ::collection::index iMonitor, ::collection::index iWorkspace);
//
//      virtual bool monitor_to_workspace(::int_rectangle* prectangle, ::collection::index iWorkspace, ::collection::index iMonitor);
//
//      virtual bool workspace_to_monitor(::int_rectangle* prectangle);
//
//      virtual bool monitor_to_workspace(::int_rectangle* prectangle);
//
//      //virtual ::collection::count get_desk_monitor_count() ;
//      //virtual bool  get_desk_monitor_rect(::collection::index iMonitor, ::int_rectangle * prectangle) ;
//
//      virtual monitor* get_monitor(::collection::index iMonitor);
//
//      virtual void  get_monitor(::int_rectangle_array& rectaMonitor, ::int_rectangle_array& rectaIntersect, const ::int_rectangle& rectangle);
//
//      virtual ::collection::index initial_frame_position(::int_rectangle* prectangle, const ::int_rectangle& rectangle, bool bMove, ::user::interaction* pinteraction);
//
//      virtual ::collection::index _get_best_zoneing(edisplay* pedisplay, ::int_rectangle* prectangle, const ::int_rectangle& rectangle, bool bPreserveSize = false);
//
//      virtual ::collection::index get_best_monitor(::int_rectangle* prectangle, const ::int_rectangle& rectangle, const ::user::activation & useractivation = {});
//
//      virtual ::collection::index get_best_workspace(::int_rectangle* prectangle, const ::int_rectangle& rectangle, const ::user::activation & useractivation = {});
//
//      virtual ::collection::index get_good_iconify(::int_rectangle* prectangle, const ::int_rectangle& rectangle);
//
//      virtual ::collection::index get_good_restore(::int_rectangle* prectangle, const ::int_rectangle& rectangle, ::user::interaction* pinteraction, edisplay edisplayRestore);
//
//      virtual ::collection::index get_good_move(::int_rectangle* prectangle, const ::int_rectangle& rectangle, ::user::interaction* pinteraction);
//
//
//
//
//
//      virtual void enum_display_monitors();
//
//      virtual ::collection::index get_main_monitor(::int_rectangle* prectangle = nullptr);
//      virtual ::int_size get_main_monitor_size();
//
//      virtual ::int_size get_monitor_union_size();
//
//      virtual ::collection::count get_monitor_count();
//      virtual bool  get_monitor_rectangle(::collection::index iMonitor, ::int_rectangle* prectangle);
//
//      virtual ::collection::count get_desk_monitor_count();
//      virtual bool  get_desk_monitor_rect(::collection::index iMonitor, ::int_rectangle* prectangle);
//
//
//      virtual ::collection::index get_main_workspace(::int_rectangle* prectangle = nullptr);
//
//      virtual ::collection::count get_workspace_count();
//      virtual bool  get_workspace_rectangle(::collection::index iWorkspace, ::int_rectangle* prectangle);
//
//      virtual ::collection::count get_desk_workspace_count();
//      virtual bool  get_desk_workspace_rect(::collection::index iWorkspace, ::int_rectangle* prectangle);
//
//      virtual ::collection::index get_ui_workspace(::user::interaction* pinteraction);
//
//
//
//      virtual string get_wallpaper(::collection::index iScreen);
//      virtual bool set_wallpaper(::collection::index iScreen, string strWallpaper);
//
//
//      virtual string_array get_wallpaper();
//      virtual void set_wallpaper(const string_array& strWallpaper);
//
//
//      virtual string impl_get_wallpaper(::collection::index iScreen);
//      virtual bool impl_set_wallpaper(::collection::index iScreen, string strWallpaper);
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



