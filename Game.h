#ifndef GAME_H_
#define GAME_H_

#include "Common.h"
#include "global.h"

namespace GAME
{
	// Initialize character
	bool createCharacter(CharacterObject* p_Character);
	bool createListCharacter();

	// Screen 1
	bool Screen1();
}

#endif // !GAME_H_

