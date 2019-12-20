#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()


cMain::cMain(wxDocManager* manager,
	wxFrame* parent,
	wxWindowID 	id,
	const wxString& title,
	const wxPoint& pos,
	const wxSize& size) 
	: wxDocMDIParentFrame(manager, parent, id, title, pos, size)
{
	wxMenu* menuFile = new wxMenu;

	menuFile->Append(wxID_NEW);
	menuFile->Append(wxID_OPEN);

//	AppendDocumentFileCommands(menuFile, true);

	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);


	wxMenuBar* menubar = new wxMenuBar;
	menubar->Append(menuFile, wxGetStockLabel(wxID_FILE));
	SetMenuBar(menubar);

	/*
	m_pBtn	= new wxButton(this, 10001, "click me", wxPoint(10, 10), wxSize(150, 50));
	m_txt	= new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_lst = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
	*/
}

cMain::~cMain()
{

}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
	m_lst->AppendString(m_txt->GetValue());
	evt.Skip();
}
