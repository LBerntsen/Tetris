// Local class header file
#include "gui/mainwindow.h"

// QT header files
#include <QCloseEvent>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QGraphicsView>

// Project specific header files
#include "core/app.h"

// Constructor
MainWindow::MainWindow()
{
	mGui.setupUi(this);
	this->setWindowFlags(this->windowFlags() |= Qt::MSWindowsFixedSizeDialogHint);

	connect(mGui.mExit, &QAction::triggered, this, &MainWindow::onExitClicked);
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

void
MainWindow::onExitClicked()
{
	exit(0);
}