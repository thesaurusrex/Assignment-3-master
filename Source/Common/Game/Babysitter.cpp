//SEE BABYSITTER.H

//INCLUDE
#include "Babysitter.h"
#include "Level.h"
#include "Tiles/Tile.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Utils/Utils.h"
#include "Creep.h"
#include "../OpenGL/OpenGL.h"
#include "../Game/Game.h"
#include "../Screen Manager/ScreenManager.h"

//Constructor
Babysitter::Babysitter(Level* level) : Player(level), m_Builder(NULL)
{
	//Create texture
	m_Builder = new OpenGLAnimatedTexture("SPRITE_HAMMER", true, 5.0);
}

//Destructor
Babysitter::~Babysitter()
{
	//Remove texture
	if(m_Builder != NULL)
	{
		delete m_Builder;
		m_Builder = NULL;
	}
}

//getType
const char* Babysitter::getType()
{
	return BABYSITTER_TYPE;
}

//update
void Babysitter::update(double delta)
{
    Player::update(delta);
	//Update the animated texture
    m_Builder->update(delta);
}

//paint
void Babysitter::paint()
{
	//Paint the animated texture
	OpenGLRenderer::getInstance()->drawTexture(m_Builder, getX(), getY(), getWidth(), getHeight());
}

//mouseLeftClickUpEvent
void Babysitter::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Get the tile
	Tile* tile = m_Level->getTileForPosition(positionX, positionY);
	
	//Don't mind wether the tile is walkable or not (didn't work on its own)
	if(tile != NULL /*&& tile->isWalkableTile() == true*/)
	{
		//Set the destination tile
		setDestinationTile(tile);
	}
}

//mouseMovementEvent
void Babysitter::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	//Get the tile
	Tile* tile = m_Level->getTileForPosition(positionX, positionY);

	//If there is a tile (once again tried to have it unnaffected by walkable
	if(tile != NULL /*&& tile->isWalkableTile() == true*/)
	{
		//Set the level's selected tile, this call is optional
		//Don't put it in if you dont want the reticle
		m_Level->setSelectedTileIndex(m_Level->getTileIndexForTile(tile));
	}
}

//keyUpEvent
void Babysitter::keyUpEvent(int keyCode)
{
	//My babysitter does not shoot, the towers do

	if(keyCode == KEYCODE_RETURN)
	{
		
	}
}

//handlePlayerCollision
void Babysitter::handlePlayerCollision(Projectile* projectile)
{
	//Babysitter is not affected by collision, nut needs this because of pure virtual
}