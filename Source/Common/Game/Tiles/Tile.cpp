//SEE TILE.H

#include "Tile.h"
#include "../Pickups/Pickup.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Utils/Utils.h"
#include "../../Constants/Constants.h"
#include <stdlib.h>
#include <sstream>
#include <string>
#include <math.h> 


//CONSTRUCTOR
Tile::Tile(TileType tileType, const char* tileTexture, bool aIsWalkableTile, bool aIsTower, bool aIsDestructable, int aGoldCost)
{
    //Initialize the walkable tile, tower, destructable, selected and path flags
    m_TileType = tileType;
    m_IsWalkableTile = aIsWalkableTile;
	m_IsTower = aIsTower;
	m_IsDestructable = aIsDestructable;
	m_GoldCost = aGoldCost;
    m_IsSelected = false;
    m_IsPath = false;
	m_Pickup = NULL;
    
    //Create the tile texture
    if(tileTexture != NULL)
    {
        m_Texture = OpenGLTextureCache::getInstance()->getTexture(tileTexture);
    }
    
    //Create the selected tile object
    m_SelectedTile = OpenGLTextureCache::getInstance()->getTexture(RES_SELECTED_TILE);
    
    //Create the tile index number OpenGLTextures
    m_TileIndexNumbers = new OpenGLTexture*[RES_TILE_INDEX_NUMBERS_COUNT];
    for(int i = 0; i < RES_TILE_INDEX_NUMBERS_COUNT; i++)
    {
        m_TileIndexNumbers[i] = OpenGLTextureCache::getInstance()->getTexture(RES_TILE_INDEX_NUMBERS[i]);
    }
    
    //Create the tile scoring number OpenGLTextures
    m_TileScoreNumbers = new OpenGLTexture*[RES_TILE_SCORE_NUMBERS_COUNT];
    for(int i = 0; i < RES_TILE_SCORE_NUMBERS_COUNT; i++)
    {
        m_TileScoreNumbers[i] = OpenGLTextureCache::getInstance()->getTexture(RES_TILE_SCORE_NUMBERS[i]);
    }
}

//DESTRUCTOR
Tile::~Tile()
{
    //Set the textures to NULL
    m_Texture = NULL;
    m_SelectedTile = NULL;
    
	//Delete the pickup object
	if(m_Pickup != NULL)
	{
		delete m_Pickup;
		m_Pickup = NULL;
	}

    //Delete the tile index number OpenGLTextures
    if(m_TileIndexNumbers != NULL)
    {
        for(int i = 0; i < RES_TILE_INDEX_NUMBERS_COUNT; i++)
        {
            m_TileIndexNumbers[i] = NULL;
        }
        
        //Lastly delete the array
        delete [] m_TileIndexNumbers;
        m_TileIndexNumbers = NULL;
    }
    
    //Delete the tile score number OpenGLTextures
    if(m_TileScoreNumbers != NULL)
    {
        for(int i = 0; i < RES_TILE_SCORE_NUMBERS_COUNT; i++)
        {
            m_TileScoreNumbers[i] = NULL;
        }
        
        //Lastly delete the array
        delete [] m_TileScoreNumbers;
        m_TileScoreNumbers = NULL;
    }
}

//UPDATE
void Tile::update(double aDelta)
{
    
}

//PAINT
void Tile::paint()
{
    //Paint the texture if it is set
    if(m_Texture != NULL)
    {
        OpenGLRenderer::getInstance()->drawTexture(m_Texture, getX(), getY(), getWidth(), getHeight());
    }

    //Paint the selected texture if this tile is actually selected
    if(isSelected() == true)
    {
        OpenGLRenderer::getInstance()->drawTexture(m_SelectedTile, getX(), getY(), getWidth(), getHeight());
    }

	//Paint the pickup object
	if(m_Pickup != NULL)
	{
		m_Pickup->paint();
	}
}

//RESET
void Tile::reset()
{
    m_IsSelected = false;
    m_IsPath = false;

	//Reset the pickup object
	if(m_Pickup != NULL)
	{
		m_Pickup->reset();
	}
}

//SCORE PAINTING FUNCTIONS FOR MOVEMENT------------------------------------------------

