#include "QSxeView.h"

wxIMPLEMENT_DYNAMIC_CLASS(QSxeView, QCommonView);

void QSxeView::OnDraw(wxDC* dc) wxOVERRIDE
{
	wxPoint l_p1(100, 100);
	wxCoord l_coord(20);
	dc->DrawCircle(l_p1, l_coord);
}
