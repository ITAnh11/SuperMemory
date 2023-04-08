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
#include <fstream>

#include "BaseObject.h"

//Screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FPS = 20;
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
const int SCREEN_SPEED = 3;
const int CHARACTER_SPEED = 16;

//Number Frame
const int ANIMATION_FRAMES = 4;

//Number character
const int NUMBER_CHARACTER = 4;

//Size Text
const int TEXT_SIZE_BIG = 80;
const int TEXT_SIZE_MEDIUM = 40;
const int TEXT_SIZE_SMALL = 20;

//Direction character
enum LeftRight
{
    LEFT = -1,
    RIGHT = 1,
};

enum Status_Player_Sellect
{
    CORRECT,
    INCORRECT,
    NONE_SELLECT,
    IS_CHECKED,
};

enum Status_Game
{
    GAME_WIN,
    GAME_OVER,
    GAME_QUIT,
    NONE,
};

//The window we'll be rendering to
extern SDL_Window* g_Window;

//The window renderer
extern SDL_Renderer* g_Renderer;

//Globally used font
extern TTF_Font* g_Font;

namespace COMMONFUNC
{
    std::string intTostring(int n);
}

#endif // !COMMON_H_