#include "timer.h"

Timer::Timer(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags){
	ui.setupUi(this);
	m_timerId=startTimer(500);
}

Timer::~Timer(){

}

void Timer::timerEvent(QTimerEvent *event){
	//可以有多个定时器，每个定时器有不同的处理
	if(event->timerId()==m_timerId){
		QTime now=QTime::currentTime();
		QString text=now.toString("HH:mm:ss");
		qDebug()<< text;
		ui.labelTime->setText(text);
	}
}