#include "framework.h"
#include "file_context.h"
#include "dir_system.h"
#include "file_system.h"
#include "apex/platform/system.h"


namespace apex_android
{


   file_context::file_context()
   {

   }


   file_context::~file_context()
   {

   }


   void file_context::initialize(::particle * pparticle)
   {

      //auto estatus = 
      
      ::file_context::initialize(pparticle);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //estatus = 
      
      m_pdirsystem = acmesystem()->m_papexsystem->m_pdirsystem;

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //estatus = 
      
      m_pfilesystem = acmesystem()->m_papexsystem->m_pfilesystem;

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   //void file_context::update_module_path()
   //{

   //   auto estatus = ::file_context::update_module_path();

   //   if (!estatus)
   //   {

   //      return estatus;

   //   }

   //   return estatus;

   //}


} // namespace apex_android



