// Local class header file
#include "core/app.h"

// QT header files
#include <QApplication>
#include <QDebug>

// Project specific header files
#include "gui/mainwindow.h"
#include "core/game.h"

App *App::sThis = NULL;


/** Constructor. Load the file given in the command arguments or show the main menu.
*/
App::App()
{
	sThis = this;
	
	mGame = new Game();

	mMainWindow = new MainWindow();
	mMainWindow->show();
}


/** Destructor.
*/
App::~App()
{
	
}


/** Get pointer to this application. Create it if it's not existing.
*/
App *
App::sInstance()
{
	if (sThis == NULL)
		new App;
	return sThis;
}


/** Get pointer to the main window.
*/
MainWindow *
App::getMainWindow() const
{
	return mMainWindow;
}