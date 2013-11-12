//SEE LEVELEDITOR.H

#include "LevelEditor.h"
#include "../Constants/Constants.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../UI/UIToggle.h"


//CONSTRUCTOR----------------------------------------------------------------------------
LevelEditor::LevelEditor() :
    m_TilesMenu(NULL),
	m_DruthersMenu(NULL),
	m_SaveSlots(NULL),
	m_LoadSlots(NULL),
    m_Level(NULL),
    m_IsMouseDown(false),
    m_SelectedTileIndex(-1)
{
    //Create the Tiles menu items
    m_TilesMenu = new UISideMenu(this, SideMenuRight);
    m_TilesMenu->addButton(new UIToggle("MenuTileGround"));
	m_TilesMenu->addButton(new UIToggle("MenuTileLegoBricks"));
	m_TilesMenu->addButton(new UIToggle("MenuTileBarbieHead"));
	m_TilesMenu->addButton(new UIToggle("MenuTileToyCars"));
	m_TilesMenu->addButton(new UIToggle("MenuTileBlanket"));
	m_TilesMenu->addButton(new UIToggle("MenuTileBearicade"));

	//Create the "Options" side menu
	m_DruthersMenu = new UISideMenu(this, SideMenuLeft);
	m_DruthersMenu->addButton(new UIButton("ButtonClear"));
	m_DruthersMenu->addButton(new UIButton("ButtonSave"));
	m_DruthersMenu->addButton(new UIButton("ButtonLoad"));
	m_DruthersMenu->addButton(new UIButton("ButtonExit"));
    
	//Create the Save hack menu
	m_SaveSlots = new UISideMenu(this, SideMenuRight);
	m_SaveSlots->addButton(new UIButton("Button_SaveLevel1"));
	m_SaveSlots->addButton(new UIButton("Button_SaveLevel2"));
	m_SaveSlots->addButton(new UIButton("Button_SaveLevel3"));
	m_SaveSlots->addButton(new UIButton("Button_SaveLevel4"));
	m_SaveSlots->addButton(new UIButton("Button_SaveLevel5"));
	m_SaveSlots->addButton(new UIButton("Button_SaveLevel6"));

	//Create Load menu
	m_LoadSlots = new UISideMenu(this, SideMenuRight);
	m_LoadSlots->addButton(new UIButton("Button_LoadLevel1"));
	m_LoadSlots->addButton(new UIButton("Button_LoadLevel2"));
	m_LoadSlots->addButton(new UIButton("Button_LoadLevel3"));
	m_LoadSlots->addButton(new UIButton("Button_LoadLevel4"));
	m_LoadSlots->addButton(new UIButton("Button_LoadLevel5"));
	m_LoadSlots->addButton(new UIButton("Button_LoadLevel6"));

    //Create the level object
    m_Level = new Level(true);
    
    //Reset everything
    reset();
}

//DESTRUCTOR-----------------------------------------------------------------------------
LevelEditor::~LevelEditor()
{
	//delete the level
    if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }
    
	//delete the tile menu
    if(m_TilesMenu != NULL)
    {
        delete m_TilesMenu;
        m_TilesMenu = NULL;
    }

	//delete the options menu
	if(m_DruthersMenu != NULL)
	{
		delete m_DruthersMenu;
		m_DruthersMenu = NULL;
	}

	//delete the save menu
	if(m_SaveSlots != NULL)
	{
		delete m_SaveSlots;
		m_SaveSlots = NULL;
	}

	//delete the load menu
	if(m_LoadSlots != NULL)
	{
		delete m_LoadSlots;
		m_LoadSlots = NULL;
	}
}

//GET NAME-------------------------------------------------------------------------------
const char* LevelEditor::getName()
{
    return LEVEL_EDITOR_SCREEN_NAME;
}

//UPDATE---------------------------------------------------------------------------------
void LevelEditor::update(double delta)
{
	//level
    if(m_Level != NULL)
    {
        m_Level->update(delta);
    }

	//tiles
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->update(delta);
    }

	//options
	if(m_DruthersMenu != NULL)
	{
		m_DruthersMenu->update(delta);
	}

	//save
	if(m_SaveSlots != NULL)
	{
		m_SaveSlots->update(delta);
	}

	//load
	if(m_LoadSlots != NULL)
	{
		m_LoadSlots->update(delta);
	}
}

//PAINT----------------------------------------------------------------------------------
void LevelEditor::paint()
{
	//level
    if(m_Level != NULL)
    {
        m_Level->paint();
    }

	//tiles
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->paint();
    }

	//options
	if(m_DruthersMenu != NULL)
	{
		m_DruthersMenu->paint();
	}

	//save
	if(m_SaveSlots != NULL)
	{
		m_SaveSlots->paint();
	}

	//load
	if(m_LoadSlots != NULL)
	{
		m_LoadSlots->paint();
	}
}

//RESET----------------------------------------------------------------------------------
void LevelEditor::reset()
{
    if(m_Level != NULL)
    {
        m_Level->reset();
    }
}

//MOUSE MOVEMENT EVENT-------------------------------------------------------------------
void LevelEditor::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{    
	//Tiles menu
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }
    
	//If there is a level...
    if(m_Level != NULL)
    {        
        if(m_SelectedTileIndex != -1 && m_IsMouseDown == true)
        {
            m_Level->setTileTypeAtPosition((TileType)m_SelectedTileIndex, positionX, positionY);
        }
    }

	//Options menu
	if(m_DruthersMenu != NULL)
	{
		m_DruthersMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}

	//Save menu
	if(m_SaveSlots != NULL)
	{
		m_SaveSlots->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}

	//Load Menu
	if(m_LoadSlots != NULL)
	{
		m_LoadSlots->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}
}

