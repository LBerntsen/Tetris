#ifndef BLOCK_H
#define BLOCK_H

#include "core/gameScene.h"

#include <QObject>
#include <QGraphicsItem>
#include <QColor>
#include <QTimer>
#include <QList>

class Tile;

class Block : public QObject
{
	Q_OBJECT
public:
	Block(int aTileSize, int aNumCols, int aNumRows, int aTimerInterval, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList);
	virtual ~Block();
	void start();
	void resetGame();
	void newBlock();


signals:
	void sigPlaceTiles(QList<int> aXListIndexes, QList<int> aYListIndexes, QList<QGraphicsItem *> aBlockTiles);

private:
	QTimer* mTimer;
	QColor randomColor();
	QList<Tile *> mTiles;
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
	int moveBlockDown();

};
#endif