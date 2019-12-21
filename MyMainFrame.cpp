#include "MyMainFrame.h"

wxBEGIN_EVENT_TABLE(MyMainFrame, wxDocMDIParentFrame)
EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()


MyMainFrame::MyMainFrame(wxDocManager* manager,
	wxFrame* parent,
	wxWindowID 	id,
	const wxString& title,
	const wxPoint& pos,
	const wxSize& size) 
	: wxDocMDIParentFrame(manager, parent, id, title, pos, size)
{
	Create_Main_Menu();


	/*
	m_pBtn	= new wxButton(this, 10001, "click me", wxPoint(10, 10), wxSize(150, 50));
	m_txt	= new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_lst = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
	*/
}

MyMainFrame::~MyMainFrame()
{

}

void MyMainFrame::Create_Main_Menu()
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
}



void MyMainFrame::OnButtonClicked(wxCommandEvent &evt)
{
	m_lst->AppendString(m_txt->GetValue());
	evt.Skip();
}
