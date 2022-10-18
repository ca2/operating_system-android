﻿#include "framework.h"
#include "file.h"
#include "acme_directory.h"
#include <fcntl.h>

#undef USE_MISC

#include <dlfcn.h>
#include <link.h>
#include <ctype.h>

#include <sys/stat.h>


void set_last_errno_status();


bool CLASS_DECL_ACME windows_full_path(wstring& wstrFullPath, const wstring& wstrPath);


namespace acme_android
{

   
   bool file_get_status(::file::file_status & rStatus, const ::file::path & path)
   {

      // attempt to fully qualify path first

      wstring wstrFullName;

      wstring wstrFileName;

      wstrFileName = utf8_to_unicode(path);

      if (!windows_full_path(wstrFullName, wstrFileName))
      {

         rStatus.m_strFullName.Empty();

         return false;

      }

      unicode_to_utf8(rStatus.m_strFullName, wstrFullName);

      struct stat st;

      if (stat(path, &st) == -1)
      {

         return false;

      }
      //if (hFind == INVALID_HANDLE_VALUE)
      // return false;
      //VERIFY(FindClose(hFind));

      // strip attribute of NORMAL bit, our API doesn't have a "normal" bit.
      //rStatus.m_attribute = (byte) (findFileData.dwFileAttributes & ~FILE_ATTRIBUTE_NORMAL);

      rStatus.m_attribute = 0;

      // get just the low ::u32 of the file size_i32
      //ASSERT(findFileData.nFileSizeHigh == 0);
      //rStatus.m_size = (::i32)findFileData.nFileSizeLow;

      rStatus.m_filesize = st.st_size;

      // convert times as appropriate
      /*rStatus.m_ctime = ::earth::time(findFileData.ftCreationTime);
      rStatus.m_atime = ::earth::time(findFileData.ftLastAccessTime);
      rStatus.m_mtime = ::earth::time(findFileData.ftLastWriteTime);*/
      rStatus.m_ctime = ::earth::time(st.st_mtime);
      rStatus.m_atime = ::earth::time(st.st_atime);
      rStatus.m_mtime = ::earth::time(st.st_ctime);

      if (rStatus.m_ctime.get_time() == 0)
         rStatus.m_ctime = rStatus.m_mtime;

      if (rStatus.m_atime.get_time() == 0)
         rStatus.m_atime = rStatus.m_mtime;

      return true;

   }


   file::file()
   {

      m_iFile = (::u32) hFileNull;

   }


   file::~file()
   {

      if (m_iFile != hFileNull)
         close();

   }


