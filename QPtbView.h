#pragma once

#include "QCommonView.h"
#include "wx\docview.h"

class QPtbView :
	public QCommonView
{
public:
	virtual void OnDraw(wxDC* dc) wxOVERRIDE;


	wxDECLARE_DYNAMIC_CLASS(QPtbView);

};

