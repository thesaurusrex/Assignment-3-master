//SEE CASTLE.H

#include "Castle.h"
#include "PathNode.h"
#include "Player.h"
#include "Level.h"
#include "Tiles/Tile.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "../Input/Input.h"
#include "Creep.h"
#include "../OpenGL/OpenGL.h"
#include "../Screen Manager/ScreenManager.h"

Castle::Castle(Level* level) : 
		Player(level), 
		m_CastleTexture(NULL),
		m_CastleTexture2(NULL),
		m_CastleTexture3(NULL),
		m_CastleTexture4(NULL)
{
	//Create castle textures
	m_CastleTexture = new OpenGLTexture("Tile_TheCastleUnharmed");
	setSize(m_CastleTexture->getSourceWidth(), m_CastleTexture->getSourceHeight());

	m_CastleTexture2 = new OpenGLTexture("Tile_TheCastleMediumDamage");
	//setSize(m_CastleTexture2->getSourceWidth(), m_CastleTexture2->getSourceHeight());

	m_CastleTexture3 = new OpenGLTexture("Tile_TheCastleLotsDamage");
	//setSize(m_CastleTexture3->getSourceWidth(), m_CastleTexture3->getSourceHeight());

	m_CastleTexture4 = new OpenGLTexture("Tile_TheCastleNearDeath");
	//setSize(m_CastleTexture4->getSourceWidth(), m_CastleTexture4->getSourceHeight());
	
	//Initialize health
	m_Health = CASTLE_HEALTH;
}

Castle::~Castle()
{
	//Delete the rediculous amount of textures
	if(m_CastleTexture != NULL)
	{
		delete m_CastleTexture;
		m_CastleTexture = NULL;
	}
	if(m_CastleTexture2 != NULL)
	{
		delete m_CastleTexture2;
		m_CastleTexture2 = NULL;
	}
	if(m_CastleTexture3 != NULL)
	{
		delete m_CastleTexture3;
		m_CastleTexture3 = NULL;
	}
	if(m_CastleTexture4 != NULL)
	{
		delete m_CastleTexture4;
		m_CastleTexture4 = NULL;
	}
}

void Castle::paint()
{
	//Here goes! Everyone loves if statements in the paint function!

	//If the castle is unharmed
	if(m_Health == 20)
	{
		OpenGLRenderer::getInstance()->drawTexture(m_CastleTexture, getX(), getY());
	}
	//If the health is between 19 and 15
	else if(m_Health < 20  && m_Health >= 15)
	{
		delete m_CastleTexture;
		OpenGLRenderer::getInstance()->drawTexture(m_CastleTexture2, getX(), getY());
	}
	//If the health is between 14 and 2
	else if(m_Health < 15 && m_Health > 2)
	{
		OpenGLRenderer::getInstance()->drawTexture(m_CastleTexture3, getX(), getY());
	}
	//If two or less
	else
	{
		OpenGLRenderer::getInstance()->drawTexture(m_CastleTexture4, getX(), getY());
	}
}

void Castle::update(double delta)
{
	
}

const char* Castle::getType()
{
	return CASTLE_TYPE;
}

void Castle::handlePlayerCollision(Projectile* projectile)
{
	
}