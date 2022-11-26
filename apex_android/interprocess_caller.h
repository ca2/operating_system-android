// created by Camilo 2021-01-31 05:26 BRT <3CamiloSasukeThomasBorregaardSoerensen
// from apex_windows by Camilo on 2022-05-24 18:42 <3TThomasBorregaardSoerensen
// From interprocess_communication.h by camilo on 2022-10-17 14:35 <3ThomasBorregaardSorensen!!
#pragma once


#include "interprocess_base.h"
#include "apex/interprocess/caller.h"


namespace apex_android
{


   class CLASS_DECL_APEX interprocess_caller :
      virtual public interprocess_base,
      virtual public interprocess::caller
   {
   public:


      //__creatable_from_base(interprocess_caller, ::inteprocess::caller);


      interprocess_caller();
      ~interprocess_caller() override;


      void open(const ::string & strChannel, ::launcher * plauncher = nullptr) override;
      void close() override;


      void call(const ::string & strMessage, const class time & timeTimeout) override;
      //void send(int message, void * pdata, int len, const class time & timeTimeout) override;


      bool is_caller_ok() override;


   };


} // namespace apex_android



