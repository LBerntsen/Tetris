#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>

class GameScene : public QGraphicsScene
{
	Q_OBJECT
public:
	GameScene();
	virtual ~GameScene();

signals:
	void sigKeyLeftPressed();
	void sigKeyRightPressed();
	void sigKeyDownPressed();
	void sigKeyTestPressed();

private:
	void keyPressEvent(QKeyEvent *event);
	
};
#endif