#ifndef NONMODUALDIALOG_H
#define NONMODUALDIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QMainWindow>
#include <QDebug>
#include "ui_nonmodualdialog.h"
#include "LoginDlg.h"
#include "SearchWindow.h"
#include <GBK.h>

class NonModualDialog : public QDialog{
	Q_OBJECT

public:
	NonModualDialog(QWidget *parent = 0, Qt::WFlags flags = 0);
	~NonModualDialog();

private slots:
	int onBtnShow1();
	int onBtnShow2();
	int onStartSearch();

private:
	Ui::NonModualDialogClass ui;
	SearchWindow* m_searchWin;
};

#endif // NONMODUALDIALOG_H
