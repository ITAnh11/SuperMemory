#include "../HeaderFile/MenuGame.h"

bool MENU::createText()
{
	bool success = true;

	// Open the font
	g_Font = TTF_OpenFont("Font/Bebas_Neue/BebasNeue-Regular.ttf", TEXT_SIZE_BIG);
	if (g_Font == NULL)
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		// Render text
		SDL_Color textColor = {0, 0, 0};
		g_GameOver.loadFromRenderedText("GAME OVER", textColor);
		g_GameOver.setPos(SCREEN_WIDTH / 2 - g_GameOver.getWidth() / 2, 100);

		g_GameWin.loadFromRenderedText("WIN", textColor);
		g_GameWin.setPos(SCREEN_WIDTH / 2 - g_GameWin.getWidth() / 2, 100);
	}

	// Open the font
	g_Font = TTF_OpenFont("Font/Bebas_Neue/BebasNeue-Regular.ttf", TEXT_SIZE_MEDIUM);
	if (g_Font == NULL)
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		// Render text
		SDL_Color textColor = {0, 0, 0};
		g_NewGame.loadFromRenderedText("NEWGAME", textColor);

		g_PlayAgain.loadFromRenderedText("AGAIN", textColor);

		g_Quit.loadFromRenderedText("QUIT", textColor);

		g_NextLevel.loadFromRenderedText("NEXT LEVEL", textColor);

		g_Continue.loadFromRenderedText("CONTINUE", textColor);

		g_Sellect.loadFromRenderedText("SELLECT", textColor);

		g_SellectLevel.loadFromRenderedText("SELLECT LEVEL", textColor);

		g_LevelSellect.loadFromRenderedText("1", textColor);

		g_Return_Menu.loadFromRenderedText("RETURN MENU", textColor);
	}

	// Load Screen PNG texture
	if (!g_MenuStart->loadFromFile("Image/brain.png"))
	{
		printf("Failed to load texture image Screen!\n");
		success = false;
	}

	if (!g_ButtonLeft.loadFromFile("Image/buttonleft.png"))
	{
		printf("Failed to load texture image Screen!\n");
		success = false;
	}

	if (!g_ButtonRight.loadFromFile("Image/buttonright.png"))
	{
		printf("Failed to load texture image Screen!\n");
		success = false;
	}

	return success;
}

MENU::StatusGameOver MENU::GameOVER()
{
	Mix_PlayChannel(-1, g_S_GameOver, 0);

	// Event handler
	SDL_Event e;

	Uint32 frameStart;
	int frameTime;

	g_PlayAgain.setPos(SCREEN_WIDTH / 2 - g_PlayAgain.getWidth() / 2 - 100, 250);
	g_Quit.setPos(SCREEN_WIDTH / 2 - g_Quit.getWidth() / 2, 300);
	g_Return_Menu.setPos(SCREEN_WIDTH / 2 - g_Return_Menu.getWidth() / 2 + 100, 250);

	// While application is running
	while (true)
	{
		frameStart = SDL_GetTicks();

		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				return StatusGameOver::O_QUIT;
			}

			g_Font = TTF_OpenFont("Font/Bebas_Neue/BebasNeue-Regular.ttf", TEXT_SIZE_MEDIUM);

			TextObject::Status_Button ret = g_PlayAgain.handleInputAction(e);
			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_PlayAgain.loadFromRenderedText("AGAIN", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_PlayAgain.loadFromRenderedText("AGAIN", textColor);
				return StatusGameOver::O_PLAY_AGAIN;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_PlayAgain.loadFromRenderedText("AGAIN", textColor);
			}

			ret = g_Quit.handleInputAction(e);

			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_Quit.loadFromRenderedText("QUIT", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_Quit.loadFromRenderedText("QUIT", textColor);
				return StatusGameOver::O_QUIT;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_Quit.loadFromRenderedText("QUIT", textColor);
			}

			ret = g_Return_Menu.handleInputAction(e);

			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_Return_Menu.loadFromRenderedText("RETURN MENU", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_Return_Menu.loadFromRenderedText("RETURN MENU", textColor);
				return StatusGameOver::O_RETURN_MENU;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_Return_Menu.loadFromRenderedText("RETURN MENU", textColor);
			}
		}

		// Clear screen
		SDL_RenderClear(g_Renderer);

		// Render Text
		Uint8 r = rand() % 256;
		Uint8 g = rand() % 256;
		Uint8 b = rand() % 256;
		g_Font = TTF_OpenFont("Font/Bebas_Neue/BebasNeue-Regular.ttf", TEXT_SIZE_BIG);
		SDL_Color textColor = {r, g, b};
		g_GameOver.loadFromRenderedText("GAME OVER", textColor);
		g_GameOver.render(g_GameOver.getPos().x, g_GameOver.getPos().y);

		g_PlayAgain.render(g_PlayAgain.getPos().x, g_PlayAgain.getPos().y);
		g_Quit.render(g_Quit.getPos().x, g_Quit.getPos().y);
		g_Return_Menu.render(g_Return_Menu.getPos().x, g_Return_Menu.getPos().y);

		// Update screen
		SDL_RenderPresent(g_Renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return StatusGameOver::O_NONE;
}

