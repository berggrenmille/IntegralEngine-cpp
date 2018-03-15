#include "stdafx.h"
#include "Window.h"
#include <GL/glew.h>

int Window::m_currentWindowID = -1;

Window::Window(int width, int height)
	: m_internalWindow(nullptr), m_internalContext(nullptr), m_windowID(-1), m_width(width), m_height(height), m_mouseFocus(true), m_keyboardFocus(true), m_fullScreen(false), m_minimized(false), m_shown(true)
{
	
	//INIT MEMBER VARIABLES
}

bool Window::Init()
{
	//Create the window
	m_internalWindow = SDL_CreateWindow("!TEST!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if(m_internalWindow != nullptr)
	{
		m_keyboardFocus = true;
		m_mouseFocus = true;
		m_shown = true;
		m_windowID = SDL_GetWindowID(m_internalWindow);
	}
	//Apply gl context
	m_internalContext = SDL_GL_CreateContext(m_internalWindow);

	//Init glew
	glewExperimental = GL_TRUE;
	if(GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
	}

	//Setup gl viewport
	glViewport(0, 0, m_width, m_height);
	
	//Validate
	if(m_internalWindow != nullptr && m_internalContext != NULL)
		return true;
	return false;
}

void Window::OnEvent(SDL_Event& event)
{
	if (event.window.windowID == m_windowID)
	{
		switch (event.window.event)
		{
			//Window appeared
		case SDL_WINDOWEVENT_SHOWN:
			m_shown = true;
			break;

			//Window disappeared
		case SDL_WINDOWEVENT_HIDDEN:
			m_shown = false;
			break;

			//Get new dimensions and repaint
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			m_width = event.window.data1;
			m_height = event.window.data2;
			glViewport(0, 0, m_width, m_height);
			break;

			//Mouse enter
		case SDL_WINDOWEVENT_ENTER:
			m_mouseFocus = true;
			break;

			//Mouse exit
		case SDL_WINDOWEVENT_LEAVE:
			m_mouseFocus = false;
			
			break;

			//Keyboard focus gained
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			m_keyboardFocus = true;
			break;

			//Keyboard focus lost
		case SDL_WINDOWEVENT_FOCUS_LOST:
			m_keyboardFocus = false;
			break;

			//Window minimized
		case SDL_WINDOWEVENT_MINIMIZED:
			m_minimized = true;
			break;

			//Window maxized
		case SDL_WINDOWEVENT_MAXIMIZED:
			m_minimized = false;
			break;

			//Window restored
		case SDL_WINDOWEVENT_RESTORED:
			m_minimized = false;
			break;
			//Hide on close
		case SDL_WINDOWEVENT_CLOSE:
			SDL_HideWindow(m_internalWindow);
			break;
		}

	}
}

void Window::SetFocus()
{
	//If window is hidden, show it
	if (!m_shown)
		SDL_ShowWindow(m_internalWindow);
	SDL_RaiseWindow(m_internalWindow);
	m_currentWindowID = m_currentWindowID;
}

void Window::Tick()
{
	
	
}

void Window::Cleanup()
{
	SDL_DestroyWindow(m_internalWindow);
}

int Window::GetWidth() const
{
	return m_width;
}

int Window::GetHeight() const
{
	return m_height;
}

bool Window::HasKeyboardFocus() const
{
	return m_keyboardFocus;
}
bool Window::HasMouseFocus() const
{
	return m_mouseFocus;
}
bool Window::IsMinimized() const
{
	return m_minimized;
}
bool Window::IsShown() const
{
	return m_shown;
}

int Window::GetCurrentID()
{
	return m_currentWindowID;
}

Window::~Window()
{
}
