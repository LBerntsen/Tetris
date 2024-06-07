//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "core/blockShape.h"

class ZBlock : public BlockShape{
public:
    ZBlock(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval);
    ~ZBlock();

private:
    void createBlock(QColor aColor) override;
    void setPivotPoint() override;
};

#endif //ZBLOCK_H
