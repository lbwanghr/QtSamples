#include "emitcrash.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EmitCrash w;
	w.show();
	return a.exec();
}
