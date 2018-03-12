#include "stdafx.h"
#include "Engine.h"
#include <SDL.h>
#include <iostream>
#include "Time.h"
#include "Input.h"

Engine::Engine()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	AddWindow(1280, 720);
	AddWindow(400, 600);
	MainLoop();
}

void Engine::AddWindow(int width, int height)
{
	
	Window* window = new Window(width, height);
	bool success = window->Init();
	
	if (success)
		m_windows.push_back(window);
	else
	{
		std::cout << "Could not create display " + m_windows.size();
		delete window;
	}
}

void Engine::MainLoop()
{
	while(m_windows.size() != 0)
	{
		Time::Tick();
		Input::Tick();

		for (int i = 0; i < m_windows.size(); ++i)
		{
			m_windows[i]->Tick();
		}
	}
}


Engine::~Engine()
{
	
}



