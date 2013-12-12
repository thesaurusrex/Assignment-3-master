//SEE BarbieHeadTILE.H

//INCLUDE
#include "BarbieHeadTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
BarbieHeadTile::BarbieHeadTile(const char* textureName) : 
				Tile(TileTypeBarbieHead, textureName, false, true, false, 5)
{
	//NOT Walkable
	//can shoot (is a tower)
	//not destructable
	//costs 5 gold
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
