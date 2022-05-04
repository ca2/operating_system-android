// Created by camilo on 2022-05-04 03:30 <3ThomasBorregaardSorensen(ThomasLikesNumber5)
#pragma once


namespace apex_android
{


   class CLASS_DECL_APEX_ANDROID node :
      virtual public ::apex_posix::node,
      virtual public ::acme_android::node
   {
   public:


      node();
      ~node() override;


   };


} // namespace apex_android



