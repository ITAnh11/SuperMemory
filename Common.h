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
	
//The surface contained by the window
static SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
static SDL_Surface* gPNGSurface = NULL;

#endif // !COMMON_H_