#include "framework.h"
#include "out.h"
#include "audio/audio/audio.h"


__FACTORY_EXPORT void audio_opensles_factory(::factory::factory* pfactory)
{

   pfactory->add_factory_item < ::multimedia::audio_opensles::out, ::wave::out >();

}



