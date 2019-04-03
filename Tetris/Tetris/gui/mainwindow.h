#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// QT header files
#include <QMainWindow>

// Project specific header files
#include "ui_mainwindow.h"

class QGraphicsView;
class QCloseEvent;
class MenuBar;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();
	virtual ~MainWindow();
	QGraphicsView *getView();
	
signals:

public slots:

private:
	void closeEvent(QCloseEvent *aEvent);
	Ui::Tetris mGui;
};
#endif