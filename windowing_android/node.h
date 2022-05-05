// Created by camilo on 2022-05-04 00:00 <3ThomasBorregaardSorensen(ThomasLikesNumber5)
#pragma once


namespace windowing_android
{


   class CLASS_DECL_WINDOWING_ANDROID node :
      virtual public ::aura_android::node
   {
   public:


      node();
      ~node() override;


      void on_initialize_object() override;


      void report_exception_to_user(::object* pobject, ::exception& exception, const ::string& strMoreDetails) override;


   };


} // namespace windowing_android