   void file::open(const ::file::path & path, const ::file::e_open & eopenParam)
   {

      ::file::e_open eopen(eopenParam);

      if (m_iFile != hFileNull)
      {

         close();

      }

      ASSERT_VALID(this);
      ASSERT(__is_valid_string(path));
      ASSERT(!(eopen & ::file::e_open_text));   // text mode not supported

      // file objects are always binary and CreateFile does not need flag
      eopen -= ::file::e_open_binary;

      if ((eopen & ::file::e_open_defer_create_directory) && (eopen & ::file::e_open_write))
      {

         auto psystem = m_psystem;

         auto pacmedirectory = psystem->m_pacmedirectory;

         pacmedirectory->create(path.folder());

      }

      m_iFile = (::u32)hFileNull;

      m_strFileName.Empty();

      m_strFileName = path;

      ASSERT(::file::e_open_share_compat == 0);

      // ::collection::map read/write mode
      ASSERT((::file::e_open_read | ::file::e_open_write | ::file::e_open_read_write) == 3);
      ::u32 dwFlags =  0;
      switch (eopen & 3)
      {
      case ::file::e_open_read:
         dwFlags |=  O_RDONLY;
         break;
      case ::file::e_open_write:
         dwFlags |=  O_WRONLY;
         break;
      case ::file::e_open_read_write:
         dwFlags |=  O_RDWR;
         break;
      default:
         dwFlags |=  O_RDONLY;
         break;
      }

      // ::collection::map share mode
      //::u32 dwShareMode = 0;
      switch (eopen & 0x70)    // ::collection::map compatibility mode to exclusive
      {
      default:
         ASSERT(false);  // invalid share mode?
      case ::file::e_open_share_compat:
      case ::file::e_open_share_exclusive:
         //dwShareMode = 0;
         break;
      case ::file::e_open_share_deny_write:
         //dwFlags |= O_SHLOCK;
         break;
      case ::file::e_open_share_deny_read:
         //dwFlags |= O_EXLOCK;
         break;
      case ::file::e_open_share_deny_none:
         //dwFlags = FILE_SHARE_WRITE|FILE_SHARE_READ;
         break;
      }

      if(eopen & ::file::e_open_create)
      {
         dwFlags |= O_CREAT;
         if(!(eopen & ::file::e_open_no_truncate))
            dwFlags |= O_TRUNC;
      }

      ::u32 dwPermission = 0;

      dwPermission |= S_IRUSR | S_IWUSR | S_IXUSR;
      dwPermission |= S_IRGRP | S_IWGRP | S_IXGRP;

      // attempt file creation
      //HANDLE hFile = shell::CreateFile(utf8_to_unicode(m_strFileName), dwAccess, dwShareMode, &sa, dwCreateFlag, FILE_ATTRIBUTE_NORMAL, nullptr);
      i32 hFile = ::open(m_strFileName, dwFlags, dwPermission); //::open(m_strFileName, dwAccess, dwShareMode, &sa, dwCreateFlag, FILE_ATTRIBUTE_NORMAL, nullptr);

      if(hFile == -1)
      {

//         set_last_errno_status();
         int iErrNo = errno;

         m_estatus = errno_to_status(iErrNo);

         auto errorcode = __errno(iErrNo);

         set_nok();

         if (eopen & ::file::e_open_no_exception_on_open)
         {

            if (!::failed(m_estatus))
            {

               m_estatus = error_failed;

            }

            //set_nok();

            return;

         }

         if(m_estatus != error_not_found && m_estatus != error_path_not_found)
         {

            /*         if (pException != nullptr)
            {
            pException->create(this);
            ::file::exception * pfe = dynamic_cast < ::file::exception * > (pException->m_p);
            if(pfe != nullptr)
            {
            pfe->m_lOsError = dwLastError;
            pfe->m_cause = ::win::file_exception::os_error_to_exception(pfe->m_lOsError);
            pfe->m_strFileName = lpszFileName;
            }
            return false;
            }
            else
            {*/


            //return __new(::file::exception(::error_os_error_to_exception(dwLastError), dwLastError, m_strFileName, nOpenFlags));
            throw ::file::exception(m_estatus, errorcode, path, "::open == -1", m_eopen);

            //}

         }

         /*try
         {
            get_app()->m_psystem->m_spfilesystem.m_p->FullPath(m_wstrFileName, m_wstrFileName);
         }
         catch(...)
         {
            return false;
         }

         m_strFileName = unicode_to_utf8(m_wstrFileName);

         hFile = ::open(m_strFileName, nOpenFlags);*/

         if (hFile == -1)
         {
            /*if (pException != nullptr)
            {
            pException->create(this);
            ::file::exception * pfe = dynamic_cast < ::file::exception * > (pException->m_p);
            if(pfe != nullptr)
            {
            pfe->m_lOsError = ::get_last_error();
            pfe->m_cause = ::win::file_exception::os_error_to_exception(pfe->m_lOsError);
            pfe->m_strFileName = lpszFileName;
            }
            return false;
            }
            else
            {*/

            throw ::file::exception(m_estatus, errorcode, path, "::open == -1 (2)", m_eopen);

            //}

         }

      }

      m_iFile = (i32)hFile;

      m_estatus = ::success;

      set_ok();

      //return ::success;

   }


