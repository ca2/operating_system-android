// Created by camilo 2021-01
// Recreated by camilo 2021-02-10 <3TBS_!!
// From write_text_pango by camilo on 2022-01-05 05:21 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/platform/node.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "aura/graphics/write_text/font_enumeration_item.h"
#include "aura/graphics/write_text/true_type_font_utilities.h"
#include "aura/graphics/draw2d/draw2d.h"
#include "aqua/xml/document.h"
//#include <pango/pangocairo.h>


namespace write_text_android
{


   font_enumeration::font_enumeration()
   {


   }


   font_enumeration::~font_enumeration()
   {


   }


   void font_enumeration::on_enumerate_fonts()
   {

      //synchronous_lock ml(cairo_mutex());

      __defer_construct_new(m_pfontenumerationitema);

      m_pfontenumerationitema->erase_all();

      auto & itema = *m_pfontenumerationitema;

      //namespace draw2d
      //{


      //   void draw2d::enum_draw2d_fonts(::write_text::font_enumeration_item_array & itema)
      //   {

      //      critical_section_lock synchronouslock(::aura::g_pcsFont);

      auto pwritetext = system()->m_paurasystem->m_pdraw2d->m_pwritetext;

            ::pointer<::write_text::font_enumeration_item>pitem;

            double dAndroid = 4.4;

            string strSystemFonts = file()->safe_get_string("/system/etc/system_fonts.xml");

            if (strSystemFonts.is_empty())
            {

               strSystemFonts = file()->safe_get_string("/system/etc/fonts.xml");

            }

            auto pxmldocument = __create_new < ::xml::document >();

            ::pointer<true_type_font_utilities>putilities;

            //::e_status estatus = 
            __construct_new(putilities);

            const char * pszSystemFonts = strSystemFonts;

            bool bOk = true;

            try
            {

               pxmldocument->load(strSystemFonts);

            }
            catch (...)
            {

               bOk = false;

            }

            if(bOk)
            {

               ::collection::count iChildCount = 0;

               string strFamily;

               while (auto pfamily = pxmldocument->root()->get_child_at(iChildCount))
               {

                  iChildCount++;

                  if (pfamily->m_strName == "alias" && strFamily.has_char())
                  {

                     string strWeight = pfamily->attribute("weight");

                     if (strWeight.has_char())
                     {

                        int iWeight = atoi(strWeight);

                        int iItalic = pfamily->attribute("style").case_insensitive_equals("italic");

                        int iKey = iWeight * 10 + iItalic;

                        string strName = pfamily->attribute("name");

                        //::file::path path = pfamily->attribute("path");;

                        ::file::path path = pwritetext->m_mapFontKeyFaceName[strFamily][iKey];

                        pitem = __new ::write_text::font_enumeration_item();

                        pitem->m_mapFileName[iKey] = path;

                        pitem->m_strName = strName;

                        itema.add(pitem);

                        auto & map = pwritetext->m_mapFontKeyFaceName;

                        auto & map2 = map[strName];

                        map2[iKey] = path.c_str();

                     }
                     else
                     {


                        string strName = pfamily->attribute("name");

                        for (auto & pair : pwritetext->m_mapFontKeyFaceName[strFamily])
                        {

                           pitem = __new ::write_text::font_enumeration_item();

                           pitem->m_mapFileName[pair.m_element1] = pair.m_element2;

                           pitem->m_strName = strName;

                           itema.add(pitem);

                           auto & map = pwritetext->m_mapFontKeyFaceName;

                           auto & map2 = map[strName];

                           map2[pair.m_element1] = pair.m_element2;

                        }

                     }



                     continue;

                  }


                  if (pfamily->m_strName != "family")
                  {

                     continue;

                  }

                  if (pfamily->get_name() == "family")
                  {

                     ::collection::index iNamesetPos = 0;

                     auto pnameset = pfamily->get_child("nameset", iNamesetPos);

                     ::collection::index iFilesetPos = 0;

                     auto pfileset = pfamily->get_child("fileset", iFilesetPos);

                     if (pnameset && pfileset)
                     {

                        if (pnameset->get_children_count() >= 1 && pfileset->get_children_count() >= 1)
                        {

                           ::collection::index iNamePos = 0;

                           auto pfirstname = pnameset->get_child("name", iNamePos);

                           ::collection::index iFilePos = 0;

                           auto pfirstfile = pfileset->get_child("file", iFilePos);

                           if (pfirstname && pfirstfile)
                           {

                              string strName = pfirstname->get_value();

                              string strFile = pfirstfile->get_value();

                              strFamily = strName;

                              ::file::path path = "/system/fonts";

                              path /= strFile;

                              pitem = __new ::write_text::font_enumeration_item();

                              if (acmefile()->exists(path))
                              {

                                 pitem->m_mapFileName[0] = path;

                              }
                              else
                              {

                                 pitem->m_mapFileName[0] = strFile;

                              }

                              pitem->m_strName = strName;

                              itema.add(pitem);

                              pwritetext->m_mapFontKeyFaceName[strName][0] = pitem->m_mapFileName[0];

                           }

                        }

                     }
                     else
                     {

                        ::collection::count iFontCount = 0;

                        strFamily = pfamily->attribute("name");

                        pitem = __new ::write_text::font_enumeration_item();

                        pitem->m_strName = strFamily;

                        itema.add(pitem);

                        while (true)
                        {

                           auto pnodeFont = pfamily->get_child("font", iFontCount);

                           if (!pnodeFont)
                           {

                              break;

                           }

                           iFontCount++;

                           int iWeight = pnodeFont->attribute("weight").as_i32();

                           int iItalic = pnodeFont->attribute("style").case_insensitive_equals("italic");

                           int iKey = iWeight * 10 + iItalic;

                           string strFile = pnodeFont->get_value();

                           ::file::path path = "/system/fonts";

                           path /= strFile;

                           if (acmefile()->exists(path))
                           {

                              pitem->m_mapFileName[iKey] = path;

                           }
                           else
                           {

                              pitem->m_mapFileName[iKey] = strFile;

                           }

                           auto & map = pwritetext->m_mapFontKeyFaceName;

                           auto & map2 = map[strFamily];

                           map2[iKey] = path.c_str();

                        }

                     }

                  }

               }

            }

            if (dAndroid >= 8.0)
            {

               ::file::listing listing;

               listing.set_file_listing("/system/fonts");

               acmedirectory()->enumerate(listing);

               //::dir::ls(patha, "/system/fonts");

               //if (estatus.succeeded())
               {

                  for (auto & path : listing)
                  {

                     pitem = __new ::write_text::font_enumeration_item();

                     pitem->m_mapFileName[0] = path;

                     string strName = putilities->GetFontNameFromFile(path);

                     if (strName.is_empty())
                     {

                        strName = path.title();

                     }

                     pitem->m_strName = strName;

                     itema.add(pitem);

                     pwritetext->m_mapFontKeyFaceName[strName][0] = path;

                  }

               }

            }

            if (itema.is_empty())
            {


//#ifdef FONT_MONO

               pitem = __new ::write_text::font_enumeration_item();

               pitem->m_mapFileName[0] = node()->font_name(e_font_monospace);

               pitem->m_strName = node()->font_name(e_font_monospace);

               itema.add(pitem);

//#endif


//#ifdef FONT_SANS

               pitem = __new ::write_text::font_enumeration_item();

               pitem->m_mapFileName[0] = system()->m_pnode->font_name(e_font_sans);

               pitem->m_strName = system()->m_pnode->font_name(e_font_sans);

               itema.add(pitem);

//#endif


//#ifdef FONT_SERIF

               pitem = __new ::write_text::font_enumeration_item();

               pitem->m_mapFileName[0] = system()->m_pnode->font_name(e_font_serif);

               pitem->m_strName = system()->m_pnode->font_name(e_font_serif);

               itema.add(pitem);

//#endif


//#ifdef FONT_SANS_EX

               pitem = __new ::write_text::font_enumeration_item();

               pitem->m_mapFileName[0] = system()->m_pnode->font_name(e_font_sans_ex);

               pitem->m_strName = system()->m_pnode->font_name(e_font_sans_ex);

               itema.add(pitem);

//#endif


//#ifdef FONT_SERIF_EX

               pitem = __new ::write_text::font_enumeration_item();

               pitem->m_mapFileName[0] = system()->m_pnode->font_name(e_font_serif_ex);

               pitem->m_strName = system()->m_pnode->font_name(e_font_serif_ex);

               itema.add(pitem);

//#endif


//#ifdef FONT_SANS_FX

               pitem = __new ::write_text::font_enumeration_item();

               pitem->m_mapFileName[0] = system()->m_pnode->font_name(e_font_sans_fx);

               pitem->m_strName = system()->m_pnode->font_name(e_font_sans_fx);

               itema.add(pitem);

//#endif


//#ifdef FONT_SERIF_FX

               pitem = __new ::write_text::font_enumeration_item();

               pitem->m_mapFileName[0] = system()->m_pnode->font_name(e_font_serif_fx);

               pitem->m_strName = system()->m_pnode->font_name(e_font_serif_fx);

               itema.add(pitem);

//#endif


#ifdef FONT_SANS_FX2

               pitem = __new ::write_text::font_enumeration_item();

               pitem->m_mapFileName[0] = FONT_SANS_FX2;

               pitem->m_strName = FONT_SANS_FX2;

               itema.add(pitem);

#endif


            }

         }


      //} // namespace draw2d





      //PangoFontMap * pfontmap = pango_cairo_font_map_get_default();

      //PangoFontFamily ** families;

      //int n_families = 0;

      //pango_font_map_list_families(pfontmap, &families, &n_families);

      //printf("Total fonts: %d", n_families);

      //for (int i = 0; i < n_families; i++)
      //{

      //   auto pitem = __new ::write_text::font_enumeration_item();

      //   PangoFontFamily * pfamily = families[i];

      //   string strFileName = pango_font_family_get_name(pfamily);

      //   pitem->m_mapFileName[0] = strFileName;

      //   pitem->m_strName = strFileName;

      //   m_pfontenumerationitema->add(pitem);

      //}

      //g_free(families);

      //return ::success;

   //}


} // namespace write_text_android



