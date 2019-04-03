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

private:
	void keyPressEvent(QKeyEvent *event);
	
};
#endif