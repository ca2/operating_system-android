// Created by camilo 2021-02-10 <3TBS_!!
#pragma once


#include "aura/graphics/write_text/fonts.h"


<<<<<<< HEAD
namespace write_text_win32
{


   class CLASS_DECL_WRITE_TEXT_WIN32 fonts :
=======
namespace write_text_afont
{


   class CLASS_DECL_WRITE_TEXT_AFONT fonts :
>>>>>>> origin/main
      virtual public ::write_text::fonts
   {
   public:


      //__creatable_from_base(fonts, ::write_text::fonts);


      fonts();
      ~fonts() override;


      void initialize(::particle * pparticle) override;


   };


<<<<<<< HEAD
} // namespace write_text_win32
=======
} // namespace write_text_afont
>>>>>>> origin/main



