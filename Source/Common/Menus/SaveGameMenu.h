/*
NAME:	Breanna Henry
DATE:	11/10/2013
PURP:	Save Menu
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#include "Menu.h"

class Level;

class SaveGameMenu : public Menu
{
public:
    SaveGameMenu();
    ~SaveGameMenu();
    
    const char* getName();
	//void getGame();

private:
    void buttonAction(UIButton* button);

	Level* m_Level;
};
