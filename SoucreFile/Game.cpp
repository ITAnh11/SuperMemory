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

bool GAME::Screen1()
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	Uint32 frameStart;
	int frameTime;

	int currentCharacter = 0;
	int sizelist1 = g_listCharacter1.size();

	//While application is running
	while (currentCharacter < sizelist1 && !quit)
	{
		frameStart = SDL_GetTicks();

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
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

	return quit;
}

bool GAME::moveScreen()
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event event;

	Uint32 frameStart;
	int frameTime;

	while (g_Screen->getIsmove() && !quit)
	{
		frameStart = SDL_GetTicks();

		//Handle events on queue
		while (SDL_PollEvent(&event) != 0)
		{
			//User requests status
			if (event.type == SDL_QUIT)
			{
				quit = true;
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
	return quit;
}

void GAME::resetListCharacter2()
{
	for (auto c : g_listCharacter2)
	{
		c->reset();
	}
}

bool GAME::Screen2()
{
	//reset list 2
	resetListCharacter2();

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	Uint32 frameStart;
	int frameTime;

	int currentCharacter = 0;
	int sizelist2 = g_listCharacter2.size();

	//While application is running
	while (currentCharacter < sizelist2 && !quit)
	{
		frameStart = SDL_GetTicks();

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		//Clear screen
		SDL_RenderClear(g_Renderer);

		//Render texture to screen
		g_listCharacter2.at(currentCharacter)->handleMove();
		g_listCharacter2.at(currentCharacter)->renderClips(g_listCharacter2.at(currentCharacter)->getRect().x, g_listCharacter2.at(currentCharacter)->getRect().y);

		if (!g_listCharacter2.at(currentCharacter)->getIsMove())
		{
			++currentCharacter;
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

	return quit;
}
