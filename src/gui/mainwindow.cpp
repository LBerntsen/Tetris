// Local class header file
#include "gui/mainwindow.h"

// QT header files
#include <QCloseEvent>
#include <QMenu>
#include <QDebug>
#include <QGraphicsView>

// Project specific header files
#include "core/app.h"
#include "core/game.h"

// Constructor
MainWindow::MainWindow(Game *aGame)
{
	mGame = aGame;
	mGui.setupUi(this);
	this->setWindowFlags(this->windowFlags() |= Qt::MSWindowsFixedSizeDialogHint);

}

// Destructor
MainWindow::~MainWindow()
{

}

QGraphicsView *
MainWindow::getView()
{
	return mGui.mView;
}