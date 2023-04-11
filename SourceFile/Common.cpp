#include "../HeaderFile/Common.h"

//The window we'll be rendering to
SDL_Window* g_Window = NULL;

//The window renderer
SDL_Renderer* g_Renderer = NULL;

//Globally used font
TTF_Font* g_Font = NULL;

std::string COMMONFUNC::intTostring(int n)
{
	std::string result = "";
	while (n)
	{
		result = char(n % 10 + '0') + result;
		n /= 10;
	}
	return result;
}
