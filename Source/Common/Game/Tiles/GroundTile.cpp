//SEE GROUNDTILE.H

//INCLUDE
#include "GroundTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
GroundTile::GroundTile(const char* textureName) : 
			Tile(TileTypeGround, textureName, true, false, false, 0)
{
	//Walkable
	//not tower
	//not destructable
	//costs is free
}

//DESTRUCTOR---------------------------------------
GroundTile::~GroundTile()
{

}

//GET TYPE-----------------------------------------
const char* GroundTile::getType()
{
    return TILE_GROUND_TYPE;
}
