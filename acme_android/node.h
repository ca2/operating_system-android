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


      void set_last_run_application_path(const ::scoped_string & scopedstrAppId) override;

      
      string audio_get_default_implementation_name() override;

//#if defined(__clang__)
//      ::string get_callstack() override;
//#endif


//      void media_store_set_data(const ::scoped_string & scopedstrPath, const ::block & block) override;
//      ::memory media_store_get_data(const ::scoped_string & scopedstrPath) override;


   };


} // namespace acme_android



