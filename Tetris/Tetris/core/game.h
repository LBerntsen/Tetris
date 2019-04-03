#ifndef GAME_H 
#define GAME_H

#include <QString>
#include <QSize>

class QGraphicsScene;

class Game
{
public:
	Game();
	virtual ~Game();
	QGraphicsScene *getScene();
	QSize getMapSize() const;
	void makeGrid(int aTileSize, int aRow, int aCols);

private:
	QGraphicsScene *mScene;
	QSize mSize;

};

#endif
