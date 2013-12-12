/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	11/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		Babysitter
MODIFIED:		12/10/2013
				-Added "Tower" type stuff
                12/11/2013
                -Animated textures
*/


//DEFINE
#ifndef Babysitter_H
#define Babysitter_H

//INHERIT
#include "Player.h"
#include "../OpenGL/OpenGLAnimatedTexture.h"

class Babysitter : public Player
{
public:
	Babysitter(Level* level);
	~Babysitter();

	const char* getType();

	void paint();
    void update(double delta);

	void mouseLeftClickUpEvent(float positionX, float positionY);
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	//Use this to palce selected tile and subtract gold?
	void keyUpEvent(int keyCode);

private:
	//Pure virtual, so it has to be here
	void handlePlayerCollision(Projectile* projectile);

	//Texture
	OpenGLAnimatedTexture* m_Builder;
};

#endif