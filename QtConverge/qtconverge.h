#ifndef QTCONVERGE_H
#define QTCONVERGE_H

#include <QtGui/QMainWindow>
#include "ui_qtconverge.h"
#include <TextEditor/texteditor.h>
#include <NonModualDialog/nonmodualdialog.h>

class QtConverge : public QMainWindow{
	Q_OBJECT

public:
	QtConverge(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtConverge();

private:
	Ui::QtConvergeClass ui;
	//TextEditor* dlgTextEditor;

private slots:
	int onStartTextEditor();
	int onStartModualDialog();
};

#endif // QTCONVERGE_H
