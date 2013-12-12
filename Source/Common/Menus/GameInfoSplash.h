/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	12/11/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		barbie head tile
MODIFIED:		creation date
*/


//DEFINE
#ifndef __GAM_1514_OSX_Game__GameInfoSplash__
#define __GAM_1514_OSX_Game__GameInfoSplash__

//INHERIT
#include "Menu.h"

class GameInfoSplash : public Menu
{
public:
    GameInfoSplash();
    ~GameInfoSplash();
    
    const char* getName();

	void keyUpEvent(int keyCode);
};

#endif
