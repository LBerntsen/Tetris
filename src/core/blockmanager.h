//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef BLOCKMANAGER_H
#define BLOCKMANAGER_H

#include <QObject>

class GameScene;
class Shape;

class QGraphicsItem;
class QTimer;

class BlockManager : public QObject{
public:
    BlockManager(int aTileSize, int aNumCols, int aNumRows, int aTimerInterval, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList);
    ~BlockManager();
    void start();
    void reset();
    void newBlock();

signals:
    void sigPlaceTiles(QList<int> aXListIndexes, QList<int> aYListIndexes, QList<QGraphicsItem *> aBlockTiles);

private:
    QColor randomColor();

    QTimer *mTimer;
    int mTimerInterval;
    Shape *mBlock;
    GameScene *mScene;
    QList<QList<QGraphicsItem *> *> mGridRowList;
    int mTileSize;
    int mNumCols;
    int mNumRows;

public slots:
    int keyLeftReciever();
    int keyRightReciever();
    void keyDownReciever();
    int moveBlockDown();
};

#endif //BLOCKMANAGER_H
