#include "framework.h"
#include "android_asset_manager.h"
#include "jni_message_sink.h"
#include "acme/constant/id.h"
#include "acme/parallelization/manual_reset_happening.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/system.h"
#include "_internal.h"


namespace android
{

    namespace acme
    {


        int ::user::e_message_box_to_button(const ::user::e_message_box &emessagebox);


        //::pointer<::acme::driver> g_pandroiddriver;


        application_state::application_state()
        {


           m_passetmanager = nullptr;

           //m_bLastShowSoftwareKeyboard = false;

        }


        application_state::~application_state()
        {

           if (::is_set(m_passetmanager)) {

              delete m_passetmanager;

           }

        }


       void application_state::on_initialize_particle()
       {

          defer_create_synchronization();

       }




        void application_state::exchange1()
        {

           {

              synchronous_lock synchronouslock(synchronization());

              auto pbind = ::jni_bind::get();


//              string strOpenUrl;
//
//              {
//
//                 //synchronous_lock lock(synchronization());
//
//                 while (m_straOpenUrl.has_element()) {
//
//                    strOpenUrl = m_straOpenUrl.pick_first();
//
//                    if (strOpenUrl.has_character()) {
//
//                       break;
//
//                    }
//
//                 }
//
//              }
//
//              if (strOpenUrl.has_character()) {
//
//                 pbind->setOpenUrl(strOpenUrl);
//
//              }

//              if(m_iDocumentFolderRequestSent < m_iDocumentFolderRequest)
//              {
//
//                 m_iDocumentFolderRequestSent = m_iDocumentFolderRequest;
//
//                 pbind->setDocumentFolderRequest(m_iDocumentFolderRequestSent);
//
//              }

              //if (m_bMessageBoxOn)
              //{

              //   int iResult = pbind->getMessageBoxResult();

              //   if (iResult > 0)
              //   {

              //      m_bMessageBoxOn = false;

              //   }

              //}
              //else
              //{

              auto pmessagebox = pick_message_box();

              if (::is_set(pmessagebox)) {

                 pmessagebox->increment_reference_count();

                 pbind->setMessageBoxSequence((::iptr) pmessagebox.m_p);

                 pbind->setMessageBox(pmessagebox->m_strMessage);

                 pbind->setMessageBoxCaption(pmessagebox->m_strTitle);

                 pbind->setMessageBoxButton(
                         ::user::e_message_box_to_button(pmessagebox->m_emessagebox));

              }

              defer_post_all_media_store_operations();


//
//       {
//
//          synchronous_lock sl(m_pparticleMutexListFileEnumerate);
//
//          if (m_straListFileEnumerate.has_element()) {
//
//             auto pbind = ::jni_bind::get();
//
//             auto bLock = pbind->getLockListFileEnumerate();
//
//             if (!bLock) {
//
//                string strEnumerate = m_straListFileEnumerate.pick_first();
//
//                pbind->setListFileEnumerate(strEnumerate);
//
//                pbind->setLockListFileEnumerate(true);
//
//             }
//
//          }

           }


        }


//        ::file::path application_state::synchronously_getDocumentFolder(
//           const class ::time & timeOut)
//        {
//
//           m_iDocumentFolderRequest++;
//
//           int iDocumentFolderRequest = m_iDocumentFolderRequest;
//
//           bool bRequestSentThisCall = false;
//
//           class ::time timeAroundLastSentRequest;
//
//           int iTry = 0;
//
//           while(true)
//           {
//
//              if(m_iDocumentFolderResponse >= iDocumentFolderRequest)
//              {
//
//                 return m_pathDocumentFolder;
//
//              }
//
//              if(iTry < 3 && (!bRequestSentThisCall || timeAroundLastSentRequest.elapsed() > 20_s))
//              {
//
//                 m_iDocumentFolderRequest++;
//
//                 iDocumentFolderRequest = m_iDocumentFolderRequest;
//
//                 timeAroundLastSentRequest.Now();
//
//                 iTry++;
//
//              }
//
//              preempt(200_ms);
//
//              if(timeOut.elapsed() > timeOut)
//              {
//
//                 break;
//
//              }
//
//           }
//
//           return {};
//
//        }

        void application_state::after_exchange()
        {

//           {
//
//              auto pbind = ::jni_bind::get();
//
//              string strUri = pbind->getUri();
//
//              if (strUri.has_character()) {
//
//                 pbind->setUri("");
//
//                 system()->handle_uri(strUri);
//
//              }
//
////              if (m_iDocumentFolderResponse < m_iDocumentFolderRequestSent) {
////
////                 m_iDocumentFolderResponse = pbind->getDocumentFolderResponse();
////
////                 if (m_iDocumentFolderResponse == m_iDocumentFolderRequestSent)
////                 {
////
////                    m_pathDocumentFolder = pbind->getDocumentFolder();
////
////                 }
////
////              }
//
//           }

        }


//    void driver::list_file_enumerate(const ::scoped_string & scopedstrListFileEnumerate)
//    {
//
//       synchronous_lock lock(m_pparticleMutexListFileEnumerate);
//
//       m_straListFileEnumerate.add(strListFileEnumerate);
//
//    }


      void application_state::post_media_store_operation(::data::block * pdatablock)
      {

           ::platform::application_state::post_media_store_operation(pdatablock);

//         auto pbind = ::jni_bind::get();
//
////         auto pdatablock = øcreate_new<::data::block>();
////
////         pdatablock->m_bWrite = true;
////
////         pdatablock->m_strPath = scopedstrPath;
////
////         pdatablock->m_strMime = "text/plain";
////
////         pdatablock->m_memory = block;
//
////         manual_reset_happening happening;
////
////         pdatablock->m_procedureOnFinished=[&happening]()
////         {
////
////            happening.set_happening();
////
////         };
//
//         pbind->post_media_store_operation(pdatablock);
//
////         if(happening.wait(1_min).succeeded()) {
////
////pdatablock->m_estatus = success;
////
////         } else{
////
////            pdatablock->m_estatus = error_timeout;
////
////         }
//
//         //return pdatablock;

      }


//      ::pointer < ::data::block > application_state::media_store_get_data(const ::scoped_string & scopedstrPath)
//      {
//
//         auto pbind = ::jni_bind::get();
//
//         auto pdatablock = øcreate_new<::data::block>();
//
//         pdatablock->m_bWrite = false;
//
//         pdatablock->m_strPath = scopedstrPath;
//
//         pdatablock->m_strMime = "text/plain";
//
//         manual_reset_happening happening;
//
//         pdatablock->m_procedureOnFinished=[&happening]()
//         {
//
//            happening.set_happening();
//
//         };
//
//         pbind->media_store_schedule_data_block_operation(pdatablock);
//
//         if(happening.wait(1_min).succeeded()) {
//
//            pdatablock->m_estatus = success;
//
//         } else{
//
//            pdatablock->m_estatus = error_timeout;
//
//         }
//
//         return pdatablock;
//
//      }

      void application_state::on_main_task_iteration()
      {

           if(m_pjnimessagesink)
           {

              m_pjnimessagesink->dispatch_posted_messages();

           }

      }


    } // namespace acme



} // namespace android


