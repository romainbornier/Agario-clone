#include <SDL.h>
#include <stdio.h>

#include "graphics.h"
#include "input.h"
#include "tools.h"
#include "client.h"

#ifdef main
#undef main
#endif

void CClient::Render()
{
	m_Graphics.DrawQuad(100, 100, 256, 256);


	m_Graphics.SwapBuffer();
}

bool CClient::Init()
{
	// Use Opengl 3.2
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Log("client", "failed to init SDL: %s", SDL_GetError());
		return false;
	}

	if(!m_Graphics.Init())
	{
		Log("client", "failed to init graphics");
		return false;
	}

	return true;
}

void CClient::Run()
{
	m_Running = true;

	if(!Init())
		return;

	while(m_Running)
	{
		
		if(!m_Input.Update())
			m_Running = false; // SDL_Quit

		Render();
	}

	SDL_Quit();	
}


int main(int argc, const char **argv)
{
	CClient Client;
	Client.Run();

	return 0;
}