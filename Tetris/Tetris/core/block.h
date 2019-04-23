#ifndef BLOCK_H
#define BLOCK_H

#include "core/gameScene.h"

#include <QObject>
#include <QGraphicsItem>
#include <QColor>
#include <QTimer>
#include <QList>

class Block : public QObject
{
	Q_OBJECT
public:
	Block(int aTileSize, int aNumCols, int aNumRows, int aTimerInterval, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList);
	virtual ~Block();
	void start();
	void manageRows();
	int checkRow(int aRow);
	int removeRow(int aRow);
	void moveRowDown(int aRemoved);
	void makeBlockRowList(int aNumRows, int aNumCols);

private:
	void newBlock();
	QTimer* mTimer;
	QColor randomColor();
	QGraphicsItem *mBlock;
	GameScene *mScene;
	QList<QList<QGraphicsItem *> *> mGridRowList;
	QList<QList<QGraphicsItem *> *> mBlockRowList;
	int mTileSize;
	int mNumCols;
	int mNumRows;
	int mTimerInterval;
	int getYListIndex();
	int getXListIndex();

public slots:
	int keyLeftReciever();
	int keyRightReciever();
	void keyDownReciever();
	int moveBlockDown();

};
#endif