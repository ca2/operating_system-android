// Created by camilo 2021-01
// Recreated by camilo 2021-02-10 <3TBS_!!
#include "framework.h"
#include "font_enumeration.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/platform/node.h"
#include "aura/graphics/draw2d/draw2d.h"
#include "aura/graphics/write_text/font_enumeration_item.h"
#include "aura/graphics/write_text/true_type_font_utilities.h"
#include "aqua/xml/document.h"
#include <dlfcn.h>


struct AFont;
struct ASystemFontIterator;


namespace
{


   using PFN_ASystemFontIterator_open = ASystemFontIterator * (*)();
   using PFN_ASystemFontIterator_next = AFont * (*)(ASystemFontIterator *);
   using PFN_ASystemFontIterator_close = void (*)(ASystemFontIterator *);
   using PFN_AFont_close = void (*)(AFont *);
   using PFN_AFont_getFontFilePath = const char * (*)(const AFont *);
   using PFN_AFont_getWeight = uint16_t (*)(const AFont *);
   using PFN_AFont_isItalic = bool (*)(const AFont *);


   class afont_api
   {
   public:

      void * m_plibrary = nullptr;
      PFN_ASystemFontIterator_open m_pfnSystemFontIteratorOpen = nullptr;
      PFN_ASystemFontIterator_next m_pfnSystemFontIteratorNext = nullptr;
      PFN_ASystemFontIterator_close m_pfnSystemFontIteratorClose = nullptr;
      PFN_AFont_close m_pfnFontClose = nullptr;
      PFN_AFont_getFontFilePath m_pfnFontGetFontFilePath = nullptr;
      PFN_AFont_getWeight m_pfnFontGetWeight = nullptr;
      PFN_AFont_isItalic m_pfnFontIsItalic = nullptr;


      bool load()
      {

         if (m_plibrary)
         {

            return true;

         }

         m_plibrary = dlopen("libandroid.so", RTLD_NOW | RTLD_LOCAL);

         if (!m_plibrary)
         {

            return false;

         }

         m_pfnSystemFontIteratorOpen = (PFN_ASystemFontIterator_open) dlsym(m_plibrary, "ASystemFontIterator_open");
         m_pfnSystemFontIteratorNext = (PFN_ASystemFontIterator_next) dlsym(m_plibrary, "ASystemFontIterator_next");
         m_pfnSystemFontIteratorClose = (PFN_ASystemFontIterator_close) dlsym(m_plibrary, "ASystemFontIterator_close");
         m_pfnFontClose = (PFN_AFont_close) dlsym(m_plibrary, "AFont_close");
         m_pfnFontGetFontFilePath = (PFN_AFont_getFontFilePath) dlsym(m_plibrary, "AFont_getFontFilePath");
         m_pfnFontGetWeight = (PFN_AFont_getWeight) dlsym(m_plibrary, "AFont_getWeight");
         m_pfnFontIsItalic = (PFN_AFont_isItalic) dlsym(m_plibrary, "AFont_isItalic");

         return m_pfnSystemFontIteratorOpen
            && m_pfnSystemFontIteratorNext
            && m_pfnSystemFontIteratorClose
            && m_pfnFontClose
            && m_pfnFontGetFontFilePath
            && m_pfnFontGetWeight
            && m_pfnFontIsItalic;

      }

   };


   int font_key(int iWeight, bool bItalic)
   {

      return iWeight * 10 + (bItalic ? 1 : 0);

   }


   void map_font_name(::write_text::write_text * pwritetext, const ::scoped_string & scopedstrName, int iKey, const ::file::path & path)
   {

      if (::is_null(pwritetext) || scopedstrName.is_empty() || path.is_empty())
      {

         return;

      }

      string strName(scopedstrName);

      pwritetext->m_mapFontKeyFaceName[strName][iKey] = path;

      strName.make_lower();

      pwritetext->m_mapFontKeyFaceName[strName][iKey] = path;

   }


