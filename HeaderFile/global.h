#ifndef GLOBAL_VARIABLE_H_
#define	GLOBAL_VARIABLE_H_

#include "../HeaderFile/Common.h"

#include "../HeaderFile/BaseObject.h"
#include "ScreenObject.h"
#include "CharacterObject.h"

//Sceen gameplay
extern ScreenObject* g_Screen;

//List character
extern std::vector <CharacterObject*> g_listCharacter1;
extern std::vector <CharacterObject*> g_listCharacter2;
extern std::vector <int> posChar1inlist2;

//Level
extern int LEVEL;

#endif // !GLOBAL_VARIABLE_H_

