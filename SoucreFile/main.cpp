#include "../HeaderFile/Common.h"
#include "../HeaderFile/global.h"
#include "../HeaderFile/Game.h"
#include "../HeaderFile/MenuGame.h"

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

bool init()
{
	//Initialize random number generators
	srand(time(NULL));

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		g_Window = SDL_CreateWindow("Super Memory", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (g_Window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			g_Renderer = SDL_CreateRenderer(g_Window, -1, SDL_RENDERER_ACCELERATED);
			if (g_Renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(g_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;
	if (!MENU::createText())
	{
		printf("Failed to create text Menu\n");
		success = false;
	}
	return true;
}

void close()
{
	//Free loaded image
	g_Screen->free();
	g_MenuStart->free();

	//free text
	g_IntructSellect.free();
	g_NumCorrect.free();
	g_NoticeSc1.free();
	g_GameOver.free();
	g_PlayAgain.free();
	g_Quit.free();
	g_GameWin.free();
	g_NextLevel.free();
	g_NewGame.free();
	g_Continue.free();
	g_Sellect.free();
	g_ButtonLeft.free();
	g_ButtonRight.free();
	g_SellectLevel.free();
	g_LevelSellect.free();
	
	//free list character
	g_listCharacter1.clear();
	g_listCharacter2.clear();

	//Free global font
	TTF_CloseFont(g_Font);
	g_Font = NULL;

	//Destroy window	
	SDL_DestroyRenderer(g_Renderer);
	SDL_DestroyWindow(g_Window);
	g_Window = NULL;
	g_Renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}

		bool begin = true;

		// Run game
		while (true)
		{
			if (begin == true)
			{
				begin = false;
				MENU::StatusGameStart stGS = MENU::GameSTART();
				if (stGS == MENU::StatusGameStart::S_NEWGAME) { LEVEL = 1; }
				else if (stGS == MENU::StatusGameStart::S_QUIT) break;
				else if (stGS == MENU::StatusGameStart::S_CONTINUE)
				{
					MENU::loadSaveGame();
				}
				else if (stGS == MENU::StatusGameStart::S_SELLECT_LEVEL)
				{
					MENU::SellectLevel();
				}

			}
			Status_Game stGame;
			if (GAME::createGame() == false)
			{
				printf("Failed to create game!\n");
			}
			if (GAME::Screen1() == GAME_QUIT) break;
			if (GAME::moveScreen() == GAME_QUIT) break;

			stGame = GAME::Screen2();
			if (stGame == GAME_QUIT) break;
			else
				if (stGame == GAME_OVER)
				{
					MENU::StatusGameOver stGO = MENU::GameOVER();
					if (stGO == MENU::StatusGameOver::O_QUIT) break;
					if (stGO == MENU::StatusGameOver::O_PLAY_AGAIN) continue;
				}
				else if (stGame == GAME_WIN)
				{
					MENU::StatusGameWin stGW = MENU::GameWIN();
					if (stGW == MENU::StatusGameWin::W_QUIT) break;
					if (stGW == MENU::StatusGameWin::W_NEXT_LEVEL)
					{
						LEVEL++;
						continue;
					}
				}
		}
		MENU::createSaveGame();
	}

	//Free resources and close SDL
	close();

	return 0;
}