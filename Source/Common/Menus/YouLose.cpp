//SEE YouLose.H

//INCLUDE
#include "YouLose.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"

//CONSTRUCTOR
YouLose::YouLose() : Menu("LOSE_Background", NULL)
{

}

//DESTRUCTOR
YouLose::~YouLose()
{

}

//GET NAME
const char* YouLose::getName()
{
    return YOU_LOSE_SCREEN_NAME;
}

//KEY UP EVENT
void YouLose::keyUpEvent(int keyCode)
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
