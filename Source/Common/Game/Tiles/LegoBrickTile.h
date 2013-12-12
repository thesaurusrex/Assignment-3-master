/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	11/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		Lego brick tile
MODIFIED:		12/10/2013
				-Added "Tower" type stuff
*/


//DEFINE
#ifndef LEGOBRICK_TILE_H
#define LEGOBRICK_TILE_H

//INCLUDE
#include "Tile.h"

class LegoBrickTile : public Tile
{
public:
	LegoBrickTile(const char* textureName = RES_TILE_LEGOBRICK);
	virtual ~LegoBrickTile();
  
	//Speed
	float getTileSpeed();

    //Return the type of the tile
    const char* getType();
};

#endif
