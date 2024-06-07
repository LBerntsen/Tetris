#ifndef BLOCK1_H
#define BLOCK1_H

#include "core/gameScene.h"

#include <QObject>
#include <QGraphicsItem>
#include <QColor>
#include <QTimer>
#include <QList>

class Tile;
class BlockShape;

class Block1 : public QObject
{
	Q_OBJECT
public:
	Block1(int aTileSize, int aNumCols, int aNumRows, int aTimerInterval, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList);
	virtual ~Block1();
	void start();
	void resetGame();
	void newBlock();

signals:
	void sigPlaceTiles(QList<int> aXListIndexes, QList<int> aYListIndexes, QList<QGraphicsItem *> aBlockTiles);

private:
	QTimer* mTimer;
	QColor randomColor();
	QList<Tile *> mTiles;
	BlockShape *mBlock;
	GameScene *mScene;
	QList<QList<QGraphicsItem *> *> mGridRowList;
	int mTileSize;
	int mNumCols;
	int mNumRows;
	int mTimerInterval;

public slots:
	int keyLeftReciever();
	int keyRightReciever();
	void keyDownReciever();
	//int moveBlockDown();

};
#endif