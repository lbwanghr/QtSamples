#ifndef BTNDIALOG_H
#define BTNDIALOG_H

#include <QWidget>
#include "ui_BtnDialog.h"

class BtnDialog : public QWidget
{
	Q_OBJECT

public:
	BtnDialog(QWidget *parent = 0);
	~BtnDialog();

private:
	Ui::BtnDialog ui;
private slots:
	void btnSendSig();
signals:
	void sendSig();
};

#endif // BTNDIALOG_H
