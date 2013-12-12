//SEE Highscores.H

#include "Highscores.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"

//CONSTRUCTOR
Highscores::Highscores() : Menu("HIGHSCORES_Background", NULL)
{
   
}

//DESTRUCTOR
Highscores::~Highscores()
{

}

//GET NAME
const char* Highscores::getName()
{
    return HIGHSCORES_SCREEN_NAME;
}

//KEY UP EVENT
void Highscores::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_RETURN)
	{
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}
