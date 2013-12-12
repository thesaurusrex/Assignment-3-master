/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	7/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		the freakin level yo
MODIFIED:		12/12/2013
                -tried to do stuff for placing towers
*/


//DEFINE
#ifndef LEVEL_H
#define LEVEL_H

//INHERIT
#include "../Constants/Constants.h"
#include <vector>

//CLASSES
class Tile;
class Player;
class Babysitter;
class Creep;
class Pickup;
class Castle;

class Level
{
public:
	Level(bool isEditingLevel = false);
	~Level();
    
	//Update, paint and reset methods
	void update(double delta);
    void paint();
    void reset();
    
    //Save and load
    void load(const char* levelName);
    void save(const char* levelName);
    
    //Input methods
	//maybe put this one in tower?
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
    void mouseLeftClickUpEvent(float positionX, float positionY);
    void keyUpEvent(int keyCode);
	
	//Tile index
    TileType getTileTypeForIndex(int index);
	PickupType getPickupTypeForIndex(int index);
    
	//Tile count methods
    unsigned int getNumberOfTiles();
	unsigned int getNumberOfHorizontalTiles();
	unsigned int getNumberOfVerticalTiles();
    
	//Validate that the tile coordinates passed in are valid
	bool validateTileCoordinates(int coordinatesX, int coordinatesY);
    
	//Converts a position in screen space into a position in coordinate space
	int getTileCoordinateForPosition(int position);
    
	//Index methods
	int getTileIndexForPosition(int positionX, int positionY);
	int getTileIndexForCoordinates(int coordinatesX, int coordinatesY);
	int getTileIndexForTile(Tile* tile);
	int getTileIndexForPlayer(Player* player);
	int getTileIndexForCastle(Castle* castle);
	int getTileIndexForCreeps(Creep* creep);
    
	//Tile methods
	Tile* getTileForPosition(int positionX, int positionY);
	Tile* getTileForCoordinates(int coordinatesX, int coordinatesY);
	Tile* getTileForIndex(int index);
	Tile* getTileForPlayer(Player* player);
	Tile* getTileForCastle(Castle* castle);
	Tile* getTileForCreeps(Creep* creep);
    
    //Set tile type methods
    void setTileTypeAtPosition(TileType tileType, int positionX, int positionY);
    void setTileTypeAtCoordinates(TileType tileType, int coordinatesX, int coordinatesY);
    void setTileTypeAtIndex(TileType tileType, int index);

	//Pickup type methods
	void setPickupTypeAtPosition(PickupType pickupType, int positionX, int positionY);
	void setPickupTypeAtCoordinates(PickupType pickupType, int coordinateX, int coordinateY);
	void setPickupTypeAtIndex(PickupType pickupType, int index);
    
    //Coveniance methods to toggle debug paint methods
    void togglePaintTileScoring();
    void togglePaintTileIndexes();

	//Disables the old tiles selection (if ground tile) and
	//enables the newly selected tiles selection (if ground tile)
	void setSelectedTileIndex(int selectedIndex);
	int getSelectedTileIndex();

	//Getter methods
	Babysitter* getBabysitter();
	Castle* getCastle();
	std::vector<Creep*> getCreeps();

protected:
	//Protected Member variables
	Babysitter* m_Babysitter;
	Castle* m_Castle;
	Tile** m_Tiles;
	unsigned int m_HorizontalTiles;
	unsigned int m_VerticalTiles;
	unsigned int m_TileSize;
    unsigned int m_PlayerStartingTileIndex;
	int m_SelectedTileIndex;
    bool m_PaintTileScoring;
    bool m_PaintTileIndexes;
	int m_CastleHealth;
	std::vector<Creep*> m_Creeps;
};

#endif
