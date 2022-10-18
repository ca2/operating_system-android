// created by Camilo 2021-01-31 05:26 BRT <3CamiloSasukeThomasBorregaardSoerensen
// from apex_windows by Camilo on 2022-05-24 18:42 <3TThomasBorregaardSoerensen
// From interprocess_communication.h by camilo on 2022-10-17 14:35 <3ThomasBorregaardSorensen!!
#pragma once


#include "apex/interprocess/base.h"


namespace apex_android
{


   class CLASS_DECL_APEX interprocess_base :
      virtual public interprocess::base
   {
   public:



      //__creatable_from_base(interprocess_communication_base, ::interprocess_handler::base);


      //HWND              m_hwnd;
      string            m_strBaseChannel;


      interprocess_base();
      ~interprocess_base() override;


      //HWND get_hwnd() const { return (HWND)m_hwnd; }
      //void set_hwnd(HWND hwnd) { m_hwnd = hwnd; }

   };


} // namespace apex_android