   void map_android_font_name_alias(::write_text::write_text * pwritetext, const ::scoped_string & scopedstrAlias, const ::scoped_string & scopedstrSource)
   {

      if (::is_null(pwritetext) || scopedstrAlias.is_empty() || scopedstrSource.is_empty())
      {

         return;

      }

      string strSource(scopedstrSource);

      strSource.make_lower();

      for (auto & pair : pwritetext->m_mapFontKeyFaceName[strSource])
      {

         map_font_name(pwritetext, scopedstrAlias, pair.m_element1, pair.m_element2);

      }

   }


   void map_android_font_file(::particle * pparticle, ::write_text::write_text * pwritetext,
      const ::scoped_string & scopedstrName, const ::file::path & path)
   {

      if (::is_null(pparticle) || ::is_null(pwritetext) || scopedstrName.is_empty() || path.is_empty())
      {

         return;

      }

      if (!pparticle->file_system()->exists(path))
      {

         return;

      }

      map_font_name(pwritetext, scopedstrName, 0, path);

      for (int iWeight = 100; iWeight <= 900; iWeight += 100)
      {

         map_font_name(pwritetext, scopedstrName, font_key(iWeight, false), path);
         map_font_name(pwritetext, scopedstrName, font_key(iWeight, true), path);

      }

   }


   void map_android_system_font_files(::particle * pparticle, ::write_text::write_text * pwritetext)
   {

      ::file::path pathRoboto = "/system/fonts/Roboto-Regular.ttf";
      ::file::path pathRobotoStatic = "/system/fonts/RobotoStatic-Regular.ttf";
      ::file::path pathNotoSerif = "/system/fonts/NotoSerif-Regular.ttf";
      ::file::path pathDroidSansMono = "/system/fonts/DroidSansMono.ttf";
      ::file::path pathCutiveMono = "/system/fonts/CutiveMono.ttf";

      map_android_font_file(pparticle, pwritetext, "Roboto", pathRoboto);
      map_android_font_file(pparticle, pwritetext, "sans-serif", pathRoboto);
      map_android_font_file(pparticle, pwritetext, "Noto Serif", pathNotoSerif);
      map_android_font_file(pparticle, pwritetext, "serif", pathNotoSerif);
      map_android_font_file(pparticle, pwritetext, "Droid Sans Mono", pathDroidSansMono);
      map_android_font_file(pparticle, pwritetext, "monospace", pathDroidSansMono);
      map_android_font_file(pparticle, pwritetext, "Cutive Mono", pathCutiveMono);

      if (!pparticle->file_system()->exists(pathRoboto))
      {

         map_android_font_file(pparticle, pwritetext, "Roboto", pathRobotoStatic);
         map_android_font_file(pparticle, pwritetext, "sans-serif", pathRobotoStatic);

      }

   }


   void map_android_font_name_aliases(::write_text::write_text * pwritetext)
   {

      map_android_font_name_alias(pwritetext, "Roboto", "sans-serif");
      map_android_font_name_alias(pwritetext, "Noto Serif", "serif");
      map_android_font_name_alias(pwritetext, "Droid Sans Mono", "monospace");
      map_android_font_name_alias(pwritetext, "Cutive Mono", "serif-monospace");

   }


   void add_font_item(::write_text::font_enumeration_item_array & itema, ::write_text::write_text * pwritetext,
      const ::scoped_string & scopedstrName, const ::file::path & path, int iWeight, bool bItalic)
   {

      if (scopedstrName.is_empty() || path.is_empty())
      {

         return;

      }

      int iKey = font_key(iWeight, bItalic);

      auto pitem = allocateø ::write_text::font_enumeration_item();

      pitem->m_mapFileName[0] = path;
      pitem->m_mapFileName[iKey] = path;
      pitem->m_strName = scopedstrName;

      itema.add(pitem);

      map_font_name(pwritetext, scopedstrName, iKey, path);

      if (iWeight == 400 && !bItalic)
      {

         map_font_name(pwritetext, scopedstrName, 0, path);

      }

   }


