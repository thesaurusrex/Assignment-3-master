/*
NAME:	Breanna Henry
DATE:	11/3/2013
PURP:	Toy Car Tiles
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef TOYCAR_TILE_H
#define TOYCAR_TILE_H

//Inherit from Tile
#include "Tile.h"


class ToyCarTile : public Tile
{
public:
	ToyCarTile(const char* textureName = RES_TILE_TOYCAR);
	virtual ~ToyCarTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
