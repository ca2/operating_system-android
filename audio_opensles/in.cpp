#include "framework.h"
#include "in.h"
#include "acme/parallelization/synchronous_lock.h"


namespace multimedia
{


   namespace audio_opensles
   {


      in::in()
      {

         m_pencoder = NULL;
         m_einstate = ::wave::e_in_state_initial;
         m_bResetting = false;


      }

      in::~in()
      {
      }


      void in::init_task()
      {

         //information("in::initialize_instance %X\n", get_os_int());
         //SetMainWnd(NULL);
         //ASSERT(GetMainWnd() == NULL);
         set_thread_priority(::e_priority_highest);

         //m_evInitialized.SetEvent();

         //return true;

      }


      void in::term_task()
      {

         m_eventExitInstance.SetEvent();

         return thread::term_task();

      }



      void in::in_open(int32_t iBufferCount, int32_t iBufferSampleCount)
      {

         //return ::success;

         //if(m_ppcm != NULL && m_einstate != ::wave::e_in_state_initial)
         //{

         //   in_initialize_encoder();

         //   //return success;

         //   return;

         //}

         synchronous_lock sLock(synchronization());

         ::e_status mmr = ::success;

         //ASSERT(m_ppcm == NULL);

         ASSERT(m_einstate == ::wave::e_in_state_initial);

         m_pwaveformat->m_waveformat.wFormatTag = 0;
         m_pwaveformat->m_waveformat.nChannels = 2;
         m_pwaveformat->m_waveformat.nSamplesPerSec = 44100;
         m_pwaveformat->m_waveformat.wBitsPerSample = sizeof(::wave::WAVEBUFFERDATA) * 8;
         m_pwaveformat->m_waveformat.nBlockAlign = m_pwaveformat->m_waveformat.wBitsPerSample * m_pwaveformat->m_waveformat.nChannels / 8;
         m_pwaveformat->m_waveformat.nAvgBytesPerSec = m_pwaveformat->m_waveformat.nSamplesPerSec * m_pwaveformat->m_waveformat.nBlockAlign;
         //m_pwaveformat->m_waveformat.cbSize = 0;

         //return result_error;

         //if(snd_pcm_open(SND_PCM_STREAM_CAPTURE) != 0)
         //   return result_error;


         //goto Opened;
         //m_pwaveformat->wFormatTag = WAVE_FORMAT_PCM;
         //m_pwaveformat->nChannels = 2;
         //m_pwaveformat->nSamplesPerSec = 44100;
         //m_pwaveformat->wBitsPerSample = sizeof(::multimedia::audio::WAVEBUFFERDATA) * 8;
         //m_pwaveformat->nBlockAlign = m_pwaveformat->wBitsPerSample * m_pwaveformat->nChannels / 8;
         //m_pwaveformat->nAvgBytesPerSec = m_pwaveformat->nSamplesPerSec * m_pwaveformat->nBlockAlign;
         //m_pwaveformat->cbSize = 0;
         //sp(::multimedia::audio::wave) audiowave = papplication->audiowave();
         //m_iBuffer = 0;

         /*if(result_success == (mmr = waveInOpen(
            &m_hwavein,
            audiowave->m_uiWaveInDevice,
            wave_format(),
            get_os_int(),
            (uint32_t) 0,
            CALLBACK_THREAD)))
            goto Opened;
         m_pwaveformat->nSamplesPerSec = 22050;
         m_pwaveformat->nAvgBytesPerSec = m_pwaveformat->nSamplesPerSec * m_pwaveformat->nBlockAlign;
         if(result_success == (mmr = waveInOpen(
            &m_hwavein,
            WAVE_MAPPER,
            wave_format(),
            (uint32_t) get_os_int(),
            (uint32_t) 0,
            CALLBACK_THREAD)))
            goto Opened;
         m_pwaveformat->nSamplesPerSec = 11025;
         m_pwaveformat->nAvgBytesPerSec = m_pwaveformat->nSamplesPerSec * m_pwaveformat->nBlockAlign;
         if(result_success == (mmr = waveInOpen(
            &m_hwavein,
            WAVE_MAPPER,
            wave_format(),
            (uint32_t) get_os_int(),
            (uint32_t) 0,
            CALLBACK_THREAD)))
            goto Opened;

         if(mmr !=result_success)
         {
            if(mmr == MMSYSERR_ALLOCATED)
            {
               information("Specified resource is already allocated.");
            }
            else if(mmr == MMSYSERR_BADDEVICEID)
            {
               information("Specified device identifier is out of range.");
            }
            else if(mmr == WAVERR_BADFORMAT)
            {
               information("Attempted to open with an unsupported waveform-audio_opensles format.");
            }
            information("ERROR OPENING WAVE INPUT DEVICE");
            return mmr;
         }*/

//Opened:
         uint32_t uiBufferSizeLog2;
         uint32_t uiBufferSize;
         uint32_t uiAnalysisSize;
         uint32_t uiAllocationSize;
         uint32_t uiInterestSize;
         uint32_t uiSkippedSamplesCount;

         if(m_pwaveformat->m_waveformat.nSamplesPerSec == 44100)
         {
            uiBufferSizeLog2 = 16;
            uiBufferSize = m_pwaveformat->m_waveformat.nChannels * 2 * iBufferSampleCount; // 512 kbytes
            uiAnalysisSize = 4 * 1 << uiBufferSizeLog2;
            if(iBufferCount > 0)
            {
               uiAllocationSize = iBufferCount * uiBufferSize;
            }
            else
            {
               uiAllocationSize = 8 * uiAnalysisSize;
            }
            uiInterestSize = 200;
            uiSkippedSamplesCount = 2;
         }
         else if(m_pwaveformat->m_waveformat.nSamplesPerSec == 22050)
         {
           
            uiBufferSizeLog2 = 9;
            uiBufferSize = 4 * 1 << uiBufferSizeLog2;
            uiAnalysisSize = 16 * 1 << uiBufferSizeLog2;
            uiAllocationSize = 4 * uiAnalysisSize;
            uiInterestSize = 600;
            uiSkippedSamplesCount = 1;

         }
         else if(m_pwaveformat->m_waveformat.nSamplesPerSec == 11025)
         {

            uiBufferSizeLog2 = 9;
            uiBufferSize = 2 * 1 << uiBufferSizeLog2;
            uiAnalysisSize = 8 * 1 << uiBufferSizeLog2;
            uiAllocationSize = 4 * uiAnalysisSize;
            uiInterestSize = 600;
            uiSkippedSamplesCount = 1;

         }
         else
         {

            throw ::exception(::error_failed);

         }
         
         in_get_buffer()->FFTOpen(
            uiAllocationSize,
            uiBufferSize,
            uiAnalysisSize,
            uiInterestSize,
            uiSkippedSamplesCount);

         /*int32_t i, iSize;

         iSize = (int32_t) wave_in_get_buffer()->GetBufferCount();

         for(i = 0; i < iSize; i++)
         {

            if(result_success != (mmr =  waveInPrepareHeader(m_hwavein, create_new_WAVEHDR(wave_in_get_buffer(), i), sizeof(WAVEHDR))))
            {
               information("ERROR OPENING Preparing INPUT DEVICE buffer");
               return mmr;
            }

            wave_in_add_buffer(i);

         }*/

         if(m_pencoder != NULL && !wave_in_initialize_encoder())
         {

            m_einstate = ::wave::e_in_state_opened;

            in_close();

            //return (::e_status) -1;

            throw ::exception(::error_failed);

         }

         m_einstate = ::wave::e_in_state_opened;

         //return result_success;

      }


