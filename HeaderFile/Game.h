#ifndef GAME_H_
#define GAME_H_

#include "../HeaderFile/Common.h"
#include "../HeaderFile/global.h"

namespace GAME
{
	enum Status_Player_Sellect
	{
		CORRECT,
		INCORRECT,
		NONE_SELLECT,
		IS_CHECKED,
	};

	enum Status_Game
	{
		GAME_WIN,
		GAME_OVER,
		GAME_QUIT,
		NONE,
	};

	// Initialize character
	bool createCharacter(CharacterObject* p_Character);
	bool createListCharacter1();
	bool createListCharacter2();
	bool checkTheSame(const CharacterObject* p_Character1, const CharacterObject* p_Character2);
	void posCharofList1InList2();

	// Create game
	bool createGame();
	
	// Screen 1
	Status_Game Screen1();

	//move screen
	Status_Game moveScreen();

	// creen 2
	void resetListCharacter2();
	Status_Player_Sellect playerSellect(const SDL_Event event, CharacterObject* p_CharCheck, CharacterObject* p_CharDes, int& numCorrect);
	Status_Game Screen2();
}

#endif // !GAME_H_

