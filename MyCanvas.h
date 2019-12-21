#pragma once
#include "wx\scrolwin.h"
#include "wx/docview.h"

class MyCanvas :
	public wxScrolledWindow
{
public:
	// view may be NULL if we're not associated with one yet, but parent must
	// be a valid pointer
	MyCanvas(wxView* view, wxWindow* parent = NULL);
	virtual ~MyCanvas();

	virtual void OnDraw(wxDC& dc) wxOVERRIDE;

	// in a normal multiple document application a canvas is associated with
	// one view from the beginning until the end, but to support the single
	// document mode in which all documents reuse the same MyApp::GetCanvas()
	// we need to allow switching the canvas from one view to another one

	void SetView(wxView* view)
	{
		wxASSERT_MSG(!m_view, "shouldn't be already associated with a view");

		m_view = view;
	}

	void ResetView()
	{
		wxASSERT_MSG(m_view, "should be associated with a view");

		m_view = NULL;
	}


private:
	void OnMouseEvent(wxMouseEvent& event);

	wxView* m_view;


	// the last mouse press position
	wxPoint m_lastMousePos;

	wxDECLARE_EVENT_TABLE();

};

