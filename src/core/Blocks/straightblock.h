//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef STRAIGHTBLOCK_H
#define STRAIGHTBLOCK_H

#include "core/blockShape.h"

class StraightBlock : public BlockShape{
public:
    StraightBlock(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval);
    ~StraightBlock();

private:
    void createBlock(QColor aColor) override;
    void setPivotPoint() override;
};

#endif //STRAIGHTBLOCK_H
