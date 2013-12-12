/*
 RIGHTS:		Copyright (c) 2013 Algonquin College. All rights reserved.
 STUDENT:		Breanna Henry
 CREATION DATE:	12/12/2013
 COURSE NUMBER:	GAM1514
 PROFESSOR:		Bradley Flood
 PURPOSE:		Babysitter
 MODIFIED:		creationdate
 */

//DEFINE
#ifndef __GAM_1514_OSX_Game__WinScreen__
#define __GAM_1514_OSX_Game__WinScreen__

//INHERIT
#include "Menu.h"

class WinScreen : public Menu
{
public:
    WinScreen();
    ~WinScreen();
    
    const char* getName();
    
	void keyUpEvent(int keyCode);
};

#endif /* defined(__GAM_1514_OSX_Game__WinScreen__) */
