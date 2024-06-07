//
// Created by Lukas Berntsen on 07/06/2024.
//

#ifndef TILE_H
#define TILE_H

#include <QColor>

class QGraphicsRectItem;

class Tile {
public:
    Tile(int aXIndex, int aYIndex, int aTileSize, QColor aColor);
    ~Tile();
    QGraphicsRectItem *getTile() const;
    int getXListIndex() const;
    int getYListIndex() const;
private:
    QGraphicsRectItem *mTile;
    int mTileSize;
};

#endif //TILE_H
