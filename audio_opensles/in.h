#pragma once


#include "engine.h"
#include "app-core/audio/wave/in.h"


namespace multimedia
{


   namespace audio_opensles
   {


      class  CLASS_DECL_AUDIO_OPENSLES in :
         public engine,
         virtual public ::wave::in
      {
      public:




         in();
         ~in() override;


         virtual bool wave_in_initialize_encoder();

         //virtual ::e_status wave_in_add_buffer(int32_t iBuffer);
         //virtual ::e_status wave_in_add_buffer(LPWAVEHDR lpwavehdr);

         //snd_pcm_t * wave_in_get_safe_PCM();
         virtual void * get_os_data();

         void in_open(i32 iBufferCount, i32 iBufferSampleCount) override;
         void in_close() override;
         void in_stop() override;
         void in_start() override;
         void in_reset() override;

         //virtual void translate_wave_in_message(::signal_details * pobj);

         void init_task() override;
         void term_task() override;
         //virtual void pre_translate_message(::signal_details * pobj);

         //void CALLBACK wave_in_proc(snd_pcm_t * hwi, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2);

         void run() override;

         //WAVEFORMATEX * wave_format();
         //LPWAVEHDR wave_hdr(int iBuffer);


      };


   } // namespace audio_opensles


} // namespace multimedia