MENU::StatusGameWin MENU::GameWIN()
{
	Mix_PlayChannel(-1, g_S_GameWin, 0);
	// Event handler
	SDL_Event e;

	Uint32 frameStart;
	int frameTime;

	g_NextLevel.setPos(SCREEN_WIDTH / 2 - g_NextLevel.getWidth() / 2 - 100, 250);
	g_Quit.setPos(SCREEN_WIDTH / 2 - g_Quit.getWidth() / 2, 300);
	g_Return_Menu.setPos(SCREEN_WIDTH / 2 - g_Return_Menu.getWidth() / 2 + 100, 250);

	// While application is running
	while (true)
	{
		frameStart = SDL_GetTicks();

		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				return StatusGameWin::W_QUIT;
			}

			g_Font = TTF_OpenFont("Font/Bebas_Neue/BebasNeue-Regular.ttf", TEXT_SIZE_MEDIUM);

			TextObject::Status_Button ret = g_NextLevel.handleInputAction(e);
			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_NextLevel.loadFromRenderedText("NEXT LEVEL", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_NextLevel.loadFromRenderedText("NEXT LEVEL", textColor);
				return StatusGameWin::W_NEXT_LEVEL;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_NextLevel.loadFromRenderedText("NEXT LEVEL", textColor);
			}

			ret = g_Quit.handleInputAction(e);

			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_Quit.loadFromRenderedText("QUIT", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_Quit.loadFromRenderedText("QUIT", textColor);
				return StatusGameWin::W_QUIT;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_Quit.loadFromRenderedText("QUIT", textColor);
			}

			ret = g_Return_Menu.handleInputAction(e);

			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_Return_Menu.loadFromRenderedText("RETURN MENU", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_Return_Menu.loadFromRenderedText("RETURN MENU", textColor);
				return StatusGameWin::W_RETURN_MENU;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_Return_Menu.loadFromRenderedText("RETURN MENU", textColor);
			}
		}

		// Clear screen
		SDL_RenderClear(g_Renderer);

		// Render Text
		Uint8 r = rand() % 256;
		Uint8 g = rand() % 256;
		Uint8 b = rand() % 256;
		g_Font = TTF_OpenFont("Font/Bebas_Neue/BebasNeue-Regular.ttf", TEXT_SIZE_BIG);
		SDL_Color textColor = {r, g, b};
		g_GameWin.loadFromRenderedText("WIN", textColor);
		g_GameWin.render(g_GameWin.getPos().x, g_GameWin.getPos().y);

		g_NextLevel.render(g_NextLevel.getPos().x, g_NextLevel.getPos().y);
		g_Quit.render(g_Quit.getPos().x, g_Quit.getPos().y);
		g_Return_Menu.render(g_Return_Menu.getPos().x, g_Return_Menu.getPos().y);

		// Update screen
		SDL_RenderPresent(g_Renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return StatusGameWin::W_NONE;
}

MENU::StatusGameStart MENU::GameSTART()
{
	// Event handler
	SDL_Event e;

	Uint32 frameStart;
	int frameTime;
	g_NewGame.setPos(SCREEN_WIDTH / 2 - g_NewGame.getWidth() / 2, 50);
	g_Quit.setPos(SCREEN_WIDTH / 2 - g_Quit.getWidth() / 2, 50 + 350);
	g_Continue.setPos(SCREEN_WIDTH / 2 - g_Continue.getWidth() / 2 - 200, 50 + 175);
	g_SellectLevel.setPos(SCREEN_WIDTH / 2 - g_Continue.getWidth() / 2 + 200, 50 + 175);

	// While application is running
	while (true)
	{
		frameStart = SDL_GetTicks();

		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				return StatusGameStart::S_QUIT;
			}

			g_Font = TTF_OpenFont("Font/Bebas_Neue/BebasNeue-Regular.ttf", TEXT_SIZE_MEDIUM);

			TextObject::Status_Button ret = g_NewGame.handleInputAction(e);
			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_NewGame.loadFromRenderedText("NEWGAME", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_NewGame.loadFromRenderedText("NEWGAME", textColor);
				return StatusGameStart::S_NEWGAME;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_NewGame.loadFromRenderedText("NEWGAME", textColor);
			}

			ret = g_Quit.handleInputAction(e);

			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_Quit.loadFromRenderedText("QUIT", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_Quit.loadFromRenderedText("QUIT", textColor);
				return StatusGameStart::S_QUIT;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_Quit.loadFromRenderedText("QUIT", textColor);
			}

			ret = g_Continue.handleInputAction(e);

			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_Continue.loadFromRenderedText("CONTINUE", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_Continue.loadFromRenderedText("CONTINUE", textColor);
				return StatusGameStart::S_CONTINUE;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_Continue.loadFromRenderedText("CONTINUE", textColor);
			}

			ret = g_SellectLevel.handleInputAction(e);

			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_SellectLevel.loadFromRenderedText("SELLECT LEVEL", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				SDL_Color textColor = {0, 0, 0};
				g_SellectLevel.loadFromRenderedText("SELLECT LEVEL", textColor);
				return StatusGameStart::S_SELLECT_LEVEL;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_SellectLevel.loadFromRenderedText("SELLECT LEVEL", textColor);
			}
		}

		// Clear screen
		SDL_RenderClear(g_Renderer);

		g_MenuStart->render(SCREEN_WIDTH / 2 - g_MenuStart->getWidth() / 2, SCREEN_HEIGHT / 2 - g_MenuStart->getHeight() / 2);

		// Render Text
		g_NewGame.render(g_NewGame.getPos().x, g_NewGame.getPos().y);
		g_Quit.render(g_Quit.getPos().x, g_Quit.getPos().y);
		g_Continue.render(g_Continue.getPos().x, g_Continue.getPos().y);
		g_SellectLevel.render(g_SellectLevel.getPos().x, g_SellectLevel.getPos().y);

		// Update screen
		SDL_RenderPresent(g_Renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return StatusGameStart::NONE;
}

