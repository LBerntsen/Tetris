//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef JBLOCK_H
#define JBLOCK_H

#include "core/blockShape.h"

class JBlock : public BlockShape{
public:
    JBlock(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval);
    ~JBlock();

private:
    void createBlock(QColor aColor) override;
    void setPivotPoint() override;
};

#endif //JBLOCK_H
