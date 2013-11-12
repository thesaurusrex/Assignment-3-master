//SEE ToyCarTILE.H

#include "ToyCarTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
ToyCarTile::ToyCarTile(const char* textureName) : Tile(TileTypeToyCar, textureName, false)
{
	//NOT Walkable
}

//DESTRUCTOR---------------------------------------
ToyCarTile::~ToyCarTile()
{

}

//GET TYPE-----------------------------------------
const char* ToyCarTile::getType()
{
    return TILE_TOYCAR_TYPE;
}
