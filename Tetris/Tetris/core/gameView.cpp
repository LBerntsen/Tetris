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
	if (Qt::LeftArrow == event->key())
	{
		emit sigKeyLeftPressed();
	}
	else if (Qt::RightArrow == event->key())
	{
		emit sigKeyRightPressed();
	}
}