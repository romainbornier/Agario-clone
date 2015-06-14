#pragma once

class CClient
{
	CInput m_Input;
	CGraphics m_Graphics;
	bool m_Running;

	void HandleEvents();
	void Render();
	bool Init();

public:
	void Run();
	void Exit() { m_Running = false; }
};