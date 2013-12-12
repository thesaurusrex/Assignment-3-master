/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	7/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		Game Constants
MODIFIED:		by Breanna, created by Brad
*/


//DEFINE
#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

//INCLUDE
#include "../../OpenGL/OpenGLColor.h"

//Game Constants
extern const char* GAME_SCREEN_NAME;

//Tile Constants
extern const char* TILE_GROUND_TYPE;
extern const char* TILE_LEGOBRICK_TYPE;
extern const char* TILE_BARBIEHEAD_TYPE;
extern const char* TILE_TOYCAR_TYPE;
extern const char* TILE_BLANKET_TYPE;
extern const char* TILE_BEARICADE_TYPE;
extern const char* TILE_CASTLE_TYPE;
extern const int TILE_PADDING;
extern int TILE_COST;
extern int TILE_GOLD_COST;

//Player Constants
extern const char* BABYSITTER_TYPE;
extern const int PLAYER_SIZE;
extern int PLAYER_LIVES;
extern float PLAYER_SPEED;
extern int PLAYER_MAX_GOLD;
extern int PLAYER_CURRENT_GOLD;
extern const OpenGLColor PLAYER_INSIDE_COLOR;
extern const OpenGLColor PLAYER_OUTLINE_COLOR;

//Castle Constants
extern const char* CASTLE_TYPE;
extern int CASTLE_HEALTH;

//Enemy Constants
extern const char* CREEP_TYPE;
extern int CREEP_COUNT;
extern int CREEP_HEALTH;
extern int CREEP_DAMAGE;
extern float CREEP_SPEED;

//Pickup Constants
extern const char* PICKUP_TYPE_GOLD;

#endif 