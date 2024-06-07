//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef TEST_H
#define TEST_H

#include "blockshape.h"

class test : public BlockShape{
public:
    test(int aTileSize);
    ~test();

private:
    void createBlock(GameScene *aScene, int aX, int aY) override;

public slots:
    int keyLeftReciever() override;
    int keyRightReciever() override;
    int keyDownReciever() override;
    int moveBlockDown() override;
};



#endif //TEST_H
