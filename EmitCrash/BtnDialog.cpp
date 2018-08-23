#include "BtnDialog.h"

BtnDialog::BtnDialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.btn,SIGNAL(clicked()),this,SLOT(btnSendSig()));
}

BtnDialog::~BtnDialog()
{

}
void BtnDialog::btnSendSig(){
	emit sendSig();	
}