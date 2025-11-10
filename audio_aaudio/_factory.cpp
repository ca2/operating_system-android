#include "framework.h"
#include "wave_in.h"
#include "wave_out.h"


__FACTORY_EXPORT void audio_aaudio_factory(::factory::factory * pfactory)
{

   pfactory->add_factory_item < ::multimedia::audio_aaudio::wave_in  , ::wave::in                  > ();

   pfactory->add_factory_item < ::multimedia::audio_aaudio::wave_out ,::wave::out                 > ();

}



