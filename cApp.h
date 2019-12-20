#pragma once

#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp
{

public:
	cApp();
	~cApp();

	virtual bool OnInit() wxOVERRIDE;
	virtual int OnExit() wxOVERRIDE;

	wxFrame* CreateChildFrame(wxView* view, bool isCanvas);


private:
	cMain* m_frame;

	void CreateMenuBarForFrame(wxFrame* frame, wxMenu* file, wxMenu* edit);
	void AppendDocumentFileCommands(wxMenu* menu, bool supportsPrinting);

};

wxDECLARE_APP(cApp);

