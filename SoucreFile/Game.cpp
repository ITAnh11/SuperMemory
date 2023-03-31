#include "../HeaderFile/Game.h"

bool GAME::createCharacter(CharacterObject* p_Character)
{
	bool success = true;
	std::string path = "Image/";
	path+=char(rand() % NUMBER_CHARACTER + 1 + '0');
	path += ".png";
	if (!p_Character->loadFromFile(path))
	{
		printf("Failed to load texture image Character!\n");
		success = false;
	}
	else
	{
		p_Character->setClip(WALKING_ANIMATION_FRAMES);
		p_Character->randomLeftRight();
	}


	return success;
}

bool GAME::createListCharacter1()
{
	g_listCharacter1.clear();

	CharacterObject* p_Charracter;

	for ( int i = 0; i < LEVEL; i++)
	{
		p_Charracter = new CharacterObject();
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

bool GAME::createListCharacter2()
{
	g_listCharacter2.clear();
	g_listCharacter2 = g_listCharacter1;

	CharacterObject* p_Charracter;

	int numCharAdd = rand() % LEVEL + LEVEL;

	for (int i = 0; i < numCharAdd; i++)
	{
		p_Charracter = new CharacterObject();
		if (!createCharacter(p_Charracter))
		{
			printf("Failed to create Character!\n");
			return false;
		}
		else
		{
			int posInsert = rand() % g_listCharacter2.size();
			g_listCharacter2.insert(g_listCharacter2.begin() + posInsert, p_Charracter);
		}
	}

	return true;
}

bool GAME::checkTheSame(const CharacterObject* p_Character1, const CharacterObject* p_Character2)
{
	if (p_Character1->getFilename() != p_Character2->getFilename()) return false;
	if (p_Character1->getLeftRight() != p_Character2->getLeftRight()) return false;
	return true;
}

void GAME::posCharofList1InList2()
{
	int j = g_listCharacter2.size() - 1;
	for (int i = g_listCharacter1.size() - 1; i >= 0; --i)
	{
		while (!checkTheSame(g_listCharacter1.at(i), g_listCharacter2.at(j))) --j;
		posChar1inlist2.insert(posChar1inlist2.begin(), j);
		--j;
	}
}

Status_Game GAME::Screen1()
{
	//Event handler
	SDL_Event e;

	Uint32 frameStart;
	int frameTime;

	int currentCharacter = 0;
	int sizelist1 = g_listCharacter1.size();

	//While application is running
	while (currentCharacter < sizelist1)
	{
		frameStart = SDL_GetTicks();

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				return GAME_QUIT;
			}
		}

		//Clear screen
		SDL_RenderClear(g_Renderer);

		//Render texture to screen
		g_listCharacter1.at(currentCharacter)->handleMove();
		g_listCharacter1.at(currentCharacter)->renderClips(g_listCharacter1.at(currentCharacter)->getRect().x, g_listCharacter1.at(currentCharacter)->getRect().y);

		if (!g_listCharacter1.at(currentCharacter)->getIsMove())
		{
			++currentCharacter;
		}

		g_Screen->render(0, 0);

		//Update screen
		SDL_RenderPresent(g_Renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return NONE;
}

Status_Game GAME::moveScreen()
{
	//Event handler
	SDL_Event event;

	Uint32 frameStart;
	int frameTime;

	while (g_Screen->getIsmove())
	{
		frameStart = SDL_GetTicks();

		//Handle events on queue
		while (SDL_PollEvent(&event) != 0)
		{
			//User requests status
			if (event.type == SDL_QUIT)
			{
				return GAME_QUIT;
			}
		}

		//Clear screen
		SDL_RenderClear(g_Renderer);

		g_Screen->handleMove();
		g_Screen->render(g_Screen->getRect().x, g_Screen->getRect().y);

		//Update screen
		SDL_RenderPresent(g_Renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	return NONE;
}

void GAME::resetListCharacter2()
{
	for (auto c : g_listCharacter2)
	{
		c->reset();
	}
}

Status_Player_Sellect GAME::playerSellect(const SDL_Event event, CharacterObject* p_CharCheck, CharacterObject* p_CharDes, int& numCorrect)
{
	if (p_CharCheck->getIsChecked()) return IS_CHECKED;
	if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.sym == SDLK_SPACE)
		{
			std::cout << "player sellect\n";
			p_CharCheck->isChecked();
			if (checkTheSame(p_CharCheck, p_CharDes))
			{
				++numCorrect;
				std::cout << "Correct\n";
				return CORRECT;
			}
			else
			{
				std::cout << "Incorrect\n";
				return INCORRECT;
			}
		}
	}
	return NONE_SELLECT;
}

Status_Game GAME::Screen2()
{
	//reset list 2
	resetListCharacter2();

	//Event handler
	SDL_Event e;

	Uint32 frameStart;
	int frameTime;

	int currentCharacter1 = 0;
	int currentCharacter2 = 0;
	int numCorrect = 0;
	int sizelist2 = g_listCharacter2.size();
	int sizelist1 = g_listCharacter1.size();

	//While application is running
	while (currentCharacter2 < sizelist2 && currentCharacter1 < sizelist1)
	{
		frameStart = SDL_GetTicks();

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				return GAME_QUIT;
			}

			Status_Player_Sellect ret = playerSellect(e, g_listCharacter2.at(currentCharacter2), g_listCharacter1.at(currentCharacter1), numCorrect);
			if (ret == CORRECT)
			{
				++currentCharacter1;
				std::cout << "num correct is: " << numCorrect << "\n";
				if (currentCharacter1 == sizelist1)
				{
					std::cout << "WIN\n";
					return GAME_WIN;
				}
			}
			else 
				if (ret == INCORRECT)
				{
					std::cout << "GAME OVER" << "\n";
					return GAME_OVER;
				}
		}

		//Clear screen
		SDL_RenderClear(g_Renderer);

		//Render texture to screen
		if (g_listCharacter2.at(currentCharacter2)->getIsMove())
		{
			g_listCharacter2.at(currentCharacter2)->handleMove();
			g_listCharacter2.at(currentCharacter2)->renderClips(g_listCharacter2.at(currentCharacter2)->getRect().x, g_listCharacter2.at(currentCharacter2)->getRect().y);
		}
		else
		{
			++currentCharacter2;
			if (posChar1inlist2[currentCharacter1] < currentCharacter2)
			{
				std::cout << "GAME OVER" << "\n";
				return GAME_OVER;
			}
		}

		g_Screen->render(g_Screen->getRect().x, g_Screen->getRect().y);

		//Update screen
		SDL_RenderPresent(g_Renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return NONE;
}
