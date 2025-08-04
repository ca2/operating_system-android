#include "framework.h"
#include "acme/constant/id.h"
#include "_internal.h"
#include "acme/platform/node.h"


operating_system_bind * g_pandroidbind;


CLASS_DECL_WINDOWING_ANDROID void operating_system_log_exception(::particle * pparticle, ::exception& exception, const ::string& strMoreDetails)
{

   string strMessage;

   strMessage += "Failed to initialize application\n";
   strMessage += "\n";
   strMessage += exception.m_strMessage + "\n";
   strMessage += "(" + ::as_string(exception.m_estatus) + ")";

   string strTitle;

   strTitle = "Exception during initialization";

   string strDetails;

   strDetails += strMessage + "\n";
   strDetails += exception.m_strDetails + "\n\n";
   strDetails += "\n";
   strDetails += "PID: " + ::as_string(pparticle->node()->current_process_identifier()) + "\n";
   //strDetails += "Working Directory: " + string(GetCurrentDirectory()) + "\n\n";

   if (strMoreDetails.has_character())
   {

      strDetails += strMoreDetails + "\n";

   }

   if (exception.m_strCallStackTrace)
   {

      strDetails += "\n\n" + string(exception.m_strCallStackTrace);

   }

   auto pmessagebox = __allocate ::message_box(
           strMessage,
           strTitle,
           e_message_box_ok
               | e_message_box_icon_exclamation,
           strDetails);

   pmessagebox->initialize(pparticle);

   pmessagebox->sync();

   __android_log_write(ANDROID_LOG_WARN, "com.ca2", strDetails);

}


operating_system_bind* operating_system_bind::get()
{

   return g_pandroidbind;

}



void operating_system_bind::set(operating_system_bind* pdirect)
{

   g_pandroidbind = pdirect;

}



