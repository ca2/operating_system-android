// Created by camilo on 2022-05-04 03:33 <3ThomasBorregaardSorensen
#pragma once


#include "acme_posix/node.h"


namespace acme_android
{


   class CLASS_DECL_ACME_ANDROID node :
      virtual public ::acme_posix::node
   {
   public:


      node();
      ~node() override;


      void system_main() override;


      void set_last_run_application_path(const ::string& strAppId) override;

      
      string audio_get_default_library_name() override;


   };


} // namespace acme_android



