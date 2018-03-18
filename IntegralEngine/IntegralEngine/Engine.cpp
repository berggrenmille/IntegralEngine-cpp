#include "stdafx.h"
#include "Engine.h"
#include <SDL.h>
#include "Input.h"
#include "Time.h"
#include "Cursor.h"

namespace IntegralEngine
{


	Engine::Engine()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
		AddWindow(1280, 720);
		Application::Cursor::ToggleSecureCursor();

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
		window->SetFocus();
	}

	void Engine::MainLoop()
	{
		while (m_windows.size() != 0)
		{
			//Tick systems
			Application::Time::Tick();
			Application::Input::Tick();

			//Check for sdl events
			SDL_Event e;
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_WINDOWEVENT)
				{
					for (unsigned int  i = 0; i < m_windows.size(); ++i)
					{
						m_windows[i]->OnEvent(e);
					}
				}
				else if(e.type == SDL_MOUSEMOTION)
				{
					Application::Input::OnEvent(e);
				}
			}

			//Main tick
			for (unsigned int i = 0; i < m_windows.size(); ++i)
			{
				m_windows[i]->Tick();
			}
		
			if(Application::Input::GetMouseMotionRaw().x)
				std::cout << Application::Input::GetMouseMotionRaw().x << std::endl;
		}
	}


	Engine::~Engine()
	{

	}
}


