/*
NAME:	Breanna Henry
DATE:	11/23/2013
PURP:	Level Select Menu
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/

#ifndef __GAM_1514_OSX_Game__LevelSelectMenu__
#define __GAM_1514_OSX_Game__LevelSelectMenu__

#include "Menu.h"

class LevelSelectMenu : public Menu
{
public:
    LevelSelectMenu();
    ~LevelSelectMenu();
    
    const char* getName();

	void keyUpEvent(int keyCode);

private:
    void buttonAction(UIButton* button);
};

#endif
