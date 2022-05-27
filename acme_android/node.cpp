// Created by camilo on 2022-05-04 03:33 <3ThomasBorregaardSorensen
#include "framework.h"


namespace acme_android
{


   node::node()
   {


   }


   node::~node()
   {


   }


   void node::system_main()
   {

      m_psystem->increment_reference_count();

      m_psystem->branch();

//      m_psystem->post_initial_request();

   }

   void node::set_last_run_application_path(const ::string& strAppId)
   {


   }

   
   string node::audio_get_default_library_name()
   {

      return "audio_opensles";

   }


} // namespace acme_android



