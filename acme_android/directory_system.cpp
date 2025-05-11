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


   void directory_system::initialize(::particle * pparticle)
   {

      ::directory_system::initialize(pparticle);

      m_pathHome = system()->m_pathCacheDirectory / "home";

      m_pathCa2Config = system()->m_pathCacheDirectory / ".config/ca2";

   }


} // namespace acme_android



