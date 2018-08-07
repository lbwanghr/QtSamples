#ifndef TRANSFERTASK_H
#define TRANSFERTASK_H

#include <QThread>
#include <QDebug>

class TransferTask : public QThread{
	Q_OBJECT

public:
	TransferTask(QObject *parent);
	~TransferTask();
	int GetStatus();
	int GetProgress();
	void Create(const char* filename);
	void Destroy();
private:
	void run();	//线程工作函数
private:
	char m_filename[128];
	int m_filesize;
	int m_bytesread;	//读取并处理了多少字节
	int m_status;
};

#endif // TRANSFERTASK_H
