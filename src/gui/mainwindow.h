#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// QT header files
#include <QMainWindow>

// Project specific header files
#include "ui_mainwindow.h"

class Game;
class QGraphicsView;
class QCloseEvent;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(Game *aGame);
	virtual ~MainWindow();
	QGraphicsView *getView();
	
signals:

public slots :

private:
	Ui::Tetris mGui;
	Game *mGame;

};
#endif