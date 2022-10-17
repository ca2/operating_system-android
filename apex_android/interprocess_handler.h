// created by Camilo 2021-01-31 05:26 BRT <3CamiloSasukeThomasBorregaardSoerensen
// from apex_windows by Camilo on 2022-05-24 18:42 <3TThomasBorregaardSoerensen
#pragma once


namespace apex_android
{


   class CLASS_DECL_APEX interprocess_communication_base :
      virtual public interprocess_handler::base
   {
   public:



      //__creatable_from_base(interprocess_communication_base, ::interprocess_handler::base);


      //HWND              m_hwnd;
      string            m_strBaseChannel;


      interprocess_communication_base();
      ~interprocess_communication_base() override;


      //HWND get_hwnd() const { return (HWND)m_hwnd; }
      //void set_hwnd(HWND hwnd) { m_hwnd = hwnd; }

   };


   class CLASS_DECL_APEX interprocess_caller :
      virtual public interprocess_communication_base,
      virtual public interprocess_handler::caller
   {
   public:


      //__creatable_from_base(interprocess_caller, ::inteprocess::caller);


      interprocess_caller();
      ~interprocess_caller() override;


      void open(const ::string & strChannel, ::launcher * plauncher = nullptr) override;
      void close() override;


      void send(const ::string & strMessage, const duration & durationTimeout) override;
      void send(int message, void * pdata, int len, const duration & durationTimeout) override;


      bool is_tx_ok() override;


   };


   class rx_private;


   class CLASS_DECL_APEX interprocess_handler :
      virtual public interprocess_communication_base,
      virtual public interprocess_handler::handler
   {
   public:


      //__creatable_from_base(interprocess_handler, ::inteprocess::handler);


      interprocess_handler();
      ~interprocess_handler() override;


      void create(const ::string & pszChannel) override;
      void destroy() override;


      //void * on_interprocess_receive(const ::string & pszMessage) override;
      //void * on_interprocess_receive(int message, void * pdata, memsize len) override;
      //void * on_interprocess_post(i64 a, i64 b) override;


      virtual bool on_idle() override;


      //LRESULT message_queue_proc(UINT message, WPARAM wparam, LPARAM lparam);


      bool is_rx_ok() override;


   };


   CLASS_DECL_APEX string app_install(string strPlatform = "");


} // namespace apex_android


