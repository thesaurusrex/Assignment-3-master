//SEE GameInfoSplash.H

#include "GameInfoSplash.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"

//CONSTRUCTOR
GameInfoSplash::GameInfoSplash() : Menu("GAMEINFOSPLASH_Background", NULL)
{

}

//DESTRUCTOR
GameInfoSplash::~GameInfoSplash()
{

}

//GET NAME
const char* GameInfoSplash::getName()
{
    return GAMEINFO_SCREEN_NAME;
}

//KEY UP EVENT
void GameInfoSplash::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_RETURN)
	{
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}
}
