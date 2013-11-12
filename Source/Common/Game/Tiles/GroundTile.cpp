//SEE GROUNDTILE.H

#include "GroundTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
GroundTile::GroundTile(const char* textureName) : Tile(TileTypeGround, textureName, true)
{
	//Walkable
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
