#pragma once
#include <SDL_hints.h>
#include <SDL.h>

class Input
{
	friend class Engine;
public:
	static void Tick();
	static void OnEvent(SDL_Event& e);
	
	static bool GetKeyDown(SDL_Keycode key);
	static bool GetKeyUp(SDL_Keycode key);
	static bool GetKeyHold(SDL_Keycode key);

	static bool GetMouseDown(int i);
	static bool GetMouseUp(int i);
	static bool GetMouseHold(int i);

	static Sint32 mouseX;
	static Sint32 mouseY;
private:
	const static Uint8* m_keyboardState;
	static Uint8* m_lastKeyboardState;

    static Uint32 m_mouseState;
	static Uint32 m_lastMouseState;
	
	
};
