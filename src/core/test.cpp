//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "test.h"
#include "tile.h"
#include "gameScene.h"

#include <QColor>
#include <QGraphicsRectItem>

test::test(int aTileSize) : BlockShape(aTileSize)
{

}

test::~test(){}

void test::createBlock(GameScene *aScene, int aX, int aY)
{
    QColor color = randomColor();

    Tile *tile1 = new Tile(aX, aY, 0, 0, mTileSize, color);
    Tile *tile2 = new Tile(aX, aY, 1, 0, mTileSize, color);

    mTiles.append(tile1);
    mTiles.append(tile2);
    aScene->addItem(tile1->getTile());
    aScene->addItem(tile2->getTile());
}

int
test::keyLeftReciever()
{
    int i = 0;
    return i;
}
int
test::keyRightReciever()
{
    int i = 0;
    return i;
}
int
test::keyDownReciever()
{
    int i = 0;
    return i;
}
int
test::moveBlockDown()
{
    int i = 0;
    return i;
}
