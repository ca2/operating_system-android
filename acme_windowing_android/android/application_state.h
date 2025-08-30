#pragma once


//#include "acme/prototype/geometry2d/_geometry2d.h"
#include "acme/platform/application_state.h"


namespace android
{


    namespace acme
    {


        class asset_manager;


        class asset;


        class application_state :
            virtual public ::platform::application_state
        {
        public:


            ::particle_pointer m_pparticleMainOsThread;
            string m_strApplicationIdentifier;
            string m_strCommandLineParameters;
            ::file::path m_pathCacheDirectory;
            float m_fDpiX;
            float m_fDpiY;
            float m_fDensity;
            int m_iDocumentFolderRequest;
           int m_iDocumentFolderRequestSent = 0;
           int m_iDocumentFolderResponse;
            ::file::path m_pathDocumentFolder;

            //bool m_bShowKeyboard;
            //bool m_bHideKeyboard;
            //string_array_base m_straOpenUrl;

            //string m_strSetUserWallpaper;
            //string m_strGetUserWallpaper;
            //bool m_bGetUserWallpaper;

            //::iptr                   m_iptrMessageBoxSequence;
            // int                  m_iMessageBoxButton;
            //string                   m_strMessageBox;
            //string                   m_strMessageBoxCaption;
            //int                      m_iMessageBoxButton;
            //bool                     m_bMessageBox;
            //bool                     m_bMessageBoxOn;
            //bool                     m_iMessageBoxResult;
            //long long m_lMemFreeAvailableKb;


            //bool m_bEditFocusSet;
            //int_rectangle m_rectangleEditFocus;
            //bool m_bEditFocusKill;

            //bool m_bRedraw;

            //bool m_bEditorSelectionUpdated;
            //int m_iEditorSelectionStart;
            //int m_iEditorSelectionEnd;

            //bool m_bEditorTextUpdated;
            //string m_strEditorText;


            //bool m_bLastShowSoftwareKeyboard;


            //bool m_bInputMethodManagerUpdateSelection;
            //int m_iInputMethodManagerSelectionStart;
            //int m_iInputMethodManagerSelectionEnd;
            //int m_iInputMethodManagerCandidateStart;
            //int m_iInputMethodManagerCandidateEnd;

//        asset_manager *m_passetmanager;
//
//        ::pointer <asset> m_passetResourceFolder;


          void on_initialize_particle() override;

            ::particle_pointer m_pparticleMutexMessageBoxSequencer;
            ::pointer_array<::message_box> m_messageboxa;


            ::particle_pointer m_pparticleMutexListFileEnumerate;
            ::string_array_base m_straListFileEnumerate;


            application_state();

            ~application_state() override;

            // windowing::text_editor_interface
            //void set_input_method_manager_selection(character_count iSelBeg, character_count iSelEnd,
            //                                      character_count iCandidateBeg,
            //                                    character_count iCandidateEnd) override;

            //void set_input_method_manager_candidate_position(character_count iStart, character_count iEnd) override;
            //void synchronize_input_method_manager_with_selection_end() override;

            //void set_editor_selection(character_count iStart, character_count iEnd) override;

            //void set_editor_text(const ::scoped_string & scopedstrText) override;

            //void show_software_keyboard() override;

            //void hide_software_keyboard() override;


//        static operating_system_driver *get();
//
//        static void set(operating_system_driver *pdriver);


            //virtual void queue_message_box(::message_box *psequencer);

            //virtual ::pointer<::message_box> pick_message_box();


            //virtual void open_url(const ::scoped_string & scopedstrOpenUrl);

          void on_write_input_output_data_block(::data::block * pdatablock) override;
          void on_read_input_output_data_block(::data::block * pdatablock) override;

            void exchange1() override;
            void after_exchange() override;


            ::file::path synchronously_getDocumentFolder(const class ::time & timeOut) override;


          void post_media_store_operation(::data::block * pdatablock) override;


        };


    } // namespace acme



} // namespace android