#ifndef GAME_H_
#define GAME_H_

#include "../HeaderFile/Common.h"
#include "../HeaderFile/global.h"

namespace GAME
{
	// Initialize character
	bool createCharacter(CharacterObject* p_Character);
	bool createListCharacter1();
	bool createListCharacter2();
	bool checkTheSame(const CharacterObject* p_Character1, const CharacterObject* p_Character2);
	void posCharofList1InList2();

	// Screen 1
	bool Screen1();

	//move screen
	bool moveScreen();

	// creen 2
	void resetListCharacter2();
	bool Screen2();
}

#endif // !GAME_H_

