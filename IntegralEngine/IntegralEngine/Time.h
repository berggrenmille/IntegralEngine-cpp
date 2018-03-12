#pragma once

class Time
{
public:
	static double deltaTime;
	static double time;

	static void Tick();

private:
	static double lastTime;
};
