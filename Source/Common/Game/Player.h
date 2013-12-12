//
//  Player.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "PathFinder.h"
#include "GameObject.h"
#include "Projectile.h"
#include <vector>

class Level;
class Tile;
class Pickup;

class Player : public GameObject, public PathFinderListener, public ProjectileListener
{
public:
	Player(Level* level);
	virtual ~Player();

	//Update, paint and reset methods
	void update(double delta);
	void paint();
	void reset();
  
	//Keep GameObject's pure virtual method, we dont need to reclare it pure
	//virtual, but it makes it easier for inheriting classes to know the Player
	//is an abstract class
	virtual const char* getType() = 0;
  
	//Setter methods for the current and destination tiles
	void setCurrentTile(Tile* tile);
	void setDestinationTile(Tile* tile);

	//Projectile Methods
	void fireProjectile(float x, float y);
	void applyDamage(int damage);

protected:
	//Pickup Method
	void handlePickup(Pickup* pickup);

	//Projectile Listener Methods
	virtual void handlePlayerCollision(Projectile* projectile) = 0;
	virtual void handleBoundsCollision(Projectile* projectile);

	//Pathfinder Listener methods
	void pathFinderFinishedSearching(PathFinder* pathFinder, bool pathWasFound);

	//Pathfinder methods
	PathFinder* getPathFinder();
	void findPath();

	//Animation methods
	float animate(float current, float target, double delta, float speed);
	void startAnimating();
	void stopAnimating();
	bool isAnimating();

	//Friend class level so that it can access the protected members
	friend class Level;

	Level* m_Level;
	PathFinder* m_PathFinder;
	Tile* m_CurrentTile;
	Tile* m_DestinationTile;
	bool m_CanAnimate;
	bool m_AbortAnimation;
	int m_AnimationPathNodeIndex;
	float m_Speed;
	float m_CreepSpeed;
	int m_CurrentGold;
	int m_MaxGold;

	//ADD THIS TO CASTLE CLASS, player has no health/is not damaged
	//int m_Health;

	//ADD THIS TO TOWER CLASS? Player does not shoot!? Wait it does... RAWR
	std::vector<Projectile*> m_Projectiles;
};

#endif