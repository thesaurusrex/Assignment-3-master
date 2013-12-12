//SEE LEGOBRICKTILE.H

//INCLUDE
#include "LegoBrickTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"

//CONSTRUCTOR--------------------------------------
LegoBrickTile::LegoBrickTile(const char* textureName) : 
				Tile(TileTypeLegoBrick, textureName, true, false, false, 3)
{
	//Walkable
	//Cant shoot
	//not destructable
	//costs 3 gold
}

//DESTRUCTOR---------------------------------------
LegoBrickTile::~LegoBrickTile()
{

}

//GET TYPE-----------------------------------------
const char* LegoBrickTile::getType()
{
    return TILE_LEGOBRICK_TYPE;
}

//GET TILE SPEED-----------------------------------
float LegoBrickTile::getTileSpeed()
{
	//Slightly slows
	return 0.8f;
}