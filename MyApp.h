#pragma once

#include "wx/wx.h"
#include "MyMainFrame.h"

class MyApp : public wxApp
{

public:
	MyApp();
	~MyApp();

	virtual bool OnInit() wxOVERRIDE;
	virtual int OnExit() wxOVERRIDE;

	wxFrame* CreateChildFrame(wxView* view, bool isCanvas);


private:
	MyMainFrame* m_frame;

	void CreateMenuBarForFrame(wxFrame* frame, wxMenu* file, wxMenu* edit);
	void AppendDocumentFileCommands(wxMenu* menu, bool supportsPrinting);

};

wxDECLARE_APP(MyApp);

