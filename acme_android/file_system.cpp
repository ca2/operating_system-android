#include "framework.h"
#include "file_system.h"


struct PROCESS_INFO_t
{


   string csProcess;
   unsigned int dwImageListIndex;


};


namespace acme_android
{


   file_system::file_system()
   {

   }


   file_system::~file_system()
   {

   }


   void file_system::initialize(::particle * pparticle)
   {

      //auto estatus = 
      
      ::file_system::initialize(pparticle);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }

   
   //void file_system::update_module_path()
   //{

   //   m_pathModule = path_system()->app_module();

   //   m_pathCa2Module = m_pathModule;

   //   return true;

   //}


} // namespace acme_android



