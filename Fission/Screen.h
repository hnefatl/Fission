#ifndef _SCREEN_H
#define _SCREEN_H

#include <SDL.h>
#include <stack>

enum ScreenResult
{
	Success,
	Error,
	NewScreen,
	RemoveScreen,
};

class Screen
{
public:
	virtual bool Load(SDL_Renderer *const Renderer)=0;

	virtual ScreenResult HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens)=0;
	virtual void Update()=0;
	virtual void Draw(SDL_Renderer *const Renderer)=0;

protected:

};

#endif