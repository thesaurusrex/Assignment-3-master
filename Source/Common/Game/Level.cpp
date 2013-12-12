//SEE LEVEL.H

//INCLUDE TIMES EVERYTHING
#include "Level.h"
#include "Player.h"
#include "Babysitter.h"
#include "Creep.h"
#include "Castle.h"
#include "PathFinder.h"
#include "../Game/Pickups/Pickup.h"
#include "../Game/Pickups/GoldPickup.h"
#include "Tiles/Tile.h"
#include "Tiles/GroundTile.h"
#include "Tiles/BarbieHeadTile.h"
#include "Tiles/LegoBrickTile.h"
#include "Tiles/ToyCarTile.h"
#include "Tiles/BlanketTile.h"
#include "Tiles/BearicadeTile.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../Utils/Math/GDRandom.h"
#include <stdlib.h>
#include <fstream>


Level::Level(bool isEditingLevel) :
    m_HorizontalTiles(0),
    m_VerticalTiles(0),
    m_TileSize(EMPTY_LEVEL_TILE_SIZE),
    m_PlayerStartingTileIndex(EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX),
    m_Babysitter(NULL),
	m_Castle(NULL),
    m_Tiles(NULL),
    m_SelectedTileIndex(-1),
    m_PaintTileScoring(false),
    m_PaintTileIndexes(false)
{
	//Calculate the number of horizontal and vertical tiles
    m_HorizontalTiles = ScreenManager::getInstance()->getScreenWidth() / m_TileSize;
    m_VerticalTiles = ScreenManager::getInstance()->getScreenHeight() / m_TileSize;

    //Create the player object
    if(isEditingLevel == false)
    {
        m_Babysitter = new Babysitter(this);

		//TODO: MAKE CONSTANTS FOR SPEED
		/*float min = 10.0f;
		float max = PLAYER_SPEED - 100.0f;
		GDRandom random;
		random.randomizeSeed();*/

		for(int i = 0; i < CREEP_COUNT; i++)
		{
			float speed = CREEP_SPEED;

			Creep* creep = new Creep(this, speed, 1, 1);			
			m_Creeps.push_back(creep);
		}
    }
    
	//Create the castle
	m_Castle = new Castle(this);
    
    //Allocate the tiles array, the inheriting class will populate this array with Tile objects
	m_Tiles = new Tile*[m_HorizontalTiles * m_VerticalTiles];
    
    //Initialize all the tiles to NULL
    for(int i = 0; i < m_HorizontalTiles * m_VerticalTiles; i++)
    {
        m_Tiles[i] = NULL;
    }
    
    //Load an empty level
    load(NULL);
}

Level::~Level()
{
    //Delete the player object
	if(m_Babysitter != NULL)
	{
		delete m_Babysitter;
		m_Babysitter = NULL;
	}
    
	//Delete the castle
	if(m_Castle != NULL)
	{
		delete m_Castle;
		m_Castle = NULL;
	}

	//Delete the creep array
	for(int i = 0; i < m_Creeps.size(); i++)
	{
		delete m_Creeps.at(i);
		m_Creeps.at(i) = NULL;
	}

	//Clear the creep araay
	m_Creeps.clear();

    //Delete the tiles array, the inheriting class
    //must delete the object in this array itself
	if(m_Tiles != NULL)
	{
        //Cycle through and delete all the tile objects in the array
        for(int i = 0; i < getNumberOfTiles(); i++)
        {
            if(m_Tiles[i] != NULL)
            {
                delete m_Tiles[i];
                m_Tiles[i] = NULL;
            }
        }
        
		//Delete the tile array
		delete[] m_Tiles;
		m_Tiles = NULL;
	}
}

void Level::update(double aDelta)
{
	//Update all the game tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
		if(m_Tiles[i] != NULL)
		{
			m_Tiles[i]->update(aDelta);
		}
	}
    
	//Update the Player
	if(m_Babysitter != NULL)
	{
		m_Babysitter->update(aDelta);
	}

	//Update castle
	if(m_Castle != NULL)
	{
		m_Castle->update(aDelta);
	}

	//Update the creeps
	for(int i = 0; i < m_Creeps.size(); i++)
	{
		if(m_Creeps.at(i)->getIsActive() == true)
		{
			m_Creeps.at(i)->update(aDelta);
            
            //Try and do stuff, fail.
            if(m_Creeps.at(i)->getIsActive() == false && CASTLE_HEALTH != 0)
            {
                ScreenManager::getInstance()->switchScreen(YOU_WIN_SCREEN_NAME);
            }
		}
	}
}

