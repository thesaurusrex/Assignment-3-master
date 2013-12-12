/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	11/27/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		Gold Pickups
MODIFIED:		Date of creation
*/


//DEFINE
#ifndef GOLD_PICKUP_H
#define GOLD_PICKUP_H

//INCLUDE
#include "Pickup.h"
#include "../../OpenGL/OpenGL.h"

class GoldPickup : public Pickup
{
public:
	GoldPickup(int goldCount);
	~GoldPickup();

	void paint();

	const char* getType();

	int getGoldCount();

private:
	int m_GoldCount;

	//Texture
	OpenGLTexture* m_GoldTexture;
};

#endif