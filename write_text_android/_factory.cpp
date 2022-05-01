#include "framework.h"


__FACTORY_EXPORT void write_text_android_factory(::factory::factory * pfactory)
{

   pfactory->add_factory_item < ::write_text_android::fonts, ::write_text::fonts >();
   pfactory->add_factory_item < ::write_text_android::write_text, ::write_text::write_text >();
   pfactory->add_factory_item < ::write_text_android::font_enumeration, ::write_text::font_enumeration >();

}
