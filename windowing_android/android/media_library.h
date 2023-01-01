// Created by camilo on 2022-05-28 02:43 <3ThomasBorregaardS�rensen
#pragma once


#include "acme/primitive/media_library/item.h"


namespace android
{


   class library_item :
      virtual public ::media_library::item
   {
   public:


      ::i64       m_iId;
      string      m_strDisplayName;
      string      m_strFullPath;
      string      m_strMimeType;

      library_item(::i64 iId) : m_iId(iId) {}

      ::string get_id() override;
      ::string get_display_name() override;
      ::string get_full_path() override;
      ::string get_mime_type() override;
      
   };


   class audio_item :
      virtual public library_item
   {
   public:


      string m_strTitle;
      string m_strArtist;


      audio_item(::i64 iId, const ::string& strTitle, const ::string& strArtist) :
         library_item(iId),
         m_strTitle(strTitle),
         m_strArtist(strArtist)
      {

      }


      ::enum_media_library media_library_type() override;

      /
      ::string get_title() override;
      ::string get_artist() override;


   };


   class images_item :
      virtual public library_item
   {
   public:


      string m_strTitle;

      images_item(::i64 iId, const ::string& strTitle) :
         library_item(iId),
         m_strTitle(strTitle)
      {

      }


      ::enum_media_library media_library_type() override;

      /
      ::string get_title() override;


   };


   class video_item :
      virtual public library_item
   {
   public:


      string m_strTitle;
      string m_strArtist;

      video_item(::i64 iId, const ::string& strTitle, const ::string& strArtist) :
         library_item(iId),
         m_strTitle(strTitle),
         m_strArtist(strArtist)
      {

      }


      ::enum_media_library media_library_type() override;


      /
      ::string get_title() override;
      ::string get_artist() override;


   };


   void add_media_library_item(library_item* plibraryitem);


} // namespace android



