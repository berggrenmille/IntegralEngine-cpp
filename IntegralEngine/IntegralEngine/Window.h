#pragma once
#include <SDL.h>

class Window
{
public:

	//Init internals
	Window(int width, int height);

	//Init window
	bool Init();

	//Handle incoming events
	void OnEvent(SDL_Event& event);

	//Focus
	void SetFocus();

	//Main loop tick
	void Tick();

	//Cleanup
	void Cleanup();

	//Get window dimensions
	int GetWidth() const;
	int GetHeight() const;

	//Get window info
	int GetWindowID() const;
	SDL_Window* GetInternalWindow() const;
	bool HasMouseFocus() const;
	bool HasKeyboardFocus() const;
	bool IsMinimized() const;
	bool IsShown() const;

	static Window* GetCurrentWindow();

	~Window();
private:
	//Window kernel
	SDL_Window* m_internalWindow;
	SDL_GLContext m_internalContext;
	int m_windowID;

	//Window dimensions
	int m_width;
	int m_height;

	//Window info
	bool m_mouseFocus;
	bool m_keyboardFocus;
	bool m_fullScreen;
	bool m_minimized;
	bool m_shown;

	static Window* m_currentWindow;

};
