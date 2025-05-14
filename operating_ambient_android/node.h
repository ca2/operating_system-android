// Created by camilo on 2022-05-04 00:00 <3ThomasBorregaardSorensen(ThomasLikesNumber5)
#pragma once


#include "aura_android/node.h"


namespace operating_ambient_android
{


   class CLASS_DECL_OPERATING_AMBIENT_ANDROID node :
      virtual public ::aura_android::node
   {
   public:


      node();
      ~node() override;


      void on_initialize_particle() override;


      void report_exception_to_user(::particle* pparticle, ::exception& exception, const ::string& strMoreDetails) override;


      void on_start_system() override;


      //::pointer<::conversation>create_new_message_box_conversation() override;


      void on_change_application_capability() override;


   };


} // namespace operating_ambient_android



