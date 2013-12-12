//SEE WINSCRREN.H

//INCLUDE
#include "WinScreen.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"

//CONSTRUCTOR
WinScreen::WinScreen() : Menu("WIN_Background", NULL)
{
    
}

//DESTRUCTOR
WinScreen::~WinScreen()
{
    
}

//GET NAME
const char* WinScreen::getName()
{
    return YOU_WIN_SCREEN_NAME;
}

//KEY UP EVENT
void WinScreen::keyUpEvent(int keyCode)
{
    //Back to main menu on exit
	if(keyCode == KEYCODE_RETURN)
	{
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
    
    //Exit game on escape
    else if(keyCode == KEYCODE_ESCAPE)
    {
        exit(1);
    }
}
