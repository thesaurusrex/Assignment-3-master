/*
NAME:	Bradley Flood & B the bre-est bre breanna henry
DATE:	7/3/2013
PURP:	Level Editor
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef __GAM_1514_OSX_Game__LevelEditor__
#define __GAM_1514_OSX_Game__LevelEditor__

#include "../Screen Manager/Screen.h"
#include "../UI/UISideMenu.h"

class UISideMenu;
class Level;

class LevelEditor : public Screen, public UISideMenuListener
{
public:
    LevelEditor();
    ~LevelEditor();
    
    const char* getName();

    void update(double delta);
    void paint();
    void reset();
    
    void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
    void mouseLeftClickDownEvent(float positionX, float positionY);
    void mouseLeftClickUpEvent(float positionX, float positionY);
    void keyUpEvent(int keyCode);
    
private:
    void sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex);
    void sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex);
    
	//Right hand menu
    UISideMenu* m_TilesMenu;
	//Left hand menu
	UISideMenu* m_DruthersMenu;
	//Save hacks menu
	UISideMenu* m_SaveSlots;
	//Load hacks menu
	UISideMenu* m_LoadSlots;
    //The Level
	Level* m_Level;
    
    bool m_IsMouseDown;
    int m_SelectedTileIndex;
};

#endif /* defined(__GAM_1514_OSX_Game__LevelEditor__) */
