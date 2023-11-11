#include "framework.h"
#include "dir_system.h"
#include "acme/platform/system.h"


namespace acme_android
{


   dir_system::dir_system()
   {

   }


   dir_system::~dir_system()
   {

   }


   void dir_system::initialize(::particle * pparticle)
   {

      ::dir_system::initialize(pparticle);

      m_pathHome = system()->m_pathCacheDirectory / "home";

      m_pathCa2Config = system()->m_pathCacheDirectory / ".config/ca2";

   }


} // namespace acme_android



