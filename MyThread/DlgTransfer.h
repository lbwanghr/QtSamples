#ifndef DLGTRANSFER_H
#define DLGTRANSFER_H

#include <QWidget>
#include "ui_DlgTransfer.h"
#include "TransferTask.h"
#include <GBK.h>


class DlgTransfer : public QDialog{
	Q_OBJECT

public:
	DlgTransfer(const QString& filename,QWidget *parent = 0);
	~DlgTransfer();
	//ÖØÐ´timeEventº¯Êý
	virtual void timerEvent(QTimerEvent *event);

private:
	Ui::DlgTransfer ui;
	TransferTask* m_task;
	int m_timerId;
};

#endif // DLGTRANSFER_H
