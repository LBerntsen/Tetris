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

class BlockShape : public QObject{
    Q_OBJECT
public:
    BlockShape(int aTileSize);
    ~BlockShape();
    void startBlock(GameScene *aScene, int aTimerInterval, int aX, int aY);

signals:
    void sigPlaceTiles(QList<int> aXListIndexes, QList<int> aYListIndexes, QList<QGraphicsItem *> aBlockTiles);

public slots:
    virtual int keyLeftReciever() = 0;
    virtual int keyRightReciever() = 0;
    virtual int keyDownReciever() = 0;
    virtual int moveBlockDown() = 0;

private:
    virtual void createBlock(GameScene *aScene, int aX, int aY) = 0;

    QTimer *mTimer;

protected:
    QColor randomColor();

    int mTileSize;
    QList<Tile *> mTiles;
    QList<QList<QGraphicsItem *> *> mGridRowList;
};

#endif //BLOCKSHAPE_H
