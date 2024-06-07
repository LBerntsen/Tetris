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
	else if (Qt::Key_Down == event->key())
	{
		emit sigKeyDownPressed();
	}
	else if (Qt::Key_Space == event->key()) //Spacebar for testing m� fjernes n�r spillet er ferdig
	{
		emit sigKeyTestPressed();
	}
	else if(Qt::Key_Q == event->key())
	{
		emit sigKeyQPressed();
	}
	else if(Qt::Key_E == event->key())
	{
		emit sigKeyEPressed();
	}
}