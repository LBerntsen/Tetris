#ifndef GAME_H 
#define GAME_H

#include <QObject>
#include <QString>
#include <QSize>

class BlockShape;
class GameScene;

class QGraphicsItem;

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
	void makeGrid(int aTileSize, int aRow, int aCols);
	void gameStart();
	void restart();

public slots:
	int keyLeftReciever();
	int keyRightReciever();
	void keyDownReciever();
	void keyQReciever();
	void keyEReciever();
	void placeTilesReciever(QList<int> aXListIndexes, QList<int> aYListIndexes, QList<QGraphicsItem *> aBlockTiles);


signals:
	void sigGameOver();

private:
	void makeBlockRowList(int aNumRows, int aNumCols);
	void placeTile(int aXListIndex, int aYListIndex, QGraphicsItem *aBlockTile);
	void manageRows();
	int checkRow(int aRow);
	int removeRow(int aRow);
	void moveRowDown(int aRemoved);
	void newBlock();

	GameScene *mScene;
	QSize mSize;
	BlockShape *mBlock;
	QList<QList<QGraphicsItem *> *> mGridRowList;
	QList<QList<QGraphicsItem *> *> mBlockRowList;
	int mTimerInterval;
};

#endif
