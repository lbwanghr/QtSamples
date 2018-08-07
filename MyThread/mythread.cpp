#include "mythread.h"

MyThread::MyThread(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags){
	ui.setupUi(this);
	connect(ui.btnBrowser,SIGNAL(clicked()),this,SLOT(OnBtnBrowser()));
	connect(ui.btnTransfer,SIGNAL(clicked()),this,SLOT(OnBtnTransfer()));
}

MyThread::~MyThread(){

}

int MyThread::OnBtnBrowser(){
	QString filepath=QFileDialog::getOpenFileName(this,"Ñ¡ÔñÎÄ¼þ");
	if(filepath.length()>0){
		ui.lineEdit->setText(filepath);
	}
	return 0;
}
int MyThread::OnBtnTransfer(){
	QString filename=ui.lineEdit->text();
	DlgTransfer dlg(filename,this);
	dlg.exec();
	return 0;
}