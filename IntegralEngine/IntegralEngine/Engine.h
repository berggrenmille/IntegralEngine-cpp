#pragma once
#include "Window.h"
namespace IntegralEngine
{
	class Engine
	{
	public:
		Engine();
		void AddWindow(int width = 1280, int height = 720);
		void MainLoop();
		~Engine();
	private:
		std::vector<Window*> m_windows;
	};
}