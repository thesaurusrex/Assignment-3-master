/*
NAME:	Breanna Henry
DATE:	11/10/2013
PURP:	Load Menu
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#include "Menu.h"


class LoadGameMenu : public Menu
{
public:
    LoadGameMenu();
    ~LoadGameMenu();
    
    const char* getName();

private:
    void buttonAction(UIButton* button);
};
