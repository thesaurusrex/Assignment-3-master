/*
NAME:	Bradley Flood
DATE:	7/3/2013
PURP:	Ground Tiles
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef GROUND_TILE_H
#define GROUND_TILE_H

//Inherit from Tile
#include "Tile.h"


class GroundTile : public Tile
{
public:
	GroundTile(const char* textureName = RES_TILE_GROUND);
	virtual ~GroundTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
