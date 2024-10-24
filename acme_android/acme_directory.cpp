// From acme_posix/directory_system.cpp by camilo on 2021-05-06 01:30 BRT <3ThomasBorregaardSorensen(ThomasLikesNumber5)!!
#include "framework.h"
#include "directory_system.h"
#include "acme/platform/system.h"


namespace acme_android
{


   directory_system::directory_system()
   {


   }


   directory_system::~directory_system()
   {


   }


   ::file::path directory_system::home()
   {

      return system()->m_pathCacheDirectory / "home";

   }


   ::file::path directory_system::roaming()
   {

      return system()->m_pathCacheDirectory / ".config";

   }



} // namespace acme_android

