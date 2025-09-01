// Created by camilo on 2022-05-04 00:00 <3ThomasBorregaardSorensen(ThomasLikesNumber5)
#include "framework.h"
#include "node.h"
#include "acme/platform/session.h"
#include "aura/windowing/windowing.h"
#include "windowing_android/android/application_state.h"
#include "acme_windowing_android/android/_internal.h"
//
//


namespace operating_ambient_android
{


   node::node()
   {


   }


   node::~node()
   {


   }


   void node::on_initialize_particle()
   {

      ::cast < ::android::acme::application_state > papplicationstate = ::platform::application_state::get();

      system()->m_pathCacheDirectory = papplicationstate->m_pathCacheDirectory;

      ::aura_android::node::on_initialize_particle();

   }


   void node::report_exception_to_user(::particle * pparticle, ::exception& exception, const ::scoped_string & scopedstrMoreDetails)
   {

      if (system()->m_bIsReadyForUserInteraction)
      {

         ::aura_android::node::report_exception_to_user(pparticle, exception, scopedstrMoreDetails);

      }
      else
      {

         operating_system_log_exception(pparticle, exception, scopedstrMoreDetails);

      }

   }


   void node::on_start_system()
   {

      ::node_android::node::on_start_system();

//
//      auto papplicationstate = ::platform::application_state::get();
//
//      ::int_rectangle rectangle;
//
//      rectangle.left() = 0;
//      rectangle.top() = 0;
//      rectangle.right() = papplicationstate->m_iWidth;
//      rectangle.bottom() = papplicationstate->m_iHeight;
//
//      //auto psession = session();
//
//      auto psystem = system();
//
//      auto pwindowing = psystem->windowing();
//
//      pwindowing->defer_initialize_host_window(&rectangle);
//
//      //system()->aaa_post_initial_request();

   }


   //::pointer<::conversation>node::create_new_message_box_conversation()
   //{

   //   return øallocate ::windowing_android::message_box();

   //}


   //pointer< ::sequence < ::conversation > > node::get_new_conversation_sequence()
   //{

   //   auto psequence = øallocate windowing_android::message_box();

   //   return psequence;

   //}


   //pointer< ::sequence < ::conversation > > node::message_box(const ::scoped_string & scopedstrMessage, const ::scoped_string & scopedstrTitle, const ::user::e_message_box& emessagebox)
   //{

   //   return nullptr;

   //}


   void node::on_change_application_capability()
   {

      ::aura_android::node::on_change_application_capability();

      if (has_application_capability(e_application_capability_music_library))
      {

         ::platform::application_state::get()->list_file_enumerate("music");

      }


      if (has_application_capability(e_application_capability_image_library))
      {

         ::platform::application_state::get()->list_file_enumerate("image");

      }


      if (has_application_capability(e_application_capability_video_library))
      {

         ::platform::application_state::get()->list_file_enumerate("video");

      }

   }


} // namespace operating_ambient_android



