#include "QPtbView.h"


wxIMPLEMENT_DYNAMIC_CLASS(QPtbView, QCommonView);

void QPtbView::OnDraw(wxDC* dc) wxOVERRIDE
{
	wxPoint l_p1(100, 100);
	wxCoord l_coord(20);
//	dc->DrawCircle(l_p1, l_coord);
	wxPoint l_point(50, 50);
	dc->DrawText("PTB", l_point);

	l_point.x = 200;
	l_point.y = 100;
	dc->DrawRotatedText("PTB", l_point, 45);
}
