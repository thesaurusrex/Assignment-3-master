//SEE PauseScreen.H

#include "PauseScreen.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"

//CONSTRUCTOR
PauseScreen::PauseScreen() : Menu("PAUSE_Background", NULL)
{
    addButton(new UIButton("PAUSE_Button_Resume"));
	addButton(new UIButton("PAUSE_Button_Restart"));
	addButton(new UIButton("PAUSE_Button_MainMenu"));
}

//DESTRUCTOR
PauseScreen::~PauseScreen()
{

}

//GET NAME
const char* PauseScreen::getName()
{
    return PAUSE_SCREEN_NAME;
}

//KEY UP EVENT
void PauseScreen::keyUpEvent(int keyCode)
{
	
}

//BUTTON ACTION
void PauseScreen::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
		//Resume the game
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
	else if(index == 1)
	{
		//Restart

		//Get pointer to game
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);

		//Reset the game
		game->reset();

		//Start game
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}
	else if(index == 2)
	{
		//Go to main menu
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}
