#include "framework.h"


namespace multimedia
{


   namespace audio_opensles
   {


      factory_exchange::factory_exchange(::aura::application * papp) :
         object(papp)
      {

         //psystem->factory().cloneable_large < wave_in               >  (psystem->type_info < ::multimedia::audio::wave_in                  > ());
         psystem->factory().cloneable_large < wave_out              >  (psystem->type_info < ::multimedia::audio::wave_out                 > ());

      }


      factory_exchange::~factory_exchange()
      {
      }


   } // namespace audio_opensles


} // namespace multimedia


extern "C"
void ca2_factory(::aura::application * papp)
{

   ::multimedia::audio_opensles::factory_exchange factoryexchange(papp);

}









