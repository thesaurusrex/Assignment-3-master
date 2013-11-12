/*
NAME:	Breanna Henry
DATE:	11/3/2013
PURP:	Bearicade Tiles
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef BEARICADE_TILE_H
#define BEARICADE_TILE_H

//Inherit from Tile
#include "Tile.h"


class BearicadeTile : public Tile
{
public:
	BearicadeTile(const char* textureName = RES_TILE_BEARICADE);
	virtual ~BearicadeTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
