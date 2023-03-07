#include "Common.h"
#include "global.h"

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
		g_Window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	if (!g_Screen.loadFromFile("Image/screen.png"))
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	if (!g_Character.loadFromFile("Image/2.png"))
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	else
	{
		g_Character.setClip(WALKING_ANIMATION_FRAMES);
		g_Character.randomLeftRight();
		std::cout << g_Character.getLeftRight();
	}

	return success;
}

void close()
{
	//Free loaded image
	g_Screen.free();
	g_Character.free();

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
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			Uint32 frameStart;
			int frameTime;

			//While application is running
			while (!quit)
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
				g_Character.handleMove();
				g_Character.renderClips(g_Character.getRect().x, g_Character.getRect().y);
				g_Screen.render(0, 0);

				//Update screen
				SDL_RenderPresent(g_Renderer);

				frameTime = SDL_GetTicks() - frameStart;
				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}