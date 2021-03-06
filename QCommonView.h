#pragma once


#include "wx\docview.h"

class QSxeDoc;
class MyCanvas;

class QCommonView :
	public wxView
{

public:
	//QSxeView() : wxView(), m_canvas(NULL) {}

	virtual bool OnCreate(wxDocument* doc, long flags) wxOVERRIDE;


	virtual bool OnClose(bool deleteWindow = true) wxOVERRIDE;

	QSxeDoc* GetDocument();



private:
	MyCanvas* m_canvas;

};

