// Created by camilo on 2022-05-28 02:49 <3ThomasBorregaardS�rensen
#include "framework.h"
#include "media_library.h"
#include "acme/filesystem/filesystem/acme_directory.h"


namespace android
{


   ::string library_item::get_id()
   {

      ::string str;

      str = ::as_string(m_iId);

      return ::transfer(str);

   }


   ::string library_item::get_display_name()
   {

      return m_strDisplayName;

   }


   ::string library_item::get_full_path()
   {

      return m_strFullPath;

   }


   ::string library_item::get_mime_type()
   {

      return m_strMimeType;

   }


   ::enum_media_library audio_item::media_library_type()
   {

      return e_media_library_music;

   }


   
   ::string audio_item::get_title()
   {

      return m_strTitle;

   }


   ::string audio_item::get_artist()
   {

      return m_strArtist;

   }


   ::enum_media_library video_item::media_library_type()
   {

      return e_media_library_video;

   }

   
   ::string video_item::get_title()
   {

      return m_strTitle;

   }


   ::string video_item::get_artist()
   {

      return m_strArtist;

   }


   ::enum_media_library images_item::media_library_type()
   {

      return e_media_library_image;

   }

   
   ::string images_item::get_title()
   {

      return m_strTitle;

   }


   void add_media_library_item(library_item* plibraryitem)
   {

      plibraryitem->acmedirectory()->add_media_library_item(plibraryitem);

   }


} // namespace android



