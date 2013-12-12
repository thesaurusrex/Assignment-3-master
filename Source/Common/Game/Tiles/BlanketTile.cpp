//SEE BlanketTILE.H

//INCLUDE
#include "BlanketTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
BlanketTile::BlanketTile(const char* textureName) : 
			Tile(TileTypeBlanket, textureName, false, false, false, 1)
{
	//Not Walkable
	//cant shoot
	//cant be destroyed
	//costs 1 gold
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
