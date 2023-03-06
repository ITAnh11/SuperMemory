#ifndef COMMON_H_
#define COMMON_H_

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
static SDL_Window* gWindow = NULL;
	
//The window renderer
static SDL_Renderer* gRenderer = NULL;

//Current displayed texture
static SDL_Texture* gTexture = NULL;

#endif // !COMMON_H_