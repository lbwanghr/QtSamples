#ifndef TIMER_H
#define TIMER_H

#include <QtGui/QMainWindow>
#include "ui_timer.h"
#include <QTime>
#include <QDebug>

class Timer : public QDialog{
	Q_OBJECT

public:
	Timer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Timer();

	//��д�˺���(�̳���QObject)
	virtual void timerEvent(QTimerEvent *event);

private:
	Ui::TimerClass ui;
	int m_timerId;	//ÿһ��Timer��һ��ID
};

#endif // TIMER_H