void Level::paint()
{
	//Cycle through and paint all the tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
        //Safety check the tile
		if(m_Tiles[i] != NULL)
		{
            //Paint the tile
            m_Tiles[i]->paint();
            
            //If the paint tile indexes flag is set to true,
            //draw the index number on the tiles
            if(m_PaintTileIndexes == true)
            {
                m_Tiles[i]->paintIndex(i);
            }
		}
	}
    
	//Paint the Player
	if(m_Babysitter != NULL)
	{
        //If paint tile scoring flag is set to true,
        //draw the path scoring
        if(m_PaintTileScoring == true)
        {
			m_Babysitter->getPathFinder()->paint();
        }
        
        //Paint the player
		m_Babysitter->paint();
	}

	//Paint the castle
	if(m_Castle != NULL)
	{
		//do helth if here
		m_Castle->paint();
	}

	//Paint the creeps
	for(int i = 0; i < m_Creeps.size(); i++)
	{
		if(m_Creeps.at(i)->getIsActive() == true)
		{
			m_Creeps.at(i)->paint();
		}
	}
    

}

void Level::reset()
{
	//Cycle through and reset all the tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
		if(m_Tiles[i] != NULL)
		{
			m_Tiles[i]->reset();
		}
	}
    
	std::vector<Player*> players;

	if(m_Babysitter != NULL)
	{
		players.push_back(m_Babysitter);
	}

	if(m_Castle != NULL)
	{
		m_Castle->reset();
		m_Castle->setCurrentTile(getTileForIndex(95));
	}

	//Makes all creeps spawn at same spot
	for(int i = 0; i < m_Creeps.size(); i++)
	{
		//players.push_back(m_Creeps.at(i));
		//m_Creeps.at(i)->reset();

		m_Creeps.at(0)->setCurrentTile(getTileForIndex(0));
		m_Creeps.at(1)->setCurrentTile(getTileForIndex(16));
		m_Creeps.at(2)->setCurrentTile(getTileForIndex(32));
		m_Creeps.at(3)->setCurrentTile(getTileForIndex(48));
		m_Creeps.at(4)->setCurrentTile(getTileForIndex(64));
		m_Creeps.at(5)->setCurrentTile(getTileForIndex(80));
		m_Creeps.at(6)->setCurrentTile(getTileForIndex(96));
		m_Creeps.at(7)->setCurrentTile(getTileForIndex(112));
		m_Creeps.at(8)->setCurrentTile(getTileForIndex(128));
		m_Creeps.at(9)->setCurrentTile(getTileForIndex(144));
	}

	//Random number generator for the spawn indexes
	//DONT RANDOMLY SPAWN!!!!
	//GDRandom random;
	//random.randomizeSeed();
	//int tileIndex = -1;
	//std::vector<int> usedTileIndexes;

	//Cycle through the Player objects
	//Only the Player now
	for(int i = 0; i < players.size(); i++)
	{
		players.at(i)->setCurrentTile(getTileForIndex(90));
	//	tileIndex = -1;

	//	while (tileIndex == -1)
	//	{
	//		tileIndex = random.random(getNumberOfTiles());

	//		if(getTileForIndex(tileIndex)->isWalkableTile() == false)
	//		{
	//			tileIndex = -1;
	//		}
	//		else
	//		{
	//			for(int j = 0; j < usedTileIndexes.size(); j++)
	//			{
	//				if(usedTileIndexes.at(j) == tileIndex)
	//				{
	//					tileIndex = -1;
	//					break;
	//				}
	//			}
	//			
	//			if(tileIndex != -1)
	//			{
	//				players.at(i)->setCurrentTile(getTileForIndex(tileIndex));
	//				players.at(i)->reset();
	//				usedTileIndexes.push_back(tileIndex);
	//			}
	//		}
	//	}
	}
}

//INPUT METHODS------------------------------------------------------------------------------
void Level::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	if(m_Babysitter != NULL)
	{
		m_Babysitter->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}
}

void Level::mouseLeftClickUpEvent(float aPositionX, float aPositionY)
{
	//Convert the mouse click position, into a tile index
	int index = getTileIndexForPosition(aPositionX, aPositionY);

	//Safety check that the tile isn't NULL
	if(m_Tiles[index] != NULL)
	{
        //Set the selected tile index
        setSelectedTileIndex(index);
        
        //If the tile is walkable, set the player's destination tile
		//Player not affected by walkable/non-walkable
        //if(m_Tiles[index]->isWalkableTile() == true)
        //{
            if(m_Babysitter != NULL)
            {
                m_Babysitter->setDestinationTile(m_Tiles[m_SelectedTileIndex]);
            }
        //}
	}
}

