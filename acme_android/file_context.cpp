#include "framework.h"
#include "file_context.h"
#include "directory_system.h"
#include "file_system.h"
#include "acme/filesystem/file/exception.h"
#include "acme/operating_system/shared_posix/stdio_file.h"
#include "acme/platform/system.h"
#include "acme/windowing/windowing.h"

#include <unistd.h>


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


   ::file_pointer file_context::defer_get_protocol_file(const ::scoped_string & scopedstrProtocol, const ::file::path & path, ::file::e_open eopen, ::pointer<::file::exception> * pfileexception)
   {

      if(scopedstrProtocol != "content")
      {

         return ::file_context::defer_get_protocol_file(scopedstrProtocol, path, eopen, pfileexception);

      }

      auto pfile = create_newø < ::stdio_file >();

      pfile->m_path = path;
      pfile->m_eopen = eopen;

      auto pwindowing = system()->acme_windowing();
      int iFileDescriptor = pwindowing ? pwindowing->open_file_descriptor(path, eopen) : -1;

      informationf("ID3DBG acme_android::file_context content open path=\"%s\" eopen=%lld fd=%d",
         path.c_str(),
         (long long)eopen,
         iFileDescriptor);

      if(iFileDescriptor < 0)
      {

         pfile->m_estatus = error_failed;
         pfile->set_nok();

         if(eopen & ::file::e_open_no_exception_on_open)
         {

            return pfile;

         }

         auto pexception = allocateø ::file::exception(error_failed, path, eopen, "Failed to open content URI file descriptor.");

         if(pfileexception)
         {

            *pfileexception = pexception;

         }

         throw *pexception;

      }

      string strMode;

      if(eopen & ::file::e_open_no_truncate)
      {

         strMode += "r";

      }
      else if(eopen & ::file::e_open_create)
      {

         strMode += "w";

      }
      else if(eopen & ::file::e_open_write && !(eopen & ::file::e_open_read))
      {

         strMode += "w";

      }
      else
      {

         strMode += "r";

      }

      if(eopen & ::file::e_open_binary)
      {

         strMode += "b";

      }

      if(eopen & ::file::e_open_write && eopen & ::file::e_open_read)
      {

         strMode += "+";

      }

      FILE * pstdioFile = fdopen(iFileDescriptor, strMode);

      informationf("ID3DBG acme_android::file_context fdopen path=\"%s\" mode=\"%s\" success=%d",
         path.c_str(),
         strMode.c_str(),
         pstdioFile ? 1 : 0);

      if(!pstdioFile)
      {

         close(iFileDescriptor);
         pfile->m_estatus = error_failed;
         pfile->set_nok();

         if(eopen & ::file::e_open_no_exception_on_open)
         {

            return pfile;

         }

         auto pexception = allocateø ::file::exception(error_failed, path, eopen, "Failed to create stdio stream from content URI file descriptor.");

         if(pfileexception)
         {

            *pfileexception = pexception;

         }

         throw *pexception;

      }

      pfile->m_pfile = pstdioFile;
      pfile->m_estatus = ::success;
      pfile->set_ok_flag();

      return pfile;

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



