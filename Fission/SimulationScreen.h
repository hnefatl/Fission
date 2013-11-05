#ifndef _SIMULATIONSCREEN_H
#define _SIMULATIONSCREEN_H

#include "Screen.h"

class SimulationScreen
	: public Screen
{
public:
	SimulationScreen();

	virtual bool Load(SDL_Renderer *const Renderer);

	virtual ScreenResult HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

protected:

};

#endif