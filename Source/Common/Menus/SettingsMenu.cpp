//SEE SettingsMenu.H

#include "SettingsMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"

//CONSTRUCTOR
SettingsMenu::SettingsMenu() : Menu("SETTINGS_Background", NULL)
{
    addButton(new UIButton("SETTINGS_Button_Baby"));
	addButton(new UIButton("SETTINGS_Button_Toddler"));
    addButton(new UIButton("SETTINGS_Button_BigKid"));
	addButton(new UIButton("SETTINGS_Button_QuickGame"));
	addButton(new UIButton("SETTINGS_Button_RegularGame"));
	addButton(new UIButton("SETTINGS_Button_LongGame"));
	addButton(new UIButton("SETTINGS_Button_LimitedScore"));
	addButton(new UIButton("SETTINGS_Button_UnlimitedScore"));
	addButton(new UIButton("SETTINGS_Button_Fight"));
}

//DESTRUCTOR
SettingsMenu::~SettingsMenu()
{

}

//GET NAME
const char* SettingsMenu::getName()
{
    return SETTINGS_SCREEN_NAME;
}

//KEY UP EVENT
void SettingsMenu::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_ESCAPE)
	{
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}

//BUTTON ACTION
void SettingsMenu::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
		//Easy
    }
	else if(index == 1)
	{
		//Medium
		//set creep movement speed up
	}
    else if(index == 2)
    {
		//Hard
		//set creep movement speed up
		//set tower cost up
    }
	else if(index == 3)
	{
		//time short
	}
	else if(index == 4)
	{
		//time med
	}
	else if(index == 5)
	{
		//unlimited time
	}
	else if(index == 6)
	{
		//limited max gold
	}
	else if(index == 7)
	{
		//unlimited gold
	}
	else if(index == 8)
	{
		//Level Select
		ScreenManager::getInstance()->switchScreen(LEVEL_SELECT_SCREEN_NAME);
	}
}
