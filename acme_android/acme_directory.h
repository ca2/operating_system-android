// From acme_posix/directory_system.cpp by camilo on 2021-05-06 01:20 BRT <3ThomasBorregaardSorensen(ThomasLikesNumber5)!!
#pragma once


#include "acme_posix/directory_system.h"


namespace acme_android
{


   class CLASS_DECL_ACME_POSIX directory_system :
      virtual public ::acme_posix::directory_system
   {
   public:




      directory_system();
      ~directory_system() override;


      ::file::path home() override;


      ::file::path roaming() override;


   };


} // namespace acme_android



