//SEE SAVEGAMEMENU.H

#include "SaveGameMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../OpenGL/OpenGL.h"
#include "../Screen Manager/ScreenManager.h"


//CONSTRUCTOR------------------------------------------------
SaveGameMenu::SaveGameMenu() : Menu("Background_SaveGameScreen", NULL)
{
	//Create buttons
	//false button because stuff was all weird
	addButton(new UIButton("Button_SaveLevel0"));
	//Actual buttons
	addButton(new UIButton("Button_SaveLevel1"));
	addButton(new UIButton("Button_SaveLevel2"));
	addButton(new UIButton("Button_SaveLevel3"));
	addButton(new UIButton("Button_SaveLevel4"));
	addButton(new UIButton("Button_SaveLevel5"));
	addButton(new UIButton("Button_SaveLevel6"));
}

//DESTRUCTOR-------------------------------------------------
SaveGameMenu::~SaveGameMenu()
{

}

//GET NAME---------------------------------------------------
const char* SaveGameMenu::getName()
{
	return SAVE_GAME_MENU_SCREEN_NAME;
}

//KEY UP EVENT-----------------------------------------------
void SaveGameMenu::buttonAction(UIButton* button)
{
	int index = getIndexForButton(button);
    if(index == 0)
    {
		if(m_Level != NULL)
		{
			m_Level->save("Level1.txt");
			ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
		}
    }
    else if(index == 1)
    {
		if(m_Level != NULL)
		{
			
			ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
		}
    }
    else if (index == 2)
    {
		m_Level->save("Level3.txt");
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
	else if (index == 3)
    {
		m_Level->save("Level4.txt");
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
	else if (index == 4)
    {
		m_Level->save("Level5.txt");
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
	else if (index == 5)
    {
		m_Level->save("Level6.txt");
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
	else if (index == 6)
    {
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
}