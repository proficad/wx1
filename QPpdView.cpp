#include "QPpdView.h"

wxIMPLEMENT_DYNAMIC_CLASS(QPpdView, QCommonView);

void QPpdView::OnDraw(wxDC* dc) wxOVERRIDE
{
	wxPoint l_point(50, 50);
	dc->DrawText("PPD", l_point);

}
