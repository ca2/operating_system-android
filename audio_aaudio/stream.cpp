#include "framework.h"
#include "stream.h"


struct alloca_array
{
public:

   ::pointer_array < ::memory > m_memorya;


   void * allocate(memsize s)
   {

      auto pmemory = øallocate memory();

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


         auto buffer = (float *) audioData;

         aaudio_data_callback_result_t result = pstream->output_audio_callback(buffer, numFrames);
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
         AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_FLOAT);
         AAudioStreamBuilder_setChannelCount(builder, 1);
         AAudioStreamBuilder_setSampleRate(builder, (int32_t) pformat->m_waveformat.nSamplesPerSec);
         AAudioStreamBuilder_setDirection(builder, AAUDIO_DIRECTION_OUTPUT);
         AAudioStreamBuilder_setDataCallback(builder, audioCallback, this);
         AAudioStreamBuilder_setPerformanceMode(builder, AAUDIO_PERFORMANCE_MODE_LOW_LATENCY);

         // Open stream
         result = AAudioStreamBuilder_openStream(builder, &m_pstream);
         if (result != AAUDIO_OK) {
            printf("AAudioStreamBuilder_openStream() failed: %s\n", AAudio_convertResultToText(result));
            AAudioStreamBuilder_delete(builder);
            return;
         }

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

      aaudio_data_callback_result_t stream::output_audio_callback(float * data, int numFrames)
      {

         // this default implementation just generate silence



         for(int i = 0;i < numFrames; i++)
         {

            data[i] = 0.f;

         }

         return AAUDIO_CALLBACK_RESULT_CONTINUE;

      }



   } // namespace audio_aaudio


} // namespace multimedia



