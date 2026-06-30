// Created by camilo on 2022-10-18 20:32 <3ThomasBorregaardSorensen
#pragma once


#include "aura_android/node.h"


namespace node_android
{


   class CLASS_DECL_NODE_ANDROID node :
      virtual public ::aura_android::node
   {
   public:


      node();
      ~node() override;


      void on_initialize_particle() override;


      void report_exception_to_user(::particle * pparticle, ::exception & exception, const ::scoped_string & scopedstrMoreDetails) override;

      void on_start_system() override;

      //::pointer<::message_box> create_new_message_box() override;

      void on_change_application_capability() override;
      
      void open_internet_link(const ::scoped_string & strUrl, const ::scoped_string & strProfile = {},
                              const ::scoped_string & strTarget = {}) override;

      //::file::path synchronously_request_document_folder() override;


      //::pointer < ::data::block > media_store_set_data(const ::scoped_string & scopedstrPath, const ::block & block) override;
      //::pointer < ::data::block > media_store_get_data(const ::scoped_string & scopedstrPath) override;

      void post_media_store_operation(::data::block * pdatablock) override;
      void post_google_drive_appdata_operation(::data::block * pdatablock) override;
      bool secure_app_storage_set(const ::scoped_string & scopedstrName, const ::scoped_string & scopedstrValue) override;
      ::string secure_app_storage_get(const ::scoped_string & scopedstrName) override;
      bool secure_app_storage_delete(const ::scoped_string & scopedstrName) override;
      bool secure_app_storage_contains(const ::scoped_string & scopedstrName) override;
      ::string get_google_access_token(const ::scoped_string & scopedstrScope) override;
      void clear_google_access_token(const ::scoped_string & scopedstrScope, const ::scoped_string & scopedstrAccessToken) override;
      void root_ones(::file::listing_base &listing) override;
      bool defer_enumerate_protocol(::file::listing_base& listing) override;

   };


} // namespace node_android
