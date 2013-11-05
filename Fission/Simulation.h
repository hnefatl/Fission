#ifndef _SIMULATION_H
#define _SIMULATION_H

#include "SDLWindow.h"
#include "Screen.h"

#include <stack>

class Simulation
{
public:
	Simulation();

	bool Load();

	void Run();

	bool Update();
	void Draw();

protected:
	SDLWindow Window;

	std::stack<Screen *> Screens;
};

#endif