      void in::in_close()
      {

         synchronous_lock sLock(synchronization());

         ::e_status mmr;

         if (m_einstate != ::wave::e_in_state_opened && m_einstate != ::wave::e_in_state_stopped)
         {
            //return result_success;

            return;

         }

         //mmr = in_reset();

         in_reset();

         //int32_t i, iSize;

         //iSize = (int32_t) wave_in_get_buffer()->GetBufferCount();

         /*for(i = 0; i < iSize; i++)
         {

            if(result_success != (mmr = waveInUnprepareHeader(m_hwavein, wave_hdr(i), sizeof(WAVEHDR))))
            {
               information("ERROR OPENING Unpreparing INPUT DEVICE buffer");
               //return mmr;
            }

            delete wave_hdr(i);

         }*/

         //mmr = 
         
         //snd_pcm_close();

         //m_ppcm = NULL;

         m_einstate = ::wave::e_in_state_initial;

         //return result_success;

      }


      void in::in_start()
      {

         //return result_success;

         synchronous_lock sLock(synchronization());

         if (m_einstate == ::wave::e_in_state_recording)
         {

            return;

            //return result_success;

         }

         if (m_einstate != ::wave::e_in_state_opened && m_einstate != ::wave::e_in_state_stopped)
         {

            //return result_success;

            return;

         }

         ::e_status mmr;

         //if((mmr = translate_alsa(snd_pcm_start(m_ppcm))) != result_success)
         //{
         //   
         //   information("ERROR starting INPUT DEVICE ");
         //   //return mmr;

         //   throw ::exception(error_failed);

         //}

         m_einstate = ::wave::e_in_state_recording;
         //return result_success;

      }


