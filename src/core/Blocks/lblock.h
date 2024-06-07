//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef LBLOCK_H
#define LBLOCK_H

#include "core/blockShape.h"

class LBlock : public BlockShape{
public:
    LBlock(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval);
    ~LBlock();

private:
    void createBlock(QColor aColor) override;
    void setPivotPoint() override;
};

#endif //LBLOCK_H
