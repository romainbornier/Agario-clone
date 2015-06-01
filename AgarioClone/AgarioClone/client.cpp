#include <SDL.h>
#include <stdio.h>

#include "graphics.h"
#include "tools.h"
#include "client.h"

#ifdef main
#undef main
#endif

void CClient::Run()
{
	m_pGraphics->InitSDL();
}


int main(int argc, const char **argv)
{
	CClient Client;

	Client.Run();

	Log("client", "done");


	return 0;
}