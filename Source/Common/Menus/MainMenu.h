/*
NAME:	Bradley Flood
DATE:	10/7/2013
PURP:	Save Menu
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef __GAM_1514_OSX_Game__MainMenu__
#define __GAM_1514_OSX_Game__MainMenu__

#include "Menu.h"


class MainMenu : public Menu
{
public:
    MainMenu();
    ~MainMenu();
    
    const char* getName();

private:
    void buttonAction(UIButton* button);
};

#endif /* defined(__GAM_1514_OSX_Game__MainMenu__) */
