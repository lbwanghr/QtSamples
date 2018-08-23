#ifndef SUBDIALOG_H
#define SUBDIALOG_H

#include <QObject>

class SubDialog : public QObject
{
	Q_OBJECT

public:
	SubDialog(QObject *parent);
	~SubDialog();

signals:
	void sendSig();
	
};

#endif // SUBDIALOG_H