   bool enumerate_afont(::particle * pparticle, ::write_text::font_enumeration_item_array & itema,
      ::write_text::write_text * pwritetext, true_type_font_utilities * putilities)
   {

      afont_api api;

      if (!api.load())
      {

         return false;

      }

      auto piterator = api.m_pfnSystemFontIteratorOpen();

      if (!piterator)
      {

         return false;

      }

      bool bEnumerated = false;

      while (auto pfont = api.m_pfnSystemFontIteratorNext(piterator))
      {

         const char * pszPath = api.m_pfnFontGetFontFilePath(pfont);

         if (pszPath && *pszPath)
         {

            ::file::path path = pszPath;

            string strName;

            if (putilities)
            {

               strName = putilities->GetFontNameFromFile(path);

            }

            if (strName.is_empty())
            {

               strName = path.title();

            }

            int iWeight = api.m_pfnFontGetWeight(pfont);

            if (iWeight <= 0)
            {

               iWeight = 400;

            }

            bool bItalic = api.m_pfnFontIsItalic(pfont);

            add_font_item(itema, pwritetext, strName, path, iWeight, bItalic);

            bEnumerated = true;

         }

         api.m_pfnFontClose(pfont);

      }

      api.m_pfnSystemFontIteratorClose(piterator);

      return bEnumerated;

   }


   void enumerate_android_font_xml(::particle * pparticle, ::write_text::font_enumeration_item_array & itema,
      ::write_text::write_text * pwritetext)
   {

      string strSystemFonts = pparticle->file()->safe_get_string("/system/etc/system_fonts.xml");

      if (strSystemFonts.is_empty())
      {

         strSystemFonts = pparticle->file()->safe_get_string("/system/etc/fonts.xml");

      }

      if (strSystemFonts.is_empty())
      {

         return;

      }

      auto pxmldocument = pparticle->create_newø < ::xml::document >();

      try
      {

         pxmldocument->load(strSystemFonts);

      }
      catch (...)
      {

         return;

      }

      ::collection::count iChildCount = 0;

      string strFamily;

      while (auto pfamily = pxmldocument->root()->get_child_at(iChildCount))
      {

         iChildCount++;

         if (pfamily->m_strName == "alias" && strFamily.has_character())
         {

            string strName = pfamily->attribute("name");
            string strWeight = pfamily->attribute("weight");

            if (strWeight.has_character())
            {

               int iWeight = atoi(strWeight);
               bool bItalic = pfamily->attribute("style").case_insensitive_equals("italic");
               int iKey = font_key(iWeight, bItalic);
               ::file::path path = pwritetext->m_mapFontKeyFaceName[strFamily][iKey];

               add_font_item(itema, pwritetext, strName, path, iWeight, bItalic);

            }
            else
            {

               for (auto & pair : pwritetext->m_mapFontKeyFaceName[strFamily])
               {

                  add_font_item(itema, pwritetext, strName, pair.m_element2, pair.m_element1 / 10, pair.m_element1 % 10 != 0);

               }

            }

            continue;

         }

         if (pfamily->m_strName != "family")
         {

            continue;

         }

         ::collection::index iNamesetPos = 0;
         auto pnameset = pfamily->get_child("nameset", iNamesetPos);
         ::collection::index iFilesetPos = 0;
         auto pfileset = pfamily->get_child("fileset", iFilesetPos);

         if (pnameset && pfileset)
         {

            ::collection::index iNamePos = 0;
            auto pfirstname = pnameset->get_child("name", iNamePos);
            ::collection::index iFilePos = 0;
            auto pfirstfile = pfileset->get_child("file", iFilePos);

            if (pfirstname && pfirstfile)
            {

               string strName = pfirstname->get_value();
               string strFile = pfirstfile->get_value();
               strFile.trim();
               strFamily = strName;

               ::file::path path = "/system/fonts";
               path /= strFile;

               if (!pparticle->file_system()->exists(path))
               {

                  path = strFile;

               }

               add_font_item(itema, pwritetext, strName, path, 400, false);

            }

         }
         else
         {

            strFamily = pfamily->attribute("name");

            ::collection::count iFontCount = 0;

            while (true)
            {

               auto pnodeFont = pfamily->get_child("font", iFontCount);

               if (!pnodeFont)
               {

                  break;

               }

               iFontCount++;

               int iWeight = pnodeFont->attribute("weight").as_i32();

               if (iWeight <= 0)
               {

                  iWeight = 400;

               }

               bool bItalic = pnodeFont->attribute("style").case_insensitive_equals("italic");
               string strFile = pnodeFont->get_value();
               strFile.trim();

               ::file::path path = "/system/fonts";
               path /= strFile;

               if (!pparticle->file_system()->exists(path))
               {

                  path = strFile;

               }

               add_font_item(itema, pwritetext, strFamily, path, iWeight, bItalic);

            }

         }

      }

   }


