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


   void dir_system::initialize(::object * pobject)
   {

      ::dir_system::initialize(pobject);

      m_pathHome = m_psystem->m_pathCacheDirectory / "home";

      m_pathCa2Config = m_psystem->m_pathCacheDirectory / ".config/ca2";

   }


} // namespace apex_android



