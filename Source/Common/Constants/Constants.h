/*
RIGHTS:			Copyright (c) 2013 Algonquin College. All rights reserved.
STUDENT:		Breanna Henry
CREATION DATE:	WHO KNOWS
COURSE NUMBER:	GAM1514
PROFESSOR:		Bradley Flood
PURPOSE:		CONSTANTS
MODIFIED:		created by Brad
*/

//DEFINE
#ifndef CONSTANTS_H
#define CONSTANTS_H

//INCLUDE
#include "Game/GameConstants.h"
#include "Menu/MenuConstants.h"
#include "Level/LevelConstants.h"
#include "Resources/ResourceConstants.h"

//For Windows
#if WIN32
#include "../../Windows/Windows Game/Win32Constants.h"
#endif

//For that other OS that people sometimes use
#ifdef __APPLE__
#include "OSXConstants.h"
#endif

#endif  //CONSTANTS_H
