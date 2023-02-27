#pragma once


#include "engine.h"
#include "audio/audio/wave/out.h"


namespace multimedia
{


   namespace audio_opensles
   {


      class  CLASS_DECL_AUDIO_OPENSLES out :
         virtual public engine,
         virtual public ::wave::out
      {
      public:


         enum e_impl_message
         {

            message_ready = 5555,
            message_free

         };

         // output mix interfaces
         SLObjectItf outputMixObject;

         // buffer queue player interfaces
         SLObjectItf bqPlayerObject;
         SLPlayItf bqPlayerPlay;
         SLVolumeItf bqPlayerVolume;
         SLAndroidSimpleBufferQueueItf bqPlayerBufferQueue;
         SLEffectSendItf bqPlayerEffectSend;

         //manual_reset_event      m_evBufferFull;

         bool                    m_bWrite;
         int                     m_iBuffer;

         int m_iBufferCount;
         int m_iPlayBuffer;


         out();
         ~out() override;


         void install_message_routing(::channel * pchannel) override;

         class ::time out_get_position() override;
         //imedia_position wave_out_get_position();

         void out_open_ex(::thread* pthreadCallback, u32 uiSamplesPerSec, u32 uiChannelCount, u32 uiBitsPerSample, ::wave::enum_purpose epurpose) override;
         //void out_open_ex(::thread * pthreadCallback, int32_t iBufferCount, int32_t iBufferSampleCount, uint32_t uiSamplesPerSec, uint32_t uiChannelCount, uint32_t uiBitsPerSample, ::multimedia::audio::e_purpose epurpose) override;
         void out_stop() override;
         void out_close() override;
         void out_pause() override;
         void out_restart() override;
         virtual void * get_os_data();

         virtual void out_on_playback_end() override;
         void out_filled(int iBuffer) override;
         virtual void opensles_out_filled(int iBuffer);
         virtual void out_free(int iBuffer) override;
         virtual void opensles_out_free(int iBuffer);

         //virtual bool initialize_thread() override;
         //virtual int32_t exit_thread() override;

         DECLARE_MESSAGE_HANDLER(OnReady);
         DECLARE_MESSAGE_HANDLER(OnFree);

         void out_start(const class time & time) override;

         virtual bool on_run_step();

         virtual int underrun_recovery(int err);

         //int32_t wave_out_get_buffered_buffer_count();

      };


   } // namespace audio_opensles


} // namespace multimedia



