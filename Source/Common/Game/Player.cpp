//SEE PLAYER.H

//INCLUDES TIMES FOREVER
#include "../Screen Manager/ScreenManager.h"
#include "PathNode.h"
#include "Player.h"
#include "Level.h"
#include "Tiles/Tile.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "Projectile.h"
#include "Pickups/Pickup.h"
#include "Pickups/GoldPickup.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>


Player::Player(Level* level)
{
	//Create level object
	m_Level = level;

	//Create a PathFinder object
	m_PathFinder = new PathFinder(level, this);

    //Initialize the current and destination tiles to NULL
    m_CurrentTile = NULL;
    m_DestinationTile = NULL;
    
    //Initialize the animation member variables
    m_CanAnimate = false;
    m_AbortAnimation = false;
    m_AnimationPathNodeIndex = -1;

	//Set the players speed
	m_Speed = PLAYER_SPEED;
	m_CreepSpeed = CREEP_SPEED;

	//Initialize the gold and gold and gold
	m_CurrentGold = PLAYER_CURRENT_GOLD;
	m_MaxGold = PLAYER_MAX_GOLD;

	//ADD HEALTH TO CASTLE
	//m_Health = CASTLE_HEALTH;
    
    //Initialize the player's size
    setSize(PLAYER_SIZE, PLAYER_SIZE);
}

Player::~Player()
{
    //Set the current and desination tiles to NULL
	m_CurrentTile = NULL;
	m_DestinationTile = NULL;

	//Delete the PathFinder
	if(m_PathFinder != NULL)
	{
		delete m_PathFinder;
		m_PathFinder = NULL;
	}
}

void Player::update(double aDelta)
{
    
	//Update the projectiles
	for(int i = 0; i < m_Projectiles.size(); i++)
	{
		if(m_Projectiles.at(i)->getIsActive() == true)
		{
			m_Projectiles.at(i)->update(aDelta);
		}
	}

	//Remove any 'inactive' projectiles from the projectiles vector
	int index = 0;
	while(index != m_Projectiles.size())
	{
		if(m_Projectiles.at(index)->getIsActive() == false)
		{
			Log::debug("Deleting Projectile");
			//Delete the projectile and remove it from the vector
			delete m_Projectiles.at(index);
			m_Projectiles.erase(m_Projectiles.begin() + index);
		}
		else
		{
			index++;
		}
	}

	//Safety check the pathfinder
    if(m_PathFinder->isSearchingPath() == true)
    {
        m_PathFinder->update(aDelta);
    }

	//Handle player animation
	if(isAnimating() == true && m_AnimationPathNodeIndex > -1)
	{
		PathNode* pathNode = m_PathFinder->getPathNodeAtIndex(m_AnimationPathNodeIndex);
		Tile* tile = pathNode != NULL ? pathNode->getTile() : NULL;

		//Safety check that the tile isn't NULL
		if(tile != NULL)
		{
			//Calculate the center of the tile
			float centerX = tile->getX() + (tile->getWidth() - getWidth()) / 2.0f;
			float centerY = tile->getY() + (tile->getHeight() - getHeight()) / 2.0f;

			//Get the tile speed for the tile the player is on
			Tile* playerTile = m_Level->getTileForPosition(getX(), getY());
			float speed = playerTile->getTileSpeed();

			//Next, calculate how much the player should animate this update() call
			//use the animate method to help calculate
			float playerX = animate(getX(), centerX, aDelta, speed);
			float playerY = animate(getY(), centerY, aDelta, speed);
			setPosition(playerX, playerY);

			//Has the player reached the center of the tile?
			if(playerX == centerX && playerY == centerY)
			{
				m_AnimationPathNodeIndex++;

				//Set the current tile's path flag to false
				m_CurrentTile->setIsPath(false);

				//Set the new current tile
				setCurrentTile(tile);

				//Does the tile have a pickup on it?
				if(tile->getPickup() != NULL)
				{
					handlePickup(tile->getPickup());

					//Set the pickup to NULL since it was picked up
					tile->setPickup(NULL);
				}

				//Check to see if we are done animating
				if(m_AnimationPathNodeIndex >= m_PathFinder->getPathSize())
				{
					stopAnimating();
					m_CurrentTile->setIsPath(false);
				}

				//Is the abort animation flag set?
				if(m_AbortAnimation == true)
				{
					//Reset the flag to false
					m_AbortAnimation = false;

					//Begin searching new path
					findPath();
				}
			}
		}
		else
		{
			//Is the abort animation flag set?
			if(m_AbortAnimation == true)
			{
				//Reset the flag to false
				m_AbortAnimation = false;

				//Begin searching new path
				findPath();
			}
		}
	}
}

void Player::paint()
{
	//Cyle through and paint all the 'active' projectiles
	for(int i = 0; i < m_Projectiles.size(); i++)
	{
		if(m_Projectiles.at(i)->getIsActive() == true)
		{
			m_Projectiles.at(i)->paint();
		}
	}
	OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_INSIDE_COLOR);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2);
	OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_OUTLINE_COLOR);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, false);
}

