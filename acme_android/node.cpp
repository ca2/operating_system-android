// Created by camilo on 2022-05-04 03:33 <3ThomasBorregaardSørensen
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

      acmesystem()->increment_reference_count();

      acmesystem()->main();

//      acmesystem()->post_initial_request();

   }

   void node::set_last_run_application_path(const ::string& strAppId)
   {


   }

   
   string node::audio_get_default_library_name()
   {

      return "audio_opensles";

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



