//SEE GAMECONSTANTS.H


//INCLUDE
#include "GameConstants.h"

//Game Constants
const char* GAME_SCREEN_NAME = "Game";

//Tile Constants
const char* TILE_GROUND_TYPE = "Tile_Ground";
const char* TILE_LEGOBRICK_TYPE = "Tile_LegoBrick";
const char* TILE_BARBIEHEAD_TYPE = "Tile_BarbieHead";
const char* TILE_TOYCAR_TYPE = "Tile_ToyCar";
const char* TILE_BLANKET_TYPE = "Tile_Blanket";
const char* TILE_BEARICADE_TYPE = "Tile_Bearicade";
const char* TILE_CASTLE_TYPE = "Tile_Castle";
const int TILE_PADDING = 2;
int TILE_COST = 10;
int TILE_GOLD_COST = 1;

//Player Constants
const char* BABYSITTER_TYPE = "Babysitter";
int PLAYER_LIVES = 3;
const int PLAYER_SIZE = 48;
float PLAYER_SPEED = 300.0f;
int PLAYER_MAX_GOLD = 100;
int PLAYER_CURRENT_GOLD = 5;
const OpenGLColor PLAYER_INSIDE_COLOR = OpenGLColor(0.0f, 0.0f, 0.0f, 1.0f);
const OpenGLColor PLAYER_OUTLINE_COLOR = OpenGLColor(1.0f, 1.0f, 1.0f, 1.0f);

//Castle Constants
const char* CASTLE_TYPE = "Castle";
int CASTLE_HEALTH = 1;

//Enemy Constants
const char* CREEP_TYPE = "Creep";
int CREEP_COUNT = 10;
int CREEP_HEALTH = 10;
int CREEP_DAMAGE = 1;
float CREEP_SPEED = 90.0f;

//Pickup Constants
const char* PICKUP_TYPE_GOLD = "Gold";
