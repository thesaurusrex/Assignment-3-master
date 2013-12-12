/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	11/27/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		Tile Main Header
MODIFIED:		12/10/2013
				-Added "Tower" type stuff
*/


//DEFINE
#ifndef TILE_H
#define TILE_H

//INCLUDE
#include "../GameObject.h"
#include "../../Constants/Constants.h"
#include <stdlib.h>

//CLASSES
class OpenGLTexture;
class Pickup;

class Tile : public GameObject
{
public:
    //Tile takes on parameters, texture, walked on or not, wether it can shoot, wether it can be destroyed, and gold cost
	Tile(TileType tileType, const char* tileTexture, bool isWalkableTile, bool isTower, bool isDestructable, int goldCost);

	//Virtual destructor
	virtual ~Tile();
    
    //Update, Paint and reset methods
	virtual void update(double delta);
	virtual void paint();
    virtual void reset();
    
    //Paint methods to draw the tile score, drawn from the PathFinding class
    virtual void paintScore(OpenGLColor color, int scoreG, int scoreH, int scoreF);
    
    //Paint method to draw the tile's index, drawn from the Level class
    virtual void paintIndex(int index);
    
    //Pure virtual method inerited from GameObject
    virtual const char* getType() = 0;
    
    //Gets the tile type
    virtual TileType getTileType();

	//Speed
	virtual float getTileSpeed();
	virtual float getMovementCost();
    
    //The parameters
    virtual bool isWalkableTile();
	virtual bool isTower();
	virtual bool isDestructable();
	virtual void setGoldCost();
	virtual int getGoldCost();
    
	//Tile Cost
	virtual void setTileCost();
	virtual int getTileCost();

    //Sets wether the tile is selected or not
    virtual void setIsSelected(bool isSelected);
	virtual bool isSelected();
    
    //Sets wether the tile is a path or not
	virtual void setIsPath(bool isPath);
	virtual bool isPath();
    
	//Pickup stuff
	virtual void setPickup(Pickup* pickup);
	virtual Pickup* getPickup();

protected:
	//Enum for scores
    enum ScoreNumberPosition
    {
        TopLeft = 0,
        BottomLeft,
        BottomRight
    };

    //Conveniance method to paint a score number and a certain position
    void paintScoreNumber(int number, ScoreNumberPosition position, float scale, float padding);
    float getScoreNumberScale(int number, float padding);
    
    //Member variables
    TileType m_TileType;
    bool m_IsWalkableTile;
	bool m_IsTower;
	bool m_IsDestructable;
    bool m_IsSelected;
	int m_GoldCost;
	bool m_IsPath;
	int m_TileCost;
    OpenGLTexture* m_SelectedTile;
    OpenGLTexture** m_TileIndexNumbers;
    OpenGLTexture** m_TileScoreNumbers;
	Pickup* m_Pickup;
};

#endif
