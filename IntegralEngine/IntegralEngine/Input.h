#pragma once
#include <SDL_hints.h>
#include <SDL.h>

class Input
{
public:
	static void Tick();
	
	static bool GetKeyDown(SDL_Keycode key);
	static bool GetKeyUp(SDL_Keycode key);
	static bool GetKeyHold(SDL_Keycode key);

private:
	const static Uint8* m_keyboardState;
	static Uint8* m_lastKeyboardState;
	
};
