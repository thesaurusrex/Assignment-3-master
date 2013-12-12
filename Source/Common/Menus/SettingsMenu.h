/*
NAME:	Breanna Henry
DATE:	11/16/2013
PURP:	Settings Menu
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/

#ifndef __GAM_1514_OSX_Game__SettingsMenu__
#define __GAM_1514_OSX_Game__SettingsMenu__

#include "Menu.h"

class SettingsMenu : public Menu
{
public:
    SettingsMenu();
    ~SettingsMenu();
    
    const char* getName();

	void keyUpEvent(int keyCode);

private:
    void buttonAction(UIButton* button);
};

#endif