//MOUSE LEFT CLICK DOWN EVENT------------------------------------------------------------
void LevelEditor::mouseLeftClickDownEvent(float positionX, float positionY)
{
    //Set the mouse down flag
    m_IsMouseDown = true;
}

//MOUSE LEFT CLICK UP EVENT--------------------------------------------------------------
void LevelEditor::mouseLeftClickUpEvent(float positionX, float positionY)
{
    //Set the mouse up flag
    m_IsMouseDown = false;
    
    //Safety check the level pointer, then set the new tile type in the index
    if(m_Level != NULL)
    {
        if(m_SelectedTileIndex != -1 && m_TilesMenu->isShowing() == false)
        {
            m_Level->setTileTypeAtPosition((TileType)m_SelectedTileIndex, positionX, positionY);
        }
    }
    
    //Notify the tiles menu of the mouse event
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->mouseLeftClickUpEvent(positionX, positionY);
    }

	//Notify the "options" menu of the mouse event
    if(m_DruthersMenu != NULL)
    {
        m_DruthersMenu->mouseLeftClickUpEvent(positionX, positionY);
    }

	//Notify the "save" menu of the mouse movement event
	if(m_SaveSlots != NULL)
	{
		m_SaveSlots->mouseLeftClickUpEvent(positionX, positionY);
	}

	//Notify the "save" menu of the mouse movement event
	if(m_LoadSlots != NULL)
	{
		m_LoadSlots->mouseLeftClickUpEvent(positionX, positionY);
	}
}

//KEY UP EVENT---------------------------------------------------------------------------
void LevelEditor::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_TAB)
    {
        if(m_TilesMenu != NULL)
        {
            m_TilesMenu->isShowing() == true ? m_TilesMenu->hide() : m_TilesMenu->show();
        }

		if(m_DruthersMenu != NULL)
		{
			m_DruthersMenu->isShowing() == true ? m_DruthersMenu->hide() : m_DruthersMenu->show();
		}
    }
    else
    {
        if(m_Level != NULL)
        {
            m_Level->keyUpEvent(keyCode);
        }
    }
}

//SIDE MENU BUTTON ACTION----------------------------------------------------------------
void LevelEditor::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{
	//OPTIONS MENU___________________________________________________________________________
	if(sideMenu == m_DruthersMenu)
	{
		if(buttonIndex == 0)
		{
			//CLEAR
			m_Level = new Level(true);
		}
		else if(buttonIndex == 1)
		{
			//SAVE
			m_TilesMenu->hide();
			m_LoadSlots->hide();
			m_SaveSlots->show();
			//ScreenManager::getInstance()->switchScreen(SAVE_GAME_MENU_SCREEN_NAME);
		}
		else if (buttonIndex == 2)
		{
			//LOAD
			m_TilesMenu->hide();
			m_SaveSlots->hide();
			m_LoadSlots->show();
			//ScreenManager::getInstance()->switchScreen(LOAD_GAME_MENU_SCREEN_NAME);
		}
		else if(buttonIndex == 3)
		{
			//EXIT
			ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
		}
	}

	//SAVE SLOTS MENU________________________________________________________________________
	if(sideMenu == m_SaveSlots)
	{
		if(buttonIndex == 0)
		{
			//Slot 1
			m_Level->save("Level1.txt");
			m_SaveSlots->hide();
		}
		else if(buttonIndex == 1)
		{
			//Slot 2
			m_Level->save("Level2.txt");
			m_SaveSlots->hide();
		}
		else if(buttonIndex == 2)
		{
			//Slot 3
			m_Level->save("Level3.txt");
			m_SaveSlots->hide();
		}
		else if(buttonIndex == 3)
		{
			//Slot 4
			m_Level->save("Level4.txt");
			m_SaveSlots->hide();
		}
		else if(buttonIndex == 4)
		{
			//Slot 5
			m_Level->save("Level5.txt");
			m_SaveSlots->hide();
		}
		else if(buttonIndex == 5)
		{
			//Slot 6
			m_Level->save("Level6.txt");
			m_SaveSlots->hide();
		}
	}

	//LOAD SLOTS MENU_____________________________________________________________________
	if(sideMenu == m_LoadSlots)
	{
		if(buttonIndex == 0)
		{
			//Slot 1
			m_Level->load("Level1.txt");
			m_LoadSlots->hide();
		}
		else if(buttonIndex == 1)
		{
			//Slot 2
			m_Level->load("Level2.txt");
			m_LoadSlots->hide();
		}
		else if(buttonIndex == 2)
		{
			//Slot 3
			m_Level->load("Level3.txt");
			m_LoadSlots->hide();
		}
		else if(buttonIndex == 3)
		{
			//Slot 4
			m_Level->load("Level4.txt");
			m_LoadSlots->hide();
		}
		else if(buttonIndex == 4)
		{
			//Slot 5
			m_Level->load("Level5.txt");
			m_LoadSlots->hide();
		}
		else if(buttonIndex == 5)
		{
			//Slot 6
			m_Level->load("Level6.txt");
			m_LoadSlots->hide();
		}
	}
}

//SIDE MENU TOGGLE ACTION----------------------------------------------------------------
void LevelEditor::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{
    if(sideMenu == m_TilesMenu)
    {
        //Un-toggled the previously selected toggle
        UIToggle* previousToggle = (UIToggle*)m_TilesMenu->getButtonForIndex(m_SelectedTileIndex);
        if(previousToggle != NULL)
        {
            previousToggle->setIsToggled(false);
        }
    
        //Set the selected tile index
        m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;
        
        //Hide the options and tiles menus
        m_TilesMenu->hide();
		m_DruthersMenu->hide();
    }
}