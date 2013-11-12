/*
NAME:	Breanna Henry
DATE:	11/3/2013
PURP:	Barbie Head Tiles
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef BARBIEHEAD_TILE_H
#define BARBIEHEAD_TILE_H

//Inherit from Tile
#include "Tile.h"


class BarbieHeadTile : public Tile
{
public:
	BarbieHeadTile(const char* textureName = RES_TILE_BARBIEHEAD);
	virtual ~BarbieHeadTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
