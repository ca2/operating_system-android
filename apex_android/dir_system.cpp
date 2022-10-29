#include "framework.h"
#include "dir_system.h"


namespace apex_android
{


   dir_system::dir_system()
   {

   }


   dir_system::~dir_system()
   {

   }


   void dir_system::initialize(::particle * pparticle)
   {

      ::dir_system::initialize(pobject);

      m_pathHome = acmesystem()->m_pathCacheDirectory / "home";

      m_pathCa2Config = acmesystem()->m_pathCacheDirectory / ".config/ca2";

   }


} // namespace apex_android



