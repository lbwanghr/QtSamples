#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtGui/QWidget>
#include "ui_mythread.h"

class MyThread : public QWidget{
	Q_OBJECT

public:
	MyThread(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyThread();

private:
	Ui::MyThreadClass ui;
};

#endif // MYTHREAD_H
