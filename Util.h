#pragma once

namespace Util
{
	void CreateConsole();
	void Print(const char* s);
	void Print(const wchar_t* s);
	CString FormatSize(__int64 size);
	CString FormatSpeed(__int64 speed);
	CString FormatTimeSpan(__int64 time);
	__int64 ParseSize(const CString& s);
	__int64 ParseTimeSpan(const CString& s);
	CString SanitizeFilename(const CString& fn);
	void DeleteDirectory(const CString& path);
	void RegisterAssoc(HINSTANCE hInstance);
	void UnregisterAssoc();
	CString BrowseForFolder(HWND hwndParent, const TCHAR* title, const TCHAR* initialDir);
	CWindow GetMainWindow();
	void SetMainWindow(CWindow wnd);
	CString GetErrorMessage(int error);
	int TestCreateDirectory(const CString& path); // return: system error codes (ERROR_SUCCESS, ...)
	enum EShutdownMode {
		shutdown_nothing,
		shutdown_exit,
		shutdown_poweroff,
		shutdown_suspend,
		shutdown_hibernate,
	};
	bool Shutdown(EShutdownMode mode);

	// user defined messages sent to CMainFrame
	enum {
		MSG_SAVE_NZB = WM_USER+1, // (sent from CNewzflowThread to request a "Save as..." dialog) wParam = (CNzb*)nzb, lParam = (int)errorCode
		MSG_NZB_FINISHED, // (sent from CPostProcessor to indicate a NZB is finished; handler must decrease nzb->refCount) wParam = (CNzb*)nzb
		MSG_RSSFEED_UPDATED, // (sent from CRssWatcher to indicate a RSS feed has been updated)
		MSG_TRAY_NOTIFY
	};
};

class CToolBarImageList
{
public:
	~CToolBarImageList();

	bool Load(const CString& path, int cx, int cy);
	bool LoadFromResource(ATL::_U_STRINGorID bitmap, int cx, int cy);

	bool Load(CImage &image, int cx, int cy);
	void Set(HWND hwndToolBar);

protected:
	CImageList ilNormal, ilDisabled;
};