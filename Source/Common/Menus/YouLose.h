/*
NAME:	Breanna Henry
DATE:	11/16/2013
PURP:	YouLose screen
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/

#ifndef __GAM_1514_OSX_Game__YouLose__
#define __GAM_1514_OSX_Game__YouLose__

#include "Menu.h"


class YouLose : public Menu
{
public:
    YouLose();
    ~YouLose();
    
    const char* getName();

	void keyUpEvent(int keyCode);
};

#endif
