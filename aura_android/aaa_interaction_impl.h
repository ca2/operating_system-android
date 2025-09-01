#pragma once


//#include "aura/user/user/interaction_impl.h"

//
//namespace aura_android
//{
//
//
//
//   class CLASS_DECL_AURA interaction_impl:
//      virtual public ::windowing::window
//   {
//   public:
//
//
//      string                                    m_strWindowText;
//      ::user::primitive *                       m_pbasewnd;
//      bool                                      m_bUpdateGraphics;
//      int_size                                      m_size;
//      int_point                                     m_point;
//      static const unsigned int                         m_nMsgDragList;
//      e_display                                 m_edisplayLayout;
//      ::thread *                                m_pthreadDraw;
//      int                                       m_iSoftwareKeyboardScroll;
//
//
//      interaction_impl();
//      ~interaction_impl() override;
//
//
//      //void assert_ok() const override;
//      //void dump(dump_context & dumpcontext) const override;
//
//      //bool create_message_queue(::user::interaction * pinteraction, const ::string & pszName) override;
//
//      //virtual bool create_native_window(::user::native_window_initialize * pinitialize) override;
//
//
//      void install_message_routing(::channel * pchannel) override;
//
//      //bool operator==(const ::windowing::window& wnd) const;
//      //bool operator!=(const ::windowing::window& wnd) const;
//
//      //virtual bool ModifyStyle(unsigned int dwRemove,unsigned int dwAdd,unsigned int nFlags = 0) override;
//      //virtual bool ModifyStyleEx(unsigned int dwRemove,unsigned int dwAdd,unsigned int nFlags = 0) override;
//
//      void route_command(::message::command * pcommand, bool bRouteToKeyDescendant = false) override;
//
//      //void _002OnDraw(::image::image * pimage);
//
//      //DECLARE_MESSAGE_HANDLER(on_message_size);
//      //DECLARE_MESSAGE_HANDLER(on_message_show_window);
//      //DECLARE_MESSAGE_HANDLER(_001OnProdevianSynch);
//
//      //void OnWindowPosChanging(WINDOWPOS* lpuserinteractionpos);
//      //void OnWindowPosChanged(WINDOWPOS* lpuserinteractionpos);
//
//      //virtual void win_update_graphics();
//
//#if(WINVER >= 0x0500)
//
//      bool GetWindowInfo(PWINDOWINFO pwi) const;
//      bool GetTitleBarInfo(PTITLEBARINFO pti) const;
//
//#endif   // WINVER >= 0x0500
//
//      //virtual ::windowing::window * from_os_data(void * pdata) override;
//      //virtual void * get_os_data() const override;
//
//      //static ::windowing::window * from_handle(oswindow oswindow);
//      //static ::user::interaction * ui_from_handle(oswindow oswindow);
//
//      // subclassing/unsubclassing functions
//      virtual void pre_subclass_window() override;
//      //bool subclass_window(oswindow oswindow);
//      //bool SubclassDlgItem(unsigned int nID,::user::interaction * pParent);
//      //oswindow unsubclass_window();
//
//      //void native_create_host() override;
//
//      // handling of RT_DLGINIT resource (extension to RT_DIALOG)
//      //bool ExecuteDlgInit(const ::string & lpszResourceName);
//      //bool ExecuteDlgInit(LPVOID lpResource);
//
//      // for child windows, views, panes etc
//      //virtual bool create_window(::user::interaction * pinteraction, const ::string & lpszClassName, const ::string & lpszWindowName, unsigned int dwStyle, const ::int_rectangle & rectangle, ::user::primitive * pParentWnd, atom atom, ::request * prequest = nullptr) override;
//
//      // for top level windows and/or special features
//      //virtual bool create_window_ex(::user::interaction * pinteraction, ::pointer<::user::system>pusersystem, ::user::primitive * puiParent = nullptr, ::atom atom = ::atom()) override;
//
//      // for top level windows and/or special features
//      //virtual bool _native_create_window_ex(::pointer<::user::system>pusersystem) override;
//
//      //virtual bool DestroyWindow() override;
//
//      // special pre-creation and interaction_impl int_rectangle adjustment hooks
//      virtual bool pre_create_window(::user::system * pusersystem) override;
//
//      // Advanced: virtual AdjustWindowRect
//      //enum AdjustType { adjustBorder = 0,adjustOutside = 1 };
//      //virtual void CalcWindowRect(::int_rectangle * lpClientRect,unsigned int nAdjustType = adjustBorder) override;
//
//      virtual void edit_on_set_focus(::user::interaction* pinteraction) override;
//
//      virtual void edit_on_kill_focus(::user::interaction* pinteraction) override;
//
//      void show_software_keyboard(::user::element * pelement) override;
//      void hide_software_keyboard(::user::element * pelement) override;
//
//      using ::windowing::window::get_child_by_id;
//      void get_child_by_id(atom atom,::oswindow* poswindow_) const;
//
//      //virtual bool IsWindow() const;
//
//      // oswindow State Functions
//      //virtual bool IsWindowEnabled();
//      //virtual bool EnableWindow(bool bEnable = true);
//
//      // the active ::windowing::window applies only to top-level (frame windows)
//      //virtual ::user::interaction * get_active_window() override;
//      //virtual ::user::interaction * set_active_window() override;
//
//
//      //LRESULT send_message(const ::atom & atom,const ::wparam & wparam = {},const ::lparam & lparam = {}) override;
//      //bool post_message(const ::atom & atom,const ::wparam & wparam = {},const ::lparam & lparam = {}) override;
//
//      //bool SendNotifyMessage(::enum_message emessage, ::wparam wparam, ::lparam lparam) override;
//      //bool SendChildNotifyLastMsg(LRESULT* pResult = nullptr);
//
//      //bool DragDetect(::int_point pt) const;
//
//      //virtual void RedrawWindow(unsigned int nFlags = 0) override;
//
//      // Window Text Functions
//      //virtual void set_window_text(const ::string & lpszString) override;
//      //virtual character_count get_window_text(char * lpszStringBuf, character_count nMaxCount) override;
//      //virtual void get_window_text(string & rString) override;
//      //virtual character_count get_window_text_length() override;
//
//
//      // Window int_size and position Functions
//      //virtual bool layout().is_iconic();
//      //virtual bool layout().is_zoomed();
//      //int SetWindowRgn(HRGN hRgn,bool bRedraw);
//      //int GetWindowRgn(HRGN hRgn);
//
//      //using ::windowing::window::set_window_position;
//      //virtual bool set_window_position(iptr z,int x,int y,int cx,int cy,unsigned int nFlags = SWP_SHOWWINDOW);
//      //virtual unsigned int ArrangeIconicWindows();
//      //virtual void BringToTop(int nCmdShow);
//      //virtual bool BringWindowToTop();
//      //using ::windowing::window::window_rectangle;
//      //virtual bool window_rectangle(::long_long_rectangle * lpRect);
//      //using ::windowing::window::this->rectangle;
//      //virtual bool this->rectangle(::long_long_rectangle * lpRect);
//
//      //virtual bool client_to_screen(::int_rectangle * lprect);
//      //virtual bool client_to_screen(::int_point * lppoint);
//      //virtual bool client_to_screen(::long_long_rectangle * lprect);
//      //virtual bool client_to_screen(::long_long_point * lppoint);
//      //virtual bool screen_to_client(::int_rectangle * lprect);
//      //virtual bool screen_to_client(::int_point * lppoint);
//      //virtual bool screen_to_client(::long_long_rectangle * lprect);
//      //virtual bool screen_to_client(::long_long_point * lppoint);
//
//      //virtual bool GetWindowPlacement(WINDOWPLACEMENT* lpuserinteractionpl);
//      //virtual bool SetWindowPlacement(const WINDOWPLACEMENT* lpuserinteractionpl);
//
//      //virtual void MapWindowPoints(::user::interaction * puserinteractionTo,::int_point * lpPoint,unsigned int nCount);
//      //virtual void MapWindowPoints(::user::interaction * puserinteractionTo,::int_rectangle * lpRect);
//
//      //virtual void Print(::draw2d::graphics_pointer & pgraphics,unsigned int dwFlags) const;
//      //virtual void PrintClient(::draw2d::graphics_pointer & pgraphics,unsigned int dwFlags) const;
//
//      //virtual void UpdateWindow();
//      //virtual void SetRedraw(bool bRedraw = true);
//      //virtual bool GetUpdateRect(::int_rectangle * lpRect,bool bErase = false);
//      //virtual int GetUpdateRgn(::draw2d::region* pRgn,bool bErase = false);
//      //virtual void Invalidate(bool bErase = true);
//      //virtual void InvalidateRect(const ::int_rectangle * lpRect,bool bErase = true);
//      //virtual void InvalidateRgn(::draw2d::region* pRgn,bool bErase = true);
//      //virtual void ValidateRect(const ::int_rectangle * lpRect);
//      //virtual void ValidateRgn(::draw2d::region* pRgn);
//      //virtual bool show_window(const ::e_display & edisplay) override;
////      virtual void _001WindowMinimize();
//      //virtual void _001WindowMaximize();
//      //    virtual void _001WindowFullScreen();
//      //virtual void _001WindowRestore();
//      // virtual bool _is_window() const override;
//      //virtual bool is_window_visible();
//      //virtual void ShowOwnedPopups(bool bShow = true) override;
//
//      //virtual ::draw2d::graphics * GetDC();
//      //virtual ::draw2d::graphics * GetWindowDC();
//      //virtual bool ReleaseDC(::image::image * pimage);
//      //virtual ::draw2d::graphics * GetDCEx(::draw2d::region* prgnClip,unsigned int flags);
//      //virtual bool LockWindowUpdate() override;
//      //virtual void UnlockWindowUpdate() override;
//      //virtual bool RedrawWindow(const ::int_rectangle * lpRectUpdate = nullptr,
//        //                        ::draw2d::region* prgnUpdate = nullptr,
//          //                      unsigned int flags = RDW_INVALIDATE | RDW_ERASE);
//      //virtual bool EnableScrollBar(int nSBFlags,unsigned int nArrowFlags = 0);
//
//      //virtual bool DrawAnimatedRects(int idAni,const ::int_rectangle *lprcFrom,const ::int_rectangle *lprcTo);
//      //virtual bool DrawCaption(::draw2d::graphics_pointer & pgraphics,const ::int_rectangle * lprc,unsigned int uFlags);
//
//
//
//
//      // timer Functions
//      //virtual bool SetTimer(uptr uEvent,unsigned int nElapse, PFN_TIMER pfnTimer);
//      //virtual bool KillTimer(uptr uEvent);
//
//
//      // the foreground interaction_impl applies only to top-level windows (frame windows)
//      //virtual bool set_foreground_window() override;
//      //virtual ::user::interaction * GetForegroundWindow();
//
//
//
//      //virtual bool XXXSetFocus() override;
//
//      //virtual bool has_keyboard_focus() override;
//      //virtual bool is_active() override;
//
//      //virtual ::user::interaction * GetFocus() override;
//
//      //virtual ::user::interaction * get_desktop_window();
//
//      // Obsolete and non-portable APIs - not recommended for ___new code
//      //virtual void CloseWindow() override;
//      //virtual bool OpenIcon() override;
//
//      // Dialog-Box Item Functions
//      // (NOTE: Dialog-Box Items/Controls are not necessarily in dialog boxes!)
//      //virtual void CheckDlgButton(int nIDButton, unsigned int nCheck) override;
//      //virtual void CheckRadioButton(int nIDFirstButton, int nIDLastButton, int nIDCheckButton) override;
//      //virtual int GetCheckedRadioButton(int nIDFirstButton, int nIDLastButton) override;
//      //virtual int DlgDirList(char * lpPathSpec, int nIDListBox, int nIDStaticPath, unsigned int nFileType) override;
//      //virtual int DlgDirListComboBox(char * lpPathSpec, int nIDComboBox, int nIDStaticPath, unsigned int nFileType) override;
//      //virtual bool DlgDirSelect(char * lpString, int nSize, int nIDListBox) override;
//      //virtual bool DlgDirSelectComboBox(char * lpString, int nSize, int nIDComboBox) override;
//
//      //virtual unsigned int GetChildByIdInt(int nID, bool * lpTrans = nullptr, bool bSigned = true) const;
//      //virtual int GetChildByIdText(int nID, char * lpStr, int nMaxCount) const;
//      //virtual int GetChildByIdText(int nID, string & rString) const;
//      //virtual ::user::interaction * GetNextDlgGroupItem(::user::interaction * pWndCtl, bool bPrevious = false) const;
//      //virtual ::user::interaction * GetNextDlgTabItem(::user::interaction * pWndCtl, bool bPrevious = false) const;
//      //virtual unsigned int IsDlgButtonChecked(int nIDButton) const override;
//      //virtual LRESULT SendDlgItemMessage(int nID, ::enum_message emessage, ::wparam wparam = {}, ::lparam lparam = {}) override;
//      //virtual void SetDlgItemInt(int nID, unsigned int nValue, bool bSigned = true) override;
//      //virtual void SetDlgItemText(int nID, const ::string & lpszString) override;
//
//
//      // Scrolling Functions
//      //virtual int GetScrollPos(int nBar) const override;
//      //virtual void GetScrollRange(int nBar,LPINT lpMinPos,LPINT lpMaxPos) const override;
//      //virtual void ScrollWindow(int xAmount,int yAmount, const ::int_rectangle * lpRect = nullptr, const ::int_rectangle * lpClipRect = nullptr) override;
//      //virtual int SetScrollPos(int nBar,int nPos,bool bRedraw = true) override;
//      //virtual void SetScrollRange(int nBar,int nMinPos,int nMaxPos, bool bRedraw = true) override;
//      //virtual void ShowScrollBar(unsigned int nBar,bool bShow = true) override;
//      //virtual void EnableScrollBarCtrl(int nBar,bool bEnable = true) override;
//
//      //virtual int ScrollWindowEx(int dx,int dy,
//        //                         const ::int_rectangle * lpRectScroll,const ::int_rectangle * lpRectClip,
//          //                       ::draw2d::region* prgnUpdate,::int_rectangle * lpRectUpdate,unsigned int flags) override;
//      //virtual bool SetScrollInfo(int nBar,LPSCROLLINFO lpScrollInfo,
//      //   bool bRedraw = true);
//      //virtual bool GetScrollInfo(int nBar,LPSCROLLINFO lpScrollInfo,unsigned int nMask = SIF_ALL);
////      //virtual int GetScrollLimit(int nBar) override;
////
////#if(WINVER >= 0x0500)
////
////      virtual bool GetScrollBarInfo(int idObject,PSCROLLBARINFO psbi) const;
////
////#endif   // WINVER >= 0x0500
////
////      // Window Access Functions
////      virtual ::user::interaction * ChildWindowFromPoint(::int_point int_point);
////      virtual ::user::interaction * ChildWindowFromPoint(::int_point point,unsigned int nFlags);
////      static ::user::interaction * FindWindow(const ::string & lpszClassName, const ::string & lpszWindowName);
////      static ::user::interaction * FindWindowEx(oswindow oswindowParent,oswindow oswindowChildAfter, const ::string & lpszClass, const ::string & lpszWindow);
//
//      ////virtual ::user::interaction * GetNextWindow(unsigned int nFlag = GW_HWNDNEXT);
//      ////virtual ::user::interaction * GetTopWindow() const override;
//
//      ////virtual ::user::interaction * GetWindow(unsigned int nCmd);
//      //virtual ::user::interaction * GetLastActivePopup() override;
//
//      //virtual bool IsChild(::user::interaction *  pWnd);
//      //virtual ::user::interaction * get_parent();
//      //using ::windowing::window::SetParent;
//      //::user::interaction * SetParent(::user::interaction * pWndNewParent);
//      //static::user::interaction * PASCAL oswindowFromPoint(::int_point int_point);
//
//
//      //virtual ::user::interaction * SetOwner(::user::interaction * pWndNewParent);
//      //virtual ::user::interaction * get_owner() const;
//
//      //virtual bool FlashWindow(bool bInvert);
//
//      //virtual int message_box(const ::string & lpszText, const ::string & lpszCaption = nullptr,unsigned int nType = ::user::e_message_box_ok) override;
//
////
////#if(WINVER >= 0x0500)
////
////      virtual bool FlashWindowEx(unsigned int dwFlags,unsigned int  uCount,class ::time tickTimeout);
////
////#endif   // WINVER >= 0x0500
//
//      // Clipboard Functions
//      //virtual bool ChangeClipboardChain(oswindow oswindow_Next);
//      //virtual ::oswindow  SetClipboardViewer();
//      //virtual bool OpenClipboard();
//      //static ::user::interaction * GetClipboardOwner();
//      //static ::user::interaction * GetClipboardViewer();
//      //static ::user::interaction * GetOpenClipboardWindow();
//
//
//      //static int_point GetCaretPos();
//      //static void SetCaretPos(::int_point int_point);
//      //virtual void HideCaret() override;
//      //virtual void ShowCaret() override;
//
//      //// Shell Interaction Functions
//      //virtual void DragAcceptFiles(bool bAccept = true) override;
//
//      // icon Functions
//      //virtual HICON SetIcon(HICON hIcon,bool bBigIcon);
//      //virtual HICON GetIcon(bool bBigIcon) const;
//
//      // Context Help Functions
//      //virtual bool SetWindowContextHelpId(unsigned int dwContextHelpId) override;
//      //virtual unsigned int GetWindowContextHelpId() const override;
//
//       //support
//      //virtual bool update_data(bool bSaveAndValidate = true);
//      // data wnd must be same type as this
//
//      //// Help Command Handlers
//      //void OnHelp();          // F1 (uses current action_context)
//      //void OnHelpIndex();     // ID_HELP_INDEX
//      //void OnHelpFinder();    // ID_HELP_FINDER, ID_DEFAULT_HELP
//      //void OnHelpUsing();     // ID_HELP_USING
//      //virtual void WinHelp(uptr dwData,unsigned int nCmd = 0);
//      ////virtual void HtmlHelp(uptr dwData, unsigned int nCmd = 0x000F);
//      //virtual void WinHelpInternal(uptr dwData,unsigned int nCmd = 0);
//
//
//
//      //// dialog support
//      ////void UpdateDialogControls(channel* pTarget,bool bDisableIfNoHndler) override;
//      //void CenterWindow(::user::interaction * pAlternateOwner = nullptr) override;
//
//      //virtual bool OnCommand(::user::message * pusermessage) override;
//      //virtual bool OnNotify(::user::message * pusermessage) override;
//
//      DECLARE_MESSAGE_HANDLER(on_message_create);
//
//      //virtual bool SubclassWindow(oswindow hWnd);
//      //HBRUSH OnCtlColor(::draw2d::graphics_pointer & pgraphics,::user::interaction * pwindow,unsigned int nCtlColor);
//
//      //DECLARE_MESSAGE_HANDLER(on_message_destroy);
//      //void OnEnable(bool bEnable);
//      //void OnEndSession(bool bEnding);
//      //bool OnEraseBkgnd(::draw2d::graphics_pointer & pgraphics);
//      ////void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
//      //void OnIconEraseBkgnd(::draw2d::graphics_pointer & pgraphics);
//      //void OnKillFocus(::user::interaction * pNewWnd);
//      ////LRESULT OnMenuChar(unsigned int nChar,unsigned int nFlags,::user::menu* pMenu);
//      ////void OnMenuSelect(unsigned int nItemID,unsigned int nFlags,HMENU hSysMenu);
//      //void OnMove(int x,int y);
//      //DECLARE_MESSAGE_HANDLER(_001OnPaint);
//      //DECLARE_MESSAGE_HANDLER(_001OnPrint);
//      //void OnParentNotify(const ::atom & atom,LPARAM lParam);
//      //HCURSOR OnQueryDragIcon();
//   /*   bool OnQueryEndSession();
//      bool OnQueryNewPalette();
//      bool OnQueryOpen();
//      void OnSetFocus(::user::interaction *);
//      void OnShowWindow(bool bShow,unsigned int nStatus);
//      void OnSize(unsigned int nType,int cx,int cy);
//      void OnTCard(unsigned int idAction,unsigned int dwActionData);*/
//
//      //void OnChangeUIState(unsigned int nAction,unsigned int nUIElement);
//      //void OnUpdateUIState(unsigned int nAction,unsigned int nUIElement);
//      //unsigned int OnQueryUIState();
//
//      // Nonclient-Area message handler member functions
//      //bool OnNcActivate(bool bActive);
//      //void OnNcCalcSize(bool bCalcValidRects,NCCALCSIZE_PARAMS* lpncsp);
//      //bool OnNcCreate(::user::system * lpCreateStruct);
//
//      //DECLARE_MESSAGE_HANDLER(on_message_non_client_calculate_size);
//      //LRESULT OnNcHitTest(::int_point point);
//      //void OnNcLButtonDblClk(unsigned int nHitTest, const ::int_point & point);
//      //void OnNcLButtonDown(unsigned int nHitTest, const ::int_point & point);
//      //void OnNcLButtonUp(unsigned int nHitTest, const ::int_point & point);
//      //void OnNcMButtonDblClk(unsigned int nHitTest, const ::int_point & point);
//      //void OnNcMButtonDown(unsigned int nHitTest, const ::int_point & point);
//      //void OnNcMButtonUp(unsigned int nHitTest, const ::int_point & point);
//      //void OnNcMouseMove(unsigned int nHitTest, const ::int_point & point);
//      //void OnNcPaint();
//      //void OnNcRButtonDblClk(unsigned int nHitTest, const ::int_point & point);
//      //void OnNcRButtonDown(unsigned int nHitTest, const ::int_point & point);
//      //void OnNcRButtonUp(unsigned int nHitTest, const ::int_point & point);
//
//      // ::auraacmesystem() message handler member functions
//      //void OnDropFiles(HDROP hDropInfo);
//      //void OnPaletteIsChanging(::user::interaction * pRealizeWnd);
//      //void OnSysChar(unsigned int nChar,unsigned int nRepCnt,unsigned int nFlags);
//      //void OnSysCommand(unsigned int nID,LPARAM lParam);
//      //void OnSysDeadChar(unsigned int nChar,unsigned int nRepCnt,unsigned int nFlags);
//      //void OnSysKeyDown(unsigned int nChar,unsigned int nRepCnt,unsigned int nFlags);
//      //void OnSysKeyUp(unsigned int nChar,unsigned int nRepCnt,unsigned int nFlags);
//      //void OnCompacting(unsigned int nCpuTime);
//      //void OnDevModeChange(char * lpDeviceName);
//      //void OnFontChange();
//      //void OnPaletteChanged(::user::interaction * pFocusWnd);
//      //void OnSpoolerStatus(unsigned int nStatus,unsigned int nJobs);
//      //void OnSysColorChange();
//      //void OnTimeChange();
//      //void OnSettingChange(unsigned int uFlags, const ::string & lpszSection);
//      //void OnWinIniChange(const ::string & lpszSection);
//
//      //// Input message handler member functions
//      //void OnChar(unsigned int nChar,unsigned int nRepCnt,unsigned int nFlags);
//      //void OnDeadChar(unsigned int nChar,unsigned int nRepCnt,unsigned int nFlags);
//      //      void OnHScroll(unsigned int nSBCode, unsigned int nPos, CScrollBar* pScrollBar);
//      //    void OnVScroll(unsigned int nSBCode, unsigned int nPos, CScrollBar* pScrollBar);
//      //void OnKeyDown(unsigned int nChar,unsigned int nRepCnt,unsigned int nFlags);
//      //void OnKeyUp(unsigned int nChar,unsigned int nRepCnt,unsigned int nFlags);
//      //void OnLButtonDblClk(unsigned int nFlags, const ::int_point & point);
//      //void OnLButtonDown(unsigned int nFlags, const ::int_point & point);
//      //void OnLButtonUp(unsigned int nFlags, const ::int_point & point);
//      //void OnMButtonDblClk(unsigned int nFlags, const ::int_point & point);
//      //void OnMButtonDown(unsigned int nFlags, const ::int_point & point);
//      //void OnMButtonUp(unsigned int nFlags, const ::int_point & point);
//      //int OnMouseActivate(::user::interaction * pDesktopWnd,unsigned int nHitTest,const ::atom & atom);
//      //void OnMouseMove(unsigned int nFlags, const ::int_point & point);
//      //bool OnMouseWheel(unsigned int nFlags,short zDelta, const ::int_point & point);
//      //LRESULT OnRegisteredMouseWheel(WPARAM wParam,LPARAM lParam);
//      //void OnRButtonDblClk(unsigned int nFlags, const ::int_point & point);
//      //void OnRButtonDown(unsigned int nFlags, const ::int_point & point);
//      //void OnRButtonUp(unsigned int nFlags, const ::int_point & point);
//      //////DECLARE_MESSAGE_HANDLER(on_message_set_cursor);
//      //void OnTimer(uptr uEvent);
//
//      // Initialization message handler member functions
//      //void OnInitMenu(::user::menu* pMenu);
//      //void OnInitMenuPopup(::user::menu* pPopupMenu,unsigned int nIndex,bool bSysMenu);
//
//      // Clipboard message handler member functions
//      //void OnAskCbFormatName(unsigned int nMaxCount,char * lpszString);
//      //void OnChangeCbChain(oswindow oswindow_Remove,oswindow oswindow_After);
//      //void OnDestroyClipboard();
//      //void OnDrawClipboard();
//      //void OnHScrollClipboard(::user::interaction * pClipAppWnd,unsigned int nSBCode,unsigned int nPos);
//      ////void OnPaintClipboard(::user::interaction * pClipAppWnd,HGLOBAL hPaintStruct);
//      //void OnRenderAllFormats();
//      //void OnRenderFormat(unsigned int nFormat);
//      ////void OnSizeClipboard(::user::interaction * pClipAppWnd,HGLOBAL hRect);
//      //void OnVScrollClipboard(::user::interaction * pClipAppWnd,unsigned int nSBCode,unsigned int nPos);
//
//      //// control message handler member functions
//      ////int OnCompareItem(int nIDCtl,LPCOMPAREITEMSTRUCT lpCompareItemStruct);
//      ////void OnDeleteItem(int nIDCtl,LPDELETEITEMSTRUCT lpDeleteItemStruct);
//      ////void OnDrawItem(int nIDCtl,LPDRAWITEMSTRUCT lpDrawItemStruct);
//      //unsigned int OnGetDlgCode();
//      //void OnMeasureItem(int nIDCtl,LPMEASUREITEMSTRUCT lpMeasureItemStruct);
//
//      //// MDI message handler member functions
//      //void OnMDIActivate(bool bActivate,
//      //                   ::user::interaction * pActivateWnd,::user::interaction * pDeactivateWnd);
//
//      //// menu loop notification messages
//      //void OnEnterMenuLoop(bool bIstrack_popup_menu);
//      //void OnExitMenuLoop(bool bIstrack_popup_menu);
//
//      //// Win4 messages
//      ////void OnStyleChanged(int nStyleType,LPSTYLESTRUCT lpStyleStruct);
//      ////void OnStyleChanging(int nStyleType,LPSTYLESTRUCT lpStyleStruct);
//      //void OnSizing(unsigned int nSide,::int_rectangle * lpRect);
//      //void OnMoving(unsigned int nSide,::int_rectangle * lpRect);
//      //void OnCaptureChanged(::user::interaction * pwindow);
//      //bool OnDeviceChange(unsigned int nEventType,uptr dwData);
//
//      //// Overridables and other helpers (for implementation of derived classes)
//      //// for deriving from a standard control
//      ////virtual WNDPROC* GetSuperWndProcAddr();
//
//      //// for dialog data exchange and validation
//      ////      virtual void do_data_exchange(CDataExchange* pDX);
//
//      //// for modality
//      //virtual void BeginModalState() override;
//      //virtual void EndModalState() override;
//
//      // for translating Windows messages in main message pump
//      virtual void pre_translate_message(::message::message * pmessage) override;
//
//
//      // for processing Windows messages
//      void message_handler(::message::message * pusermessage) override;
//
//
//      // for handling default processing
//      //LRESULT Default();
//      //virtual LRESULT DefWindowProc(::enum_message emessage, ::wparam wparam, ::lparam lparam);
//
//      //virtual void post_non_client_destroy() override;
//
//      // for notifications from parent
//      //virtual bool OnChildNotify(::user::message * pusermessage);
//      // return true if parent should not process this message
//      //virtual bool ReflectChildNotify(::user::message * pusermessage);
//      //static bool ReflectMessage(oswindow oswindow_Child,::user::message * pusermessage);
//
//
//      //virtual bool CheckAutoCenter() override;
//      //virtual bool GrayCtlColor(HDC hDC,oswindow oswindow,unsigned int nCtlColor,
//      //                          HBRUSH hbrGray,color32_t clrText);
//
//
//      // helper routines for implementation
//      //bool HandleFloatingSysCommand(unsigned int nID, LPARAM lParam) override;
//      //bool IsTopParentActive() override;
//      //void ActivateTopParent() override;
//      //virtual void WalkPreTranslateTree(::user::interaction * puiStop, ::message::message * pmessage);
//      //virtual bool is_frame_window(); // is_kind_of(__type(frame_window)))
//      //virtual void on_final_release() override;
//      //static bool ModifyStyle(oswindow hWnd, unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags);
//      //static bool ModifyStyleEx(oswindow hWnd, unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags);
//      //static void PASCAL _FilterToolTipMessage(MESSAGE* pMsg, ::user::interaction * pWnd);
//      //bool _EnableToolTips(bool bEnable, unsigned int nFlag) override;
//      //static oswindow PASCAL GetSafeOwner_(oswindow hWnd, oswindow* pWndTop);
//      //void PrepareForHelp() override;
//
//
//      //friend class frame_window;
//
//      ///bool CreateDlg(const ::string & lpszTemplateName,::user::interaction * pParentWnd);
//
//
//      //CLASS_DECL_AURA friend LRESULT CALLBACK __send_message_hook(int,WPARAM,LPARAM);
//      //CLASS_DECL_AURA friend LRESULT CALLBACK __cbt_filter_hook(int,WPARAM,LPARAM);
//
//      // standard message implementation
// /*     LRESULT OnNTCtlColor(WPARAM wParam,LPARAM lParam);
//      LRESULT OnDisplayChange(WPARAM,LPARAM);
//      LRESULT OnDragList(WPARAM,LPARAM);*/
//
//      //bool CALLBACK GetAppsEnumWindowsProc(oswindow hwnd, lparam lparam);
//
//
//      //static void get_app_wnda(user::oswindow_array & wnda);
//
//      //virtual void _001DeferPaintLayeredWindowBackground(HDC hdc);
//
//      //virtual int get_window_long(int nIndex) const;
//      //virtual int set_window_long(int nIndex,int lValue);
//      //virtual LONG_PTR get_window_long_ptr(int nIndex) const;
//      //virtual LONG_PTR set_window_long_ptr(int nIndex,LONG_PTR lValue);
//
//      //virtual void _001BaseWndInterfaceMap() override;
//
//
//
//
//      //void set_context_org(::draw2d::graphics_pointer & pgraphics) override;
//
//      //string calc_icon_window_class(unsigned int dwDefaultStyle, const ::string & pszMatter);
//      //string calc_window_class();
//
//      //void on_set_parent(::user::interaction * pinteraction);
//
//      //::user::interaction * FromHandlePermanent(oswindow oswindow);
//
//      //bool Attach(oswindow hWndNew);
//      //virtual oswindow Detach();
//      //virtual bool get_rect_normal(::int_rectangle * lprect);
//      //virtual oswindow UnsubclassWindow();
////      virtual void register_drop_target();
//
//      //virtual void WalkPreTranslateTree(::user::interaction * puiStop, ::message::message * pmessage);
//      //virtual bool SendChildNotifyLastMsg(LRESULT* pResult);
//
//      //virtual oswindow get_handle() const override;
//
//      //virtual void MoveWindow(int x, int y, int nWidth, int nHeight, bool bRepaint);
//      //virtual void MoveWindow(const ::int_rectangle * lpRect, bool bRepaint = true);
//
//      //virtual atom SetDlgCtrlId(atom atom) override;
//      //virtual atom GetDlgCtrlId();
//
//
//      //virtual int GetWindowLong(int nIndex);
//      //virtual int SetWindowLong(int nIndex, int lValue);
//
//
//      //virtual void SetFont(::write_text::font* pfont, bool bRedraw);
//      ////virtual void set_owner(::user::interaction * pOwnerWnd) override;
//      //virtual ::write_text::font* GetFont();
//
//
//
//
//
//      //void _001OnTriggerMouseInside() override;
//
//
//      //::user::interaction * get_next(bool bIgnoreChildren, int * piLevel) override;
//
//
//      virtual bool has_pending_graphical_update()override;
//
//
//      void on_after_graphical_update() override;
//
//
//   };
//
//
//} // namespace aura_android
//
//
//
