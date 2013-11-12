/*
NAME:	Breanna Henry
DATE:	11/3/2013
PURP:	Lego Brick Tiles
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef LEGOBRICK_TILE_H
#define LEGOBRICK_TILE_H

//Inherit from Tile
#include "Tile.h"


class LegoBrickTile : public Tile
{
public:
	LegoBrickTile(const char* textureName = RES_TILE_LEGOBRICK);
	virtual ~LegoBrickTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
