// Created by camilo on 2022-10-18 20:32 <3ThomasBorregaardSorensen
#include "framework.h"
#include "node.h"
#include "acme/filesystem/filesystem/file_system_options.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/handler/request.h"
#include "acme/platform/system.h"
#include "acme/windowing/windowing.h"
#include "apex/platform/session.h"
#include "acme_windowing_android/android/_internal.h"
#include "windowing_android/android/application_sink.h"
#include "acme_windowing_android/android/message_box.h"
#include "acme_windowing_android/windowing.h"


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

      ::cast < ::android::acme::application_sink > papplicationsink = ::platform::application_sink::get();

      papplicationsink->initialize(this);

      system()->m_pathCacheDirectory = papplicationsink->m_pathCacheDirectory;

      ::aura_android::node::on_initialize_particle();

   }


   void node::report_exception_to_user(::particle * pparticle, ::exception & exception, const ::scoped_string & scopedstrMoreDetails)
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


   void node::on_change_application_capability()
   {

      ::aura_android::node::on_change_application_capability();

      if (has_application_capability(e_application_capability_music_library))
      {

         ::platform::application_sink::get()->list_file_enumerate("music");

      }


      if (has_application_capability(e_application_capability_image_library))
      {

         ::platform::application_sink::get()->list_file_enumerate("image");

      }


      if (has_application_capability(e_application_capability_video_library))
      {

         ::platform::application_sink::get()->list_file_enumerate("video");

      }

   }


   void node::on_start_system()
   {

      auto psystem = system();

      auto pacmewindowing = psystem->acme_windowing();

      pacmewindowing->on_start_system();

      auto pdriver = ::platform::application_sink::get();

      ::int_rectangle rectangle;

      rectangle.left = 0;
      rectangle.top = 0;
      rectangle.right = pdriver->m_iWidth;
      rectangle.bottom = pdriver->m_iHeight;

      auto psession = session();

      psession->defer_initialize_host_window(&rectangle);

      //system()->defer_post_initial_request();

   }

//
//   ::pointer<::acme::user::message_box>node::create_new_message_box()
//   {
//
//      return øallocate class ::windowing_android::message_box();
//
//   }
//


   ////pointer< ::sequence < ::conversation > > node::get_new_conversation_sequence()
   ////{

   ////   auto psequence = øallocate windowing_android::message_box();

   ////   return psequence;

   ////}


   ////pointer< ::sequence < ::conversation > > node::message_box(const ::scoped_string & scopedstrMessage, const ::scoped_string & scopedstrTitle, const ::user::e_message_box& emessagebox)
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


   void node::open_internet_link(const ::scoped_string & scopedstrUrl,
                                 const ::scoped_string & scopedstrProfile,
                                 const ::scoped_string & scopedstrTarget)
   {

      ::platform::application_sink::get()->open_url(scopedstrUrl);

   }


//   ::file::path node::synchronously_request_document_folder()
//   {
//      return ::platform::application_sink::get()->synchronously_getDocumentFolder(1_min);
//
//   }


   void node::post_media_store_operation(::data::block * pdatablock)
   {

      return ::platform::application_sink::get()->post_media_store_operation(pdatablock);

   }
   void node::root_ones(::file::listing_base &listing)
   {

      ::aura_android::node::root_ones(listing);

      if(application()->m_pfilesystemoptions->m_straFileSystemExtension.contains("mediastore.image"))
      {

         auto iPickAudioMedia = listing.size();

         auto & path = listing.insert_at(iPickAudioMedia, "mediastore.image://");

         path.m_etype = ::file::e_type_existent_folder;

         listing.m_straTitle.insert_at(iPickAudioMedia, "Google Photos");

      }
      else
      {

         auto iPickBrowse = listing.size();

         auto & path = listing.insert_at(iPickBrowse, "pick-browse://");

         path.m_etype = ::file::e_type_existent_folder;

         listing.m_straTitle.insert_at(iPickBrowse, "Pick Browse...");


      }

   }

   bool node::defer_enumerate_protocol(::file::listing_base& listing)
   {

      ::file::path pathFinal = listing.m_pathFinal;

      if(pathFinal.is_empty())
      {

         pathFinal = application()->defer_process_path(listing.m_pathUser);

      }

      if(pathFinal.begins_eat("pick-browse://"))
      {

         auto callback = [this](const ::file::path & path)
         {

            auto prequest = øcreate_new <::request>();

            prequest->m_payloadFile = path;

            prequest->m_ecommand = ::e_command_file_open;

            application()->request(prequest);

         };

         application()->pick_browse(callback);

      }
      else if(pathFinal.begins_eat("mediastore.image://"))
      {

         application()->pick_media("image");

      }

      return ::aura_android::node::defer_enumerate_protocol(listing);

   }

} // namespace windowing_android



