#ifndef _BUTTON_H
#define _BUTTON_H

#include "Control.h"

#include "Event.h"

class Button
	: public Control
{
public:
	Button();

	virtual bool HandleEvents(const SDL_Event &Event);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);
	
	Event OnClick;
	
	unsigned int FramesToUpdate;

	bool IsSelected() const;
	bool IsClicked() const;

protected:
	bool Selected;
	bool Clicked;
};

#endif