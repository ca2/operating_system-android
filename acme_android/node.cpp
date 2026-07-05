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

      return system()->implementation_name("audio", "aaudio");

   }


   string node::veriwell_multimedia_music_midi_get_default_implementation_name()
   {

      return system()->implementation_name("music_midi", "tinysoundfont");

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

//   void node::media_store_set_data(const ::scoped_string & scopedstrPath, const ::block & block)
//   {
//
//
//   }
//
//
//   ::memory node::media_store_get_data(const ::scoped_string & scopedstrPath)
//   {
//
//
//   }


   bool node::set_process_priority(::enum_priority epriority)
   {


      return true;


   }


   ::file::path node::_get_app_music_folder()
   {

      return m_pathAppMusicFolder;

   }


} // namespace acme_android



