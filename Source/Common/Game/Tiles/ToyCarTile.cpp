//SEE ToyCarTILE.H

//INCLUDE
#include "ToyCarTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
ToyCarTile::ToyCarTile(const char* textureName) : 
			Tile(TileTypeToyCar, textureName, true, false, false, 3)
{
	//This tile is walkable
	//This tile cannot shoot (is not a tower)
	//This tile is not destructable
	//This tile costs 3 gold
}

//DESTRUCTOR---------------------------------------
ToyCarTile::~ToyCarTile()
{

}

//GET TILE SPEED-----------------------------------
float ToyCarTile::getTileSpeed()
{
	//Tile Super slows the enemies
	return 0.2f;
}

//GET TYPE-----------------------------------------
const char* ToyCarTile::getType()
{
    return TILE_TOYCAR_TYPE;
}
