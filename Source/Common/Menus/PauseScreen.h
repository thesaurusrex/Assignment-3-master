/*
NAME:	Breanna Henry
DATE:	11/26/2013
PURP:	Pause menu
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/

#ifndef __GAM_1514_OSX_Game__PauseScreen__
#define __GAM_1514_OSX_Game__PauseScreen__

#include "Menu.h"

class PauseScreen : public Menu
{
public:
    PauseScreen();
    ~PauseScreen();
    
    const char* getName();

	void keyUpEvent(int keyCode);

private:
    void buttonAction(UIButton* button);
};

#endif
