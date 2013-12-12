/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	7/3/2013
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		main game
MODIFIED:		12/11/2013
                -added tower placement stuff
				12/12/2013
				-added HUD menu
*/


//DEFINE
#ifndef GAME_H
#define GAME_H

//INCLUDE
#include <vector>
#include "../Screen Manager/Screen.h"
#include "../UI/UISideMenu.h"

//CLASSES
class UISideMenu;
class GameObject;
class Level;
class UIFont;

class Game : public Screen, public UISideMenuListener
{
public:
	Game();
	~Game();

	//Game lifecycle methods
	void update(double delta);
	void paint();
	void reset();

	//Screen name, must be implemented, it's a pure virtual method in the Screen class
	const char* getName();
  
	Level* getLevel();

private:
	void sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex);
	void sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex);
  
	//Mouse Events
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickDownEvent(float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);
    void mouseRightClickDownEvent(float positionX, float positionY);
    void mouseRightClickUpEvent(float positionX, float positionY);
	void keyUpEvent(int keyCode);

	//Level pointer
	Level* m_Level;

	int m_SelectedTileIndex;

	//Game Side Menus
	UISideMenu* m_TowerMenu;
	UISideMenu* m_HUDMenu;

	bool m_IsMouseDown;
	
	//Temp font pointer
    UIFont* m_Font;
};

#endif