#include "../HeaderFile/global.h"

ScreenObject* g_Screen = new ScreenObject();
ScreenObject* g_MenuStart = new ScreenObject();

std::vector <CharacterObject*> g_listCharacter1;
std::vector <CharacterObject*> g_listCharacter2;
std::vector <int> posChar1inlist2;

TextObject g_NoticeSc1;

TextObject g_NumCorrect;
TextObject g_IntructSellect;

TextObject g_GameOver;
TextObject g_PlayAgain;
TextObject g_Quit;

TextObject g_GameWin;
TextObject g_NextLevel;

TextObject g_NewGame;
TextObject g_Continue;
TextObject g_SellectLevel;

TextObject g_ButtonLeft;
TextObject g_ButtonRight;
TextObject g_Sellect;
TextObject g_LevelSellect;

TextObject g_Return_Menu;
TextObject g_B_PlayAgain;

Mix_Chunk* g_S_Click = NULL;
Mix_Chunk* g_S_GameWin = NULL;
Mix_Chunk* g_S_GameOver = NULL;
Mix_Chunk* g_S_SellectCorrect = NULL;
Mix_Music* g_S_CountDown = NULL;
 
int LEVEL = 2;