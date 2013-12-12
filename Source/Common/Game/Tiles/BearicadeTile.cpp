//SEE BearicadeTILE.H

//INCLUDE
#include "BearicadeTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
BearicadeTile::BearicadeTile(const char* textureName) : 
				Tile(TileTypeBearicade, textureName, false, false, true, 3)
{
	//NOT Walkable
	//cant shoot
	//is destructable
	//costs 3 gold
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
