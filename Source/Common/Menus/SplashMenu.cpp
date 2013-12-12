//SEE SplashMENU.H

#include "SplashMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"

//CONSTRUCTOR
SplashMenu::SplashMenu() : Menu("SPLASH_Background", NULL)
{

}

//DESTRUCTOR
SplashMenu::~SplashMenu()
{

}

//GET NAME
const char* SplashMenu::getName()
{
    return SPLASH_MENU_SCREEN_NAME;
}

//KEY UP EVENT
void SplashMenu::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_RETURN)
	{
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}
