// From acme_posix/acme_directory.cpp by camilo on 2021-05-06 01:30 BRT <3ThomasBorregaardSorensen(ThomasLikesNumber5)!!
#include "framework.h"
#include "acme_directory.h"
#include "acme/platform/system.h"


namespace acme_android
{


   acme_directory::acme_directory()
   {


   }


   acme_directory::~acme_directory()
   {


   }


   ::file::path acme_directory::home()
   {

      return acmesystem()->m_pathCacheDirectory / "home";

   }


   ::file::path acme_directory::roaming()
   {

      return acmesystem()->m_pathCacheDirectory / ".config";

   }



} // namespace acme_android