void MENU::SellectLevel()
{
	// Event handler
	SDL_Event e;

	Uint32 frameStart;
	int frameTime;

	g_ButtonLeft.setPos(SCREEN_WIDTH / 2 - g_ButtonLeft.getWidth() / 2 - 100, 200);
	g_ButtonRight.setPos(SCREEN_WIDTH / 2 - g_ButtonRight.getWidth() / 2 + 100, 200);
	g_Sellect.setPos(SCREEN_WIDTH / 2 - g_Sellect.getWidth() / 2, 200 + 100);

	int levelSellect = 1;

	// While application is running
	while (true)
	{
		frameStart = SDL_GetTicks();

		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				return;
			}

			g_Font = TTF_OpenFont("Font/Bebas_Neue/BebasNeue-Regular.ttf", TEXT_SIZE_MEDIUM);

			TextObject::Status_Button ret = g_Sellect.handleInputAction(e);
			if (ret == TextObject::B_INSIDES)
			{
				SDL_Color textColor = {100, 255, 0};
				g_Sellect.loadFromRenderedText("SELLECT", textColor);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				LEVEL = levelSellect;
				return;
			}
			else
			{
				SDL_Color textColor = {0, 0, 0};
				g_Sellect.loadFromRenderedText("SELLECT", textColor);
			}

			ret = g_ButtonLeft.handleInputAction(e);

			if (ret == TextObject::B_INSIDES)
			{
				// g_ButtonLeft.setColor(0, 255, 0);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				--levelSellect;
				g_ButtonLeft.setColor(0, 255, 0);
				if (levelSellect == 0)
					levelSellect = 1;
			}
			else
			{
				g_ButtonLeft.setColor(0, 0, 0);
			}

			ret = g_ButtonRight.handleInputAction(e);

			if (ret == TextObject::B_INSIDES)
			{
				// g_ButtonRight.setColor(0, 255, 0);
			}
			else if (ret == TextObject::B_PRESS)
			{
				Mix_PlayChannel(-1, g_S_Click, 0);
				++levelSellect;
				g_ButtonRight.setColor(0, 255, 0);
			}
			else
			{
				g_ButtonRight.setColor(0, 0, 0);
			}
		}

		// Clear screen
		SDL_RenderClear(g_Renderer);

		// Render Text
		g_ButtonLeft.render(g_ButtonLeft.getPos().x, g_ButtonLeft.getPos().y);
		g_ButtonRight.render(g_ButtonRight.getPos().x, g_ButtonRight.getPos().y);
		g_Sellect.render(g_Sellect.getPos().x, g_Sellect.getPos().y);

		g_Font = TTF_OpenFont("Font/Bebas_Neue/BebasNeue-Regular.ttf", TEXT_SIZE_BIG);
		SDL_Color textColor = {0, 0, 0};
		g_LevelSellect.loadFromRenderedText(COMMONFUNC::intTostring(levelSellect), textColor);
		g_LevelSellect.render(SCREEN_WIDTH / 2 - g_LevelSellect.getWidth() / 2, 190);

		// Update screen
		SDL_RenderPresent(g_Renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

void MENU::loadSaveGame()
{
	std::ifstream filein("savegame.txt");
	if (!filein)
	{
		printf("Can't open file save\n");
	}
	else
	{
		std::string s;
		int p_level;
		// Load last level
		filein >> s;
		filein >> p_level;
		LEVEL = p_level;
	}
}

void MENU::createSaveGame()
{
	std::ofstream fileout("savegame.txt");
	if (!fileout)
	{
		printf("Can't create file save");
	}
	else
	{
		fileout << "LASTLEVEL ";
		fileout << LEVEL << "\n";
	}
}
