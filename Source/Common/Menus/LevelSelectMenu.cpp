//SEE LevelSelectMenu.H

#include "LevelSelectMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"

//CONSTRUCTOR
LevelSelectMenu::LevelSelectMenu() : Menu("LEVELSELECT_Background", NULL)
{
    addButton(new UIButton("LEVELSELECT_Button_Level1"));
	addButton(new UIButton("LEVELSELECT_Button_Level2"));
	addButton(new UIButton("LEVELSELECT_Button_Level3"));
}

//DESTRUCTOR
LevelSelectMenu::~LevelSelectMenu()
{

}

//GET NAME
const char* LevelSelectMenu::getName()
{
    return LEVEL_SELECT_SCREEN_NAME;
}

//KEY UP EVENT
void LevelSelectMenu::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_ESCAPE)
	{
		ScreenManager::getInstance()->switchScreen(SETTINGS_SCREEN_NAME);
	}
}

//BUTTON ACTION
void LevelSelectMenu::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
		//Level 1
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
		game->getLevel()->load("Level1.txt");
		//SETTINGS
		ScreenManager::getInstance()->switchScreen(GAMEINFO_SCREEN_NAME);
    }
	else if(index == 1)
	{
		//Level 2
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
		game->getLevel()->load("Level2.txt");
		//SETTINGS
		ScreenManager::getInstance()->switchScreen(GAMEINFO_SCREEN_NAME);
	}
	else if(index == 2)
	{
		//Level 3
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
		game->getLevel()->load("Level3.txt");
		//SETTINGS
		ScreenManager::getInstance()->switchScreen(GAMEINFO_SCREEN_NAME);
	}
}
