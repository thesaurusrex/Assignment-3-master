//SEE LOADGAMEMENU.H

#include "LoadGameMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../OpenGL/OpenGL.h"
#include "../Screen Manager/ScreenManager.h"


//CONSTRUCTOR------------------------------------------------
LoadGameMenu::LoadGameMenu() : Menu("Background_LoadGameScreen", NULL)
{
	//Create buttons
	//false button because stuff was all weird
	addButton(new UIButton("Button_LoadLevel0"));
	//Actual buttons
	addButton(new UIButton("Button_LoadLevel1"));
	addButton(new UIButton("Button_LoadLevel2"));
	addButton(new UIButton("Button_LoadLevel3"));
	addButton(new UIButton("Button_LoadLevel4"));
	addButton(new UIButton("Button_LoadLevel5"));
	addButton(new UIButton("Button_LoadLevel6"));
}

//DESTRUCTOR-------------------------------------------------
LoadGameMenu::~LoadGameMenu()
{

}

//GET NAME---------------------------------------------------
const char* LoadGameMenu::getName()
{
	return LOAD_GAME_MENU_SCREEN_NAME;
}

//KEY UP EVENT-----------------------------------------------
void LoadGameMenu::buttonAction(UIButton* button)
{
	int index = getIndexForButton(button);
    if(index == 0)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
    else if(index == 1)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
    else if (index == 2)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
	else if (index == 3)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
	else if (index == 4)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
	else if (index == 5)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
	else if (index == 6)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
}