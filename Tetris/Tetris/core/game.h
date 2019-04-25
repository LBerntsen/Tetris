#ifndef GAME_H 
#define GAME_H

#include <QObject>
#include <QString>
#include <QSize>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>

class Block;
class GameScene;

class Game : public QObject
{
	Q_OBJECT

public:
	Game();
	virtual ~Game();
	GameScene *getScene();
	QSize getMapSize() const;
	int getTileSize() const;
	int getNumRows() const;
	int getNumCols() const;
	Block* getBlock();
	void makeGrid(int aTileSize, int aRow, int aCols);
	void gameStart();
	void restart();

private:
	GameScene *mScene;
	QSize mSize;
	Block *mBlock;
	QList<QList<QGraphicsItem *> *> mGridRowList;
	int mTimerInterval;


};

#endif
