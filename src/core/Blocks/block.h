//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef BLOCK_H
#define BLOCK_H

#include "core/blockshape.h"

class Block : public BlockShape
{
public:
    Block(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval);
    ~Block();

private:
    void createBlock(QColor aColor) override;
};

#endif //BLOCK_H
