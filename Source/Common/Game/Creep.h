
//DEFINE
#ifndef CREEP_H
#define CREEP_H

//INHERIT
#include "Player.h"
#include "../OpenGL/OpenGLAnimatedTexture.h"

class Creep : public Player
{
public:
	Creep(Level* level, float speed, int health, int damage);
	virtual ~Creep();

	const char* getType();

	void update(double delta);
	void paint();
	void reset();

	void applyDamage(int damage);

protected:
	void handlePlayerCollision(Projectile* projectile);

private:
	//Texture
	OpenGLAnimatedTexture* m_BabyCreep;

	//It has
	float m_Speed;
	int m_Damage;
	int m_Health;
	int m_CreepsDead;

	//Castle?
	int m_CastleHealth;
	int m_RemainingLives;
};

#endif