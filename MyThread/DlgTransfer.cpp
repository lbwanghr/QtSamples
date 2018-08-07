#include "DlgTransfer.h"

DlgTransfer::DlgTransfer(const QString& filename,QWidget *parent)
	: QDialog(parent){
	ui.setupUi(this);
	string gbk_filepath=GBK::FromUnicode(filename);	//֧������ת��
	m_task=new TransferTask(NULL);
	m_task->Create(gbk_filepath.c_str());	//���������߳�
	m_timerId=startTimer(500);	//ÿ500�����ѯһ��
}

DlgTransfer::~DlgTransfer(){

}

void DlgTransfer::timerEvent(QTimerEvent *event){
	if(event->timerId()==m_timerId){
		//��ȡ�����̵߳ĵ�ǰ״̬�ͽ��Ȳ���ʾ
		int status=m_task->GetStatus();
		int progress=m_task->GetProgress();
		ui.progressBar->setValue(progress);
		if(status){
			m_task->Destroy();	//���ٹ����߳�
			delete m_task;	//���ٶ���
			killTimer(m_timerId);	//�رն�ʱ��
			this->accept();	//�رնԻ���
		}
	}
}