   memsize file::read(void * lpBuf, memsize nCount)
   {
      ASSERT_VALID(this);
      ASSERT(m_iFile != hFileNull);

      if (nCount == 0)
         return 0;   // avoid Win32 "null-read"

      ASSERT(lpBuf != nullptr);
      ASSERT(__is_valid_address(lpBuf, nCount));

      memsize pos = 0;
      memsize sizeRead = 0;
      memsize readNow;
      while(nCount > 0)
      {
         readNow = (size_t) minimum(0x7fffffff, nCount);
         i32 iRead = ::read(m_iFile, &((byte *)lpBuf)[pos], readNow);
         
         if(iRead < 0)
         {
            
            auto iErrNo = errno;

            auto estatus = errno_to_status(iErrNo);

            auto errorcode = __errno(iErrNo);

            throw ::file::exception(estatus, errorcode, m_path, "::read < 0", m_eopen);

         }
         else if(iRead == 0)
         {
            break;
         }

         nCount -= iRead;
         pos += iRead;
         sizeRead += iRead;
      }

      return sizeRead;
   }

   
   void file::write(const void * lpBuf, memsize nCount)
   {

      ASSERT_VALID(this);

      ASSERT(m_iFile != hFileNull);

      if (nCount == 0)
      {

         return;     // avoid Win32 "null-write" option

      }

      ASSERT(lpBuf != nullptr);

      ASSERT(__is_valid_address(lpBuf, nCount, false));

      memsize pos = 0;

      while(nCount > 0)
      {
         
         i32 iWrite = ::write(m_iFile, &((const byte *)lpBuf)[pos], (size_t) minimum(0x7fffffff, nCount));
         
         if (iWrite < 0)
         {

            auto iErrNo = errno;

            auto estatus = errno_to_status(iErrNo);

            auto errorcode = __errno(iErrNo);

            throw ::file::exception(estatus, errorcode, m_path, "::write < 0", m_eopen);

         }

         nCount -= iWrite;
         pos += iWrite;
      }

      // Win32s will not return an error all the time (usually DISK_FULL)
      //if (iWrite != nCount)
      //vfxThrowFileexception(::error_disk_full, -1, m_strFileName);
   }

   filesize file::translate(filesize lOff, ::enum_seek eseek)
   {

      if (m_iFile == hFileNull)
      {

         auto iErrNo = -1;

         auto estatus = error_bad_argument;

         auto errorcode = __errno(iErrNo);

         throw ::file::exception(estatus, errorcode, m_path, "m_iFile == hFileNull", m_eopen);

      }

      ASSERT_VALID(this);
      ASSERT(m_iFile != hFileNull);
      ASSERT(eseek == ::e_seek_set || eseek == ::e_seek_from_end || eseek == ::e_seek_current);
      ASSERT(::e_seek_set == SEEK_SET && ::e_seek_from_end == SEEK_END && ::e_seek_current == SEEK_CUR);

      ::i32 lLoOffset = lOff & 0xffffffff;

      filesize posNew = ::lseek64(m_iFile, lLoOffset, (::u32)eseek);

      if (posNew < 0)
      {

         auto iErrNo = errno;

         auto estatus = errno_to_status(iErrNo);

         auto errorcode = __errno(iErrNo);

         throw ::file::exception(estatus, errorcode, m_path, "lseek64 < 0", m_eopen);

      }

      return posNew;

   }


   filesize file::get_position() const
   {
      ASSERT_VALID(this);
      ASSERT(m_iFile != hFileNull);

      ::i32 lLoOffset = 0;
//      ::i32 lHiOffset = 0;

      filesize pos = ::lseek64(m_iFile, lLoOffset, SEEK_CUR);
      //    pos |= ((filesize)lHiOffset) << 32;
      if (pos < 0)
      {
       
         auto iErrNo = errno;

         auto estatus = errno_to_status(iErrNo);

         auto errorcode = __errno(iErrNo);

         throw ::file::exception(estatus, errorcode, m_path, "lseek64 < 0", m_eopen);

      }

      return pos;
   }

