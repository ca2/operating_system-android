// created from windowing::display by camilo 2022-05-06 18:55 <3ThomasBorregaardSoerensen(ThomasLikesNumber5!!)
// created by Camilo 2021-01-31 05:13 BRT <3CamiloSasukeThomasBorregaardSoerensen
#pragma once


#include "aura/windowing/monitor.h"


namespace windowing_android
{


   class CLASS_DECL_AURA monitor :
      virtual public ::windowing::monitor
   {
   public:


      //::raw::index                                               m_iIndex;
      //::rectangle_i32                                       m_rectangle;
      //::rectangle_i32                                       m_rectangleWorkspace;
      //::pointer<::windowing::display>                      m_pdisplay;


      monitor();
      ~monitor() override;


      //virtual void update_cache();

      //virtual ::u32 get_monitor_color_temperature();
      //virtual bool adjust_monitor(::u32 dwTemperature, double dBrightness, double dwGamma);


      //virtual void get_monitor_rectangle(::rectangle_i32* prectangle);
      //virtual void get_workspace_rectangle(::rectangle_i32* prectangle);
      ::rectangle_i32 monitor_rectangle() override;
      ::e_status _get_monitor_rectangle();

   };


   //using monitor_map = iptr_map < ::pointer<monitor >>


} // namespace windowing_android



