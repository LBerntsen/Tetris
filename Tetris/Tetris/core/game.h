#ifndef GAME_H 
#define GAME_H

#include <QString>
#include <QSize>

class GameScene;

class Game
{
public:
	Game();
	virtual ~Game();
	GameScene *getScene();
	QSize getMapSize() const;
	void makeGrid(int aTileSize, int aRow, int aCols);
	void moveLeft();
	void moveRight();

private:
	GameScene *mScene;
	QSize mSize;

};

#endif
