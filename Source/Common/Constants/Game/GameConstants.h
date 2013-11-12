/*
NAME:	Bradley Flood
DATE:	7/3/2013
PURP:	Game Constants
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

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
extern const int TILE_PADDING;

//Player Constants
extern const char* PLAYER_TYPE;
extern const int PLAYER_SIZE;
extern const float PLAYER_SPEED;
extern const OpenGLColor PLAYER_INSIDE_COLOR;
extern const OpenGLColor PLAYER_OUTLINE_COLOR;

#endif 