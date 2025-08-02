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


   };


} // namespace node_android