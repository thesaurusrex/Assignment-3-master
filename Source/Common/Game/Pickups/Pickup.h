/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	11/27/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		Pickups
MODIFIED:		Creation date
*/


//DEFINE
#ifndef PICKUP_H
#define PICKUP_H

//INCLUDE
#include "../GameObject.h"
#include "../../Constants/Constants.h"

class Pickup : public GameObject
{
public:
	Pickup(PickupType pickupType);
	virtual ~Pickup();

	virtual void update(double delta);
	virtual void paint() = 0;
	virtual void reset();

	virtual const char* getType() = 0;

	virtual PickupType getPickupType();

protected:
	PickupType m_PickupType;
};

#endif