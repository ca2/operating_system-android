// Created by camilo on 2022-05-04 03:33 <3ThomasBorregaardSorensen
#include "framework.h"
#include "node.h"
#include "acme/platform/system.h"


#if defined(__clang__)
   ::string android_backtrace();
#endif

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

      system()->increment_reference_count();

      system()->main();

//      system()->aaa_post_initial_request();

   }

   void node::set_last_run_application_path(const ::scoped_string & scopedstrAppId)
   {


   }

   
   string node::audio_get_default_implementation_name()
   {

      return system()->implementation_name("audio", "opensles");

   }


//#if defined(__clang__)
//   ::string node::get_callstack()
//   {
//
//      return android_backtrace();
//
//   }
//
//#endif


} // namespace acme_android



