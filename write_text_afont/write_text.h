// Created by camilo 2021-02-10 <3TBS_!!
#pragma once


#include "aura/graphics/write_text/write_text.h"


<<<<<<< HEAD
namespace write_text_win32
{


   class CLASS_DECL_WRITE_TEXT_WIN32 write_text :
=======
namespace write_text_afont
{


   class CLASS_DECL_WRITE_TEXT_AFONT write_text :
>>>>>>> origin/main
      virtual public ::write_text::write_text
   {
   public:


      

<<<<<<< HEAD
      //__creatable_from_base(write_text, ::write_text::write_text, "write_text_win32");
=======
      //__creatable_from_base(write_text, ::write_text::write_text, "write_text_afont");
>>>>>>> origin/main


      write_text();
      ~write_text() override;


   };


<<<<<<< HEAD
} // namespace write_text_win32
=======
} // namespace write_text_afont
>>>>>>> origin/main