//PAINT SCORE
void Tile::paintScore(OpenGLColor color, int scoreG, int scoreH, int scoreF)
{
    //Paint the color tile outline
    OpenGLRenderer::getInstance()->setLineWidth(2.0f);
    OpenGLRenderer::getInstance()->setForegroundColor(color);
    OpenGLRenderer::getInstance()->drawRectangle(getX(), getY(), getWidth(), getHeight(), false);
    OpenGLRenderer::getInstance()->setLineWidth(1.0f);

    //Get the scale, we get the smallest one for consistency
    float padding = 1.0f;
    float scale = fminf(getScoreNumberScale(scoreG, padding), fminf(getScoreNumberScale(scoreH, padding), getScoreNumberScale(scoreF, padding)));

    //Paint the scores
    paintScoreNumber(scoreG, BottomLeft, scale, padding);
    paintScoreNumber(scoreH, BottomRight, scale, padding);
    paintScoreNumber(scoreF, TopLeft, scale, padding);
}

//PAINT INDEX
void Tile::paintIndex(int aIndex)
{
    //Convert the index to a stringstream
    std::stringstream numberStream;
    numberStream << aIndex;
    
    //Next convert the stringstream into a string
    std::string numberString(numberStream.str());
    
    //Cycle through each number in the string and calculate the total width of the string
    float stringWidth = 0.0f;
    float stringHeight = 0.0f;
    for(int i = 0; i < numberString.length(); i++)
    {
        //Convert the letter in the string back to an int
        int index = atoi(numberString.substr(i,1).c_str());
        
        //Increment the X value
        stringWidth += m_TileIndexNumbers[index]->getSourceWidth();
        stringHeight = stringHeight < m_TileIndexNumbers[index]->getSourceHeight() ? m_TileIndexNumbers[index]->getSourceHeight() : stringHeight;
    }
    
    float padding = 4.0f;
    float scale = fminf((m_Width - padding) / stringWidth, 1.0f);
    float scaledWidth = stringWidth * scale;
    float scaledHeight = stringHeight * scale;
    
    //Calculate the x and y position based on the string width and height
    float x = getX() + (getWidth() - scaledWidth) / 2.0f;
    float y = getY() + (getHeight() - scaledHeight) / 2.0f;
    for(int i = 0; i < numberString.length(); i++)
    {
        //Convert the letter in the string back to an int
        int index = atoi(numberString.substr(i,1).c_str());
        
        //Calculate the scaled width and height
        float width = m_TileIndexNumbers[index]->getSourceWidth() * scale;
        float height = m_TileIndexNumbers[index]->getSourceHeight() * scale;
        
        //Draw the texture that is equivalent to the number
        OpenGLRenderer::getInstance()->drawTexture(m_TileIndexNumbers[index], x, y, width, height);
        
        //Increment the X value
        x += width;
    }
}

//PAINT SCORE NUMBER
void Tile::paintScoreNumber(int number, ScoreNumberPosition position, float scale, float padding)
{
    //Check to see if its a walkable tile
    if(isWalkableTile() == true)
    {
        //Convert the number to a stringstream
        std::stringstream numberStream;
        numberStream << number;
        
        //Next convert the stringstream into a string
        std::string numberString(numberStream.str());
        
        //Cycle through each number in the string and calculate the total width of the string
        float stringWidth = 0.0f;
        float stringHeight = 0.0f;
        for(int i = 0; i < numberString.length(); i++)
        {
            //Convert the letter in the string back to an int
            int index = atoi(numberString.substr(i,1).c_str());
            
            //Increment the X value
            stringWidth += m_TileScoreNumbers[index]->getSourceWidth();
            stringHeight = stringHeight < m_TileScoreNumbers[index]->getSourceHeight() ? m_TileScoreNumbers[index]->getSourceHeight() : stringHeight;
        }
        
        float scaledWidth = stringWidth * scale;
        float scaledHeight = stringHeight * scale;
        float x = 0.0f;
        float y = 0.0f;
        
        //Calculate the x and y position based on the string width and height
        switch (position)
        {
            case TopLeft:
            x = getX() + padding;
            y = getY() + padding;
            break;

            case BottomLeft:
            x = getX() + padding;
            y = getY() + getHeight() - scaledHeight - padding;
            break;

            case BottomRight:
            x = getX() + getWidth() - scaledWidth - padding;
            y = getY() + getHeight() - scaledHeight - padding;
            break;
        }
        
        //Cycle through each number in the string and draw it
        for(int i = 0; i < numberString.length(); i++)
        {
            //Convert the letter in the string back to an int
            int index = atoi(numberString.substr(i,1).c_str());
            
            //Calculate the scaled width and height
            float width = m_TileScoreNumbers[index]->getSourceWidth() * scale;
            float height = m_TileScoreNumbers[index]->getSourceHeight() * scale;
            
            //Draw the texture that is equivalent to the number
            OpenGLRenderer::getInstance()->drawTexture(m_TileScoreNumbers[index], x, y, width, height);
            
            //Increment the X value
            x += m_TileScoreNumbers[index]->getSourceWidth() * scale;
        }
    }
}

