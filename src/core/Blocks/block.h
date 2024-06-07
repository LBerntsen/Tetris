//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef BLOCK_H
#define BLOCK_H

#include "core/blockshape.h"

class Block : public BlockShape
{
public:
    Block(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, int aNumRows, int aNumCols);
    ~Block();

private:
    void createBlock(GameScene *aScene, QColor aColor, int aX, int aY) override;
};

#endif //BLOCK_H
