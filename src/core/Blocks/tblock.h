//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef TBLOCK_H
#define TBLOCK_H

#include "core/blockShape.h"

class TBlock : public BlockShape{
public:
    TBlock(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval);
    ~TBlock();

private:
    void createBlock(QColor aColor) override;
};

#endif //TBLOCK_H