      void in::in_stop()
      {

         synchronous_lock sLock(synchronization());

         if (m_einstate != ::wave::e_in_state_recording)
         {

            //return result_error;

            throw ::exception(::error_failed);

         }

         ::e_status mmr;

         m_einstate = ::wave::e_in_state_stopping;

         //try
         //{

         //   if(result_success != (mmr = translate_alsa(snd_pcm_drain(m_ppcm))))
         //   {

         //      information("in::wave_in_stop : ERROR OPENING stopping INPUT DEVICE ");

         //   }

         //}
         //catch(...)
         //{

         //   information("in::wave_in_stop : Exception OPENING stopping INPUT DEVICE ");

         //}

         m_einstate = ::wave::e_in_state_stopped;

         m_eventStopped.SetEvent();

         //return result_success;

      }


      void in::run()
      {

         int iBuffer = 0;
         int iSize;
         int err;

         //while(thread_get_run())
         //{

         //   if(wave_in_is_recording() && wave_in_get_buffer()->GetBufferCount() > 0)
         //   {

         //      iSize = (int32_t) wave_in_get_buffer()->GetBufferCount();

         //      if(iBuffer >= iSize)
         //         iBuffer = 0;

         //      if(iBuffer < iSize)
         //      {

         //         if ((err = snd_pcm_readi (m_ppcm, wave_in_get_buffer()->get_buffer_data(iBuffer), wave_in_get_buffer()->m_uiBufferSize)) == wave_in_get_buffer()->m_uiBufferSize)
         //         {
         //            wave_in_proc(m_ppcm, 0, 0, iBuffer, 0);
         //         }
         //         else
         //         {
         //            information("read from audio interface failed (%s)\n", snd_strerror (err));
         //         }

         //      }

         //   }
         //   else
         //   {
         //       Sleep(5);
         //   }

         //}

      }


      //void CALLBACK in::wave_in_proc(snd_pcm_t * p, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
      //{

      //   m_iBuffer--;

      //   uint32_t msSampleTime = papplication->multimedia_get_time();

      //   int iBuffer = dwParam1;

      //   wave_in_get_buffer()->get_buffer(iBuffer)->OnMultimediaDone();

      //   m_listenerset.wave_in_data_proc(this, msSampleTime, iBuffer);

      //   if(m_pencoder != NULL)
      //   {
      //      m_pencoder->EncoderWriteBuffer(wave_in_get_buffer()->get_buffer_data(iBuffer), wave_in_get_buffer()->m_uiBufferSize);
      //   }

      //   if(!wave_in_is_resetting() && wave_in_is_recording())
      //   {
      //      wave_in_add_buffer(iBuffer);
      //   }

      //}


      void in::in_reset()
      {

         synchronous_lock lock(synchronization());

         m_bResetting = true;

         //if(m_ppcm == NULL)
         //{

         //   throw ::exception(error_failed);

         //}

         ::e_status mmr;

         if(m_einstate == ::wave::e_in_state_recording)
         {

            /*if(result_success != (mmr = wave_in_stop()))
            {

               information("in::Reset error stopping input device");

               return mmr;

            }*/

         }

         //try
         //{

         //   if(result_success != (mmr = translate_alsa(snd_pcm_drop(m_ppcm))))
         //   {

         //      information("in::Reset error resetting input device");
         //      //return mmr;

         //      throw ::exception(::error_failed);

         //   }

         //}
         //catch(...)
         //{
         //}

         m_einstate = ::wave::e_in_state_opened;

         m_bResetting = false;

         //return result_success;

      }


/*

      ::e_status in::wave_in_add_buffer(int32_t iBuffer)
      {

         return wave_in_add_buffer(wave_hdr(iBuffer));

      }


      ::e_status in::wave_in_add_buffer(LPWAVEHDR lpwavehdr)
      {

         ::e_status mmr;

         /*if(result_success != (mmr = waveInAddBuffer(m_hwavein, lpwavehdr, sizeof(WAVEHDR))))
         {

            information("ERROR OPENING Adding INPUT DEVICE buffer");

         }*/

/*         m_iBuffer++;

         return mmr;

      }
*/

      bool in::wave_in_initialize_encoder()
      {

         if (m_pencoder == NULL)
         {

            //return false;
            throw ::exception(::error_failed);

         }

         //if (!::multimedia::audio::in::wave_in_initialize_encoder())
         //{

         //   //return false;
         //   throw ::exception(::error_failed);

         //}

         return true;

      }

/*      WAVEFORMATEX * in::wave_format()
      {

         translate(m_waveformatex, m_pwaveformat);

         return &m_waveformatex;

      }
*/
      //snd_pcm_t * in::wave_in_get_safe_PCM()
      //{

      //   if (this == NULL)
      //   {

      //      //return NULL;

      //      throw ::exception(::error_failed);

      //   }

      //   //return m_ppcm;

      //}


      void * in::get_os_data()
      {
         
         //return m_ppcm;

         return nullptr;

      }

/*      LPWAVEHDR in::wave_hdr(int iBuffer)
      {
         return ::multimedia::audio_opensles::get_os_data(wave_in_get_buffer(), iBuffer);
      }*/


   } // namespace audio_opensles


} // namespace multimedia






