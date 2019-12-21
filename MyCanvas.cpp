// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if !wxUSE_DOC_VIEW_ARCHITECTURE
#error You must set wxUSE_DOC_VIEW_ARCHITECTURE to 1 in setup.h!
#endif


#include "MyCanvas.h"


wxBEGIN_EVENT_TABLE(MyCanvas, wxScrolledWindow)
EVT_MOUSE_EVENTS(MyCanvas::OnMouseEvent)
wxEND_EVENT_TABLE()

// Define a constructor for my canvas
MyCanvas::MyCanvas(wxView* view, wxWindow* parent)
	: wxScrolledWindow(parent ? parent : view->GetFrame())
{
	m_view = view;

	m_lastMousePos = wxDefaultPosition;

	SetCursor(wxCursor(wxCURSOR_PENCIL));

	// this is completely arbitrary and is done just for illustration purposes
	SetVirtualSize(1000, 1000);
	SetScrollRate(20, 20);

	SetBackgroundColour(*wxWHITE);
}

MyCanvas::~MyCanvas()
{

}


// Define the repainting behaviour
void MyCanvas::OnDraw(wxDC& dc)
{
	if (m_view)
		m_view->OnDraw(&dc);
}

// This implements a tiny doodling program. Drag the mouse using the left
// button.
void MyCanvas::OnMouseEvent(wxMouseEvent& event)
{
	if (!m_view)
		return;

	wxClientDC dc(this);
	PrepareDC(dc);

	dc.SetPen(*wxBLACK_PEN);

	const wxPoint pt(event.GetLogicalPosition(dc));



	m_lastMousePos = pt;
}