#pragma once
#include "wx/wx.h"

#include "wx/docview.h"
#include "wx/docmdi.h"

#if !wxUSE_DOC_VIEW_ARCHITECTURE
#error You must set wxUSE_DOC_VIEW_ARCHITECTURE to 1 in setup.h!
#endif

class MyMainFrame : public wxDocMDIParentFrame
{

public:
	MyMainFrame(wxDocManager* manager,
		wxFrame* parent,
		wxWindowID 	id,
		const wxString& title,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize);

	// create main menu (shown when no document open)
	void Create_Main_Menu();

	~MyMainFrame();

	wxButton* m_pBtn;
	wxTextCtrl* m_txt;
	wxListBox* m_lst;

	void OnButtonClicked(wxCommandEvent &evt);

	wxDECLARE_EVENT_TABLE();
};

