#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QtGui/QMainWindow>
#include "ui_texteditor.h"
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <GBK.h>

class TextEditor : public QDialog{
	Q_OBJECT

public:
	TextEditor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TextEditor();

private:
	Ui::TextEditorClass ui;

private slots:
	void OnBtnOpen();
	void OnBtnSave();
};

#endif // TEXTEDITOR_H
