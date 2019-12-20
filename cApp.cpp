#include "cApp.h"

#include "QSxeDoc.h"
#include "QSxeView.h"
#include "QPpdDoc.h"
#include "QPpdView.h"
#include "QPtbDoc.h"
#include "QPtbView.h"


wxIMPLEMENT_APP(cApp);

cApp::cApp()
{

}

cApp::~cApp()
{

}

bool cApp::OnInit()
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
	new wxDocTemplate(docManager, "Drawing", "*.sxe", "", "sxe",
		"Sxe Doc", "Sxe View", CLASSINFO(QSxeDoc), CLASSINFO(QSxeView));

	
	new wxDocTemplate(docManager, "Ppd", "*.ppd", "", "ppd",
		"Ppd Doc", "Ppd View",	CLASSINFO(QPpdDoc), CLASSINFO(QPpdView));

	new wxDocTemplate(docManager, "Ptb", "*.ptb", "", "ptb",
		"Ptb Doc", "Ptb View",	CLASSINFO(QPtbDoc), CLASSINFO(QPtbView));


	m_frame = new cMain(docManager, NULL, wxID_ANY,
		GetAppDisplayName(),
		wxDefaultPosition,
		wxSize(500, 400));

	m_frame->Show();

	return true;
}
