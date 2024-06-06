// Local class header file
#include "core/app.h"

// QT header files
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

// Project specific header files
#include "gui/mainwindow.h"
#include "core/game.h"
#include "core/gameScene.h"
#include "core/block.h"

App *App::sThis = NULL;


/** Constructor. Load the file given in the command arguments or show the main menu.
*/
App::App()
{
	sThis = this;
	mGame = new Game();
	mMainWindow = new MainWindow(mGame);
	//Vise eller tegne p� bildet
	mMainWindow->show();	
	mMainWindow->getView()->setScene(mGame->getScene());
	mMainWindow->resize(mGame->getMapSize());

	//Start Meny
	startGameMenu();

	mBlock = mGame->getBlock();
	mScene = mGame->getScene();

	connect(mBlock, SIGNAL(sigGameOver()), this, SLOT(gameOverReciever()));
	connect(mScene, SIGNAL(sigKeyTestPressed()), this, SLOT(keyTestReciever()));
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

GameScene *
App::getScene() const
{
	return mGame->getScene();
}

void
App::startGameMenu()
{
	QMessageBox startDialog;

	startDialog.setIcon(QMessageBox::Question);
	startDialog.setText(QString("Vil du spille?"));

	QPushButton *yesButton = startDialog.addButton("Ja", QMessageBox::YesRole);
	startDialog.addButton(QString("Nei (Avslutt spillet)"), QMessageBox::RejectRole);

	startDialog.exec();

	if (startDialog.clickedButton() == yesButton)
	{
		qDebug() << "Game started";
		mGame->gameStart();
	}
	else
	{
		exit(0);
	}
}

void
App::gameOverReciever()
{
	QMessageBox gameOverDialog;

	gameOverDialog.setIcon(QMessageBox::Warning);
	gameOverDialog.setText(QString("Game over!"));

	QPushButton *restartButton = gameOverDialog.addButton(QString("Start på nytt"), QMessageBox::AcceptRole);
	gameOverDialog.setDefaultButton(restartButton);
	gameOverDialog.addButton(QString("Avslutt spillet"), QMessageBox::RejectRole);

	gameOverDialog.exec();

	if (gameOverDialog.clickedButton() == restartButton)
	{
		mGame->restart();
	}
	else
	{
		exit(0);
	}
}

int
App::keyTestReciever()
{
	qDebug() << "Test button pressed!";

	gameOverReciever();

	return 0;
}