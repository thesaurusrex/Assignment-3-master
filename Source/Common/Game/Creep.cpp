//SEE CREEP.H

//INCLUDE
#include "Creep.h"
#include "Tiles/Tile.h"
#include "Level.h"
#include "Castle.h"
#include "Babysitter.h"
#include "../Constants/Constants.h"
#include "../OpenGL/OpenGL.h"
#include "../Screen Manager/ScreenManager.h"

Creep::Creep(Level* level, float speed, int health, int damage) : Player(level)
{
	m_BabyCreep = new OpenGLAnimatedTexture("SPRITE_CREEP_BABY", true, 5.0);
	m_Speed = speed;
	m_Health = health;
	m_Damage = damage;

	//inizialize dead creeps
	m_CreepsDead = 0;

	//Castle?
	m_CastleHealth = CASTLE_HEALTH;
	m_RemainingLives = PLAYER_LIVES;
}

Creep::~Creep()
{

}

const char* Creep::getType()
{
	return CREEP_TYPE;
}

void Creep::update(double delta)
{
	//Update the player
	Player::update(delta);

	//Tell the creeps to attack the tower
	setDestinationTile(m_Level->getTileForPlayer(m_Level->getCastle()));

	//Update the animated texture
    m_BabyCreep->update(delta);
    
	//Get the pointer to tiles
    Tile* castleTile = m_Level->getTileForIndex(95);

	//Get the tile for the creep
    Tile* creepTile = m_Level->getTileForPlayer(this);
	
	//If a creep is on the castle tile
    if(castleTile == creepTile)
    {
		//Add a dead Creep
		m_CreepsDead += 1;

		//Subtract one from the castle health
		m_CastleHealth -= m_Damage *= m_CreepsDead;

		//Kill the creep
		setIsActive(false);
        
		//If the castle health reaches zero,
		if(m_CastleHealth == 0)
		{
			//take away one life
			m_RemainingLives -= 1;

			//If player has 3, 2, or 1 lives
			if(m_RemainingLives == 3 || 2 || 1)
			{
				//Reset the level
				m_Level->reset();
			}
			else
			{
				//You lose
				ScreenManager::getInstance()->switchScreen(YOU_LOSE_SCREEN_NAME);
			}
		}
	}
}

void Creep::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BabyCreep, getX(), getY(), getWidth(), getHeight(), false);
}

void Creep::reset()
{
	Player::reset();
	setDestinationTile(m_Level->getTileForPlayer(m_Level->getCastle()));
}

void Creep::applyDamage(int damage)
{
		
}

void Creep::handlePlayerCollision(Projectile* projectile)
{
	//This doesn't work either
	//Because of projectile?
	//if(m_CurrentTile == m_DestinationTile)
	//{
		//m_CastleHealth--;
	//}
}