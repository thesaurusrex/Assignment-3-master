//SEE GAME.H

//INCLUDE
#include "Game.h"
#include "GameObject.h"
#include "Level.h"
#include "Tiles/Tile.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIFont.h"
#include "../UI/UIButton.h"
#include "../UI/UIToggle.h"


//CONSTRUCTOR
Game::Game() :
	m_HUDMenu(NULL),
	m_TowerMenu(NULL),
	m_Level(NULL),
    m_IsMouseDown(false),
	m_SelectedTileIndex(-1)
{
    //Create the level object
    m_Level = new Level();
    
	//CreateTower Menu
	m_TowerMenu = new UISideMenu(this, SideMenuRight);
    m_TowerMenu->addButton(new UIToggle("MenuTileGround"));
	m_TowerMenu->addButton(new UIToggle("MenuTileLegoBricks"));
	m_TowerMenu->addButton(new UIToggle("MenuTileBarbieHead"));
	m_TowerMenu->addButton(new UIToggle("MenuTileToyCars"));
	m_TowerMenu->addButton(new UIToggle("MenuTileBlanket"));
	m_TowerMenu->addButton(new UIToggle("MenuTileBearicade"));

	//Create HUD Menu
	m_HUDMenu = new UISideMenu(this, SideMenuLeft);
	m_HUDMenu->addButton(new UIButton("HUD_UpgradeText"));
	m_HUDMenu->addButton(new UIButton("HUD_Damage"));
	m_HUDMenu->addButton(new UIButton("HUD_Speed"));
	m_HUDMenu->addButton(new UIButton("HUD_Health"));

    //Font
    m_Font = new UIFont("FONT");
    m_Font->setText("FONT");
    
    //Reset everything
    reset();
}

//DESTRUCTOR
Game::~Game()
{
    //Delete the level object
    if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }
    
	//Delete the font
    if(m_Font != NULL)
    {
        delete m_Font;
        m_Font = NULL;
    }

	//Delete the side menus
	if(m_TowerMenu != NULL)
	{
		//Tower
		delete m_TowerMenu;
		m_TowerMenu = NULL;
	}

	if(m_HUDMenu != NULL)
	{
		//HUD
		delete m_HUDMenu;
		m_HUDMenu = NULL;
	}
}

//update
void Game::update(double delta)
{
	//Level
    if(m_Level != NULL)
    {
        m_Level->update(delta);
    }

	//Tower menu
    if(m_TowerMenu != NULL)
    {
        m_TowerMenu->update(delta);
    }

	//HUD Menu
    if(m_HUDMenu != NULL)
    {
        m_HUDMenu->update(delta);
    }
}

//paint
void Game::paint()
{
	//Level
    if(m_Level != NULL)
    {
        m_Level->paint();
    }
    
	//Font
    if(m_Font != NULL)
    {
        m_Font->draw(100.0f, 100.0f);
    }

	//Tower Menu
	if(m_TowerMenu != NULL)
    {
        m_TowerMenu->paint();
    }

	//HUD Menu
	if(m_HUDMenu != NULL)
    {
        m_HUDMenu->paint();
    }
}

//reset
void Game::reset()
{
	//Reset the level
    if(m_Level != NULL)
    {
        m_Level->reset();
    }
}

//getName
const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

//getLevel
Level* Game::getLevel()
{
	//We need that level...
    return m_Level;
}

//mouseMovementEvent
void Game::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{   
	//If there is a level...
    if(m_Level != NULL)
    {        
		m_Level->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }

	//If theres a tower menu
    if(m_TowerMenu != NULL)
    {
        m_TowerMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }

	//The HUD menu
	if(m_HUDMenu != NULL)
    {
        m_HUDMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }
}

//mouseLeftClickDownEvent
void Game::mouseLeftClickDownEvent(float positionX, float positionY)
{
    //Set the mouse down flag
    m_IsMouseDown = true;
}

//mouseLeftClickUpEvent
void Game::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Set flag to false
	m_IsMouseDown = false;

	//level
    if(m_Level != NULL)
    {
        m_Level->mouseLeftClickUpEvent(positionX, positionY);
    }

	//tower
	if(m_TowerMenu != NULL)
    {
        m_TowerMenu->mouseLeftClickUpEvent(positionX, positionY);
    }

	//hud
	if(m_HUDMenu != NULL)
    {
        m_HUDMenu->mouseLeftClickUpEvent(positionX, positionY);
    }
}

void Game::mouseRightClickDownEvent(float positionX, float positionY)
{
    m_IsMouseDown = true;
}

void Game::mouseRightClickUpEvent(float positionX, float positionY)
{
    //Set flag to false
	m_IsMouseDown = false;
    
	//If there is a level
	if(m_Level != NULL)
	{
		//It a tile is selected, the menus arent showing
		if(m_SelectedTileIndex != -1 && m_TowerMenu->isShowing() == false)
		{
			//Set the tile types
			TileType types[] = {TileTypeGround, TileTypeLegoBrick, TileTypeBarbieHead, TileTypeToyCar, TileTypeBlanket, TileTypeBearicade};
			TileType type = types[m_SelectedTileIndex];
            
			//Place the tile
			m_Level->setTileTypeAtPosition(type, positionX, positionY);
		}
	}
}

//keyUpEvent
void Game::keyUpEvent(int keyCode)
{
	//Level
    if(m_Level != NULL)
    {
        m_Level->keyUpEvent(keyCode);
    }

	//Bring up pause menu on ESC key
	if(keyCode == KEYCODE_ESCAPE)
    {
		ScreenManager::getInstance()->switchScreen(PAUSE_SCREEN_NAME);
	}

	//Bring us side menus on TAB key
	if(keyCode == KEYCODE_TAB)
    {
		//Tower
        if(m_TowerMenu != NULL)
        {
            m_TowerMenu->isShowing() == true ? m_TowerMenu->hide() : m_TowerMenu->show();
        }

		//HUD
		if(m_HUDMenu != NULL)
        {
            m_HUDMenu->isShowing() == true ? m_HUDMenu->hide() : m_HUDMenu->show();
        }
    }
}

//sideMenuToggleAction
void Game::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{
	//If the side menu is the tower menu
    if(sideMenu == m_TowerMenu)
    {
        //Un-toggled the previously selected toggle
        UIToggle* previousToggle = (UIToggle*)m_TowerMenu->getButtonForIndex(m_SelectedTileIndex);
        if(previousToggle != NULL)
        {
            previousToggle->setIsToggled(false);
        }
    
        //Set the selected tile index
        m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;
        
        //Hide the options and tiles menus
        m_TowerMenu->hide();
		m_HUDMenu->hide();
    }
}

void Game::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{
	if(sideMenu == m_HUDMenu)
	{
		if(buttonIndex == 0)
		{
			//Just Text, do nothing
		}
		else if(buttonIndex == 1)
		{
			//Check gold
			//Increse Tower Damage
			m_HUDMenu->hide();
			m_TowerMenu->hide();
		}
		else if (buttonIndex == 2)
		{
			//Check gold
			//Increase movement speed
			PLAYER_SPEED++;
			m_HUDMenu->hide();
			m_TowerMenu->hide();
		}
		else if(buttonIndex == 3)
		{
			//Check gold
			//Increase castle Health
			CASTLE_HEALTH += 5;
			m_HUDMenu->hide();
			m_TowerMenu->hide();
		}
	}
}