void Level::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_R)
    {
        reset();
    }
	else
	{
		if(m_Babysitter!= NULL)
		{
			m_Babysitter->keyUpEvent(keyCode);
		}
	}
	
	//SPEED UP STUFF
	if(keyCode == KEYCODE_1)
	{
		PLAYER_SPEED = 100.0f;
		CREEP_SPEED = 80.0f;
	}

	else if(keyCode == KEYCODE_2)
	{
		//Player::m_Speed = PLAYER_SPEED * 2;
		//Player::m_CreepSpeed = CREEP_SPEED * 2;
		PLAYER_SPEED = 200.0f;
		CREEP_SPEED = 160.0f;
	}

	else if(keyCode == KEYCODE_3)
	{
		//Player::m_Speed = PLAYER_SPEED * 4;
		//Player::m_CreepSpeed = CREEP_SPEED * 4;
		PLAYER_SPEED = 400.0f;
		CREEP_SPEED = 320.0f;
	}
}

//SAVE AND LOAD------------------------------------------------------------------------------
void Level::load(const char* levelName)
{
    if(levelName != NULL)
    {
		std::ifstream inputStream;
		inputStream.open(levelName, std::ifstream::in | std::ifstream::binary);
    
		if(inputStream.is_open() == true)
		{

			inputStream.seekg(0, inputStream.end);
			long long bufferSize = inputStream.tellg();
        

			inputStream.seekg(0, inputStream.beg);

			char* buffer = new char [bufferSize];

			inputStream.read(buffer, (int)bufferSize);

			inputStream.close();
        
			for(int i = 0; i < bufferSize; i++)
			{
				PickupType pickupType = PickupTypeUnknown;
				//Chekc to see if the buffer contains the the GoldPickup bit
				if((buffer[i] & PickupTypeGold) > 0)
				{
					//It does
					pickupType = PickupTypeGold;

					//Clear the Gold bit
					buffer[i] &= ~PickupTypeGold;
				}

				//Set the tile type
				setTileTypeAtIndex((TileType)buffer[i], i);

				//Set the pickupType
				setPickupTypeAtIndex(pickupType, i);
			}

			delete [] buffer;
			buffer = NULL; 
		}
    }
    else
    {
        //Tile variables
        int tileIndex = 0;
        float tileX = 0.0f;
        float tileY = 0.0f;

        //Cycle through all the tiles and create them
        for(int v = 0; v < getNumberOfVerticalTiles(); v++)
        {
            for(int h = 0; h < getNumberOfHorizontalTiles(); h++)
            {
                //The empty level will contain only ground tiles
                m_Tiles[tileIndex] = new GroundTile();
                m_Tiles[tileIndex]->setPosition(tileX, tileY);
                m_Tiles[tileIndex]->setSize(m_TileSize, m_TileSize);

                //Increment the tile index
                tileIndex++;

                //And increment the tile x position
                tileX += m_TileSize;
            }

            //Increment the tile y position and reset the tile x position, since we started a new row
            tileY += m_TileSize;
            tileX = 0.0f;
        }
    }
    
    //The level is loaded, reset everything
    reset();
}

void Level::save(const char* levelName)
{
    int bufferSize = getNumberOfTiles();
	char* buffer = new char [bufferSize];

	for(int i = 0; i < bufferSize; i++)
	{
		buffer[i] = (char) getTileTypeForIndex(i);

		//Save the tile's pickup if there is one
		if(m_Tiles[i]->getPickup() != NULL && m_Tiles[i]->getPickup()->getPickupType() != PickupTypeUnknown)
		{
			buffer[i] |= m_Tiles[i]->getPickup()->getPickupType();
		}
	}

	std::ofstream outputStream;
	outputStream.open(levelName, std::ofstream::out | std::ofstream::binary);

	if(outputStream.is_open() == true)
	{
		outputStream.write(buffer, bufferSize);
		outputStream.close();
	}

	delete[] buffer;
	buffer = NULL;
}

//TYPE FUNCTIONS-----------------------------------------------------------------------------
TileType Level::getTileTypeForIndex(int index)
{
    if(index >= 0 && index < getNumberOfTiles())
    {
        return m_Tiles[index]->getTileType();
    }
    return TileTypeUnknown;
}

