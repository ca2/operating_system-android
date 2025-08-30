//
// Created by camilo on 2025-08-30 02:41 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "application_state.h"
#include "jni_local.h"
#include "jni_object_impl.h"
#include "_internal.h"


namespace android
{

   namespace acme
   {

      void application_state::on_write_input_output_data_block(::data::block * pdatablock)
      {



            //}
            //
            //
            }

      void application_state::on_read_input_output_data_block(::data::block * pdatablock)
      {

         ASSERT(pdatablock->m_bWrite);
         //{

      }

   } // namespace acme


}// namespace android