// Local class header file
#include "core/gameScene.h"

// QT header files
#include <QDebug>
#include <QKeyEvent>

GameScene::GameScene()
{
	
}

GameScene::~GameScene()
{
	
}

void
GameScene::keyPressEvent(QKeyEvent *event)
{
	int key = event->key();
	if (Qt::Key_Left == event->key())
	{
		emit sigKeyLeftPressed();
	} 
	else if (Qt::Key_Right == event->key())
	{
		emit sigKeyRightPressed();
	}
	else if (Qt::Key_Space == event->key()) //Spacebar for testing må fjernes når spillet er ferdig
	{
		emit sigKeyTestPressed();
	}
}