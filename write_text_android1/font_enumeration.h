// From write_text_pango by camilo on 2022-01-05 05:21 <3ThomasBorregaardSoerensen!!
#pragma once


#include "aura/graphics/write_text/font_enumeration.h"


namespace write_text_android
{


   class CLASS_DECL_WRITE_TEXT_ANDROID font_enumeration :
      virtual public ::write_text::font_enumeration
   {
   public:



      font_enumeration();
      ~font_enumeration() override;



      void on_enumerate_fonts() override;


   };


} // namespace write_text_pango



