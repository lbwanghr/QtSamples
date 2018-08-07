#include "qtconverge.h"

QtConverge::QtConverge(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags){
	ui.setupUi(this);
	connect(ui.btnTextEditor,SIGNAL(triggered()),this,SLOT(onStartTextEditor()));
	connect(ui.btnModualDialog,SIGNAL(triggered()),this,SLOT(onStartModualDialog()));
	connect(ui.btnTimer,SIGNAL(triggered()),this,SLOT(onStartTimer()));
	dlgTimer = new Timer(this);
}

QtConverge::~QtConverge(){

}

int QtConverge::onStartTextEditor(){
	TextEditor dlgTextEditor(this);
	dlgTextEditor.exec();
	return 0;
}
int QtConverge::onStartModualDialog(){
	NonModualDialog dlgModualDialog(this);
	dlgModualDialog.exec();
	return 0;
}
int QtConverge::onStartTimer(){
	dlgTimer->show();
	return 0;
}