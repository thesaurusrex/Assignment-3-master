//SEE PICKUP.H

#include "Pickup.h"

//Constructor
Pickup::Pickup(PickupType pickupType) :
	m_PickupType(pickupType)
{
	//Maybe put random stuff here to generate during game?
}

//Destructor
Pickup::~Pickup()
{

}

//Update
void Pickup::update(double delta)
{
	//Or here?
}

//Reset
void Pickup::reset()
{
	//When one is picked up?
}

//getPickupType
PickupType Pickup::getPickupType()
{
	return m_PickupType;
}