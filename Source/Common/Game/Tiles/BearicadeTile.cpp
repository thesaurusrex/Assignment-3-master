//SEE BearicadeTILE.H

#include "BearicadeTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
BearicadeTile::BearicadeTile(const char* textureName) : Tile(TileTypeBearicade, textureName, false)
{
	//NOT Walkable
}

//DESTRUCTOR---------------------------------------
BearicadeTile::~BearicadeTile()
{

}

//GET TYPE-----------------------------------------
const char* BearicadeTile::getType()
{
    return TILE_BEARICADE_TYPE;
}