   void file::flush()
   {

      /*      ::open
            ::read
            ::write

            access the system directly no buffering : direct I/O - efficient for large writes - innefficient for lots of single byte writes

            */

      /*ASSERT_VALID(this);

      /*  if (m_iFile == hFileNull)
         return;

      if (!::FlushFileBuffers((HANDLE)m_iFile))
         ::file::throw_os_error( (::i32)::get_last_error());*/
   }

   void file::close()
   {
      ASSERT_VALID(this);
      ASSERT(m_iFile != hFileNull);

      bool bError = false;
      if (m_iFile != hFileNull)
         bError = ::close(m_iFile) == -1;

      m_iFile = (::u32) hFileNull;
      m_strFileName.Empty();

      if (bError)
      {

         auto iErrNo = errno;

         auto estatus = errno_to_status(iErrNo);

         auto errorcode = __errno(iErrNo);

         throw ::file::exception(estatus, errorcode, m_path, "::close == -1", m_eopen);

      }

   }


   //void file::Abort()
   //{
   //   ASSERT_VALID(this);
   //   if (m_iFile != hFileNull)
   //   {
   //      // close but ignore errors
   //      ::close(m_iFile);
   //      m_iFile = (::u32)hFileNull;
   //   }
   //   m_strFileName.Empty();
   //}

   void file::lock(filesize dwPos, filesize dwCount)
   {
      ASSERT_VALID(this);
      ASSERT(m_iFile != hFileNull);

      /*if (!::LockFile((HANDLE)m_iFile, LODWORD(dwPos), HIDWORD(dwPos), LODWORD(dwCount), HIDWORD(dwCount)))
         ::file::throw_os_error( (::i32)::get_last_error());*/
   }

   void file::unlock(filesize dwPos, filesize dwCount)
   {
      ASSERT_VALID(this);
      ASSERT(m_iFile != hFileNull);

      /*      if (!::UnlockFile((HANDLE)m_iFile,  LODWORD(dwPos), HIDWORD(dwPos), LODWORD(dwCount), HIDWORD(dwCount)))
               ::file::throw_os_error( (::i32)::get_last_error());*/
   }

   void file::set_size(filesize dwNewLen)
   {
      ASSERT_VALID(this);
      ASSERT(m_iFile != hFileNull);

      set_position((::i32)dwNewLen);

#ifdef __LP64
      int iError = ::ftruncate64(m_iFile, dwNewLen);
      if (iError == -1)
         ::file::throw_os_error( (::i32)::get_last_error());
#else
      int iError = ::ftruncate(m_iFile, dwNewLen);
      if (iError == -1)
      {

         auto iErrNo = errno;

         auto estatus = errno_to_status(iErrNo);

         auto errorcode = __errno(iErrNo);

         throw ::file::exception(estatus, errorcode, m_path, "ftruncate == -1", m_eopen);

      }
#endif
   }

   filesize file::get_size() const
   {
      ASSERT_VALID(this);

      filesize dwLen, dwCur;

      // seek is a non const operation
      file* pFile = (file*)this;
      dwCur = pFile->get_position();
      dwLen = pFile->seek_to_end();
      VERIFY(dwCur == pFile->set_position(dwCur));

      return (filesize) dwLen;
   }

   //// file does not support direct buffering (CMemFile does)
   //u64 file::GetBufferPtr(::u32 nCommand, u64 /*nCount*/,
   //                            void ** /*ppBufStart*/, void ** /*ppBufMax*/)
   //{
   //   ASSERT(nCommand == bufferCheck);
   //   __UNREFERENCED_PARAMETER(nCommand);    // not used in retail build

   //   return 0;   // no support
   //}

   /*
   void PASCAL file::Rename(const char * lpszOldName, const char * lpszNewName)
   {
   if (!::MoveFile((char *)lpszOldName, (char *)lpszNewName))
   ::win::file::throw_os_error( (::i32)::get_last_error());
   }

   void PASCAL file::erase(const char * lpszFileName)
   {
   if (!::DeleteFile((char *)lpszFileName))
   ::win::file::throw_os_error( (::i32)::get_last_error());
   }
   */





