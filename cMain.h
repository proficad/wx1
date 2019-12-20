#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{

public:
	cMain();
	~cMain();

	wxButton* m_pBtn;
	wxTextCtrl* m_txt;
	wxListBox* m_lst;

	void OnButtonClicked(wxCommandEvent &evt);

	wxDECLARE_EVENT_TABLE();
};

