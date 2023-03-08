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
const int FPS = 16;
const int frameDelay = 1000 / FPS;

//Color
const int RENDER_DRAW_COLOR_R = 255;
const int RENDER_DRAW_COLOR_G = 255;
const int RENDER_DRAW_COLOR_B = 255;
const int RENDER_DRAW_COLOR_A = 0;

const int COLOR_KEY_R = 0;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;

//Speed
const int SCREEN_SPEED = 4;
const int CHARACTER_SPEED = 8;

//Number Frame
const int WALKING_ANIMATION_FRAMES = 4;

//Number character
const int NUMBER_CHARACTER = 3;

//Direction character
enum LeftRight
{
    LEFT = -1,
    RIGHT = 1,
};

//The window we'll be rendering to
extern SDL_Window* g_Window;

//The window renderer
extern SDL_Renderer* g_Renderer;

#endif // !COMMON_H_