//SET SCORE NUMBER SCALE
float Tile::getScoreNumberScale(int number, float padding)
{
    //Convert the number to a stringstream
    std::stringstream numberStream;
    numberStream << number;
    
    //Next convert the stringstream into a string
    std::string numberString(numberStream.str());
    
    //Cycle through each number in the string and calculate the total width of the string
    float stringWidth = 0.0f;
    float stringHeight = 0.0f;
    for(int i = 0; i < numberString.length(); i++)
    {
        //Convert the letter in the string back to an int
        int index = atoi(numberString.substr(i,1).c_str());
        
        //Increment the X value
        stringWidth += m_TileScoreNumbers[index]->getSourceWidth();
        stringHeight = stringHeight < m_TileScoreNumbers[index]->getSourceHeight() ? m_TileScoreNumbers[index]->getSourceHeight() : stringHeight;
    }
    
    float scale = fminf(((m_Width - padding * 2.0f) / 2.0f) / stringWidth, 1.0f);
    return scale;
}

//TILE TYPE FUNCTIONS------------------------------------------------------------------

//GET TILE TYPE
TileType Tile::getTileType()
{
    return m_TileType;
}

//GET TILE SPEED
float Tile::getTileSpeed()
{
	return 1.0f;
}

//GET MOVEMENT COST
float Tile::getMovementCost()
{
	return 1.0f / getTileSpeed();
}

//IS WALKABLE TILE
bool Tile::isWalkableTile()
{
    return m_IsWalkableTile;
}

//IS TOWER
bool Tile::isTower()
{
	return m_IsTower;
}

//IS DESTRUCTABLE
bool Tile::isDestructable()
{
	return m_IsDestructable;
}

//SET GOLD COST
void Tile::setGoldCost()
{
	TILE_GOLD_COST = m_GoldCost;
}

//GET GOLD COST
int Tile::getGoldCost()
{
	return m_GoldCost;
}

//SET TILE COST
void Tile::setTileCost()
{
	TILE_COST = m_TileCost;
}

//GET TILE COST
int Tile::getTileCost()
{
	return m_TileCost;
}

//SET IS SELECTED
void Tile::setIsSelected(bool aIsSelected)
{
	m_IsSelected = aIsSelected;
}

//IS SELECTED
bool Tile::isSelected()
{
	return m_IsSelected;
}

//SET IS PATH
void Tile::setIsPath(bool aIsPath)
{
    if(m_IsWalkableTile == true /*Or, if the mover is the babysitter*/)
    {
        m_IsPath = aIsPath;
    }
}

//IS PATH
bool Tile::isPath()
{
	return m_IsPath;
}

//PICKUP TYPE FUNCTIONS----------------------------------------------------------------

//SET PICKUP
void Tile::setPickup(Pickup* pickup)
{
	//If the pointer already points to a pickup object, we need to delete it
	if(m_Pickup != NULL)
	{
		delete m_Pickup;
		m_Pickup = NULL;
	}

	//Set the new pickup object to the m_Pickup pointer
	m_Pickup = pickup;
}

//GET PICKUP
Pickup* Tile::getPickup()
{
	return m_Pickup;
}