PickupType Level::getPickupTypeForIndex(int index)
{
	if(index >= 0 && index < getNumberOfTiles())
	{
		if(m_Tiles[index]->getPickup()->getPickupType())
		{
			return m_Tiles[index]->getPickup()->getPickupType();
		}
	}
	return PickupTypeUnknown;
}

//GET TILE STUFF!-----------------------------------------------------------------------------
unsigned int Level::getNumberOfTiles()
{
    return getNumberOfHorizontalTiles() * getNumberOfVerticalTiles();
}

unsigned int Level::getNumberOfHorizontalTiles()
{
	return m_HorizontalTiles;
}

unsigned int Level::getNumberOfVerticalTiles()
{
	return m_VerticalTiles;
}

bool Level::validateTileCoordinates(int aCoordinatesX, int aCoordinatesY)
{
    if(aCoordinatesX < 0 || aCoordinatesY < 0 || aCoordinatesX >= getNumberOfHorizontalTiles() || aCoordinatesY >= getNumberOfVerticalTiles())
	{
        return false;
    }
    return true;
}

int Level::getTileCoordinateForPosition(int aPosition)
{
	return (aPosition / m_TileSize);
}

int Level::getTileIndexForPosition(int aPositionX, int aPositionY)
{
	int coordinatesX = getTileCoordinateForPosition(aPositionX);
	int coordinatesY = getTileCoordinateForPosition(aPositionY);
	return getTileIndexForCoordinates(coordinatesX, coordinatesY);
}

int Level::getTileIndexForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	//Validate the coordinates, then calculate the array index
	if(validateTileCoordinates(aCoordinatesX, aCoordinatesY) == true)
	{
		return aCoordinatesX + (aCoordinatesY * getNumberOfHorizontalTiles());
	}
    
	return -1;
}

int Level::getTileIndexForPlayer(Player* player)
{
	return getTileIndexForPosition(player->getX(), player->getY());
}

int Level::getTileIndexForCastle(Castle* castle)
{
	return getTileIndexForPosition(castle->getX(), castle->getY());
}

int Level::getTileIndexForCreeps(Creep* creep)
{
	return getTileIndexForPosition(creep->getX(), creep->getY());
}

int Level::getTileIndexForTile(Tile* aTile)
{
	return getTileIndexForPosition(aTile->getX(), aTile->getY());
}

Tile* Level::getTileForPosition(int aPositionX, int aPositionY)
{
	return getTileForIndex(getTileIndexForPosition(aPositionX, aPositionY));
}

Tile* Level::getTileForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	return getTileForIndex(getTileIndexForCoordinates(aCoordinatesX, aCoordinatesY));
}

Tile* Level::getTileForIndex(int aIndex)
{
    //Safety check the index bounds
	if(aIndex >= 0 && aIndex < getNumberOfTiles())
	{
		return m_Tiles[aIndex];
	}
    
    //If we got here, it means the index passed in was out of bounds
	return NULL;
}

Tile* Level::getTileForPlayer(Player* player)
{
	return getTileForPosition(player->getX(), player->getY());
}

Tile* Level::getTileForCreeps(Creep* creeps)
{
	return getTileForPosition(creeps->getX(), creeps->getY());
}

Tile* Level::getTileForCastle(Castle* castle)
{
	return getTileForPosition(castle->getX(), castle->getY());
}

//SET TILE STUFF------------------------------------------------------------------------------
void Level::setTileTypeAtPosition(TileType tileType, int positionX, int positionY)
{
    setTileTypeAtIndex(tileType, getTileIndexForPosition(positionX, positionY));
}

void Level::setTileTypeAtCoordinates(TileType tileType, int coordinatesX, int coordinatesY)
{
    setTileTypeAtIndex(tileType, getTileIndexForCoordinates(coordinatesX, coordinatesY));
}

