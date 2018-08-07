#include "TransferTask.h"

TransferTask::TransferTask(QObject *parent)
	: QThread(parent){

}

TransferTask::~TransferTask(){

}
int TransferTask::GetStatus(){
	return m_status;
}
int TransferTask::GetProgress(){
	if(m_filesize<=0)return 0;
	return m_bytesread*100/m_filesize;
}
void TransferTask::run(){	//�߳�������
	FILE* fp=fopen(m_filename,"rb");
	if(!fp){
		return ;
	}
	fseek(fp,0,SEEK_END);
	m_filesize=ftell(fp);
	fseek(fp,0,SEEK_SET);
	char buf[256];
	while(true){
		int n=fread(buf,1,256,fp);
		if(n<=0)break;
		m_bytesread+=n;
		qDebug()<<"Read:"<<m_bytesread;
		QThread::msleep(50);	//����ÿ�ζ�ȡʱ���Ա�۲�
	}
	fclose(fp);
	m_status=1;	//�Ѿ��������
	qDebug()<<"Complete!";
}
void TransferTask::Create(const char* filename){
	strcpy(m_filename,filename);
	m_filesize=0;
	m_bytesread=0;
	m_status=0;
	start();	//start��ζ�ſ�ʼִ��run����
}
void TransferTask::Destroy(){
	wait();
}