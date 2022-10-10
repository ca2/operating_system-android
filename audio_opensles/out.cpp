#include "framework.h"
#include "out.h"


void bqPlayerCallback(SLAndroidSimpleBufferQueueItf bq, void *context);


namespace multimedia
{


   namespace audio_opensles
   {


      out::out()
      {

         m_eoutstate             = ::wave::e_out_state_initial;
         m_pthreadCallback    = NULL;
         m_iBufferedCount     = 0;
         //m_mmr                = result_success;
         //m_peffect            = NULL;
         m_bWrite             = false;


         // output mix interfaces
         outputMixObject = NULL;

         // buffer queue player interfaces
         bqPlayerObject = NULL;
         bqPlayerPlay = NULL;
         bqPlayerVolume = NULL;
         bqPlayerBufferQueue = NULL;
         bqPlayerEffectSend = NULL;


      }


      out::~out()
      {


      }


      void out::install_message_routing(::channel * pchannel)
      {

         ::wave::out::install_message_routing(pchannel);

         //IGUI_WIN_MSG_LINK(e_message_ready, pchannel, this, &out::OnReady);
         //IGUI_WIN_MSG_LINK(e_message_free, pchannel, this, &out::OnFree);

      }



      /*bool out::init_task()
      {

         if (!::wave::out::initialize_task())
         {

            return false;

         }

         return true;

      }

      *///int32_t out::exit_thread()
      //{

      //   ::multimedia::audio::out::exit_thread();

      //   return thread::exit_thread();

      //}

      //void out::out_open(::thread* pthreadCallback, u32 uiSamplesPerSec, u32 uiChannelCount, u32 uiBitsPerSample, ::wave::enum_purpose epurpose)
      //{
      //   single_lock sLock(m_mutex, true);
      //   if(engineObject != NULL &&
      //      m_eoutstate != ::wave::e_out_state_initial)
      //      return result_success;
      //   m_pthreadCallback = pthreadCallback;
      //   ::e_status mmr;
      //   ASSERT(engineObject == NULL);
      //   ASSERT(m_eoutstate == ::wave::e_out_state_initial);

      //   //m_pwaveformat->wFormatTag = WAVE_FORMAT_PCM;
      //   m_pwaveformat->wFormatTag = 0;
      //   m_pwaveformat->nChannels = 2;
      //   m_pwaveformat->nSamplesPerSec = 44100;
      //   m_pwaveformat->wBitsPerSample = sizeof(multimedia::audio::WAVEBUFFERDATA) * 8;
      //   m_pwaveformat->nBlockAlign = m_pwaveformat->wBitsPerSample * m_pwaveformat->nChannels / 8;
      //   m_pwaveformat->nAvgBytesPerSec = m_pwaveformat->nSamplesPerSec * m_pwaveformat->nBlockAlign;
      //   m_pwaveformat->cbSize = 0;

      //   //if((m_mmr = this->snd_pcm_open(SND_PCM_STREAM_PLAYBACK)) != result_success)
      //   //{

      //   //   return result_error;

      //   //}



      //   //uint32_t uiBufferSizeLog2;
      //   //uint32_t uiBufferSize;
      //   //uint32_t uiAnalysisSize;
      //   //uint32_t uiAllocationSize;
      //   //uint32_t uiInterestSize;
      //   //uint32_t uiSkippedSamplesCount;
      //   //uint32_t uiBufferCount = iBufferCount;

