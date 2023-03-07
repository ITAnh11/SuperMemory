#ifndef COMMON_H_
#define COMMON_H_

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>

//Screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int RENDER_DRAW_COLOR_R = 255;
const int RENDER_DRAW_COLOR_G = 255;
const int RENDER_DRAW_COLOR_B = 255;
const int RENDER_DRAW_COLOR_A = 0;

const int COLOR_KEY_R = 0;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;

//The window we'll be rendering to
extern SDL_Window* g_Window;

//The window renderer
extern SDL_Renderer* g_Renderer;

#endif // !COMMON_H_