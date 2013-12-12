//SEE GOLDPICKUP.H

//INCLUDE
#include "GoldPickup.h"


//Constructor
GoldPickup::GoldPickup(int goldCount) : 
	Pickup(PickupTypeGold),
	m_GoldTexture(NULL)
{
	//Create the texture
	m_GoldTexture = new OpenGLTexture("PICKUP_Gold");

	//The size should be that of the texture you use for the pickup
	setSize(58.0f, 58.0f);
}

//Destructor
GoldPickup::~GoldPickup()
{
	//Delete the texture
	if(m_GoldTexture != NULL)
	{
		delete m_GoldTexture;
		m_GoldTexture = NULL;
	}
}

//Paint
void GoldPickup::paint()
{
	//Paint the texture
	OpenGLRenderer::getInstance()->drawTexture(m_GoldTexture, getX(), getY(), getWidth(), getHeight(), false);
}

//getType
const char* GoldPickup::getType()
{
	return PICKUP_TYPE_GOLD;
}

//getGoldCount
int GoldPickup::getGoldCount()
{
	return m_GoldCount;
}