//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "blockshape.h"

#include <QColor>
#include <QTimer>

BlockShape::BlockShape(int aTileSize)
{
    mTileSize = aTileSize;
    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &BlockShape::moveBlockDown);
}

BlockShape::~BlockShape()
{

}

void
BlockShape::startBlock(GameScene *aScene, int aTimerInterval, int aX, int aY)
{
    createBlock(aScene, aX, aY);
    //mTimer->start(aTimerInterval);
}

QColor
BlockShape::randomColor()
{
    srand(time(NULL));
    QColor color;

    switch(rand() % 5 + 1)
    {
        case 1:
            color = QColor(Qt::magenta);
            break;
        case 2:
            color = QColor(Qt::red);
            break;
        case 3:
            color = QColor(Qt::green);
            break;
        case 4:
            color = QColor(Qt::blue);
            break;
        case 5:
            color = QColor(Qt::yellow);
            break;
        default:
            color = QColor(Qt::black);
            break;
    }

    return color;
}