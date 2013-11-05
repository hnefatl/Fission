#ifndef _OPTIONSSCREEN_H
#define _OPTIONSSCREEN_H

#include "Screen.h"

class OptionsScreen
	: public Screen
{
public:
	OptionsScreen();

	virtual bool Load(SDL_Renderer *const Renderer);

	virtual ScreenResult HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

protected:

};

#endif