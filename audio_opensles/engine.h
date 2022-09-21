#pragma once


#include "app-core/audio/wave/base.h"


namespace multimedia
{


   namespace audio_opensles
   {


      class CLASS_DECL_AUDIO_OPENSLES engine :
         virtual public ::wave::base
      {
      public:


         SLObjectItf engineObject;
         SLEngineItf engineEngine;

         
         engine();
         ~engine() override;

         
         // creates the OpenSL ES audio engine
         SLresult create();
         void destroy() override;


      };


   } // namespace audio_opensles


} // namespace multimedia




