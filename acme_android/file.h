#pragma once


class FileException;
struct FileStatus;


#define INVALID_FILE -1


namespace acme_android
{


   class CLASS_DECL_ACME file :
      virtual public ::file::file
   {
   public:


      enum Attribute
      {
         normal =    0x00,
         readOnly =  0x01,
         hidden =    0x02,
         system =    0x04,
         volume =    0x08,
         directory = 0x10,
         archive =   0x20
      };

      enum
      {

         hFileNull = -1

      };

      enum BufferCommand
      {

         bufferRead,
         bufferWrite,
         bufferCommit,
         bufferCheck

      };

      ::file::path   m_strFileName;
      i32        m_iFile;


      file();
      ~file() override;


      void assert_ok() const override;
      void dump(dump_context & dumpcontext) const override;


      virtual filesize get_position() const override;


      virtual bool get_status(::file::file_status & rStatus) const override;
      //virtual string GetFileName() const;
      //virtual string GetFileTitle() const;
      ::file::path get_file_path() const override;
      void set_file_path(const ::file::path & path) override;

      void open(const ::file::path & lpszFileName, const ::file::e_open & eopen) override;

      //virtual bool PASCAL GetStatus(const char * lpszFileName, ::file::file_status& rStatus);

      //u64 ReadHuge(void * lpBuffer, u64 dwCount);
      //void WriteHuge(const void * lpBuffer, u64 dwCount);

      //virtual file_pointer Duplicate() const;

      virtual filesize translate(filesize lOff, ::enum_seek eseek) override;
      virtual void set_size(filesize dwNewLen) override;
      virtual filesize get_size() const override;

      virtual memsize read(void * lpBuf, memsize nCount) override;
      virtual void write(const void * lpBuf, memsize nCount) override;

      virtual void lock(filesize dwPos, filesize dwCount) override;
      virtual void unlock(filesize dwPos, filesize dwCount) override;

      //virtual void Abort();
      virtual void flush() override;
      virtual void close() override;

      virtual bool is_opened() const override;

      //virtual u64 GetBufferPtr(::u32 nCommand, u64 nCount = 0, void ** ppBufStart = nullptr, void ** ppBufMax = nullptr);


   };


} // namespace acme_android


bool CLASS_DECL_ACME windows_full_path(wstring & wstrFullPath, const wstring & wstrPath);



