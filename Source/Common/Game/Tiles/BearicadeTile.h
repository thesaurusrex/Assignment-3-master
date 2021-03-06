/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	11/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		Bearicade tile
MODIFIED:		12/10/2013
				-Added "Tower" type stuff
*/


//DEFINE
#ifndef BEARICADE_TILE_H
#define BEARICADE_TILE_H

//INCLUDE
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
