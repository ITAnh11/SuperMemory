#ifndef GLOBAL_VARIABLE_H_
#define	GLOBAL_VARIABLE_H_

#include "../HeaderFile/Common.h"

#include "../HeaderFile/BaseObject.h"
#include "../HeaderFile/ScreenObject.h"
#include "../HeaderFile/CharacterObject.h"
#include "../HeaderFile/TextObject.h"

//Sceen gameplay
extern ScreenObject* g_Screen;

//List character
extern std::vector <CharacterObject*> g_listCharacter1;
extern std::vector <CharacterObject*> g_listCharacter2;
extern std::vector <int> posChar1inlist2;

// text
extern TextObject g_NoticeSc1;

extern TextObject g_NumCorrect;
extern TextObject g_IntructSellect;

//Level
extern int LEVEL;

#endif // !GLOBAL_VARIABLE_H_

