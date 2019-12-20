#pragma once
#include "wx/wx.h"

#include "wx/docview.h"
#include "wx/docmdi.h"

#if !wxUSE_DOC_VIEW_ARCHITECTURE
#error You must set wxUSE_DOC_VIEW_ARCHITECTURE to 1 in setup.h!
#endif

class cMain : public wxDocMDIParentFrame
{

public:
	cMain(wxDocManager* manager,
		wxFrame* parent,
		wxWindowID 	id,
		const wxString& title,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize);

	~cMain();

	wxButton* m_pBtn;
	wxTextCtrl* m_txt;
	wxListBox* m_lst;

	void OnButtonClicked(wxCommandEvent &evt);

	wxDECLARE_EVENT_TABLE();
};

