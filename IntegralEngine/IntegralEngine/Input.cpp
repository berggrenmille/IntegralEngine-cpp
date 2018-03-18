#include "stdafx.h"
#include "Input.h"
#include <SDL.h>
#include "Window.h"

const Uint8* Input::m_keyboardState = new Uint8[SDL_NUM_SCANCODES];
Uint8* Input::m_lastKeyboardState = new Uint8[SDL_NUM_SCANCODES];
Uint32 Input::m_mouseState = 0;
Uint32 Input::m_lastMouseState = 0;
Sint32 Input::mouseMotionX = 0;
Sint32 Input::mouseMotionY = 0;
Sint32 Input::mousePosGlobalX = 0; Sint32 Input::mousePosGlobalY = 0;
Sint32 Input::lastMousePosGlobalX = 0; Sint32 Input::lastMousePosGlobalY = 0;


void Input::Tick()
{
	//Save previous states
	for (unsigned int i = 0; i<SDL_NUM_SCANCODES; ++i)
	{
		m_lastKeyboardState[i] = m_keyboardState[i];
	}
	m_lastMouseState = m_mouseState;
	//Get new states
	m_keyboardState = SDL_GetKeyboardState(nullptr);
	lastMousePosGlobalX = mousePosGlobalX; lastMousePosGlobalY = mousePosGlobalY;
	m_mouseState = SDL_GetMouseState(&mousePosGlobalX, &mousePosGlobalY);
	mouseMotionX = 0;
	mouseMotionY = 0;
	SDL_PumpEvents();
}

void Input::OnEvent(SDL_Event& e)
{
	if(e.window.windowID == Window::GetCurrentWindow()->GetWindowID())
		mouseMotionX = e.motion.xrel;
		mouseMotionY = e.motion.yrel;	
}

bool Input::GetKeyDown(SDL_Keycode key)
{
	return m_keyboardState[SDL_GetScancodeFromKey(key)] && !m_lastKeyboardState[SDL_GetScancodeFromKey(key)];
}

bool Input::GetKeyUp(SDL_Keycode key)
{
	return !m_keyboardState[SDL_GetScancodeFromKey(key)] && m_lastKeyboardState[SDL_GetScancodeFromKey(key)];
}

bool Input::GetKeyHold(SDL_Keycode key)
{
	return m_keyboardState[SDL_GetScancodeFromKey(key)];
}

bool Input::GetMouseDown(int i)
{
	return (m_mouseState & SDL_BUTTON(i)) && !(m_lastMouseState & SDL_BUTTON(i));
}

bool Input::GetMouseUp(int i)
{
	return !(m_mouseState & SDL_BUTTON(i)) && (m_lastMouseState & SDL_BUTTON(i));
}

bool Input::GetMouseHold(int i)
{
	return m_mouseState & SDL_BUTTON(i);
}

Vector2 Input::GetMouseMotionRaw()
{
	return Vector2(mouseMotionX, mouseMotionY);
}

Vector2 Input::GetMouseMotion()
{
	return Vector2(mousePosGlobalX - lastMousePosGlobalX, mousePosGlobalY - lastMousePosGlobalY);
}



