#pragma once


#include "audio/audio/wave/base.h"


namespace multimedia
{


   namespace audio_aaudio
   {


      class CLASS_DECL_AUDIO_AAUDIO stream :
         virtual public ::wave::base {
      public:


         AAudioStream * m_pstream = NULL;
         int m_iCurrentBuffer;
         int m_iBufferCount;
         int m_frameCount;


         stream();

         virtual ~stream();



         void open_output_stream();
         void open_input_stream();

         void close_stream();


         virtual aaudio_data_callback_result_t output_audio_callback(float * data, int numFrames);

      };


   } // namespace audio_aaudio


} // namespace multimedia




