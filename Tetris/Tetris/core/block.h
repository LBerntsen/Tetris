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
	Block(int aTileSize, int aNumCols, int aNumRows, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList);
	virtual ~Block();
	void start();
	void removeRow(int aRow);
	void checkRows();

private:
	QColor randomColor();
	QGraphicsItem *mBlock;
	int mTileSize;
	int mNumCols;
	int mNumRows;
	GameScene *mScene;
	QList<QList<QGraphicsItem *> *> mGridRowList;

public slots:
	int keyLeftReciever();
	int keyRightReciever();

};
#endif