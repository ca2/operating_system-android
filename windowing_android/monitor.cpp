// created from windowing::monitor by camilo 2022-05-06 18:54 <3ThomasBorregaardSoerensen!!
// created by Camilo 2021-01-31 05:16 BRT <3CamiloSasukeThomasBorregaardSoerensen
#include "framework.h"
#include "monitor.h"
#include "android/_internal.h"


namespace windowing_android
{


   monitor::monitor()
   {


   }


   monitor::~monitor()
   {


   }


   //void monitor::update_cache()
   //{

   //   //return ::success_none;

   //}


   //::u32 monitor::get_monitor_color_temperature()
   //{

   //   return 0;

   //}


   //bool monitor::adjust_monitor(::u32 dwTemperature, double dBrightness, double dwGamma)
   //{

   //   return false;

   //}


   //void monitor::get_monitor_rectangle(::rectangle_i32* prectangle)
   //{

   //   __copy(prectangle, m_rectangle);

   //   //      return true;

   //}


   //void monitor::get_workspace_rectangle(::rectangle_i32* prectangle)
   //{

   //   __copy(prectangle, m_rectangleWorkspace);

   //   //      return true;

   //}


   ::rectangle_i32 monitor::monitor_rectangle()
   {

      _get_monitor_rectangle();

      //copy(rectangle, m_rectangle);

      return m_rectangle;

   }


   ::e_status monitor::_get_monitor_rectangle()
   {

      m_rectangle.left() = 0;
      m_rectangle.top() = 0;
      m_rectangle.right() = ::operating_system_driver::get()->m_iWidth;
      m_rectangle.bottom() = ::operating_system_driver::get()->m_iHeight;

      return ::success;

   }


} // namespace windowing_android



