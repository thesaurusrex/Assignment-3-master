/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	11/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		ToyCarTile
MODIFIED:		12/10/2013
				-Added "Tower" type stuff
*/


//DEFINE
#ifndef TOYCAR_TILE_H
#define TOYCAR_TILE_H

//INCLUDE
#include "Tile.h"

class ToyCarTile : public Tile
{
public:
	ToyCarTile(const char* textureName = RES_TILE_TOYCAR);
	virtual ~ToyCarTile();
  
	//Tile changes speed
	float getTileSpeed();

    //Return the type of the tile
    const char* getType();
};

#endif
