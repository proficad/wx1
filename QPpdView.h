#pragma once
#include "QCommonView.h"
#include "wx\docview.h"
class QPpdView :
	public QCommonView
{

public:
	virtual void OnDraw(wxDC* dc) wxOVERRIDE;


	wxDECLARE_DYNAMIC_CLASS(QPpdView);


};

