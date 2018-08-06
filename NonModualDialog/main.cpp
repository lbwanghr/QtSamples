#include "nonmodualdialog.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	NonModualDialog w;
	w.show();
	return a.exec();
}
