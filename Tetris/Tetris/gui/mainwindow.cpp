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
}

// Destructor
MainWindow::~MainWindow()
{

}

void
MainWindow::closeEvent(QCloseEvent *aEvent)
{
	QWidget::closeEvent(aEvent);
}

QGraphicsView *
MainWindow::getView()
{
	return mGui.mView;
}