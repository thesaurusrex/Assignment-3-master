//SEE SPLASHMENU.H

#include "../OpenGL/OpenGL.h"
#include "SplashMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"


//CONSTRUCTOR------------------------------------------------
SplashMenu::SplashMenu() : Menu(NULL, NULL)
{
	//Create background
	m_SplashBackground = new OpenGLTexture("Background_SplashScreen");
}

//DESTRUCTOR-------------------------------------------------
SplashMenu::~SplashMenu()
{
	//Delete background
	if(m_SplashBackground != NULL)
	{
		delete m_SplashBackground;
		m_SplashBackground = NULL;
	}
}

//GET NAME---------------------------------------------------
const char* SplashMenu::getName()
{
	return SPLASH_MENU_SCREEN_NAME;
}

//PAINT(probobly should have replaced one of those NULLs?)---
void SplashMenu::paint()
{
	//Paint the background
	OpenGLRenderer::getInstance()->drawTexture(m_SplashBackground, 0.0f, 0.0f);
}

//KEY UP EVENT-----------------------------------------------
void SplashMenu::keyUpEvent(int keyCode)
{
	//ENTER key pressed
	if(keyCode == KEYCODE_RETURN)
	{
		//go to main menu
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}