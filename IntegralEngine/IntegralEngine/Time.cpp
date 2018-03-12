#include "stdafx.h"
#include "Time.h"
#include <SDL.h>

double Time::deltaTime = 0.0;
double Time::time = 0.0;
double Time::lastTime = 0.0;

void Time::Tick()
{
	lastTime = time;
	time = static_cast<double>(SDL_GetTicks()) / 1000.0;
	deltaTime = time - lastTime;
}
