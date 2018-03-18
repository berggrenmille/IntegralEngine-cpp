#include "stdafx.h"
#include "Cursor.h"
#include <SDL.h>
#include "Window.h"

bool Cursor::m_locked = false;
bool Cursor::m_secured = false;

bool Cursor::IsLocked()
{
	return m_locked;
}

bool Cursor::IsSecured()
{
	return m_secured;
}

void Cursor::ToggleLockCursor()
{
	if(m_locked)
	{
		SDL_SetRelativeMouseMode(SDL_FALSE);
	}
	else
	{
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	m_locked = !m_locked;
}

void Cursor::ToggleSecureCursor()
{
	if (m_secured)
	{
		SDL_SetWindowGrab(Window::GetCurrentWindow()->GetInternalWindow(), SDL_FALSE);
	}
	else
	{
		SDL_SetWindowGrab(Window::GetCurrentWindow()->GetInternalWindow(), SDL_TRUE);
	}
	m_secured = !m_secured;
}

void Cursor::FreeCursor()
{
	SDL_SetWindowGrab(Window::GetCurrentWindow()->GetInternalWindow(), SDL_FALSE);
	m_secured = false;
}

void Cursor::ToggleCursor()
{
	if (SDL_ShowCursor(-1) == 1)
		SDL_ShowCursor(0);
	else
		SDL_ShowCursor(1);
}