      //   //if(m_pwaveformat->nSamplesPerSec == 44100)
      //   //{
      //   //   uiBufferSizeLog2 = 16;
      //   //   uiBufferSize = m_pwaveformat->nChannels * 2 * iBufferSampleCount; // 512 kbytes
      //   //   uiAnalysisSize = 4 * 1 << uiBufferSizeLog2;
      //   //   if(iBufferCount > 0)
      //   //   {
      //   //      uiAllocationSize = iBufferCount * uiAnalysisSize;
      //   //   }
      //   //   else
      //   //   {
      //   //      uiAllocationSize = 8 * uiAnalysisSize;
      //   //   }
      //   //   uiInterestSize = 200;
      //   //   uiSkippedSamplesCount = 2;
      //   //}
      //   //else if(m_pwaveformat->nSamplesPerSec == 22050)
      //   //{
      //   //   uiBufferSizeLog2 = 10;
      //   //   uiBufferSize = 4 * 1 << uiBufferSizeLog2;
      //   //   uiAnalysisSize = 4 * 1 << uiBufferSizeLog2;
      //   //   uiAllocationSize = 4 * uiAnalysisSize;
      //   //   uiInterestSize = 200;
      //   //   uiSkippedSamplesCount = 1;
      //   //}
      //   //else if(m_pwaveformat->nSamplesPerSec == 11025)
      //   //{
      //   //   uiBufferSizeLog2 = 10;
      //   //   uiBufferSize = 2 * 1 << uiBufferSizeLog2;
      //   //   uiAnalysisSize = 2 * 1 << uiBufferSizeLog2;
      //   //   uiAllocationSize = 4 * uiAnalysisSize;
      //   //   uiInterestSize = 200;
      //   //   uiSkippedSamplesCount = 1;
      //   //}

      //   ////uiBufferCount = 1;

      //   //wave_out_get_buffer()->PCMOutOpen(this, uiBufferSize, uiBufferCount, 128, m_pwaveformat, m_pwaveformat);

      //   //m_pprebuffer->open(this, m_pwaveformat->nChannels, uiBufferCount, iBufferSampleCount); // group sample count

      //   //int iFrameSize = (m_pwaveformat->nChannels * m_pwaveformat->wBitsPerSample) / 8;

      //   //int err;

      //   //snd_pcm_sw_params_alloca(&m_pswparams);

      //   ///* get the current m_pswparams */
      //   //err = snd_pcm_sw_params_current(m_ppcm, m_pswparams);

      //   //if (err < 0)
      //   //{

      //   //   TRACE("Unable to determine current m_pswparams for playback: %s\n", snd_strerror(err));

      //   //   return result_error;

      //   //}


      //   ///* start the transfer when the buffer is almost full: */
      //   ///* (buffer_size / avail_min) * avail_min */
      //   //err = snd_pcm_sw_params_set_start_threshold(m_ppcm, m_pswparams, (buffer_size / period_size) * period_size);
      //   //if (err < 0)
      //   //{

      //   //   TRACE("Unable to set start threshold mode for playback: %s\n", snd_strerror(err));

      //   //   return result_error;

      //   //}

      //   ///* allow the transfer when at least period_size samples can be processed */
      //   //err = snd_pcm_sw_params_set_avail_min(m_ppcm, m_pswparams, period_size);
      //   //if (err < 0)
      //   //{

      //   //   TRACE("Unable to set avail minimum for playback: %s\n", snd_strerror(err));

      //   //   return result_error;

      //   //}

      //   ///* write the parameters to the playback device */
      //   //err = snd_pcm_sw_params(m_ppcm, m_pswparams);
      //   //if (err < 0)
      //   //{

      //   //   TRACE("Unable to set sw params for playback: %s\n", snd_strerror(err));

      //   //   return result_error;

      //   //}

      //   m_eoutstate = ::wave::e_out_state_opened;
      // //  return result_success;
      //}


