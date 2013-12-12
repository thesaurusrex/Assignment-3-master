/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	12/2/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		THE FREAKIN CASTLE
MODIFIED:		12/11/2013
                -Texture for damges, health
*/


//DEFINE
#ifndef CASTLE_H
#define CASTLE_H

//INCLUDE
#include "PathFinder.h"
#include "GameObject.h"
#include "Projectile.h"
#include "Level.h"
#include "Player.h"

//CLASSES
class Level;
class Tile;
class Creep;

class Castle : public Player
{
public:
	Castle(Level* level);
	~Castle();

	void paint();
	void update(double delta);
  
	//GameObject pure virtual
	const char* getType();

	int getTileCoordinateForPosition(int position);

private:
	//Player pure virtual
	void handlePlayerCollision(Projectile* projectile);

	//Textures
	OpenGLTexture* m_CastleTexture;
	OpenGLTexture* m_CastleTexture2;
	OpenGLTexture* m_CastleTexture3;
	OpenGLTexture* m_CastleTexture4;

	//What it has
	int m_Health;
};

#endif