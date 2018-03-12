#include "stdafx.h"
#include "Input.h"
#include <SDL.h>

const Uint8* Input::m_keyboardState = new Uint8[SDL_NUM_SCANCODES];
Uint8* Input::m_lastKeyboardState = new Uint8[SDL_NUM_SCANCODES];

void Input::Tick()
{
	for (unsigned int i = 0; i<SDL_NUM_SCANCODES; ++i)
	{
		m_lastKeyboardState[i] = m_keyboardState[i];
	}
	m_keyboardState = SDL_GetKeyboardState(nullptr);
	SDL_PumpEvents();
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


