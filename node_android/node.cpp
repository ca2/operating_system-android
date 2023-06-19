// Created by camilo on 2022-10-18 20:32 <3ThomasBorregaardSorensen
#include "framework.h"
#include "node.h"
#include "acme/platform/system.h"
#include "apex/platform/session.h"
#include "windowing_android/android/_internal.h"
#include "windowing_android/android/driver.h"
#include "windowing_android/android/message_box.h"


namespace node_android
{


   node::node()
   {


   }


   node::~node()
   {


   }


   void node::on_initialize_particle()
   {

      acmesystem()->m_pathCacheDirectory = ::operating_system_driver::get()->m_pathCacheDirectory;

      ::aura_android::node::on_initialize_particle();

   }


   void node::report_exception_to_user(::particle * pparticle, ::exception & exception, const ::string & strMoreDetails)
   {

      if (acmesystem()->m_bIsReadyForUserInteraction)
      {

         ::aura_android::node::report_exception_to_user(pparticle, exception, strMoreDetails);

      }
      else
      {

         operating_system_log_exception(pparticle, exception, strMoreDetails);

      }

   }


   void node::on_change_application_capability()
   {

      ::aura_android::node::on_change_application_capability();

      if (has_application_capability(e_application_capability_music_library))
      {

         ::operating_system_driver::get()->list_file_enumerate("music");

      }


      if (has_application_capability(e_application_capability_image_library))
      {

         ::operating_system_driver::get()->list_file_enumerate("image");

      }


      if (has_application_capability(e_application_capability_video_library))
      {

         ::operating_system_driver::get()->list_file_enumerate("video");

      }

   }


   void node::on_start_system()
   {

      auto pdriver = ::operating_system_driver::get();

      ::rectangle_i32 rectangle;

      rectangle.left = 0;
      rectangle.top = 0;
      rectangle.right = pdriver->m_iWidth;
      rectangle.bottom = pdriver->m_iHeight;

      auto psession = acmesession();

      psession->m_papexsession->defer_initialize_host_window(&rectangle);

      acmesystem()->defer_post_initial_request();

   }


   ::pointer<::conversation>node::create_new_message_box_conversation()
   {

      return __new(class ::windowing_android::message_box());

   }



   ////pointer< ::sequence < ::conversation > > node::get_new_conversation_sequence()
   ////{

   ////   auto psequence = __new(windowing_android::message_box);

   ////   return psequence;

   ////}


   ////pointer< ::sequence < ::conversation > > node::message_box(const ::string& strMessage, const ::string& strTitle, const ::e_message_box& emessagebox)
   ////{

   ////   return nullptr;

   ////}

   //
   //void node::on_change_application_capability()
   //{

   //   ::aura_android::node::on_change_application_capability();

   //   if (has_application_capability(e_application_capability_music_library))
   //   {

   //      ::operating_system_driver::get()->list_file_enumerate("music");

   //   }
   //   
   //   
   //   if (has_application_capability(e_application_capability_image_library))
   //   {

   //      ::operating_system_driver::get()->list_file_enumerate("image");

   //   }
   //   
   //   
   //   if (has_application_capability(e_application_capability_video_library))
   //   {

   //      ::operating_system_driver::get()->list_file_enumerate("video");

   //   }

   //}


   void node::open_url(const ::string & strUrl)
   {

      ::operating_system_driver::get()->open_url(strUrl);

   }


} // namespace windowing_android



