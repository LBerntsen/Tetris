//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef BLOCKSHAPE_H
#define BLOCKSHAPE_H

#include <QObject>
#include <QTimer>

class GameScene;
class Tile;

class QGraphicsItem;
class QGraphicsItemGroup;

class BlockShape : public QObject{
    Q_OBJECT
public:
    BlockShape(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, int aNumRows, int aNumCols);
    ~BlockShape();
    void startBlock(GameScene *aScene, int aTimerInterval, int aX, int aY);
    void keyLeftReciever();
    void keyRightReciever();
    void keyDownReciever();

signals:
    void sigPlaceTiles(QList<int> aXListIndexes, QList<int> aYListIndexes, QList<QGraphicsItem *> aBlockTiles);

private:
    virtual void createBlock(GameScene *aScene, QColor aColor, int aX, int aY) = 0;
    void placeTiles();
    QColor randomColor();

    QTimer *mTimer;

protected:
    int getXListIndex() const;
    int getYListIndex() const;

    int mTileSize;
    int mNumRows;
    int mNumCols;
    QList<Tile *> mTiles;
    QGraphicsItemGroup *mTileGroup;
    QList<QList<QGraphicsItem *> *> mGridRowList;
};

#endif //BLOCKSHAPE_H
