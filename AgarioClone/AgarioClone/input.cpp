#include <SDL.h>

#include "input.h"

bool CInput::Update()
{
	SDL_Event Event;
	while(SDL_PollEvent(&Event))
	{
		switch(Event.type)
		{
			case SDL_QUIT: return false;
			case SDL_KEYDOWN: //do some key stuff
			case SDL_KEYUP:
		}
	}
	return true;
}
