#ifndef BLOCK_H
#define BLOCK_H

#include "core/gameScene.h"

#include <QObject>
#include <QGraphicsItem>
#include <QColor>

class Block : public QObject
{
	Q_OBJECT
public:
	Block(int aTileSize, int aNumCols, GameScene *aScene);
	virtual ~Block();
	void start();

private:
	QColor randomColor();
	QGraphicsItem *mBlock;
	int mTileSize;
	int mNumCols;
	GameScene *mScene;

public slots:
	int keyLeftReciever();
	int keyRightReciever();

};
#endif