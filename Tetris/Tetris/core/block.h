#ifndef BLOCK_H
#define BLOCK_H

#include "core/gameScene.h"

#include <QObject>
#include <QGraphicsItem>
#include <QColor>
#include <QTimer>

class Block : public QObject
{
	Q_OBJECT
public:
	Block(int aTileSize, int aNumCols, int aNumRows, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList);
	virtual ~Block();
	void start();
	void removeRow(int aRow);
	int checkRows();
	void startMoveDownTimer(int aSeconds);

private:
	QTimer* mTimer;
	QColor randomColor();
	QGraphicsItem *mBlock;
	GameScene *mScene;
	QList<QList<QGraphicsItem *> *> mGridRowList;
	QList<QList<QGraphicsItem *> *> mBlockRowList;
	int mTileSize;
	int mNumCols;
	int mNumRows;

public slots:
	int keyLeftReciever();
	int keyRightReciever();
	int moveBlockDown();

};
#endif