/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	11/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		blanket tile
MODIFIED:		12/10/2013
				-Added "Tower" type stuff
*/


//DEFINE
#ifndef BLANKET_TILE_H
#define BLANKET_TILE_H

//INCLUDE
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
