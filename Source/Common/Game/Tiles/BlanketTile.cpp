//SEE BlanketTILE.H

#include "BlanketTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
BlanketTile::BlanketTile(const char* textureName) : Tile(TileTypeBlanket, textureName, TRUE)
{
	//Walkable
}

//DESTRUCTOR---------------------------------------
BlanketTile::~BlanketTile()
{

}

//GET TYPE-----------------------------------------
const char* BlanketTile::getType()
{
    return TILE_BLANKET_TYPE;
}
