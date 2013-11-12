//SEE LEGOBRICKTILE.H

#include "LegoBrickTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


//CONSTRUCTOR--------------------------------------
LegoBrickTile::LegoBrickTile(const char* textureName) : Tile(TileTypeLegoBrick, textureName, false)
{
	//NOT Walkable
}

//DESTRUCTOR---------------------------------------
LegoBrickTile::~LegoBrickTile()
{

}

//GET TYPE-----------------------------------------
const char* LegoBrickTile::getType()
{
    return TILE_LEGOBRICK_TYPE;
}