void Level::setTileTypeAtIndex(TileType tileType, int index)
{
    //Safety check the index
    if(index >= 0 && index < getNumberOfTiles())
	{
        //Don't replace the tile if its the same type of tile that already exists
        if(m_Tiles[index]->getTileType() == tileType)
        {
            return;
        }
    
        //Delete the tile at the index, if one exists
        if(m_Tiles[index] != NULL)
        {
            delete m_Tiles[index];
            m_Tiles[index] = NULL;
        }
        
        //Create the new tile based on the TileType
        switch (tileType)
        {
            case TileTypeGround:
                m_Tiles[index] = new GroundTile();
                break;

			case TileTypeBlanket:
                m_Tiles[index] = new BlanketTile();
                break;

			case TileTypeBarbieHead:
                m_Tiles[index] = new BarbieHeadTile();
                break;

			case TileTypeLegoBrick:
                m_Tiles[index] = new LegoBrickTile();
                break;

			case TileTypeToyCar:
                m_Tiles[index] = new ToyCarTile();
                break;

			case TileTypeBearicade:
                m_Tiles[index] = new BearicadeTile();
                break;

            case TileTypeUnknown:
            default:
                m_Tiles[index] = NULL;
                break;
        }
        
        //Calculate the coordinates and set the tile position and size
        int coordinateX = (index % getNumberOfHorizontalTiles());
        int coordinateY = ((index - coordinateX) / getNumberOfHorizontalTiles());
        m_Tiles[index]->setPosition(coordinateX  * m_TileSize, coordinateY * m_TileSize);
        m_Tiles[index]->setSize(m_TileSize, m_TileSize);
	}
}

//SET PICKUP STUFF---------------------------------------------------------------------------
void Level::setPickupTypeAtPosition(PickupType pickupType, int positionX, int positionY)
{
	setPickupTypeAtIndex(pickupType, getTileIndexForPosition(positionX, positionY));
}

void Level::setPickupTypeAtCoordinates(PickupType pickupType, int coordinateX, int coordinateY)
{
	setPickupTypeAtIndex(pickupType, getTileIndexForCoordinates(coordinateX, coordinateY));
}

void Level::setPickupTypeAtIndex(PickupType pickupType, int index)
{
	//Safety check the index
	if(index >= 0 && index < getNumberOfTiles())
	{
		//Don't replace the tile if a pickup of the same type already exists there
		if(m_Tiles[index] != NULL && m_Tiles[index]->getPickup() != NULL)
		{
			if(m_Tiles[index]->getPickup()->getPickupType() == pickupType)
			{
				return;
			}
		}

		//Delete the pickup at the index if one exists already
		if(m_Tiles[index] != NULL)
		{
			if(m_Tiles[index]->getPickup() != NULL)
			{
				m_Tiles[index]->setPickup(NULL);
			}

			//Create a new pickup object based on the pickup type
			switch(pickupType)
			{
				case PickupTypeGold:
				{
					GDRandom random;
					random.randomizeSeed();

					int min = 1;
					int max = 5;
					int gold = min + random.random(max-min);

					m_Tiles[index]->setPickup(new GoldPickup(gold));
				}
				break;

				//ADD PICKUPS HERE

				case PickupTypeUnknown:
				default:
				break;
			}

			//Set the pickups position and size
			if(m_Tiles[index]->getPickup() != NULL)
			{
				int coordinateX = (index % getNumberOfHorizontalTiles());
				int coordinateY = ((index - coordinateX) / getNumberOfHorizontalTiles());

				Pickup* pickup = m_Tiles[index]->getPickup();
				float x = (coordinateX * m_TileSize) + (m_TileSize - pickup->getWidth()) / 2.0f;
				float y = (coordinateY * m_TileSize) + (m_TileSize - pickup->getHeight()) / 2.0f;
				pickup->setPosition(x, y);
			}
		}
	}
}

//TILE SCORING STUFF-----------------------------------------------------------------------
void Level::togglePaintTileScoring()
{
    m_PaintTileScoring = !m_PaintTileScoring;
}

void Level::togglePaintTileIndexes()
{
    m_PaintTileIndexes = !m_PaintTileIndexes;
}

//TILE INDEXES-----------------------------------------------------------------------------
void Level::setSelectedTileIndex(int aSelectedIndex)
{
	//Deselect the previously selected tile
	if(m_SelectedTileIndex >= 0 && m_SelectedTileIndex < getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(false);
	}
    
	//Set the new tile index
	m_SelectedTileIndex = aSelectedIndex;
    
	//Selected the newly selected tile
	if(m_SelectedTileIndex >= 0 && m_SelectedTileIndex < getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(true);
	}
}

int Level::getSelectedTileIndex()
{
	return m_SelectedTileIndex;
}

//THE PLAYERS-------------------------------------------------------------------------------
Babysitter* Level::getBabysitter()
{
	return m_Babysitter;
}

Castle* Level::getCastle()
{
	return m_Castle;
}

std::vector<Creep*> Level::getCreeps()
{
	return m_Creeps;
}
