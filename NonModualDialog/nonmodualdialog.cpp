#include "nonmodualdialog.h"

NonModualDialog::NonModualDialog(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags){
	ui.setupUi(this);
	connect(ui.btnShow1,SIGNAL(clicked()),this,SLOT(onBtnShow1()));
	connect(ui.btnShow2,SIGNAL(clicked()),this,SLOT(onBtnShow2()));
	m_searchWin=new SearchWindow(this);
	m_searchWin->setWindowFlags((Qt::Window));
	//响应小窗口内的按钮动作(需要在SearchWindow.h中将UI置为public)
	connect(m_searchWin->ui.m_btnSearch,SIGNAL(clicked()),this,SLOT(onStartSearch()));
}

NonModualDialog::~NonModualDialog(){

}

int NonModualDialog::onBtnShow1(){
	LoginDlg ModualDlg("admin",this);
	int ret=ModualDlg.exec();
	if(ret==QDialog::Accepted){
		qDebug()<<ModualDlg.m_user<<ModualDlg.m_password;
		QString text=GBK::ToUnicode("用户名:")+ModualDlg.m_user+"\t"+GBK::ToUnicode("密码:")+ModualDlg.m_password;
		ui.textEdit->append(text);
	}else{

	}
	return 0;
}

int NonModualDialog::onBtnShow2(){
	m_searchWin->show();
	return 0;
}

int NonModualDialog::onStartSearch(){
	QString text=m_searchWin->ui.m_text->text();
	text=GBK::ToUnicode("当前查找内容为:\n")+text;
	ui.textEdit->append(text);
	return 0;
}