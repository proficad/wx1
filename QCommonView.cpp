#include "QCommonView.h"
#include "MyApp.h"
#include "QSxeDoc.h"
#include "MyCanvas.h"


bool QCommonView::OnCreate(wxDocument* doc, long flags) wxOVERRIDE
{
	if (!wxView::OnCreate(doc, flags))
		return false;


	MyApp& app = wxGetApp();
	wxFrame* frame = app.CreateChildFrame(this, true);
	wxASSERT(frame == GetFrame());
	m_canvas = new MyCanvas(this);

	frame->Show();

	return true;
}

/*
void QCommonView::OnDraw(wxDC* dc) wxOVERRIDE
{


	wxPoint l_p1(100, 100);
	wxCoord l_coord(20);
	dc->DrawCircle(l_p1, l_coord);

}
*/

bool QCommonView::OnClose(bool deleteWindow /*= true*/) wxOVERRIDE
{
	if (!wxView::OnClose(deleteWindow))
		return false;

	Activate(false);
	return true;
}


QSxeDoc* QCommonView::GetDocument()
{
	return wxStaticCast(wxView::GetDocument(), QSxeDoc);
}
