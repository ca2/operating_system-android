#pragma once


#include "aura/graphics/write_text/font_enumeration.h"


namespace write_text_afont
{


   class CLASS_DECL_WRITE_TEXT_AFONT font_enumeration :
      virtual public ::write_text::font_enumeration
   {
   public:




      //HDC                                    m_hdc;
      //wstring                                m_wstrTopicFaceName;


      font_enumeration();
      ~font_enumeration() override;


      void on_enumerate_fonts() override;


   };


} // namespace write_text_afont
