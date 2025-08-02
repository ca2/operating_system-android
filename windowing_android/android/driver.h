#pragma once


#include "acme_windowing_android/android/driver.h"
#include "aura/windowing/text_editor_interface.h"


class asset_manager;

class asset;

namespace android
{

    class driver :
virtual public ::android::acme::driver,
            virtual public ::windowing::text_editor_interface
    {
    public:


        ::particle_pointer m_pparticleMainOsThread;
//   string                     m_strApplicationIdentifier;
//   string                     m_strCommandLineParameters;
//   ::file::path               m_pathCacheDirectory;
//   int                        m_iWidth;
//   int                        m_iHeight;
//   float                      m_fDpiX;
//   float                      m_fDpiY;
        //float                      m_fDensity;
        bool m_bShowKeyboard;
        bool m_bHideKeyboard;
///   string_array               m_straOpenUrl;

        string m_strSetUserWallpaper;
        string m_strGetUserWallpaper;
        bool m_bGetUserWallpaper;

        //::iptr                   m_iptrMessageBoxSequence;
        // int                  m_iMessageBoxButton;
        //string                   m_strMessageBox;
        //string                   m_strMessageBoxCaption;
        //int                      m_iMessageBoxButton;
        //bool                     m_bMessageBox;
        //bool                     m_bMessageBoxOn;
        //bool                     m_iMessageBoxResult;
        long long m_lMemFreeAvailableKb;


        bool m_bEditFocusSet;
        int_rectangle m_rectangleEditFocus;
        bool m_bEditFocusKill;

        //bool                       m_bRedraw;

        bool m_bEditorSelectionUpdated;
        int m_iEditorSelectionStart;
        int m_iEditorSelectionEnd;

        bool m_bEditorTextUpdated;
        string m_strEditorText;


        bool m_bLastShowSoftwareKeyboard;


        bool m_bInputMethodManagerUpdateSelection;
        int m_iInputMethodManagerSelectionStart;
        int m_iInputMethodManagerSelectionEnd;
        int m_iInputMethodManagerCandidateStart;
        int m_iInputMethodManagerCandidateEnd;

        //asset_manager *            m_passetmanager;

        //::pointer<asset>           m_passetResourceFolder;

        //::particle_pointer                        m_pparticleMutexMessageBoxSequencer;
        //::pointer_array < ::message_box > m_messageboxa;


        //::particle_pointer                        m_pparticleMutexListFileEnumerate;
        //::string_array                                  m_straListFileEnumerate;


        driver();

        ~driver() override;

        // windowing::text_editor_interface
        void set_input_method_manager_selection(character_count iSelBeg, character_count iSelEnd,
                                                character_count iCandidateBeg,
                                                character_count iCandidateEnd) override;

        //void set_input_method_manager_candidate_position(character_count iStart, character_count iEnd) override;
        void synchronize_input_method_manager_with_selection_end() override;

        void set_editor_selection(character_count iStart, character_count iEnd) override;

        void set_editor_text(const ::scoped_string & scopedstrText) override;

        void show_software_keyboard() override;

        void hide_software_keyboard() override;


//   static operating_system_driver* get();
//   static void set(operating_system_driver* pdriver);

//
//   virtual void queue_message_box(::message_box* psequencer);
//   virtual ::pointer < ::message_box > pick_message_box();

//
//   virtual void open_url(const ::scoped_string & scopedstrOpenUrl);


        void exchange1() override;

        //void after_exchange() override;


//   void list_file_enumerate(const ::scoped_string & scopedstrListFileEnumerate) override;


    };


} // namespace android

