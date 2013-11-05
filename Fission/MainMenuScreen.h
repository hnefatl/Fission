#ifndef _MAINMENUSCREEN_H
#define _MAINMENUSCREEN_H

#include "Screen.h"

#include "Label.h"
#include "Button.h"

class MainMenuScreen
	: public Screen
{
public:
	MainMenuScreen();

	virtual bool Load(SDL_Renderer *const Renderer);

	virtual ScreenResult HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

protected:
	Label Title;
	Button Start;
	Button Options;
	Button Exit;

	bool CallbackExit;
};

#endif