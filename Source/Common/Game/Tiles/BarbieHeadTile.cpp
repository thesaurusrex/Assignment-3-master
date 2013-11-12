//SEE BarbieHeadTILE.H

#include "BarbieHeadTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
BarbieHeadTile::BarbieHeadTile(const char* textureName) : Tile(TileTypeBarbieHead, textureName, false)
{
	//NOT Walkable
}

//DESTRUCTOR---------------------------------------
BarbieHeadTile::~BarbieHeadTile()
{

}

//GET TYPE-----------------------------------------
const char* BarbieHeadTile::getType()
{
    return TILE_BARBIEHEAD_TYPE;
}
