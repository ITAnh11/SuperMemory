#include "Game.h"

bool GAME::createCharacter(CharacterObject& p_Character)
{
	bool success = true;
	std::string path = "Image/";
	path+=char(rand() % NUMBER_CHARACTER + 1 + '0');
	path += ".png";
	if (!p_Character.loadFromFile(path))
	{
		printf("Failed to load texture image Character!\n");
		success = false;
	}
	else
	{
		p_Character.setClip(WALKING_ANIMATION_FRAMES);
		p_Character.randomLeftRight();
		std::cout << p_Character.getLeftRight() << "\n";
	}

	return success;
}

bool GAME::createListCharacter()
{
	for ( int i = 0; i < LEVEL; i++)
	{
		CharacterObject p_Charracter;
		if (!createCharacter(p_Charracter))
		{
			printf("Failed to create Character!\n");
			return false;
		}
		else
		{
			g_listCharacter1.push_back(p_Charracter);
		}
	}
	return true;
}
