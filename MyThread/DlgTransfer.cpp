#include "DlgTransfer.h"

DlgTransfer::DlgTransfer(const QString& filename,QWidget *parent)
	: QDialog(parent){
	ui.setupUi(this);
	string gbk_filepath=GBK::FromUnicode(filename);	//支持中文转换
	m_task=new TransferTask(NULL);
	m_task->Create(gbk_filepath.c_str());	//开启工作线程
	m_timerId=startTimer(500);	//每500毫秒查询一次
}

DlgTransfer::~DlgTransfer(){

}

void DlgTransfer::timerEvent(QTimerEvent *event){
	if(event->timerId()==m_timerId){
		//获取工作线程的当前状态和进度并显示
		int status=m_task->GetStatus();
		int progress=m_task->GetProgress();
		ui.progressBar->setValue(progress);
		if(status){
			m_task->Destroy();	//销毁工作线程
			delete m_task;	//销毁对象
			killTimer(m_timerId);	//关闭定时器
			this->accept();	//关闭对话框
		}
	}
}