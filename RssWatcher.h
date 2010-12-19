#pragma once

#include "HttpDownloader.h"

class CRssWatcher : public CThreadImpl<CRssWatcher>
{
public:
	CRssWatcher();

	DWORD Run();
	void ProcessFeed(int id, const CString& sUrl);
	CEvent shutDown; // CNewzflow will set this event to indicate the dir watcher should shut down

protected:
	CHttpDownloader downloader;
};