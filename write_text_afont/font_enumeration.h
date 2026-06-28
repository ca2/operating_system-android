#pragma once


#include "aura/graphics/write_text/font_enumeration.h"


<<<<<<< HEAD
#include "acme/_operating_system.h"


namespace write_text_win32
{


   // Windows GDI

   class CLASS_DECL_WRITE_TEXT_WIN32 font_enumeration :
=======
namespace write_text_afont
{


   class CLASS_DECL_WRITE_TEXT_AFONT font_enumeration :
>>>>>>> origin/main
      virtual public ::write_text::font_enumeration
   {
   public:


<<<<<<< HEAD
      //__creatable_from_base(font_enumeration, ::write_text::font_enumeration);


      HDC                                    m_hdc;
      wstring                                m_wstrTopicFaceName;


=======
>>>>>>> origin/main
      font_enumeration();
      ~font_enumeration() override;


      void on_enumerate_fonts() override;


<<<<<<< HEAD
      virtual void enumerate_character_set(::write_text::font_enumeration_item * pitem);


      static ::i32 CALLBACK OLDFONTENUMPROCW(CONST LOGFONTW* plogfont, CONST TEXTMETRICW* ptextmetric, DWORD dwFontType, LPARAM lparam);


      static ::i32 CALLBACK OLDFONTENUMPROCW_character_set(CONST LOGFONTW* plogfont, CONST TEXTMETRICW* ptextmetric, DWORD dwFontType, LPARAM lparam);


   };


} // namespace write_text_win32



=======
   };


} // namespace write_text_afont
>>>>>>> origin/main
