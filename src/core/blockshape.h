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
    BlockShape(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval);
    ~BlockShape();
    void startBlock();
    void keyLeftReciever();
    void keyRightReciever();
    void keyDownReciever();
    void rotateCCW();
    void rotateCW();

signals:
    void sigPlaceTiles(QList<int> aXListIndexes, QList<int> aYListIndexes, QList<QGraphicsItem *> aBlockTiles);

private:
    virtual void createBlock(QColor aColor) = 0;
    void createGroup();
    virtual void setPivotPoint() = 0;
    void placeTiles();
    QColor randomColor();

    QTimer *mTimer;

protected:
    int getXListIndex() const;
    int getYListIndex() const;

    int mTileSize;
    int mNumRows;
    int mNumCols;
    int mTimerInterval;
    QList<Tile *> mTiles;
    QGraphicsItemGroup *mTileGroup;
    QList<QList<QGraphicsItem *> *> mGridRowList;
    GameScene *mScene;
};

#endif //BLOCKSHAPE_H
