/*
NAME:	Breanna Henry
DATE:	11/10/2013
PURP:	Splash menu
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/

#include "Menu.h"


class SplashMenu : public Menu
{
public:
    SplashMenu();
    ~SplashMenu();
    
    const char* getName();

	void paint();

	void keyUpEvent(int keyCode);

private:
	//Background texture
	OpenGLTexture* m_SplashBackground;
};