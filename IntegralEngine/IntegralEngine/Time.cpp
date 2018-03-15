#include "stdafx.h"
#include "Time.h"
#include <SDL.h>

namespace Time
{
	double time = 0;
	double deltaTime = 0;
	void Tick()
	{
		double lastTime = time;
		time = static_cast<double>(SDL_GetTicks()) / 1000.0;
		deltaTime = time - lastTime;
	}
	
}