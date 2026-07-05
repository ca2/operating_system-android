#include "framework.h"
#include "stream.h"


struct alloca_array
{
public:

   ::pointer_array < ::memory > m_memorya;


   void * allocate(memsize s)
   {

      auto pmemory = allocateø memory();

      m_memorya.add(pmemory);

      pmemory->set_size(s);

      auto p = pmemory->data();

      return p;


   }

};


namespace multimedia
{


   namespace audio_aaudio
   {


      stream::stream()
      {

         m_pstream = nullptr;
         //m_ppcm = NULL;
         //m_phwparams = NULL;
         //m_pswparams = NULL;
         //m_phandler = NULL;
         m_iCurrentBuffer = 0;
         //m_iPeriodMin = -1;
         //m_iPeriodMax = -1;
         //m_dwBufferTime    = 100 * 1000; /* ring buffer length in us */
         m_frameCount = -1;
      }

      stream::~stream()
      {

         close_stream();
      }

// Callback that fills the audio output buffer
      aaudio_data_callback_result_t audioCallback(
         AAudioStream *paaudiostream,
         void *userData,
         void *audioData,
         int32_t numFrames)
         {


         auto pstream = (stream *) userData;


         aaudio_data_callback_result_t result = pstream->output_audio_callback(audioData, numFrames);
//         for (int i = 0; i < numFrames; i++)
//         {
//
//            buffer[i] = (float) ;
//
//         }

return result;

         //return AAUDIO_CALLBACK_RESULT_CONTINUE;

      }

      void stream::open_input_stream()
      {


      }

      void stream::open_output_stream()

      {


         AAudioStreamBuilder *builder = NULL;



         // Generate a 440 Hz tone (A4)
         double frequency = 440.0;
         double sampleRate = 48000.0;

         // Create stream builder
         aaudio_result_t result = AAudio_createStreamBuilder(&builder);
         if (result != AAUDIO_OK) {
            printf("AAudio_createStreamBuilder() failed: %s\n", AAudio_convertResultToText(result));
            return;
         }


         ::pointer<::wave::format>pformat = m_pwaveformat;


         // Configure builder
         AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_I16);
         AAudioStreamBuilder_setChannelCount(builder, (int32_t) pformat->m_waveformat.nChannels);
         AAudioStreamBuilder_setSampleRate(builder, (int32_t) pformat->m_waveformat.nSamplesPerSec);
         AAudioStreamBuilder_setDirection(builder, AAUDIO_DIRECTION_OUTPUT);
         AAudioStreamBuilder_setDataCallback(builder, audioCallback, this);
         AAudioStreamBuilder_setUsage(builder, AAUDIO_USAGE_MEDIA);
         AAudioStreamBuilder_setContentType(builder, AAUDIO_CONTENT_TYPE_MUSIC);
         AAudioStreamBuilder_setSharingMode(builder, AAUDIO_SHARING_MODE_SHARED);
         AAudioStreamBuilder_setPerformanceMode(builder, AAUDIO_PERFORMANCE_MODE_NONE);

         int32_t iRequestedCallbackFrameCount = 0;

         if (m_frameCount > 0)
         {

            iRequestedCallbackFrameCount = (int32_t) m_frameCount;

            AAudioStreamBuilder_setFramesPerDataCallback(builder, iRequestedCallbackFrameCount);

         }

         int32_t iRequestedCapacityFrameCount = 0;

         if (m_frameCount > 0 && m_iBufferCount > 0)
         {

            iRequestedCapacityFrameCount = (int32_t) (m_frameCount * m_iBufferCount);

         }

         auto iSamplesPerSecond = (int32_t) pformat->m_waveformat.nSamplesPerSec;

         if (iSamplesPerSecond > 0)
         {

            auto iMinimumStableCapacityFrameCount = iSamplesPerSecond / 4;

            if (iRequestedCapacityFrameCount < iMinimumStableCapacityFrameCount)
            {

               iRequestedCapacityFrameCount = iMinimumStableCapacityFrameCount;

            }

         }

         int32_t iRequestedBufferSizeFrameCount = 0;

         if (m_frameCount > 0)
         {

            iRequestedBufferSizeFrameCount = (int32_t) (m_frameCount * 4);

         }

