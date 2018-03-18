#pragma once
#include <SDL_hints.h>
#include <SDL.h>

class Input
{
public:
	static void Tick();
	static void OnEvent(SDL_Event& e);
	
	static bool GetKeyDown(SDL_Keycode key);
	static bool GetKeyUp(SDL_Keycode key);
	static bool GetKeyHold(SDL_Keycode key);

	static bool GetMouseDown(int i);
	static bool GetMouseUp(int i);
	static bool GetMouseHold(int i);

	static Vector2 GetMouseMotionRaw();
	static Vector2 GetMouseMotion();

	
private:
	const static Uint8* m_keyboardState;
	static Uint8* m_lastKeyboardState;

    static Uint32 m_mouseState;
	static Uint32 m_lastMouseState;
	
	static Sint32 mouseMotionX;
	static Sint32 mouseMotionY;

	static Sint32 mousePosGlobalX;
	static Sint32 mousePosGlobalY;
	static Sint32 lastMousePosGlobalX;
	static Sint32 lastMousePosGlobalY;
};
