#include "mythread.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyThread w;
	w.show();
	return a.exec();
}
