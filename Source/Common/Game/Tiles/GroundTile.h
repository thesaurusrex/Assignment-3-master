/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	11/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		Basic ground tile
MODIFIED:		12/10/2013
				-Added "Tower" type stuff
*/


//DEFINE
#ifndef GROUND_TILE_H
#define GROUND_TILE_H

//INCLUDE
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
