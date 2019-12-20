#include "QSxeView.h"
#include "cApp.h"
#include "QSxeDoc.h"

wxIMPLEMENT_DYNAMIC_CLASS(QSxeView, wxView);

bool QSxeView::OnCreate(wxDocument* doc, long flags) wxOVERRIDE
{
	if (!wxView::OnCreate(doc, flags))
		return false;


	cApp& app = wxGetApp();
	wxFrame* frame = app.CreateChildFrame(this, true);
	wxASSERT(frame == GetFrame());
	//m_canvas = new MyCanvas(this);

	frame->Show();

	return true;
}

void QSxeView::OnDraw(wxDC* dc) wxOVERRIDE
{

}


bool QSxeView::OnClose(bool deleteWindow /*= true*/) wxOVERRIDE
{
	if (!wxView::OnClose(deleteWindow))
		return false;

	Activate(false);
	return true;
}

QSxeDoc* QSxeView::GetDocument()
{
	return wxStaticCast(wxView::GetDocument(), QSxeDoc);
}
