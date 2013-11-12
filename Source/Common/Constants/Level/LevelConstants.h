/*
NAME:	Bradley Flood
DATE:	2013-03-07
PURP:	Level Constants
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef LEVEL_CONSTANTS_H
#define LEVEL_CONSTANTS_H

//Global enum for the Level's tile types,
//add additional tile types in this enum
enum TileType
{
  TileTypeGround = 0,
  TileTypeLegoBrick = 1,
  TileTypeBarbieHead = 2,
  TileTypeToyCar = 3,
  TileTypeBlanket = 4,
  TileTypeBearicade = 5,
  TileTypeUnknown,
  TileTypeCount
};

//Level editor screen name
extern const char* LEVEL_EDITOR_SCREEN_NAME;

//Empty Level Constants
extern const int EMPTY_LEVEL_TILE_SIZE;
extern const int EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX;

#endif