void Player::reset()
{
	//Stop animating the player
	stopAnimating();

	//Reset the path finder
	m_PathFinder->reset();

	//Set the destination tile to NULL
    m_DestinationTile = NULL;

	//Set the player's state to active
	setIsActive(true);
}

//PROJECTILE METHODS***********************************************************************
//ADD TO TOWER CLASS create ammo? create range?
void Player::fireProjectile(float x, float y)
{
	//This need to be for the tiles/tower
	//Safety check that there is some ammo left
	//if(m_Ammo > 0)
	//m_Ammo--;

	//Where is this comming from?

	//Create a new projectile object
	Projectile* projectile = new Projectile(this, 1, 10.0f);
	projectile->setPosition(getX() + (getWidth() / 2.0f), getY() + (getHeight() / 2.0f));
	projectile->setTarget(x, y);
	m_Projectiles.push_back(projectile);

	//Remove after
	Log::debug("Fired Projectile.");
}

//*****ADD TO CASTLE CLASS??? Or creeps? or tower/tile?
void Player::applyDamage(int damage)
{
	//m_CastleHealth = CASTLE_HEALTH;

	//m_Health -= damage;

	//if(m_Level->getTileForCreeps(m_Level->m_Creeps.at(95)) == m_Level->getTileForCastle(m_Level->getCastle()))
	//{
		//m_Health--;

		//if(m_Health == 0)
		//{
			//ScreenManager::getInstance()->switchScreen(YOU_LOSE_SCREEN_NAME);
		//}
	//}


	//m_Health -= damage;

	//if(m_Health <= 0)
	//{
		//m_Health = 0;
		//setIsActive(false);

		//Log::debug("Player is Dead.");
		//GO TO LOSE SCREEN!!!!!
	//}
	//else
	//{
		//Log::debug("Player is Hit. %i health remaining.", m_Health);
	//}
}

void Player::handleBoundsCollision(Projectile* projectile)
{
	Tile* tile = m_Level->getTileForPosition(projectile->getX(), projectile->getY());
	if(tile == NULL)
	{
		projectile->setIsActive(false);

		Log::debug("Projectile went off screen");
	}
}

//PATH FINDER METHODS**********************************************************************
PathFinder* Player::getPathFinder()
{
	return m_PathFinder;
}

void Player::findPath()
{
	m_PathFinder->reset();
	m_PathFinder->findPath(m_CurrentTile, m_DestinationTile);
}

void Player::setCurrentTile(Tile* tile)
{
	//Set the current tile pointer
	m_CurrentTile = tile;
    
	//Center the player's position on the tile
	setPosition(tile->getX() + ((tile->getWidth() - getWidth()) / 2), tile->getY() + ((tile->getHeight() - getHeight()) / 2));
}

void Player::setDestinationTile(Tile* tile)
{
	//Set the destination tile pointer
	m_DestinationTile = tile;

	//Start pathfinding
	if(isAnimating() == false)
	{
		findPath();
	}
	else
	{
		m_AbortAnimation = true;
	}
}

void Player::pathFinderFinishedSearching(PathFinder* pathFinder, bool pathWasFound)
{
	if(pathFinder == m_PathFinder)
	{
		if(pathWasFound == true)
		{
			startAnimating();
		}
		else
		{
			m_PathFinder->reset();
		}
	}
}

//PICKUP METHODS***************************************************************************
void Player::handlePickup(Pickup* pickup)
{
	switch(pickup->getPickupType())
	{
	case PickupTypeGold:
		m_CurrentGold += ((GoldPickup*)pickup)->getGoldCount();
		break;

	default:
		break;
	}
}

//ANIMATION METHODS************************************************************************

float Player::animate(float aCurrent, float aTarget, double aDelta, float speed)
{
	//FOR PLAYER
	if(getType() == BABYSITTER_TYPE)
	{
		float increment = aDelta * PLAYER_SPEED * (aTarget < aCurrent ? -1 : 1) * speed;

		if(fabs(increment) > fabs(aTarget - aCurrent))
		{
			return aTarget;
		}
		else
		{
			aCurrent += increment;
		}
		return aCurrent;
	}

	//FOR CREEPS
	if(getType() == CREEP_TYPE)
	{
		float increment = aDelta * CREEP_SPEED * (aTarget < aCurrent ? -1 : 1) * speed;

		if(fabs(increment) > fabs(aTarget - aCurrent))
		{
			return aTarget;
		}
		else
		{
			aCurrent += increment;
		}
		return aCurrent;
	}
}

void Player::startAnimating()
{
	m_CanAnimate = true;
	m_AnimationPathNodeIndex = 0;
}

void Player::stopAnimating()
{
	m_CanAnimate = false;
	m_AnimationPathNodeIndex = -1;
}

bool Player::isAnimating()
{
    return m_CanAnimate;
}