   void enumerate_system_font_directory(::particle * pparticle, ::write_text::font_enumeration_item_array & itema,
      ::write_text::write_text * pwritetext, true_type_font_utilities * putilities)
   {

      ::file::listing_base listing;

      listing.set_file_listing("/system/fonts");

      pparticle->directory_system()->enumerate(listing);

      for (auto & path : listing)
      {

         string strName;

         if (putilities)
         {

            strName = putilities->GetFontNameFromFile(path);

         }

         if (strName.is_empty())
         {

            strName = path.title();

         }

         add_font_item(itema, pwritetext, strName, path, 400, false);

      }

   }


} // namespace


namespace write_text_afont
{


   font_enumeration::font_enumeration()
   {

   }


   font_enumeration::~font_enumeration()
   {

   }


   void font_enumeration::on_enumerate_fonts()
   {

      defer_construct_newø(m_pfontenumerationitema);

      m_pfontenumerationitema->erase_all();

      auto & itema = *m_pfontenumerationitema;

      auto pwritetext = system()->m_pdraw2d->m_pwritetext;

      ::pointer<true_type_font_utilities> putilities;

      construct_newø(putilities);

      bool bAFontEnumerated = enumerate_afont(this, itema, pwritetext, putilities);

      enumerate_android_font_xml(this, itema, pwritetext);

      map_android_font_name_aliases(pwritetext);
      map_android_system_font_files(this, pwritetext);

      if (!bAFontEnumerated)
      {

         enumerate_system_font_directory(this, itema, pwritetext, putilities);

      }

      if (itema.is_empty())
      {

         add_font_item(itema, pwritetext, node()->font_name(e_font_monospace), node()->font_name(e_font_monospace), 400, false);
         add_font_item(itema, pwritetext, node()->font_name(e_font_monospace_ui), node()->font_name(e_font_monospace_ui), 400, false);
         add_font_item(itema, pwritetext, node()->font_name(e_font_monospace_ex), node()->font_name(e_font_monospace_ex), 400, false);
         add_font_item(itema, pwritetext, node()->font_name(e_font_monospace_fx), node()->font_name(e_font_monospace_fx), 400, false);
         add_font_item(itema, pwritetext, system()->m_pnode->font_name(e_font_sans), system()->m_pnode->font_name(e_font_sans), 400, false);
         add_font_item(itema, pwritetext, system()->m_pnode->font_name(e_font_sans_ui), system()->m_pnode->font_name(e_font_sans_ui), 400, false);
         add_font_item(itema, pwritetext, system()->m_pnode->font_name(e_font_serif), system()->m_pnode->font_name(e_font_serif), 400, false);
         add_font_item(itema, pwritetext, system()->m_pnode->font_name(e_font_serif_ui), system()->m_pnode->font_name(e_font_serif_ui), 400, false);
         add_font_item(itema, pwritetext, system()->m_pnode->font_name(e_font_sans_ex), system()->m_pnode->font_name(e_font_sans_ex), 400, false);
         add_font_item(itema, pwritetext, system()->m_pnode->font_name(e_font_serif_ex), system()->m_pnode->font_name(e_font_serif_ex), 400, false);
         add_font_item(itema, pwritetext, system()->m_pnode->font_name(e_font_sans_fx), system()->m_pnode->font_name(e_font_sans_fx), 400, false);
         add_font_item(itema, pwritetext, system()->m_pnode->font_name(e_font_serif_fx), system()->m_pnode->font_name(e_font_serif_fx), 400, false);

      }

   }



} // namespace write_text_afont