      void out::out_open_ex(::thread* pthreadCallback, u32 uiSamplesPerSec, u32 uiChannelCount, u32 uiBitsPerSample, ::wave::enum_purpose epurpose)
      {

         synchronous_lock sLock(mutex());

         if (engineObject != NULL && m_eoutstate != ::wave::e_out_state_initial)
         {

            //return result_success;

            return;

         }

         m_pthreadCallback = pthreadCallback;

         int iBufferCount = 4;
         int period_size = 2048;
         ASSERT(engineObject == NULL);

         ASSERT(m_eoutstate == ::wave::e_out_state_initial);

         m_pwaveformat->m_waveformat.wFormatTag        = 0;
         m_pwaveformat->m_waveformat.nChannels         = uiChannelCount;
         m_pwaveformat->m_waveformat.nSamplesPerSec    = uiSamplesPerSec;
         m_pwaveformat->m_waveformat.wBitsPerSample    = uiBitsPerSample;
         m_pwaveformat->m_waveformat.nBlockAlign       = m_pwaveformat->m_waveformat.wBitsPerSample * m_pwaveformat->m_waveformat.nChannels / 8;
         m_pwaveformat->m_waveformat.nAvgBytesPerSec   = m_pwaveformat->m_waveformat.nSamplesPerSec * m_pwaveformat->m_waveformat.nBlockAlign;
         //m_pwaveformat->m_waveformat.cbSize            = 0;
         int iBufferSampleCount = 0;


         SLresult result;
         SLuint32 sr = uiSamplesPerSec;
         SLuint32  channels = uiChannelCount;
         uint32_t uiBufferSizeLog2;
         uint32_t uiBufferSize;
         uint32_t uiAnalysisSize;
         uint32_t uiAllocationSize;
         uint32_t uiInterestSize;
         uint32_t uiSkippedSamplesCount;
         int err;
         if (create() != SL_RESULT_SUCCESS)
         {
            throw ::exception(::error_failed);

         }

            // configure audio source
            SLDataLocator_AndroidSimpleBufferQueue loc_bufq =
            {
               SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE,
               (SLuint32) iBufferCount
            };
            m_iBufferCount = iBufferCount;
            switch (sr) {

            case 8000:
               sr = SL_SAMPLINGRATE_8;
               break;
            case 11025:
               sr = SL_SAMPLINGRATE_11_025;
               break;
            case 16000:
               sr = SL_SAMPLINGRATE_16;
               break;
            case 22050:
               sr = SL_SAMPLINGRATE_22_05;
               break;
            case 24000:
               sr = SL_SAMPLINGRATE_24;
               break;
            case 32000:
               sr = SL_SAMPLINGRATE_32;
               break;
            case 44100:
               sr = SL_SAMPLINGRATE_44_1;
               break;
            case 48000:
               sr = SL_SAMPLINGRATE_48;
               break;
            case 64000:
               sr = SL_SAMPLINGRATE_64;
               break;
            case 88200:
               sr = SL_SAMPLINGRATE_88_2;
               break;
            case 96000:
               sr = SL_SAMPLINGRATE_96;
               break;
            case 192000:
               sr = SL_SAMPLINGRATE_192;
               break;
            default:
               throw ::exception(::error_failed);
            }

            {

               //const SLInterfaceID ids[] = { SL_IID_VOLUME };
               //const SLboolean req[] = { SL_BOOLEAN_FALSE };
               //result = (*engineEngine)->CreateOutputMix(engineEngine, &(outputMixObject), 1, ids, req);
               result = (*engineEngine)->CreateOutputMix(engineEngine, &(outputMixObject), 0, NULL, NULL);
               output_debug_string("engineEngine="+ __string((uptr)engineEngine));
               ASSERT(!result);
               if (result != SL_RESULT_SUCCESS) goto end_openaudio;

               // realize the output mix
               result = (*outputMixObject)->Realize(outputMixObject, SL_BOOLEAN_FALSE);
               output_debug_string("Realize" + __string((uptr)result));
               if (result != SL_RESULT_SUCCESS) goto end_openaudio;

               int speakers;
               if (channels > 1)
                  speakers = SL_SPEAKER_FRONT_LEFT | SL_SPEAKER_FRONT_RIGHT;
               else speakers = SL_SPEAKER_FRONT_CENTER;
               SLDataFormat_PCM format_pcm = { SL_DATAFORMAT_PCM,channels, sr,
                  SL_PCMSAMPLEFORMAT_FIXED_16, SL_PCMSAMPLEFORMAT_FIXED_16,
                  (SLuint32) speakers, SL_BYTEORDER_LITTLEENDIAN };

               SLDataSource audioSrc = { &loc_bufq, &format_pcm };

               // configure audio sink
               SLDataLocator_OutputMix loc_outmix = { SL_DATALOCATOR_OUTPUTMIX, outputMixObject };
               SLDataSink audioSnk = { &loc_outmix, NULL };

               // create audio player
               const SLInterfaceID ids1[] = { SL_IID_ANDROIDSIMPLEBUFFERQUEUE, SL_IID_VOLUME };
               const SLboolean req1[] = { SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE };
               result = (*engineEngine)->CreateAudioPlayer(engineEngine,
                  &(bqPlayerObject), &audioSrc, &audioSnk, 2, ids1, req1);
               output_debug_string("bqPlayerObject="+__string((uptr)bqPlayerObject));
               //ASSERT(!result);
               if (result != SL_RESULT_SUCCESS) goto end_openaudio;

               // realize the player
               result = (*bqPlayerObject)->Realize(bqPlayerObject, SL_BOOLEAN_FALSE);
               output_debug_string("Realize="+__string((uptr)result));
               //ASSERT(!result);
               if (result != SL_RESULT_SUCCESS) goto end_openaudio;

               // get the play interface
               result = (*bqPlayerObject)->GetInterface(bqPlayerObject, SL_IID_PLAY, &(bqPlayerPlay));
               output_debug_string("bqPlayerPlay=" + __string((uptr) bqPlayerPlay));
               //ASSERT(!result);
               if (result != SL_RESULT_SUCCESS) goto end_openaudio;

               // get the volume interface
               result = (*bqPlayerObject)->GetInterface(bqPlayerObject, SL_IID_VOLUME, &(bqPlayerVolume));
               output_debug_string("bqPlayerVolume=" + __string((uptr) bqPlayerVolume));
               //ASSERT(!result);
               if (result != SL_RESULT_SUCCESS) goto end_openaudio;

               // get the buffer queue interface
               result = (*bqPlayerObject)->GetInterface(bqPlayerObject, SL_IID_ANDROIDSIMPLEBUFFERQUEUE,
                  &(bqPlayerBufferQueue));
               ::output_debug_string("bqPlayerBufferQueue=" + __string((uptr) bqPlayerBufferQueue));
               //ASSERT(!result);
               if (result != SL_RESULT_SUCCESS) goto end_openaudio;

               // register callback on the buffer queue
               result = (*bqPlayerBufferQueue)->RegisterCallback(bqPlayerBufferQueue, bqPlayerCallback, this);
               output_debug_string("bqPlayerCallback=" + __string((uptr)bqPlayerCallback));
               //ASSERT(!result);
               if (result != SL_RESULT_SUCCESS) goto end_openaudio;


            }

         if(true)
         {
            uiBufferSizeLog2 = 16;
            //uiBufferSize = m_pwaveformat->nChannels * 2 * iBufferSampleCount; // 512 kbytes
            /*while(((double)(buffer_size * 8) / (double)(uiBitsPerSample * uiSamplesPerSec)) > 0.084)
            {
                buffer_size /= 2;
            }*/
            uiBufferSize = period_size;
            
            iBufferSampleCount = period_size / (m_pwaveformat->m_waveformat.nChannels * 2);

            uiAnalysisSize = 4 * 1 << uiBufferSizeLog2;

            if(iBufferCount > 0)
            {

               uiAllocationSize = iBufferCount * uiAnalysisSize;

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
            uiBufferSizeLog2 = 10;
            uiBufferSize = 4 * 1 << uiBufferSizeLog2;
            uiAnalysisSize = 4 * 1 << uiBufferSizeLog2;
            uiAllocationSize = 4 * uiAnalysisSize;
            uiInterestSize = 200;
            uiSkippedSamplesCount = 1;
         }
         else if(m_pwaveformat->m_waveformat.nSamplesPerSec == 11025)
         {
            uiBufferSizeLog2 = 10;
            uiBufferSize = 2 * 1 << uiBufferSizeLog2;
            uiAnalysisSize = 2 * 1 << uiBufferSizeLog2;
            uiAllocationSize = 4 * uiAnalysisSize;
            uiInterestSize = 200;
            uiSkippedSamplesCount = 1;
         }

         out_get_buffer()->PCMOutOpen(this, uiBufferSize, iBufferCount, 128, m_pwaveformat, m_pwaveformat);

         m_pprebuffer->open(m_pwaveformat->m_waveformat.nChannels, iBufferCount, iBufferSampleCount);

         //m_pprebuffer->SetMinL1BufferCount(wave_out_get_buffer()->GetBufferCount());

         
         m_eoutstate = ::wave::e_out_state_opened;

         m_epurpose = epurpose;
      
      end_openaudio:

         if (result == SL_RESULT_SUCCESS)
         {
            
            output_debug_string("out::wave_out_open_ex success");
            //return ::success;

            m_estatus = ::success;

         }
         else
         {

            output_debug_string("out::wave_out_open_ex error");
            
            m_estatus = ::error_failed;
            
            throw ::exception(error_failed);

         }

      }



      void out::out_close()
      {

         synchronous_lock sLock(mutex());

         if(m_eoutstate == ::wave::e_out_state_playing)
         {
            
            //wave_out_stop();

         }

         if (m_eoutstate != ::wave::e_out_state_opened)
         {
            //return result_success;

            return;

         }

         ::e_status mmr;


         // destroy buffer queue audio player object, and invalidate all associated interfaces
         if (bqPlayerObject != NULL) {
            (*bqPlayerObject)->Destroy(bqPlayerObject);
            bqPlayerObject = NULL;
            bqPlayerVolume = NULL;
            bqPlayerPlay = NULL;
            bqPlayerBufferQueue = NULL;
            bqPlayerEffectSend = NULL;
         }

         // destroy output mix object, and invalidate all associated interfaces
         if (outputMixObject != NULL) {
            (*outputMixObject)->Destroy(outputMixObject);
            outputMixObject = NULL;
         }


         destroy();

         //::multimedia::audio::out::wave_out_close();

         m_eoutstate = ::wave::e_out_state_initial;

         //return result_success;

      }



      void out::out_stop()
      {

         //single_lock sLock(m_mutex, true);

         synchronous_lock sLock(mutex());

         if (m_eoutstate != ::wave::e_out_state_playing && m_eoutstate != ::wave::e_out_state_paused)
         {

            //return result_error;

            throw ::exception(::error_failed);

         }

         //m_eventStopped.ResetEvent();

         ///m_pprebuffer->stop();

         m_eoutstate = ::wave::e_out_state_stopping;

         // waveOutReset
         // The waveOutReset function stops playback on the given
         // waveform-audio_opensles output device and resets the current position
         // to zero. All pending playback buffers are marked as done and
         // returned to the application.
         //m_mmr = translate_alsa(snd_pcm_drain(m_ppcm));


         //if(m_mmr == result_success)
         //{

            m_eoutstate = ::wave::e_out_state_opened;

//         }

         //return m_mmr;

      }


      void out::out_pause()
      {

         synchronous_lock sLock(mutex());

         ASSERT(m_eoutstate == ::wave::e_out_state_playing);

         if (m_eoutstate != ::wave::e_out_state_playing)
         {

            throw ::exception(error_failed);

         }

         // waveOutReset
         // The waveOutReset function stops playback on the given
         // waveform-audio_opensles output device and resets the current position
         // to zero. All pending playback buffers are marked as done and
         // returned to the application.
         //m_mmr = translate_alsa(snd_pcm_pause(m_ppcm, 1));

         //ASSERT(m_mmr == result_success);

         //if(m_mmr == result_success)
         //{
         //   
         //   m_eoutstate = ::wave::e_out_state_paused;

         //}

         //return m_mmr;

      }

      
      void out::out_restart()
      {

         synchronous_lock sLock(mutex());

         ASSERT(m_eoutstate == ::wave::e_out_state_paused);

         if (m_eoutstate != ::wave::e_out_state_paused)
         {
          
            throw ::exception(error_failed);
            //return result_error;

         }

         // waveOutReset
         // The waveOutReset function stops playback on the given
         // waveform-audio_opensles output device and resets the current position
         // to zero. All pending playback buffers are marked as done and
         // returned to the application.
         //m_mmr = translate_alsa(snd_pcm_pause(m_ppcm, 0));

         //ASSERT(m_mmr == result_success);

         //if(m_mmr == result_success)
         //{
         //   m_eoutstate = ::wave::e_out_state_playing;
         //}

         //return m_mmr;

      }


      //imedia_time out::wave_out_get_position_millis()
      ::duration out::out_get_position()
      {

         //single_lock sLock(m_mutex, true);

         synchronous_lock lock(mutex());

         //if(m_ppcm != NULL)
         //{

         //   snd_pcm_sframes_t frames = snd_pcm_avail_update(m_ppcm);

         //   return frames * 1000 / m_pwaveformat->nSamplesPerSec;

         //}
         //else
         //{

         //   return 0;

         //}

         //return 0;

         SLmillisecond nPositionMs;
         SLresult result = (*bqPlayerPlay)->GetPosition(bqPlayerPlay,
            &nPositionMs);


         return INTEGRAL_MILLISECOND{ nPositionMs };

      }


      //imedia_position out::wave_out_get_position()
      //{

      //   single_lock sLock(m_mutex, true);

      //   //if(m_ppcm != NULL)
      //   //{

      //   //   snd_pcm_sframes_t frames = snd_pcm_avail_update(m_ppcm);

      //   //   return frames;

      //   //}
      //   //else
      //   {

      //      return 0;

      //   }

      //}


      void out::out_on_playback_end()
      {

         ::wave::out::out_on_playback_end();

         //wave_out_stop();

         //if(m_pprebuffer->m_pstreameffectOut != NULL)
         //{
           // ::multimedia::iaudio::wave_stream_effect * peffect = m_pprebuffer->m_pstreameffectOut;
            //m_pprebuffer->m_pstreameffectOut = NULL;
            //delete peffect;
         //}

         //m_eventStopped.SetEvent();

         //m_pplayer->OnEvent(::multimedia::wave::player::EventPlaybackEnd);

      }



      //snd_pcm_t * out::wave_out_get_safe_PCM()
      //{

      //   if(this == NULL)
      //      return NULL;

      //   return m_ppcm;

      //}

      void * out::get_os_data()
      {

         //return m_ppcm;
         return NULL;

      }


      void out::out_free(int iBuffer)
      {

         //post_message(message_free, ibuffer);

         ::wave::out::out_free(iBuffer);

      }


      void out::out_filled(int iBuffer)
      {

//         post_message(message_ready, iBuffer);

         //int iBuffer = pmessage->m_wparam;

         opensles_out_filled(iBuffer);


      }



      void out::OnReady(::message::message * pmessage)
      {

         //::pointer<::message::user>pusermessage(pmessage);

         int iBuffer = pmessage->m_wparam;

         opensles_out_filled(iBuffer);

      }


      void out::OnFree(::message::message * pmessage)
      {

         //::pointer<::user::message>pusermessage(pobj);

         int iBuffer = pmessage->m_wparam;

         opensles_out_free(iBuffer);

      }


      void out::opensles_out_filled(int iBuffer)
      {

         synchronous_lock sLock(mutex());

         if(m_eoutstate != ::wave::e_out_state_playing
         && m_eoutstate != ::wave::e_out_state_stopping)
         {

            goto destroy;

         }

         //if(m_peffect != NULL)
         //{

         //   m_peffect->Process16bits((int16_t *) wave_out_get_buffer_data(iBuffer), wave_out_get_buffer_size());

         //}

         (*bqPlayerBufferQueue)->Enqueue(bqPlayerBufferQueue, out_get_buffer_data(iBuffer), out_get_buffer_size());

         //output_debug_string("buffer_size"+__string((uint_ptr) wave_out_get_buffer_size()));

         destroy:

         sLock.unlock();

      }


      void out::out_start(const ::duration & position)
      {

         synchronous_lock sLock(mutex());

         if (m_eoutstate == ::wave::e_out_state_playing)
         {

          //  return result_success;

            return;

         }

         if (m_eoutstate != ::wave::e_out_state_opened && m_eoutstate != ::wave::e_out_state_stopped)
         {

            //return result_error;

            throw ::exception(::error_wrong_state);

         }

         int err = 0;

         output_debug_string("out::wave_out_start");

         //if ((err = snd_pcm_prepare (m_ppcm)) < 0)
         //{

         //   TRACE ("cannot prepare audio interface for use (%s)\n",snd_strerror (err));

         //   return result_error;

         //}

         m_iPlayBuffer = 0;

         m_iBufferedCount = 0;

         //m_evBufferFull.ResetEvent();

         ::wave::out::out_start(position);

         //if (failed(m_mmr))
         //{
         //   return m_mmr;

         //}

         // set the player's state to playing
         SLresult result = (*bqPlayerPlay)->SetPlayState(bqPlayerPlay, SL_PLAYSTATE_PLAYING);
         //DEBUG_SND("SetPlayState=%d", result);
         //ASSERT(!result);

         if (result != SL_RESULT_SUCCESS)
         {

            throw ::exception(::error_failed);

         }

         //return result_success;

      }


      bool out::on_run_step()
      {

//         return ::multimedia::audio::out::on_run_step();
         return false;

      }


      int out::underrun_recovery(int err)
      {

         //if(verbose)
           //printf("stream recovery\n");

         if(m_pprebuffer->is_eof() || out_get_state() == ::wave::e_out_state_stopping)
         {

            return 0;

         }
         else if (err == -EPIPE)
         {

            //// under-run
            //err = snd_pcm_prepare(m_ppcm);

            //if (err < 0)
            //{

            //   TRACE("Can't recovery from underrun, prepare failed: %s\n", snd_strerror(err));

            //}
            //else if (err == -ESTRPIPE)
            //{

            //   while ((err = snd_pcm_resume(m_ppcm)) == -EAGAIN)
            //   {

            //      sleep(1); /* wait until the suspend flag is released */

            //   }

            //   if (err < 0)
            //   {

            //      err = snd_pcm_prepare(m_ppcm);

            //      if (err < 0)
            //      {

            //         TRACE("Can't recovery from suspend, prepare failed: %s\n", snd_strerror(err));

            //      }

            //   }

            //}

            //return 0;

         }

         return err;

      }


      void out::opensles_out_free(int iBuffer)
      {

         ::wave::out::out_free(iBuffer);

      }


   } // namespace audio_opensles


} // namespace multimedia



// this callback handler is called every time a buffer finishes playing
void bqPlayerCallback(SLAndroidSimpleBufferQueueItf bq, void *context)
{
   
   multimedia::audio_opensles::out *p = (multimedia::audio_opensles::out *)context;

   SLAndroidSimpleBufferQueueState s{};

   (*bq)->GetState(bq, &s);

   //output_debug_string("buffer_index" + __string(s.index % p->m_iBufferCount));

   p->out_free(s.index % p->m_iBufferCount);


   
}
