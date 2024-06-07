//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef REVERSEZBLOCK_H
#define REVERSEZBLOCK_H

#include "core/blockShape.h"

class ReverseZBlock : public BlockShape{
public:
    ReverseZBlock(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval);
    ~ReverseZBlock();

private:
    void createBlock(QColor aColor) override;
    void setPivotPoint() override;
};

#endif //REVERSEZBLOCK_H
