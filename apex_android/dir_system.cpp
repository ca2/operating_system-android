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

      //auto estatus = 
      
      ::dir_system::initialize(pobject);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //m_pathInstall = ::dir::install();

      m_pathHome = m_psystem->m_pathCacheDirectory / "home";

      //return estatus;

   }


} // namespace apex_android



