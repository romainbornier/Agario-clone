#include <SDL.h>
#include <SDL_opengl.h>

#include "graphics.h"
#include "tools.h"

void CGraphics::Flush()
{
	if(!m_NumVertices)
		return;

	glVertexPointer(3, GL_FLOAT, sizeof(CVertex), m_aVertices);
	glColorPointer(4, GL_FLOAT, sizeof(CVertex), (char*)m_aVertices + sizeof(float) * 5);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glDrawArrays(GL_QUADS, 0, m_NumVertices);

	m_NumVertices = 0;
}

void CGraphics::DrawQuad(float x, float y, float w, float h)
{
	if(m_NumVertices + VERTICES_QUAD > MAX_VERTICES)
		Flush();

	m_aVertices[m_NumVertices].m_Pos.x = x;
	m_aVertices[m_NumVertices].m_Pos.y = y;
	m_aVertices[m_NumVertices].m_Color = { 1.0f, 0.0f, 0.0f, 1.0f };

	m_aVertices[m_NumVertices + 1].m_Pos.x = x + w;
	m_aVertices[m_NumVertices + 1].m_Pos.y = y;
	m_aVertices[m_NumVertices + 1].m_Color = { 0.0f, 1.0f, 0.0f, 1.0f };

	m_aVertices[m_NumVertices + 2].m_Pos.x = x + w;
	m_aVertices[m_NumVertices + 2].m_Pos.y = y + h;
	m_aVertices[m_NumVertices + 2].m_Color = { 0.0f, 0.0f, 1.0f, 1.0f };

	m_aVertices[m_NumVertices + 3].m_Pos.x = x;
	m_aVertices[m_NumVertices + 3].m_Pos.y = y + h;
	m_aVertices[m_NumVertices + 3].m_Color = { 1.0f, 0.0f, 1.0f, 1.0f };

	m_NumVertices += VERTICES_QUAD;
}

void CGraphics::SwapBuffer()
{
	Flush();
	SDL_GL_SwapWindow(m_pWindow);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool CGraphics::Init()
{
	m_NumVertices = 0;
	m_pWindow = NULL;
	
	for(int i = 0; i < MAX_VERTICES; i++)
		m_aVertices[i].m_Pos.z = 0.0f;

	SDL_GLContext hContext;
	int Flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	m_pWindow = SDL_CreateWindow("Agario Clone",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		512, 512, 
		Flags);
	if(m_pWindow == NULL)
	{
		Log("gfx", "failed to create window: %s", SDL_GetError());
		return false;
	}

	hContext = SDL_GL_CreateContext(m_pWindow);
	if(hContext == NULL)
	{
		Log("gfx/gl", "failed to create context: %s", SDL_GetError());
		return false;
	}

	glEnable(GL_BLEND);
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glAlphaFunc(GL_GREATER, 0);
	glEnable(GL_ALPHA_TEST);
	glDepthMask(0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(0, 512, 512, 0, -1, 1);
	
	
	return true;
}