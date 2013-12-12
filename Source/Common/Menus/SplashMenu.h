/*
NAME:	Breanna Henry
DATE:	11/16/2013
PURP:	SPLASH screen
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef __GAM_1514_OSX_Game__SplashMenu__
#define __GAM_1514_OSX_Game__SplashMenu__

#include "Menu.h"


class SplashMenu : public Menu
{
public:
    SplashMenu();
    ~SplashMenu();
    
    const char* getName();

	void keyUpEvent(int keyCode);
};

#endif
