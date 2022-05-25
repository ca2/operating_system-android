// From acme_posix/acme_directory.cpp by camilo on 2021-05-06 01:20 BRT <3ThomasBorregaardSørensen(ThomasLikesNumber5)!!
#pragma once


namespace acme_android
{


   class CLASS_DECL_ACME_POSIX acme_directory :
      virtual public ::acme_posix::acme_directory
   {
   public:


      acme_directory();
      ~acme_directory() override;


      ::file::path home() override;


      ::file::path roaming() override;


   };


} // namespace acme_android



