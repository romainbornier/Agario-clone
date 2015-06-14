#pragma once

class CGraphics
{
	typedef struct { float x, y, z; } CPoint;
	typedef struct { float u, v; } CTexCoord;
	typedef struct { float r, g, b, a; } CColor;

	typedef struct
	{
		CPoint m_Pos;
		CTexCoord m_Tex;
		CColor m_Color;
	} CVertex;

	enum
	{
		VERTICES_POINT = 1,
		VERTICES_LINE,
		VERTICES_TRIANGLE,
		VERTICES_QUAD,
		MAX_VERTICES = 16 * 1024,
	};

	CVertex m_aVertices[MAX_VERTICES];

	//CVertex m_aVertices[MAX_VERTICES];
	SDL_Window *m_pWindow;
	int m_NumVertices;

	void Flush();

public:
	bool Init();
	void SwapBuffer();

	void SetColor(float r, float g, float b);
	void DrawQuad(float x, float y, float w, float h);
};