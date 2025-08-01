// created by Camilo 2021-01-31 05:26 BRT <3CamiloSasukeThomasBorregaardSoerensen
// from apex_windows by Camilo on 2022-05-24 18:42 <3TThomasBorregaardSoerensen
// From interprocess_communication.h by camilo on 2022-10-17 14:35 <3ThomasBorregaardSorensen!!
#pragma once


#include "interprocess_base.h"
#include "apex/interprocess/target.h"


namespace apex_android
{


   class CLASS_DECL_APEX interprocess_target :
      virtual public interprocess_base,
      virtual public interprocess::target
   {
   public:


      //__creatable_from_base(interprocess_handler, ::inteprocess::handler);


      interprocess_target();
      ~interprocess_target() override;


      void create(const ::scoped_string & scopedstrChannel) override;
      void destroy() override;


      //void * on_interprocess_receive(const ::scoped_string & scopedstrMessage) override;
      //void * on_interprocess_receive(int message, void * pdata, memsize len) override;
      //void * on_interprocess_post(long long a, long long b) override;


      virtual bool on_idle() override;


      //LRESULT message_queue_proc(UINT message, WPARAM wparam, LPARAM lparam);


      bool is_target_ok() override;


   };


} // namespace apex_android



