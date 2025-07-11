// Created by camilo on 2022-05-04 00:00 <3ThomasBorregaardSorensen(ThomasLikesNumber5)
#include "framework.h"
#include "node.h"
#include "acme/platform/session.h"
#include "aura/windowing/windowing.h"
#include "windowing_android/android/driver.h"
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

      ::cast < ::android::acme::driver > pdriver = ::acme::driver::get();

      system()->m_pathCacheDirectory = pdriver->m_pathCacheDirectory;

      ::aura_android::node::on_initialize_particle();

   }


   void node::report_exception_to_user(::particle * pparticle, ::exception& exception, const ::string& strMoreDetails)
   {

      if (system()->m_bIsReadyForUserInteraction)
      {

         ::aura_android::node::report_exception_to_user(pparticle, exception, strMoreDetails);

      }
      else
      {

         operating_system_log_exception(pparticle, exception, strMoreDetails);

      }

   }


   void node::on_start_system()
   {

      auto pdriver = ::acme::driver::get();

      ::int_rectangle rectangle;

      rectangle.left() = 0;
      rectangle.top() = 0;
      rectangle.right() = pdriver->m_iWidth;
      rectangle.bottom() = pdriver->m_iHeight;

      //auto psession = session();

      auto psystem = system();

      auto pwindowing = psystem->windowing();

      pwindowing->defer_initialize_host_window(&rectangle);

      //system()->aaa_post_initial_request();

   }


   //::pointer<::conversation>node::create_new_message_box_conversation()
   //{

   //   return __allocate ::windowing_android::message_box();

   //}


   //pointer< ::sequence < ::conversation > > node::get_new_conversation_sequence()
   //{

   //   auto psequence = __allocate windowing_android::message_box();

   //   return psequence;

   //}


   //pointer< ::sequence < ::conversation > > node::message_box(const ::string& strMessage, const ::string& strTitle, const ::e_message_box& emessagebox)
   //{

   //   return nullptr;

   //}


   void node::on_change_application_capability()
   {

      ::aura_android::node::on_change_application_capability();

      if (has_application_capability(e_application_capability_music_library))
      {

         ::acme::driver::get()->list_file_enumerate("music");

      }


      if (has_application_capability(e_application_capability_image_library))
      {

         ::acme::driver::get()->list_file_enumerate("image");

      }


      if (has_application_capability(e_application_capability_video_library))
      {

         ::acme::driver::get()->list_file_enumerate("video");

      }

   }


} // namespace operating_ambient_android



