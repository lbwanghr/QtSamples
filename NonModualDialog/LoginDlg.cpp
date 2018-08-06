#include "LoginDlg.h"

LoginDlg::LoginDlg(const char* user, QWidget *parent)
	: QDialog(parent){
	ui.setupUi(this);
	ui.textUser->setText(user);
	connect(ui.btnOk,SIGNAL(clicked()),this,SLOT(onBtnOk()));
	connect(ui.btnCancel,SIGNAL(clicked()),this,SLOT(onBtnOk()));
}

LoginDlg::~LoginDlg(){

}

int LoginDlg::onBtnOk(){
	m_user=ui.textUser->text();
	m_password=ui.textPassword->text();
	accept();	//ȷ���û����룬����ֵ
	return 0;
}
int LoginDlg::onBtnCancel(){
	reject();	//ȡ���û����룬����ֵ
	return 0;
}