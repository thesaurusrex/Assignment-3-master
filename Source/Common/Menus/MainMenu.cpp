//SEE MAINMENU.H

#include "MainMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"

//CONSTRUCTOR
MainMenu::MainMenu() : Menu("MAINMENU_Background", NULL)
{
    addButton(new UIButton("MAINMENU_Button_StartGame"));
	addButton(new UIButton("MAINMENU_Button_Settings"));
    addButton(new UIButton("MAINMENU_Button_Highscores"));
    addButton(new UIButton("MAINMENU_Button_LevelEditor"));
	addButton(new UIButton("MAINMENU_Button_Exit"));
}

//DESTRUCTOR
MainMenu::~MainMenu()
{

}

//GET NAME
const char* MainMenu::getName()
{
    return MAIN_MENU_SCREEN_NAME;
}

//BUTTON ACTION
void MainMenu::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
		//Game
        ScreenManager::getInstance()->switchScreen(GAMEINFO_SCREEN_NAME);
    }
	else if(index == 1)
	{
		//Settings
		ScreenManager::getInstance()->switchScreen(SETTINGS_SCREEN_NAME);
	}
    else if(index == 2)
    {
		//Highscores
        ScreenManager::getInstance()->switchScreen(HIGHSCORES_SCREEN_NAME);
    }
    else if (index == 3)
    {
		//Level Editor
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
	else if(index == 4)
	{
		//Exit
		exit(1);
	}
}
