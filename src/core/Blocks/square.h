//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef SQUARE_H
#define SQUARE_H

#include "core/blockshape.h"

class Square : public BlockShape{
public:
    Square(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, int aNumRows, int aNumCols);
    ~Square();

private:
    void createBlock(GameScene *aScene, QColor aColor, int aX, int aY) override;
};

#endif //SQUARE_H
