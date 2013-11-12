/*
NAME:	Breanna Henry
DATE:	11/3/2013
PURP:	Blanket Tiles
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef BLANKET_TILE_H
#define BLANKET_TILE_H

//Inherit from Tile
#include "Tile.h"


class BlanketTile : public Tile
{
public:
	BlanketTile(const char* textureName = RES_TILE_BLANKET);
	virtual ~BlanketTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
