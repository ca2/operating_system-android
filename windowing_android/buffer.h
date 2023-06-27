#pragma once


#include "aura/graphics/graphics/double_buffer.h"


namespace windowing_android
{


   class CLASS_DECL_AURA buffer :
      virtual public ::graphics::double_buffer
   {
   public:


      buffer();
      ~buffer() override;

      ::graphics::buffer_item * on_begin_draw() override;

      bool update_buffer(::graphics::buffer_item * pitem) override;
      void destroy_buffer() override;

      bool on_update_screen(::graphics::buffer_item * pitem) override;

      //virtual ::draw2d::graphics * on_begin_draw();

   };


} // namespace windowing_android