   /////////////////////////////////////////////////////////////////////////////
   // file diagnostics


   void file::assert_ok() const
   {
      ::file::file::assert_ok();
      // we permit the descriptor m_iFile to be any value for derived classes
   }

   
   void file::dump(dump_context & dumpcontext) const
   {
      
      ::file::file::dump(dumpcontext);

      //dumpcontext << "with handle " << (::u32)m_iFile;
      //dumpcontext << " and name \"" << m_strFileName << "\"";
      //dumpcontext << "\n";

   }


   //string file::GetFileName() const
   //{
   //   ASSERT_VALID(this);

   //   ::file::file_status status;
   //   GetStatus(status);
   //   return status.m_strFullName.name();
   //}

   //string file::GetFileTitle() const
   //{
   //   ASSERT_VALID(this);

   //   ::file::file_status status;
   //   GetStatus(status);
   //   return status.m_strFullName.title();
   //}

   ::file::path file::get_file_path() const
   {
      
      ASSERT_VALID(this);
      
      ::file::file_status status;
      
      get_status(status);

      return status.m_strFullName;

   }




   /////////////////////////////////////////////////////////////////////////////
   // FileException




   //void PASCAL ::file::throw_os_error(::matter * pobject, ::i32 lOsError, const char * lpszFileName /* = nullptr */)
   //{
   //   if (lOsError != 0)
   //      vfxThrowFileexception(file_exception::os_error_to_exception(lOsError), lOsError, lpszFileName);
   //}

   //void PASCAL file_exception::ThrowErrno(::matter * pobject, i32 nErrno, const char * lpszFileName /* = nullptr */)
   //{
   //   if (nErrno != 0)
   //      vfxThrowFileexception(file_exception::errno_to_status(nErrno), errno, lpszFileName);
   //}





   // IMPLEMENT_DYNAMIC(WinFileException, ::exception)

   /////////////////////////////////////////////////////////////////////////////




   /////////////////////////////////////////////////////////////////////////////
   // file Status implementation

   bool file::get_status(::file::file_status& rStatus) const
   {
      ASSERT_VALID(this);

      //__memset(&rStatus, 0, sizeof(::file::file_status));

      // copy file name from cached m_strFileName
      rStatus.m_strFullName = m_strFileName;

      if (m_iFile != hFileNull)
      {
         struct stat st;
         if(fstat(m_iFile, &st) == -1)
            return false;
         // get time ::e_seek_current file size_i32
         /*FILETIME ftCreate, ftAccess, ftModify;
         if (!::GetFileTime((HANDLE)m_iFile, &ftCreate, &ftAccess, &ftModify))
            return false;*/

         rStatus.m_filesize = st.st_size;

         rStatus.m_attribute = 0;

         rStatus.m_ctime = ::earth::time(st.st_mtime);
         rStatus.m_atime = ::earth::time(st.st_atime);
         rStatus.m_mtime = ::earth::time(st.st_ctime);

         if (rStatus.m_ctime.get_time() == 0)
            rStatus.m_ctime = rStatus.m_mtime;

         if (rStatus.m_atime.get_time() == 0)
            rStatus.m_atime = rStatus.m_mtime;
      }
      return true;
   }





   bool file::is_opened() const
   {
      return m_iFile != hFileNull;
   }


   void file::set_file_path(const ::file::path & path)
   {

      m_strFileName = path;

   }


} // namespace acme_android


#define _wcsdec(_cpc1, _cpc2) ((_cpc1)>=(_cpc2) ? nullptr : (_cpc2)-1)

#define _wcsinc(_pc)    ((_pc)+1)


// turn a file, relative path or other into an absolute path
bool CLASS_DECL_ACME windows_full_path(wstring & wstrFullPath, const wstring & wstrPath)
{

   wstrFullPath = wstrPath;
   
   return true;

}



