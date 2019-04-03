// Local class header file
#include "gui/mainwindow.h"

// QT header files
#include <QCloseEvent>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QFileDialog>

// Project specific header files
#include "core/app.h"

// Constructor
MainWindow::MainWindow()
{
	mGui.setupUi(this);
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