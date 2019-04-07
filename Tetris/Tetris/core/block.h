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
	Block(int aTileSize, int aNumCols);
	virtual ~Block();
	void start(GameScene *aScene);

private:
	QColor randomColor();
	QGraphicsItem *mBlock;
	int tileSize;
	int numCols;

public slots:
	int keyLeftReciever();
	int keyRightReciever();

};
#endif