         if (iRequestedBufferSizeFrameCount <= 0 ||
             (iRequestedCapacityFrameCount > 0 && iRequestedBufferSizeFrameCount > iRequestedCapacityFrameCount))
         {

            iRequestedBufferSizeFrameCount = iRequestedCapacityFrameCount;

         }

         if (iRequestedCapacityFrameCount > 0)
         {

            AAudioStreamBuilder_setBufferCapacityInFrames(builder, iRequestedCapacityFrameCount);

         }

         // Open stream
         result = AAudioStreamBuilder_openStream(builder, &m_pstream);
         if (result != AAUDIO_OK) {
            printf("AAudioStreamBuilder_openStream() failed: %s\n", AAudio_convertResultToText(result));
            AAudioStreamBuilder_delete(builder);
            return;
         }

         auto iActualBufferSizeFrameCount = 0;

         if (iRequestedBufferSizeFrameCount > 0)
         {

            auto iSetBufferSizeResult = AAudioStream_setBufferSizeInFrames(m_pstream, iRequestedBufferSizeFrameCount);

            if (iSetBufferSizeResult >= 0)
            {

               iActualBufferSizeFrameCount = iSetBufferSizeResult;

            }
            else
            {

               warning() << "audio_aaudio AAudioStream_setBufferSizeInFrames failed result="
                         << AAudio_convertResultToText((aaudio_result_t) iSetBufferSizeResult);

            }

         }

         information() << "audio_aaudio stream config"
                       << " requestedCallbackFrames=" << iRequestedCallbackFrameCount
                       << " requestedCapacityFrames=" << iRequestedCapacityFrameCount
                       << " requestedBufferSizeFrames=" << iRequestedBufferSizeFrameCount
                       << " actualBufferSizeFrames=" << iActualBufferSizeFrameCount
                       << " capacityFrames=" << AAudioStream_getBufferCapacityInFrames(m_pstream)
                       << " framesPerBurst=" << AAudioStream_getFramesPerBurst(m_pstream)
                       << " framesPerCallback=" << AAudioStream_getFramesPerDataCallback(m_pstream)
                       << " format=" << AAudioStream_getFormat(m_pstream)
                       << " sampleRate=" << AAudioStream_getSampleRate(m_pstream)
                       << " channelCount=" << AAudioStream_getChannelCount(m_pstream);

         AAudioStreamBuilder_delete(builder);

      }


      void stream::close_stream()
      {

         if (m_pstream != nullptr)
         {

            AAudioStream_close(m_pstream);

            m_pstream = nullptr;

         }
      }


//      void stream::print_snd_pcm_status()
//      {
//
//         use_alloca();
//
//         {
//
//            snd_pcm_status_t *status;
//
//            snd_pcm_status_alloca (&status);
//            snd_pcm_status(m_ppcm, status);
//            int iState = snd_pcm_status_get_state(status);
//
//            if (iState == SND_PCM_STATE_RUNNING)
//            {
//
//               informationf("SND_PCM_STATE_RUNNING");
//
//            }
//            else if (iState == SND_PCM_STATE_XRUN)
//            {
//
//               informationf("SND_PCM_STATE_XRUN");
//
//            }
//            else if (iState == SND_PCM_STATE_DRAINING)
//            {
//
//               informationf("SND_PCM_STATE_DRAINING");
//
//            }
//            else if (iState == SND_PCM_STATE_PREPARED)
//            {
//
//               informationf("SND_PCM_STATE_PREPARED");
//
//            }
//            else if (iState == SND_PCM_STATE_SETUP)
//            {
//
//               informationf("SND_PCM_STATE_SETUP");
//
//            }
//            else if (iState == SND_PCM_STATE_OPEN)
//            {
//
//               informationf("SND_PCM_STATE_OPEN");
//
//            }
//
//            auto avail = snd_pcm_status_get_avail(status);
//
//            information() << "avail:" << avail;
//
//         }
//
//      }

      aaudio_data_callback_result_t stream::output_audio_callback(void * data, int numFrames)
      {

         // this default implementation just generate silence



         auto iChannelCount = maximum(1, (int) m_pwaveformat->m_waveformat.nChannels);
         auto pSampleData = (short *) data;

         for(int i = 0; i < numFrames * iChannelCount; i++)
         {

            pSampleData[i] = 0;

         }

         return AAUDIO_CALLBACK_RESULT_CONTINUE;

      }



   } // namespace audio_aaudio


} // namespace multimedia



