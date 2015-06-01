#include <SDL.h>

#include "graphics.h"
#include "tools.h"

bool CGraphics::InitSDL()
{
	//The window we'll be rendering to 
	SDL_Window* window = NULL;

	//The surface contained by the window 
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL 
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Log("gfx", "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		//Create window 
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN);

		if(window == NULL)
		{
			Log("gfx", "Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			//Get window surface 
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white 
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface 
			SDL_UpdateWindowSurface(window);

			//Wait two seconds 
			SDL_Delay(2000);
		}
	}
	return true;
}