#ifndef GLOBAL_VARIABLE_H_
#define	GLOBAL_VARIABLE_H_

#include "Common.h"

#include "BaseObject.h"
#include "ScreenObject.h"
#include "CharacterObject.h"

//Sceen gameplay
extern ScreenObject g_Screen;

//List character
extern std::vector <CharacterObject> g_listCharacter1;

//Level
extern int LEVEL;

#endif // !GLOBAL_VARIABLE_H_

