#include "qtconverge.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtConverge w;
	w.show();
	return a.exec();
}
