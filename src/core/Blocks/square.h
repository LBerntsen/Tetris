//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef SQUARE_H
#define SQUARE_H

#include "core/blockshape.h"

class Square : public BlockShape{
public:
    Square(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval);
    ~Square();

private:
    void createBlock(QColor aColor) override;
    void setPivotPoint() override;
};

#endif //SQUARE_H
