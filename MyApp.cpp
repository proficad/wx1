#include "MyApp.h"

#include "QSxeDoc.h"
#include "QSxeView.h"
#include "QPpdDoc.h"
#include "QPpdView.h"
#include "QPtbDoc.h"
#include "QPtbView.h"


wxIMPLEMENT_APP(MyApp);

MyApp::MyApp()
{

}

MyApp::~MyApp()
{

}

bool MyApp::OnInit()
{
	if (!wxApp::OnInit())
	{
		return false;
	}

	SetVendorName("ProfiCAD");
	SetAppName("ProfiCAD");
	SetAppDisplayName("Electrical CAD");

	//// Create a document manager
	wxDocManager* docManager = new wxDocManager;

	//// Create a template relating drawing documents to their views
	wxDocTemplate* l_template_sxe = new wxDocTemplate(docManager, "Sxe", "*.sxe", "", "sxe",
		"Sxe Doc", "Sxe View", CLASSINFO(QSxeDoc), CLASSINFO(QSxeView));
	
	wxDocTemplate* l_template_ppd = new wxDocTemplate(docManager, "Ppd", "*.ppd", "", "ppd",
		"Ppd Doc", "Ppd View",	CLASSINFO(QPpdDoc), CLASSINFO(QPpdView));

	new wxDocTemplate(docManager, "Ptb", "*.ptb", "", "ptb",
		"Ptb Doc", "Ptb View",	CLASSINFO(QPtbDoc), CLASSINFO(QPtbView));


	m_frame = new MyMainFrame(docManager, NULL, wxID_ANY,
		GetAppDisplayName(),
		wxDefaultPosition,
		wxSize(500, 400));

	m_frame->Show();
	//docManager->CreateNewDocument();
	
	l_template_ppd->CreateDocument(wxString(), wxDOC_NEW);

	return true;
}

int MyApp::OnExit() wxOVERRIDE
{
	wxDocManager* const manager = wxDocManager::GetDocumentManager();
#if wxUSE_CONFIG
	//9 manager->FileHistorySave(*wxConfig::Get());
#endif // wxUSE_CONFIG
	delete manager;

	return wxApp::OnExit();
}

wxFrame* MyApp::CreateChildFrame(wxView* view, bool isCanvas)
{
	wxFrame* subframe = NULL;
	wxDocument* doc = view->GetDocument();


	subframe = new wxDocMDIChildFrame
	(
		doc,
		view,
		wxStaticCast(GetTopWindow(), wxDocMDIParentFrame),
		wxID_ANY,
		"Child Frame",
		wxDefaultPosition,
		wxSize(300, 300)
	);


	wxMenu* menuFile = new wxMenu;

	menuFile->Append(wxID_NEW);
	menuFile->Append(wxID_OPEN);
	AppendDocumentFileCommands(menuFile, isCanvas);
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu* menuEdit;

	menuEdit = new wxMenu;
	menuEdit->Append(wxID_COPY);
	menuEdit->Append(wxID_PASTE);
	menuEdit->Append(wxID_SELECTALL);


	CreateMenuBarForFrame(subframe, menuFile, menuEdit);

	subframe->SetIcon(isCanvas ? wxICON(chrt) : wxICON(notepad));

	return subframe;

}

void MyApp::CreateMenuBarForFrame(wxFrame* frame, wxMenu* file, wxMenu* edit)
{
	wxMenuBar* menubar = new wxMenuBar;

	menubar->Append(file, wxGetStockLabel(wxID_FILE));

	if (edit)
		menubar->Append(edit, wxGetStockLabel(wxID_EDIT));

	wxMenu* help = new wxMenu;
	help->Append(wxID_ABOUT);
	menubar->Append(help, wxGetStockLabel(wxID_HELP));

	frame->SetMenuBar(menubar);
}

void MyApp::AppendDocumentFileCommands(wxMenu* menu, bool supportsPrinting)
{
	menu->Append(wxID_CLOSE);
	menu->Append(wxID_SAVE);
	menu->Append(wxID_SAVEAS);
	menu->Append(wxID_REVERT, _("Re&vert..."));

	if (supportsPrinting)
	{
		menu->AppendSeparator();
		menu->Append(wxID_PRINT);
		menu->Append(wxID_PRINT_SETUP, "Print &Setup...");
		menu->Append(wxID_PREVIEW);
	}
}
