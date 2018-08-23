#ifndef EMITCRASH_H
#define EMITCRASH_H

#include <QtGui/QMainWindow>
#include "ui_emitcrash.h"
#include "SubDialog.h"
#include "BtnDialog.h"
class EmitCrash : public QMainWindow
{
	Q_OBJECT

public:
	EmitCrash(QWidget *parent = 0, Qt::WFlags flags = 0);
	~EmitCrash();

private:
	Ui::EmitCrashClass ui;
	SubDialog* m_SubDialog;
	BtnDialog* m_BtnDialog;

public slots:
	void testSlot();
};

#endif // EMITCRASH_H
