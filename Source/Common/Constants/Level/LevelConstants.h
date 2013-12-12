/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	7/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		Level Constants
MODIFIED:		by Breanna, created by Brad
*/


//DEFINE
#ifndef LEVEL_CONSTANTS_H
#define LEVEL_CONSTANTS_H

//Global enum for the Level's tile types,
//add additional tile types in this enum
enum TileType
{
	TileTypeGround = 1,		//(0000 0001)
	TileTypeLegoBrick = 2,	//(0000 0010)
	TileTypeBarbieHead = 4,	//(0000 0100)
	TileTypeToyCar = 8,		//(0000 1000)
	TileTypeBlanket = 16,	//(0001 0000)
	TileTypeBearicade = 32,	//(0010 0000)
	TileTypeCastle = 128,

	//This Count MUST now be manually updated when a new tile is added
	TileTypeCount = 6,
	TileTypeUnknown = -1
};

//Pickup Enum
enum PickupType
{
	PickupTypeGold = 64,	//(0100 0000);

	//This Count MUST now be manually updated when a new pickup is added
	PickupTypeCount = 1,
	PickupTypeUnknown = -1
};

//Level editor screen name
extern const char* LEVEL_EDITOR_SCREEN_NAME;

//Empty Level Constants
extern const int EMPTY_LEVEL_TILE_SIZE;
extern const int EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX;

#endif
