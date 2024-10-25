#include "framework.h"
#include "file_context.h"
#include "directory_system.h"
#include "file_system.h"
#include "acme/platform/system.h"


namespace acme_android
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
      
      m_pdirectorysystem = system()->m_pdirectorysystem;

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //estatus = 
      
      m_pfilesystem = system()->m_pfilesystem;

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


} // namespace acme_android



