#include "Game.h"

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

bool GAME::createListCharacter()
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
		//g_listCharacter1.at(currentCharacter)->render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		//std::cout << g_listCharacter1[currentCharacter].getRect().x << " " << g_listCharacter1[currentCharacter].getRect().y << "\n";

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
