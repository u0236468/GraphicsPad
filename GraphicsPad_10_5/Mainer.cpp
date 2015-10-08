#include <Qt\qapplication.h>
#include "MeOpenGl.h"

void main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MeOpenGl widg;
	widg.show();
	app.exec();
}