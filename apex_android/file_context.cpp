#include "framework.h"
#include "file_context.h"
#include "dir_system.h"
#include "file_system.h"


namespace apex_android
{


   file_context::file_context()
   {

   }


   file_context::~file_context()
   {

   }


   void file_context::initialize(::object * pobject)
   {

      //auto estatus = 
      
      ::file_context::initialize(pobject);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //estatus = 
      
      __refer(m_pdirsystem, m_psystem->m_papexsystem->m_pdirsystem);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //estatus = 
      
      __refer(m_pfilesystem, m_psystem->m_papexsystem->m_pfilesystem);

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



