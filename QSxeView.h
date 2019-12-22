#pragma once
#include "QCommonView.h"
class QSxeView :
	public QCommonView
{


public:
	virtual void OnDraw(wxDC* dc) wxOVERRIDE;


	wxDECLARE_DYNAMIC_CLASS(QSxeView);
};

