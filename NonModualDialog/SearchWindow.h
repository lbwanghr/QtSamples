#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QWidget>
#include "ui_SearchWindow.h"

class SearchWindow : public QWidget{
	Q_OBJECT

public:
	SearchWindow(QWidget *parent = 0);
	~SearchWindow();

public:
	Ui::SearchWindow ui;
};

#endif // SEARCHWINDOW_H
