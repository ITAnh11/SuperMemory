#ifndef GLOBAL_VARIABLE_H_
#define	GLOBAL_VARIABLE_H_

#include "../HeaderFile/Common.h"

#include "../HeaderFile/BaseObject.h"
#include "../HeaderFile/ScreenObject.h"
#include "../HeaderFile/CharacterObject.h"
#include "../HeaderFile/TextObject.h"

//Sceen gameplay
extern ScreenObject* g_Screen;
extern ScreenObject* g_MenuStart;

//List character
extern std::vector <CharacterObject*> g_listCharacter1;
extern std::vector <CharacterObject*> g_listCharacter2;
extern std::vector <int> posChar1inlist2;


// Text
	//Text in game
	extern TextObject g_NoticeSc1;

	extern TextObject g_NumCorrect;
	extern TextObject g_IntructSellect;

	//Text in Menu
	extern TextObject g_GameOver;
	extern TextObject g_PlayAgain;
	extern TextObject g_Quit;

	extern TextObject g_GameWin;
	extern TextObject g_NextLevel;

	extern TextObject g_NewGame;
	extern TextObject g_Continue;
	extern TextObject g_SellectLevel;

	extern TextObject g_ButtonLeft;
	extern TextObject g_ButtonRight;
	extern TextObject g_Sellect;
	extern TextObject g_LevelSellect;

	extern TextObject g_Return_Menu;
	extern TextObject g_B_PlayAgain;

//Sounds effect
	extern Mix_Chunk* g_S_Click;
	extern Mix_Chunk* g_S_GameWin;
	extern Mix_Chunk* g_S_GameOver;
	extern Mix_Chunk* g_S_SellectCorrect;
	extern Mix_Chunk* g_S_CountDown;


//Level
extern int LEVEL;

#endif // !GLOBAL_VARIABLE_H_

