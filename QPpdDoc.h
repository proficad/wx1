#pragma once

#include "wx\docview.h"
#include "QDocPpd.h"

class QPpdDoc :
	public wxDocument
{








private:
	QDocPpd m_doc;


	wxDECLARE_DYNAMIC_CLASS(QPpdDoc);
};

