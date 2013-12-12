/*
NAME:	Breanna Henry
DATE:	11/19/2013
PURP:	Highscores
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/

#ifndef __GAM_1514_OSX_Game__Highscores__
#define __GAM_1514_OSX_Game__Highscores__

#include "Menu.h"

class Highscores : public Menu
{
public:
    Highscores();
    ~Highscores();
    
    const char* getName();

	void keyUpEvent(int keyCode);
};

#endif
